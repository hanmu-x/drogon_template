# 检查Windows平台下GRIP_API的一些信息, Linux平台下使用 ecCodes
if (IS_WINDOWS)
    if ("" STREQUAL "$ENV{GRIB_DEFINITION_PATH}")
        message(WARNING "GRIB_DEFINITION_PATH NOT FOUND.")
    else ()
        set(GRIB_API_INCLUDE "${CMAKE_SOURCE_DIR}/third_party/grib_api/include")
        set(GRIB_API_LIBRARY "${CMAKE_SOURCE_DIR}/third_party/grib_api/lib/${CMAKE_BUILD_TYPE}/grib_api_lib.lib")
        include_directories(${GRIB_API_INCLUDE})
        LINK_LIBRARIES(${GRIB_API_LIBRARY})
        add_definitions("-DGRIB_ENABLED")
    endif ()
endif ()