# add glfw headers dir

MACRO(macro_use_glfw)

set( CURRENT_GLFW_VERSION glfw-3.0.1 )
set( CURRENT_GLFW_DIR ${PROJECT_SOURCE_DIR}/external_libs/glfw/${CURRENT_GLFW_VERSION} )

set (GLFW_A ${CURRENT_GLFW_DIR}/lib/src/libglfw3.a)
include_directories (${CURRENT_GLFW_DIR}/include/GLFW)

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDISPLAY_WITH_GLFW " )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDISPLAY_WITH_GLFW" )

ENDMACRO(macro_use_glfw)
