#include "string/zalgorithm.hpp"
template <typename STRING>
vc<tuple<int, int, int>> run_enumerate(const STRING& S) {
  // (period, l, r)
  ll N = len(S);
  using T = tuple<int, int, int>;
  using P = pair<int, int>;
  vc<vc<P>> by_p(N + 1);

  auto solve_sub = [&](STRING& left, STRING& right) -> vc<T> {
    vc<T> res;
    int n = len(left), m = len(right);
    auto S = left, T = right;
    reverse(all(S));
    T.insert(T.end(), all(left));
    T.insert(T.end(), all(right));
    auto ZS = zalgorithm(S), ZT = zalgorithm(T);
    FOR3(p, 1, n + 1) {
      int a = (p == n ? p : min(ZS[p] + int(p), n));
      int b = min(ZT[n + m - p], m);
      if (a + b < 2 * p) continue;
      res.eb(p, a, b);
    }
    return res;
  };

  vc<P> st = {{0, N}};
  while (!st.empty()) {
    auto [L, R] = st.back();
    st.pop_back();
    if (R - L <= 1) continue;
    int M = (L + R) / 2;
    st.eb(L, M), st.eb(M, R);
    STRING SL = {S.begin() + L, S.begin() + M};
    STRING SR = {S.begin() + M, S.begin() + R};
    {
      auto sub_res = solve_sub(SL, SR);
      for (auto&& [p, a, b]: sub_res) by_p[p].eb(M - a, M + b);
    }
    {
      reverse(all(SL)), reverse(all(SR));
      auto sub_res = solve_sub(SR, SL);
      for (auto&& [p, a, b]: sub_res) by_p[p].eb(M - b, M + a);
    }
  }

  vc<T> res;
  set<P> done;
  FOR(p, len(by_p)) {
    auto& LR = by_p[p];
    sort(all(LR),
         [](auto& x, auto& y) { return P(x.fi, -x.se) < P(y.fi, -y.se); });
    int r = -1;
    for (auto&& lr: LR) {
      if (chmax(r, lr.se) && !done.count(lr)) {
        done.insert(lr);
        res.eb(p, lr.fi, lr.se);
      }
    }
  }
  return res;
}
