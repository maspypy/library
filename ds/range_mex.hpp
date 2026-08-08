#include "alg/monoid/min.hpp"
#include "ds/segtree/segtree.hpp"

// i, A[i] を追加 -> mex(A[j],...,A[i+1]) が更新
// このときの更新規則を得る
struct Range_Mex {
  int N;
  vc<int> last;
  SegTree<Monoid_Min<int>> seg;
  int nxt_i;
  Range_Mex(int N) : N(N), last(N + 1, -1), seg(last), nxt_i(0) {}

  // F(l,r,x,y): [l,...,r) 部分が x->y に変更
  template <typename F>
  void add(int i, int x, F change) {
    assert(i == nxt_i);
    ++nxt_i;
    chmin(x, N);
    int p = last[x];
    int R = (x == 0 ? i + 1 : seg.prod(0, x) + 1);

    last[x] = i;
    seg.set(x, i);
    while (p + 1 < R) {
      int y = seg.max_right([&](int v) -> bool { return v >= R - 1; }, x + 1);
      int L = max(p + 1, last[y] + 1);
      change(L, R, x, y);
      R = L;
    }
  }
};