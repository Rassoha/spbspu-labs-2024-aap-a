#include <cstddef>
#include <iostream>
#include "getShapeInfo.hpp"
#include "shape.hpp"

void clearStr(char** stack, size_t stackSize)
{
  for (size_t i = 0; *(stack+i) && i <stackSize; i++) {
    delete (stack + i);
  }
}

int main()
{
  constexpr size_t shapesSize = 10000;
  dribas::Shape * myShapes[shapesSize] = {};
  int shapeCount = 0;
  shapeCount = dribas::getShapeInfo(std::cin, std::cerr, std::cout, myShapes);
  if (shapeCount == -1) {
    return 1;
  }
  dribas::clear(myShapes, shapeCount);
  return 0;
}
