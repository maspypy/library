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
  bundledCode: "#line 1 \"matroid/partition_matroid.hpp\"\n\nstruct Partition_Matroid\
    \ {\n  int N, C;\n  vc<int> color, cap, cnt;\n  vc<int> IDS, indptr;\n  Partition_Matroid(vc<int>\
    \ color, vc<int> capacity)\n      : color(color), cap(capacity) {\n    N = len(color);\n\
    \    C = len(capacity);\n    indptr.resize(C + 1);\n    FOR(i, N) indptr[color[i]\
    \ + 1]++;\n    FOR(i, C) indptr[i + 1] += indptr[i];\n    IDS.resize(N);\n   \
    \ FOR(i, N) IDS[indptr[color[i]]++] = i;\n    FOR_R(i, 1, C) indptr[i] = indptr[i\
    \ - 1];\n    indptr[0] = 0;\n  }\n\n  int size() { return N; }\n\n  const vc<bool>\
    \ *I = nullptr;\n  void prepare(const vc<bool> &_I) {\n    I = &_I;\n    cnt.assign(C,\
    \ 0);\n    FOR(i, N) cnt[color[i]] += (*I)[i];\n  }\n\n  bool can_add(int i) {\
    \ return cnt[color[i]] < cap[color[i]]; }\n\n  // i \u3092\u524A\u9664\u3057\u3066\
    \ j \u3092\u8FFD\u52A0\n  template <typename F>\n  void for_rm_add(int i, F &&f)\
    \ const {\n    assert((*I)[i]);\n    int c = color[i];\n    if (cnt[c] < cap[c])\
    \ return;\n    FOR(k, indptr[c], indptr[c + 1]) {\n      int j = IDS[k];\n   \
    \   if (!(*I)[j]) f(j);\n    }\n  }\n};\n"
  code: "\nstruct Partition_Matroid {\n  int N, C;\n  vc<int> color, cap, cnt;\n \
    \ vc<int> IDS, indptr;\n  Partition_Matroid(vc<int> color, vc<int> capacity)\n\
    \      : color(color), cap(capacity) {\n    N = len(color);\n    C = len(capacity);\n\
    \    indptr.resize(C + 1);\n    FOR(i, N) indptr[color[i] + 1]++;\n    FOR(i,\
    \ C) indptr[i + 1] += indptr[i];\n    IDS.resize(N);\n    FOR(i, N) IDS[indptr[color[i]]++]\
    \ = i;\n    FOR_R(i, 1, C) indptr[i] = indptr[i - 1];\n    indptr[0] = 0;\n  }\n\
    \n  int size() { return N; }\n\n  const vc<bool> *I = nullptr;\n  void prepare(const\
    \ vc<bool> &_I) {\n    I = &_I;\n    cnt.assign(C, 0);\n    FOR(i, N) cnt[color[i]]\
    \ += (*I)[i];\n  }\n\n  bool can_add(int i) { return cnt[color[i]] < cap[color[i]];\
    \ }\n\n  // i \u3092\u524A\u9664\u3057\u3066 j \u3092\u8FFD\u52A0\n  template\
    \ <typename F>\n  void for_rm_add(int i, F &&f) const {\n    assert((*I)[i]);\n\
    \    int c = color[i];\n    if (cnt[c] < cap[c]) return;\n    FOR(k, indptr[c],\
    \ indptr[c + 1]) {\n      int j = IDS[k];\n      if (!(*I)[j]) f(j);\n    }\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: matroid/partition_matroid.hpp
  requiredBy: []
  timestamp: '2025-10-13 18:56:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matroid/partition_matroid.hpp
layout: document
redirect_from:
- /library/matroid/partition_matroid.hpp
- /library/matroid/partition_matroid.hpp.html
title: matroid/partition_matroid.hpp
---
