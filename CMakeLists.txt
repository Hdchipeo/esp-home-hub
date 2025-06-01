# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

# Add RainMaker components and other common application components
set(EXTRA_COMPONENT_DIRS "/Users/dangminhtam/esp32-test/esp-rainmaker/examples/common" "/Users/dangminhtam/esp32-test/esp-rainmaker/components" "/Users/dangminhtam/esp/esp-idf/examples/common_components/protocol_examples_common")

set(PROJECT_VER "1.0")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp-home-hub)
