# Install script for directory: /home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames

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
   "/usr/local/include/taglib/attachedpictureframe.h;/usr/local/include/taglib/commentsframe.h;/usr/local/include/taglib/generalencapsulatedobjectframe.h;/usr/local/include/taglib/popularimeterframe.h;/usr/local/include/taglib/privateframe.h;/usr/local/include/taglib/relativevolumeframe.h;/usr/local/include/taglib/textidentificationframe.h;/usr/local/include/taglib/uniquefileidentifierframe.h;/usr/local/include/taglib/unknownframe.h;/usr/local/include/taglib/unsynchronizedlyricsframe.h;/usr/local/include/taglib/urllinkframe.h")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/commentsframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/privateframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/unknownframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/mpeg/id3v2/frames/urllinkframe.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

