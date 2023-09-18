
/*
https://codeforces.com/problemset/problem/713/D
・sparse_table OR disjoint_sparse table をセグ木に乗せる
・構築 O(HW log W)
・クエリ O(log H)
*/
template <typename SPARSE_TABLE>
struct Sparse_Table_On_SegTree {
  using ST = SPARSE_TABLE;
  using MX = typename ST::MX;
  using X = typename MX::value_type;
  using value_type = X;
  static_assert(MX::commute);
  int H, W;
  vc<ST> dat;

  Sparse_Table_On_SegTree() {}
  Sparse_Table_On_SegTree(vvc<X> &v) {
    H = len(v), W = (H == 0 ? 0 : len(v[0]));
    dat.resize(2 * H);
    FOR(i, H) { dat[H + i] = ST(v[i]); }
    FOR_R(i, 1, H) {
      dat[i] = ST(W, [&](int j) -> X {
        X x = dat[2 * i + 0].prod(j, j + 1);
        X y = dat[2 * i + 1].prod(j, j + 1);
        return MX::op(x, y);
      });
    }
  }

  X prod(int xl, int xr, int yl, int yr) {
    assert(0 <= xl && xl <= xr && xr <= H);
    assert(0 <= yl && yl <= yr && yr <= W);
    X res = MX::unit();
    xl += H, xr += H;
    while (xl < xr) {
      if (xl & 1) res = MX::op(res, dat[xl++].prod(yl, yr));
      if (xr & 1) res = MX::op(res, dat[--xr].prod(yl, yr));
      xl >>= 1, xr >>= 1;
    }
    return res;
  }
};