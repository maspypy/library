---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/static_range_frequency.hpp
    title: ds/static_range_frequency.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_range_freq.test.cpp
    title: test/library_checker/datastructure/static_range_freq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val, int LOG = 20, bool KEEP_IDS = false>\r\nstruct HashMap {\r\n  static constexpr\
    \ int N = (1 << LOG);\r\n  u64* key;\r\n  Val* val;\r\n  vc<int> IDS;\r\n  bitset<N>\
    \ used;\r\n  const int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\n\
    \  HashMap() : key(new u64[N]), val(new Val[N]), shift(64 - LOG) {}\r\n  u32 hash(u64\
    \ x) {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    int i = index(k);\r\n    if (!used[i]) {\r\n      used[i] =\
    \ 1, key[i] = k, val[i] = Val{};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\
    \n    }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value)\
    \ {\r\n    int i = index(k);\r\n    if (!used[i]) return default_value;\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\
    \n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  void reset() {\r\n    static_assert(KEEP_IDS);\r\
    \n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  //\
    \ f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\n  \
    \  static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) f(key[i], val[i]);\r\n\
    \  }\r\n};\r\n#line 2 \"ds/to_small_key.hpp\"\n\n// [30,10,20,30] -> [0,1,2,0]\
    \ etc.\ntemplate <int LOG = 20, bool USE_RESET = false>\nstruct To_Small_Key {\n\
    \  int kind = 0;\n  HashMap<int, LOG, true> MP;\n\n  int set_key(u64 x) {\n  \
    \  int idx = MP.index(x);\n    if (!MP.used[idx]) {\n      MP.used[idx] = 1;\n\
    \      MP.key[idx] = x;\n      MP.val[idx] = kind++;\n    }\n    return MP.val[idx];\n\
    \  }\n\n  int query(u64 x) { return MP.get(x, -1); }\n\n  void reset() {\n   \
    \ static_assert(USE_RESET);\n    MP.reset();\n  }\n};\n"
  code: "#include \"ds/hashmap.hpp\"\n\n// [30,10,20,30] -> [0,1,2,0] etc.\ntemplate\
    \ <int LOG = 20, bool USE_RESET = false>\nstruct To_Small_Key {\n  int kind =\
    \ 0;\n  HashMap<int, LOG, true> MP;\n\n  int set_key(u64 x) {\n    int idx = MP.index(x);\n\
    \    if (!MP.used[idx]) {\n      MP.used[idx] = 1;\n      MP.key[idx] = x;\n \
    \     MP.val[idx] = kind++;\n    }\n    return MP.val[idx];\n  }\n\n  int query(u64\
    \ x) { return MP.get(x, -1); }\n\n  void reset() {\n    static_assert(USE_RESET);\n\
    \    MP.reset();\n  }\n};"
  dependsOn:
  - ds/hashmap.hpp
  isVerificationFile: false
  path: ds/to_small_key.hpp
  requiredBy:
  - ds/static_range_frequency.hpp
  timestamp: '2023-11-08 21:50:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/static_range_freq.test.cpp
documentation_of: ds/to_small_key.hpp
layout: document
redirect_from:
- /library/ds/to_small_key.hpp
- /library/ds/to_small_key.hpp.html
title: ds/to_small_key.hpp
---
