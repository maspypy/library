#define PROBLEM "https://atcoder.jp/contests/abc312/tasks/abc312_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/slide_split_sum.hpp"

void solve() {
  LL(N, M);
  vi A, B, C;
  ll ANS = 0;
  FOR(N) {
    LL(t, x);
    if (t == 0) C.eb(x);
    if (t == 1) B.eb(x);
    if (t == 2) A.eb(x);
  }
  sort(all(A));
  reverse(all(A));
  sort(all(B));
  reverse(all(B));
  sort(all(C));
  reverse(all(C));

  Slide_Split_Sum<ll> SSS;
  auto calc = [&](ll n) -> void {
    int k = min(n, len(SSS));
    chmax(ANS, SSS.query_r(k));
  };
  for (auto&& x: C) SSS.insert(x);
  calc(M);

  ll p = 0;
  for (auto&& a: A) {
    FOR(i, p, p + a) {
      if (i >= len(B)) break;
      SSS.insert(B[i]);
    }
    M -= 1;
    p += a;
    if (M == 0) break;
    calc(M);
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
