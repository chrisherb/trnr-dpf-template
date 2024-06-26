#include "TemplatePlugin.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

TemplatePlugin::TemplatePlugin()
	: Plugin(paramCount, 0, 0) // 0 programs, 0 states
	, fWaveform(50)
{
}

// -----------------------------------------------------------------------
// Init

void TemplatePlugin::initAudioPort(bool input, uint32_t index, AudioPort& port)
{
	port.groupId = kPortGroupStereo;

	Plugin::initAudioPort(input, index, port);

	fWaveform.setSampleRate(getSampleRate());
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
		return mDsp.getGain();
	default:
		DISTRHO_SAFE_ASSERT(false);
		return 0.0;
	}
}

void TemplatePlugin::setParameterValue(uint32_t index, float value)
{
	switch (index) {
	case paramGain:
		mDsp.setGain(value);
		break;
	}
}

// -----------------------------------------------------------------------
// Process

void TemplatePlugin::run(const float** inputs, float** outputs, uint32_t frames)
{
	mDsp.processBlock(inputs, outputs, frames);

	fWaveform.process(inputs, frames);
}

// -----------------------------------------------------------------------

Plugin* createPlugin() { return new TemplatePlugin(); }

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
