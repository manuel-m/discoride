
#add_subdirectory (external_libs)

include(MacroDefineCFlags)
macro_define_cflags()

include(MacroDefineCXXFlags)
macro_define_cxxflags()


#==============================================================================
# required packages
# 
#==============================================================================
#find_package(Cairo REQUIRED)
#find_package(Taglib REQUIRED)
#find_package(Portaudio REQUIRED)
#find_package(Mpg123 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(XRandR REQUIRED)
find_package(X11 REQUIRED)




#==============================================================================
# includes directories 
#
#==============================================================================
#include_directories (${Cairo_INCLUDE_DIRS})

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

set( LIB_BASENAME libs)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME} )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/trace )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/conf )

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/audio )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/audio/proxy )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/audio/backends/rtaudio )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/audio/backends/portaudio )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/audio/loaders/mpg123 )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/audio/process )

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/ui )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/ui/backends/glfw )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/ui/backends/glfw/wids_glfw )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/ui/backends/fltk )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/${LIB_BASENAME}/ui/backends/minimal )





#==============================================================================
# sub_dir
# 
#==============================================================================
add_subdirectory (main)


#if( CMAKE_BUILD_TYPE MATCHES Debug )
  add_subdirectory (samples)  
#endif( CMAKE_BUILD_TYPE MATCHES Debug )





