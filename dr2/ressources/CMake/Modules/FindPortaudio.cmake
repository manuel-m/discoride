find_path(PORTAUDIO_INCLUDE_DIR NAMES portaudio.h
          PATH_SUFFIXES portaudio
          DOC "The portaudio include directory"
)

find_library(PORTAUDIO_LIBRARY NAMES portaudio
          DOC "The portaudio library"
)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PORTAUDIO DEFAULT_MSG PORTAUDIO_LIBRARY PORTAUDIO_INCLUDE_DIR)

if(PORTAUDIO_FOUND)
  set( PORTAUDIO_LIBRARIES ${PORTAUDIO_LIBRARY} )
  set( PORTAUDIO_INCLUDE_DIRS ${PORTAUDIO_INCLUDE_DIR} )
endif()

mark_as_advanced(PORTAUDIO_INCLUDE_DIR PORTAUDIO_LIBRARY)
