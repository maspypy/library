#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/substring_abundant_string.hpp"

void test() {
  auto check = [&](ll N) -> bool {
    string S = substring_abundant_string(N);
    assert(len(S) == N);
    ll ub = 1;
    FOR(k, 1, N + 1) {
      ub = min(ub * 2, N);
      ll n = min(ub, N - k + 1);
      set<string> ss;
      FOR(i, N - k + 1) { ss.insert(S.substr(i, k)); }
      if (len(ss) != n) return 0;
    }
    return 1;
  };
  FOR(n, 1, 100) { assert(check(n)); }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}