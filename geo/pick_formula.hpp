
// input: simple polygon
// return: area2, inner, boundary
template <typename T>
tuple<i128, i128, i128> pick_formula(vc<Point<T>>& A) {
  using P = Point<T>;
  int N = len(A);
  i128 area2 = 0;
  i128 bd = 0;
  FOR(i, N) {
    P a = A[i], b = A[(i + 1) % N];
    area2 += i128(a.x) * b.y - i128(a.y) * b.x;
    P d = b - a;
    bd += gcd(d.x, d.y);
  }
  i128 in = (area2 + 2 - bd) / 2;
  return {area2, in, bd};
}