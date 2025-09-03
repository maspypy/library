#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/potentialized_unionfind.hpp"
#include "mod/modint.hpp"
#include "linalg/matrix_mul.hpp"

using mint = modint998;

struct Mono {
  using value_type = array<array<mint, 2>, 2>;
  using X = value_type;
  static X op(X L, X R) { return matrix_mul<mint, 2>(L, R); }
  static constexpr X unit() { return {mint(1), mint(0), mint(0), mint(1)}; }
  static X inverse(X& x) { return {x[1][1], -x[0][1], -x[1][0], x[0][0]}; }
  static constexpr bool commute = 0;
};

void solve() {
  INT(N, Q);
  Potentialized_UnionFind<Mono> uf(N);

  FOR(Q) {
    INT(t, u, v);
    if (t == 0) {
      array<array<mint, 2>, 2> x;
      read(x);
      auto [is_same, path] = uf.get_path(v, u);
      bool valid = (!is_same) || (path == x);
      print(valid);
      if (!is_same) uf.merge(v, u, x);
    }
    if (t == 1) {
      auto [is_same, path] = uf.get_path(v, u);
      if (!is_same) {
        print(-1);
      } else {
        print(path);
      }
    }
  }
}

signed main() {
  solve();
  return 0;
}
