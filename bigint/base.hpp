#include "poly/convolution.hpp"

// 10^9 ずつ区切って
struct BigInteger {
  static constexpr int TEN[]
      = {1,      10,      100,      1000,      10000,
         100000, 1000000, 10000000, 100000000, 1000000000};
  static constexpr int LOG = 9;
  static constexpr int MOD = TEN[LOG];
  using bint = BigInteger;
  int sgn; // +1 or -1. 内部状態で -0 を許容する.
  vc<int> dat;

  BigInteger() : sgn(1) {}
  BigInteger(i128 val) {
    sgn = 1;
    if (val != 0) {
      if (val < 0) sgn = -1, val = -val;
      while (val > 0) {
        dat.eb(val % MOD);
        val /= MOD;
      }
    }
  }
  BigInteger(string s) {
    assert(!s.empty());
    sgn = 1;
    if (s[0] == '-') {
      sgn = -1;
      s.erase(s.begin());
      assert(!s.empty());
    }
    if (s[0] == '0') s.clear();
    reverse(all(s));
    int n = len(s);
    int m = ceil(n, LOG);
    dat.assign(m, 0);
    FOR(i, n) { dat[i / LOG] += TEN[i % LOG] * (s[i] - '0'); }
  }
  bint &operator=(const bint &p) {
    sgn = p.sgn;
    dat = p.dat;
    return *this;
  }
  bool operator<(const bint &p) const {
    if (sgn != p.sgn) return sgn < p.sgn;
    if (len(dat) != len(p.dat)) {
      if (sgn == 1) return len(dat) < len(p.dat);
      if (sgn == -1) return len(dat) > len(p.dat);
    }
    FOR_R(i, len(dat)) {
      if (dat[i] == p.dat[i]) continue;
      if (sgn == 1) return dat[i] < p.dat[i];
      if (sgn == -1) return dat[i] > p.dat[i];
    }
    return false;
  }
  bool operator>(const bint &p) const { return p < *this; }
  bool operator<=(const bint &p) const { return !(*this > p); }
  bool operator>=(const bint &p) const { return !(*this < p); }
  bint &operator+=(const bint p) {
    if (sgn != p.sgn) {
      *this -= (-p);
      return *this;
    }
    int n = max(len(dat), len(p.dat));
    dat.resize(n + 1);
    FOR(i, n) {
      if (i < len(p.dat)) dat[i] += p.dat[i];
      if (dat[i] >= MOD) dat[i] -= MOD, dat[i + 1] += 1;
    }
    while (len(dat) && dat.back() == 0) dat.pop_back();
    return *this;
  }
  bint &operator-=(const bint p) {
    if (sgn != p.sgn) {
      *this += (-p);
      return *this;
    }
    if ((sgn == 1 && *this < p) || (sgn == -1 && *this > p)) {
      *this = p - *this;
      sgn = -sgn;
      return *this;
    }
    FOR(i, len(p.dat)) { dat[i] -= p.dat[i]; }
    FOR(i, len(dat) - 1) {
      if (dat[i] < 0) dat[i] += MOD, dat[i + 1] -= 1;
    }
    while (len(dat) && dat.back() == 0) { dat.pop_back(); }
    return *this;
  }
  bint &operator*=(const bint &p) {
    sgn *= p.sgn;
    dat = convolve(dat, p.dat);
    return *this;
  }
  // bint &operator/=(const bint &p) { return *this; }
  bint operator-() const {
    bint p = *this;
    p.sgn *= -1;
    return p;
  }
  bint operator+(const bint &p) const { return bint(*this) += p; }
  bint operator-(const bint &p) const { return bint(*this) -= p; }
  bint operator*(const bint &p) const { return bint(*this) *= p; }
  // bint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const bint &p) const {
    return (sgn == p.sgn && dat == p.dat);
  }
  bool operator!=(const bint &p) const {
    return (sgn != p.sgn || dat != p.dat);
  }

  vc<int> convolve(const vc<int> &a, const vc<int> &b) {
    int n = len(a), m = len(b);
    if (!n || !m) return {};
    if (min(n, m) <= 500) {
      vc<int> c(n + m - 1);
      u128 x = 0;
      FOR(k, n + m - 1) {
        int s = max<int>(0, k + 1 - m), t = min<int>(k, n - 1);
        FOR(i, s, t + 1) { x += u64(a[i]) * b[k - i]; }
        c[k] = x % MOD, x = x / MOD;
      }
      while (x > 0) { c.eb(x % MOD), x = x / MOD; }
      return c;
    }
    static constexpr int p0 = 167772161;
    static constexpr int p1 = 469762049;
    static constexpr int p2 = 754974721;
    using mint0 = modint<p0>;
    using mint1 = modint<p1>;
    using mint2 = modint<p2>;
    vc<mint0> a0(all(a)), b0(all(b));
    vc<mint1> a1(all(a)), b1(all(b));
    vc<mint2> a2(all(a)), b2(all(b));
    auto c0 = convolution_ntt<mint0>(a0, b0);
    auto c1 = convolution_ntt<mint1>(a1, b1);
    auto c2 = convolution_ntt<mint2>(a2, b2);
    vc<int> c(len(c0));
    u128 x = 0;
    FOR(i, n + m - 1) {
      x += CRT3<u128, p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);
      c[i] = x % MOD, x = x / MOD;
    }
    while (x) { c.eb(x % MOD), x = x / MOD; }
    return c;
  }

  string to_string() {
    if (dat.empty()) return "0";
    string s;
    for (int x: dat) {
      FOR(LOG) {
        s += '0' + (x % 10);
        x = x / 10;
      }
    }
    while (s.back() == '0') s.pop_back();
    if (sgn == -1) s += '-';
    reverse(all(s));
    return s;
  }

  // https://codeforces.com/contest/504/problem/D
  string to_binary_string() {
    vc<u32> A(all(dat));
    string ANS;
    while (1) {
      while (len(A) && A.back() == u32(0)) POP(A);
      if (A.empty()) break;
      u64 rem = 0;
      FOR_R(i, len(A)) {
        rem = rem * MOD + A[i];
        A[i] = rem >> 32;
        rem &= u32(-1);
      }
      FOR(i, 32) { ANS += '0' + (rem >> i & 1); }
    }
    while (len(ANS) && ANS.back() == '0') ANS.pop_back();
    reverse(all(ANS));
    if (ANS.empty()) ANS += '0';
    return ANS;
  }

  // https://codeforces.com/contest/759/problem/E
  pair<bint, int> divmod(int p) {
    assert(dat.empty() || sgn == 1);
    vc<int> after;
    ll rm = 0;
    FOR_R(i, len(dat)) {
      rm = rm * MOD + dat[i];
      after.eb(rm / p);
      rm = rm % p;
    }
    reverse(all(after));
    while (len(after) && after.back() == 0) POP(after);
    bint q;
    q.sgn = 1;
    q.dat = after;
    return {q, rm};
  }

  // https://codeforces.com/problemset/problem/582/D
  vc<int> base_p_representation(int p) {
    vc<u32> A(all(dat));
    vc<int> res;
    while (1) {
      while (len(A) && A.back() == u32(0)) POP(A);
      if (A.empty()) break;
      u64 rm = 0;
      FOR_R(i, len(A)) {
        rm = rm * MOD + A[i];
        A[i] = rm / p;
        rm %= p;
      }
      res.eb(rm);
    }
    reverse(all(res));
    return res;
  }

  // overflow 無視して計算
  ll to_ll() {
    ll x = 0;
    FOR_R(i, len(dat)) x = MOD * x + dat[i];
    return sgn * x;
  }

  // https://codeforces.com/contest/986/problem/D
  bint pow(ll n) {
    auto dfs = [&](auto &dfs, ll n) -> bint {
      if (n == 1) return (*this);
      bint x = dfs(dfs, n / 2);
      x *= x;
      if (n & 1) x *= (*this);
      return x;
    };
    if (n == 0) return bint(1);
    return dfs(dfs, n);
  }

  // https://codeforces.com/contest/986/problem/D
  double log10() {
    assert(!dat.empty() && sgn == 1);
    if (len(dat) <= 3) {
      double x = 0;
      FOR_R(i, len(dat)) x = MOD * x + dat[i];
      return std::log10(x);
    }
    double x = 0;
    FOR(i, 4) x = MOD * x + dat[len(dat) - 1 - i];
    x = std::log10(x);
    x += double(LOG) * (len(dat) - 4);
    return x;
  }

#ifdef FASTIO
  void write() { fastio::printer.write(to_string()); }
  void read() {
    string s;
    fastio::scanner.read(s);
    *this = bint(s);
  }
#endif
};