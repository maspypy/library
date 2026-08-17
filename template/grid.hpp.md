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
  bundledCode: "#line 1 \"template/grid.hpp\"\n// template/grid.hpp\nauto isin = [&](int\
    \ x, int y) -> bool {\n  return (0 <= x && x < H && 0 <= y && y < W);\n};\nint\
    \ dx[] = {1, 0, -1, 0, 1, 1, -1, -1};\nint dy[] = {0, 1, 0, -1, 1, -1, 1, -1};\n\
    auto idx = [&](int x, int y) -> int { return W * x + y; };\n"
  code: "// template/grid.hpp\nauto isin = [&](int x, int y) -> bool {\n  return (0\
    \ <= x && x < H && 0 <= y && y < W);\n};\nint dx[] = {1, 0, -1, 0, 1, 1, -1, -1};\n\
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};\nauto idx = [&](int x, int y) -> int {\
    \ return W * x + y; };"
  dependsOn: []
  isVerificationFile: false
  path: template/grid.hpp
  requiredBy: []
  timestamp: '2026-08-17 09:25:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/grid.hpp
layout: document
redirect_from:
- /library/template/grid.hpp
- /library/template/grid.hpp.html
title: template/grid.hpp
---
