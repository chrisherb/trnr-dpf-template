#include <DSP.hpp>

#include "c74_min.h"

using namespace c74::min;

class Template : public object<Template>, public vector_operator<> {
public:
	MIN_DESCRIPTION {"Template for a Max external"};
	MIN_TAGS {"template"};
	MIN_AUTHOR {"Christopher Herb"};

	inlet<> in1 {this, "(signal) Input1"};
	inlet<> in2 {this, "(signal) Input2"};
	outlet<> out1 {this, "(signal) Output1", "signal"};
	outlet<> out2 {this, "(signal) Output2", "signal"};

	message<> dspsetup {this, "dspsetup", MIN_FUNCTION {double sr = samplerate();
		dsp.setSamplerate(sr);
		return {};
	}};

	attribute<number, threadsafe::no, limit::clamp> attr_gain {this, "gain", 0.1, range {0.0, 1.0}, setter { MIN_FUNCTION {
		dsp.setGain(args[0]);
		return args; 
	}}};

	void operator()(audio_bundle _input, audio_bundle _output)
	{
		int sample_frames = _input.frame_count();

		dsp.processBlock(_input.samples(), _output.samples(), sample_frames);
	}

private:
	DSP dsp;
};

MIN_EXTERNAL(Template);