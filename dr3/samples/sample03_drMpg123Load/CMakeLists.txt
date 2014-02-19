set(S03_MAIN sample03_drMpg123Load)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S03_MAIN "${S03_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S03_MAIN} sample03_drMpg123Load.cpp)

target_link_libraries (${S03_MAIN} audio_portaudio)
target_link_libraries (${S03_MAIN} audio)
target_link_libraries (${S03_MAIN} audio_process)
target_link_libraries (${S03_MAIN} loader_mpg123)
target_link_libraries (${S03_MAIN} audio_proxy)
target_link_libraries (${S03_MAIN} ${PORTAUDIO_A})
target_link_libraries (${S03_MAIN} ${MPG123_A})
target_link_libraries (${S03_MAIN} drtrace)
target_link_libraries (${S03_MAIN} -lasound)
target_link_libraries (${S03_MAIN} -lpthread)









