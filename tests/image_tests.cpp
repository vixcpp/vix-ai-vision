#include <cassert>
#include <vix/ai/vision/Image.hpp>
using namespace vix::ai::vision;

int main()
{
    Image e;
    (void)e;
    assert(e.empty());
    Image a(640, 480);
    assert(!a.empty());
    assert(a.width() == 640);
    assert(a.height() == 480);
    assert(a.area() == 640u * 480u);
    (void)a;
    return 0;
}
