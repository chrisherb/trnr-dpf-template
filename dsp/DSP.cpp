#include "DSP.hpp"

void DSP::setSamplerate(double samplerate) { mSamplerate = samplerate; }

void DSP::processBlock(const float** inputs, float** outputs, int blockSize)
{
	for (int i = 0; i < blockSize; i++) {
		outputs[0][i] = inputs[0][i] * mGain;
		outputs[1][i] = inputs[1][i] * mGain;
	}
}

void DSP::processBlock(double** inputs, double** outputs, int blockSize)
{
	for (int i = 0; i < blockSize; i++) {
		outputs[0][i] = inputs[0][i] * mGain;
		outputs[1][i] = inputs[1][i] * mGain;
	}
}