#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "string/suffix_lcp_change.hpp"
#include "random/base.hpp"

/*
suffix array 順 suffix s[0],...,s[n-1]. L_p: s[p] との lcp.
sum_k min(L_p[k], r-l) * [l<=SA[k]<r].

L_p[] が大きいのは区間 [L,R)

sum_{0<=k<L} (r-l) * [l<=SA[k]<r]
sum_{L<=k<R} L_p[k] * [l<=SA[k]<r]
sum_{R<=k<N} (r-l) * [l<=SA[k]<r]
*/
void test() {
  FOR(N, 1, 30) {
    FOR(K, 1, 20) {
      FOR(1000) {
        string S;
        FOR(N) S += 'a' + RNG(0, K);
        Suffix_Array<0> X(S);
        auto [A, change] = suffix_lcp_change(X);
        auto& SA = X.SA;
        FOR(i, N) { assert(A[i] == X.lcp(SA[0], SA[i])); }
        FOR(k, N - 1) {
          for (auto [l, r, x]: change[k]) {
            FOR(i, l, r) {
              assert(A[i] != x);
              A[i] = x;
            }
          }
          FOR(i, N) { assert(A[i] == X.lcp(SA[k + 1], SA[i])); }
        }
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
