set(S04_MAIN sample04_drMpg123_Portaudio)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S04_MAIN "${S04_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S04_MAIN} sample04_drMpg123_Portaudio.cpp)

target_link_libraries (${S04_MAIN} audio_portaudio)
target_link_libraries (${S04_MAIN} loader_mpg123)
target_link_libraries (${S04_MAIN} audio)
target_link_libraries (${S04_MAIN} audio_process)
target_link_libraries (${S04_MAIN} audio_proxy)
target_link_libraries (${S04_MAIN} ${PORTAUDIO_A})
target_link_libraries (${S04_MAIN} ${MPG123_A})
target_link_libraries (${S04_MAIN} drtrace)
target_link_libraries (${S04_MAIN} -lasound)
target_link_libraries (${S04_MAIN} -lpthread)









