#include "mod/modint.hpp"
#include "mod/primitive_root.hpp"
#include "nt/spf_table.hpp"
#include "ds/hashmap.hpp"

// prime modint
template <typename mint>
struct ModFast {
  static constexpr int LIM = 1 << 21;
  static constexpr int p = mint::get_mod();
  static_assert(2 <= p && p < (1 << 30));

  // small mod では全非零元を直接 table 化する
  static constexpr bool DIRECT = (p <= LIM);
  static constexpr int K = (DIRECT ? p - 1 : LIM);

  static constexpr int TABLE_SIZE = (DIRECT ? p : 2 * K + 1);
  static constexpr int FRAC_SIZE = (DIRECT ? 1 : 1 + (1 << 20));

  u32 root;
  array<u32, 32769> POW[2];
  array<pair<u16, u16>, FRAC_SIZE> FRAC;

  array<u32, TABLE_SIZE> LOG;
  array<u32, TABLE_SIZE> INV;

  ModFast() {
    root = (p == 998244353 ? 3 : primitive_root(p));
    build_pow();
    build_inv();
    build_log();
    if constexpr (!DIRECT) build_frac();
  }

  // a^exp
  // a != 0 なら exp は任意の signed ll.
  // a == 0 の場合は exp >= 0 が必要.
  mint pow(mint a, ll exp) const {
    if (a == 0) {
      assert(exp >= 0);
      return mint::raw(exp == 0);
    }

    u32 lg = log_r(a);

    // lg < 2^31 なので積は u64 に収まる.
    if (u64(exp) < (1ULL << 33)) {
      u32 e = u64(lg) * u64(exp) % (p - 1);
      return pow_r_32(e);
    }

    ll e = exp % (p - 1);
    if (e < 0) e += p - 1;
    u32 f = u64(lg) * u64(e) % (p - 1);
    return pow_r_32(f);
  }

  // primitive root^exp
  mint pow_r(ll exp) const {
    exp %= p - 1;
    if (exp < 0) exp += p - 1;
    return pow_r_32(exp);
  }

  // 0 <= exp <= p-1
  mint pow_r_32(u32 exp) const {
    assert(exp <= p - 1);
    return mint::raw(u64(POW[0][exp & 32767]) * POW[1][exp >> 15] % p);
  }

  // x = root^e に対する離散対数.
  // 返り値は [0, 2p-2).
  u32 log_r(mint x) const {
    assert(x != 0);

    if constexpr (DIRECT) {
      return LOG[x.val];
    } else {
      auto [a, b] = FRAC[x.val >> 10];

      // xb-ap を u32 wrap で表現する.
      u32 t = x.val * u32(b) - u32(a) * u32(p);
      return LOG[K + t] + (p - 1) - LOG[K + b];
    }
  }

  mint inverse(mint x) const {
    assert(x != 0);

    if constexpr (DIRECT) {
      return mint::raw(INV[x.val]);
    } else {
      auto [a, b] = FRAC[x.val >> 10];

      // xb-ap を u32 wrap で表現する.
      u32 t = x.val * u32(b) - u32(a) * u32(p);
      return mint::raw(INV[K + t] * u64(b) % p);
    }
  }

  // res[x] = log_r(x), res[0] = 0 (dummy)
  vc<u32> get_log_table(int n) const {
    assert(0 <= n && n <= K);

    if constexpr (DIRECT) {
      return {LOG.begin(), LOG.begin() + n + 1};
    } else {
      return {LOG.begin() + K, LOG.begin() + K + n + 1};
    }
  }

 private:
  void build_inv() {
    if constexpr (DIRECT) {
      INV[0] = 0;
      INV[1] = 1;

      for (u32 i = 2; i < u32(p); ++i) {
        u64 q = (p + i - 1) / i;
        u32 t = i * q - p;
        INV[i] = INV[t] * q % p;
      }
    } else {
      INV[K] = 0;
      INV[K + 1] = 1;

      for (u32 i = 2; i <= K; ++i) {
        u64 q = (p + i - 1) / i;
        INV[K + i] = INV[K + i * q - p] * q % p;
      }

      FOR(i, 1, K + 1) { INV[K - i] = p - INV[K + i]; }
    }
  }

  void build_pow() {
    POW[0][0] = POW[1][0] = 1;

    FOR(i, (1 << 15)) { POW[0][i + 1] = POW[0][i] * u64(root) % p; }
    FOR(i, (1 << 15)) { POW[1][i + 1] = POW[1][i] * u64(POW[0][1 << 15]) % p; }
  }

  void build_log() {
    if constexpr (DIRECT) {
      LOG[0] = 0;

      u32 x = 1;
      FOR(e, p - 1) {
        LOG[x] = e;
        x = u64(x) * root % p;
      }

      return;
    }

    auto spf = spf_table(K);

    const int S = 1 << 17;
    HashMap<u32> MP(S);

    u32 pw = 1;
    for (int k = 0; k < S; ++k, pw = u64(root) * pw % p) {
      MP[pw] = k;
    }

    u32 q = pow_r_32(p - 1 - S).val;

    auto BSGS = [&](u32 s) -> u32 {
      u32 ans = 0;
      while (1) {
        u32 v = MP.get(s, -1);
        if (v != u32(-1)) return ans + v;
        ans += S;
        s = u64(s) * q % p;
      }
      return 0;
    };

    LOG[K] = 0;
    LOG[K + 1] = 0;

    FOR(i, 2, K + 1) {
      if (spf[i] < i) {
        LOG[K + i] = (LOG[K + spf[i]] + LOG[K + i / spf[i]]) % (p - 1);
        continue;
      }

      if (i < 100) {
        LOG[K + i] = BSGS(i);
        continue;
      }

      if (i * i > p) {
        auto [j, k] = divmod<int>(p, i);
        // i = (-k)/j
        LOG[K + i] =
            (LOG[K + k] + (p - 1) / 2 + (p - 1) - LOG[K + j]) % (p - 1);
        continue;
      }

      while (1) {
        u32 k = RNG(0, p - 1);
        u64 ans = p - 1 - k;
        u32 x = u64(i) * pow_r_32(k).val % p;

        auto div = [&](u32 q) -> void {
          x /= q;
          ans += LOG[K + q];
        };

        for (u32 q : {2, 3, 5, 7, 11, 13, 17, 19}) {
          while (x % q == 0) div(q);
        }

        if (x >= K) continue;

        while (i < x && x < K && spf[x] < i) {
          div(spf[x]);
        }
        if (1 < x && x < i) div(x);

        if (x == 1) {
          LOG[K + i] = ans % (p - 1);
          break;
        }
      }
    }

    FOR(i, 1, K + 1) { LOG[K - i] = (LOG[K + i] + (p - 1) / 2) % (p - 1); }
  }

  void build_frac() {
    static_assert(!DIRECT);

    vc<tuple<u16, u16, u16, u16>> que;
    que.eb(0, 1, 1, 1);

    while (len(que)) {
      auto [a, b, c, d] = POP(que);

      if (b + d < 2048) {
        que.eb(a + c, b + d, c, d);
        que.eb(a, b, a + c, b + d);
        continue;
      }

      u32 s = (u64(a) * p) / (1024 * b);
      u32 t = (u64(c) * p) / (1024 * d);

      FRAC[s] = {a, b};
      FRAC[t] = {c, d};

      a = min(a, c);
      b = min(b, d);
      FOR(i, s + 1, t) FRAC[i] = {a, b};
    }
  }
};