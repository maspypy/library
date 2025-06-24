#pragma once

#include "ds/hashmap.hpp"
#include "seq/cartesian_tree.hpp"
#include "string/rollinghash.hpp"
#include "string/suffix_array.hpp"

// https://arxiv.org/pdf/2312.11873
// https://uoj.ac/problem/697
struct Basic_Substring_Structure {
  using SA_t = Suffix_Array<false>;
  int N;
  string S, T; // T = rev(S)
  RollingHash RH;
  vc<decltype(RH)::mint> SH;
  SA_t S_SA, T_SA;
  HashMap<int> hash_to_col;

  /*
  block を diagonal に配置した長方形を作る感じにする.
  X, Y: i 番目の block が [X[i],X[i+1]) x [Y[i],Y[i+1]) になる.
  X_to_block, Y_to_block: 行番号や列番号に対応する block.
  width, height: 行の幅, 列の高さ. [X[i],X[i]+width[i]) など.
  right: 行き先の行
  down: 行き先の列
  */

  // topological 逆順 (最後に S[0,N) が来る)
  vc<pair<int, int>> raw_index; // 各 block の代表元に対応する [i,j]
  vc<int> X, Y;
  vc<int> X_to_block, Y_to_block;
  vc<int> width, height;
  vc<int> right, down;

  int n_block() { return len(raw_index); }
  pair<int, int> shape() { return {X.back(), Y.back()}; }

  Basic_Substring_Structure(string &S) { build(S); }

  void build(string &S_) {
    S = S_, T = {S_.rbegin(), S_.rend()};
    SH = RH.build(S);
    S_SA = SA_t(S), T_SA = SA_t(T);
    S_SA.seg.build(S_SA.LCP), S_SA.build_seg = true;
    T_SA.seg.build(T_SA.LCP), T_SA.build_seg = true;
    N = len(S);
    if (N == 1) {
      raw_index = {{0, 0}}, X = {0, 1}, Y = {0, 1}, X_to_block = {0},
      Y_to_block = {0};
      width = {1}, height = {1}, right = {-1}, down = {-1};
      return;
    }
    X_to_block.reserve(2 * N - 1), Y_to_block.reserve(2 * N - 1);
    width.reserve(2 * N - 1), height.reserve(2 * N - 1);
    right.reserve(2 * N - 1), down.reserve(2 * N - 1);
    X = {0}, Y = {0};

    CartesianTree<int, true> CS(S_SA.LCP);
    CartesianTree<int, true> CT(T_SA.LCP);
    hash_to_col.build(N - 1);
    HashMap<int> hash_to_row(N - 1);

    auto is_node = [&](CartesianTree<int, true> &CT, int i) -> bool {
      return (CT.A[i] > 0 && (CT.par[i] == -1 || CT.A[CT.par[i]] != CT.A[i]));
    };

    // 列の先頭に相当するハッシュを集めておく
    HashMap<int> tmp(N - 1);
    FOR(i, N - 1) {
      if (!is_node(CS, i))
        continue;
      int s = S_SA.SA[i], n = S_SA.LCP[i];
      tmp[RH.query(SH, s, s + n).val] = i;
    }

    // occur が小さい行から作っていく
    vc<int> ptr(N);
    FOR(i, N - 1) {
      if (is_node(CT, i))
        ptr[CT.range[i].se - CT.range[i].fi]++;
    }
    ptr = cumsum<int>(ptr);
    vc<int> I(ptr.back(), -1);
    FOR(i, N - 1) {
      if (!is_node(CT, i))
        continue;
      int occ = CT.range[i].se - CT.range[i].fi;
      I[ptr[occ]++] = i;
    }

    auto new_block = [&](int h, int w, int i, int j) -> int {
      int bid = len(raw_index);
      raw_index.eb(i, j);
      X.eb(X.back() + h), Y.eb(Y.back() + w);
      FOR(h) X_to_block.eb(bid), width.eb(-1), right.eb(-1);
      FOR(w) Y_to_block.eb(bid), height.eb(-1), down.eb(-1);
      return bid;
    };

    auto get_w = [&](int i) -> int {
      return CT.A[i] - (CT.par[i] == -1 ? 0 : CT.A[CT.par[i]]);
    };
    auto get_h = [&](int i) -> int {
      return CS.A[i] - (CS.par[i] == -1 ? 0 : CS.A[CS.par[i]]);
    };

    reverse(all(I));
    for (int a0 : I) {
      int j = N - T_SA.SA[a0], n = T_SA.LCP[a0];
      u64 key = RH.query(SH, j - n, j).val;
      int b0 = tmp.get(key, -1);
      if (b0 == -1)
        continue;
      // occur>=2 に対応する block 発見
      int h = get_h(b0), w = get_w(a0);
      int bid = new_block(h, w, j - n, j);
      FOR(x, X[bid], X[bid + 1]) {
        hash_to_row[RH.query(SH, j - n, j - (x - X[bid])).val] = x;
      }
      FOR(y, Y[bid], Y[bid + 1]) {
        hash_to_col[RH.query(SH, j - n + (y - Y[bid]), j).val] = y;
      }
    }
    FOR(i, N - 1) {
      if (!is_node(CT, i))
        continue;
      int r = N - T_SA.SA[i], n = T_SA.LCP[i];
      u64 key = RH.query(SH, r - n, r).val;
      int x = hash_to_row[key];
      width[x] = get_w(i);
      right[x] = hash_to_row.get(RH.query(SH, r - n + width[x], r).val, -1);
    }
    FOR(i, N - 1) {
      if (!is_node(CS, i))
        continue;
      int l = S_SA.SA[i], n = S_SA.LCP[i];
      u64 key = RH.query(SH, l, l + n).val;
      int y = hash_to_col[key];
      height[y] = get_h(i);
      down[y] = hash_to_col.get(RH.query(SH, l, l + n - height[y]).val, -1);
    }

    // occur==1
    auto get_w2 = [&](int i) -> int { // [0,i)
      int k = T_SA.ISA[N - i];
      int n = i, m = 0;
      if (k > 0)
        chmax(m, T_SA.LCP[k - 1]);
      if (k < N - 1)
        chmax(m, T_SA.LCP[k]);
      return n - m;
    };
    auto get_h2 = [&](int i) -> int { // [i,N)
      int k = S_SA.ISA[i];
      int n = N - i, m = 0;
      if (k > 0)
        chmax(m, S_SA.LCP[k - 1]);
      if (k < N - 1)
        chmax(m, S_SA.LCP[k]);
      return n - m;
    };
    int h = get_h2(0), w = get_w2(N);
    int bid = new_block(h, w, 0, N);
    FOR(x, X[bid], X[bid + 1]) {
      int r = N - (x - X[bid]);
      width[x] = get_w2(r);
      right[x] = hash_to_row.get(RH.query(SH, width[x], r).val, -1);
    }
    FOR(y, Y[bid], Y[bid + 1]) {
      int l = y - Y[bid];
      height[y] = get_h2(l);
      down[y] = hash_to_col.get(RH.query(SH, l, N - height[y]).val, -1);
    }
  }

  // S[i,j) に対応する (x,y).
  pair<int, int> get_position(int i, int j) {
    // occur を保って長くする
    auto &seg = S_SA.seg;
    int n = j - i, k = S_SA.ISA[i];
    int m = N - i;
    auto check = [&](int e) -> bool {
      if (e >= n)
        chmin(m, e);
      return e >= n;
    };
    seg.min_left(check, k), seg.max_right(check, k);
    int y = hash_to_col.get(RH.query(SH, i, i + m).val, -1);
    if (y == -1) {
      assert(i + m == N);
      int x = X[n_block() - 1] + (N - j), y = Y[n_block() - 1] + i;
      return {x, y};
    }
    int bid = Y_to_block[y];
    auto [l, r] = raw_index[bid];
    int x = (X[bid] + Y[bid]) + ((r - l) - (j - i)) - y;
    return {x, y};
  }

  void debug() {
    auto [H, W] = shape();
    FOR(x, H) {
      string tmp(W, '.');
      int k = X_to_block[x];
      FOR(y, Y[k], Y[k] + width[x]) tmp[y] = '#';
      print(tmp);
    }
    SHOW(S);
    SHOW(raw_index);
    SHOW(width);
    SHOW(height);
    SHOW(right);
    SHOW(down);
    print();
  }
};
