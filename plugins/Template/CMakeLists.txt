dpf_add_plugin(Template
  TARGETS
    clap vst2 vst3 jack
  FILES_DSP
    TemplatePlugin.cpp
  FILES_UI
    TemplateArtwork.cpp
    TemplateUI.cpp
)

target_include_directories(Template
  PUBLIC
    .
    # any additional include directories
)
