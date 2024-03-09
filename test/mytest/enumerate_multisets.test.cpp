#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "enumerate/multiset.hpp"

void test() {
  {
    vvc<int> res;
    auto f = [&](vc<int> A) -> void { res.eb(A); };
    enumerate_multiset(2, 3, f);
    assert(len(res) == 6);
    assert(res[0] == vc<int>({0, 0, 2}));
    assert(res[1] == vc<int>({0, 1, 1}));
    assert(res[2] == vc<int>({0, 2, 0}));
    assert(res[3] == vc<int>({1, 0, 1}));
    assert(res[4] == vc<int>({1, 1, 0}));
    assert(res[5] == vc<int>({2, 0, 0}));
  }
  {
    int cnt = 0;
    auto f = [&](vc<int> A) -> void { ++cnt; };
    enumerate_multiset(4, 3, f);
    assert(cnt == 15);
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
