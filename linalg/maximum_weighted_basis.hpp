
template <typename T, typename WT>
struct Maximum_Weighted_Basis {
  int n;
  vc<int> idx;
  vvc<T> basis;  // basis[k][k] = 1, basis[k][0..k) = 0
  vc<WT> wt;
  WT wt_sum;
  int dim, nxt_idx;

  Maximum_Weighted_Basis(int n)
      : n(n),
        idx(n, -1),
        basis(n, vc<T>(n)),
        wt(n, WT(0)),
        wt_sum(0),
        dim(0),
        nxt_idx(0) {}

  // 消えるものの番号
  int add(vc<T> x, WT w) {
    assert(len(x) == n);
    int p = nxt_idx++;

    FOR(k, n) {
      if (x[k] == T(0)) continue;

      if (idx[k] == -1) {
        T c = T(1) / x[k];
        FOR(j, k, n) x[j] *= c;

        idx[k] = p;
        wt[k] = w;
        basis[k] = x;
        wt_sum += w;
        ++dim;
        return -1;
      }

      if (wt[k] < w) {
        wt_sum = wt_sum - wt[k] + w;
        swap(idx[k], p);
        swap(wt[k], w);
        swap(basis[k], x);

        T c = T(1) / basis[k][k];
        FOR(j, k, n) basis[k][j] *= c;
      }

      T c = x[k];
      FOR(j, k, n) x[j] -= c * basis[k][j];
    }

    return p;
  }
};