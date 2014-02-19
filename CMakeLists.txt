#==============================================================================
# CMake version minimum requirement
# 
#==============================================================================
cmake_minimum_required (VERSION 2.8) 

#==============================================================================
# DISCORIDE
#==============================================================================
project (DISCORIDE) 

#==============================================================================
# Additional package ressource finders
#==============================================================================
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/ressources/CMake/Modules")

#==============================================================================
# The macro below forces the build directory to be different from source directory
#==============================================================================
include(MacroOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build.")

include(MacroLogAll)
macro_logall()

include(MacroUseTinyCThread)
macro_use_tinycthread()

include(MacroUseGlfw)
macro_use_glfw()

include(MacroUsePortaudio)
macro_use_portaudio()

include(MacroUseMpg123)
macro_use_mpg123()

include(MacroUseFltk)
macro_use_fltk()



set(DR_BIN ${CMAKE_CURRENT_SOURCE_DIR}/bin)
file(MAKE_DIRECTORY ${DR_BIN})
set(EXECUTABLE_OUTPUT_PATH ${DR_BIN})


set(LIBDR_SRC lib)

include_directories (src ${LIBDR_SRC})


# include(Splint)

# add_subdirectory (dr2)
add_subdirectory (lib)  
add_subdirectory (dr3)  






