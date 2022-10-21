#pragma once

/*
・各 i に対して、[i, m) に対する計算結果
・各 j に対して、[m, j) に対する計算結果
が陽に持てて、そこからクエリ [i, j) に答えられるときに使える。
----
・1要素の追加：O(NlogN) 回、データのマージ：O(Q) 回。
・大きなマージに時間がかかるときにはセグ木より高速。
・disjoint sparse table と同じ仕組みだが、省メモリ。
----
example：xor basis のマージ
https://codeforces.com/contest/1100/submission/153353485
*/
template <typename Data>
struct Divide_Conquer_Range_Query {
  int n;
  vc<pair<int, int>> query;
  vc<Data> dat;

  Divide_Conquer_Range_Query(int n) : n(n) {}
  void add(int l, int r) {
    assert(0 <= l && l < r && r <= n);
    query.eb(l, r);
  }

  // add_left：(i, data) -> data
  // add_right：(i, data) -> data
  // calc：(q, data_l, data_r) -> data
  template <typename AL, typename AR, typename CALC>
  void calc(Data empty_data, AL add_left, AR add_right, CALC calc) {
    auto dfs = [&](auto self, int L, int R, vc<int>& I) -> void {
      vc<int> left, right;
      int M = (L + R) / 2;
      // [i, M) に対する計算データ
      dat[M] = empty_data;
      FOR_R(i, L, M) { dat[i] = add_left(i, dat[i + 1]); }
      // [M, R) に対する計算データ
      int k = M;
      Data data_r = empty_data;
      for (auto&& q: I) {
        auto [l, r] = query[q];
        if (r <= M) left.eb(q);
        elif (M < l) right.eb(q);
        else {
          while (k < r) data_r = add_right(k++, data_r);
          calc(q, dat[l], data_r);
        }
      }
      if (len(left)) self(self, L, M, left);
      if (len(right)) self(self, M, R, right);
    };
    dat.resize(n + 1);
    vc<int> I(len(query));
    iota(all(I), 0);
    sort(all(I), [&](auto& x, auto& y) { return query[x].se < query[y].se; });
    dfs(dfs, 0, n, I);
  }
};