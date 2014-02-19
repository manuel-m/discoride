
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



#==============================================================================
# sub_dir
# 
#==============================================================================
add_subdirectory (main)


#if( CMAKE_BUILD_TYPE MATCHES Debug )
  add_subdirectory (samples)  
#endif( CMAKE_BUILD_TYPE MATCHES Debug )





