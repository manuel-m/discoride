set(S10_MAIN sample10_lacewing)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(S10_MAIN "${S10_MAIN}_d")
endif (CMAKE_BUILD_TYPE MATCHES Debug)

add_executable (${S10_MAIN} sample10_lacewing.c)

target_link_libraries (${S10_MAIN} drconfig )
target_link_libraries (${S10_MAIN} drtrace )
target_link_libraries (${S10_MAIN} ${LACEWING_A})
target_link_libraries (${S10_MAIN} -lssl )
target_link_libraries (${S10_MAIN} -lcrypto )
target_link_libraries (${S10_MAIN} -lz )
target_link_libraries (${S10_MAIN} -lpthread )



