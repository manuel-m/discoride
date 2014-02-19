
set(DR3_MAIN dr3)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(DR3_MAIN "${DR3_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable(${DR3_MAIN} dr3.cpp)
#add_splint(${DR3_MAIN} dr3.cpp)

target_link_libraries (${DR3_MAIN} ui_glfw ui_wids ui drtrace)

#target_link_libraries (${DR3_MAIN} ${TAGLIB_LIBRARIES})
#target_link_libraries (${DR3_MAIN} ${Cairo_LIBRARIES})
#target_link_libraries (${DR3_MAIN} ${MPG123_LIBRARIES})
#target_link_libraries (${DR3_MAIN} ${PORTAUDIO_LIBRARIES})

target_link_libraries (${DR3_MAIN} ${GLFW_A})
target_link_libraries (${DR3_MAIN} ${OpenGL_LIBRARIES})
target_link_libraries (${DR3_MAIN} ${X11_LIBRARIES})
target_link_libraries (${DR3_MAIN} ${XRANDR_LIBRARIES})
target_link_libraries (${DR3_MAIN} ${TINYCTHREAD_A})
target_link_libraries (${DR3_MAIN} -lpthread)
target_link_libraries (${DR3_MAIN} -lXxf86vm -lXi)
 
