#==============================================================================
# CMake version minimum requirement
# 
#==============================================================================
cmake_minimum_required (VERSION 2.6) 

#==============================================================================
# DISCORIDE
# 
#==============================================================================
project (DISCORIDE) 

#==============================================================================
# Additional package ressource finders
# 
#==============================================================================
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/ressources/CMake/Modules/")

#==============================================================================
# strict
# 
#==============================================================================

if (CMAKE_COMPILER_IS_GNUCXX)

   if (CMAKE_SYSTEM_NAME MATCHES Linux)

#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic-errors")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wbad-function-cast")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wcast-align")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wcast-qual")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wchar-subscripts")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wdeclaration-after-statement")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wdisabled-optimization")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror-implicit-function-declaration")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wformat-security")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Winit-self")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Winline")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Winvalid-pch")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wlogical-op")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wmissing-declarations")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wmissing-format-attribute")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wmissing-include-dirs")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wmissing-prototypes")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wnested-externs")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-long-long")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wold-style-definition")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Woverlength-strings")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpointer-arith")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wredundant-decls")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wshadow")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wstrict-prototypes")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wswitch-default")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wundef")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wunsafe-loop-optimizations")
#    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wwrite-strings")

#    set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -ggdb -pg -DDEBUG")
#    set (CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -mmmx -msse -m3dnow")


   endif (CMAKE_SYSTEM_NAME MATCHES Linux)
endif (CMAKE_COMPILER_IS_GNUCXX)



#==============================================================================
# Required packages
# 
#==============================================================================
find_package(Cairo REQUIRED)
#find_package(Taglib REQUIRED)
find_package(Portaudio REQUIRED)
find_package(Mpg123 REQUIRED)
find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(XRandR REQUIRED)
find_package(X11 REQUIRED)

set( LIBTAG_C_A ${CMAKE_CURRENT_SOURCE_DIR}/ressources/taglib-1.7/bindings/c/libtag_c.a)
set( LIBTAG_A ${CMAKE_CURRENT_SOURCE_DIR}/ressources/taglib-1.7/taglib/libtag.a)




#==============================================================================
# includes passed to sub makes
# 
#==============================================================================
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/src/lib )
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/src/gui )

#==============================================================================
# subfolders
# 
#==============================================================================
add_subdirectory (src) 



