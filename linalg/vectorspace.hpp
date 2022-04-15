// K^n の subspace を管理する。
// add：生成系にベクトルを追加
// dim, get_basis, contain
template <typename K>
struct VectorSpace {
  vc<vc<K>> basis;
  vc<int> pivot;
  int n;

  VectorSpace(int n) : n(n) {}

  int dim() { return len(basis); }

  vc<vc<K>> get_basis() { return basis; }

  void add(const vc<K>& v) {
    vc<K> w = reduce(v);
    int p = n;
    FOR(i, n) if (w[i] != K(0)) chmin(p, i);
    if (p == n) return;
    K c = K(1) / w[p];
    FOR3(j, p, n) w[j] *= c;

    FOR(i, len(basis)) {
      K c = basis[i][p];
      if (c == K(0)) continue;
      FOR3(j, p, n) basis[i][j] -= c * w[j];
    }

    basis.eb(w);
    pivot.eb(p);
    int k = len(basis) - 1;
    while (k > 0 && pivot[k - 1] > p) {
      swap(basis[k], basis[k - 1]);
      swap(pivot[k], pivot[k - 1]);
      --k;
    }
  }

  bool contain(const vc<K>& v) {
    vc<K> w = reduce(v);
    FOR(i, n) if (w[i] != K(0)) return false;
    return true;
  }

private:
  vc<K> reduce(vc<K> v) {
    FOR(i, len(basis)) {
      int p = pivot[i];
      K c = v[p];
      FOR3(j, p, n) v[j] -= basis[i][j] * c;
    }
    return v;
  }
};
