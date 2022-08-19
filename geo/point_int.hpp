template <typenamt INT>
struct Point {
  INT x, y;
  template <typename S, typename T>
  Point_int(S x, T y) : x(x), y(y) {}

  template <typename S, typename T>
  Point_int(pair<S, T> p) : x(p.fi), y(p.se) {}
};
