#include "ring.hpp"
#include <cmath>
#include <stdexcept>

tkach::Ring::Ring(point_t center, double outer_radius, double inner_radius)
{
  if (outer_radius <= inner_radius)
  {
    throw std::logic_error("Outer radius is lesser than inner_radius or equal to it");
  }
  center_ = center;
  outer_radius_ = outer_radius;
  inner_radius_ = inner_radius; 
}
double tkach::Ring::getArea() const noexcept
{
  return M_PI * (outer_radius_ * outer_radius_ - inner_radius_ * inner_radius_);
}
tkach::rectangle_t tkach::Ring::getFrameRect() const noexcept
{
  rectangle_t frame_rect;
  frame_rect.height = 2 * outer_radius_;
  frame_rect.width = 2 * outer_radius_;
  frame_rect.pos.x = center_.x;
  frame_rect.pos.y = center_.y;
  return frame_rect;
}
void tkach::Ring::move(double add_to_x, double add_to_y) noexcept
{
  center_.x += add_to_x;
  center_.y += add_to_y;
}
void tkach::Ring::move(point_t point_to_move) noexcept
{
  center_ = point_to_move;
}
void tkach::Ring::scale(double multiplier) noexcept
{
  outer_radius_ *= multiplier;
  inner_radius_ *= multiplier;
}