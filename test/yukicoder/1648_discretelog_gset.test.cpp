#define PROBLEM "https://yukicoder.me/problems/no/1648"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "alg/group_mul.hpp"
#include "alg/gset_gl2_vec.hpp"
#include "other/discrete_log.hpp"

using mint = modint998;

void solve() {
  mint A, B, P, Q;
  read(A), read(B), read(P), read(Q);
  swap(P, Q);

  if (B != mint(0)) {
    using GSet = GSet_GL2_Vec<mint>;
    using G = typename GSet::G;
    using X = typename GSet::X;
    // 行列は可逆なので、離散対数問題で解ける
    G g;
    g[0] = {mint(0), mint(1)};
    g[1] = {-B, A};
    X x = {mint(2), A};
    X y = {P, Q};
    // g^{n-1}x=y
    auto H = [&](X x) -> ll { return (ll(x.fi.val)) << 32 | (x.se.val); };
    ll lb = 1;
    ll ub = 10'000'000'000;
    ll n = discrete_log_gset<GSet>(g, x, y, H, lb, ub);
    return print(n + 1);
  }
  // X = A, Y = 0
  assert(A * P == Q);
  auto H = [&](mint x) -> ll { return x.val; };
  ll lb = 1;
  ll ub = 10'000'000'000;
  using Grp = Group_Mul<mint>;

  ll n = discrete_log<Grp>(A, P, H, lb, ub);
  print(n + 1);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
