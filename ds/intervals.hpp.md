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
    - https://codeforces.com/contest/1638/problem/E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fastset.hpp\"\n\n// FastSet \u3067\u9AD8\u901F\u5316\u3057\u305F\
    \u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast {\n  const int LLIM,\
    \ RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\
    \u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  int total_len;\n\
    \  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n      : LLIM(0),\n\
    \        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n      \
    \  total_len(0),\n        dat(N, none_val),\n        ss(N) {\n    ss.insert(0);\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<int, int, T> get(int x, bool ERASE = false) {\n    int l =\
    \ ss.prev(x);\n    int r = ss.next(x + 1);\n    T t = dat[l];\n    if (t != none_val\
    \ && ERASE) {\n      --total_num, total_len -= r - l;\n      dat[l] = none_val;\n\
    \      merge_at(l);\n      merge_at(r);\n    }\n    return {l, r, t};\n  }\n\n\
    \  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97\n  // f(l,r,x)\n\
    \  template <typename F>\n  void enumerate_range(int L, int R, F f, bool ERASE\
    \ = false) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n\
    \    if (!ERASE) {\n      int l = ss.prev(L);\n      while (l < R) {\n       \
    \ int r = ss.next(l + 1);\n        f(max(l, L), min(r, R), dat[l]);\n        l\
    \ = r;\n      }\n      return;\n    }\n    // \u534A\u7AEF\u306A\u3068\u3053\u308D\
    \u306E\u5206\u5272\n    int p = ss.prev(L);\n    if (p < L) {\n      ss.insert(L);\n\
    \      dat[L] = dat[p];\n      if (dat[L] != none_val) ++total_num;\n    }\n \
    \   p = ss.next(R);\n    if (R < p) {\n      dat[R] = dat[ss.prev(R)];\n     \
    \ ss.insert(R);\n      if (dat[R] != none_val) ++total_num;\n    }\n    p = L;\n\
    \    while (p < R) {\n      int q = ss.next(p + 1);\n      T x = dat[p];\n   \
    \   f(p, q, x);\n      if (dat[p] != none_val) --total_num, total_len -= q - p;\n\
    \      ss.erase(p);\n      p = q;\n    }\n    ss.insert(L);\n    dat[L] = none_val;\n\
    \  }\n\n  void set(int L, int R, T t) {\n    if (L == R) return;\n    enumerate_range(L,\
    \ R, [](int l, int r, T x) -> void {}, true);\n    ss.insert(L);\n    dat[L] =\
    \ t;\n    if (t != none_val) total_num++, total_len += R - L;\n    merge_at(L);\n\
    \    merge_at(R);\n  }\n\n  template <typename F>\n  void enumerate_all(F f) {\n\
    \    enumerate_range(0, RLIM, f, false);\n  }\n\n  void merge_at(int p) {\n  \
    \  if (p <= 0 || RLIM <= p) return;\n    int q = ss.prev(p - 1);\n    if (dat[p]\
    \ == dat[q]) {\n      if (dat[p] != none_val) --total_num;\n      ss.erase(p);\n\
    \    }\n  }\n\n  vc<T> get_all() {\n    vc<T> res(RLIM, none_val);\n    enumerate_all([&](int\
    \ a, int b, T t) -> void { FOR(i, a, b) res[i] = t; });\n    return res;\n  }\n\
    };\n\n// https://codeforces.com/contest/1638/problem/E\n// \u6301\u3064\u5024\u306E\
    \u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n// \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\u5B9A\u3059\u308B\
    \n// \u5148\u8AAD\u307F\u53EF\u80FD\u306A\u3089\u5EA7\u5727\u3057\u3066 fastset\
    \ \u306E\u65B9\u304C\u901F\u3044\ntemplate <typename T, typename X = ll>\nstruct\
    \ Intervals {\n  static constexpr X LLIM = -infty<X>;\n  static constexpr X RLIM\
    \ = infty<X>;\n  T none_val;\n  // const T none_val;\n  // none_val \u3067\u306A\
    \u3044\u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n\
    \  X total_len;\n  map<X, T> dat;\n\n  Intervals(T none_val = 0) : none_val(none_val),\
    \ total_num(0), total_len(0) {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<X, X, T> get(X x, bool ERASE = false) {\n    auto it2 = dat.upper_bound(x);\n\
    \    auto it1 = prev(it2);\n    auto [l, tl] = *it1;\n    auto [r, tr] = *it2;\n\
    \    if (tl != none_val && ERASE) {\n      --total_num, total_len -= r - l;\n\
    \      dat[l] = none_val;\n      merge_at(l);\n      merge_at(r);\n    }\n   \
    \ return {l, r, tl};\n  }\n\n  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\
    \u53D6\u5F97 f(l, r, t)\n  template <typename F>\n  void enumerate_range(X L,\
    \ X R, F f, bool ERASE = false) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n\
    \    if (!ERASE) {\n      auto it = prev(dat.upper_bound(L));\n      while ((*it).fi\
    \ < R) {\n        auto it2 = next(it);\n        f(max((*it).fi, L), min((*it2).fi,\
    \ R), (*it).se);\n        it = it2;\n      }\n      return;\n    }\n    // \u534A\
    \u7AEF\u306A\u3068\u3053\u308D\u306E\u5206\u5272\n    auto p = prev(dat.upper_bound(L));\n\
    \    if ((*p).fi < L) {\n      dat[L] = (*p).se;\n      if (dat[L] != none_val)\
    \ ++total_num;\n    }\n    p = dat.lower_bound(R);\n    if (R < (*p).fi) {\n \
    \     T t = (*prev(p)).se;\n      dat[R] = t;\n      if (t != none_val) ++total_num;\n\
    \    }\n    p = dat.lower_bound(L);\n    while (1) {\n      if ((*p).fi >= R)\
    \ break;\n      auto q = next(p);\n      T t = (*p).se;\n      f((*p).fi, (*q).fi,\
    \ t);\n      if (t != none_val) --total_num, total_len -= (*q).fi - (*p).fi;\n\
    \      p = dat.erase(p);\n    }\n    dat[L] = none_val;\n  }\n\n  void set(X L,\
    \ X R, T t) {\n    assert(L <= R);\n    if (L == R) return;\n    enumerate_range(L,\
    \ R, [](int l, int r, T x) -> void {}, true);\n    dat[L] = t;\n    if (t != none_val)\
    \ total_num++, total_len += R - L;\n    merge_at(L);\n    merge_at(R);\n  }\n\n\
    \  template <typename F>\n  void enumerate_all(F f) {\n    enumerate_range(LLIM,\
    \ RLIM, f, false);\n  }\n\n  void merge_at(X p) {\n    if (p == LLIM || RLIM ==\
    \ p) return;\n    auto itp = dat.lower_bound(p);\n    assert((*itp).fi == p);\n\
    \    auto itq = prev(itp);\n    if ((*itp).se == (*itq).se) {\n      if ((*itp).se\
    \ != none_val) --total_num;\n      dat.erase(itp);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/intervals.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/intervals.hpp
layout: document
redirect_from:
- /library/ds/intervals.hpp
- /library/ds/intervals.hpp.html
title: ds/intervals.hpp
---
