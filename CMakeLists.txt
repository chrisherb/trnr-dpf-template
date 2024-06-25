cmake_minimum_required(VERSION 3.7)

project(trnr-template)
set(CMAKE_CXX_STANDARD 17)

# add trnr-lib and link with dsp code
add_subdirectory(lib/trnr-lib)
add_library(trnr-dsp SHARED dsp/DSP.cpp)
target_include_directories(trnr-dsp PUBLIC dsp)
target_link_libraries(trnr-dsp trnr-lib)

if(DEFINED ENV{BUILD_DPF})
    # add dpf and plugins
    add_subdirectory(lib/dpf)
    add_subdirectory(plugins/dpf/Template)
endif()

if(DEFINED ENV{BUILD_MAX})
    # enable apple silicon builds
    set(CMAKE_OSX_ARCHITECTURES x86_64;arm64)

    # min-api setup and subroutines
    include(lib/min-api/script/min-package.cmake)

    # add min-api and externals
    add_subdirectory(lib/min-api)
    add_subdirectory(plugins/max/trnr.core.template_tilde)
endif()