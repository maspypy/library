#define PROBLEM "https://yukicoder.me/problems/no/2626"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "string/rollinghash.hpp"
#include "poly/middle_product.hpp"

using mint = modint998;

void solve() {
  LL(N, M, K);
  STR(A, B);
  RollingHash RH;

  vc<mint> F1(N), F2(N), G1(M), G2(M);
  FOR(i, N) F1[i] = ('a' <= A[i] && A[i] <= 'z');
  FOR(i, N) F2[i] = mint(1) - F1[i];
  FOR(i, M) G1[i] = ('a' <= B[i] && B[i] <= 'z');
  FOR(i, M) G2[i] = mint(1) - G1[i];

  for (auto& x: A) {
    if ('a' <= x && x <= 'z') x ^= 32;
  }
  for (auto& x: B) {
    if ('a' <= x && x <= 'z') x ^= 32;
  }

  vc<mint> X = middle_product<mint>(F1, G2);
  vc<mint> Y = middle_product<mint>(F2, G1);
  FOR(i, len(Y)) X[i] += Y[i];

  auto AH = RH.build(A);
  auto BH = RH.build(B);

  ll ANS = 0;
  FOR(i, len(X)) {
    ll cnt = X[i].val;
    auto a = RH.query(AH, i, i + M);
    auto b = RH.query(BH, 0, M);
    bool match = (a == b);
    if (match && 1 <= cnt && cnt <= K) { ++ANS; }
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
