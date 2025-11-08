#pragma once
#include <string>
#include "Image.hpp"

namespace vix::ai::vision
{

    struct OCR
    {
        // v0 stub: returns empty string, but validates image
        std::string recognize(const Image &img) const
        {
            img.assert_not_empty("OCR::recognize");
            return {};
        }
    };

} // namespace vix::ai::vision
