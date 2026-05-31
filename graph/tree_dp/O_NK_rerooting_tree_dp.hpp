
// 2乗の木DP型のO(NK)全方位.
// 各頂点 v を根としたときのサイズ K の DP 値だけが最終的に必要である場合
// https://codeforces.com/contest/2229/problem/I
//
// f_ee(A, B, L, R)
// f_ev(A, v, L, R)
// f_ve(A, v, p, L, R)
// get_ANS(A, v)
// A, B や返り値は Offset_Vector<T> で、返り値は [L,R) になる組を全計算
//
// f_ee: virtual tree のマージ
// f_ev: virtual tree に根をつけて real tree にする
// f_ve: real tree に親辺をつけて virtual tree にする
// get_ANS: virtual tree, v から答を得る. [K-1,K]
template <typename GT, typename T, typename F1, typename F2, typename F3,
          typename F4>
vc<T> O_NK_rerooting_tree_dp(GT& G, int K, F1 f_ee, F2 f_ev, F3 f_ve,
                             F4 get_ANS, const T unit) {
  int N = G.N;
  vc<int> V(N), par(N, -1), sz(N, 1);
  vvc<int> ch(N);
  {
    int t = 0;
    V[t++] = 0;
    FOR(i, N) {
      int v = V[i];
      for (auto& e : G[v]) {
        if (e.to == par[v]) continue;
        V[t++] = e.to;
        par[e.to] = v;
        ch[v].eb(e.to);
      }
    }
    FOR_R(i, 1, N) {
      int v = V[i];
      sz[par[v]] += sz[v];
    }
  }

  /*
  dp_down[v]: virtual tree at v.
  dp_prefix[c]: prefix virtual tree at v, before c. (c: not included)
  dp_up[v]: virtual tree at v, upward.
  */

  using D = OffsetVector<T>;
  vc<D> dp_down(N), dp_prefix(N), dp_up(N);
  vc<T> ANS(N);

  // calc dp_down, dp_prefix
  FOR_R(i, N) {
    int v = V[i];
    D X(0, 1, unit);
    int n = 0;
    for (int c : ch[v]) {
      dp_prefix[c] = X;
      D Y = f_ev(dp_down[c], c, 0, min<int>(K, sz[c]) + 1);
      Y = f_ve(Y, c, v, 0, min<int>(K, sz[c]) + 1);
      n += sz[c];
      X = f_ee(X, Y, 0, min<int>(n, K) + 1);
    }
    dp_down[v] = X;
  }

  dp_up[0] = D(0, 1, unit);
  FOR(i, N) {
    int v = V[i];
    int nc = len(ch[v]);
    D X = dp_up[v];
    int s = sz[v];
    FOR_R(k, nc) {
      int c = ch[v][k];
      D Y = f_ee(X, dp_prefix[c], max(K - sz[c] - 1, 0), K + 1);
      Y = f_ev(Y, v, max(K - sz[c], 0), K + 1);
      dp_up[c] = f_ve(Y, v, c, max(K - sz[c], 0), K + 1);
      s -= sz[c];
      Y = f_ev(dp_down[c], c, 0, min(K, sz[c]) + 1);
      Y = f_ve(Y, c, v, 0, min(K, sz[c]) + 1);
      X = f_ee(X, Y, max(K - s, 0), K + 1);
    }
    ANS[v] = get_ANS(X, v);
  }
  return ANS;
}
