/**
 * @file Tracker.hpp
 * @author Gaspard Kirira
 *
 * Copyright 2025, Gaspard Kirira. All rights reserved.
 * https://github.com/vixcpp/vix
 * Use of this source code is governed by a MIT license that can be found in the License file.
 *
 * Vix.cpp
 */
#ifnde VIX_AI_VISION_TRACKER_HPP
#define VIX_AI_VISION_TRACKER_HPP

#include <cstddef>
#include <vix/ai/vision/Image.hpp>

namespace vix::ai::vision
{
  struct Tracker
  {
    std::size_t update(const Image &img)
    {
      img.assert_not_empty("Tracker::update");
      return ++frames_;
    }

  private:
    std::size_t frames_{0};
  };

} // namespace vix::ai::vision

#endif
