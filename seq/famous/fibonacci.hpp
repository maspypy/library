// 0, 1, 1, 2, 3, 5, ...
template <typename mint>
mint fibonacci(ll N) {
  using P = pair<mint, mint>;
  P f = {0, 1}, res = {1, 0};
  while (N) {
    auto& [a, b] = f;
    auto& [c, d] = res;
    if (N & 1) { res = {a * c + b * d, b * c + (a + b) * d}; }
    f = {a * a + b * b, b * (a + a + b)};
    N >>= 1;
  }
  return res.se;
}
