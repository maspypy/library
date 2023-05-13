// 10^6 ずつ区切って
struct BigInteger {
  static constexpr int LOG = 6;
  static constexpr int MOD = 1000000;
  using bint = BigInteger;
  int sgn; // +1 or -1. 内部状態で -0 を許容する.
  vc<int> dat;

  BigInteger(i128 val) {
    if (val == 0) {
      sgn = 1;
    } else {
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
    array<int, LOG> pow = {1, 10, 100, 1000, 10000, 100000};
    FOR(i, n) { dat[i / LOG] += pow[i % LOG] * (s[i] - '0'); }
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
  bint &operator+=(const bint &p) {
    if (sgn != p.sgn) {
      *this -= (-p);
      return *this;
    }
    int n = max(len(dat), len(p.dat));
    dat.resize(n + 1);
    FOR(i, n) {
      dat[i] += p.dat[i];
      if (dat[i] >= MOD) dat[i] -= MOD, dat[i + 1] += 1;
    }
    while (len(dat) && dat.back() == 0) dat.pop_back();
    return *this;
  }
  bint &operator-=(const bint &p) {
    if (sgn != p.sgn) {
      *this += (-p);
      return *this;
    }
    bool small = (*this) < p;
    if ((sgn == 1 && small) || (sgn == -1 && (!small))) {
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
  // bint &operator*=(const bint &p) { return *this; }
  // bint &operator/=(const bint &p) { return *this; }
  bint operator-() const {
    bint p = *this;
    p.sgn *= -1;
    return p;
  }
  bint operator+(const bint &p) const { return bint(*this) += p; }
  bint operator-(const bint &p) const { return bint(*this) -= p; }
  // bint operator*(const modint &p) const { return modint(*this) *= p; }
  // bint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const bint &p) const {
    return (sgn == p.sgn && dat == p.dat);
  }
  bool operator!=(const bint &p) const {
    return (sgn != p.sgn || dat != p.dat);
  }
#ifdef FASTIO
  void write() { fastio::printer.write(to_string()); }
  void read() {
    string s;
    fastio::printer.write(s);
    *this = bint(s);
  }
#endif
  string to_string() {
    if (dat.empty()) return "0";
    string s;
    for (int x: dat) {
      FOR(6) {
        s += '0' + (x % 10);
        x = x / 10;
      }
    }
    while (s.back() == '0') s.pop_back();
    if (sgn == -1) s += '-';
    reverse(all(s));
    return s;
  }
};