

find_package(CUnit REQUIRED)
include_directories (${CUNIT_INCLUDE_DIRS})

file(GLOB drTests_SOURCES *.c)

add_executable (test_lib ${drTests_SOURCES})

target_link_libraries (test_lib rUi drWids cunit)

# pour lancer auto avec cmake 
#add_custom_command(TARGET test_lib
#                   POST_BUILD
#                   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_lib
#                   VERBATIM)








