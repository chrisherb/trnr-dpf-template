#include "aw_cliponly2.h"

class DSP {
public:
	void setSamplerate(double samplerate);

	void processBlock(const float** inputs, float** outputs, int blockSize);

	void processBlock(double** inputs, double** outputs, int blockSize);

	void setGain(float gain) { mGain = gain; }

	float getGain() const { return mGain; }

private:
	float mGain = 0.5;
	double mSamplerate = 48000;
	trnr::aw_cliponly2 mClipper;

	template<typename sample>
	void processBlock(sample** audio, int frames)
	{
		mClipper.process_block(audio, audio, frames);
	}
};