﻿#include <string>
#include <iostream>
#include "base-types.hpp"
#include "outputFunctions.hpp"

using asafov::getHash;
using asafov::ShapeFactory;
using asafov::scaleShapes;
using asafov::point_t;
using asafov::rectangle_t;
using asafov::Shape;

int main()
{
  Shape** shapes = new Shape*[10000];
  unsigned long long count = 0;

  unsigned long long hash = 0;
  while (true)
  {
    try
    {
      hash = getHash(std::cin);
    }
    catch (const std::logic_error & e)
    {
      for (size_t i = 0; i < count; i++)
      {
        delete shapes[i];
      }
      delete[] shapes;
      std::cerr << "in err\n";
      return 1;
    }
    if (hash == 'S' * 'C' * 'A' * 'L')
    {
      break;
    }
    else if (hash == 0)
    {
    }
    else
    {
      count++;
      try
      {
        shapes[count-1] = ShapeFactory(hash, std::cin);
      }
      catch (const std::logic_error & e)
      {
        std::cerr << "shape err\n";
        count--;
      }
    }
  }

  point_t pos;
  double scale = 0;
  std::cin >> pos.x >> pos.y >> scale;
  if (scale <= 0)
  {
    for (size_t i = 0; i < count; i++)
    {
      delete shapes[i];
    }
    delete[] shapes;
    return 1;
  }
  try
  {
    scaleShapes(shapes, count, pos, scale, std::cout);
  }
  catch (const std::logic_error & e)
  {
    for (size_t i = 0; i < count; i++)
    {
      delete shapes[i];
    }
    delete[] shapes;
    return 1;
  }
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
  return 0;
}
