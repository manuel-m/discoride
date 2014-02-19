find_path(TAGLIB_INCLUDE_DIR NAMES taglib/tag_c.h
          PATH_SUFFIXES Taglib
          DOC "The taglib include directory"
)

find_library(TAGLIB_LIBRARY NAMES tag_c
          DOC "The taglib library"
)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TAGLIB DEFAULT_MSG TAGLIB_LIBRARY TAGLIB_INCLUDE_DIR)

if(TAGLIB_FOUND)
  set( TAGLIB_LIBRARIES ${TAGLIB_LIBRARY} )
  set( TAGLIB_INCLUDE_DIRS ${TAGLIB_INCLUDE_DIR} )
endif()

mark_as_advanced(TAGLIB_INCLUDE_DIR TAGLIB_LIBRARY)