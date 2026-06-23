#include "nt/factor.hpp"
#include "mod/mod_inv.hpp"

vc<int> Reeds_Sloane_Prime_Power(vc<int> S, int p, int e) {
  int N = len(S);
  if (N == 0) return {1};
  int M = 1;
  FOR(e) M *= p;

  using mint = Dynamic_Modint<20260623>;
  mint::set_mod(M);

  auto decompose = [&](mint x) -> pair<mint, int> {
    // x = tp^u
    int t = x.val, u = 0;
    if (t == 0) return {1, e};
    while (t % p == 0) t /= p, ++u;
    return {t, u};
  };

  using poly = vc<mint>;
  vc<poly> Q(e);
  vc<int> L(e);

  vc<poly> B(e);
  vc<int> LB(e);
  vc<int> nB(e);
  vc<mint> tB(e);

  mint pw = 1;
  for (int i = 0; i < e; ++i, pw *= p) {
    Q[i] = {pw};
    L[i] = 0;
    nB[i] = -1;
  }

  for (int n = 0; n < N; ++n) {
    // delta=tp^u
    vc<mint> t(e);
    vc<int> u(e);
    FOR(i, e) {
      mint delta = 0;
      assert(len(Q[i]) <= 1 + n);
      FOR(k, len(Q[i])) delta += Q[i][k] * S[n - k];
      tie(t[i], u[i]) = decompose(delta);
    }

    vc<poly> Q_next = Q;
    vc<int> L_next = L;

    FOR(i, e) {
      if (u[i] == e) continue;

      int j = e - 1 - u[i];
      if (nB[j] == -1) {
        Q_next[i].resize(n + 2);
        L_next[i] = n + 1;
      } else {
        L_next[i] = max(L[i], LB[j] + n - nB[j]);
        Q_next[i].resize(L_next[i] + 1);
        mint c = t[i] / tB[j];
        FOR(k, len(B[j])) Q_next[i][k + n - nB[j]] -= c * B[j][k];
      }
    }
    FOR(i, e) {
      if (L[i] < L_next[i]) {
        int j = e - 1 - u[i];
        B[i] = Q[j];
        LB[i] = L[j];
        nB[i] = n;
        tB[i] = t[j];
      }
    }
    swap(Q, Q_next);
    swap(L, L_next);
  }
  vc<int> res;
  for (auto& x : Q[0]) res.eb(x.val);
  assert(len(res) == L[0] + 1);
  return res;
}

/*
return {P(x),Q(x)} such that
S(x)=P(x)/Q(x) mod x^N, [x^0]Q=1
minimize L=max(deg(P)+1,deg(Q))
*/
template <typename mint>
pair<vc<mint>, vc<mint>> Reeds_Sloane(vc<mint> S, vc<pair<ll, int>> pfs = {}) {
  int mod = mint::get_mod();
  if (mod > 1 && pfs.empty()) {
    pfs = factor(mod);
  }
  {
    int check = mod;
    for (auto [p, e] : pfs) {
      FOR(e) {
        assert(check % p == 0);
        check /= p;
      }
    }
    assert(check == 1);
  }

  if (mod == 1) return {{}, {1}};

  int n = len(pfs);
  vi coef(n);
  FOR(i, n) {
    auto [p, e] = pfs[i];
    int a = 1, b = mod;
    FOR(e) a *= p, b /= p;
    ll c = mod_inv(b, a);
    coef[i] = c * b % mod;
  }
  vc<mint> Q;
  FOR(k, n) {
    auto [p, e] = pfs[k];
    int a = 1;
    FOR(e) a *= p;
    vc<int> T(len(S));
    FOR(i, len(S)) T[i] = (S[i].val) % a;
    auto Qk = Reeds_Sloane_Prime_Power(T, p, e);
    if (len(Q) < len(Qk)) Q.resize(len(Qk));
    FOR(i, len(Qk)) Q[i] += Qk[i] * coef[k];
  }
  vc<mint> P(len(Q) - 1);
  FOR(i, len(P)) FOR(j, i + 1) P[i] += Q[j] * S[i - j];
  return {P, Q};
}
