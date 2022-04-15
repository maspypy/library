#include "ds/fenwick.hpp"

template <typename WT = ll, bool SMALL = false>
struct RectangleSums {
  int N;
  int n, Q;
  vi X, Y;
  vi keyX, keyY;
  ll min_x, max_x, min_y, max_y;
  vc<WT> wt;
  vc<vc<pair<int, WT>>> add;
  vc<vc<tuple<int, int, int>>> query_l;
  vc<vc<tuple<int, int, int>>> query_r;

  RectangleSums(int N)
      : N(N), n(0), Q(0), X(N), Y(N), keyX(N), keyY(N), wt(N) {}

  void add_pt(ll x, ll y, WT w = 1) {
    X[n] = x, Y[n] = y, wt[n] = w, keyX[n] = x, keyY[n] = y;
    ++n;
    if (n == N) { compress(); }
  }

  void compress() {
    if (!SMALL) {
      UNIQUE(keyX), UNIQUE(keyY);
      add.resize(len(keyX) + 1);
      FOR(i, N) {
        ll x = X[i], y = Y[i], w = wt[i];
        x = LB(keyX, x), y = LB(keyY, y);
        add[x].eb(y, w);
      }
    } else {
      min_x = (N == 0 ? 0 : MIN(X));
      max_x = (N == 0 ? 0 : MAX(X));
      min_y = (N == 0 ? 0 : MIN(Y));
      max_y = (N == 0 ? 0 : MAX(Y));
      add.resize(max_x - min_x + 2);
      FOR(i, N) {
        ll x = X[i], y = Y[i], w = wt[i];
        x -= min_x, y -= min_y;
        add[x].eb(y, w);
      }
    }
    query_l.resize(len(add));
    query_r.resize(len(add));
  }

  void add_rect(ll xl, ll yl, ll xr, ll yr) {
    assert(n == N);
    if (!SMALL) {
      xl = LB(keyX, xl), xr = LB(keyX, xr);
      yl = LB(keyY, yl), yr = LB(keyY, yr);
    } else {
      xl -= min_x, xr -= min_x;
      yl -= min_y, yr -= min_y;
      xl = clamp(xl, 0LL, max_x - min_x + 1);
      xr = clamp(xr, 0LL, max_x - min_x + 1);
      yl = clamp(yl, 0LL, max_y - min_y + 1);
      yr = clamp(yr, 0LL, max_y - min_y + 1);
    }
    query_l[xl].eb(Q, yl, yr);
    query_r[xr].eb(Q, yl, yr);
    ++Q;
  }

  vc<WT> calc() {
    assert(n == N);
    vc<WT> ANS(Q);
    int k = (SMALL ? max_y - min_y + 2 : len(keyY) + 1);
    FenwickTree<Group_Add<WT>> bit(k);
    FOR(x, len(add)) {
      for (auto&& t: query_l[x]) {
        auto [q, yl, yr] = t;
        ANS[q] -= bit.sum(yl, yr);
      }
      for (auto&& t: query_r[x]) {
        auto [q, yl, yr] = t;
        ANS[q] += bit.sum(yl, yr);
      }
      for (auto&& t: add[x]) {
        auto [y, w] = t;
        bit.add(y, w);
      }
      query_l[x].clear();
      query_r[x].clear();
    }
    Q = 0;
    return ANS;
  }

  void doc() {
    print("N 個の点は最初に決めてしまう。");
    print("同じ点群に対してクエリをやり直せる。"); // abc233-h
    print("SMALL=true にすると、座圧をしないため少し高速");
  }
};
