---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/csr.hpp
    title: ds/csr.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/EGZ.test.cpp
    title: test/1_mytest/EGZ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/csr.hpp\"\n\ntemplate <typename T>\nstruct CSR {\n  int\
    \ n;\n  bool prepared;\n  vc<int> ptr;\n  vc<int> I;\n  vc<T> dat;\n\n  CSR(int\
    \ n = 0) : n(n), prepared(false) {}\n  void reserve(int n) { dat.reserve(n); }\n\
    \n  void add(int i, const T& x) {\n    assert(0 <= i && i < n && !prepared);\n\
    \    I.eb(i), dat.eb(x);\n  }\n\n  void build() {\n    assert(!prepared);\n  \
    \  prepared = 1;\n    ptr.assign(n + 1, 0);\n    for (auto& i : I) ptr[1 + i]++;\n\
    \    FOR(i, len(ptr) - 1) ptr[i + 1] += ptr[i];\n    vc<T> tmp(len(dat));\n  \
    \  FOR(k, len(dat)) {\n      int i = I[k];\n      tmp[ptr[i]++] = dat[k];\n  \
    \  }\n    swap(dat, tmp);\n    ptr.pop_back();\n    ptr.insert(ptr.begin(), 0);\n\
    \    I.clear();\n  }\n\n  struct range {\n    T *first, *last;\n    T* begin()\
    \ const { return first; }\n    T* end() const { return last; }\n    bool empty()\
    \ const { return first == last; }\n    int size() const { return last - first;\
    \ }\n  };\n\n  range operator[](int i) {\n    assert(prepared);\n    return range{dat.data()\
    \ + ptr[i], dat.data() + ptr[i + 1]};\n  }\n};\n#line 1 \"mod/mod_inv.hpp\"\n\n\
    // long \u3067\u3082\u5927\u4E08\u592B\n// (val * x - 1) \u304C mod \u306E\u500D\
    \u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n// \u7279\u306B mod=0\
    \ \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll val, ll mod) {\n  if\
    \ (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n  if (val < 0) val +=\
    \ mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while (b > 0) {\n    t = a\
    \ / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n  }\n  if (u < 0) u +=\
    \ mod;\n  return u;\n}\n#line 3 \"nt/EGZ.hpp\"\n\n// p-subset \u3067\u7DCF\u548C\
    \u304C 0 mod p \u306E\u3082\u306E\u3092\u4F5C\u308B\n// return: indices\nvc<int>\
    \ EGZ_prime(int p, vc<ll> A) {\n  assert(len(A) == p + p - 1);\n  for (auto& x\
    \ : A) x = bmod<ll>(x, p);\n  CSR<int> ids(p);\n  FOR(i, len(A)) { ids.add(A[i],\
    \ i); }\n  ids.build();\n\n  A.clear();\n  FOR(x, p) FOR(len(ids[x])) A.eb(x);\n\
    \n  [&]() -> void {\n    FOR(i, p) {\n      if (A[i] == A[i + p - 1]) {\n    \
    \    A = {A.begin() + i, A.begin() + i + p};\n        return;\n      }\n    }\n\
    \    int t = 0;\n    FOR(i, p) t = (t + p - A[i]) % p;\n    vc<int> par(p, -1);\n\
    \    auto exist = [&](int i) -> bool { return (i == 0 || par[i] != -1); };\n \
    \   FOR(i, p - 1) {\n      if (exist(t)) break;\n      int d = A[i + p] - A[i];\n\
    \      ll L = 0, R = mod_inv(d, p) * t % p;\n      while (L + 1 < R) {\n     \
    \   ll M = (L + R) / 2;\n        (exist(M * d % p) ? L : R) = M;\n      }\n  \
    \    par[R * d % p] = i;\n    }\n    while (t != 0) {\n      int i = par[t];\n\
    \      int d = A[i + p] - A[i];\n      t = (t + p - d) % p;\n      A[i] = A[i\
    \ + p];\n    }\n    A.resize(p);\n  }();\n  vc<int> CNT(p);\n  for (auto& x :\
    \ A) CNT[x]++;\n  vc<int> res;\n  FOR(x, p) {\n    for (int i : ids[x]) {\n  \
    \    if (CNT[x]) --CNT[x], res.eb(i);\n    }\n  }\n  return res;\n}\n\n// N-subset\
    \ \u3067\u7DCF\u548C\u304C 0 mod p \u306E\u3082\u306E\u3092\u4F5C\u308B\n// return:\
    \ indices\nvc<int> EGZ(int N, vc<ll> A) {\n  for (auto& x : A) x = bmod<ll>(x,\
    \ N);\n  assert(len(A) == 2 * N - 1);\n  if (N == 1) return {0};\n  int p = 2;\n\
    \  while (N % p != 0) ++p;\n  if (N == p) return EGZ_prime(N, A);\n\n  // p is\
    \ a prime factor\n  int M = N / p;\n  vc<int> ids;\n  vc<int> yet;\n  vi nxt_val;\n\
    \  int k = 0;\n  // p-EGZ * (2M-1)\n  vc<int> used(2 * p - 1);\n  FOR(2 * M -\
    \ 1) {\n    while (len(yet) < 2 * p - 1) {\n      yet.eb(k++);\n    }\n    vc<ll>\
    \ B = rearrange(A, yet);\n    vc<int> way = EGZ_prime(p, B);\n    FOR(i, 2 * p\
    \ - 1) used[i] = 0;\n    for (int i : way) used[i] = 1;\n    vc<int> nxt;\n  \
    \  ll x = 0;\n    FOR(i, 2 * p - 1) {\n      if (used[i]) {\n        x += A[yet[i]];\n\
    \        ids.eb(yet[i]);\n      } else {\n        nxt.eb(yet[i]);\n      }\n \
    \   }\n    swap(yet, nxt);\n    assert(x % p == 0);\n    nxt_val.eb(x / p);\n\
    \  }\n  vc<int> I = EGZ(M, nxt_val);\n  vc<int> res;\n  for (int i : I) {\n  \
    \  FOR(j, p * i, p * i + p) res.eb(ids[j]);\n  }\n  return res;\n}\n"
  code: "#include \"ds/csr.hpp\"\n#include \"mod/mod_inv.hpp\"\n\n// p-subset \u3067\
    \u7DCF\u548C\u304C 0 mod p \u306E\u3082\u306E\u3092\u4F5C\u308B\n// return: indices\n\
    vc<int> EGZ_prime(int p, vc<ll> A) {\n  assert(len(A) == p + p - 1);\n  for (auto&\
    \ x : A) x = bmod<ll>(x, p);\n  CSR<int> ids(p);\n  FOR(i, len(A)) { ids.add(A[i],\
    \ i); }\n  ids.build();\n\n  A.clear();\n  FOR(x, p) FOR(len(ids[x])) A.eb(x);\n\
    \n  [&]() -> void {\n    FOR(i, p) {\n      if (A[i] == A[i + p - 1]) {\n    \
    \    A = {A.begin() + i, A.begin() + i + p};\n        return;\n      }\n    }\n\
    \    int t = 0;\n    FOR(i, p) t = (t + p - A[i]) % p;\n    vc<int> par(p, -1);\n\
    \    auto exist = [&](int i) -> bool { return (i == 0 || par[i] != -1); };\n \
    \   FOR(i, p - 1) {\n      if (exist(t)) break;\n      int d = A[i + p] - A[i];\n\
    \      ll L = 0, R = mod_inv(d, p) * t % p;\n      while (L + 1 < R) {\n     \
    \   ll M = (L + R) / 2;\n        (exist(M * d % p) ? L : R) = M;\n      }\n  \
    \    par[R * d % p] = i;\n    }\n    while (t != 0) {\n      int i = par[t];\n\
    \      int d = A[i + p] - A[i];\n      t = (t + p - d) % p;\n      A[i] = A[i\
    \ + p];\n    }\n    A.resize(p);\n  }();\n  vc<int> CNT(p);\n  for (auto& x :\
    \ A) CNT[x]++;\n  vc<int> res;\n  FOR(x, p) {\n    for (int i : ids[x]) {\n  \
    \    if (CNT[x]) --CNT[x], res.eb(i);\n    }\n  }\n  return res;\n}\n\n// N-subset\
    \ \u3067\u7DCF\u548C\u304C 0 mod p \u306E\u3082\u306E\u3092\u4F5C\u308B\n// return:\
    \ indices\nvc<int> EGZ(int N, vc<ll> A) {\n  for (auto& x : A) x = bmod<ll>(x,\
    \ N);\n  assert(len(A) == 2 * N - 1);\n  if (N == 1) return {0};\n  int p = 2;\n\
    \  while (N % p != 0) ++p;\n  if (N == p) return EGZ_prime(N, A);\n\n  // p is\
    \ a prime factor\n  int M = N / p;\n  vc<int> ids;\n  vc<int> yet;\n  vi nxt_val;\n\
    \  int k = 0;\n  // p-EGZ * (2M-1)\n  vc<int> used(2 * p - 1);\n  FOR(2 * M -\
    \ 1) {\n    while (len(yet) < 2 * p - 1) {\n      yet.eb(k++);\n    }\n    vc<ll>\
    \ B = rearrange(A, yet);\n    vc<int> way = EGZ_prime(p, B);\n    FOR(i, 2 * p\
    \ - 1) used[i] = 0;\n    for (int i : way) used[i] = 1;\n    vc<int> nxt;\n  \
    \  ll x = 0;\n    FOR(i, 2 * p - 1) {\n      if (used[i]) {\n        x += A[yet[i]];\n\
    \        ids.eb(yet[i]);\n      } else {\n        nxt.eb(yet[i]);\n      }\n \
    \   }\n    swap(yet, nxt);\n    assert(x % p == 0);\n    nxt_val.eb(x / p);\n\
    \  }\n  vc<int> I = EGZ(M, nxt_val);\n  vc<int> res;\n  for (int i : I) {\n  \
    \  FOR(j, p * i, p * i + p) res.eb(ids[j]);\n  }\n  return res;\n}"
  dependsOn:
  - ds/csr.hpp
  - mod/mod_inv.hpp
  isVerificationFile: false
  path: nt/EGZ.hpp
  requiredBy: []
  timestamp: '2026-08-31 22:36:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/EGZ.test.cpp
documentation_of: nt/EGZ.hpp
layout: document
redirect_from:
- /library/nt/EGZ.hpp
- /library/nt/EGZ.hpp.html
title: nt/EGZ.hpp
---
