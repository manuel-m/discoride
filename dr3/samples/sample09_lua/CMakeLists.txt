set(S09_MAIN sample09_lua)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S09_MAIN "${S09_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S09_MAIN} sample09_lua.c)

target_link_libraries (${S09_MAIN} drconfig )
target_link_libraries (${S09_MAIN} drtrace )
target_link_libraries (${S09_MAIN} lua )
target_link_libraries (${S09_MAIN} -lm )
target_link_libraries (${S09_MAIN} -ldl )


