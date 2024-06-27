#include "aw_cliponly2.h"

template <typename sample>
class DSP {
public:
	void setSamplerate(double samplerate)
	{
		mSamplerate = samplerate;
		mClipper.set_samplerate(samplerate);
	}

	void processBlock(const float** inputs, float** outputs, int blockSize)
	{
		for (int i = 0; i < blockSize; i++) {
			outputs[0][i] = inputs[0][i] * mGain;
			outputs[1][i] = inputs[1][i] * mGain;
		}

		process(outputs, blockSize);
	}

	void processBlock(double** inputs, double** outputs, int blockSize)
	{
		for (int i = 0; i < blockSize; i++) {
			outputs[0][i] = inputs[0][i] * mGain;
			outputs[1][i] = inputs[1][i] * mGain;
		}

		process(outputs, blockSize);
	}

	void setGain(float gain) { mGain = gain; }

	float getGain() const { return mGain; }

private:
	float mGain = 0.5;
	double mSamplerate = 48000;
	trnr::aw_cliponly2 mClipper;

	void process(sample** audio, int frames) { mClipper.process_block(audio, audio, frames); }
};