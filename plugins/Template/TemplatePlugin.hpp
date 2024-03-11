#ifndef TEMPLATE_PLUGIN_HPP_INCLUDED
#define TEMPLATE_PLUGIN_HPP_INCLUDED

#include "DistrhoPlugin.hpp"

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

	const char* getDescription() const override { return "DPF Template by Ternär Music Technology"; }

	const char* getMaker() const noexcept override { return "Christopher Herb, Akaroid"; }

	const char* getHomePage() const override { return "https://github.com/chrisherb"; }

	const char* getLicense() const noexcept override { return "GPL v2+"; }

	uint32_t getVersion() const noexcept override { return d_version(1, 1, 0); }

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
	float fGain;

	DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TemplatePlugin)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // TEMPLATE_PLUGIN__HPP_INCLUDED
