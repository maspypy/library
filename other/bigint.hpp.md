---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bigint.hpp\"\n// 10^6 \u305A\u3064\u533A\u5207\u3063\
    \u3066\nstruct BigInteger {\n  static constexpr int LOG = 6;\n  static constexpr\
    \ int MOD = 1000000;\n  using bint = BigInteger;\n  int sgn; // +1 or -1. \u5185\
    \u90E8\u72B6\u614B\u3067 -0 \u3092\u8A31\u5BB9\u3059\u308B.\n  vc<int> dat;\n\n\
    \  BigInteger(i128 val) {\n    if (val == 0) {\n      sgn = 1;\n    } else {\n\
    \      if (val < 0) sgn = -1, val = -val;\n      while (val > 0) {\n        dat.eb(val\
    \ % MOD);\n        val /= MOD;\n      }\n    }\n  }\n  BigInteger(string s) {\n\
    \    assert(!s.empty());\n    sgn = 1;\n    if (s[0] == '-') {\n      sgn = -1;\n\
    \      s.erase(s.begin());\n      assert(!s.empty());\n    }\n    if (s[0] ==\
    \ '0') s.clear();\n    reverse(all(s));\n    int n = len(s);\n    int m = ceil(n,\
    \ LOG);\n    dat.assign(m, 0);\n    array<int, LOG> pow = {1, 10, 100, 1000, 10000,\
    \ 100000};\n    FOR(i, n) { dat[i / LOG] += pow[i % LOG] * (s[i] - '0'); }\n \
    \ }\n  bint &operator=(const bint &p) {\n    sgn = p.sgn;\n    dat = p.dat;\n\
    \    return *this;\n  }\n  bool operator<(const bint &p) const {\n    if (sgn\
    \ != p.sgn) return sgn < p.sgn;\n    if (len(dat) != len(p.dat)) {\n      if (sgn\
    \ == 1) return len(dat) < len(p.dat);\n      if (sgn == -1) return len(dat) >\
    \ len(p.dat);\n    }\n    FOR_R(i, len(dat)) {\n      if (dat[i] == p.dat[i])\
    \ continue;\n      if (sgn == 1) return dat[i] < p.dat[i];\n      if (sgn == -1)\
    \ return dat[i] > p.dat[i];\n    }\n    return false;\n  }\n  bool operator>(const\
    \ bint &p) const { return p < *this; }\n  bool operator<=(const bint &p) const\
    \ { return !(*this > p); }\n  bool operator>=(const bint &p) const { return !(*this\
    \ < p); }\n  bint &operator+=(const bint &p) {\n    if (sgn != p.sgn) {\n    \
    \  *this -= (-p);\n      return *this;\n    }\n    int n = max(len(dat), len(p.dat));\n\
    \    dat.resize(n + 1);\n    FOR(i, n) {\n      dat[i] += p.dat[i];\n      if\
    \ (dat[i] >= MOD) dat[i] -= MOD, dat[i + 1] += 1;\n    }\n    while (len(dat)\
    \ && dat.back() == 0) dat.pop_back();\n    return *this;\n  }\n  bint &operator-=(const\
    \ bint &p) {\n    if (sgn != p.sgn) {\n      *this += (-p);\n      return *this;\n\
    \    }\n    bool small = (*this) < p;\n    if ((sgn == 1 && small) || (sgn ==\
    \ -1 && (!small))) {\n      *this = p - *this;\n      sgn = -sgn;\n      return\
    \ *this;\n    }\n    FOR(i, len(p.dat)) { dat[i] -= p.dat[i]; }\n    FOR(i, len(dat)\
    \ - 1) {\n      if (dat[i] < 0) dat[i] += MOD, dat[i + 1] -= 1;\n    }\n    while\
    \ (len(dat) && dat.back() == 0) { dat.pop_back(); }\n    return *this;\n  }\n\
    \  // bint &operator*=(const bint &p) { return *this; }\n  // bint &operator/=(const\
    \ bint &p) { return *this; }\n  bint operator-() const {\n    bint p = *this;\n\
    \    p.sgn *= -1;\n    return p;\n  }\n  bint operator+(const bint &p) const {\
    \ return bint(*this) += p; }\n  bint operator-(const bint &p) const { return bint(*this)\
    \ -= p; }\n  // bint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  // bint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const bint &p) const {\n    return (sgn == p.sgn && dat\
    \ == p.dat);\n  }\n  bool operator!=(const bint &p) const {\n    return (sgn !=\
    \ p.sgn || dat != p.dat);\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(to_string());\
    \ }\n  void read() {\n    string s;\n    fastio::printer.write(s);\n    *this\
    \ = bint(s);\n  }\n#endif\n  string to_string() {\n    if (dat.empty()) return\
    \ \"0\";\n    string s;\n    for (int x: dat) {\n      FOR(6) {\n        s +=\
    \ '0' + (x % 10);\n        x = x / 10;\n      }\n    }\n    while (s.back() ==\
    \ '0') s.pop_back();\n    if (sgn == -1) s += '-';\n    reverse(all(s));\n   \
    \ return s;\n  }\n};\n"
  code: "// 10^6 \u305A\u3064\u533A\u5207\u3063\u3066\nstruct BigInteger {\n  static\
    \ constexpr int LOG = 6;\n  static constexpr int MOD = 1000000;\n  using bint\
    \ = BigInteger;\n  int sgn; // +1 or -1. \u5185\u90E8\u72B6\u614B\u3067 -0 \u3092\
    \u8A31\u5BB9\u3059\u308B.\n  vc<int> dat;\n\n  BigInteger(i128 val) {\n    if\
    \ (val == 0) {\n      sgn = 1;\n    } else {\n      if (val < 0) sgn = -1, val\
    \ = -val;\n      while (val > 0) {\n        dat.eb(val % MOD);\n        val /=\
    \ MOD;\n      }\n    }\n  }\n  BigInteger(string s) {\n    assert(!s.empty());\n\
    \    sgn = 1;\n    if (s[0] == '-') {\n      sgn = -1;\n      s.erase(s.begin());\n\
    \      assert(!s.empty());\n    }\n    if (s[0] == '0') s.clear();\n    reverse(all(s));\n\
    \    int n = len(s);\n    int m = ceil(n, LOG);\n    dat.assign(m, 0);\n    array<int,\
    \ LOG> pow = {1, 10, 100, 1000, 10000, 100000};\n    FOR(i, n) { dat[i / LOG]\
    \ += pow[i % LOG] * (s[i] - '0'); }\n  }\n  bint &operator=(const bint &p) {\n\
    \    sgn = p.sgn;\n    dat = p.dat;\n    return *this;\n  }\n  bool operator<(const\
    \ bint &p) const {\n    if (sgn != p.sgn) return sgn < p.sgn;\n    if (len(dat)\
    \ != len(p.dat)) {\n      if (sgn == 1) return len(dat) < len(p.dat);\n      if\
    \ (sgn == -1) return len(dat) > len(p.dat);\n    }\n    FOR_R(i, len(dat)) {\n\
    \      if (dat[i] == p.dat[i]) continue;\n      if (sgn == 1) return dat[i] <\
    \ p.dat[i];\n      if (sgn == -1) return dat[i] > p.dat[i];\n    }\n    return\
    \ false;\n  }\n  bool operator>(const bint &p) const { return p < *this; }\n \
    \ bool operator<=(const bint &p) const { return !(*this > p); }\n  bool operator>=(const\
    \ bint &p) const { return !(*this < p); }\n  bint &operator+=(const bint &p) {\n\
    \    if (sgn != p.sgn) {\n      *this -= (-p);\n      return *this;\n    }\n \
    \   int n = max(len(dat), len(p.dat));\n    dat.resize(n + 1);\n    FOR(i, n)\
    \ {\n      dat[i] += p.dat[i];\n      if (dat[i] >= MOD) dat[i] -= MOD, dat[i\
    \ + 1] += 1;\n    }\n    while (len(dat) && dat.back() == 0) dat.pop_back();\n\
    \    return *this;\n  }\n  bint &operator-=(const bint &p) {\n    if (sgn != p.sgn)\
    \ {\n      *this += (-p);\n      return *this;\n    }\n    bool small = (*this)\
    \ < p;\n    if ((sgn == 1 && small) || (sgn == -1 && (!small))) {\n      *this\
    \ = p - *this;\n      sgn = -sgn;\n      return *this;\n    }\n    FOR(i, len(p.dat))\
    \ { dat[i] -= p.dat[i]; }\n    FOR(i, len(dat) - 1) {\n      if (dat[i] < 0) dat[i]\
    \ += MOD, dat[i + 1] -= 1;\n    }\n    while (len(dat) && dat.back() == 0) { dat.pop_back();\
    \ }\n    return *this;\n  }\n  // bint &operator*=(const bint &p) { return *this;\
    \ }\n  // bint &operator/=(const bint &p) { return *this; }\n  bint operator-()\
    \ const {\n    bint p = *this;\n    p.sgn *= -1;\n    return p;\n  }\n  bint operator+(const\
    \ bint &p) const { return bint(*this) += p; }\n  bint operator-(const bint &p)\
    \ const { return bint(*this) -= p; }\n  // bint operator*(const modint &p) const\
    \ { return modint(*this) *= p; }\n  // bint operator/(const modint &p) const {\
    \ return modint(*this) /= p; }\n  bool operator==(const bint &p) const {\n   \
    \ return (sgn == p.sgn && dat == p.dat);\n  }\n  bool operator!=(const bint &p)\
    \ const {\n    return (sgn != p.sgn || dat != p.dat);\n  }\n#ifdef FASTIO\n  void\
    \ write() { fastio::printer.write(to_string()); }\n  void read() {\n    string\
    \ s;\n    fastio::printer.write(s);\n    *this = bint(s);\n  }\n#endif\n  string\
    \ to_string() {\n    if (dat.empty()) return \"0\";\n    string s;\n    for (int\
    \ x: dat) {\n      FOR(6) {\n        s += '0' + (x % 10);\n        x = x / 10;\n\
    \      }\n    }\n    while (s.back() == '0') s.pop_back();\n    if (sgn == -1)\
    \ s += '-';\n    reverse(all(s));\n    return s;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/bigint.hpp
  requiredBy: []
  timestamp: '2023-05-14 04:42:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/bigint.hpp
layout: document
redirect_from:
- /library/other/bigint.hpp
- /library/other/bigint.hpp.html
title: other/bigint.hpp
---
