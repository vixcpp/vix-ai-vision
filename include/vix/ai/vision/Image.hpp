/**
 * @file Image.hpp
 * @author Gaspard Kirira
 *
 * Copyright 2025, Gaspard Kirira. All rights reserved.
 * https://github.com/vixcpp/vix
 * Use of this source code is governed by a MIT license that can be found in the License file.
 *
 * Vix.cpp
 */
#ifndef VIX_AI_VISION_IMAGE_HPP
#define VIX_AI_VISION_IMAGE_HPP

#include <cstddef>
#include <stdexcept>
#include <string>

namespace vix::ai::vision
{

  struct Image
  {
    // width in pixels
    std::size_t w{};

    // height in pixels
    std::size_t h{};

    constexpr Image() = default;
    constexpr Image(std::size_t width, std::size_t height) : w(width), h(height) {}
    constexpr bool empty() const noexcept { return w == 0 || h == 0; }
    constexpr std::size_t width() const noexcept { return w; }
    constexpr std::size_t height() const noexcept { return h; }
    constexpr std::size_t area() const noexcept { return w * h; }

    void assert_not_empty(const char *where) const
    {
      if (empty())
        throw std::invalid_argument(std::string(where) + ": image is empty");
    }
  };

} // namespace vix::ai::vision

#endif
