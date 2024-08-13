#define PROBLEM "https://yukicoder.me/problems/no/1783"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "mod/primitive_root.hpp"
#include "poly/multivar_convolution.hpp"

constexpr int TEN[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

constexpr int MOD = 120586241;
using mint = modint<MOD>;

vc<mint> solve_truncate(int K, vc<mint> f, ll M) {
  // べき零性質を利用
  mint a = f[0];
  f[0] -= a;
  // (a+f)^M
  int LIM = 10 * K;
  chmax(LIM, 1);
  vv(mint, POW, LIM + 1, TEN[K]);
  POW[0][0] = 1;
  POW[1] = f;
  vc<int> ns(K, 10);
  FOR(i, 2, LIM + 1) POW[i] = multivar_convolution(ns, POW[i - 1], f);

  vc<mint> g(TEN[K]);
  FOR(m, LIM + 1) {
    // C(M,m) a^{M-m}f^m
    if (m > M) break;
    mint x = C<mint, true>(M, m);
    x *= a.pow(M - m);
    FOR(i, TEN[K]) g[i] += POW[m][i] * x;
  }
  return g;
}

void solve() {
  LL(NNN, K, M, T);
  int N = TEN[K];
  vc<mint> A(TEN[K]);
  FOR(NNN) {
    INT(a);
    A[a] += mint(1);
  }

  vc<mint> root(11), iroot(11);
  root[0] = 1;
  root[1] = mint(primitive_root(MOD)).pow((MOD - 1) / 10);
  FOR(i, 2, 11) root[i] = root[i - 1] * root[1];
  iroot = root;
  reverse(all(iroot));

  /*
  下の方の桁：truncate
  上の方の桁：cyclic

  上の桁で FFT
  pointwise に multivar pow
  上の桁で iFFT
  */

  auto fft = [&](bool inv) -> void {
    FOR(t, T, K) {
      FOR(i, N) {
        if ((i / TEN[t]) % 10 != 0) continue;
        vc<mint> f(10);
        FOR(j, 10) f[j] = A[i + TEN[t] * j];
        vc<mint> g(10);
        FOR(p, 10) FOR(q, 10) {
          g[q] += f[p] * (inv ? iroot[p * q % 10] : root[p * q % 10]);
        }
        FOR(j, 10) A[i + TEN[t] * j] = g[j];
      }
    }
  };

  fft(false);
  FOR(s, TEN[K - T]) {
    vc<mint> f = {A.begin() + TEN[T] * s, A.begin() + TEN[T] * (s + 1)};
    f = solve_truncate(T, f, M);
    FOR(j, len(f)) { A[TEN[T] * s + j] = f[j]; }
  }
  fft(true);

  mint c = mint(1) / mint(TEN[K - T]);
  for (auto& x: A) x *= c;
  for (auto& x: A) print(x);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
