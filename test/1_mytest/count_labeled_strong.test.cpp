#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/count/count_labeled_strong_digraph.hpp"

using mint = modint998;

void test() {
  vc<mint> F = count_labeled_strong_digraph<mint>(10);
  vc<string> ANS = {"0",
                    "1",
                    "1",
                    "18",
                    "1606",
                    "565080",
                    "734774776",
                    "3523091615568",
                    "63519209389664176",
                    "4400410978376102609280",
                    "1190433705317814685295399296"};
  FOR(n, 11) {
    mint ans = 0;
    for (auto& x: ANS[n]) ans = mint(10) * ans + mint(x - '0');
    assert(F[n] == ans);
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