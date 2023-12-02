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

  auto merge = [&](vc<int>& A, vc<int>& B) -> pair<vc<int>, vc<int>> {
    vc<int> C;
    vc<int> left;
    int a = 0, b = 0;
    A.eb(infty<int>), B.eb(infty<int>);
    FOR(len(A) + len(B) - 2) {
      if (A[a] < B[b]) {
        C.eb(A[a++]), left.eb(1);
      } else {
        C.eb(B[b++]), left.eb(0);
      }
    }
    POP(A), POP(B);
    return {C, left};
  };

  int n = len(STT.par);
  vvc<int> V(n);
  vvc<int> LEFT(n);
  vvc<ll> Ac(n);
  {
    auto dfs = [&](auto& dfs, int k) -> void {
      int l = STT.lch[k], r = STT.rch[k], a = STT.A[k];
      if (l != -1) dfs(dfs, l);
      if (r != -1) dfs(dfs, r);
      if (l == -1 && r == -1) {
        V[k] = {a};
        return;
      }
      if (r == -1) {
        if (STT.heavy[k]) {
          vc<int> B = {a};
          auto [C, left] = merge(V[l], B);
          V[k] = C;
          LEFT[k] = left;
          return;
        }
        V[k] = V[l];
        LEFT[k] = vc<int>(len(V[k]), 1);
        return;
      }
      auto [C, left] = merge(V[l], V[r]);
      V[k] = C;
      LEFT[k] = left;
    };
    dfs(dfs, 0);
  }

  FOR(i, n) {
    Ac[i] = {0};
    for (auto& v: V[i]) Ac[i].eb(Ac[i].back() + A[v]);
    LEFT[i] = cumsum<int>(LEFT[i]);
  }

  auto get = [&](int k, ll K, ll L, ll R, ll delta) -> ll {
    ll cnt = R - L;
    ll sm = Ac[k][R] - Ac[k][L];
    ll val = K * cnt + sm;
    val = 10 * val + (delta != -1);
    return val;
  };

  auto solve = [&](ll L, ll R, ll delta, ll K) -> int {
    ll total = get(0, K, L, R, true);
    ll need = ceil<ll>(total, 2);
    auto dfs = [&](auto& dfs, int k, ll L, ll R, ll d, ll need_path) -> int {
      if (get(k, K, L, R, d) < need_path) return -1;
      int l = STT.lch[k], r = STT.rch[k], a = STT.A[k], b = STT.B[k];
      if (l == -1 && r == -1) { return a; }
      ll L1 = LEFT[k][L], R1 = LEFT[k][R];
      ll L2 = L - L1, R2 = R - R1;
      ll d1 = -1, d2 = -1;
      if (d != -1) {
        if (LEFT[k][d] < LEFT[k][d + 1]) {
          d1 = LEFT[k][d];
        } else {
          d2 = d - LEFT[k][d];
        }
      }
      if (r == -1) {
        if (STT.heavy[k]) {
          // light に根を足したもの
          int v = dfs(dfs, l, L1, R1, d1, need);
          if (v != -1) return v;
          return a;
        }
        // heavy に light edge を足したもの
        return dfs(dfs, l, L1, R1, d1, need);
      }
      if (STT.heavy[k]) {
        // heavy path をマージしたもの
        int v1 = dfs(dfs, l, L1, R1, d1, need_path);
        if (v1 != -1) return v1;
        return dfs(dfs, r, L2, R2, d2, need_path - get(l, K, L1, R1, d1));
      }
      // light をマージしたもの
      int v = dfs(dfs, l, L1, R1, d1, need);
      if (v != -1) return v;
      return dfs(dfs, r, L2, R2, d2, need);
    };
    return dfs(dfs, 0, L, R, delta, need);
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
