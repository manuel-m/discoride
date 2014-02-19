include_directories (${Cairo_INCLUDE_DIRS})

add_subdirectory (lib)
add_subdirectory (gui)
add_subdirectory (conf)

set(DR2_MAIN dr2)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(DR2_MAIN "${DR2_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable(${DR2_MAIN} main.c)

target_link_libraries (${DR2_MAIN} gui)
target_link_libraries (${DR2_MAIN} conf)
target_link_libraries (${DR2_MAIN} ride)

target_link_libraries (${DR2_MAIN} /usr/local/lib/libtag_c.so)
target_link_libraries (${DR2_MAIN} /usr/local/lib/libtag.so)

target_link_libraries (${DR2_MAIN} ${Cairo_LIBRARIES})
target_link_libraries (${DR2_MAIN} ${MPG123_LIBRARIES})
target_link_libraries (${DR2_MAIN} ${PORTAUDIO_LIBRARIES})
target_link_libraries (${DR2_MAIN} ${GLFW_LIBRARIES})
target_link_libraries (${DR2_MAIN} ${OpenGL_LIBRARIES})

target_link_libraries (${DR2_MAIN} ${X11_LIBRARIES})
target_link_libraries (${DR2_MAIN} ${XRANDR_LIBRARIES})


# target_link_libraries (${DR2_MAIN} ${LIBTAG_C_A})
# target_link_libraries (${DR2_MAIN} ${LIBTAG_A})
target_link_libraries (${DR2_MAIN} -lz)

target_link_libraries (${DR2_MAIN} -lpthread)
target_link_libraries (${DR2_MAIN} -lm)


install (TARGETS ${DR2_MAIN} DESTINATION bin)