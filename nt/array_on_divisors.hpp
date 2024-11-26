#include "nt/factor.hpp"
#include "ds/hashmap.hpp"

template <typename T>
struct Array_On_Divisors {
  vc<pair<ll, int>> pf;
  vc<ll> divs;
  vc<T> dat;
  HashMap<int> MP;

  Array_On_Divisors(ll N = 1) { build(N); }
  Array_On_Divisors(vc<pair<ll, int>> pf) { build(pf); }

  void build(ll N) { build(factor(N)); }
  void build(vc<pair<ll, int>> pfs) {
    if (!pf.empty() && pf == pfs) return;
    pf = pfs;
    ll n = 1;
    for (auto&& [p, e]: pf) n *= (e + 1);
    divs.assign(n, 1);
    dat.assign(n, T{});
    int nxt = 1;
    for (auto&& [p, e]: pf) {
      int L = nxt;
      ll q = p;
      FOR(e) {
        FOR(i, L) { divs[nxt++] = divs[i] * q; }
        q *= p;
      }
    }
    MP.build(n);
    FOR(i, n) MP[divs[i]] = i;
  }

  T& operator[](ll d) { return dat[MP[d]]; }

  // f(p, k) を与える → 乗法的に拡張
  template <typename F>
  void set_multiplicative(F f) {
    dat.reserve(len(divs));
    dat = {T(1)};
    for (auto&& [p, e]: pf) {
      int n = len(divs);
      FOR(k, 1, e + 1) { FOR(i, n) dat.eb(dat[i] * f(p, k)); }
    }
  }

  void set_euler_phi() {
    dat.resize(len(divs));
    FOR(i, len(divs)) dat[i] = T(divs[i]);
    divisor_mobius();
  }

  void set_mobius() {
    set_multiplicative([&](ll p, int k) -> T {
      if (k >= 2) return T(0);
      return (k == 1 ? T(-1) : T(0));
    });
  }

  void multiplier_zeta() {
    ll k = 1;
    for (auto&& [p, e]: pf) {
      ll mod = k * (e + 1);
      FOR(i, len(divs) / mod) {
        FOR_R(j, mod - k) { dat[mod * i + j] += dat[mod * i + j + k]; }
      }
      k *= (e + 1);
    }
  }

  void multiplier_mobius() {
    ll k = 1;
    for (auto&& [p, e]: pf) {
      ll mod = k * (e + 1);
      FOR(i, len(divs) / mod) {
        FOR(j, mod - k) { dat[mod * i + j] -= dat[mod * i + j + k]; }
      }
      k *= (e + 1);
    }
  }

  void divisor_zeta() {
    ll k = 1;
    for (auto&& [p, e]: pf) {
      ll mod = k * (e + 1);
      FOR(i, len(divs) / mod) {
        FOR(j, mod - k) { dat[mod * i + j + k] += dat[mod * i + j]; }
      }
      k *= (e + 1);
    }
  }

  void divisor_mobius() {
    ll k = 1;
    for (auto&& [p, e]: pf) {
      ll mod = k * (e + 1);
      FOR(i, len(divs) / mod) {
        FOR_R(j, mod - k) { dat[mod * i + j + k] -= dat[mod * i + j]; }
      }
      k *= (e + 1);
    }
  }

  // (Ta,Tb)->T : a-b
  template <typename F>
  void divisor_mobius(F SUB) {
    ll k = 1;
    for (auto&& [p, e]: pf) {
      ll mod = k * (e + 1);
      FOR(i, len(divs) / mod) {
        FOR_R(j, mod - k) { dat[mod * i + j + k] = SUB(dat[mod * i + j + k], dat[mod * i + j]); }
      }
      k *= (e + 1);
    }
  }

  // ADD(Ta,Tb)->T : a+b
  template <typename F>
  void multiplier_zeta(F ADD) {
    ll k = 1;
    for (auto&& [p, e]: pf) {
      ll mod = k * (e + 1);
      FOR(i, len(divs) / mod) {
        FOR_R(j, mod - k) { dat[mod * i + j] = ADD(dat[mod * i + j], dat[mod * i + j + k]); }
      }
      k *= (e + 1);
    }
  }

  // SUB(Ta,Tb)->T : a-=b
  template <typename F>
  void multiplier_mobius(F SUB) {
    ll k = 1;
    for (auto&& [p, e]: pf) {
      ll mod = k * (e + 1);
      FOR(i, len(divs) / mod) {
        FOR(j, mod - k) { dat[mod * i + j] = SUB(dat[mod * i + j], dat[mod * i + j + k]); }
      }
      k *= (e + 1);
    }
  }

  // ADD(T&a,Tb)->void : a+=b
  template <typename F>
  void divisor_zeta(F ADD) {
    ll k = 1;
    for (auto&& [p, e]: pf) {
      ll mod = k * (e + 1);
      FOR(i, len(divs) / mod) {
        FOR(j, mod - k) { dat[mod * i + j + k] = ADD(dat[mod * i + j + k], dat[mod * i + j]); }
      }
      k *= (e + 1);
    }
  }

  template <typename F>
  void set(F f) {
    FOR(i, len(divs)) { dat[i] = f(divs[i]); }
  }

  // (d, fd)
  // &fd で受け取れば代入とかもできます
  template <typename F>
  void enumerate(F f) {
    FOR(i, len(divs)) { f(divs[i], dat[i]); }
  }
};
