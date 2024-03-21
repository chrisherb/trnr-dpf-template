#pragma once

#ifndef WAVEFORMBUFFER_HPP_INCLUDED
#define WAVEFORMBUFFER_HPP_INCLUDED

#include <array>

template <int rows, int cols>
class WaveformBuffer {
public:
	WaveformBuffer(float _time_ms) { time_smp = msToSamples(_time_ms); }

	void setSampleRate(float _sampleRate) { _sampleRate = _sampleRate; }

	void setTimeMs(float _time_ms) { time_smp = msToSamples(_time_ms); }

	void process(const float** inputs, uint32_t frames)
	{
		for (uint32_t i = 0; i < frames; ++i) {

			// get maximum value from left/right channels
			float max = abs(inputs[0][i]) > abs(inputs[1][i]) ? inputs[0][i] : inputs[1][i];

			if (max > posMax) posMax = max;
			if (max < negMax) negMax = max;

			if (counter > 0) counter--;

			if (counter <= 0) {
				for (int i = 0; i < cols - 1; i++) {
					// shift all values one column to the left
					for (int j = 0; j < rows; j++) { grid.at(i).at(j) = grid.at(i + 1).at(j); }
				}

				int halfRows = rows / 2;

				int adjustedPos = posMax * halfRows;
				int adjustedNeg = abs(negMax * halfRows - halfRows);

				// upper half (positive values)
				for (int rowIndex = 0; rowIndex < halfRows; rowIndex++) {
					int adjustedIndex = abs(rowIndex - halfRows);
					grid.at(cols - 1).at(rowIndex) = adjustedIndex <= adjustedPos;
				}

				// lower half (negative values)
				for (int rowIndex = halfRows; rowIndex < rows; rowIndex++) {
					grid.at(cols - 1).at(rowIndex) = rowIndex < adjustedNeg;
				}

				// reset
				counter = time_smp;
				posMax = 0;
				negMax = 0;
			}
		}
	}

	const std::array<std::array<bool, rows>, cols>& getGrid() const { return grid; }

private:
	std::array<std::array<bool, rows>, cols> grid = {false};
	int counter = -1;
	float time_smp = 0;
	float sampleRate = 48000;

	float posMax = 0;
	float negMax = 0;

	int msToSamples(float ms) { return ms * sampleRate / 1000; }
};

#endif