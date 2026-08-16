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
    - https://arxiv.org/pdf/2312.11873
    - https://uoj.ac/problem/697
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/rollinghash.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"ds/hashmap.hpp\"\n#include \"seq/cartesian_tree.hpp\"\n#include\
    \ \"string/rollinghash.hpp\"\n#include \"string/suffix_array.hpp\"\n\n// https://arxiv.org/pdf/2312.11873\n\
    // https://uoj.ac/problem/697\nstruct Basic_Substring_Structure {\n  using SA_t\
    \ = Suffix_Array<false>;\n  int N;\n  string S, T; // T = rev(S)\n  RollingHash\
    \ RH;\n  vc<decltype(RH)::mint> SH;\n  SA_t S_SA, T_SA;\n  HashMap<int> hash_to_col;\n\
    \n  /*\n  block \u3092 diagonal \u306B\u914D\u7F6E\u3057\u305F\u9577\u65B9\u5F62\
    \u3092\u4F5C\u308B\u611F\u3058\u306B\u3059\u308B.\n  X, Y: i \u756A\u76EE\u306E\
    \ block \u304C [X[i],X[i+1]) x [Y[i],Y[i+1]) \u306B\u306A\u308B.\n  X_to_block,\
    \ Y_to_block: \u884C\u756A\u53F7\u3084\u5217\u756A\u53F7\u306B\u5BFE\u5FDC\u3059\
    \u308B block.\n  width, height: \u884C\u306E\u5E45, \u5217\u306E\u9AD8\u3055.\
    \ [X[i],X[i]+width[i]) \u306A\u3069.\n  right: \u884C\u304D\u5148\u306E\u884C\n\
    \  down: \u884C\u304D\u5148\u306E\u5217\n  */\n\n  // topological \u9006\u9806\
    \ (\u6700\u5F8C\u306B S[0,N) \u304C\u6765\u308B)\n  vc<pair<int, int>> raw_index;\
    \ // \u5404 block \u306E\u4EE3\u8868\u5143\u306B\u5BFE\u5FDC\u3059\u308B [i,j]\n\
    \  vc<int> X, Y;\n  vc<int> X_to_block, Y_to_block;\n  vc<int> width, height;\n\
    \  vc<int> right, down;\n\n  int n_block() { return len(raw_index); }\n  pair<int,\
    \ int> shape() { return {X.back(), Y.back()}; }\n\n  Basic_Substring_Structure(string\
    \ &S) { build(S); }\n\n  void build(string &S_) {\n    S = S_, T = {S_.rbegin(),\
    \ S_.rend()};\n    SH = RH.build(S);\n    S_SA = SA_t(S), T_SA = SA_t(T);\n  \
    \  S_SA.seg.build(S_SA.LCP), S_SA.build_seg = true;\n    T_SA.seg.build(T_SA.LCP),\
    \ T_SA.build_seg = true;\n    N = len(S);\n    if (N == 1) {\n      raw_index\
    \ = {{0, 0}}, X = {0, 1}, Y = {0, 1}, X_to_block = {0},\n      Y_to_block = {0};\n\
    \      width = {1}, height = {1}, right = {-1}, down = {-1};\n      return;\n\
    \    }\n    X_to_block.reserve(2 * N - 1), Y_to_block.reserve(2 * N - 1);\n  \
    \  width.reserve(2 * N - 1), height.reserve(2 * N - 1);\n    right.reserve(2 *\
    \ N - 1), down.reserve(2 * N - 1);\n    X = {0}, Y = {0};\n\n    CartesianTree<int,\
    \ true> CS(S_SA.LCP);\n    CartesianTree<int, true> CT(T_SA.LCP);\n    hash_to_col.build(N\
    \ - 1);\n    HashMap<int> hash_to_row(N - 1);\n\n    auto is_node = [&](CartesianTree<int,\
    \ true> &CT, int i) -> bool {\n      return (CT.A[i] > 0 && (CT.par[i] == -1 ||\
    \ CT.A[CT.par[i]] != CT.A[i]));\n    };\n\n    // \u5217\u306E\u5148\u982D\u306B\
    \u76F8\u5F53\u3059\u308B\u30CF\u30C3\u30B7\u30E5\u3092\u96C6\u3081\u3066\u304A\
    \u304F\n    HashMap<int> tmp(N - 1);\n    FOR(i, N - 1) {\n      if (!is_node(CS,\
    \ i))\n        continue;\n      int s = S_SA.SA[i], n = S_SA.LCP[i];\n      tmp[RH.query(SH,\
    \ s, s + n).val] = i;\n    }\n\n    // occur \u304C\u5C0F\u3055\u3044\u884C\u304B\
    \u3089\u4F5C\u3063\u3066\u3044\u304F\n    vc<int> ptr(N);\n    FOR(i, N - 1) {\n\
    \      if (is_node(CT, i))\n        ptr[CT.range[i].se - CT.range[i].fi]++;\n\
    \    }\n    ptr = cumsum<int>(ptr);\n    vc<int> I(ptr.back(), -1);\n    FOR(i,\
    \ N - 1) {\n      if (!is_node(CT, i))\n        continue;\n      int occ = CT.range[i].se\
    \ - CT.range[i].fi;\n      I[ptr[occ]++] = i;\n    }\n\n    auto new_block = [&](int\
    \ h, int w, int i, int j) -> int {\n      int bid = len(raw_index);\n      raw_index.eb(i,\
    \ j);\n      X.eb(X.back() + h), Y.eb(Y.back() + w);\n      FOR(h) X_to_block.eb(bid),\
    \ width.eb(-1), right.eb(-1);\n      FOR(w) Y_to_block.eb(bid), height.eb(-1),\
    \ down.eb(-1);\n      return bid;\n    };\n\n    auto get_w = [&](int i) -> int\
    \ {\n      return CT.A[i] - (CT.par[i] == -1 ? 0 : CT.A[CT.par[i]]);\n    };\n\
    \    auto get_h = [&](int i) -> int {\n      return CS.A[i] - (CS.par[i] == -1\
    \ ? 0 : CS.A[CS.par[i]]);\n    };\n\n    reverse(all(I));\n    for (int a0 : I)\
    \ {\n      int j = N - T_SA.SA[a0], n = T_SA.LCP[a0];\n      u64 key = RH.query(SH,\
    \ j - n, j).val;\n      int b0 = tmp.get(key, -1);\n      if (b0 == -1)\n    \
    \    continue;\n      // occur>=2 \u306B\u5BFE\u5FDC\u3059\u308B block \u767A\u898B\
    \n      int h = get_h(b0), w = get_w(a0);\n      int bid = new_block(h, w, j -\
    \ n, j);\n      FOR(x, X[bid], X[bid + 1]) {\n        hash_to_row[RH.query(SH,\
    \ j - n, j - (x - X[bid])).val] = x;\n      }\n      FOR(y, Y[bid], Y[bid + 1])\
    \ {\n        hash_to_col[RH.query(SH, j - n + (y - Y[bid]), j).val] = y;\n   \
    \   }\n    }\n    FOR(i, N - 1) {\n      if (!is_node(CT, i))\n        continue;\n\
    \      int r = N - T_SA.SA[i], n = T_SA.LCP[i];\n      u64 key = RH.query(SH,\
    \ r - n, r).val;\n      int x = hash_to_row[key];\n      width[x] = get_w(i);\n\
    \      right[x] = hash_to_row.get(RH.query(SH, r - n + width[x], r).val, -1);\n\
    \    }\n    FOR(i, N - 1) {\n      if (!is_node(CS, i))\n        continue;\n \
    \     int l = S_SA.SA[i], n = S_SA.LCP[i];\n      u64 key = RH.query(SH, l, l\
    \ + n).val;\n      int y = hash_to_col[key];\n      height[y] = get_h(i);\n  \
    \    down[y] = hash_to_col.get(RH.query(SH, l, l + n - height[y]).val, -1);\n\
    \    }\n\n    // occur==1\n    auto get_w2 = [&](int i) -> int { // [0,i)\n  \
    \    int k = T_SA.ISA[N - i];\n      int n = i, m = 0;\n      if (k > 0)\n   \
    \     chmax(m, T_SA.LCP[k - 1]);\n      if (k < N - 1)\n        chmax(m, T_SA.LCP[k]);\n\
    \      return n - m;\n    };\n    auto get_h2 = [&](int i) -> int { // [i,N)\n\
    \      int k = S_SA.ISA[i];\n      int n = N - i, m = 0;\n      if (k > 0)\n \
    \       chmax(m, S_SA.LCP[k - 1]);\n      if (k < N - 1)\n        chmax(m, S_SA.LCP[k]);\n\
    \      return n - m;\n    };\n    int h = get_h2(0), w = get_w2(N);\n    int bid\
    \ = new_block(h, w, 0, N);\n    FOR(x, X[bid], X[bid + 1]) {\n      int r = N\
    \ - (x - X[bid]);\n      width[x] = get_w2(r);\n      right[x] = hash_to_row.get(RH.query(SH,\
    \ width[x], r).val, -1);\n    }\n    FOR(y, Y[bid], Y[bid + 1]) {\n      int l\
    \ = y - Y[bid];\n      height[y] = get_h2(l);\n      down[y] = hash_to_col.get(RH.query(SH,\
    \ l, N - height[y]).val, -1);\n    }\n  }\n\n  // S[i,j) \u306B\u5BFE\u5FDC\u3059\
    \u308B (x,y).\n  pair<int, int> get_position(int i, int j) {\n    // occur \u3092\
    \u4FDD\u3063\u3066\u9577\u304F\u3059\u308B\n    auto &seg = S_SA.seg;\n    int\
    \ n = j - i, k = S_SA.ISA[i];\n    int m = N - i;\n    auto check = [&](int e)\
    \ -> bool {\n      if (e >= n)\n        chmin(m, e);\n      return e >= n;\n \
    \   };\n    seg.min_left(check, k), seg.max_right(check, k);\n    int y = hash_to_col.get(RH.query(SH,\
    \ i, i + m).val, -1);\n    if (y == -1) {\n      assert(i + m == N);\n      int\
    \ x = X[n_block() - 1] + (N - j), y = Y[n_block() - 1] + i;\n      return {x,\
    \ y};\n    }\n    int bid = Y_to_block[y];\n    auto [l, r] = raw_index[bid];\n\
    \    int x = (X[bid] + Y[bid]) + ((r - l) - (j - i)) - y;\n    return {x, y};\n\
    \  }\n\n  void debug() {\n    auto [H, W] = shape();\n    FOR(x, H) {\n      string\
    \ tmp(W, '.');\n      int k = X_to_block[x];\n      FOR(y, Y[k], Y[k] + width[x])\
    \ tmp[y] = '#';\n      print(tmp);\n    }\n    SHOW(S);\n    SHOW(raw_index);\n\
    \    SHOW(width);\n    SHOW(height);\n    SHOW(right);\n    SHOW(down);\n    print();\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/basic_substring_structure.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/basic_substring_structure.hpp
layout: document
redirect_from:
- /library/string/basic_substring_structure.hpp
- /library/string/basic_substring_structure.hpp.html
title: string/basic_substring_structure.hpp
---
