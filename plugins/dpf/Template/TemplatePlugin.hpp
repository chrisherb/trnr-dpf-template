#ifndef TEMPLATE_PLUGIN_HPP_INCLUDED
#define TEMPLATE_PLUGIN_HPP_INCLUDED

#include "DistrhoPlugin.hpp"
#include "WaveformBuffer.h"

#include <DSP.hpp>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class TemplatePlugin : public Plugin {
public:
	enum Parameters {
		paramGain = 0,
		paramCount
	};

	TemplatePlugin();

protected:
	// -------------------------------------------------------------------
	// Information

	const char* getLabel() const noexcept override { return "Template"; }

	const char* getDescription() const override { return "DPF plugin template by Ternär Music Technology"; }

	const char* getMaker() const noexcept override { return "Ternar Music Technology"; }

	const char* getHomePage() const override { return "https://www.ternar.tech"; }

	const char* getLicense() const noexcept override { return "GPL v2+"; }

	uint32_t getVersion() const noexcept override { return d_version(0, 0, 1); }

	int64_t getUniqueId() const noexcept override { return d_cconst('T', 'e', 'm', 'p'); }

	// -------------------------------------------------------------------
	// Init

	void initAudioPort(bool input, uint32_t index, AudioPort& port) override;
	void initParameter(uint32_t index, Parameter& parameter) override;

	// -------------------------------------------------------------------
	// Internal data

	float getParameterValue(uint32_t index) const override;
	void setParameterValue(uint32_t index, float value) override;

	// -------------------------------------------------------------------
	// Process

	void run(const float** inputs, float** outputs, uint32_t frames) override;

	// -------------------------------------------------------------------

private:
	friend class TemplateUI;

	DSP mDsp;

	BipolarWaveformBuffer<17, 27> fWaveform;

	DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TemplatePlugin)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // TEMPLATE_PLUGIN__HPP_INCLUDED
