---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/csr.hpp
    title: ds/csr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/134/problem/C
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
    \ + ptr[i], dat.data() + ptr[i + 1]};\n  }\n};\n#line 2 \"graph/degree_sequence.hpp\"\
    \n\n// O(N). \u5358\u7D14\u30B0\u30E9\u30D5\u306E\u5B58\u5728\u5224\u5B9A. Erdos-Gallai\
    \ \u306E\u5B9A\u7406.\nbool check_degree_sequence(vc<int> deg) {\n  int N = len(deg);\n\
    \  if (N == 0) return true;\n  ll sm = 0;\n  vc<int> freq(N, 0);\n  FOR(i, N)\
    \ {\n    int d = deg[i];\n    if (!(0 <= d && d < N)) return false;\n    freq[d]++,\
    \ sm += d;\n  }\n  if (sm & 1) return false;\n  int p = 0;\n  FOR_R(x, N) FOR(freq[x])\
    \ deg[p++] = x;\n\n  vi S = cumsum<ll>(deg);\n  ll m = 0;  // # of d_i s.t. d_i>=k\n\
    \  FOR_R(k, N + 1) {\n    while (m < N && deg[m] >= k) ++m;\n    ll lhs = S[k];\n\
    \    ll rhs = k * (k - 1);\n    if (m < k) {\n      rhs += S[N] - S[k];\n    }\
    \ else {\n      rhs += (m - k) * k;\n      rhs += S[N] - S[m];\n    }\n    if\
    \ (lhs > rhs) return false;\n  }\n  return true;\n}\n\n// O(N+M) time\n// https://codeforces.com/contest/134/problem/C\n\
    pair<bool, vc<pair<int, int>>> construct_from_degree_sequence(vc<int> deg) {\n\
    \  if (!check_degree_sequence(deg)) return {false, {}};\n  int N = len(deg);\n\
    \  CSR<int> csr(N);\n  FOR(v, N) { csr.add(deg[v], v); }\n  csr.build();\n  vc<int>\
    \ cnt(N), D(N), V(N);\n  int p = 0;\n  FOR(x, N) for (auto& v : csr[x]) cnt[x]++,\
    \ D[p] = x, V[p] = v, ++p;\n  assert(p == N);\n\n  vc<pair<int, int>> ANS;\n \
    \ vc<pair<int, int>> tmp;\n  FOR_R(idx, N) {\n    int v = V[idx], n = D[idx];\n\
    \    cnt[D[idx]] -= 1, D[idx] = 0;\n    int p = idx;  // [p,n) used\n    while\
    \ (n > 0) {\n      int d = D[p - 1];\n      int l = p - cnt[d];\n      int m =\
    \ min(n, cnt[d]);\n      for (int i = l; i < l + m; ++i) {\n        ANS.eb(V[i],\
    \ v), D[i]--;\n      }\n      tmp.eb(d, m);\n      n -= m, p = l;\n    }\n   \
    \ for (auto& [d, m] : tmp) cnt[d] -= m, cnt[d - 1] += m;\n    tmp.clear();\n \
    \ }\n  return {true, ANS};\n}\n\npair<bool, vc<pair<int, int>>> construct_from_degree_sequence_tree(\n\
    \    vc<int> deg) {\n  int N = len(deg);\n  if (SUM<ll>(deg) != N + N - 2) return\
    \ {false, {}};\n  if (N == 1) return {true, {}};\n  if (MIN(deg) == 0) return\
    \ {false, {}};\n  vc<pair<int, int>> E;\n  vc<int> X, Y;\n  FOR(v, N)(deg[v] ==\
    \ 1 ? X : Y).eb(v);\n  FOR(step, N - 1) {\n    while (len(Y) && deg[Y.back()]\
    \ <= 1) X.eb(POP(Y));\n    while (len(X) && deg[X.back()] != 1) POP(X);\n    int\
    \ v = POP(X);\n    while (len(X) && deg[X.back()] != 1) POP(X);\n    if (step\
    \ == N - 2) {\n      E.eb(v, POP(X));\n    } else {\n      int w = POP(Y);\n \
    \     E.eb(v, w);\n      deg[w]--, Y.eb(w);\n    }\n  }\n  return {true, E};\n\
    }\n"
  code: "#include \"ds/csr.hpp\"\n\n// O(N). \u5358\u7D14\u30B0\u30E9\u30D5\u306E\u5B58\
    \u5728\u5224\u5B9A. Erdos-Gallai \u306E\u5B9A\u7406.\nbool check_degree_sequence(vc<int>\
    \ deg) {\n  int N = len(deg);\n  if (N == 0) return true;\n  ll sm = 0;\n  vc<int>\
    \ freq(N, 0);\n  FOR(i, N) {\n    int d = deg[i];\n    if (!(0 <= d && d < N))\
    \ return false;\n    freq[d]++, sm += d;\n  }\n  if (sm & 1) return false;\n \
    \ int p = 0;\n  FOR_R(x, N) FOR(freq[x]) deg[p++] = x;\n\n  vi S = cumsum<ll>(deg);\n\
    \  ll m = 0;  // # of d_i s.t. d_i>=k\n  FOR_R(k, N + 1) {\n    while (m < N &&\
    \ deg[m] >= k) ++m;\n    ll lhs = S[k];\n    ll rhs = k * (k - 1);\n    if (m\
    \ < k) {\n      rhs += S[N] - S[k];\n    } else {\n      rhs += (m - k) * k;\n\
    \      rhs += S[N] - S[m];\n    }\n    if (lhs > rhs) return false;\n  }\n  return\
    \ true;\n}\n\n// O(N+M) time\n// https://codeforces.com/contest/134/problem/C\n\
    pair<bool, vc<pair<int, int>>> construct_from_degree_sequence(vc<int> deg) {\n\
    \  if (!check_degree_sequence(deg)) return {false, {}};\n  int N = len(deg);\n\
    \  CSR<int> csr(N);\n  FOR(v, N) { csr.add(deg[v], v); }\n  csr.build();\n  vc<int>\
    \ cnt(N), D(N), V(N);\n  int p = 0;\n  FOR(x, N) for (auto& v : csr[x]) cnt[x]++,\
    \ D[p] = x, V[p] = v, ++p;\n  assert(p == N);\n\n  vc<pair<int, int>> ANS;\n \
    \ vc<pair<int, int>> tmp;\n  FOR_R(idx, N) {\n    int v = V[idx], n = D[idx];\n\
    \    cnt[D[idx]] -= 1, D[idx] = 0;\n    int p = idx;  // [p,n) used\n    while\
    \ (n > 0) {\n      int d = D[p - 1];\n      int l = p - cnt[d];\n      int m =\
    \ min(n, cnt[d]);\n      for (int i = l; i < l + m; ++i) {\n        ANS.eb(V[i],\
    \ v), D[i]--;\n      }\n      tmp.eb(d, m);\n      n -= m, p = l;\n    }\n   \
    \ for (auto& [d, m] : tmp) cnt[d] -= m, cnt[d - 1] += m;\n    tmp.clear();\n \
    \ }\n  return {true, ANS};\n}\n\npair<bool, vc<pair<int, int>>> construct_from_degree_sequence_tree(\n\
    \    vc<int> deg) {\n  int N = len(deg);\n  if (SUM<ll>(deg) != N + N - 2) return\
    \ {false, {}};\n  if (N == 1) return {true, {}};\n  if (MIN(deg) == 0) return\
    \ {false, {}};\n  vc<pair<int, int>> E;\n  vc<int> X, Y;\n  FOR(v, N)(deg[v] ==\
    \ 1 ? X : Y).eb(v);\n  FOR(step, N - 1) {\n    while (len(Y) && deg[Y.back()]\
    \ <= 1) X.eb(POP(Y));\n    while (len(X) && deg[X.back()] != 1) POP(X);\n    int\
    \ v = POP(X);\n    while (len(X) && deg[X.back()] != 1) POP(X);\n    if (step\
    \ == N - 2) {\n      E.eb(v, POP(X));\n    } else {\n      int w = POP(Y);\n \
    \     E.eb(v, w);\n      deg[w]--, Y.eb(w);\n    }\n  }\n  return {true, E};\n\
    }"
  dependsOn:
  - ds/csr.hpp
  isVerificationFile: false
  path: graph/degree_sequence.hpp
  requiredBy: []
  timestamp: '2026-08-01 03:11:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/degree_sequence.hpp
layout: document
redirect_from:
- /library/graph/degree_sequence.hpp
- /library/graph/degree_sequence.hpp.html
title: graph/degree_sequence.hpp
---
