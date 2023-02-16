#include "linalg/xor/transpose.hpp"

template <typename UINT>
struct Vector_Space {
#define SP Vector_Space
  vc<UINT> dat;

  Vector_Space() {}
  Vector_Space(vc<UINT> dat, bool is_reduced = false) : dat(dat) {
    if (!is_reduced) reduce();
  }

  int size() { return dat.size(); }

  bool add_element(UINT v) {
    for (auto&& e: dat) {
      if (e == 0 || v == 0) break;
      chmin(v, v ^ e);
    }
    if (v) {
      dat.eb(v);
      return true;
    }
    return false;
  }

  bool contain(UINT v) {
    for (auto&& w: dat) {
      if (v == 0) break;
      chmin(v, v ^ w);
    }
    return v == 0;
  }

  UINT get_max(UINT xor_val = 0) {
    UINT res = xor_val;
    for (auto&& x: dat) chmax(res, res ^ x);
    return res;
  }

  UINT get_min(UINT xor_val) {
    UINT res = xor_val;
    for (auto&& x: dat) chmin(res, res ^ x);
    return res;
  }

  static SP merge(SP x, SP y) {
    if (len(x) < len(y)) swap(x, y);
    for (auto v: y.dat) { x.add_element(v); }
    return x;
  }

  static SP intersection(SP& x, SP& y, int max_dim) {
    SP xx = x.orthogonal_space(max_dim);
    SP yy = y.orthogonal_space(max_dim);
    xx = merge(xx, yy);
    return xx.orthogonal_space(max_dim);
  }

  SP orthogonal_space(int max_dim) {
    normalize();
    int m = max_dim;
    // pivot[k] == k となるように行の順番を変える
    vc<u64> tmp(m);
    FOR(i, len(dat)) tmp[topbit(dat[i])] = dat[i];
    tmp = transpose(m, m, tmp, 0);
    SP res;
    FOR(j, m) {
      if (tmp[j] >> j & 1) continue;
      res.add_element(tmp[j] | UINT(1) << j);
    }
    return res;
  }

  void normalize(bool dec = true) {
    int n = len(dat);
    // 三角化
    FOR(j, n) FOR(i, j) chmin(dat[i], dat[i] ^ dat[j]);
    sort(all(dat));
    if (dec) reverse(all(dat));
  }

private:
  void reduce() {
    SP y;
    for (auto&& e: dat) y.add_element(e);
    (*this) = y;
  }
#undef SP
};
