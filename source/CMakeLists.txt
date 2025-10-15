file(GLOB_RECURSE maa_magic_node_src *.h *.hpp *.cpp)
file(GLOB_RECURSE maa_magic_node_header ${MAA_PLUGIN_PUBLIC_INC}/*)

add_library(MaaMagicNode SHARED ${maa_magic_node_src} ${maa_magic_node_header})

target_include_directories(
    MaaMagicNode
    PUBLIC ${MAA_PLUGIN_PUBLIC_INC}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(MaaMagicNode PRIVATE MAA_PLUGIN_EXPORTS)

target_link_libraries(MaaMagicNode PRIVATE HeaderOnlyLibraries MaaFramework::MaaFramework)

install(TARGETS MaaMagicNode)

if(WIN32)
    install(FILES $<TARGET_PDB_FILE:MaaMagicNode> DESTINATION symbol OPTIONAL)
endif()

install(DIRECTORY "${MAA_PLUGIN_PUBLIC_INC}" DESTINATION ".")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${maa_magic_node_src})
