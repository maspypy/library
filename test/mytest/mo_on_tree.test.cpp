#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "graph/tree.hpp"
#include "graph/ds/mo_on_tree.hpp"
#include "graph/ds/tree_monoid.hpp"
#include "alg/monoid/affine.hpp"
#include "alg/monoid/add_pair.hpp"
#include "mod/modint.hpp"

using mint = modint998;
using AFF = pair<mint, mint>;

AFF gen() {
  mint a = RNG(1, 3);
  mint b = RNG(0, 3);
  return {a, b};
}

template <typename Mono, bool EDGE>
void test() {
  constexpr bool ORIENTED = !(Mono::commute);
  FOR(N, 1, 50) {
    FOR(Q, 1, 50) {
      vc<pi> query(Q);
      vc<AFF> dat;
      if (!EDGE) {
        FOR(v, N) dat.eb(gen());
      } else {
        FOR(i, N - 1) dat.eb(gen());
      }
      Graph<int, 0> G(N);
      FOR(v, 1, N) {
        int p = RNG(0, v);
        G.add(p, v);
      }
      G.build();
      Tree<decltype(G)> tree(G);
      Tree_Monoid<decltype(tree), Mono, EDGE> TM(tree, dat);

      FOR(q, Q) {
        int a = RNG(0, N);
        int b = RNG(0, N);
        query[q] = {a, b};
      }
      Mo_on_Tree<decltype(tree), ORIENTED> mo(tree);
      for (auto&& [a, b]: query) mo.add(a, b);

      if constexpr (!EDGE) {
        AFF f = Mono::unit();
        auto init = [&]() -> void { f = dat[0]; };
        auto add_l = [&](int v) -> void { f = Mono::op(dat[v], f); };
        auto rm_l
            = [&](int v) -> void { f = Mono::op(Mono::inverse(dat[v]), f); };
        auto add_r = [&](int v) -> void { f = Mono::op(f, dat[v]); };
        auto rm_r
            = [&](int v) -> void { f = Mono::op(f, Mono::inverse(dat[v])); };
        auto ans = [&](int q) -> void {
          assert(f == TM.prod_path(query[q].fi, query[q].se));
        };
        mo.calc_vertex(init, add_l, add_r, rm_l, rm_r, ans);
      } else {
        AFF f = Mono::unit();
        auto get = [&](int a, int b) -> int {
          return tree.v_to_e((tree.parent[a] == b ? a : b));
        };
        auto init = [&]() -> void {};
        auto add_l
            = [&](int a, int b) -> void { f = Mono::op(dat[get(a, b)], f); };
        auto rm_l = [&](int a, int b) -> void {
          f = Mono::op(Mono::inverse(dat[get(a, b)]), f);
        };
        auto add_r
            = [&](int a, int b) -> void { f = Mono::op(f, dat[get(a, b)]); };
        auto rm_r = [&](int a, int b) -> void {
          f = Mono::op(f, Mono::inverse(dat[get(a, b)]));
        };
        auto ans = [&](int q) -> void {
          assert(f == TM.prod_path(query[q].fi, query[q].se));
        };
        mo.calc_edge(init, add_l, add_r, rm_l, rm_r, ans);
      }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  // パスの向きが可逆で頂点可換モノイド積
  test<Monoid_Add_Pair<mint>, false>();
  // パスの向きが不可逆で頂点非可換モノイド積
  test<Monoid_Affine<mint>, false>();
  // パスの向きが可逆で辺可換モノイド積
  test<Monoid_Add_Pair<mint>, true>();
  // パスの向きが不可逆で辺非可換モノイド積
  test<Monoid_Affine<mint>, true>();
  solve();
  return 0;
}
