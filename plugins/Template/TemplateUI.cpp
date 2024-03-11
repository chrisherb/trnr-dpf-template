#include "TemplateUI.hpp"
#include "TemplatePlugin.hpp"

START_NAMESPACE_DISTRHO

namespace Art = TemplateArtwork;

// -----------------------------------------------------------------------

TemplateUI::TemplateUI()
	: UI(Art::backgroundWidth, Art::backgroundHeight, true)
	, fImgBackground(Art::backgroundData, Art::backgroundWidth, Art::backgroundHeight, kImageFormatBGR)
	, fAboutWindow(this)
{

	// knobs
	Image knobImage(Art::knobData, Art::knobWidth, Art::knobHeight, kImageFormatBGRA);

	// knob Tuning
	fKnobTuning = new ImageKnob(this, knobImage, ImageKnob::Vertical);
	fKnobTuning->setId(TemplatePlugin::paramTuning);
	fKnobTuning->setAbsolutePos(41, 43);
	fKnobTuning->setRange(-12.0f, 12.0f);
	fKnobTuning->setDefault(0.0f);
	fKnobTuning->setValue(0.0f);
	fKnobTuning->setRotationAngle(305);
	fKnobTuning->setCallback(this);
}

TemplateUI::~TemplateUI() { removeIdleCallback(this); }

// -----------------------------------------------------------------------
// DSP Callbacks

void TemplateUI::parameterChanged(uint32_t index, float value)
{
	switch (index) {
	case TemplatePlugin::paramGain:
		fGain->setValue(value);
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
	fNeko.draw(context);
}

// -----------------------------------------------------------------------
// Other Callbacks

void TemplateUI::idleCallback()
{
	if (fNeko.idle()) repaint();
}

// -----------------------------------------------------------------------

UI* createUI() { return new TemplateUI(); }

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
