
MACRO(macro_use_mpg123)

set( CURRENT_MPG123_VERSION mpg123-1.18.0 )
set( CURRENT_MPG123_DIR ${PROJECT_SOURCE_DIR}/external_libs/mpg123/${CURRENT_MPG123_VERSION} )

set (MPG123_A ${PROJECT_SOURCE_DIR}/external_libs/out/libmpg123.a)

include_directories (${CURRENT_MPG123_DIR}/src/libmpg123)

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__WITH_MPG123__" )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__WITH_MPG123__" )

ENDMACRO(macro_use_mpg123)




