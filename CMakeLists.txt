cmake_minimum_required(VERSION 3.28)

project(MaaPlugin)

include(source/MaaUtils/MaaUtils.cmake)

set(DEPS_DIR ${CMAKE_SOURCE_DIR}/deps)
set(MAA_PLUGIN_PUBLIC_INC ${DEPS_DIR}/share/MaaPlugin)

set(CMAKE_PREFIX_PATH "${DEPS_DIR}/share/cmake/MaaFramework;${CMAKE_PREFIX_PATH}")
find_package(MaaFramework REQUIRED)

add_subdirectory(source)
