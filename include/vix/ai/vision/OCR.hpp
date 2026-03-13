/**
 * @file OCR.hpp
 * @author Gaspard Kirira
 *
 * Copyright 2025, Gaspard Kirira. All rights reserved.
 * https://github.com/vixcpp/vix
 * Use of this source code is governed by a MIT license that can be found in the License file.
 *
 * Vix.cpp
 */
#ifndef VIX_AI_VISION_OCR_HPP
#define VIX_AI_VISION_OCR_HPP

#include <string>
#include <vix/ai/vision/Image.hpp>

namespace vix::ai::vision
{
  struct OCR
  {
    std::string recognize(const Image &img) const
    {
      img.assert_not_empty("OCR::recognize");
      return {};
    }
  };

} // namespace vix::ai::vision

#endif
