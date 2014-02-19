
MACRO(macro_use_fltk)

set( CURRENT_FLTK_VERSION fltk-1.3.2 )
set( CURRENT_FLTK_DIR ${PROJECT_SOURCE_DIR}/external_libs/fltk/${CURRENT_FLTK_VERSION} )

set (FLTK_A ${PROJECT_SOURCE_DIR}/external_libs/out/libfltk.a)

include_directories (${CURRENT_FLTK_DIR})

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__WITH_FLTK__" )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__WITH_FLTK__" )

ENDMACRO(macro_use_fltk)




