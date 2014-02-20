
file(GLOB audio_SOURCES *.cpp)
add_library (audio ${audio_SOURCES} )

add_subdirectory (process)
add_subdirectory (backends)
add_subdirectory (proxy)
add_subdirectory (loaders)


