#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/random.hpp"
#include "string/run_length.hpp"

void test() {
  {
    string A = "aabbcaaab";
    auto res = run_length(A);
    assert(len(res) == 5);
    assert(res[0].fi == 'a' && res[0].se == 2);
    assert(res[1].fi == 'b' && res[1].se == 2);
    assert(res[2].fi == 'c' && res[2].se == 1);
    assert(res[3].fi == 'a' && res[3].se == 3);
    assert(res[4].fi == 'b' && res[4].se == 1);
  }
  {
    string A = "aaaaaa";
    auto res = run_length(A);
    assert(len(res) == 1);
    assert(res[0].fi == 'a' && res[0].se == 6);
  }
  {
    string A = "";
    auto res = run_length(A);
    assert(len(res) == 0);
  }
  {
    vc<int> A = {1, 1, 2, 2, 3, 1, 1, 1, 2};
    auto res = run_length(A);
    assert(len(res) == 5);
    assert(res[0].fi == 1 && res[0].se == 2);
    assert(res[1].fi == 2 && res[1].se == 2);
    assert(res[2].fi == 3 && res[2].se == 1);
    assert(res[3].fi == 1 && res[3].se == 3);
    assert(res[4].fi == 2 && res[4].se == 1);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
