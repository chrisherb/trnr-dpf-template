#include "c74_min.h"
#include <DSP.hpp>

using namespace c74::min;

class max_template : public object<max_template>, public vector_operator<> {
public:
	MIN_DESCRIPTION {"Template for a Max external"};
	MIN_TAGS {"template"};
	MIN_AUTHOR {"Christopher Herb"};

	inlet<>  in1 {this, "(signal) Input1"};
	inlet<>  in2 {this, "(signal) Input2"};
	outlet<> out1 {this, "(signal) Output1", "signal"};
	outlet<> out2 {this, "(signal) Output2", "signal"};

	message<> dspsetup {this, "dspsetup", MIN_FUNCTION {double sr = samplerate();
	m_dsp.setSamplerate(sr);
	return {};
}
}
;

void operator()(audio_bundle _input, audio_bundle _output) {

	long sample_frames = _input.frame_count();
	m_dsp.processBlock(_input.samples(), _output.samples(), sample_frames);
}

private:
DSP m_dsp;
}
;