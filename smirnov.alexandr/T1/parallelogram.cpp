#include "parallelogram.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

smirnov::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  vertex1{p1},
  vertex2{p2},
  vertex3{p3},
  vertex4{p1.x + p3.x - p2.x, p1.y + p3.y - p2.y}
{
  if ((p1.x == p3.x && p2.y == p3.y) || (p2.x == p3.x && p1.y == p3.y))
  {
    throw std::invalid_argument("Incorrect coordinates for the parallelogram");
  }
  if (!(p1.y == p2.y || p1.y == p3.y || p2.y == p3.y))
  {
    throw std::invalid_argument("The sides of the parallelogram must be parallel to the X-axis");
  }
}

double smirnov::Parallelogram::getArea() const
{
  double vector1X = vertex2.x - vertex1.x;
  double vector1Y = vertex2.y - vertex1.y;
  double vector2X = vertex3.x - vertex1.x;
  double vector2Y = vertex3.y - vertex1.y;
  return std::abs(vector1X * vector2Y - vector1Y * vector2X);
}

smirnov::rectangle_t smirnov::Parallelogram::getFrameRect() const
{
  point_t center;
  center.x = (vertex1.x + vertex2.x + vertex3.x + vertex4.x) / 4;
  center.y = (vertex1.y + vertex2.y + vertex3.y + vertex4.y) / 4;
  double minX = std::min({vertex1.x, vertex2.x, vertex3.x, vertex4.x});
  double maxX = std::max({vertex1.x, vertex2.x, vertex3.x, vertex4.x});
  double minY = std::min({vertex1.y, vertex2.y, vertex3.y, vertex4.y});
  double maxY = std::max({vertex1.y, vertex2.y, vertex3.y, vertex4.y});
  return {center, maxX- minX, maxY - minY};
}

void smirnov::Parallelogram::move(point_t newPos)
{
  point_t currentPos = getFrameRect().pos;
  double dx = newPos.x - currentPos.x;
  double dy = newPos.y - currentPos.y;
  move(dx, dy);
}

void smirnov::Parallelogram::move(double dx, double dy)
{
  applyMove(vertex1, dx, dy);
  applyMove(vertex2, dx, dy);
  applyMove(vertex3, dx, dy);
  applyMove(vertex4, dx, dy);
}

void smirnov::Parallelogram::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Zoom coefficient must be positive");
  }
  point_t center = getFrameRect().pos;
  applyScale(vertex1, center, k);
  applyScale(vertex2, center, k);
  applyScale(vertex3, center, k);
  applyScale(vertex4, center, k);
}
