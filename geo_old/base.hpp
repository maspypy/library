#pragma once

template<typename X = long long>
struct Point {
  X x, y;
  Point(X x=0, X y=0) : x(x), y(y) {}

  template <typename S, typename T>
  Point(pair<S, T> p) : x(p.fi), y(p.se) {}

  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  X det(Point p) const { return x * p.y - y * p.x; }
  X dot(Point p) const { return x * p.x + y * p.y; }
  pair<double,double> polar(){
    double r = sqrt(x * x + y * y);
    double theta = atan2(y, x);
    return {r, theta};
  }
  bool operator<(Point p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  bool operator==(Point p) const { return x == p.x && y == p.y; }
  Point operator-() const { return {-x, -y}; }
};
