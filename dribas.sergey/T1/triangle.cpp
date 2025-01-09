#include "triangle.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

dribas::Triangle::Triangle(point_t a, point_t b, point_t c):
  a_(a),
  b_(b),
  c_(c)
{
  if ((a_.x * (b_.y -c_.y) + b_.x * (c_.y - a_.y) + c_.x * (a_.y - b_.y)) == 0) {
    throw std::invalid_argument("error arguments for triangle\n");
  }
}
double dribas::Triangle::getArea() const
{
    return std::abs(((b_.x - a_.x) * (c_.y - a_.y) - (c_.x - a_.x) * (b_.y - a_.y))) / 2.0;
}
dribas::rectangle_t dribas::Triangle::getFrameRect() const
{
  double maxX = std::max(a_.x, std::max(b_.x, c_.x));
  double maxY = std::max(a_.y, std::max(b_.y, c_.y));
  double minX = std::min(a_.x, std::min(b_.x, c_.x));
  double minY = std::min(a_.y, std::min(b_.y, c_.y));
  dribas::rectangle_t result;
  result.height = maxY - minY;
  result.width = maxX - minX;
  result.pos.x = minX + (result.width / 2.0);
  result.pos.y = minY + (result.height / 2.0);
  return result;
}
void dribas::Triangle::move(point_t centerP)
{
  dribas::point_t pos;
  pos.x = std::abs(a_.x + b_.x + c_.x) / 3.0;
  pos.y = std::abs(a_.y + b_.y + c_.y) / 3.0;
  double moveX = centerP.x - pos.x;
  double moveY = centerP.y - pos.y;
  a_.x += moveX;
  a_.y += moveY;
  b_.x += moveX;
  b_.y += moveY;
  c_.x += moveX;
  c_.y += moveY;
}
void dribas::Triangle::move(double x, double y)
{
  a_.x += x;
  a_.y += y;
  b_.x += x;
  b_.y += y;
  c_.x += x;
  c_.y += y;
}
void dribas::Triangle::scale(double ratio)
{
  if (ratio<= 0) {
    throw std::invalid_argument("under zero ratio\n");
  }
  point_t pos;
  pos.x = std::abs(a_.x + b_.x + c_.x) / 3.0;
  pos.y = std::abs(a_.y + b_.y + c_.y) / 3.0;
  a_.x = (a_.x - pos.x) * ratio + pos.x;
  a_.y = (a_.y - pos.y) * ratio + pos.y;
  b_.x = (b_.x - pos.x) * ratio + pos.x;
  b_.y = (b_.y - pos.y) * ratio + pos.y;
  c_.x = (c_.x - pos.x) * ratio + pos.x;
  c_.y = (c_.y - pos.y) * ratio + pos.y;
}
