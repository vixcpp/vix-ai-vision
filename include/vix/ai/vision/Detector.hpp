#pragma once
#include <vector>
#include <array>
#include "Image.hpp"

namespace vix::ai::vision
{

    // Bounding box: {x, y, w, h}
    using BBox = std::array<int, 4>;

    struct Detector
    {
        // v0 stub: returns empty vec, but checks image validity
        std::vector<BBox> detect(const Image &img) const
        {
            img.assert_not_empty("Detector::detect");
            return {};
        }
    };

} // namespace vix::ai::vision
