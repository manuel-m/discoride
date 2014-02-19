
MACRO(macro_use_portaudio)

set( CURRENT_PORTAUDIO_VERSION portaudio_v19 )
set( CURRENT_PORTAUDIO_DIR ${PROJECT_SOURCE_DIR}/external_libs/portaudio/${CURRENT_PORTAUDIO_VERSION} )

set (PORTAUDIO_CPP_A ${CURRENT_PORTAUDIO_DIR}/bindings/cpp/lib/.libs/libportaudiocpp.a)
set (PORTAUDIO_A ${CURRENT_PORTAUDIO_DIR}/lib/.libs/libportaudio.a)

include_directories (${CURRENT_PORTAUDIO_DIR}/bindings/cpp/include)

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__WITH_PORTAUDIO__" )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__WITH_PORTAUDIO__" )

ENDMACRO(macro_use_portaudio)


