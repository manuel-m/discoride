set(S02_MAIN sample02_drPortaudioOpen)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S02_MAIN "${S02_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S02_MAIN} sample02_drPortaudioOpen.cpp)

target_link_libraries (${S02_MAIN} loader_mpg123)
target_link_libraries (${S02_MAIN} audio_portaudio)
target_link_libraries (${S02_MAIN} audio)
target_link_libraries (${S02_MAIN} audio_process)
target_link_libraries (${S02_MAIN} audio_proxy)
target_link_libraries (${S02_MAIN} ${PORTAUDIO_A})
target_link_libraries (${S02_MAIN} ${MPG123_A})
target_link_libraries (${S02_MAIN} drtrace)
target_link_libraries (${S02_MAIN} -lasound)
target_link_libraries (${S02_MAIN} -lpthread)
target_link_libraries (${S02_MAIN} -lm)







