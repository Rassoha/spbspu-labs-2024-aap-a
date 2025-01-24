#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"

zakirov::Rectangle::Rectangle(point_t bottom_left, point_t top_right):
  bottom_left_(bottom_left),
  top_right_(top_right)
{
  if (bottom_left_.x >= top_right_.x || bottom_left_.y >= top_right_.y)
  {
    throw std::invalid_argument("Incorrect data");
  }
}

double zakirov::Rectangle::getArea() const
{
  double distance_x = get_distance_x(top_right_, bottom_left_);
  double distance_y = get_distance_y(top_right_, bottom_left_);
  return distance_x * distance_y;
}

zakirov::rectangle_t zakirov::Rectangle::getFrameRect() const
{
  double width = get_distance_x(top_right_, bottom_left_);
  double height = get_distance_y(top_right_, bottom_left_);
  point_t position = get_middle(top_right_, bottom_left_);

  return {width, height, position};
}

void zakirov::Rectangle::move(point_t target)
{
  point_t center = getFrameRect().pos;
  point_t bias = {target.x - center.x, target.y - center.y};
  move_point(& top_right_, bias.x, bias.y);
  move_point(& bottom_left_, bias.x, bias.y);
}

void zakirov::Rectangle::move(double bias_x, double bias_y)
{
  move_point(& top_right_, bias_x, bias_y);
  move_point(& bottom_left_, bias_x, bias_y);
}

void zakirov::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect coefficient");
  }

  point_t center = getFrameRect().pos;
  point_t bias = {(top_right_.x - center.x) * k, (top_right_.y - center.y) * k};

  move_point(& top_right_, bias.x, bias.y);
  move_point(& top_right_, -bias.x, -bias.y);
}
