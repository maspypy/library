#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/index_compression.hpp"
#include "ds/fenwicktree/fenwicktree_01.hpp"

void solve() {
  INT(N, Q);
  vc<int> A(N + Q);
  FOR(i, N) read(A[i]);
  vc<int> tp(Q);
  FOR(q, Q) {
    INT(t, x);
    A[N + q] = x;
    tp[q] = t;
  }
  Index_Compression_SAME_LARGE<int> X;
  A = X.build(A);

  int n = len(X);
  vc<bool> exist(n);
  FOR(i, N) exist[A[i]] = 1;

  FenwickTree_01 bit(n, [&](int i) -> int { return exist[i]; });

  auto Q0 = [&](int x) -> void {
    if (!bit.get(x)) bit.add(x);
  };
  auto Q1 = [&](int x) -> void {
    if (bit.get(x)) bit.remove(x);
  };
  auto Q2 = [&](int x) -> void {
    x = X.idx_to_val(x);
    --x;
    int ans = (x < bit.sum_all() ? X.idx_to_val(bit.kth(x)) : -1);
    print(ans);
  };
  auto Q3 = [&](int x) -> void { print(bit.sum(x + 1)); };
  auto Q4 = [&](int x) -> void {
    int i = bit.prev(x);
    print(i == -1 ? -1 : X.idx_to_val(i));
  };
  auto Q5 = [&](int x) -> void {
    int i = bit.next(x);
    print(i == n ? -1 : X.idx_to_val(i));
  };

  FOR(q, Q) {
    int t = tp[q];
    if (t == 0) Q0(A[N + q]);
    if (t == 1) Q1(A[N + q]);
    if (t == 2) Q2(A[N + q]);
    if (t == 3) Q3(A[N + q]);
    if (t == 4) Q4(A[N + q]);
    if (t == 5) Q5(A[N + q]);
  }
}

signed main() {
  solve();

  return 0;
}
