#include "mod/primitive_root.hpp"
#include "mod/mod_log_998244353.hpp"
#include "nt/lpf_table.hpp"
#include "ds/hashmap.hpp"

template <int p>
struct ModFast {
  static_assert(p < (1 << 30));

  u32 root;
  array<u32, 65537> POW[2];
  array<pair<u16, u16>, 1 + (1 << 20)> FRAC;

  static constexpr int K = 1 << 21;
  array<u32, 2 * K + 1> LOG;
  array<u32, 2 * K + 1> INV;

  ModFast() {
    root = (p == 998244353 ? 3 : primitive_root(p));
    build_pow();
    build_inv();
    build_log();
    build_frac();
  }

  void build_inv() {
    INV[K + 1] = 1;
    for (u32 i = 2; i <= K; ++i) {
      u64 q = (p + i - 1) / i;
      INV[K + i] = INV[K + i * q - p] * u64(q) % p;
    }
    FOR(i, 1, K + 1) INV[K - i] = p - INV[K + i];
  }

  u32 pow(u32 a, ll exp) {
    assert(0 <= a && a < p && 0 <= exp && exp < (1 << 30));
    if (a == 0) return (exp == 0 ? 1 : 0);
    return pow_r(log_r(a) * exp % (p - 1));
  }

  u32 pow_r(u32 exp) {
    assert(0 <= exp && exp <= p - 1);
    return u64(POW[0][exp & 32767]) * POW[1][exp >> 15] % p;
  }

  // [0, 2p-2)
  u32 log_r(u32 x) {
    assert(1 <= x && x < p);
    auto [a, b] = FRAC[x >> 10];
    u32 t = x * b - a * p;
    return LOG[K + t] + (p - 1) - LOG[K + b];
  }

  u32 inverse(u32 x) {
    assert(1 <= x && x < p);
    auto [a, b] = FRAC[x >> 10];
    u32 t = x * b - a * p;
    return INV[K + t] * u64(b) % p;
  }

private:
  void build_pow() {
    POW[0][0] = POW[1][0] = 1;
    FOR(i, (1 << 15)) POW[0][i + 1] = POW[0][i] * u64(root) % p;
    FOR(i, (1 << 15)) POW[1][i + 1] = POW[1][i] * u64(POW[0][1 << 15]) % p;
  }

  // 0.72sec [0.10sec if p=998]
  void build_log() {
    if (p == 998244353) return build_log_998();
    auto lpf = lpf_table(1 << 21);
    const int S = 5'000'000;
    HashMap<u32> MP(S);
    u32 pw = 1;
    for (int k = 0; k < S; ++k, pw = u64(root) * pw % p) { MP[pw] = k; }
    u32 q = pow_r(p - 1 - S);

    LOG[K + 1] = 0;
    FOR(i, 2, 1 + (1 << 21)) {
      if (lpf[i] < i) {
        LOG[K + i] = (LOG[K + lpf[i]] + LOG[K + i / lpf[i]]) % (p - 1);
        continue;
      }
      u32 s = i;
      LOG[K + i] = 0;
      while (1) {
        u32 v = MP.get(s, -1);
        if (v != u32(-1)) {
          LOG[K + i] += v;
          break;
        }
        LOG[K + i] += S, s = u64(s) * q % p;
      }
    }
    FOR(i, 1, 1 + (1 << 21)) { LOG[K - i] = (LOG[K + i] + (p - 1) / 2) % (p - 1); }
  }

  void build_log_998() {
    auto lpf = lpf_table(1 << 21);
    LOG[K + 1] = 0;
    FOR(i, 2, 1 + (1 << 21)) { LOG[K + i] = (lpf[i] < i ? (LOG[K + lpf[i]] + LOG[K + i / lpf[i]]) % (p - 1) : mod_log_998_primitive_root(i)); }
    FOR(i, 1, 1 + (1 << 21)) { LOG[K - i] = (LOG[K + i] + (p - 1) / 2) % (p - 1); }
  }

  void build_frac() {
    vc<tuple<u16, u16, u16, u16>> que;
    que.eb(0, 1, 1, 1);
    while (len(que)) {
      auto [a, b, c, d] = POP(que);
      if (b + d < 2048) {
        que.eb(a + c, b + d, c, d), que.eb(a, b, a + c, b + d);
        continue;
      }
      u32 s = (u64(a) * p) / (1024 * b);
      u32 t = (u64(c) * p) / (1024 * d);
      FRAC[s] = {a, b}, FRAC[t] = {c, d};
      a = min(a, c), b = min(b, d);
      FOR(i, s + 1, t) FRAC[i] = {a, b};
    }
  }
};
