#include "geo/base.hpp"

/*
https://codeforces.com/blog/entry/75929
動的凸包。
x 座標でソートして完全二分木のセグ木の形にしておく。
セグ木のマージ部分（次の bridge を求める）で二分探索する。
bridge 同士の 4 点での上側凸包を見れば、次に探索するべき区間対が分かる。

構築 O(NlogN)、更新 O(Nlog^2N)
座標 10^9 以下の整数を仮定
*/
template<typename Point>
struct DynamicUpperHull {
  struct node {
    int l, r;   // 範囲 (-1 if no vertex)
    int bl, br; // bridge idx
  };
  int N, sz;
  vc<Point> P;
  vc<node> seg;
  // 受け取ったインデックスとの対応
  vc<int> to_original_idx, to_seg_idx;

  DynamicUpperHull(vc<Point> P) : DynamicUpperHull(P, 0) {}
  DynamicUpperHull(vc<Point> P, bool b)
      : DynamicUpperHull(P, vc<bool>(len(P), b)) {}

  DynamicUpperHull(vc<Point> _P, vc<bool> isin) : N(len(_P)), P(_P) {
    to_original_idx = argsort(P);
    sort(all(P));
    sz = 1;
    while (sz < N) sz *= 2;
    to_seg_idx.resize(N);
    seg.assign(sz + sz, {-1, -1, -1, -1});
    for (int i = 0; i < N; ++i) to_seg_idx[to_original_idx[i]] = i;
    for (int i = 0; i < N; ++i)
      if (isin[to_original_idx[i]]) { seg[sz + i] = {i, i + 1, i, i}; }
    FOR3_R(i, 1, sz) update(i);
  }

  void insert(int i) {
    i = to_seg_idx[i];
    seg[sz + i] = {i, i + 1, i, i};
    i = (sz + i) / 2;
    while (i) {
      update(i);
      i /= 2;
    }
  }

  void erase(int i) {
    i = to_seg_idx[i];
    seg[sz + i] = {-1, -1, -1, -1};
    i = (sz + i) / 2;
    while (i) {
      update(i);
      i /= 2;
    }
  }

  inline bool exist(int i) { return seg[i].r != -1; }

  void update(int i) {
    if (!exist(2 * i + 0) && !exist(2 * i + 1)) {
      seg[i].r = -1;
      return;
    }
    if (!exist(2 * i + 0)) {
      seg[i] = seg[2 * i + 1];
      return;
    }
    if (!exist(2 * i + 1)) {
      seg[i] = seg[2 * i + 0];
      return;
    }
    int p = 2 * i, q = 2 * i + 1;
    ll X = P[seg[q].l].x;
    while (p < sz || q < sz) {
      if (p < sz && !exist(2 * p + 0)) {
        p = 2 * p + 1;
        continue;
      }
      if (p < sz && !exist(2 * p + 1)) {
        p = 2 * p + 0;
        continue;
      }
      if (q < sz && !exist(2 * q + 0)) {
        q = 2 * q + 1;
        continue;
      }
      if (q < sz && !exist(2 * q + 1)) {
        q = 2 * q + 0;
        continue;
      }
      int a = seg[p].bl, b = seg[p].br, c = seg[q].bl, d = seg[q].br;
      if (a != b && (P[b] - P[a]).det(P[c] - P[a]) > 0) p = p * 2 + 0;
      elif (c != d && (P[c] - P[b]).det(P[d] - P[b]) > 0) q = 2 * q + 1;
      elif (a == b) q = 2 * q + 0;
      elif (c == d) p = 2 * p + 1;
      else {
        i128 c1 = (P[b] - P[a]).det(P[c] - P[a]);
        i128 c2 = (P[a] - P[b]).det(P[d] - P[b]);
        if (c1 + c2 == 0 || c1 * P[d].x + c2 * P[c].x < X * (c1 + c2)) {
          p = 2 * p + 1;
        } else {
          q = 2 * q + 0;
        }
      }
    }
    seg[i].l = seg[2 * i].l, seg[i].r = seg[2 * i + 1].r;
    seg[i].bl = seg[p].l, seg[i].br = seg[q].l;
  }

  vc<int> get() {
    // output sensitive complexity
    vc<int> res;
    auto dfs = [&](auto self, int k, int l, int r) -> void {
      if (!exist(k) || l >= r) return;
      if (k >= sz) {
        res.eb(seg[k].l);
        return;
      }
      if (!exist(2 * k + 0)) return self(self, 2 * k + 1, l, r);
      if (!exist(2 * k + 1)) return self(self, 2 * k + 0, l, r);
      if (r <= seg[k].bl) return self(self, 2 * k + 0, l, r);
      if (seg[k].br <= l) return self(self, 2 * k + 1, l, r);
      self(self, 2 * k + 0, l, seg[k].bl + 1);
      self(self, 2 * k + 1, seg[k].br, r);
    };
    dfs(dfs, 1, 0, N);
    for (auto&& i: res) i = to_original_idx[i];
    return res;
  }

  void debug() {
    print("points");
    FOR(i, len(P)) print(i, P[i].x, P[i].y);
    print("seg");
    FOR(i, len(seg)) print(i, seg[i].l, seg[i].r, seg[i].bl, seg[i].br);
    print("get");
    print(get());
  }
};
