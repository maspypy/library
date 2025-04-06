#include "alg/monoid_pow.hpp"

/*
インデックス i にコスト cost_i の物が cnt_i 個ある. dat_i in Monoid もある.
所持金 x からはじめて i=l,l+1,...,r-1 について貪欲にとって Monoid 積を計算.
cost_i < LOG. O(LOG * logN time).
https://codeforces.com/contest/1515/problem/I
*/
template <typename Monoid, int LOG>
struct Greedy_Subtract_SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;
  /*
  [0,2^k) の sum に最後に [2^k,infty) をちょうどひとつつけたもの
  [0,2^k) の sum
  */

  vi cost, cnt;
  vc<X> element;

  struct Node {
    array<ll, LOG + 1> SM_A;
    array<ll, LOG + 1> SM_B;
    array<X, LOG + 1> prod_B;
  };
  vc<Node> dat;

  int n, log, size;
  // f(i) = (cost_i, cnt_i, x_i)
  template <typename F>
  Greedy_Subtract_SegTree(int N, F f) {
    build(N, f);
  }

  // f(i) = (cost_i, cnt_i, x_i)
  template <typename F>
  void build(int n_, F f) {
    n = n_;
    if (n == 0) return;
    log = 0;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    cost.assign(size, 0), cnt.assign(size, 0), element.assign(size, MX::unit());
    FOR(i, n) {
      tie(cost[i], cnt[i], element[i]) = f(i);
      assert(0 <= cost[i] && cost[i] < (1LL << LOG));
    }
    dat.resize(2 * size);
    FOR_R(i, 2 * size) update(i);
  }

  void update(int idx) {
    if (size <= idx) {
      int i = idx - size;
      if (n <= i || cnt[i] == 0) {
        fill(all(dat[idx].SM_A), infty<ll>);
        fill(all(dat[idx].SM_B), 0);
        fill(all(dat[idx].prod_B), MX::unit());
        return;
      }
      FOR(k, LOG + 1) {
        if (cost[i] < (1LL << k)) {
          dat[idx].SM_A[k] = infty<ll>;
          dat[idx].SM_B[k] = cost[i] * cnt[i];
          dat[idx].prod_B[k] = monoid_pow<MX>(element[i], cnt[i]);
        } else {
          dat[idx].SM_A[k] = cost[i];
          dat[idx].SM_B[k] = 0;
          dat[idx].prod_B[k] = MX::unit();
        }
      }
      return;
    }
    int l = 2 * idx + 0, r = 2 * idx + 1;
    FOR(k, LOG + 1) {
      dat[idx].SM_A[k] = min(dat[l].SM_A[k], dat[l].SM_B[k] + dat[r].SM_A[k]);
      dat[idx].SM_B[k] = dat[l].SM_B[k] + dat[r].SM_B[k];
      dat[idx].prod_B[k] = MX::op(dat[l].prod_B[k], dat[r].prod_B[k]);
    }
  }

  void set(int i, ll cost_i, ll cnt_i, X x_i) {
    cost[i] = cost_i, cnt[i] = cnt_i, element[i] = x_i;
    i += size;
    while (i >= 1) update(i), i /= 2;
  }

  // return: 残金, モノイド積
  pair<ll, X> query(int L, int R, ll x) {
    X prod = MX::unit();
    int k = LOG;
    auto upd_k = [&]() -> void {
      while (k > 0 && (x < (1LL << (k - 1)))) --k;
    };
    auto dfs = [&](auto& dfs, int idx, int nl, int nr) -> void {
      if (nr <= L || R <= nl) return;
      if (size <= idx) {
        int i = idx - size;
        ll take = (cost[i] == 0 ? cnt[i] : min<ll>(x / cost[i], cnt[i]));
        x -= take * cost[i], prod = MX::op(prod, monoid_pow<MX>(element[i], take));
        upd_k();
        return;
      }
      int l = 2 * idx + 0, r = 2 * idx + 1, nm = (nl + nr) / 2;
      if (L <= nl && nr <= R) {
        if (k == 0) {
          prod = MX::op(prod, dat[idx].prod_B[0]);
          return;
        }
        if (dat[idx].SM_B[k] <= x) {
          x -= dat[idx].SM_B[k], prod = MX::op(prod, dat[idx].prod_B[k]);
          upd_k();
          return;
        }
        if (x < dat[idx].SM_A[k - 1] && x >= dat[idx].SM_B[k - 1]) {
          x -= dat[idx].SM_B[k - 1], prod = MX::op(prod, dat[idx].prod_B[k - 1]);
          upd_k();
          return;
        }
      }
      dfs(dfs, l, nl, nm);
      dfs(dfs, r, nm, nr);
    };
    dfs(dfs, 1, 0, size);
    return {x, prod};
  }

  // 全区間. return: 残金, モノイド積
  pair<ll, X> query(ll x) { return query(0, size, x); }
};