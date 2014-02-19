set(S07_MAIN sample07_drFltk)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S07_MAIN "${S07_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S07_MAIN} sample07_drFltk.cpp)

target_link_libraries (${S07_MAIN} ui_fltk )
target_link_libraries (${S07_MAIN} ui_wids)
target_link_libraries (${S07_MAIN} ui )
target_link_libraries (${S07_MAIN} drtrace )
target_link_libraries (${S07_MAIN} ${FLTK_A})
target_link_libraries (${S07_MAIN} ${X11_LIBRARIES})
target_link_libraries (${S07_MAIN} -lfontconfig)
target_link_libraries (${S07_MAIN} -lXft)
target_link_libraries (${S07_MAIN} -lXext)
target_link_libraries (${S07_MAIN} -lXinerama)
target_link_libraries (${S07_MAIN} -ldl)
target_link_libraries (${S07_MAIN} -lpthread)





