#define PROBLEM "https://yukicoder.me/problems/no/2627"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/dynamic_segtree_sparse.hpp"
#include "alg/monoid/add_pair.hpp"
#include "other/fibonacci_search.hpp"

/*
max - min を減らすということ
0 回操作するやつがあるとしてよい

width=Kq+r

商を持つ
最小値のあまりを決めると
[c,c+q] （r箇所）
[c,c+q) （K-r箇所）
これで c を最適化したいのだが
これは c について凸なので適当にやる

やりたいこと c を決めたときの計算ができればよい
セグ木でいいか
*/

void solve() {
  LL(N, K, L, U);
  VEC(ll, A, N);

  for (auto& x: A) x += K;

  vvc<ll> dat(K + K);
  FOR(i, N) {
    ll r = A[i] % K;
    dat[r].eb((A[i] - r) / K);
    dat[K + r].eb((A[i] - K - r) / K);
  }
  // FOR(k, K + K) print("dat", k, dat[k]);

  ll q, r;
  tie(q, r) = divmod(U - L + 1, K);
  ll LIM = ceil<ll>(1LL << 40, K);
  Dynamic_SegTree_Sparse<Monoid_Add_Pair<ll>, false> seg(10 * N, 0, LIM);
  using np = decltype(seg)::np;

  np X = seg.new_root();
  np Y = seg.new_root();
  FOR(k, K) {
    if (k < r)
      for (auto& x: dat[k]) { X = seg.multiply(X, x, {1, x}); }
    if (k >= r)
      for (auto& x: dat[k]) { Y = seg.multiply(Y, x, {1, x}); }
  }

  auto eval = [&](i128 c) -> i128 {
    i128 ans = 0;
    if (0 <= c) {
      auto [cnt, sm] = seg.prod(X, 0, c);
      ans += i128(cnt) * c - sm;
      tie(cnt, sm) = seg.prod(Y, 0, c);
      ans += i128(cnt) * c - sm;
    }
    if (c + q + 1 < LIM) {
      auto [cnt, sm] = seg.prod(X, c + q + 1, LIM);
      ans += i128(sm) - i128(cnt) * (c + q);
      tie(cnt, sm) = seg.prod(Y, c + q, LIM);
      ans += i128(sm) - i128(cnt) * (c + q - 1);
    }
    return ans;
  };

  auto best = [&]() -> ll { return fibonacci_search<i128, true>(eval, 0, LIM).fi; };

  ll ANS = infty<ll>;
  FOR(L, K) {
    chmin(ANS, best());
    // L 削除
    // L+r Y->X
    // L+K Y
    for (auto& x: dat[L]) { X = seg.multiply(X, x, {-1, -x}); }
    for (auto& x: dat[L + r]) {
      X = seg.multiply(X, x, {1, x});
      Y = seg.multiply(Y, x, {-1, -x});
    }
    for (auto& x: dat[L + K]) { Y = seg.multiply(Y, x, {1, x}); }
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}