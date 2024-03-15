#include "TemplateUI.hpp"
#include "TemplatePlugin.hpp"

START_NAMESPACE_DISTRHO

namespace Art = TemplateArtwork;

// -----------------------------------------------------------------------

TemplateUI::TemplateUI()
	: UI(Art::backgroundWidth, Art::backgroundHeight, true)
	, fImgBackground(Art::backgroundData, Art::backgroundWidth, Art::backgroundHeight, kImageFormatBGRA)
{
	const float width = getWidth();
	const float height = getHeight();
	const double scaleFactor = getScaleFactor();

	// knobs
	Image knobImage(Art::gainData, Art::gainWidth, Art::gainHeight, kImageFormatBGRA);

	// knob Tuning
	fKnobGain = new ImageKnob(this, knobImage, ImageKnob::Vertical);
	fKnobGain->setId(TemplatePlugin::paramGain);
	fKnobGain->setAbsolutePos(115, 83);
	fKnobGain->setRange(0, 1.0f);
	fKnobGain->setDefault(0.0f);
	fKnobGain->setValue(0.0f);
	fKnobGain->setCallback(this);
}

// -----------------------------------------------------------------------
// DSP Callbacks

void TemplateUI::parameterChanged(uint32_t index, float value)
{
	switch (index) {
	case TemplatePlugin::paramGain:
		fKnobGain->setValue(value);
		break;
	}
}

// -----------------------------------------------------------------------
// Widget Callbacks

void TemplateUI::imageKnobDragStarted(ImageKnob* knob) { editParameter(knob->getId(), true); }

void TemplateUI::imageKnobDragFinished(ImageKnob* knob) { editParameter(knob->getId(), false); }

void TemplateUI::imageKnobValueChanged(ImageKnob* knob, float value) { setParameterValue(knob->getId(), value); }

void TemplateUI::onDisplay()
{
	const GraphicsContext& context(getGraphicsContext());

	fImgBackground.draw(context);
}

// -----------------------------------------------------------------------

UI* createUI() { return new TemplateUI(); }

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
