#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/tree.hpp"
#include "graph/rerooting_dp.hpp"

#include "linalg/xor/vector_space_xor.hpp"
#include "linalg/xor/mat_inv_xor.hpp"
#include "linalg/xor/transpose.hpp"

const int LOG = 64;

vc<u64> solve_QOJ_5445(int N, vc<int> par, vvc<u64> dat) {
  using SP = Vector_Space_Xor<u64>;

  Graph<bool, 0> G(N);
  FOR(v, 1, N) { G.add(par[v - 1] - 1, v); }
  G.build();
  Tree<decltype(G)> tree(G);

  vc<SP> dual(N);
  FOR(v, N) {
    SP x;
    for (auto&& e: dat[v]) x.add_element(e);
    dual[v] = x.orthogonal_space(LOG);
  }

  /*
  木 dp の状態
  ・深さ d のときに dual space に a が追加される (d,a) というイベントの列
  ・高々 64
  */
  using P = pair<int, u64>;
  using Data = vc<P>;
  Data unit = {};

  auto fee = [&](Data& x, Data& y) -> Data {
    // merge sort
    Data z;
    auto V = SP{};
    auto add = [&](P& dat) -> void {
      if (len(V) == LOG) return;
      if (V.add_element(dat.se)) z.eb(dat.fi, V.dat.back());
    };

    int p = 0, q = 0;
    while (p < len(x) || q < len(y)) {
      if (len(V) == LOG) break;
      if (p == len(x)) { add(y[q++]); }
      elif (q == len(y)) { add(x[p++]); }
      else {
        if (x[p].fi < y[q].fi) {
          add(x[p++]);
        } else {
          add(y[q++]);
        }
      }
    }
    return z;
  };
  auto fev = [&](Data& x, int v) -> Data {
    Data y;
    for (auto&& a: dual[v].dat) y.eb(0, a);
    auto V = dual[v];
    for (auto&& [d, a]: x) {
      if (len(V) == LOG) break;
      if (V.add_element(a)) y.eb(d, V.dat.back());
    }
    return y;
  };
  // e は v から出る有向辺
  auto fve = [&](Data x, auto& e) -> Data {
    for (auto&& [d, a]: x) ++d;
    return x;
  };
  Rerooting_dp<decltype(tree), Data> dp(tree, fee, fev, fve, unit);

  vc<u64> ANS(N);
  FOR(v, N) {
    auto event = dp[v];
    // full space にしておく
    vc<int> done(LOG);
    for (auto&& [d, a]: event) done[topbit(a)] = 1;
    FOR(i, LOG) if (!done[i]) event.eb(N, u64(1) << i);
    assert(len(event) == LOG);
    vc<u64> mat(LOG);
    FOR(i, LOG) mat[i] = event[i].se;
    mat = mat_inv_xor<u64>(mat, 0);
    mat = transpose<u64>(LOG, LOG, mat);
    FOR(j, LOG) { event[j].se = mat[j]; }
    event.insert(event.begin(), {0, u64(0)});

    SP X{};
    FOR_R(i, 1, 1 + LOG) {
      u64 x = event[i].se;
      X.add_element(x);
      int t1 = event[i - 1].fi, t2 = event[i].fi;
      if (t1 < t2) {
        u64 ans = X.get_max(0);
        ANS[v] += ans * u64(t2 - t1);
      }
    }
  }
  return ANS;
}

void solve() {
  INT(N);
  VEC(int, par, N - 1);
  vvc<u64> dat(N);
  FOR(v, N) {
    INT(n);
    dat[v].resize(n);
    FOR(i, n) { read(dat[v][i]); }
  }
  auto ANS = solve_QOJ_5445(N, par, dat);
  for (auto&& x: ANS) print(x);
}
signed main() {
  solve();
  return 0;
}