#include "geo/point_int.hpp"

template <typenamt INT>
struct Line_int {
  INT x, y;
  template <typename S, typename T>
  Point_int(S x, T y) : x(x), y(y) {}

  template <typename S, typename T>
  Point_int(pair<S, T> p) : x(p.fi), y(p.se) {}
};
