#include <cassert>
#include <stdexcept>
#include <vix/ai/vision/OCR.hpp>
using namespace vix::ai::vision;

int main()
{
  OCR ocr;

  try
  {
    (void)ocr.recognize(Image{});
    assert(false && "Expected throw");
  }
  catch (const std::invalid_argument &)
  {
  }

  auto txt = ocr.recognize(Image{32, 32});
  assert(txt.empty());
  (void)txt;
  return 0;
}
