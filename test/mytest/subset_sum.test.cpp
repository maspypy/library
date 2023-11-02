#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "knapsack/subset_sum.hpp"
#include "random/base.hpp"

void test() {
  FOR(10) {
    FOR(N, 10) {
      vc<int> A(N);
      FOR(i, N) A[i] = RNG(0, 100);
      FOR(s, 1, 500) {
        vc<int> I1 = subset_sum_solution_1<int>(A, s);
        vc<int> I2 = subset_sum_solution_2<int>(A, s);
        vc<int> I3 = subset_sum_solution_3<int>(A, s);
        vc<int> I4 = subset_sum_solution_4<int>(A, s);
        vc<int> I5 = subset_sum_solution_4<int>(A, s);
        if (I1.empty()) {
          assert(I2.empty());
          assert(I3.empty());
          assert(I4.empty());
          assert(I5.empty());
          continue;
        }
        for (vc<int> I: {I1, I2, I3, I4, I5}) {
          FOR(i, len(I) - 1) assert(I[i] != I[i + 1]);
          int sm = 0;
          for (auto& i: I) sm += A[i];
          assert(sm == s);
        }
      }
    }
  }
}

void solve() {
  INT(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}