#include "aw_cliponly2.h"

class DSP {
public:
	float Gain = 0.5;

	void setSamplerate(double samplerate);

	void processBlock(const float** inputs, float** outputs, int blockSize);

	void processBlock(double** inputs, double** outputs, int blockSize);

protected:
private:
	double mSamplerate = 48000;
};