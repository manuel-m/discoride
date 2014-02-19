
MACRO(macro_use_rtaudio)

set( CURRENT_RTAUDIO_VERSION rtaudio-4.0.12 )
set( CURRENT_RTAUDIO_DIR ${PROJECT_SOURCE_DIR}/external_libs/rtaudio/${CURRENT_RTAUDIO_VERSION} )

set (RTAUDIO_A ${CURRENT_RTAUDIO_DIR}/librtaudio.a)
include_directories (${CURRENT_RTAUDIO_DIR})

set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__LINUX_ALSA__ -D__WITH_RTAUDIO__" )
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__LINUX_ALSA__ -D__WITH_RTAUDIO__" )

ENDMACRO(macro_use_rtaudio)


