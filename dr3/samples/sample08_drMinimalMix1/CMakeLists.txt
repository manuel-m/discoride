set(S08a_MAIN sample08_drMinimalMix1)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S08a_MAIN "${S08a_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_library (sample08 sample08.cpp)

add_executable (${S08a_MAIN} sample08_drMinimalMix1.cpp)

target_link_libraries (${S08a_MAIN} ui_minimal )
target_link_libraries (${S08a_MAIN} ui )
target_link_libraries (${S08a_MAIN} sample08)
target_link_libraries (${S08a_MAIN} audio_portaudio)
target_link_libraries (${S08a_MAIN} loader_mpg123)
target_link_libraries (${S08a_MAIN} audio)
target_link_libraries (${S08a_MAIN} audio_process)
target_link_libraries (${S08a_MAIN} audio_proxy)
target_link_libraries (${S08a_MAIN} ${PORTAUDIO_A})
target_link_libraries (${S08a_MAIN} ${MPG123_A})
target_link_libraries (${S08a_MAIN} -lasound)
target_link_libraries (${S08a_MAIN} drtrace)
target_link_libraries (${S08a_MAIN} -lpthread)

set(S08b_MAIN sample08_drFltkMix1)

add_executable (${S08b_MAIN} sample08_drFltkMix1.cpp)

target_link_libraries (${S08b_MAIN} ui_fltk )
target_link_libraries (${S08b_MAIN} ui )
target_link_libraries (${S08b_MAIN} sample08)
target_link_libraries (${S08b_MAIN} audio_portaudio)
target_link_libraries (${S08b_MAIN} loader_mpg123)
target_link_libraries (${S08b_MAIN} audio)
target_link_libraries (${S08b_MAIN} audio_process)
target_link_libraries (${S08b_MAIN} audio_proxy)
target_link_libraries (${S08b_MAIN} drtrace )
target_link_libraries (${S08b_MAIN} ${PORTAUDIO_A})
target_link_libraries (${S08b_MAIN} ${MPG123_A})
target_link_libraries (${S08b_MAIN} -lasound)
target_link_libraries (${S08b_MAIN} ${FLTK_A})
target_link_libraries (${S08b_MAIN} ${X11_LIBRARIES})
target_link_libraries (${S08b_MAIN} -lfontconfig)
target_link_libraries (${S08b_MAIN} -lXft)
target_link_libraries (${S08b_MAIN} -lXext)
target_link_libraries (${S08b_MAIN} -lXinerama)
target_link_libraries (${S08b_MAIN} -ldl)
target_link_libraries (${S08b_MAIN} -lpthread)




