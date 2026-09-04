---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/offline_query/offline_set_intersection.hpp
    title: ds/offline_query/offline_set_intersection.hpp
  - icon: ':heavy_check_mark:'
    path: ds/static_range_frequency.hpp
    title: ds/static_range_frequency.hpp
  - icon: ':warning:'
    path: string/aho_corasick_for_general_trie.hpp
    title: string/aho_corasick_for_general_trie.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_range_freq.test.cpp
    title: test/2_library_checker/data_structure/static_range_freq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_range_frequency.test.cpp
    title: test/2_library_checker/data_structure/static_range_frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_range_mode_query.test.cpp
    title: test/2_library_checker/data_structure/static_range_mode_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\n\
    struct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\
    \u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n \
    \   u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n\
    \    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\
    \u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build\
    \ \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used), 0);\n\
    \    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\
    \n  int index(const u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] &&\
    \ key[i] != k; i = (i + 1) & mask) {\n    }\n    return i;\n  }\n\n  Val& operator[](const\
    \ u64& k) {\n    int i = index(k);\n    if (used[i]) return val[i];\n    if (cap\
    \ == 0) extend(), i = index(k);\n    used[i] = 1, key[i] = k, val[i] = Val{},\
    \ --cap;\n    return val[i];\n  }\n\n  Val get(const u64& k, Val default_value)\
    \ {\n    int i = index(k);\n    return (used[i] ? val[i] : default_value);\n \
    \ }\n\n  bool count(const u64& k) {\n    int i = index(k);\n    return used[i]\
    \ && key[i] == k;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\n  }\n\n private:\n\
    \  u32 cap, mask;\n  vc<u64> key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64\
    \ x) {\n    static const u64 FIXED_RANDOM =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b] : dat) (*this)[a] = b;\n\
    \  }\n};\n#line 2 \"ds/to_small_key.hpp\"\n\n// [30,10,20,30] -> [0,1,2,0] etc.\n\
    struct To_Small_Key {\n  int kind = 0;\n  HashMap<int> MP;\n  vc<u64> raw;\n \
    \ To_Small_Key(u32 n = 0) : MP(n) {}\n  void reserve(u32 n) { MP.build(n); }\n\
    \  int size() { return MP.size(); }\n  u64 restore(int i) { return raw[i]; }\n\
    \  int query(u64 x, bool set_if_not_exist) {\n    int ans = MP.get(x, -1);\n \
    \   if (ans == -1 && set_if_not_exist) {\n      raw.eb(x);\n      MP[x] = ans\
    \ = kind++;\n    }\n    return ans;\n  }\n};\n"
  code: "#include \"ds/hashmap.hpp\"\n\n// [30,10,20,30] -> [0,1,2,0] etc.\nstruct\
    \ To_Small_Key {\n  int kind = 0;\n  HashMap<int> MP;\n  vc<u64> raw;\n  To_Small_Key(u32\
    \ n = 0) : MP(n) {}\n  void reserve(u32 n) { MP.build(n); }\n  int size() { return\
    \ MP.size(); }\n  u64 restore(int i) { return raw[i]; }\n  int query(u64 x, bool\
    \ set_if_not_exist) {\n    int ans = MP.get(x, -1);\n    if (ans == -1 && set_if_not_exist)\
    \ {\n      raw.eb(x);\n      MP[x] = ans = kind++;\n    }\n    return ans;\n \
    \ }\n};"
  dependsOn:
  - ds/hashmap.hpp
  isVerificationFile: false
  path: ds/to_small_key.hpp
  requiredBy:
  - string/aho_corasick_for_general_trie.hpp
  - ds/static_range_frequency.hpp
  - ds/offline_query/offline_set_intersection.hpp
  timestamp: '2026-09-01 10:19:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/static_range_freq.test.cpp
  - test/2_library_checker/data_structure/static_range_mode_query.test.cpp
  - test/2_library_checker/data_structure/static_range_frequency.test.cpp
documentation_of: ds/to_small_key.hpp
layout: document
redirect_from:
- /library/ds/to_small_key.hpp
- /library/ds/to_small_key.hpp.html
title: ds/to_small_key.hpp
---
