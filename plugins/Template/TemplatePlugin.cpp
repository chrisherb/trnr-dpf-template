#include "TemplatePlugin.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

TemplatePlugin::TemplatePlugin()
	: Plugin(paramCount, 0, 0) // 0 programs, 0 states
	, fGain(0.5f)
{
}

// -----------------------------------------------------------------------
// Init

void TemplatePlugin::initAudioPort(bool input, uint32_t index, AudioPort& port)
{
	port.groupId = kPortGroupStereo;

	Plugin::initAudioPort(input, index, port);
}

void TemplatePlugin::initParameter(uint32_t index, Parameter& parameter)
{
	switch (index) {
	case paramGain:
		parameter.name = "Gain";
		parameter.symbol = "gain";
		parameter.ranges.def = 0.5f;
		parameter.ranges.min = 0.0f;
		parameter.ranges.max = 1.0f;
		break;
	}
}

// -----------------------------------------------------------------------
// Internal data

float TemplatePlugin::getParameterValue(uint32_t index) const
{
	switch (index) {
	case paramGain:
		return fGain;
	}

	return 0.0f;
}

void TemplatePlugin::setParameterValue(uint32_t index, float value)
{
	switch (index) {
	case paramGain:
		fGain = value;
		break;
	}
}

// -----------------------------------------------------------------------
// Process

void TemplatePlugin::run(const float** inputs, float** outputs, uint32_t frames)
{

	float inLeft, inRight;

	for (uint32_t i = 0; i < frames; ++i) {
		inLeft = inputs[0][i];
		inRight = inputs[1][i];

		outputs[0][i] = inLeft * fGain;
		outputs[1][i] = inRight * fGain;
	}
}

// -----------------------------------------------------------------------

Plugin* createPlugin() { return new TemplatePlugin(); }

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
