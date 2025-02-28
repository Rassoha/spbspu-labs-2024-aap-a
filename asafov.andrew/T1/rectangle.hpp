#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace asafov
{
  class Rectangle final: public Shape
  {
    virtual void unsafeScale(double scale) = 0;
  public:
    Rectangle(point_t lb, point_t rt);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double dx, double dy);
    void scale(double scale);
  private:
    point_t lb_;
    point_t rt_;
  };
}
#endif
