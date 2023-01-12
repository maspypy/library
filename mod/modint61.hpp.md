---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/rollinghash.hpp
    title: alg/monoid/rollinghash.hpp
  - icon: ':heavy_check_mark:'
    path: graph/classify_subtree.hpp
    title: graph/classify_subtree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/max_matching_size.hpp
    title: graph/max_matching_size.hpp
  - icon: ':heavy_check_mark:'
    path: graph/rerooting_classify_subtree.hpp
    title: graph/rerooting_classify_subtree.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  - icon: ':heavy_check_mark:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash_vector.hpp
    title: random/hash_vector.hpp
  - icon: ':heavy_check_mark:'
    path: string/rollinghash.hpp
    title: string/rollinghash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/classify_tree.test.cpp
    title: test/library_checker/graph/classify_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/rerooting_classify_subtree.test.cpp
    title: test/library_checker/graph/rerooting_classify_subtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1397.test.cpp
    title: test/yukicoder/1397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2102.test.cpp
    title: test/yukicoder/2102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2167.test.cpp
    title: test/yukicoder/2167.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/263.test.cpp
    title: test/yukicoder/263.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4_1.test.cpp
    title: test/yukicoder/4_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\nstruct modint61 {\r\n  static constexpr\
    \ bool is_modint = true;\r\n  static constexpr ll mod = (1LL << 61) - 1;\r\n \
    \ ll val;\r\n  constexpr modint61(const ll x = 0) : val(x) {\r\n    while (val\
    \ < 0) val += mod;\r\n    while (val >= mod) val -= mod;\r\n  }\r\n  bool operator<(const\
    \ modint61 &other) const {\r\n    return val < other.val;\r\n  } // To use std::map\r\
    \n  bool operator==(const modint61 &p) const { return val == p.val; }\r\n  bool\
    \ operator!=(const modint61 &p) const { return val != p.val; }\r\n  modint61 &operator+=(const\
    \ modint61 &p) {\r\n    if ((val += p.val) >= mod) val -= mod;\r\n    return *this;\r\
    \n  }\r\n  modint61 &operator-=(const modint61 &p) {\r\n    if ((val += mod -\
    \ p.val) >= mod) val -= mod;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &p) {\r\n    ll a = val, b = p.val;\r\n    const ll MASK30 = (1LL <<\
    \ 30) - 1;\r\n    const ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 =\
    \ (1LL << 61) - 1;\r\n    ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >>\
    \ 31, bd = b & MASK31;\r\n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30,\
    \ xd = x & MASK30;\r\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n   \
    \ xu = x >> 61, xd = x & MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x\
    \ -= MASK61;\r\n    val = x;\r\n    return *this;\r\n  }\r\n  modint61 operator-()\
    \ const { return modint61(get_mod() - val); }\r\n  modint61 &operator/=(const\
    \ modint61 &p) {\r\n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n\
    \  modint61 operator+(const modint61 &p) const { return modint61(*this) += p;\
    \ }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n\r\n  modint61 inverse() const {\r\n    ll a = val, b = mod, u =\
    \ 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t\
    \ * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n\
    \  modint61 pow(int64_t n) const {\r\n    modint61 ret(1), mul(val);\r\n    while\
    \ (n > 0) {\r\n      if (n & 1) ret = ret * mul;\r\n      mul = mul * mul;\r\n\
    \      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n  static constexpr ll get_mod()\
    \ { return mod; }\r\n  void write() { fastio::printer.write(val); }\r\n  void\
    \ read() { fastio::scanner.read(val); }\r\n};\r\n"
  code: "#pragma once\r\nstruct modint61 {\r\n  static constexpr bool is_modint =\
    \ true;\r\n  static constexpr ll mod = (1LL << 61) - 1;\r\n  ll val;\r\n  constexpr\
    \ modint61(const ll x = 0) : val(x) {\r\n    while (val < 0) val += mod;\r\n \
    \   while (val >= mod) val -= mod;\r\n  }\r\n  bool operator<(const modint61 &other)\
    \ const {\r\n    return val < other.val;\r\n  } // To use std::map\r\n  bool operator==(const\
    \ modint61 &p) const { return val == p.val; }\r\n  bool operator!=(const modint61\
    \ &p) const { return val != p.val; }\r\n  modint61 &operator+=(const modint61\
    \ &p) {\r\n    if ((val += p.val) >= mod) val -= mod;\r\n    return *this;\r\n\
    \  }\r\n  modint61 &operator-=(const modint61 &p) {\r\n    if ((val += mod - p.val)\
    \ >= mod) val -= mod;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &p) {\r\n    ll a = val, b = p.val;\r\n    const ll MASK30 = (1LL <<\
    \ 30) - 1;\r\n    const ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 =\
    \ (1LL << 61) - 1;\r\n    ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >>\
    \ 31, bd = b & MASK31;\r\n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30,\
    \ xd = x & MASK30;\r\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n   \
    \ xu = x >> 61, xd = x & MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x\
    \ -= MASK61;\r\n    val = x;\r\n    return *this;\r\n  }\r\n  modint61 operator-()\
    \ const { return modint61(get_mod() - val); }\r\n  modint61 &operator/=(const\
    \ modint61 &p) {\r\n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n\
    \  modint61 operator+(const modint61 &p) const { return modint61(*this) += p;\
    \ }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n\r\n  modint61 inverse() const {\r\n    ll a = val, b = mod, u =\
    \ 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t\
    \ * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n\
    \  modint61 pow(int64_t n) const {\r\n    modint61 ret(1), mul(val);\r\n    while\
    \ (n > 0) {\r\n      if (n & 1) ret = ret * mul;\r\n      mul = mul * mul;\r\n\
    \      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n  static constexpr ll get_mod()\
    \ { return mod; }\r\n  void write() { fastio::printer.write(val); }\r\n  void\
    \ read() { fastio::scanner.read(val); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint61.hpp
  requiredBy:
  - graph/rerooting_classify_subtree.hpp
  - graph/classify_subtree.hpp
  - graph/max_matching_size.hpp
  - string/rollinghash.hpp
  - alg/monoid/rollinghash.hpp
  - random/hash_vector.hpp
  - other/connected_dp.hpp
  - mod/modular_subset_sum.hpp
  timestamp: '2022-12-23 11:05:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/classify_tree.test.cpp
  - test/library_checker/graph/rerooting_classify_subtree.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/1397.test.cpp
  - test/yukicoder/2167.test.cpp
  - test/yukicoder/263.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/2102.test.cpp
  - test/yukicoder/4_1.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/578.test.cpp
  - test/aoj/ALDS1_14_C.test.cpp
  - test/mytest/tdpc_grid_dp.test.cpp
  - test/mytest/tutte.test.cpp
documentation_of: mod/modint61.hpp
layout: document
redirect_from:
- /library/mod/modint61.hpp
- /library/mod/modint61.hpp.html
title: mod/modint61.hpp
---
