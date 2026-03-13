cmake_minimum_required(VERSION 3.20)

project(vision
  VERSION 0.1.0
  DESCRIPTION "Vix.AI Vision: image primitives, detector, tracker, OCR (header-only v0)"
  LANGUAGES CXX)

option(VIX_AI_VISION_BUILD_TESTS "Build vision tests" ON)
option(VIX_AI_VISION_INSTALL     "Install vision targets" ON)
option(VIX_AI_VISION_WARNINGS    "Enable extra warnings" ON)

# ---- Library target ---------------------------------------------------------
add_library(vix_ai_vision INTERFACE)
add_library(Vix::AI::vision ALIAS vix_ai_vision)

target_include_directories(vix_ai_vision INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(vix_ai_vision INTERFACE cxx_std_20)

if(DEFINED VIX_AI_VERSION)
  set(PROJECT_VERSION ${VIX_AI_VERSION})
endif()

target_compile_definitions(vix_ai_vision INTERFACE VIX_AI_VISION_VERSION="${PROJECT_VERSION}")

if(VIX_AI_VISION_WARNINGS)
  if(MSVC)
    target_compile_options(vix_ai_vision INTERFACE /W4 /permissive-)
  else()
    target_compile_options(vix_ai_vision INTERFACE -Wall -Wextra -Wpedantic)
  endif()
endif()

# ---- Tests ------------------------------------------------------------------
if(VIX_AI_VISION_BUILD_TESTS)
  enable_testing()
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests")
    add_subdirectory(tests)
  endif()
endif()

# ---- Install / Package ------------------------------------------------------
if(VIX_AI_VISION_INSTALL)
  include(GNUInstallDirs)
  include(CMakePackageConfigHelpers)

  install(TARGETS vix_ai_vision
          EXPORT vix_ai_visionTargets)

  install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

  install(EXPORT vix_ai_visionTargets
          FILE vix_ai_visionTargets.cmake
          NAMESPACE Vix::AI::
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai/vision)

  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_visionConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_visionConfig.cmake
"include(\"\${CMAKE_CURRENT_LIST_DIR}/vix_ai_visionTargets.cmake\")\n")

  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_visionConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/vix_ai_visionConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai/vision)
endif()
