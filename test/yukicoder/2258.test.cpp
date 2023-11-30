#define PROBLEM "https://yukicoder.me/problems/no/2258"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/static_toptree.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree(0, 0);
  VEC(int, A, N);

  Tree<decltype(G)> tree(G);
  Static_TopTree<decltype(tree)> STT(tree);

  int n = len(STT.par);
  vvc<int> V(n);
  vvc<ll> Ac(n);
  {
    auto dfs = [&](auto& dfs, int k) -> void {
      int l = STT.lch[k], r = STT.rch[k], a = STT.A[k], b = STT.B[k];
      if (l != -1) dfs(dfs, l);
      if (r != -1) dfs(dfs, r);
      if (l == -1 && r == -1) {
        V[k] = {a};
        return;
      }
      if (r == -1) {
        if (STT.heavy[k]) {
          V[k] = V[l];
          V[k].eb(a);
          return;
        }
        V[k] = V[l];
        return;
      }
      V[k] = V[l];
      V[k].insert(V[k].end(), all(V[r]));
    };
    dfs(dfs, n - 1);
  }
  FOR(i, n) {
    sort(all(V[i]));
    Ac[i] = {0};
    for (auto& v: V[i]) Ac[i].eb(Ac[i].back() + A[v]);
  }

  auto get = [&](int k, ll K, ll L, ll R, ll delta) -> ll {
    int a = LB(V[k], L);
    int b = LB(V[k], R);
    ll cnt = b - a;
    ll sm = Ac[k][b] - Ac[k][a];
    ll val = K * cnt + sm;
    val = 10 * val + binary_search(all(V[k]), delta);
    return val;
  };

  auto get_v = [&](int v, ll K, ll L, ll R, ll delta) -> ll {
    ll val = 0;
    if (L <= v && v < R) val += A[v] + K;
    val *= 10;
    if (v == delta) ++val;
    return val;
  };

  auto solve = [&](ll L, ll R, ll delta, ll K) -> int {
    ll total = get(n - 1, K, L, R, delta);
    ll need = ceil<ll>(total, 2);
    auto dfs = [&](auto& dfs, int k, ll need_path) -> int {
      if (get(k, K, L, R, delta) < need_path) return -1;
      int l = STT.lch[k], r = STT.rch[k], a = STT.A[k], b = STT.B[k];
      if (l == -1 && r == -1) {
        return (get_v(a, K, L, R, delta) >= need_path ? a : -1);
      }
      if (r == -1) {
        if (STT.heavy[k]) {
          // light に根を足したもの
          int v = dfs(dfs, l, need);
          if (v != -1) return v;
          return (get(k, K, L, R, delta) >= need_path ? a : -1);
        }
        // heavy に light edge を足したもの
        return dfs(dfs, l, need);
      }
      if (STT.heavy[k]) {
        // heavy path をマージしたもの
        int v1 = dfs(dfs, l, need_path);
        if (v1 != -1) return v1;
        return dfs(dfs, r, need_path - get(l, K, L, R, delta));
      }
      // light をマージしたもの
      int v = dfs(dfs, l, need);
      if (v != -1) return v;
      return dfs(dfs, r, need);
    };
    return dfs(dfs, n - 1, need);
  };

  ll X_SUM = 0;
  INT(Q);
  FOR(Q) {
    LL(aa, bb, kk, delta);
    ll a = (aa + X_SUM) % N;
    ll b = (bb + 2 * X_SUM) % N;
    int mod = 150001;
    ll K = (kk + (X_SUM % mod) * (X_SUM % mod)) % mod;
    ll L = min(a, b);
    ll R = 1 + max(a, b);

    ll X = solve(L, R, delta, K);
    // print(X, ",", L, R, K, delta);
    print(X);
    X_SUM += X;
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
