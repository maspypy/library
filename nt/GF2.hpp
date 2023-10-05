#include <emmintrin.h>
#include <smmintrin.h>
#include <wmmintrin.h>

__attribute__((target("pclmul"))) inline __m128i myclmul(const __m128i &a,
                                                         const __m128i &b) {
  return _mm_clmulepi64_si128(a, b, 0);
}

// 2^n 元体
template <int K>
struct GF2 {
  // https://oeis.org/A344141
  // irreducible poly x^K + ...
  static constexpr int POLY[65]
      = {0,  0, 3,  3,   3,  5,   3,  3,  27,  3,  9,  5,   9, 27, 33, 3,   43,
         9,  9, 39, 9,   5,  3,   33, 27, 9,   27, 39, 3,   5, 3,  9,  141, 75,
         27, 5, 53, 63,  99, 17,  57, 9,  39,  89, 33, 27,  3, 33, 45, 113, 29,
         75, 9, 71, 125, 71, 149, 17, 99, 123, 3,  39, 105, 3, 27};

  static constexpr u64 mask() { return u64(-1) >> (64 - K); }

  __attribute__((target("sse4.2"))) static u64 mul(u64 a, u64 b) {
    static bool prepared = 0;
    static u64 MEMO[8][65536];
    if (!prepared) {
      prepared = 1;
      vc<u64> tmp(128);
      tmp[0] = 1;
      FOR(i, 127) {
        tmp[i + 1] = tmp[i] << 1;
        if (tmp[i] >> (K - 1) & 1) {
          tmp[i + 1] ^= POLY[K];
          tmp[i + 1] &= mask();
        }
      }
      FOR(k, 8) {
        MEMO[k][0] = 0;
        FOR(i, 16) {
          FOR(s, 1 << i) { MEMO[k][s | 1 << i] = MEMO[k][s] ^ tmp[16 * k + i]; }
        }
      }
    }
    const __m128i a_ = _mm_set_epi64x(0, a);
    const __m128i b_ = _mm_set_epi64x(0, b);
    const __m128i c_ = myclmul(a_, b_);
    u64 lo = _mm_extract_epi64(c_, 0);
    u64 hi = _mm_extract_epi64(c_, 1);
    u64 x = 0;
    x ^= MEMO[0][lo & 65535];
    x ^= MEMO[1][(lo >> 16) & 65535];
    x ^= MEMO[2][(lo >> 32) & 65535];
    x ^= MEMO[3][(lo >> 48) & 65535];
    x ^= MEMO[4][hi & 65535];
    x ^= MEMO[5][(hi >> 16) & 65535];
    x ^= MEMO[6][(hi >> 32) & 65535];
    x ^= MEMO[7][(hi >> 48) & 65535];
    return x;
  }

  u64 val;
  constexpr GF2(const u64 val = 0) noexcept : val(val & mask()) {}
  bool operator<(const GF2 &other) const {
    return val < other.val;
  } // To use std::map
  GF2 &operator+=(const GF2 &p) {
    val ^= p.val;
    return *this;
  }
  GF2 &operator-=(const GF2 &p) {
    val ^= p.val;
    return *this;
  }
  GF2 &operator*=(const GF2 &p) {
    val = mul(val, p.val);
    return *this;
  }

  GF2 &operator/=(const GF2 &p) {
    *this *= p.inverse();
    return *this;
  }
  GF2 operator-() const { return GF2(-val); }
  GF2 operator+(const GF2 &p) const { return GF2(*this) += p; }
  GF2 operator-(const GF2 &p) const { return GF2(*this) -= p; }
  GF2 operator*(const GF2 &p) const { return GF2(*this) *= p; }
  GF2 operator/(const GF2 &p) const { return GF2(*this) /= p; }
  bool operator==(const GF2 &p) const { return val == p.val; }
  bool operator!=(const GF2 &p) const { return val != p.val; }
  GF2 inverse() const { return pow((u64(1) << K) - 2); }
  GF2 pow(u64 n) const {
    GF2 ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
};
