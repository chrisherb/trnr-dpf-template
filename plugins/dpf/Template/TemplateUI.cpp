#include "TemplateUI.hpp"
#include "TemplatePlugin.hpp"

START_NAMESPACE_DISTRHO

namespace Art = TemplateArtwork;

// -----------------------------------------------------------------------

TemplateUI::TemplateUI()
	: UI(Art::backgroundWidth, Art::backgroundHeight, true)
	, fImgBackground(Art::backgroundData, Art::backgroundWidth, Art::backgroundHeight, kImageFormatBGRA)
	, fImgLed(Art::ledData, Art::ledWidth, Art::ledHeight, kImageFormatBGRA)
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
// UI Callbacks

void TemplateUI::uiIdle() { repaint(); }

// -----------------------------------------------------------------------
// Widget Callbacks

void TemplateUI::imageKnobDragStarted(ImageKnob* knob) { editParameter(knob->getId(), true); }

void TemplateUI::imageKnobDragFinished(ImageKnob* knob) { editParameter(knob->getId(), false); }

void TemplateUI::imageKnobValueChanged(ImageKnob* knob, float value) { setParameterValue(knob->getId(), value); }

void TemplateUI::imageKnobDoubleClicked(ImageKnob* knob) { knob->setValue(knob->getDefault(), true); }

void TemplateUI::onDisplay()
{
	const GraphicsContext& context(getGraphicsContext());

	fImgBackground.draw(context);

	if (TemplatePlugin* const dspPtr = (TemplatePlugin*)getPluginInstancePointer()) {
		auto& grid = dspPtr->fWaveform.getGrid();

		for (uint32_t i = 0; i < grid.size(); ++i) {
			for (uint32_t j = 0; j < grid.at(i).size(); ++j) {
				if (grid.at(i).at(j)) { fImgLed.drawAt(context, i * 9 + 84, j * 6 + 262); }
			}
		}
	}
}

// -----------------------------------------------------------------------

UI* createUI() { return new TemplateUI(); }

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
