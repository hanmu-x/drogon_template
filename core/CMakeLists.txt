project(core_tool)

foreach(dirname ${CMAKE_CURRENT_SOURCE_DIR})
    file(GLOB_RECURSE CORE_TOOL_SRC_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
            "${dirname}/*.h"
            "${dirname}/*.hpp"
            "${dirname}/*.c"
            "${dirname}/*.cpp"
            )

endforeach()


add_library(${PROJECT_NAME} STATIC ${CORE_TOOL_SRC_FILES})


find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC JsonCpp::JsonCpp)

