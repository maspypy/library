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
    - https://cyanmond.hatenablog.com/entry/2023/08/07/163326
  bundledCode: "#line 1 \"convex/monge_lichao_tree.hpp\"\n\n// https://cyanmond.hatenablog.com/entry/2023/08/07/163326\n\
    // F f: f(fid,x)\ntemplate <typename T, bool MINIMIZE, typename F>\nstruct Monge_LiChao_Tree\
    \ {\n  int n, log, size;\n  F f;\n  vc<int> FID;\n\n  Monge_LiChao_Tree(int n,\
    \ F f) : n(n), f(f) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    FID.assign(size << 1, -1);\n  }\n\n  void add_line(int fid)\
    \ { return add_line_at(1, fid); }\n  void add_segment(int L, int R, int fid) {\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) add_line_at(L++,\
    \ fid);\n      if (R & 1) add_line_at(--R, fid);\n      L >>= 1, R >>= 1;\n  \
    \  }\n  }\n\n  // [fx, fid]\n  pair<T, int> query(int x) {\n    int i = x + size;\n\
    \    pair<T, int> res;\n    if (!MINIMIZE) res = {-infty<T>, -1};\n    if (MINIMIZE)\
    \ res = {infty<T>, -1};\n    while (i) {\n      pair<T, int> res1 = {evaluate(FID[i],\
    \ x), FID[i]};\n      res = (MINIMIZE ? min(res, res1) : max(res, res1));\n  \
    \    i >>= 1;\n    }\n    return res;\n  }\n\nprivate:\n  void add_line_at(int\
    \ i, int fid) {\n    int upper_bit = 31 - __builtin_clz(i);\n    int l = (size\
    \ >> upper_bit) * (i - (1 << upper_bit));\n    int r = l + (size >> upper_bit);\n\
    \    while (l < r) {\n      int gid = FID[i];\n      T fl = evaluate(fid, l),\
    \ fr = evaluate(fid, r - 1);\n      T gl = evaluate(gid, l), gr = evaluate(gid,\
    \ r - 1);\n      bool bl = (MINIMIZE ? fl < gl : fl > gl);\n      bool br = (MINIMIZE\
    \ ? fr < gr : fr > gr);\n      if (bl && br) {\n        FID[i] = fid;\n      \
    \  return;\n      }\n      if (!bl && !br) return;\n      int m = (l + r) / 2;\n\
    \      T fm = evaluate(fid, m), gm = evaluate(gid, m);\n      bool bm = (MINIMIZE\
    \ ? fm < gm : fm > gm);\n      if (bm) {\n        FID[i] = fid;\n        fid =\
    \ gid;\n        if (!bl) { i = 2 * i + 0, r = m; }\n        if (bl) { i = 2 *\
    \ i + 1, l = m; }\n      }\n      if (!bm) {\n        if (bl) { i = 2 * i + 0,\
    \ r = m; }\n        if (!bl) { i = 2 * i + 1, l = m; }\n      }\n    }\n  }\n\n\
    \  T evaluate(int fid, int x) {\n    if (fid == -1) return (MINIMIZE ? infty<T>\
    \ : -infty<T>);\n    chmin(x, n - 1);\n    return f(fid, x);\n  }\n};\n"
  code: "\n// https://cyanmond.hatenablog.com/entry/2023/08/07/163326\n// F f: f(fid,x)\n\
    template <typename T, bool MINIMIZE, typename F>\nstruct Monge_LiChao_Tree {\n\
    \  int n, log, size;\n  F f;\n  vc<int> FID;\n\n  Monge_LiChao_Tree(int n, F f)\
    \ : n(n), f(f) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size =\
    \ 1 << log;\n    FID.assign(size << 1, -1);\n  }\n\n  void add_line(int fid) {\
    \ return add_line_at(1, fid); }\n  void add_segment(int L, int R, int fid) {\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) add_line_at(L++,\
    \ fid);\n      if (R & 1) add_line_at(--R, fid);\n      L >>= 1, R >>= 1;\n  \
    \  }\n  }\n\n  // [fx, fid]\n  pair<T, int> query(int x) {\n    int i = x + size;\n\
    \    pair<T, int> res;\n    if (!MINIMIZE) res = {-infty<T>, -1};\n    if (MINIMIZE)\
    \ res = {infty<T>, -1};\n    while (i) {\n      pair<T, int> res1 = {evaluate(FID[i],\
    \ x), FID[i]};\n      res = (MINIMIZE ? min(res, res1) : max(res, res1));\n  \
    \    i >>= 1;\n    }\n    return res;\n  }\n\nprivate:\n  void add_line_at(int\
    \ i, int fid) {\n    int upper_bit = 31 - __builtin_clz(i);\n    int l = (size\
    \ >> upper_bit) * (i - (1 << upper_bit));\n    int r = l + (size >> upper_bit);\n\
    \    while (l < r) {\n      int gid = FID[i];\n      T fl = evaluate(fid, l),\
    \ fr = evaluate(fid, r - 1);\n      T gl = evaluate(gid, l), gr = evaluate(gid,\
    \ r - 1);\n      bool bl = (MINIMIZE ? fl < gl : fl > gl);\n      bool br = (MINIMIZE\
    \ ? fr < gr : fr > gr);\n      if (bl && br) {\n        FID[i] = fid;\n      \
    \  return;\n      }\n      if (!bl && !br) return;\n      int m = (l + r) / 2;\n\
    \      T fm = evaluate(fid, m), gm = evaluate(gid, m);\n      bool bm = (MINIMIZE\
    \ ? fm < gm : fm > gm);\n      if (bm) {\n        FID[i] = fid;\n        fid =\
    \ gid;\n        if (!bl) { i = 2 * i + 0, r = m; }\n        if (bl) { i = 2 *\
    \ i + 1, l = m; }\n      }\n      if (!bm) {\n        if (bl) { i = 2 * i + 0,\
    \ r = m; }\n        if (!bl) { i = 2 * i + 1, l = m; }\n      }\n    }\n  }\n\n\
    \  T evaluate(int fid, int x) {\n    if (fid == -1) return (MINIMIZE ? infty<T>\
    \ : -infty<T>);\n    chmin(x, n - 1);\n    return f(fid, x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: convex/monge_lichao_tree.hpp
  requiredBy: []
  timestamp: '2023-11-02 17:52:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge_lichao_tree.hpp
layout: document
redirect_from:
- /library/convex/monge_lichao_tree.hpp
- /library/convex/monge_lichao_tree.hpp.html
title: convex/monge_lichao_tree.hpp
---
