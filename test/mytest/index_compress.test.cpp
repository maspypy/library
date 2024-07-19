#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "ds/index_compress.hpp"
#include "random/base.hpp"

template <bool SMALL>
void test() {
  vc<int> X = {3, 4, 7, 4, 3, 6, 6, 7, 3};
  To_Unique_Index<int, SMALL> IDX;
  vc<int> Y = IDX.build(X);
  assert(Y == vc<int>({0, 3, 7, 4, 1, 5, 6, 8, 2}));
  assert(IDX(1) == 0 && IDX(2) == 0 && IDX(3) == 0);
  assert(IDX(4) == 3 && IDX(5) == 5 && IDX(6) == 5);
  assert(IDX(7) == 7 && IDX(8) == 9 && IDX(9) == 9);

  FOR(100) {
    FOR(N, 0, 300) {
      vc<int> X(N);
      FOR(i, N) X[i] = RNG(-100, 100);
      To_Unique_Index<int, SMALL> IDX;
      vc<int> Y = IDX.build(X);
      auto I = argsort(X);
      FOR(i, N) assert(Y[I[i]] == i);
      X = rearrange(X, I);
      FOR(x, -100, 100) assert(IDX(x) == LB(X, x));
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test<false>();
  test<true>();
  solve();
}