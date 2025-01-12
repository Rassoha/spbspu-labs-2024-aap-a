#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace sveshnikov
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t p) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;

  protected:
    void unsafe_scale(double k);
  };
}

#endif
