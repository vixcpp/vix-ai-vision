#include <cassert>
#include <stdexcept>
#include <vix/ai/vision/Tracker.hpp>
using namespace vix::ai::vision;

int main()
{
  Tracker t;

  try
  {
    (void)t.update(Image{});
    assert(false && "Expected throw");
  }
  catch (const std::invalid_argument &)
  {
  }

  auto f1 = t.update(Image{4, 4});
  auto f2 = t.update(Image{4, 4});
  assert(f1 == 1 && f2 == 2);
  (void)f1;
  (void)f2;
  return 0;
}
