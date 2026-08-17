#include "other/bit.hpp"
#include "nt/factor.hpp"
#include "mod/mod_inv.hpp"
#include "mod/dynamic_modint.hpp"

template <bool EVEN>
vc<u32> reeds_sloane_prime_power(vc<u32> S, int p, int e) {
  using T = std::conditional_t<EVEN, u32, Dynamic_Modint<20260623>>;
  u32 M = 1;
  FOR(e) M *= p;
  if constexpr (EVEN) {
    assert(p == 2);
  } else {
    assert(p != 2);
    T::set_mod(M);
  }
  int N = len(S);
  if (N == 0) return {1};

  auto decompose = [&](T x) -> pair<T, int> {
    if constexpr (EVEN) {
      int k = lowbit(x);
      if (k == -1 || k >= e) return {1, e};
      return {x >> k, k};
    } else {
      // x = tp^u
      int t = x.val, u = 0;
      if (t == 0) return {1, e};
      while (t % p == 0) t /= p, ++u;
      return {t, u};
    }
  };
  auto inv = [&](T a) -> T {
    if constexpr (EVEN) {
      T x = 1;
      x = x * (2U - a * x);
      x = x * (2U - a * x);
      x = x * (2U - a * x);
      x = x * (2U - a * x);
      x = x * (2U - a * x);
      return x;
    } else {
      return a.pow(M - M / p - 1);
    }
  };

  using poly = vc<T>;
  vc<poly> Q(e);
  vc<int> L(e);

  vc<poly> B(e);
  vc<int> LB(e);
  vc<int> nB(e);
  vc<T> tB(e);

  T pw = 1;
  for (int j = 0; j < e; ++j, pw *= p) {
    Q[j] = {pw};
    L[j] = 0;
    nB[j] = -1;
  }

  for (int n = 0; n < N; ++n) {
    // delta=tp^u
    vc<T> t(e);
    vc<int> u(e);
    FOR(j, e) {
      T delta = 0;
      assert(len(Q[j]) <= 1 + n);
      FOR(k, len(Q[j])) delta += Q[j][k] * S[n - k];
      tie(t[j], u[j]) = decompose(delta);
    }

    vc<poly> Q_next = Q;
    vc<int> L_next = L;

    FOR(j, e) {
      if (u[j] == e) continue;

      int k = e - 1 - u[j];
      if (nB[k] == -1) {
        Q_next[j].resize(n + 2);
        L_next[j] = n + 1;
      } else {
        L_next[j] = max(L[j], LB[k] + n - nB[k]);
        Q_next[j].resize(L_next[j] + 1);
        T c = t[j] * inv(tB[k]);
        FOR(i, len(B[k])) Q_next[j][i + n - nB[k]] -= c * B[k][i];
      }
    }
    FOR(j, e) {
      if (L[j] < L_next[j]) {
        int k = e - 1 - u[j];
        B[j] = Q[k];
        LB[j] = L[k];
        nB[j] = n;
        tB[j] = t[k];
      }
    }
    swap(Q, Q_next), swap(L, L_next);
  }
  if constexpr (EVEN) {
    return Q[0];
  } else {
    vc<u32> res;
    for (auto& x : Q[0]) res.eb(x.val);
    assert(len(res) == L[0] + 1);
    return res;
  }
}

/*
return {P(x),Q(x)} such that
S(x)=P(x)/Q(x) mod x^N, [x^0]Q=1
minimize L=max(deg(P)+1,deg(Q))
*/
template <typename mint>
pair<vc<mint>, vc<mint>> reeds_sloane(vc<mint> S, vc<pair<ll, int>> pfs = {}) {
  u32 mod = mint::get_mod();
  if (mod > 1 && pfs.empty()) {
    pfs = factor(mod);
  }
  {
    u32 check = mod;
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
    vc<u32> T(len(S));
    FOR(i, len(S)) T[i] = (S[i].val) % a;
    auto Qk = (p == 2 ? reeds_sloane_prime_power<1>(T, p, e)
                      : reeds_sloane_prime_power<0>(T, p, e));
    if (len(Q) < len(Qk)) Q.resize(len(Qk));
    FOR(i, len(Qk)) Q[i] += ll(Qk[i]) * coef[k];
  }
  vc<mint> P(len(Q) - 1);
  FOR(i, len(P)) FOR(j, i + 1) P[i] += Q[j] * S[i - j];
  return {P, Q};
}
