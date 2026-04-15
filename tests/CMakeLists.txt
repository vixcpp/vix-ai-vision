cmake_minimum_required(VERSION 3.20)

#  @file test/CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
#  @brief Tests for the vix_ai_vision module.
#
#  Minimal assert-based tests for the header-only vision module.

add_executable(vix_ai_vision_test_image
  image_tests.cpp
)
target_link_libraries(vix_ai_vision_test_image
  PRIVATE
    vix::ai::vision
)
target_compile_features(vix_ai_vision_test_image PRIVATE cxx_std_20)
add_test(NAME vision_image COMMAND vix_ai_vision_test_image)

add_executable(vix_ai_vision_test_detector
  detector_tests.cpp
)
target_link_libraries(vix_ai_vision_test_detector
  PRIVATE
    vix::ai::vision
)
target_compile_features(vix_ai_vision_test_detector PRIVATE cxx_std_20)
add_test(NAME vision_detector COMMAND vix_ai_vision_test_detector)

add_executable(vix_ai_vision_test_ocr
  ocr_tests.cpp
)
target_link_libraries(vix_ai_vision_test_ocr
  PRIVATE
    vix::ai::vision
)
target_compile_features(vix_ai_vision_test_ocr PRIVATE cxx_std_20)
add_test(NAME vision_ocr COMMAND vix_ai_vision_test_ocr)

add_executable(vix_ai_vision_test_tracker
  tracker_tests.cpp
)
target_link_libraries(vix_ai_vision_test_tracker
  PRIVATE
    vix::ai::vision
)
target_compile_features(vix_ai_vision_test_tracker PRIVATE cxx_std_20)
add_test(NAME vision_tracker COMMAND vix_ai_vision_test_tracker)
