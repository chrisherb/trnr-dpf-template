#ifndef DISTRHO_PLUGIN_INFO_H_INCLUDED
#define DISTRHO_PLUGIN_INFO_H_INCLUDED

#include "TemplateArtwork.hpp"

#define DISTRHO_PLUGIN_BRAND "Ternär Music Technology"
#define DISTRHO_PLUGIN_NAME "Template"
#define DISTRHO_PLUGIN_URI "https://github.com/chrisherb"
#define DISTRHO_PLUGIN_CLAP_ID "trnr.Template"

#define DISTRHO_PLUGIN_BRAND_ID Trnr
#define DISTRHO_PLUGIN_UNIQUE_ID Temp

#define DISTRHO_PLUGIN_HAS_UI 1
#define DISTRHO_PLUGIN_IS_RT_SAFE 1
#define DISTRHO_PLUGIN_IS_SYNTH 0
#define DISTRHO_PLUGIN_WANT_DIRECT_ACCESS 1
#define DISTRHO_PLUGIN_NUM_INPUTS 2
#define DISTRHO_PLUGIN_NUM_OUTPUTS 2

#define DISTRHO_UI_DEFAULT_WIDTH TemplateArtwork::backgroundWidth
#define DISTRHO_UI_DEFAULT_HEIGHT TemplateArtwork::backgroundHeight

#define DPF_VST3_DONT_USE_BRAND_ID

#endif // DISTRHO_PLUGIN_INFO_H_INCLUDED
