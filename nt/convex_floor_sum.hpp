
// f: 凸, 非負, 単調増加を仮定
// above(x,y) : y > f(x)
// slope(x,a,b) : f'(x) >= a/b
// return : sum_[0,N) floor(f(x))
// https://qoj.ac/contest/1195/problem/6188
template <typename U, typename ANS_TYPE, typename F1, typename F2>
ANS_TYPE convex_floor_sum(U N, F1 above, F2 slope) {
  if (N == 0) return 0;
  auto check = [&](U x, U y) -> bool { return x < N && above(x, y); };

  using T = ANS_TYPE;
  auto max_add = [&](auto f, U& a, U& b, U c, U d) -> void {
    auto dfs = [&](auto& dfs, U c, U d) -> void {
      if (!f(a + c, b + d)) return;
      a += c, b += d, dfs(dfs, c + c, d + d);
      if (f(a + c, b + d)) a += c, b += d;
    };
    dfs(dfs, c, d);
  };

  assert(!above(0, 0));
  U x = 0, y = 0;
  max_add([&](U x, U y) -> bool { return !above(x, y); }, x, y, 0, 1);
  ++y;
  T ANS = 2 * (y - 1); //  [0,1) x [1,y)

  auto add_ANS = [&](U& x, U& y, U a, U b) -> void {
    U x0 = x, y0 = y;
    max_add(check, x, y, a, b);
    U n = (x - x0) / a;
    //  (x0,y0) to (x,y)
    ANS += 2 * (y0 - 1) * (x - x0);
    ANS += (x - x0 + 1) * (y - y0 + 1) - (n + 1);
  };

  add_ANS(x, y, 1, 0);
  vc<tuple<U, U, U, U>> SBT;
  SBT.eb(1, 0, 0, 1);
  while (x < N - 1) {
    U a, b, c, d;
    tie(a, b, c, d) = SBT.back();
    if (!check(x + c, y + d)) {
      POP(SBT);
      continue;
    }
    auto f = [&](u64 a, u64 b) -> bool {
      if (x + a >= N) return 0;
      if (above(x + a, y + b)) return 0;
      if (slope(x + a, d, c)) return 0;
      return 1;
    };
    max_add(f, a, b, c, d);
    if (check(x + a + c, y + b + d)) {
      max_add([&](U a, U b) -> bool { return check(x + a, y + b); }, c, d, a, b);
      SBT.eb(a, b, c, d);
      continue;
    }
    add_ANS(x, y, c, d);
  }
  ANS /= T(2);
  return ANS;
}