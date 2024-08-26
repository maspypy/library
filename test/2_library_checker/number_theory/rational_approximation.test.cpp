#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/rational_binary_search.hpp"

void solve() {
  LL(N, x, y);
  auto [a, b, c, d] = rational_binary_search<int>([&](ll a, ll b) -> bool { return a * y <= b * x; }, N);
  if (a * y == b * x) {
    print(a, b, a, b);
  } else {
    print(a, b, c, d);
  }
}

int main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
