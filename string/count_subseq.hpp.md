---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_subsequences.test.cpp
    title: test/library_checker/string/number_of_subsequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1493.test.cpp
    title: test/yukicoder/1493.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val, int LOG = 20>\r\nstruct HashMap\
    \ {\r\n  int N;\r\n  u64* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1\
    \ << LOG> used;\r\n  const int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\
    \n  HashMap()\r\n      : N(1 << LOG), keys(new u64[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const u64 FIXED_RANDOM\r\n\
    \        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n  \
    \  return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i]\
    \ != key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  // [] \u3057\
    \u305F\u6642\u70B9\u3067\u8981\u7D20\u306F\u4F5C\u3089\u308C\u308B\r\n  Val& operator[](const\
    \ u64& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const u64& key, Val default_value) {\r\n    int i = index(key);\r\n\
    \    if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const u64& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key, val)\r\n  template\
    \ <typename F>\r\n  void enumerate_all(F f) {\r\n    for (auto&& i: IDS) f(keys[i],\
    \ vals[i]);\r\n  }\r\n};\r\n#line 2 \"string/count_subseq.hpp\"\n\ntemplate <typename\
    \ mint, typename CHAR, typename STRING, int LOG = 20>\nmint count_subseq(STRING\
    \ S) {\n  static HashMap<int, LOG> IDX;\n  ll N = len(S);\n  vc<mint> DP(N + 1);\n\
    \  DP[0] = 1;\n  FOR(i, N) {\n    CHAR c = S[i];\n    DP[i + 1] = DP[i] + DP[i];\n\
    \    int k = IDX.get(c, -1);\n    if (k != -1) DP[i + 1] -= DP[k];\n    IDX[c]\
    \ = i;\n  }\n  return DP.back();\n}\n"
  code: "#include \"ds/hashmap.hpp\"\n\ntemplate <typename mint, typename CHAR, typename\
    \ STRING, int LOG = 20>\nmint count_subseq(STRING S) {\n  static HashMap<int,\
    \ LOG> IDX;\n  ll N = len(S);\n  vc<mint> DP(N + 1);\n  DP[0] = 1;\n  FOR(i, N)\
    \ {\n    CHAR c = S[i];\n    DP[i + 1] = DP[i] + DP[i];\n    int k = IDX.get(c,\
    \ -1);\n    if (k != -1) DP[i + 1] -= DP[k];\n    IDX[c] = i;\n  }\n  return DP.back();\n\
    }\n"
  dependsOn:
  - ds/hashmap.hpp
  - random/base.hpp
  isVerificationFile: false
  path: string/count_subseq.hpp
  requiredBy: []
  timestamp: '2023-04-02 04:26:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1493.test.cpp
  - test/library_checker/string/number_of_subsequences.test.cpp
documentation_of: string/count_subseq.hpp
layout: document
redirect_from:
- /library/string/count_subseq.hpp
- /library/string/count_subseq.hpp.html
title: string/count_subseq.hpp
---
