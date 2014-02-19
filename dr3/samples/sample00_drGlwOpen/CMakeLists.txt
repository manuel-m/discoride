set(S00_MAIN sample00_drGlfwOpen)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S00_MAIN "${S00_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)



add_executable (${S00_MAIN} sample00_drGlfwOpen.cpp)

target_link_libraries (${S00_MAIN} ui_glfw  )
target_link_libraries (${S00_MAIN} ui_wids )
target_link_libraries (${S00_MAIN} ui )
target_link_libraries (${S00_MAIN} drtrace )
target_link_libraries (${S00_MAIN} ${GLFW_A})
target_link_libraries (${S00_MAIN} ${OpenGL_LIBRARIES})
target_link_libraries (${S00_MAIN} ${X11_LIBRARIES})
target_link_libraries (${S00_MAIN} ${XRANDR_LIBRARIES})
target_link_libraries (${S00_MAIN} tinycthread)
target_link_libraries (${S00_MAIN} -lpthread)
target_link_libraries (${S00_MAIN} -lXxf86vm)
target_link_libraries (${S00_MAIN} -lXi)





