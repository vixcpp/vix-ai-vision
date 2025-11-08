#pragma once
#include <cstddef>
#include <stdexcept>
#include <string>

namespace vix::ai::vision
{

    struct Image
    {
        std::size_t w{}; // width in pixels
        std::size_t h{}; // height in pixels

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
