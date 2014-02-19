cmake_minimum_required(VERSION 2.8)


#==============================================================================
# project sources includes directories
#==============================================================================
include_directories (${CMAKE_CURRENT_SOURCE_DIR})

#==============================================================================
# build libs
#==============================================================================

add_library (tinycthread STATIC tinycthread.c)
