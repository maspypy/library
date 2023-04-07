#include "nt/factor.hpp"

template <typename T>
struct Function_on_Divisors {
  vc<pair<ll, int>> pf;
  vc<ll> divs;
  vc<T> dat;

  Function_on_Divisors(ll N) : Function_on_Divisors(factor(N)) {}
  Function_on_Divisors(vc<pair<ll, int>> pf) : pf(pf) {
    ll n = 1;
    for (auto&& [p, e]: pf) n *= (e + 1);
    divs.reserve(n);
    divs = {1};
    for (auto&& [p, e]: pf) {
      int n = len(divs);
      ll q = p;
      FOR(e) {
        FOR(i, n) divs.eb(divs[i] * q);
        q *= p;
      }
    }
  }

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

  // (d, fd)
  template <typename F>
  void enumerate(F f) {
    FOR(i, len(divs)) { f(divs[i], dat[i]); }
  }
};
