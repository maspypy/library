#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/tree.hpp"
#include "graph/rerooting_dp.hpp"

#include "alg/monoid/xor_basis.hpp"
#include "linalg/xor/mat_inv_xor.hpp"
#include "linalg/xor/transpose.hpp"
#include "linalg/xor/solve_linear_xor.hpp"

const int LOG = 64;

vc<u64> solve_QOJ_5445(int N, vc<int> par, vvc<u64> dat) {
  using Mono = Monoid_XorBasis<u64>;
  using SP = Mono::value_type;
  Graph<bool, 0> G(N);
  FOR(v, 1, N) { G.add(par[v - 1] - 1, v); }
  G.build();
  Tree<decltype(G)> tree(G);

  vc<SP> dual(N);
  FOR(v, N) {
    SP X = Mono::unit();
    for (auto&& e: dat[v]) { Mono::add_element(X, e); }
    dual[v] = solve_linear_xor<u64>(len(X), LOG, X, 0, 0);
    dual[v].erase(dual[v].begin());
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
    auto V = Mono::unit();
    auto add = [&](P& dat) -> void {
      if (len(V) == LOG) return;
      if (Mono::add_element(V, dat.se)) z.eb(dat.fi, V.back());
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
    for (auto&& a: dual[v]) y.eb(0, a);
    auto V = dual[v];
    for (auto&& [d, a]: x) {
      if (len(V) == LOG) break;
      if (Mono::add_element(V, a)) y.eb(d, V.back());
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

    SP X = Mono::unit();
    FOR_R(i, 1, 1 + LOG) {
      u64 x = event[i].se;
      Mono::add_element(X, x);
      int t1 = event[i - 1].fi, t2 = event[i].fi;
      if (t1 < t2) {
        u64 ans = Mono::get_max(X, 0);
        ANS[v] += ans * u64(t2 - t1);
      }
    }
  }
  return ANS;
}

void test_QOJ_5445() {
  int N = 5;
  vc<int> par = {1, 2, 2, 3};
  vvc<u64> dat(N);
  dat[0] = {83, 75, 58};
  dat[1] = {125, 124, 58, 16};
  dat[2] = {39, 125, 71, 112};
  dat[3] = {69, 66, 5};
  dat[4] = {48, 73, 69, 6};
  auto ANS = solve_QOJ_5445(N, par, dat);
  assert(ANS == vc<u64>({171, 125, 183, 142, 243}));
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test_QOJ_5445();
  solve();
  return 0;
}