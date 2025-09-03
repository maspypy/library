#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D"
#include "my_template.hpp"
#include "other/io.hpp"
#include "setfunc/all_k_subset.hpp"

void solve() {
  LL(N, K);
  for (u32 s: all_nCk(N, K)) {
    vi I;
    for (int i: all_bit<u32>(s)) I.eb(i);
    print(to_string(s) + ":", I);
  }
}

signed main() {
  solve();
  return 0;
}