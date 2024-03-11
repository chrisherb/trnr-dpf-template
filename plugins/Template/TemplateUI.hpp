#ifndef TEMPLATE_UI_HPP_INCLUDED
#define TEMPLATE_UI_HPP_INCLUDED

#include "TemplateUI.hpp"

using DGL_NAMESPACE::ImageKnob;

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

class TemplateUI : public UI, public ImageKnob::Callback, public IdleCallback {
public:
	TemplateUI();
	~TemplateUI() override;

protected:
	// -------------------------------------------------------------------
	// DSP Callbacks

	void parameterChanged(uint32_t index, float value) override;

	// -------------------------------------------------------------------
	// Widget Callbacks

	void imageKnobDragStarted(ImageKnob* knob) override;
	void imageKnobDragFinished(ImageKnob* knob) override;
	void imageKnobValueChanged(ImageKnob* knob, float value) override;

	void onDisplay() override;

	// -------------------------------------------------------------------
	// Other Callbacks

	void idleCallback() override;

private:
	Image fImgBackground;

	ScopedPointer<ImageKnob> fGain;

	DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TemplateUI)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // TEMPLATE_UI_HPP_INCLUDED
