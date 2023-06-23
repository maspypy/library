
template <typename T>
struct Point {
  T x, y, z;

  Point() = default;

  template <typename A, typename B, typename C>
  Point(A x, B y, C z) : x(x), y(y), z(z) {}

  Point operator+(Point p) const { return {x + p.x, y + p.y, z + p.z}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y, z - p.z}; }
  bool operator==(Point p) const { return x == p.x && y == p.y && z == p.z; }
  bool operator!=(Point p) const { return x != p.x || y != p.y || z == p.z; }
  Point operator-() const { return {-x, -y, -z}; }

  bool is_parallel(Point p) const {
    return x * p.y == y * p.x && y * p.z == z * p.y && z * p.x == x * p.z;
  }

  T dot(Point other) { return x * other.x + y * other.y + z * other.z; }
  Point cross(Point other) {
    return Point(y * other.z - z * other.y, z * other.x - x * other.z,
                 x * other.y - y * other.x);
  }
};