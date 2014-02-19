#==============================================================================
# lib definition
#==============================================================================
file(GLOB ui_glfw_SOURCES *.cpp)
add_library (ui_glfw ${ui_glfw_SOURCES})

add_subdirectory(wids_glfw)
