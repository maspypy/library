#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/convolution.hpp"
#include "mod/dynamic_modint.hpp"
#include "seq/reeds_sloane.hpp"

template <typename mint>
vc<mint> from_PQ(int N, vc<mint> P, vc<mint> Q) {
  P.resize(N), Q.resize(N);
  vc<mint> S(N);
  FOR(i, N) {
    S[i] += P[i];
    FOR(j, 1, len(Q)) {
      int k = i - j;
      if (0 <= k) S[i] -= S[k] * Q[j];
    }
  }
  return S;
}

template <int mod>
void test(int T) {
  using mint = modint<mod>;
  auto pfs = factor(mod);

  FOR(T) {
    int N = RNG(1, 20);
    int L = RNG(0, N + 1);
    vc<mint> QQ(L + 1);
    vc<mint> PP(L);
    QQ[0] = 1;
    FOR(i, L) PP[i] = RNG(0, mod), QQ[1 + i] = RNG(0, mod);
    auto S = from_PQ(N, PP, QQ);
    auto [P, Q] = Reeds_Sloane<mint>(S, pfs);
    assert(len(P) <= L);
    assert(len(Q) - 1 <= L);
    assert(Q[0] == 1);
    assert(S == from_PQ(N, P, Q));
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  int T = 1 << 13;
  test<1>(T);
  test<2>(T);
  test<3>(T);
  test<4>(T);
  test<5>(T);
  test<6>(T);
  test<7>(T);
  test<8>(T);
  test<9>(T);
  test<10>(T);
  test<12>(T);
  test<16>(T);
  test<32>(T);
  test<64>(T);
  test<60>(T);
  test<100>(T);
  test<210>(T);
  solve();
  return 0;
}