#==============================================================================
# project sources includes directories
#==============================================================================
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/lib)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/lib/x11)


list ( APPEND MYGLFW_LIB_SRC lib/enable.c )
list ( APPEND MYGLFW_LIB_SRC lib/fullscreen.c )
list ( APPEND MYGLFW_LIB_SRC lib/glext.c )
#list ( APPEND MYGLFW_LIB_SRC lib/image.c )
list ( APPEND MYGLFW_LIB_SRC lib/init.c )
list ( APPEND MYGLFW_LIB_SRC lib/input.c )
#list ( APPEND MYGLFW_LIB_SRC lib/joystick.c )
#list ( APPEND MYGLFW_LIB_SRC lib/stream.c )
#list ( APPEND MYGLFW_LIB_SRC lib/tga.c )
list ( APPEND MYGLFW_LIB_SRC lib/thread.c )
list ( APPEND MYGLFW_LIB_SRC lib/time.c )
list ( APPEND MYGLFW_LIB_SRC lib/window.c )

list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_enable.c )
list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_fullscreen.c )
list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_glext.c )
list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_init.c )
#list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_joystick.c )
list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_thread.c )
list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_time.c )
list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_window.c )
list ( APPEND MYGLFW_LIB_SRC lib/x11/x11_keysym2unicode.c )


#set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GLFW_USE_LINUX_JOYSTICKS -D_GLFW_HAS_XRANDR -D_GLFW_HAS_PTHREAD -D_GLFW_HAS_SCHED_YIELD -D_GLFW_HAS_GLXGETPROCADDRESS -D_GLFW_HAS_SYSCONF" )
set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GLFW_HAS_XRANDR -D_GLFW_HAS_PTHREAD -D_GLFW_HAS_SCHED_YIELD -D_GLFW_HAS_GLXGETPROCADDRESS -D_GLFW_HAS_SYSCONF" )

#==============================================================================
# build libs
#==============================================================================

add_library (glfw STATIC ${MYGLFW_LIB_SRC})


