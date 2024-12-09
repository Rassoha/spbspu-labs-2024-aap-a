#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp""
class Ellipse: public Shape
{
public:
  double getArea();
  rectangle getFrameRect();
  void move(point_t k);
  void move(double x, double y);
  void scale(double n);
private:
  point_t a;
  point_t b;
  point_t c;
  point_t d;
  rectangle base_rectangle;
};
#endif
