#==============================================================================
# lib definition
#==============================================================================

file(GLOB ui_SOURCES *.cpp)
add_library (ui ${ui_SOURCES} )

add_subdirectory (backends)


