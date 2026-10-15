// Source: https://github.com/maspypy/library/blob/main/geo/triangle_area.hpp
template <typename REAL, typename T>
REAL triangle_area(Point<T> A, Point<T> B, Point<T> C) {
  return abs((B - A).det(C - A)) * 0.5;
}
