cmake_minimum_required(VERSION 3.28)

project(MaaPlugin)

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

cmake_policy(SET CMP0155 OLD)

set(Boost_NO_WARN_NEW_VERSIONS ON)

option(ENABLE_CCACHE "enable ccache if possible" ON)
option(ENABLE_HASH_VERSION "enable hash version from git" OFF)

set(DEPS_DIR ${CMAKE_SOURCE_DIR}/deps)
set(MAA_PLUGIN_PUBLIC_INC ${DEPS_DIR}/share/MaaPlugin)

# Basic compile and link configuration
include(${PROJECT_SOURCE_DIR}/cmake/config.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/utils.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/version.cmake)

set(CMAKE_PREFIX_PATH "${DEPS_DIR}/share/cmake/MaaFramework;${CMAKE_PREFIX_PATH}")
find_package(MaaFramework REQUIRED)

find_program(CCACHE_PROG ccache)

if(CCACHE_PROG)
    message("Find ccache at ${CCACHE_PROG}")

    if(ENABLE_CCACHE)
        set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROG})
        set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROG})
    endif()
endif()

add_subdirectory(3rdparty)
add_subdirectory(source)
