
MACRO(macro_use_lacewing)

set( CURRENT_LACEWING_VERSION udp-lacewing-d0a41bc)
set( CURRENT_LACEWING_DIR ${PROJECT_SOURCE_DIR}/external_libs/lacewing/${CURRENT_LACEWING_VERSION} )

set (LACEWING_A ${CURRENT_LACEWING_DIR}/liblacewing.a)

include_directories (${CURRENT_LACEWING_DIR}/include)

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__WITH_LACEWING__" )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__WITH_LACEWING__" )

ENDMACRO(macro_use_lacewing)




