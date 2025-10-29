#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/offline_query/parallel_binary_search.hpp"
#include "ds/segtree/beats_summin_chmax.hpp"

void solve() {
  LL(N, K, Q);
  VEC(ll, A, N);
  vc<tuple<ll, ll, ll>> U(K);
  vc<tuple<ll, ll, ll>> query(Q);
  FOR(k, K) {
    LL(l, r, x);
    U[k] = {--l, r, x};
  }
  FOR(k, Q) {
    LL(l, r, x);
    query[k] = {--l, r, x};
  }

  Beats_SumMin_Chmax<ll> seg;
  auto init = [&]() -> void { seg.build(N, [&](ll i) -> ll { return A[i]; }); };

  auto upd = [&](ll k) -> void {
    assert(0 <= k && k < K);
    auto [l, r, x] = U[k];
    seg.chmax(l, r, x);
  };
  auto check = [&](ll q) -> bool {
    auto [l, r, x] = query[q];
    return seg.prod(l, r).fi >= x;
  };

  auto ANS = parallel_binary_search(Q, K + 1, -1, init, upd, check);
  for (auto& x : ANS) {
    if (x == K + 1) x = -1;
    print(x);
  }
}

signed main() { solve(); }
