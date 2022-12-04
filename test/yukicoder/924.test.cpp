#define PROBLEM "https://yukicoder.me/problems/no/924"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/waveletmatrix.hpp"
#include "ds/fenwicktree/fenwicktree.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  auto Ac = cumsum<ll>(A);
  vi X = A;
  UNIQUE(X);
  for (auto&& a: A) a = LB(X, a);
  WaveletMatrix<ll> WM(A);
  VEC(pi, query, Q);
  for (auto&& [l, r]: query) --l;
  vc<int> med(Q);
  vi low_sum(Q), low_cnt(Q);
  FOR(q, Q) {
    auto [l, r] = query[q];
    ll n = r - l;
    med[q] = WM.kth(l, r, n / 2);
  }

  vvc<int> QID(N);
  FOR(q, Q) QID[med[q]].eb(q);

  vvc<int> AID(N);
  FOR(i, N) AID[A[i]].eb(i);

  FenwickTree<Monoid_Add<ll>> bit_c(N), bit_s(N);

  FOR(x, N) {
    for (auto&& i: AID[x]) {
      bit_c.add(i, 1);
      bit_s.add(i, X[x]);
    }
    for (auto&& q: QID[x]) {
      auto [l, r] = query[q];
      low_cnt[q] = bit_c.sum(l, r);
      low_sum[q] = bit_s.sum(l, r);
    }
  }

  FOR(q, Q) {
    auto [l, r] = query[q];
    ll x = X[med[q]];
    ll lc = low_cnt[q], ls = low_sum[q];
    ll hc = r - l - lc;
    ll hs = Ac[r] - Ac[l] - ls;
    ll ANS = 0;
    ANS += x * lc - ls;
    ANS += hs - x * hc;
    //    print(x, lc, ls, hc, hs);
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
