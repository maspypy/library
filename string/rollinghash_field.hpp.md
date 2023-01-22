---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/_atcoder/abc274_h.test.cpp
    title: test/_atcoder/abc274_h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rollinghash_field.hpp\"\n// +, -, * \u304C\u5B9A\u7FA9\
    \u3055\u308C\u305F\u69CB\u9020\u4F53\u3092\u6E21\u3059\ntemplate <typename Field>\n\
    struct RollingHash_Field {\n  using F = Field;\n  const F base;\n  vector<F> power;\n\
    \n  static inline F generate_base() { return RNG(1LL << 60); }\n\n  inline void\
    \ expand(int sz) {\n    if (int(power.size()) < sz + 1) {\n      int pre_sz =\
    \ (int)power.size();\n      power.resize(sz + 1);\n      for (int i = pre_sz -\
    \ 1; i < sz; i++) { power[i + 1] = power[i] * base; }\n    }\n  }\n\n  explicit\
    \ RollingHash_Field(F base = generate_base()) : base(base), power{1} {}\n\n  template\
    \ <typename STRING>\n  vector<F> build(const STRING &s) const {\n    int sz =\
    \ s.size();\n    vector<F> hashed(sz + 1);\n    for (int i = 0; i < sz; i++) {\n\
    \      hashed[i + 1] = (hashed[i] * base) + F(s[i]);\n    }\n    return hashed;\n\
    \  }\n\n  F query(const vector<F> &s, int l, int r) {\n    expand(r - l);\n  \
    \  return s[r] - s[l] * power[r - l];\n  }\n\n  F combine(F h1, F h2, size_t h2len)\
    \ {\n    expand(h2len);\n    return add(mul(h1, power[h2len]), h2);\n  }\n\n \
    \ int lcp(const vector<F> &a, int l1, int r1, const vector<F> &b, int l2,\n  \
    \        int r2) {\n    int len = min(r1 - l1, r2 - l2);\n    int low = 0, high\
    \ = len + 1;\n    while (high - low > 1) {\n      int mid = (low + high) / 2;\n\
    \      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))\n        low = mid;\n\
    \      else\n        high = mid;\n    }\n    return low;\n  }\n};\n"
  code: "// +, -, * \u304C\u5B9A\u7FA9\u3055\u308C\u305F\u69CB\u9020\u4F53\u3092\u6E21\
    \u3059\ntemplate <typename Field>\nstruct RollingHash_Field {\n  using F = Field;\n\
    \  const F base;\n  vector<F> power;\n\n  static inline F generate_base() { return\
    \ RNG(1LL << 60); }\n\n  inline void expand(int sz) {\n    if (int(power.size())\
    \ < sz + 1) {\n      int pre_sz = (int)power.size();\n      power.resize(sz +\
    \ 1);\n      for (int i = pre_sz - 1; i < sz; i++) { power[i + 1] = power[i] *\
    \ base; }\n    }\n  }\n\n  explicit RollingHash_Field(F base = generate_base())\
    \ : base(base), power{1} {}\n\n  template <typename STRING>\n  vector<F> build(const\
    \ STRING &s) const {\n    int sz = s.size();\n    vector<F> hashed(sz + 1);\n\
    \    for (int i = 0; i < sz; i++) {\n      hashed[i + 1] = (hashed[i] * base)\
    \ + F(s[i]);\n    }\n    return hashed;\n  }\n\n  F query(const vector<F> &s,\
    \ int l, int r) {\n    expand(r - l);\n    return s[r] - s[l] * power[r - l];\n\
    \  }\n\n  F combine(F h1, F h2, size_t h2len) {\n    expand(h2len);\n    return\
    \ add(mul(h1, power[h2len]), h2);\n  }\n\n  int lcp(const vector<F> &a, int l1,\
    \ int r1, const vector<F> &b, int l2,\n          int r2) {\n    int len = min(r1\
    \ - l1, r2 - l2);\n    int low = 0, high = len + 1;\n    while (high - low > 1)\
    \ {\n      int mid = (low + high) / 2;\n      if (query(a, l1, l1 + mid) == query(b,\
    \ l2, l2 + mid))\n        low = mid;\n      else\n        high = mid;\n    }\n\
    \    return low;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash_field.hpp
  requiredBy: []
  timestamp: '2022-10-23 02:20:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/_atcoder/abc274_h.test.cpp
documentation_of: string/rollinghash_field.hpp
layout: document
redirect_from:
- /library/string/rollinghash_field.hpp
- /library/string/rollinghash_field.hpp.html
title: string/rollinghash_field.hpp
---
