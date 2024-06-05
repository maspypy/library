#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "string/lex_min_suffix_for_all_prefix.hpp"
#include "string/lex_max_suffix_for_all_prefix.hpp"

void test_str(string S) {
  vc<int> A = lex_min_suffix_for_all_prefix(S);
  vc<int> B = lex_max_suffix_for_all_prefix(S);
  FOR(n, 1, len(S) + 1) {
    string t = S.substr(0, n);
    vc<string> suffix;
    FOR(i, len(t)) suffix.eb(t.substr(i));
    int a = min_element(all(suffix)) - suffix.begin();
    int b = max_element(all(suffix)) - suffix.begin();
    assert(A[n] == len(t) - a);
    assert(B[n] == len(t) - b);
  }
}

void test() {
  FOR(N, 1, 20) {
    FOR(K, 1, 10) {
      FOR(1000) {
        string S;
        FOR(N) S += 'a' + RNG(0, K);
        test_str(S);
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}
