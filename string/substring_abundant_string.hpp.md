---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: string/run_length.hpp
    title: string/run_length.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/substring_abundant.test.cpp
    title: test/1_mytest/substring_abundant.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://oeis.org/A094913
    - https://qoj.ac/contest/1096/problem/5434
    - https://www.mimuw.edu.pl/~rytter/MYPAPERS/paper.pdf
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"string/run_length.hpp\"\
    \ntemplate <typename STRING = string>\nvc<pair<typename STRING::value_type, ll>>\
    \ run_length(const STRING& S) {\n  vc<pair<typename STRING::value_type, ll>> res;\n\
    \  for (auto&& x : S) {\n    if (res.empty() || res.back().fi != x) {\n      res.emplace_back(x,\
    \ 0);\n    }\n    res.back().se++;\n  }\n  return res;\n}\n#line 3 \"string/substring_abundant_string.hpp\"\
    \n\n// \u90E8\u5206\u6587\u5B57\u5217\u306E\u7A2E\u985E\u6570\u304C\u6700\u5927\
    \u3067\u3042\u308B\u3088\u3046\u306A 01 \u6587\u5B57\u5217\u306E\u69CB\u6210\n\
    // https://qoj.ac/contest/1096/problem/5434\n// https://oeis.org/A094913\n// https://www.mimuw.edu.pl/~rytter/MYPAPERS/paper.pdf\n\
    string substring_abundant_string(ll N) {\n  ll N0 = N;\n  N = 1;\n  while ((1\
    \ << N) + (N - 1) < N0) ++N;\n\n  string S = [&]() -> string {\n    if (N == 1)\
    \ return \"01\";\n    if (N == 2) return \"00110\";\n\n    auto SHIFT = [&](string\
    \ x, string y) -> string {\n      int n = len(x);\n      x += x;\n      FOR(i,\
    \ n, n + n) {\n        if (x.substr(i - len(y), len(y)) == y) {\n          return\
    \ x.substr(i - n, n);\n        }\n      }\n      return \"\";\n    };\n    auto\
    \ oplus = [&](string x, string y) -> string {\n      int n = topbit(len(y));\n\
    \      assert(len(x) == (1 << n) && len(y) == (1 << n));\n      return x + SHIFT(y,\
    \ x.substr(len(x) - n, n));\n    };\n    auto NOT = [&](string x) -> string {\n\
    \      string y;\n      for (auto&& s : x) y += (s == '0' ? '1' : '0');\n    \
    \  return y;\n    };\n    auto PSI = [&](string x) -> string {\n      int a =\
    \ 0;\n      FOR(i, len(x)) {\n        a ^= (x[i] - '0');\n        x[i] = ('0'\
    \ + a);\n      }\n      return x;\n    };\n\n    auto NEXT = [&](string x) ->\
    \ string {\n      x = PSI(x);\n      return oplus(x, NOT(x));\n    };\n\n    auto\
    \ otimes = [&](string x, string y) -> string {\n      string t;\n      FOR(topbit(len(x)))\
    \ t += '0';\n      x = SHIFT(x, t);\n      y = SHIFT(y, t);\n      rotate(x.begin(),\
    \ x.end() - len(t), x.end());\n      rotate(y.begin(), y.end() - len(t), y.end());\n\
    \n      int n = len(x);\n      int x0 = 0, x1 = 0, y0 = 0, y1 = 1;\n      for\
    \ (auto&& [k, v] : run_length(x)) {\n        if (k == '0') chmax(x0, v);\n   \
    \     if (k == '1') chmax(x1, v);\n      }\n      for (auto&& [k, v] : run_length(y))\
    \ {\n        if (k == '0') chmax(y0, v);\n        if (k == '1') chmax(y1, v);\n\
    \      }\n      string X, Y;\n      for (auto&& [k, v] : run_length(x)) {\n  \
    \      if (k == '0' && v < x0) {\n          X += string(v, k);\n        }\n  \
    \      if (k == '0' && v == x0) {\n          X += string(v - 1, k);\n        }\n\
    \        if (k == '1' && v < x1) {\n          X += string(v, k);\n        }\n\
    \        if (k == '1' && v == x1) {\n          X += string(v + 1, k);\n      \
    \  }\n      }\n      for (auto&& [k, v] : run_length(y)) {\n        if (k == '0'\
    \ && v < y0) {\n          Y += string(v, k);\n        }\n        if (k == '0'\
    \ && v == y0) {\n          Y += string(v + 1, k);\n        }\n        if (k ==\
    \ '1' && v < y1) {\n          Y += string(v, k);\n        }\n        if (k ==\
    \ '1' && v == y1) {\n          Y += string(v - 1, k);\n        }\n      }\n  \
    \    return X + Y;\n    };\n\n    string x = \"0011\", y = \"0011\";\n    FOR(i,\
    \ 2, N - 1) {\n      string t;\n      FOR(i) t += '1';\n      x = SHIFT(x, t);\n\
    \      x = NEXT(x);\n      y = SHIFT(y, t);\n      y = NOT(NEXT(y));\n    }\n\
    \    x = otimes(x, y);\n    FOR(i, N - 1) x += x[i];\n    return x;\n  }();\n\
    \  return S.substr(0, N0);\n}\n"
  code: "#include \"other/bit.hpp\"\n#include \"string/run_length.hpp\"\n\n// \u90E8\
    \u5206\u6587\u5B57\u5217\u306E\u7A2E\u985E\u6570\u304C\u6700\u5927\u3067\u3042\
    \u308B\u3088\u3046\u306A 01 \u6587\u5B57\u5217\u306E\u69CB\u6210\n// https://qoj.ac/contest/1096/problem/5434\n\
    // https://oeis.org/A094913\n// https://www.mimuw.edu.pl/~rytter/MYPAPERS/paper.pdf\n\
    string substring_abundant_string(ll N) {\n  ll N0 = N;\n  N = 1;\n  while ((1\
    \ << N) + (N - 1) < N0) ++N;\n\n  string S = [&]() -> string {\n    if (N == 1)\
    \ return \"01\";\n    if (N == 2) return \"00110\";\n\n    auto SHIFT = [&](string\
    \ x, string y) -> string {\n      int n = len(x);\n      x += x;\n      FOR(i,\
    \ n, n + n) {\n        if (x.substr(i - len(y), len(y)) == y) {\n          return\
    \ x.substr(i - n, n);\n        }\n      }\n      return \"\";\n    };\n    auto\
    \ oplus = [&](string x, string y) -> string {\n      int n = topbit(len(y));\n\
    \      assert(len(x) == (1 << n) && len(y) == (1 << n));\n      return x + SHIFT(y,\
    \ x.substr(len(x) - n, n));\n    };\n    auto NOT = [&](string x) -> string {\n\
    \      string y;\n      for (auto&& s : x) y += (s == '0' ? '1' : '0');\n    \
    \  return y;\n    };\n    auto PSI = [&](string x) -> string {\n      int a =\
    \ 0;\n      FOR(i, len(x)) {\n        a ^= (x[i] - '0');\n        x[i] = ('0'\
    \ + a);\n      }\n      return x;\n    };\n\n    auto NEXT = [&](string x) ->\
    \ string {\n      x = PSI(x);\n      return oplus(x, NOT(x));\n    };\n\n    auto\
    \ otimes = [&](string x, string y) -> string {\n      string t;\n      FOR(topbit(len(x)))\
    \ t += '0';\n      x = SHIFT(x, t);\n      y = SHIFT(y, t);\n      rotate(x.begin(),\
    \ x.end() - len(t), x.end());\n      rotate(y.begin(), y.end() - len(t), y.end());\n\
    \n      int n = len(x);\n      int x0 = 0, x1 = 0, y0 = 0, y1 = 1;\n      for\
    \ (auto&& [k, v] : run_length(x)) {\n        if (k == '0') chmax(x0, v);\n   \
    \     if (k == '1') chmax(x1, v);\n      }\n      for (auto&& [k, v] : run_length(y))\
    \ {\n        if (k == '0') chmax(y0, v);\n        if (k == '1') chmax(y1, v);\n\
    \      }\n      string X, Y;\n      for (auto&& [k, v] : run_length(x)) {\n  \
    \      if (k == '0' && v < x0) {\n          X += string(v, k);\n        }\n  \
    \      if (k == '0' && v == x0) {\n          X += string(v - 1, k);\n        }\n\
    \        if (k == '1' && v < x1) {\n          X += string(v, k);\n        }\n\
    \        if (k == '1' && v == x1) {\n          X += string(v + 1, k);\n      \
    \  }\n      }\n      for (auto&& [k, v] : run_length(y)) {\n        if (k == '0'\
    \ && v < y0) {\n          Y += string(v, k);\n        }\n        if (k == '0'\
    \ && v == y0) {\n          Y += string(v + 1, k);\n        }\n        if (k ==\
    \ '1' && v < y1) {\n          Y += string(v, k);\n        }\n        if (k ==\
    \ '1' && v == y1) {\n          Y += string(v - 1, k);\n        }\n      }\n  \
    \    return X + Y;\n    };\n\n    string x = \"0011\", y = \"0011\";\n    FOR(i,\
    \ 2, N - 1) {\n      string t;\n      FOR(i) t += '1';\n      x = SHIFT(x, t);\n\
    \      x = NEXT(x);\n      y = SHIFT(y, t);\n      y = NOT(NEXT(y));\n    }\n\
    \    x = otimes(x, y);\n    FOR(i, N - 1) x += x[i];\n    return x;\n  }();\n\
    \  return S.substr(0, N0);\n}"
  dependsOn:
  - other/bit.hpp
  - string/run_length.hpp
  isVerificationFile: false
  path: string/substring_abundant_string.hpp
  requiredBy: []
  timestamp: '2026-08-31 13:26:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/substring_abundant.test.cpp
documentation_of: string/substring_abundant_string.hpp
layout: document
redirect_from:
- /library/string/substring_abundant_string.hpp
- /library/string/substring_abundant_string.hpp.html
title: string/substring_abundant_string.hpp
---
