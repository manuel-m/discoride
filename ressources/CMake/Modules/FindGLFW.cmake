find_path(GLFW_INCLUDE_DIR NAMES GL/glfw.h
          PATH_SUFFIXES glfw
          DOC "The glfw include directory"
)

find_library(GLFW_LIBRARY NAMES glfw
          DOC "The glfw library"
)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLFW DEFAULT_MSG GLFW_LIBRARY GLFW_INCLUDE_DIR)

if(GLFW_FOUND)
  set( GLFW_LIBRARIES ${GLFW_LIBRARY} )
  set( GLFW_INCLUDE_DIRS ${GLFW_INCLUDE_DIR} )
endif()

mark_as_advanced(GLFW_INCLUDE_DIR GLFW_LIBRARY)
