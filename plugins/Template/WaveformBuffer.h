#pragma once

#ifndef WAVEFORMBUFFER_HPP_INCLUDED
#define WAVEFORMBUFFER_HPP_INCLUDED

#include <array>

template <int rows, int cols>
class BufferBase {
public:
	BufferBase(float _time_ms) { setTimeMs(_time_ms); }

	void setSampleRate(float _sampleRate) { _sampleRate = _sampleRate; }

	void setTimeMs(float _time_ms) { time_smp = msToSamples(_time_ms); }

	virtual void process(const float** inputs, uint32_t frames);

	const std::array<std::array<bool, rows>, cols>& getGrid() const { return grid; }

protected:
	std::array<std::array<bool, rows>, cols> grid = {false};
	int counter = -1;
	float time_smp = 0;
	float sampleRate = 48000;

	int msToSamples(float ms) { return ms * sampleRate / 1000; }
};

template <int rows, int cols>
class BipolarWaveformBuffer : public BufferBase<rows, cols> {
public:
	BipolarWaveformBuffer(float _time_ms)
		: BufferBase<rows, cols>(_time_ms)
	{
	}

	void process(const float** inputs, uint32_t frames) override
	{
		for (uint32_t i = 0; i < frames; ++i) {

			// get maximum value from left/right channels
			float max = abs(inputs[0][i]) > abs(inputs[1][i]) ? inputs[0][i] : inputs[1][i];

			if (max > posMax) posMax = max;
			if (max < negMax) negMax = max;

			if (BufferBase<rows, cols>::counter > 0) BufferBase<rows, cols>::counter--;

			if (BufferBase<rows, cols>::counter <= 0) {
				for (int i = 0; i < cols - 1; i++) {
					// shift all values one column to the left
					for (int j = 0; j < rows; j++) {
						BufferBase<rows, cols>::grid.at(i).at(j) = BufferBase<rows, cols>::grid.at(i + 1).at(j);
					}
				}

				int halfRows = floor(rows / 2);
				int adjustedPos = posMax * (halfRows + 1);

				// upper half (positive values)
				for (int rowIndex = 0; rowIndex < halfRows; rowIndex++) {
					int adjustedIndex = abs(rowIndex - halfRows + 1);
					BufferBase<rows, cols>::grid.at(cols - 1).at(rowIndex) = adjustedIndex < adjustedPos;
				}

				// fill middle
				BufferBase<rows, cols>::grid.at(cols - 1).at(halfRows) = true;

				halfRows++;
				int adjustedNeg = abs(negMax * halfRows - halfRows);

				// lower half (negative values)
				for (int rowIndex = halfRows; rowIndex < rows; rowIndex++) {
					BufferBase<rows, cols>::grid.at(cols - 1).at(rowIndex) = rowIndex < adjustedNeg;
				}

				// reset
				BufferBase<rows, cols>::counter = BufferBase<rows, cols>::time_smp;
				posMax = 0;
				negMax = 0;
			}
		}
	}

private:
	float posMax = 0;
	float negMax = 0;
};

#endif