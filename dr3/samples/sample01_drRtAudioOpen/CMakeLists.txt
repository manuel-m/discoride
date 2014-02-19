set(S01_MAIN sample01_drRtAudioOpen)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S01_MAIN "${S01_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S01_MAIN} sample01_drRtAudioOpen.cpp)

target_link_libraries (${S01_MAIN} audio_rtaudio)
target_link_libraries (${S01_MAIN} loader_mpg123)
target_link_libraries (${S01_MAIN} audio)
target_link_libraries (${S01_MAIN} audio_process)
target_link_libraries (${S01_MAIN} audio_proxy)
target_link_libraries (${S01_MAIN} ${RTAUDIO_A})
target_link_libraries (${S01_MAIN} ${MPG123_A})
target_link_libraries (${S01_MAIN} drtrace)
target_link_libraries (${S01_MAIN} -lasound)
target_link_libraries (${S01_MAIN} -lpthread)







