#include "DSP.hpp"

void DSP::setSamplerate(double samplerate) { mSamplerate = samplerate; }

template <typename sample>
void DSP::processBlock(sample **inputs, sample **outputs, int blockSize) {}