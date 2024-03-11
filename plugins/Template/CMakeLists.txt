dpf_add_plugin(Template
  TARGETS
    vst3 clap # au dssi lv2 vst2
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
