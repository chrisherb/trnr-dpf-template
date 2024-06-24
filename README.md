# trnr-dpf-template

Neat template for a [DPF](https://github.com/DISTRHO/DPF) plugin and Max external which share one DSP. Work in progress.

## gh-actions

Needs Settings->Actions->General->Workflow permissions set to "Read and write permissions".


To code sign the Mac builds, MACOS_CERTIFICATE (base64 encoded developer certificate) and MACOS_CERTIFICATE_PW (password for said certificate) need to be added to the Actions secrets. 
The developer certificate can be converted from p12 to base64 with the following command: 
`$ base64 Certificate.p12 > Certificate.base64`

## how to convert images to binary

- navigate to plugin folder (e.g. plugins/Template)
- call converter with .../../dpf/utils/png2rgba.py TemplateArtwork Artwork