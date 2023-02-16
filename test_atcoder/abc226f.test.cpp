#define PROBLEM "https://atcoder.jp/contests/abc226/tasks/abc226_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/partition.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  mint ANS = 0;
  enumerate_partition(N, [&](vc<int> P) {
    mint x = fact<mint>(N);
    for (auto&& a: P) x *= inv<mint>(a);
    map<int, int> MP;
    for (auto&& a: P) MP[a]++;
    for (auto&& [a, b]: MP) x *= fact_inv<mint>(b);

    ll lcm = 1;
    for (auto&& [a, b]: MP) { lcm = lcm / gcd<ll>(a, lcm) * a; }
    ANS += mint(lcm).pow(K) * x;
  });
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
