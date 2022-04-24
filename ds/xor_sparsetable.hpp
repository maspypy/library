// モノイドの列を与える。次が対数時間で計算できる。
// ・prod_{l<=i<r} A[i xor x]
// https://yukicoder.me/problems/no/1891
template <typename Monoid>
struct Xor_SparseTable {
  using X = typename Monoid::value_type;
  int LOG;
  vc<vc<X>> dat;
  Xor_SparseTable(vc<X>& A) {
    LOG = 0;
    while ((1 << LOG) < len(A)) ++LOG;
    assert(len(A) == (1 << LOG));
    // 各 k, i に対して、prod_{0<=j<2^k} A[i^j] を持つ
    dat.resize(LOG + 1);
    dat[0] = A;
    FOR(k, LOG) {
      dat[k + 1].assign(1 << LOG, Monoid::unit());
      FOR(i, 1 << LOG) {
        dat[k + 1][i] = Monoid::op(dat[k][i], dat[k][i ^ (1 << k)]);
      }
    }
  }

  // prod_{l<=i<r} A[x xor i]
  X prod(int l, int r, int xor_val) {
    X xl = Monoid::unit();
    X xr = Monoid::unit();
    FOR(k, LOG + 1) {
      if (l >= r) break;
      if (l & 1 << k) {
        xl = Monoid::op(xl, dat[k][l ^ xor_val]);
        l += (1 << k);
      }
      if (r & 1 << k) {
        r -= (1 << k);
        xr = Monoid::op(dat[k][r ^ xor_val], xr);
      }
    }

    return Monoid::op(xl, xr);
  }
};