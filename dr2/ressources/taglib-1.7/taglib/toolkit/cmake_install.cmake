# Install script for directory: /home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit

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
   "/usr/local/include/taglib/taglib.h;/usr/local/include/taglib/tstring.h;/usr/local/include/taglib/tlist.h;/usr/local/include/taglib/tlist.tcc;/usr/local/include/taglib/tstringlist.h;/usr/local/include/taglib/tbytevector.h;/usr/local/include/taglib/tbytevectorlist.h;/usr/local/include/taglib/tfile.h;/usr/local/include/taglib/tmap.h;/usr/local/include/taglib/tmap.tcc")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/taglib.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tstring.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tlist.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tlist.tcc"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tstringlist.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tbytevector.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tbytevectorlist.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tfile.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tmap.h"
    "/home/jam/Dropbox/dev/dr/dr2/ressources/taglib-1.7/taglib/toolkit/tmap.tcc"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

