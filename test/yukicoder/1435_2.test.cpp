#define PROBLEM "https://yukicoder.me/problems/no/1435"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/sliding_window_aggregation.hpp"

struct Mono {
  using value_type = tuple<int, int, int>; // max, min1, min2
  using X = value_type;
  static X op(X& x, X& y) {
    auto& [xma, xmi1, xmi2] = x;
    auto& [yma, ymi1, ymi2] = y;
    if (xma == -1) return y;
    if (yma == -1) return x;
    if (xmi1 < ymi1) { return {max(xma, yma), xmi1, min(xmi2, ymi1)}; }
    return {max(xma, yma), ymi1, min(ymi2, xmi1)};
  }
  static X from_element(int x) { return {x, x, 1 << 30}; }
  static constexpr X unit() { return {-1, -1, -1}; }
  static constexpr bool commute = 0;
};

void solve() {
  LL(N);
  VEC(int, A, N);
  Slinding_Window_Aggregation<Mono> seg;

  ll ANS = 0;
  ll R = 0;
  FOR(L, N) {
    auto check = [&](auto e) -> bool {
      auto& [M, m1, m2] = e;
      if (M == -1) return 1;
      return M <= m1 + m2;
    };
    while (R < N) {
      auto a = seg.prod();
      auto b = Mono::from_element(A[R]);
      if (check(Mono::op(a, b))) {
        seg.push(b);
        ++R;
      } else
        break;
    }
    ANS += max<int>(0, R - L - 1);
    seg.pop();
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
