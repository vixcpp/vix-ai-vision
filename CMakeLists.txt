#  @file CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
#  @brief Vix AI Vision module.
#
#  Header-only computer vision module for Vix.
#  Provides image primitives and vision-oriented APIs such as
#  detection, tracking, and OCR-related building blocks.
#
#  Public targets:
#    - vix_ai_vision
#    - vix::ai::vision
#
#  Installation:
#    Installs headers, exported targets, and CMake package files
#    for find_package(vix_ai_vision CONFIG REQUIRED).

cmake_minimum_required(VERSION 3.20)

project(vix_ai_vision VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(VIX_AI_VISION_BUILD_TESTS "Build vix_ai_vision tests" OFF)
option(VIX_AI_VISION_INSTALL "Install vix_ai_vision targets" ON)
option(VIX_AI_VISION_WARNINGS "Enable extra warnings for vix_ai_vision" ON)

if(DEFINED VIX_AI_VERSION)
  set(PROJECT_VERSION ${VIX_AI_VERSION})
endif()

add_library(vix_ai_vision INTERFACE)
add_library(vix::ai::vision ALIAS vix_ai_vision)

target_include_directories(vix_ai_vision INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(vix_ai_vision INTERFACE cxx_std_20)

target_compile_definitions(vix_ai_vision INTERFACE
  VIX_AI_VISION_VERSION="${PROJECT_VERSION}"
)

if(VIX_AI_VISION_WARNINGS)
  if(MSVC)
    target_compile_options(vix_ai_vision INTERFACE /W4 /permissive-)
  else()
    target_compile_options(vix_ai_vision INTERFACE
      -Wall
      -Wextra
      -Wpedantic
    )
  endif()
endif()

if(VIX_AI_VISION_BUILD_TESTS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()

if(VIX_AI_VISION_INSTALL)
  install(TARGETS vix_ai_vision
    EXPORT vix_ai_visionTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

  install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
  )

  install(EXPORT vix_ai_visionTargets
    FILE vix_ai_visionTargets.cmake
    NAMESPACE vix::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_vision
  )

  configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/vix_ai_visionConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_visionConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_vision"
  )

  write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_visionConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

  install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_visionConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_visionConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_vision"
  )
endif()

message(STATUS "vix::ai::vision configured (${PROJECT_VERSION})")
message(STATUS "Include dir: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install: ${VIX_AI_VISION_INSTALL}")
message(STATUS "Tests: ${VIX_AI_VISION_BUILD_TESTS}")
