#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/rollinghash.hpp"
#include "ds/disjointsparse.hpp"

void solve() {
  STR(S);
  ll N = len(S);
  using Mono = Monoid_Rolling_Hash;
  DisjointSparse<Mono> seg(N, [&](int i) { return Mono::from_element(S[i]); });
  vi Z(N);
  FOR(i, N) {
    auto check = [&](int n) -> bool {
      if (i + n > N) return false;
      return seg.prod(0, n) == seg.prod(i, i + n);
    };
    Z[i] = binary_search(check, 0, N + 1);
  }
  print(Z);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
