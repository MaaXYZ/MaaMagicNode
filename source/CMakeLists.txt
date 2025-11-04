file(GLOB_RECURSE maa_plugin_demo_src *.h *.hpp *.cpp)
file(GLOB_RECURSE maa_plugin_demo_header ${MAA_PLUGIN_PUBLIC_INC}/*)

add_library(MaaPluginDemo SHARED ${maa_plugin_demo_src} ${maa_plugin_demo_header})

target_include_directories(
    MaaPluginDemo
    PUBLIC ${MAA_PLUGIN_PUBLIC_INC}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(MaaPluginDemo PRIVATE MAA_PLUGIN_EXPORTS)

target_link_libraries(MaaPluginDemo PRIVATE HeaderOnlyLibraries MaaFramework::MaaFramework)

install(TARGETS MaaPluginDemo)

if(WIN32)
    install(FILES $<TARGET_PDB_FILE:MaaPluginDemo> DESTINATION symbol OPTIONAL)
endif()

install(DIRECTORY "${MAA_PLUGIN_PUBLIC_INC}" DESTINATION ".")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${maa_plugin_demo_src})
