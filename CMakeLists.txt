cmake_minimum_required(VERSION 3.15)

project(Drogon_temp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
include(silly_utils)

include_directories(silly_utils/su)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core)

##########################################
# 将当前目录的Config路径添加到宏DEFAULT_CONFIG_DIR.
##########################################
set(DEFAULT_CONFIG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/config")
add_definitions("-DDEFAULT_CONFIG_DIR=\"${DEFAULT_CONFIG_DIR}\"")

# 设置默认程序根目录,程序中所有路径均参照此路径,方便调试和发布
if(IS_DEBUG)
    add_definitions("-DDEFAULT_ROOT_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\"")
else()
    # add_definitions("-DDEFAULT_ROOT_DIR=\"\"")
    add_definitions("-DDEFAULT_ROOT_DIR=\"./\"")
endif()

add_subdirectory(core)
add_subdirectory(web)
