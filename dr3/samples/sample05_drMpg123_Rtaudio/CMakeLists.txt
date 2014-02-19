set(S05_MAIN sample05_drMpg123_Rtaudio)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S05_MAIN "${S05_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S05_MAIN} sample05_drMpg123_Rtaudio.cpp)

target_link_libraries (${S05_MAIN} audio_rtaudio)
target_link_libraries (${S05_MAIN} loader_mpg123)
target_link_libraries (${S05_MAIN} audio)
target_link_libraries (${S05_MAIN} audio_process)
target_link_libraries (${S05_MAIN} audio_proxy)
target_link_libraries (${S05_MAIN} ${RTAUDIO_A})
target_link_libraries (${S05_MAIN} ${MPG123_A})
target_link_libraries (${S05_MAIN} drtrace)
target_link_libraries (${S05_MAIN} -lasound)
target_link_libraries (${S05_MAIN} -lpthread)









