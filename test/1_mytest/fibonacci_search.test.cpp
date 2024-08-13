#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/fibonacci_search.hpp"
#include "enumerate/product.hpp"

void test() {
  // permutation
  FOR(N, 1, 10) {
    vc<int> A(N);
    iota(all(A), 0);
    do {
      auto f = [&](int i) -> int { return A[i]; };
      auto [y, i] = fibonacci_search<int, true>(f, 0, N);
      assert(0 <= i && i < N);
      if (0 < i) assert(A[i] < A[i - 1]);
      if (i + 1 < N) assert(A[i] < A[i + 1]);
    } while (next_permutation(all(A)));
  }
  // [0,1]
  FOR(N, 1, 18) {
    FOR(s, 1 << N) {
      vc<int> A(N);
      FOR(i, N) A[i] = s >> i & 1;
      auto f = [&](int i) -> int { return A[i]; };
      auto [y, i] = fibonacci_search<int, true>(f, 0, N);
      assert(0 <= i && i < N);
      if (0 < i) assert(A[i] <= A[i - 1]);
      if (i + 1 < N) assert(A[i] <= A[i + 1]);
    }
  }
  // [0,1,2]
  FOR(N, 1, 13) {
    enumerate_product(vc<int>(N, 3), [&](vc<int> A) -> void {
      auto f = [&](int i) -> int { return A[i]; };
      auto [y, i] = fibonacci_search<int, true>(f, 0, N);
      assert(0 <= i && i < N);
      if (0 < i) assert(A[i] <= A[i - 1]);
      if (i + 1 < N) assert(A[i] <= A[i + 1]);
    });
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
