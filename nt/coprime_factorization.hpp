
/*
互いに素な整数 p1, p2, ..., pk を用いて n_i = prod p_i^e_i と表す.
[21,60,140,400]
[3,7,20], [[(0,1),(1,1)],[(0,1),(2,1)],[(1,1),(2,1)],[(2,2)]]
*/
template <typename T>
pair<vc<T>, vvc<pair<int, int>>> coprime_factorization(vc<T> nums) {
  vc<T> basis;
  for (T val: nums) {
    vc<T> new_basis;
    for (T x: basis) {
      if (val == 1) {
        new_basis.eb(x);
        continue;
      }
      vc<T> dat = {val, x};
      FOR(p, 1, len(dat)) {
        FOR(i, p) {
          while (dat[p] > 1 && dat[i] % dat[p] == 0) dat[i] /= dat[p];
          while (dat[i] > 1 && dat[p] % dat[i] == 0) dat[p] /= dat[i];
          T g = gcd(dat[i], dat[p]);
          if (g == 1 || g == dat[i] || g == dat[p]) continue;
          dat[i] /= g, dat[p] /= g, dat.eb(g);
        }
      }
      val = dat[0];
      FOR(i, 1, len(dat)) if (dat[i] != 1) new_basis.eb(dat[i]);
    }
    if (val > 1) new_basis.eb(val);
    swap(basis, new_basis);
  }

  sort(all(basis));

  vvc<pair<int, int>> res(len(nums));
  FOR(i, len(nums)) {
    T x = nums[i];
    FOR(j, len(basis)) {
      int e = 0;
      while (x % basis[j] == 0) x /= basis[j], ++e;
      if (e) res[i].eb(j, e);
    }
  }
  return {basis, res};
}