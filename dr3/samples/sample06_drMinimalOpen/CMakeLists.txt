set(S06_MAIN sample06_drMinimalOpen)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S06_MAIN "${S06_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S06_MAIN} sample06_drMinimalOpen.cpp)

target_link_libraries (${S06_MAIN} ui_minimal ui drtrace )
target_link_libraries (${S06_MAIN} -lpthread)
#target_link_libraries (${S06_MAIN} -lXxf86vm)
#target_link_libraries (${S06_MAIN} -lXi)





