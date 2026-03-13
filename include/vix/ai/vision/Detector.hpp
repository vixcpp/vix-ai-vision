/**
 * @file Detector.hpp
 * @author Gaspard Kirira
 *
 * Copyright 2025, Gaspard Kirira. All rights reserved.
 * https://github.com/vixcpp/vix
 * Use of this source code is governed by a MIT license that can be found in the License file.
 *
 * Vix.cpp
 */
#ifndef VIX_AI_VISION_DETECTOR_HPP
#define VIX_AI_VISION_DETECTOR_HPP

#include <vector>
#include <array>
#include "Image.hpp"

namespace vix::ai::vision
{
  using BBox = std::array<int, 4>;

  struct Detector
  {
    std::vector<BBox> detect(const Image &img) const
    {
      img.assert_not_empty("Detector::detect");
      return {};
    }
  };

} // namespace vix::ai::vision

#endif
