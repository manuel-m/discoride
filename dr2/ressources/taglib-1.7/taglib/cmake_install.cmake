# Install script for directory: /home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libtag.a")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/local/lib" TYPE STATIC_LIBRARY FILES "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/libtag.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/taglib/tag.h;/usr/local/include/taglib/fileref.h;/usr/local/include/taglib/audioproperties.h;/usr/local/include/taglib/taglib_export.h")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/tag.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/fileref.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/audioproperties.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/taglib_export.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/asf/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/ogg/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/flac/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/ape/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpc/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mp4/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/wavpack/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/trueaudio/cmake_install.cmake")
  INCLUDE("/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/riff/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

