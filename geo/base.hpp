#pragma once
template <typename T>
struct Point {
  T x, y;
  template <typename A, typename B>
  Point(A x, B y) : x(x), y(y) {}

  template <typename A, typename B>
  Point(pair<A, B> p) : x(p.fi), y(p.se) {}

  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  bool operator==(Point p) const { return x == p.x && y == p.y; }
  Point operator-() const { return {-x, -y}; }

  bool operator<(Point p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }

  T dot(Point other) { return x * other.x + y * other.y; }
  T det(Point other) { return x * other.y - y * other.x; }
};

template <typename REAL, typename T>
REAL dist(Point<T> A, Point<T> B) {
  A -= B;
  T p = A.dot(A);
  return sqrt(REAL(p));
}

template <typename T>
struct Line {
  T a, b, c;

  Line(T a, T b, T c) : a(a), b(b), c(c) {}
  Line(Point<T> A, Point<T> B) {
    a = A.y - B.y;
    b = B.x - A.x;
    c = A.x * B.y - A.y * B.x;
  }
  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}

  template <typename U>
  U eval(Point<U> P) {
    return a * P.x + b * P.y + c;
  }

  template <typename U>
  T eval(U x, U y) {
    return a * x + b * y + c;
  }

  template <enable_if_t<is_integral<T>::value, int> = 0>
  bool is_parallel(Line other) {
    return a * other.b - b * other.a == 0;
  }

  template <enable_if_t<is_integral<T>::value, int> = 0>
  bool is_orthogonal(Line other) {
    return a * other.a + b * other.b == 0;
  }
};

template <typename T>
struct Segment {
  Point<T> A, B;

  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}
  Segment(T x1, T y1, T x2, T y2)
      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}

  Line<T> to_Line() { return Line(A, B); }
};

template <typename T>
struct Circle {
  Point<T> O;
  T r;
  Circle(Point<T> O, T r) : O(O), r(r) {}
  Circle(T x, T y, T r) : O(Point<T>(x, y)), r(r) {}
};
