#include <cassert>
#include <stdexcept>
#include <vix/ai/vision/Detector.hpp>
using namespace vix::ai::vision;

int main()
{
  Detector d;

  // empty image should throw
  try
  {
    (void)d.detect(Image{});
    assert(false && "Expected throw");
  }
  catch (const std::invalid_argument &)
  {
  }

  auto boxes = d.detect(Image{10, 10});
  assert(boxes.empty());
  (void)boxes;
  return 0;
}
