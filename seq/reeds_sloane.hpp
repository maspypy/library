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
  struct Cur {
    int L;
    poly Q;
  };
  struct Old {
    int L, r;
    poly Q;
    mint theta;
  };

  vc<int> pw(e + 1);
  pw[0] = 1;
  FOR(i, e) pw[i + 1] = pw[i] * p;
  vc<Cur> cur(e);
  vc<Old> old(e);
  FOR(i, e) {
    cur[i].L = 0, cur[i].Q = {pw[i]};
    old[i].r = -1;
  }

  vc<mint> theta(e);
  vc<int> u(e);
  FOR(n, N) {
    FOR(i, e) {
      mint delta = 0;
      assert(len(cur[i].Q) <= 1 + n);
      FOR(k, len(cur[i].Q)) delta += cur[i].Q[k] * S[n - k];
      tie(theta[i], u[i]) = decompose(delta);
    }

    vc<Cur> nxt = cur;
    FOR(i, e) {
      if (u[i] == e) continue;
      int j = e - 1 - u[i];
      if (old[j].r == -1) {
        poly Q = cur[i].Q;
        Q.resize(n + 2);
        nxt[i] = Cur{int(n) + 1, Q};
      } else {
        poly Q = cur[i].Q;
        int Lnxt = max<int>(cur[i].L, old[j].L + n - old[j].r);
        Q.resize(Lnxt + 1);
        mint c = theta[i] / old[j].theta;
        FOR(k, len(old[j].Q)) Q[k + n - old[j].r] -= c * old[j].Q[k];
        nxt[i] = Cur{Lnxt, Q};
      }
    }
    FOR(i, e) {
      if (cur[i].L < nxt[i].L) {
        int j = e - 1 - u[i];
        old[i].Q = cur[j].Q;
        old[i].L = cur[j].L;
        old[i].r = n;
        old[i].theta = theta[j];
      }
    }
    swap(cur, nxt);
  }
  vc<int> res;
  for (auto& x : cur[0].Q) res.eb(x.val);
  assert(len(res) == cur[0].L + 1);
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
