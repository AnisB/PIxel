cmake_minimum_required(VERSION 3.0.2)

project(pixel)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

IF(SILENT)
  add_definitions( -D _SILENT )
ENDIF(SILENT)

SET(CMAKE_MACRO_DIRS "${PROJECT_SOURCE_DIR}/cmake/")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/;${CMAKE_MODULE_PATH}")

# Setting the folder data
set(SOURCES "${PROJECT_SOURCE_DIR}/src/")
set(TEST "${PROJECT_SOURCE_DIR}/test/")
set(PROGRAM "${PROJECT_SOURCE_DIR}/program/")

include(${CMAKE_MACRO_DIRS}/Macros.cmake)

# Setting the needs
IF(UNIX AND NOT APPLE)
  add_definitions( -D__posix__ )
  add_definitions( -D LINUX )
  add_definitions(-std=c++11) 
ENDIF()

IF(APPLE)
  add_definitions( -DMACOSX)
  add_definitions( -D__posix__ )
  add_definitions(-std=c++11) 
ENDIF (APPLE)

IF(WIN32)
  add_definitions( -DWIN32 )
  set(CMAKE_CXX_FLAGS_DEBUG "/Md /Zi")
  set(CMAKE_CXX_FLAGS_RELEASE "/Md /Zi")
ENDIF()

# Generating the libraries
GENERATE_LIB("${SOURCES}/pix_base" pix_base "Pixel")
GENERATE_LIB("${SOURCES}/pix_memory" pix_memory "Pixel")
GENERATE_LIB("${SOURCES}/pix_containers" pix_containers "Pixel")

SET(CORELIBS ${CORELIBS} pix_base pix_memory pix_containers)

# Adding the tests if we should
add_subdirectory(${TEST})

# Adding the programs if we should
IF(PROGRAMS)
  add_subdirectory(${PROGRAM})
ENDIF()


 


