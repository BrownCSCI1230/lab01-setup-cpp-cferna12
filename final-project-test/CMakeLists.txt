cmake_minimum_required(VERSION 3.16)

# Sets project name
project(final-project-test LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Sets C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specifies required Qt components
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGL)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)

# Specifies .cpp and .h files to be passed to the compiler
add_executable(${PROJECT_NAME}
  src/main.cpp

  src/glwidget.cpp
  src/settings.cpp
  src/mainwindow.cpp
  src/terraingenerator.cpp

  src/glwidget.h
  src/mainwindow.h
  src/terraingenerator.h
  src/settings.h
)

# Specifies other files
qt_add_resources(${PROJECT_NAME} "Resources"
  PREFIX
  "/"
  FILES
  resources/shader/vertex.vert
  resources/shader/fragment.frag
  resources/shader/obj_vertex.vert
)

# GLEW: this creates its library and allows you to `#include "GL/glew.h"`
add_library(StaticGLEW STATIC glew/src/glew.c)
include_directories(${PROJECT_NAME} PRIVATE glew/include)

# Specifies libraries to be linked (Qt components, glew, etc)
target_link_libraries(${PROJECT_NAME} PRIVATE
  Qt::Core
  Qt::Widgets
  Qt::OpenGL
  Qt::OpenGLWidgets
  Qt::Gui
  StaticGLEW
)

# GLEW: this provides support for Windows (including 64-bit)
if (WIN32)
  add_compile_definitions(GLEW_STATIC)
  target_link_libraries(${PROJECT_NAME} PRIVATE
    opengl32
    glu32
  )
endif()

# Set this flag to silence warnings on Windows
if (MSVC OR MSYS OR MINGW)
  set(CMAKE_CXX_FLAGS "-Wno-volatile")
endif()

# Set this flag to silence warnings on MacOS
if (APPLE)
  set(CMAKE_CXX_FLAGS "-Wno-deprecated-volatile")
endif()
