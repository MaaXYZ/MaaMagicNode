cmake_minimum_required(VERSION 3.28)

project(MaaPlugin)

# set(BUILD_MAA_UTILS ON)

include(source/MaaUtils/MaaUtils.cmake)

set(DEPS_DIR ${CMAKE_SOURCE_DIR}/deps)
set(MAA_PLUGIN_PUBLIC_INC ${DEPS_DIR}/share/MaaPlugin)

set(MaaFramework_DIR ${DEPS_DIR}/share/cmake/MaaFramework)
find_package(MaaFramework REQUIRED)

add_subdirectory(source)
