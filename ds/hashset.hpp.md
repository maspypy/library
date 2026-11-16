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
  bundledCode: "#line 1 \"ds/hashset.hpp\"\n\ntemplate <typename KEY>\nstruct HashSet\
    \ {\n  static_assert(is_same_v<KEY, u32> || is_same_v<KEY, u64>);\n\n  // n \u306F\
    \u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashSet(u32\
    \ n = 0) { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k <\
    \ n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const KEY& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {\n    }\n\
    \    return i;\n  }\n\n  bool operator[](const KEY& k) {\n    int i = index(k);\n\
    \    return used[i];\n  }\n\n  void insert(const KEY& k) {\n    int i = index(k);\n\
    \    if (used[i]) return;\n    if (cap == 0) {\n      extend();\n      i = index(k);\n\
    \    }\n    used[i] = true;\n    key[i] = k;\n    --cap;\n  }\n\n  // f(key, val)\n\
    \  template <typename F>\n  void enumerate_all(F f) {\n    bool end = false;\n\
    \    FOR(i, len(used)) {\n      if (used[i]) f(key[i], end);\n      if (end) break;\n\
    \    }\n  }\n\n private:\n  u32 cap, mask;\n  vc<KEY> key;\n  vc<bool> used;\n\
    \n  u32 hash(KEY x) {\n    static const u64 FIXED_RANDOM =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<KEY> dat;\n    dat.reserve(len(used) / 2 - cap);\n\
    \    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i]);\n    }\n    build(2\
    \ * len(dat));\n    for (auto& a : dat) (*this).insert(a);\n  }\n};\n"
  code: "\ntemplate <typename KEY>\nstruct HashSet {\n  static_assert(is_same_v<KEY,\
    \ u32> || is_same_v<KEY, u64>);\n\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\
    \u306E\u306E\u500B\u6570\u3067 ok\n  HashSet(u32 n = 0) { build(n); }\n  void\
    \ build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k /\
    \ 2, mask = k - 1;\n    key.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\
    \u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build\
    \ \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used), 0);\n\
    \    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\
    \n  int index(const KEY& k) {\n    int i = 0;\n    for (i = hash(k); used[i] &&\
    \ key[i] != k; i = (i + 1) & mask) {\n    }\n    return i;\n  }\n\n  bool operator[](const\
    \ KEY& k) {\n    int i = index(k);\n    return used[i];\n  }\n\n  void insert(const\
    \ KEY& k) {\n    int i = index(k);\n    if (used[i]) return;\n    if (cap == 0)\
    \ {\n      extend();\n      i = index(k);\n    }\n    used[i] = true;\n    key[i]\
    \ = k;\n    --cap;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    bool end = false;\n    FOR(i, len(used)) {\n      if (used[i]) f(key[i],\
    \ end);\n      if (end) break;\n    }\n  }\n\n private:\n  u32 cap, mask;\n  vc<KEY>\
    \ key;\n  vc<bool> used;\n\n  u32 hash(KEY x) {\n    static const u64 FIXED_RANDOM\
    \ =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n  \
    \  x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x =\
    \ (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<KEY> dat;\n    dat.reserve(len(used) / 2 - cap);\n\
    \    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i]);\n    }\n    build(2\
    \ * len(dat));\n    for (auto& a : dat) (*this).insert(a);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/hashset.hpp
  requiredBy: []
  timestamp: '2026-11-16 12:41:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/hashset.hpp
layout: document
redirect_from:
- /library/ds/hashset.hpp
- /library/ds/hashset.hpp.html
title: ds/hashset.hpp
---
