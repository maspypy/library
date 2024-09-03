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
      if (k < N) {
        V[k] = {k};
        return;
      }
      int l = STT.lch[k], r = STT.rch[k];
      dfs(dfs, l), dfs(dfs, r);
      auto [C, left] = merge(V[l], V[r]);
      V[k] = C;
      LEFT[k] = left;
    };
    dfs(dfs, 2 * N - 2);
  }

  FOR(i, n) {
    Ac[i] = {0};
    for (auto& v: V[i]) Ac[i].eb(Ac[i].back() + A[v]);
    LEFT[i] = cumsum<int>(LEFT[i]);
  }

  auto &lch = STT.lch, &rch = STT.rch;
  // print("lch", lch);
  // print("rch", rch);
  auto solve = [&](ll L, ll R, ll delta, ll K) -> int {
    auto get = [&](int k, ll L, ll R, ll delta) -> ll {
      // この集合の中で [L,R) 番目に注目
      // K+A[v] 重みでクラスタの重み和を求める
      ll cnt = R - L;
      ll sm = Ac[k][R] - Ac[k][L];
      ll val = K * cnt + sm;
      val = 10 * val + (delta != -1);
      return val;
    };
    ll total = get(2 * N - 2, L, R, delta);
    // print("ques", L, R, K, delta), flush();
    // print("tot", total);
    ll large = ceil<ll>(total, 2);
    auto dfs = [&](auto& dfs, int k, ll L, ll R, ll d, ll cu, ll cv) -> int {
      if (cu >= large || cv >= large) return -1;
      if (k < N) { return k; }
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
      int l = lch[k], r = rch[k];
      ll a = get(l, L1, R1, d1), b = get(r, L2, R2, d2);
      assert(cu + cv + a + b == total);
      if (STT.is_compress[k]) {
        if (cu + a > cv + b) {
          return dfs(dfs, l, L1, R1, d1, cu, cv + b);
        } else {
          return dfs(dfs, r, L2, R2, d2, cu + a, cv);
        }
      }
      if (STT.B[k] == -1) {
        if (a > b) {
          return dfs(dfs, l, L1, R1, d1, cu + b, 0);
        } else {
          return dfs(dfs, r, L2, R2, d2, cu + a, 0);
        }
      }
      if (a + cv >= large) { return dfs(dfs, l, L1, R1, d1, cu + b, cv); }
      int kk = dfs(dfs, r, L2, R2, d2, cu + cv + a, 0);
      return (kk == -1 ? STT.A[k] : kk);
    };
    return dfs(dfs, 2 * N - 2, L, R, delta, 0, 0);
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
    flush();
    X_SUM += X;
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}