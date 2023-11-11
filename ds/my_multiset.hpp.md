---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc241d.test.cpp
    title: test_atcoder/abc241d.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc281e.test.cpp
    title: test_atcoder/abc281e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/my_multiset.hpp\"\ntemplate <typename VAL, typename SM>\n\
    struct My_Multiset {\n  using T = VAL;\n  int sz;\n  SM sm_all;\n  vvc<T> dat;\n\
    \  vc<SM> sm;\n  static const int BUCKET_RATIO = 50, REBUILD_RATIO = 170;\n\n\
    \  My_Multiset() : sz(0), sm_all(0), dat(1), sm(1) {}\n\n  void build(vc<T> vals)\
    \ {\n    sort(all(vals));\n    sz = len(vals);\n    int b_cnt = sqrt(sz / BUCKET_RATIO)\
    \ + 1;\n    dat.resize(b_cnt);\n    FOR(i, b_cnt) {\n      int l = sz * i / b_cnt,\
    \ r = sz * (i + 1) / b_cnt;\n      dat[i] = {vals.begin() + l, vals.begin() +\
    \ r};\n    }\n    sm.resize(b_cnt);\n    FOR(i, b_cnt) sm[i] = SUM<SM>(dat[i]);\n\
    \    sm_all = SUM<SM>(sm);\n  }\n\n  int size() { return sz; }\n  vc<T> get_all()\
    \ {\n    vc<T> res;\n    for (auto&& x: dat) res.insert(res.end(), all(x));\n\
    \    return res;\n  }\n\n  void rebuild() { build(get_all()); }\n\n  void insert(T\
    \ x) {\n    if (sz == 0) {\n      dat[0].eb(x);\n      ++sz, sm[0] += x, sm_all\
    \ += x;\n      return;\n    }\n    FOR(idx, len(dat)) {\n      if (dat[idx].back()\
    \ < x && idx < len(dat) - 1) continue;\n      dat[idx].insert(lower_bound(all(dat[idx]),\
    \ x), x);\n      ++sz, sm[idx] += x, sm_all += x;\n      if (len(dat[idx]) > len(dat)\
    \ * REBUILD_RATIO) rebuild();\n      break;\n    }\n  }\n  void add(T x) { insert(x);\
    \ }\n\n  void erase(T x) {\n    FOR(idx, len(dat)) {\n      if (dat[idx].back()\
    \ < x && idx < len(dat) - 1) continue;\n      dat[idx].erase(lower_bound(all(dat[idx]),\
    \ x));\n      --sz, sm[idx] -= x, sm_all -= x;\n      if (len(dat[idx]) == 0 &&\
    \ len(dat) > 0) {\n        dat.erase(dat.begin() + idx);\n        sm.erase(sm.begin()\
    \ + idx);\n      }\n      break;\n    }\n  }\n  void remove(T x) { erase(x); }\n\
    \n  int count(T x) {\n    int cnt = 0;\n    FOR(idx, len(dat)) {\n      if (dat[idx].back()\
    \ < x) continue;\n      if (dat[idx][0] > x) break;\n      if (dat[idx][0] ==\
    \ dat[idx].back())\n        cnt += len(dat[idx]);\n      else\n        cnt +=\
    \ upper_bound(all(dat[idx]), x) - lower_bound(all(dat[idx]), x);\n    }\n    return\
    \ cnt;\n  }\n\n  // {value[k], sum[0:k]}\n  pair<VAL, SM> get_kth(int k, bool\
    \ suffix = false) {\n    assert(0 <= k && k <= sz);\n    if (suffix) {\n     \
    \ if (k == sz) return {-infty<VAL>, sm_all};\n      auto [x, s] = get_kth(sz -\
    \ k - 1);\n      return {x, sm_all - s - x};\n    }\n    SM s = 0;\n    FOR(idx,\
    \ len(dat)) {\n      if (k >= len(dat[idx])) {\n        k -= len(dat[idx]);\n\
    \        s += sm[idx];\n        continue;\n      }\n      FOR(j, k) s += dat[idx][j];\n\
    \      return {dat[idx][k], s};\n    }\n    return {infty<VAL>, s};\n  }\n\n \
    \ // [lo, hi) \u3067 {cnt, sm}\n  pair<int, SM> get_range(T lo, T hi) {\n    if\
    \ (sz == 0) return {0, 0};\n    int cnt = 0;\n    SM s = 0;\n    FOR(idx, len(dat))\
    \ {\n      if (dat[idx].back() < lo) continue;\n      if (hi <= dat[idx][0]) break;\n\
    \      if (lo <= dat[idx][0] && dat[idx].back() < hi) {\n        cnt += len(dat[idx]),\
    \ s += sm[idx];\n        continue;\n      }\n      for (auto&& x: dat[idx])\n\
    \        if (lo <= x && x < hi) ++cnt, s += x;\n    }\n    return {cnt, s};\n\
    \  }\n};\n"
  code: "template <typename VAL, typename SM>\nstruct My_Multiset {\n  using T = VAL;\n\
    \  int sz;\n  SM sm_all;\n  vvc<T> dat;\n  vc<SM> sm;\n  static const int BUCKET_RATIO\
    \ = 50, REBUILD_RATIO = 170;\n\n  My_Multiset() : sz(0), sm_all(0), dat(1), sm(1)\
    \ {}\n\n  void build(vc<T> vals) {\n    sort(all(vals));\n    sz = len(vals);\n\
    \    int b_cnt = sqrt(sz / BUCKET_RATIO) + 1;\n    dat.resize(b_cnt);\n    FOR(i,\
    \ b_cnt) {\n      int l = sz * i / b_cnt, r = sz * (i + 1) / b_cnt;\n      dat[i]\
    \ = {vals.begin() + l, vals.begin() + r};\n    }\n    sm.resize(b_cnt);\n    FOR(i,\
    \ b_cnt) sm[i] = SUM<SM>(dat[i]);\n    sm_all = SUM<SM>(sm);\n  }\n\n  int size()\
    \ { return sz; }\n  vc<T> get_all() {\n    vc<T> res;\n    for (auto&& x: dat)\
    \ res.insert(res.end(), all(x));\n    return res;\n  }\n\n  void rebuild() { build(get_all());\
    \ }\n\n  void insert(T x) {\n    if (sz == 0) {\n      dat[0].eb(x);\n      ++sz,\
    \ sm[0] += x, sm_all += x;\n      return;\n    }\n    FOR(idx, len(dat)) {\n \
    \     if (dat[idx].back() < x && idx < len(dat) - 1) continue;\n      dat[idx].insert(lower_bound(all(dat[idx]),\
    \ x), x);\n      ++sz, sm[idx] += x, sm_all += x;\n      if (len(dat[idx]) > len(dat)\
    \ * REBUILD_RATIO) rebuild();\n      break;\n    }\n  }\n  void add(T x) { insert(x);\
    \ }\n\n  void erase(T x) {\n    FOR(idx, len(dat)) {\n      if (dat[idx].back()\
    \ < x && idx < len(dat) - 1) continue;\n      dat[idx].erase(lower_bound(all(dat[idx]),\
    \ x));\n      --sz, sm[idx] -= x, sm_all -= x;\n      if (len(dat[idx]) == 0 &&\
    \ len(dat) > 0) {\n        dat.erase(dat.begin() + idx);\n        sm.erase(sm.begin()\
    \ + idx);\n      }\n      break;\n    }\n  }\n  void remove(T x) { erase(x); }\n\
    \n  int count(T x) {\n    int cnt = 0;\n    FOR(idx, len(dat)) {\n      if (dat[idx].back()\
    \ < x) continue;\n      if (dat[idx][0] > x) break;\n      if (dat[idx][0] ==\
    \ dat[idx].back())\n        cnt += len(dat[idx]);\n      else\n        cnt +=\
    \ upper_bound(all(dat[idx]), x) - lower_bound(all(dat[idx]), x);\n    }\n    return\
    \ cnt;\n  }\n\n  // {value[k], sum[0:k]}\n  pair<VAL, SM> get_kth(int k, bool\
    \ suffix = false) {\n    assert(0 <= k && k <= sz);\n    if (suffix) {\n     \
    \ if (k == sz) return {-infty<VAL>, sm_all};\n      auto [x, s] = get_kth(sz -\
    \ k - 1);\n      return {x, sm_all - s - x};\n    }\n    SM s = 0;\n    FOR(idx,\
    \ len(dat)) {\n      if (k >= len(dat[idx])) {\n        k -= len(dat[idx]);\n\
    \        s += sm[idx];\n        continue;\n      }\n      FOR(j, k) s += dat[idx][j];\n\
    \      return {dat[idx][k], s};\n    }\n    return {infty<VAL>, s};\n  }\n\n \
    \ // [lo, hi) \u3067 {cnt, sm}\n  pair<int, SM> get_range(T lo, T hi) {\n    if\
    \ (sz == 0) return {0, 0};\n    int cnt = 0;\n    SM s = 0;\n    FOR(idx, len(dat))\
    \ {\n      if (dat[idx].back() < lo) continue;\n      if (hi <= dat[idx][0]) break;\n\
    \      if (lo <= dat[idx][0] && dat[idx].back() < hi) {\n        cnt += len(dat[idx]),\
    \ s += sm[idx];\n        continue;\n      }\n      for (auto&& x: dat[idx])\n\
    \        if (lo <= x && x < hi) ++cnt, s += x;\n    }\n    return {cnt, s};\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/my_multiset.hpp
  requiredBy: []
  timestamp: '2023-05-20 05:12:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc241d.test.cpp
  - test_atcoder/abc281e.test.cpp
documentation_of: ds/my_multiset.hpp
layout: document
redirect_from:
- /library/ds/my_multiset.hpp
- /library/ds/my_multiset.hpp.html
title: ds/my_multiset.hpp
---
