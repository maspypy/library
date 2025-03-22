---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1572/problem/F
  bundledCode: "#line 1 \"ds/segtree/beats_multiset_chmin.hpp\"\n\n// \u5217 A[i]\
    \ \u304C multiset \u3068\u3057\u3066\u3069\u3046\u306A\u3063\u3066\u3044\u308B\
    \u304B\u3092\u7BA1\u7406\u3059\u308B.\n// A[i]:=x, A[i]:=min(A[i],x)\n// https://codeforces.com/contest/1572/problem/F\n\
    template <typename T>\nstruct Beats_Multiset_Chmin {\n  int n, log, size;\n  struct\
    \ Data {\n    T max, max2;\n    int cnt, maxc;\n    T lazy;\n  };\n\n  Data from_element(T\
    \ x) { return {x, -infty<T>, 1, 1, infty<T>}; }\n  vc<Data> dat;\n\n  Data op(Data&\
    \ L, Data& R) {\n    if (L.cnt == 0) return R;\n    if (R.cnt == 0) return L;\n\
    \    Data ANS;\n    ANS.max = max(L.max, R.max);\n    ANS.max2 = -infty<T>;\n\
    \    if (L.max < ANS.max) chmax(ANS.max2, L.max);\n    if (L.max2 < ANS.max) chmax(ANS.max2,\
    \ L.max2);\n    if (R.max < ANS.max) chmax(ANS.max2, R.max);\n    if (R.max2 <\
    \ ANS.max) chmax(ANS.max2, R.max2);\n    ANS.maxc = 0;\n    if (L.max == ANS.max)\
    \ ANS.maxc += L.maxc;\n    if (R.max == ANS.max) ANS.maxc += R.maxc;\n    ANS.lazy\
    \ = infty<T>;\n    return ANS;\n  }\n\n  Beats_Multiset_Chmin() {}\n  Beats_Multiset_Chmin(int\
    \ n) { build(vc<T>(n)); }\n  template <typename F>\n  Beats_Multiset_Chmin(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Beats_Multiset_Chmin(const vc<T>& v) { build(v);\
    \ }\n  void build(const vc<T>& v) {\n    build(len(v), [&](int i) -> T { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.resize(size\
    \ << 1, {-infty<T>, -infty<T>, 0, 0, infty<T>});\n    FOR(i, n) { dat[size + i]\
    \ = from_element(f(i)); }\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void update(int\
    \ i) { dat[i] = op(dat[2 * i + 0], dat[2 * i + 1]); }\n\n  // f(before, after,\
    \ cnt)\n  template <typename F>\n  void set(int i, T x, F f) {\n    auto dfs =\
    \ [&](auto& dfs, int idx, int a, int b) -> void {\n      if (idx == size + i)\
    \ {\n        T now = dat[idx].max;\n        if (now != x) f(now, x, 1);\n    \
    \    dat[idx] = from_element(x);\n        return;\n      }\n      int c = (a +\
    \ b) / 2;\n      push(idx);\n      if (a <= i && i < c) dfs(dfs, 2 * idx + 0,\
    \ a, c);\n      if (c <= i && i < b) dfs(dfs, 2 * idx + 1, c, b);\n      update(idx);\n\
    \    };\n    dfs(dfs, 1, 0, size);\n  }\n\n  // f(before, after, cnt)\n  template\
    \ <typename F>\n  void chmin(int L, int R, T x, F f) {\n    auto dfs = [&](auto&\
    \ dfs, int idx, int a, int b) -> void {\n      if (R <= a || b <= L) return;\n\
    \      Data& X = dat[idx];\n      if (X.max <= x) return;\n      if (L <= a &&\
    \ b <= R && X.max2 < x) {\n        f(X.max, x, X.maxc);\n        X.max = x;\n\
    \        X.lazy = x;\n        return;\n      }\n      push(idx);\n      int c\
    \ = (a + b) / 2;\n      dfs(dfs, 2 * idx + 0, a, c), dfs(dfs, 2 * idx + 1, c,\
    \ b);\n      update(idx);\n    };\n    dfs(dfs, 1, 0, size);\n  }\n\n  // \u3046\
    \u307E\u304F\u4F5C\u7528\u3067\u304D\u3066\u3044\u308B\u3068\u3053\u308D\u306E\
    \u5B50\u306A\u306E\u3067\u3053\u308C\u3060\u3051\u3067\u3088\u3044\n  void push(int\
    \ i) {\n    assert(i < size);\n    T x = dat[i].lazy;\n    for (int j: {2 * i\
    \ + 0, 2 * i + 1}) {\n      ::chmin(dat[j].max, x);\n      ::chmin(dat[j].lazy,\
    \ x);\n    }\n  }\n};\n"
  code: "\n// \u5217 A[i] \u304C multiset \u3068\u3057\u3066\u3069\u3046\u306A\u3063\
    \u3066\u3044\u308B\u304B\u3092\u7BA1\u7406\u3059\u308B.\n// A[i]:=x, A[i]:=min(A[i],x)\n\
    // https://codeforces.com/contest/1572/problem/F\ntemplate <typename T>\nstruct\
    \ Beats_Multiset_Chmin {\n  int n, log, size;\n  struct Data {\n    T max, max2;\n\
    \    int cnt, maxc;\n    T lazy;\n  };\n\n  Data from_element(T x) { return {x,\
    \ -infty<T>, 1, 1, infty<T>}; }\n  vc<Data> dat;\n\n  Data op(Data& L, Data& R)\
    \ {\n    if (L.cnt == 0) return R;\n    if (R.cnt == 0) return L;\n    Data ANS;\n\
    \    ANS.max = max(L.max, R.max);\n    ANS.max2 = -infty<T>;\n    if (L.max <\
    \ ANS.max) chmax(ANS.max2, L.max);\n    if (L.max2 < ANS.max) chmax(ANS.max2,\
    \ L.max2);\n    if (R.max < ANS.max) chmax(ANS.max2, R.max);\n    if (R.max2 <\
    \ ANS.max) chmax(ANS.max2, R.max2);\n    ANS.maxc = 0;\n    if (L.max == ANS.max)\
    \ ANS.maxc += L.maxc;\n    if (R.max == ANS.max) ANS.maxc += R.maxc;\n    ANS.lazy\
    \ = infty<T>;\n    return ANS;\n  }\n\n  Beats_Multiset_Chmin() {}\n  Beats_Multiset_Chmin(int\
    \ n) { build(vc<T>(n)); }\n  template <typename F>\n  Beats_Multiset_Chmin(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Beats_Multiset_Chmin(const vc<T>& v) { build(v);\
    \ }\n  void build(const vc<T>& v) {\n    build(len(v), [&](int i) -> T { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.resize(size\
    \ << 1, {-infty<T>, -infty<T>, 0, 0, infty<T>});\n    FOR(i, n) { dat[size + i]\
    \ = from_element(f(i)); }\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void update(int\
    \ i) { dat[i] = op(dat[2 * i + 0], dat[2 * i + 1]); }\n\n  // f(before, after,\
    \ cnt)\n  template <typename F>\n  void set(int i, T x, F f) {\n    auto dfs =\
    \ [&](auto& dfs, int idx, int a, int b) -> void {\n      if (idx == size + i)\
    \ {\n        T now = dat[idx].max;\n        if (now != x) f(now, x, 1);\n    \
    \    dat[idx] = from_element(x);\n        return;\n      }\n      int c = (a +\
    \ b) / 2;\n      push(idx);\n      if (a <= i && i < c) dfs(dfs, 2 * idx + 0,\
    \ a, c);\n      if (c <= i && i < b) dfs(dfs, 2 * idx + 1, c, b);\n      update(idx);\n\
    \    };\n    dfs(dfs, 1, 0, size);\n  }\n\n  // f(before, after, cnt)\n  template\
    \ <typename F>\n  void chmin(int L, int R, T x, F f) {\n    auto dfs = [&](auto&\
    \ dfs, int idx, int a, int b) -> void {\n      if (R <= a || b <= L) return;\n\
    \      Data& X = dat[idx];\n      if (X.max <= x) return;\n      if (L <= a &&\
    \ b <= R && X.max2 < x) {\n        f(X.max, x, X.maxc);\n        X.max = x;\n\
    \        X.lazy = x;\n        return;\n      }\n      push(idx);\n      int c\
    \ = (a + b) / 2;\n      dfs(dfs, 2 * idx + 0, a, c), dfs(dfs, 2 * idx + 1, c,\
    \ b);\n      update(idx);\n    };\n    dfs(dfs, 1, 0, size);\n  }\n\n  // \u3046\
    \u307E\u304F\u4F5C\u7528\u3067\u304D\u3066\u3044\u308B\u3068\u3053\u308D\u306E\
    \u5B50\u306A\u306E\u3067\u3053\u308C\u3060\u3051\u3067\u3088\u3044\n  void push(int\
    \ i) {\n    assert(i < size);\n    T x = dat[i].lazy;\n    for (int j: {2 * i\
    \ + 0, 2 * i + 1}) {\n      ::chmin(dat[j].max, x);\n      ::chmin(dat[j].lazy,\
    \ x);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/beats_multiset_chmin.hpp
  requiredBy: []
  timestamp: '2025-03-22 20:18:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/beats_multiset_chmin.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_multiset_chmin.hpp
- /library/ds/segtree/beats_multiset_chmin.hpp.html
title: ds/segtree/beats_multiset_chmin.hpp
---
