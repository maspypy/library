#pragma once

template <typename T>
struct Point_3d {
  T x, y, z;

  Point_3d() = default;

  template <typename A, typename B, typename C>
  Point_3d(A x, B y, C z) : x(x), y(y), z(z) {}

  Point_3d operator+(Point_3d p) const { return {x + p.x, y + p.y, z + p.z}; }
  Point_3d operator-(Point_3d p) const { return {x - p.x, y - p.y, z - p.z}; }
  Point_3d operator*(T t) const { return {x * t, y * t, z * t}; }
  Point_3d operator/(T t) const { return {x / t, y / t, z / t}; }
  bool operator==(Point_3d p) const { return x == p.x && y == p.y && z == p.z; }
  bool operator!=(Point_3d p) const { return x != p.x || y != p.y || z == p.z; }
  Point_3d operator-() const { return {-x, -y, -z}; }

  bool is_parallel(Point_3d p) const { return x * p.y == y * p.x && y * p.z == z * p.y && z * p.x == x * p.z; }

  T dot(Point_3d other) { return x * other.x + y * other.y + z * other.z; }
  double norm() { return sqrt(x * x + y * y + z * z); }
  Point_3d cross(Point_3d other) { return Point_3d(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x); }
};

template <typename T>
struct Line_3d {
  // a + td
  Point_3d<T> a, d;

  Line_3d(Point_3d<T> A, Point_3d<T> B) : a(A), d(B - A) { assert(d.dot(d) != 0); }
  bool is_parallel(Line_3d<T> other) {
    Point_3d<T> n = d.cross(other.d);
    return (n.x == T(0) && n.y == T(0) && n.z == T(0));
  }
  bool contain(Point_3d<T> p) {
    p = p - a;
    p = p.cross(d);
    return (p.x == T(0) && p.y == T(0) && p.z == T(0));
  }
};

template <typename T>
struct Plane {
  // ax + by + cz == d
  T a, b, c, d;
  Point_3d<T> normal_vec;

  Plane(Point_3d<T> A, Point_3d<T> B, Point_3d<T> C) {
    Point_3d<T> AB = B - A;
    Point_3d<T> AC = C - A;
    normal_vec = AB.cross(AC);
    a = normal_vec.x, b = normal_vec.y, c = normal_vec.z;
    d = normal_vec.dot(A);
  }

  int side(Point_3d<T> p) {
    T x = normal_vec.dot(p) - d;
    if (x == 0) return 0;
    return (x > 0 ? 1 : -1);
  }

  template <typename Re>
  Point_3d<Re> cross_point(Line_3d<T> L) {
    // a + td
    T x = normal_vec.dot(L.a);
    T y = normal_vec.dot(L.d);
    Re t = Re(d - x) / y;
    Point_3d<Re> ANS;
    ANS.x = L.a.x + t * L.d.x;
    ANS.y = L.a.y + t * L.d.y;
    ANS.z = L.a.z + t * L.d.z;
    return ANS;
  }
};
