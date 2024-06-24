#include "aw_cliponly2.h"

class DSP {
public:
  void setSamplerate(double samplerate);

  template <typename sample>
  void processBlock(sample **inputs, sample **outputs, int blockSize);

private:
  double mSamplerate = 48000;
};