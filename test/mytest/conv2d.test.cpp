#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "mod/modint.hpp"
#include "poly/convolution2d.hpp"

using mint = modint998;

void test() {
  auto gen = [&](ll H, ll W) -> vvc<mint> {
    vv(mint, A, H, W);
    FOR(i, H) FOR(j, W) A[i][j] = RNG(mint::get_mod());
    return A;
  };

  auto naive_conv = [&](vvc<mint> A, vvc<mint> B) -> vvc<mint> {
    ll H = len(A) + len(B) - 1;
    ll W = len(A[0]) + len(B[0]) - 1;
    vv(mint, C, H, W);
    FOR(a, len(A)) FOR(b, len(A[0])) {
      FOR(c, len(B)) FOR(d, len(B[0])) { C[a + c][b + d] += A[a][b] * B[c][d]; }
    }
    return C;
  };

  ll LIM = 10;
  FOR(H1, 1, LIM) FOR(W1, 1, LIM) FOR(H2, 1, LIM) FOR(W2, 1, LIM) {
    auto A = gen(H1, W1);
    auto B = gen(H2, W2);
    auto C1 = naive_conv(A, B);
    auto C2 = convolution2d<mint>(A, B);
    assert(C1 == C2);
  }

  ll H1 = RNG(50, 100);
  ll W1 = RNG(50, 100);
  ll H2 = RNG(50, 100);
  ll W2 = RNG(50, 100);
  auto A = gen(H1, W1);
  auto B = gen(H2, W2);
  auto C1 = naive_conv(A, B);
  auto C2 = convolution2d<mint>(A, B);
  assert(C1 == C2);
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}