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
  bundledCode: "#line 1 \"template/sqrt_decomposition.hpp\"\n// template/sqrt_decomposition.hpp\n\
    struct Block {\n  int N, off;\n  vc<int> A;\n\n  Block(vc<int>& B, int L, int\
    \ R) : N(R - L), off(L) {\n    A = {B.begin() + L, B.begin() + R};\n  }\n\n  void\
    \ apply(int l, int r, int x) {\n    l -= off, r -= off;\n    chmax(l, 0), chmin(r,\
    \ N);\n    if (l >= r) return;  // l==r \u3068\u3057\u306A\u3044\u3088\u3046\u306B\
    \n    if (r - l != N) {\n    }\n    assert(r - l == N);\n  }\n\n  int query(int\
    \ l, int r) {\n    l -= off, r -= off;\n    chmax(l, 0), chmin(r, N);\n    if\
    \ (l >= r) return 0;  // l==r \u3068\u3057\u306A\u3044\u3088\u3046\u306B\n   \
    \ if (r - l == N) {\n    }\n    FOR(i, l, r) {}\n  }\n};\n\n// void solve() {\n\
    //   int b_sz = sqrt(N);\n//   int b_num = ceil<int>(N, b_sz);\n//   vc<Block>\
    \ BLOCK;\n//   FOR(b, b_num) {\n//     int L = b_sz * b;\n//     int R = min<int>(L\
    \ + b_sz, N);\n//     BLOCK.eb(Block(A, L, R));\n//   }\n// }\n"
  code: "// template/sqrt_decomposition.hpp\nstruct Block {\n  int N, off;\n  vc<int>\
    \ A;\n\n  Block(vc<int>& B, int L, int R) : N(R - L), off(L) {\n    A = {B.begin()\
    \ + L, B.begin() + R};\n  }\n\n  void apply(int l, int r, int x) {\n    l -= off,\
    \ r -= off;\n    chmax(l, 0), chmin(r, N);\n    if (l >= r) return;  // l==r \u3068\
    \u3057\u306A\u3044\u3088\u3046\u306B\n    if (r - l != N) {\n    }\n    assert(r\
    \ - l == N);\n  }\n\n  int query(int l, int r) {\n    l -= off, r -= off;\n  \
    \  chmax(l, 0), chmin(r, N);\n    if (l >= r) return 0;  // l==r \u3068\u3057\u306A\
    \u3044\u3088\u3046\u306B\n    if (r - l == N) {\n    }\n    FOR(i, l, r) {}\n\
    \  }\n};\n\n// void solve() {\n//   int b_sz = sqrt(N);\n//   int b_num = ceil<int>(N,\
    \ b_sz);\n//   vc<Block> BLOCK;\n//   FOR(b, b_num) {\n//     int L = b_sz * b;\n\
    //     int R = min<int>(L + b_sz, N);\n//     BLOCK.eb(Block(A, L, R));\n//  \
    \ }\n// }\n"
  dependsOn: []
  isVerificationFile: false
  path: template/sqrt_decomposition.hpp
  requiredBy: []
  timestamp: '2026-08-13 00:28:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/sqrt_decomposition.hpp
layout: document
redirect_from:
- /library/template/sqrt_decomposition.hpp
- /library/template/sqrt_decomposition.hpp.html
title: template/sqrt_decomposition.hpp
---
