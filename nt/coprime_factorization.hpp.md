---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: nt/crt.hpp
    title: nt/crt.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/coprime_factorization.test.cpp
    title: test/mytest/coprime_factorization.test.cpp
  - icon: ':x:'
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1956.test.cpp
    title: test/yukicoder/1956.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2119.test.cpp
    title: test/yukicoder/2119.test.cpp
  - icon: ':x:'
    path: test/yukicoder/590.test.cpp
    title: test/yukicoder/590.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/coprime_factorization.hpp\"\n\n/*\n\u4E92\u3044\u306B\
    \u7D20\u306A\u6574\u6570 p1, p2, ..., pk \u3092\u7528\u3044\u3066 n_i = prod p_i^e_i\
    \ \u3068\u8868\u3059.\n[21,60,140,400]\n[3,7,20], [[(0,1),(1,1)],[(0,1),(2,1)],[(1,1),(2,1)],[(2,2)]]\n\
    */\ntemplate <typename T>\npair<vc<T>, vvc<pair<int, int>>> coprime_factorization(vc<T>\
    \ nums) {\n  vc<T> basis;\n  for (T val: nums) {\n    vc<T> new_basis;\n    for\
    \ (T x: basis) {\n      if (val == 1) {\n        new_basis.eb(x);\n        continue;\n\
    \      }\n      vc<T> dat = {val, x};\n      FOR(p, 1, len(dat)) {\n        FOR(i,\
    \ p) {\n          while (1) {\n            if (dat[p] > 1 && dat[i] % dat[p] ==\
    \ 0) dat[i] /= dat[p];\n            elif (dat[i] > 1 && dat[p] % dat[i] == 0)\
    \ dat[p] /= dat[i];\n            else break;\n          }\n          T g = gcd(dat[i],\
    \ dat[p]);\n          if (g == 1 || g == dat[i] || g == dat[p]) continue;\n  \
    \        dat[i] /= g, dat[p] /= g, dat.eb(g);\n        }\n      }\n      val =\
    \ dat[0];\n      FOR(i, 1, len(dat)) if (dat[i] != 1) new_basis.eb(dat[i]);\n\
    \    }\n    if (val > 1) new_basis.eb(val);\n    swap(basis, new_basis);\n  }\n\
    \n  sort(all(basis));\n\n  vvc<pair<int, int>> res(len(nums));\n  FOR(i, len(nums))\
    \ {\n    T x = nums[i];\n    FOR(j, len(basis)) {\n      int e = 0;\n      while\
    \ (x % basis[j] == 0) x /= basis[j], ++e;\n      if (e) res[i].eb(j, e);\n   \
    \ }\n  }\n  return {basis, res};\n}\n"
  code: "\n/*\n\u4E92\u3044\u306B\u7D20\u306A\u6574\u6570 p1, p2, ..., pk \u3092\u7528\
    \u3044\u3066 n_i = prod p_i^e_i \u3068\u8868\u3059.\n[21,60,140,400]\n[3,7,20],\
    \ [[(0,1),(1,1)],[(0,1),(2,1)],[(1,1),(2,1)],[(2,2)]]\n*/\ntemplate <typename\
    \ T>\npair<vc<T>, vvc<pair<int, int>>> coprime_factorization(vc<T> nums) {\n \
    \ vc<T> basis;\n  for (T val: nums) {\n    vc<T> new_basis;\n    for (T x: basis)\
    \ {\n      if (val == 1) {\n        new_basis.eb(x);\n        continue;\n    \
    \  }\n      vc<T> dat = {val, x};\n      FOR(p, 1, len(dat)) {\n        FOR(i,\
    \ p) {\n          while (1) {\n            if (dat[p] > 1 && dat[i] % dat[p] ==\
    \ 0) dat[i] /= dat[p];\n            elif (dat[i] > 1 && dat[p] % dat[i] == 0)\
    \ dat[p] /= dat[i];\n            else break;\n          }\n          T g = gcd(dat[i],\
    \ dat[p]);\n          if (g == 1 || g == dat[i] || g == dat[p]) continue;\n  \
    \        dat[i] /= g, dat[p] /= g, dat.eb(g);\n        }\n      }\n      val =\
    \ dat[0];\n      FOR(i, 1, len(dat)) if (dat[i] != 1) new_basis.eb(dat[i]);\n\
    \    }\n    if (val > 1) new_basis.eb(val);\n    swap(basis, new_basis);\n  }\n\
    \n  sort(all(basis));\n\n  vvc<pair<int, int>> res(len(nums));\n  FOR(i, len(nums))\
    \ {\n    T x = nums[i];\n    FOR(j, len(basis)) {\n      int e = 0;\n      while\
    \ (x % basis[j] == 0) x /= basis[j], ++e;\n      if (e) res[i].eb(j, e);\n   \
    \ }\n  }\n  return {basis, res};\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/coprime_factorization.hpp
  requiredBy:
  - nt/crt.hpp
  timestamp: '2023-08-20 12:39:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2119.test.cpp
  - test/yukicoder/187.test.cpp
  - test/yukicoder/590.test.cpp
  - test/yukicoder/1956.test.cpp
  - test/mytest/coprime_factorization.test.cpp
documentation_of: nt/coprime_factorization.hpp
layout: document
redirect_from:
- /library/nt/coprime_factorization.hpp
- /library/nt/coprime_factorization.hpp.html
title: nt/coprime_factorization.hpp
---
