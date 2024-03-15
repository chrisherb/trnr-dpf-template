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

	// gain knob
	Image knobImage(Art::gainData, Art::gainWidth, Art::gainHeight, kImageFormatBGRA);
	fKnobGain = new ImageKnob(this, knobImage, ImageKnob::Vertical);
	fKnobGain->setId(TemplatePlugin::paramGain);
	fKnobGain->setAbsolutePos(115, 83);
	fKnobGain->setRange(0, 1.0f);
	fKnobGain->setDefault(0.0f);
	fKnobGain->setValue(0.0f);
	fKnobGain->setCallback(this);

	// meter
	Image meterImage(Art::meterData, Art::meterWidth, Art::meterHeight, kImageFormatBGRA);
	fMeter = new ImageKnob(this, meterImage, ImageKnob::Vertical);
	fMeter->setId(TemplatePlugin::paramMasterLevel);
	fMeter->setAbsolutePos(84, 262);
	fMeter->setImageLayerCount(11);
	fMeter->setRange(-1.0f, 1.0f);
	fMeter->setDefault(0.0f);
	fMeter->setValue(0.0f);
	fMeter->setCallback(this);
}

// -----------------------------------------------------------------------
// DSP Callbacks

void TemplateUI::parameterChanged(uint32_t index, float value)
{
	switch (index) {
	case TemplatePlugin::paramGain:
		fKnobGain->setValue(value);
		break;
	case TemplatePlugin::paramMasterLevel:
		fMeter->setValue(value);
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
