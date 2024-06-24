dpf_add_plugin(TemplatePlugin
  TARGETS
    clap vst2 vst3 jack
  FILES_DSP
    TemplatePlugin.cpp
  FILES_UI
    TemplateArtwork.cpp
    TemplateUI.cpp
)

target_link_libraries(TemplatePlugin-dsp PRIVATE trnr-dsp)
target_link_libraries(TemplatePlugin-ui PRIVATE trnr-dsp)

target_include_directories(TemplatePlugin
  PUBLIC
    .
    # any additional include directories
)