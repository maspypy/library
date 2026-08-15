
/*
ax + b (x>=0) が最小となるところの情報を返す。
prefix min を更新する x 全体が、等差数列の和集合。次を返す。
・等差数列の境界となる x_0, x_1, ..., x_n
・各境界の間での交差 dx_0, ..., dx_{n-1}
*/
pair<vc<int>, vc<int>> min_of_linear_segments(int a, int b, int mod) {
  assert(0 <= a && a < mod);
  assert(0 <= b && b < mod);
  vc<int> X = {0};
  vc<int> DX;
  int g = gcd(a, mod);
  a /= g, b /= g, mod /= g;
  // p/q <= (mod-a)/mod <= r/s
  int p = 0, q = 1, r = 1, s = 1;
  int det_l = mod - a, det_r = a;
  int x = 0, y = b;

  while (y) {
    // upd r/s
    int k = det_r / det_l;
    det_r %= det_l;
    if (det_r == 0) {
      --k;
      det_r = det_l;
    }
    r += k * p;
    s += k * q;
    while (1) {
      int k = max(0, ceil(det_l - y, det_r));
      if (det_l - k * det_r <= 0) break;
      det_l -= k * det_r;
      p += k * r;
      q += k * s;
      // p/q <= a/mod
      // (aq - pmod) = det_l を y から引く
      k = y / det_l;
      y -= k * det_l;
      x += q * k;
      X.eb(x);
      DX.eb(q);
    }
    k = det_l / det_r;
    det_l -= k * det_r;
    p += k * r;
    q += k * s;
    assert(min({p, q, r, s}) >= 0);
  }
  return {X, DX};
}
