cmake_minimum_required(VERSION 3.16)

project(
  WatchUi
  VERSION 0.1
  LANGUAGES CXX)

# Ensure we find the Qt package
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the Qt libraries
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)

# Define source files
set(PROJECT_SOURCES
    main.cpp
    watchUi.cpp
    watchUi.h
    lights.cpp
    lights.h
    patternMaker.cpp
    patternMaker.h
    form.ui)

# Set RPATH options
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# Use qt_add_executable to create the executable
qt_add_executable(WatchUi
    ${PROJECT_SOURCES}  # This should be a list of source files
)

# Link the required Qt libraries
target_link_libraries(WatchUi PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core)

# Set properties for the executable
set_target_properties(WatchUi PROPERTIES
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Installation rules
include(GNUInstallDirs)
install(TARGETS WatchUi
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  BUNDLE DESTINATION .
)

# Finalize Qt6 executable if using Qt6
if(${QT_VERSION_MAJOR} EQUAL 6)
  qt_finalize_executable(WatchUi)
endif()
