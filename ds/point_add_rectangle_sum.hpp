#pragma once
#include "ds/fenwick.hpp"


template <typename AbelGroup, bool SMALL = false>
struct Point_Add_Rectangle_Sum {
  using G = typename AbelGroup::value_type;
  int Q;
  vector<ll> X, Y;
  vector<G> WT;
  vector<tuple<ll, ll, ll, ll>> rect;

  Point_Add_Rectangle_Sum() {}

  void add_query(ll x, ll y, G w) {
    X.emplace_back(x), Y.emplace_back(y), WT.emplace_back(w);
  }

  void sum_query(ll xl, ll yl, ll xr, ll yr) {
    rect.emplace_back(xl, yl, xr, yr);
  }

  vector<G> calc() {
    int N = X.size(), Q = rect.size();
    if (N == 0) return vector<G>(Q, AbelGroup::unit());
    int NX = 0, NY = 0;
    if (!SMALL) {
      vector<ll> keyX = X, keyY = Y;
      sort(all(keyX));
      keyX.erase(unique(all(keyX)), keyX.end());
      sort(all(keyY));
      keyY.erase(unique(all(keyY)), keyY.end());
      NX = keyX.size(), NY = keyY.size();
      for (auto &&x: X) x = lower_bound(all(keyX), x) - keyX.begin();
      for (auto &&y: Y) y = lower_bound(all(keyY), y) - keyY.begin();
      for (auto &&[xl, yl, xr, yr]: rect) {
        xl = lower_bound(all(keyX), xl) - keyX.begin();
        xr = lower_bound(all(keyX), xr) - keyX.begin();
        yl = lower_bound(all(keyY), yl) - keyY.begin();
        yr = lower_bound(all(keyY), yr) - keyY.begin();
      }
    }
    if (SMALL) {
      ll mx = *(min_element(X.begin(), X.end()));
      ll my = *(min_element(Y.begin(), Y.end()));
      for (auto &&x: X) x -= mx;
      for (auto &&y: Y) y -= my;
      NX = *(max_element(X.begin(), X.end())) + 1;
      NY = *(max_element(Y.begin(), Y.end())) + 1;
      for (auto &&[xl, yl, xr, yr]: rect) {
        xl -= mx, xr -= mx;
        yl -= my, yr -= my;
        xl = max(0, min<int>(xl, NX));
        xr = max(0, min<int>(xr, NX));
        yl = max(0, min<int>(yl, NY));
        yr = max(0, min<int>(yr, NY));
      }
    }
    vector<vector<pair<int, G>>> ADD(NY + 1);
    vector<vector<tuple<int, int, int>>> CALC_1(NY + 1);
    vector<vector<tuple<int, int, int>>> CALC_2(NY + 1);
    for (int n = 0; n < N; ++n) { ADD[Y[n]].emplace_back(X[n], WT[n]); }
    for (int q = 0; q < Q; ++q) {
      auto &[xl, yl, xr, yr] = rect[q];
      CALC_1[yr].emplace_back(xl, xr, q);
      CALC_2[yl].emplace_back(xl, xr, q);
    };

    vector<G> res(Q, AbelGroup::unit());
    FenwickTree<AbelGroup> bit(NX);

    for (int y = 0; y <= NY; ++y) {
      for (auto &&[xl, xr, q]: CALC_1[y]) {
        auto x = bit.prod(xl, xr);
        res[q] = AbelGroup::op(res[q], x);
      }
      for (auto &&[xl, xr, q]: CALC_2[y]) {
        auto x = AbelGroup::inverse(bit.prod(xl, xr));
        res[q] = AbelGroup::op(res[q], x);
      }
      for (auto &&[x, g]: ADD[y]) { bit.add(x, g); }
    }
    return res;
  }
};
