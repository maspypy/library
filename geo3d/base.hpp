
template <typename T>
struct Point_3d {
  T x, y, z;

  Point_3d() = default;

  template <typename A, typename B, typename C>
  Point_3d(A x, B y, C z) : x(x), y(y), z(z) {}

  Point_3d operator+(Point_3d p) const { return {x + p.x, y + p.y, z + p.z}; }
  Point_3d operator-(Point_3d p) const { return {x - p.x, y - p.y, z - p.z}; }
  Point_3d operator*(T t) const { return {x * t, y * t, z * t}; }
  bool operator==(Point_3d p) const { return x == p.x && y == p.y && z == p.z; }
  bool operator!=(Point_3d p) const { return x != p.x || y != p.y || z == p.z; }
  Point_3d operator-() const { return {-x, -y, -z}; }

  bool is_parallel(Point_3d p) const {
    return x * p.y == y * p.x && y * p.z == z * p.y && z * p.x == x * p.z;
  }

  T dot(Point_3d other) { return x * other.x + y * other.y + z * other.z; }
  double norm() { return sqrt(x * x + y * y + z * z); }
  Point_3d cross(Point_3d other) {
    return Point_3d(y * other.z - z * other.y, z * other.x - x * other.z,
                    x * other.y - y * other.x);
  }
};