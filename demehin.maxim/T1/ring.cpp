#include "ring.hpp"
#include <stdexcept>
#include <cmath>

namespace
{
  demehin::point_t* generate_vrt(const demehin::point_t center, double radius, size_t vrt_cnt)
  {
    demehin::point_t* vrt = new demehin::point_t[vrt_cnt];
    constexpr double PI = 3.1415;
    for (size_t i = 0; i < 13; ++i)
    {
      double angle = 2 * PI * i / 13;
      double x = center.x + radius * cos(angle);
      double y = center.y + radius * sin(angle);
      vrt[i].x = x;
      vrt[i].y = y;
    }
    return vrt;
  }
}

demehin::Ring::Ring(point_t center, double out_r, double in_r):
  inner_plg_(nullptr),
  outer_plg_(nullptr)
{
  if (out_r <= in_r || out_r <= 0 || in_r <= 0)
  {
    throw std::logic_error("incorrect shape");
  }

  demehin::point_t* outerVrt = nullptr;
  demehin::point_t* innerVrt = nullptr;
  try
  {
    outerVrt = generate_vrt(center, out_r, 13);
    innerVrt = generate_vrt(center, in_r, 13);
    outer_plg_ = new demehin::Polygon(13, outerVrt);
    inner_plg_ = new demehin::Polygon(13, innerVrt);
  }
  catch (const std::bad_alloc& e)
  {
    delete[] outerVrt;
    delete[] innerVrt;
    delete outer_plg_;
    delete inner_plg_;
    throw;
  }
  delete[] outerVrt;
  delete[] innerVrt;
}
demehin::Ring::~Ring()
{
  delete outer_plg_;
  delete inner_plg_;
}


double demehin::Ring::getArea() const
{
  return outer_plg_->getArea() - inner_plg_->getArea();
}

demehin::rectangle_t demehin::Ring::getFrameRect() const
{
  return outer_plg_->getFrameRect();
}

void demehin::Ring::move(point_t s)
{
  inner_plg_->move(s);
  outer_plg_->move(s);
}

void demehin::Ring::move(double x, double y)
{
  inner_plg_->move(x, y);
  outer_plg_->move(x, y);
}

void demehin::Ring::scale(double k)
{
  inner_plg_->scale(k);
  outer_plg_->scale(k);
}
