#pragma once
#include <cstddef>
#include "Image.hpp"

namespace vix::ai::vision
{

    struct Tracker
    {
        // v0 stub: returns incrementing pseudo-frame id to show statefulness later
        std::size_t update(const Image &img)
        {
            img.assert_not_empty("Tracker::update");
            return ++frames_;
        }

    private:
        std::size_t frames_{0};
    };

} // namespace vix::ai::vision
