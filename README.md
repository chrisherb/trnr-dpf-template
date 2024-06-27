# trnr-template

Neat plugin template that will output VST2/VST3/CLAP plugins and a Max external while sharing one DSP object. Powered by the [DPF plugin framework](https://github.com/DISTRHO/DPF) and the [Min-DevKit](https://github.com/Cycling74/min-devkit).

## gh-actions

Needs Settings->Actions->General->Workflow permissions set to "Read and write permissions".


To code sign the Mac builds, MACOS_CERTIFICATE (base64 encoded developer certificate) and MACOS_CERTIFICATE_PW (password for said certificate) need to be added to the Actions secrets. 
The developer certificate can be converted from p12 to base64 with the following command: 
`$ base64 Certificate.p12 > Certificate.base64`

## DPF: how to convert images to binary

- navigate to plugin folder (e.g. plugins/dpf/Template)
- call converter with .../../../lib/dpf/utils/png2rgba.py TemplateArtwork Artwork

## Max external: how to remove quarantine flag on Mac

- run `xattr -d com.apple.quarantine path/to/external`
- verify that `xattr -l path/to/external` returns nothing
