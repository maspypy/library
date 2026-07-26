---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: ds/csr.hpp
    title: ds/csr.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: ds/to_small_key.hpp
    title: ds/to_small_key.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/2155/problem/F
  bundledCode: "#line 1 \"ds/csr.hpp\"\n\ntemplate <typename T>\nstruct CSR {\n  int\
    \ n;\n  bool prepared;\n  vc<int> ptr;\n  vc<int> I;\n  vc<T> dat;\n\n  CSR(int\
    \ n = 0) : n(n), prepared(false) {}\n  void add(int i, const T& x) {\n    assert(0\
    \ <= i && i < n && !prepared);\n    I.eb(i), dat.eb(x);\n  }\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = 1;\n    ptr.assign(n + 1, 0);\n  \
    \  for (auto& i : I) ptr[1 + i]++;\n    FOR(i, len(ptr) - 1) ptr[i + 1] += ptr[i];\n\
    \    vc<T> tmp(len(dat));\n    FOR(k, len(dat)) {\n      int i = I[k];\n     \
    \ tmp[ptr[i]++] = dat[k];\n    }\n    swap(dat, tmp);\n    ptr.pop_back();\n \
    \   ptr.insert(ptr.begin(), 0);\n    I.clear(), I.shrink_to_fit();\n  }\n\n  struct\
    \ range {\n    T *first, *last;\n    T* begin() const { return first; }\n    T*\
    \ end() const { return last; }\n    bool empty() const { return first == last;\
    \ }\n    int size() const { return last - first; }\n  };\n\n  range operator[](int\
    \ i) {\n    assert(prepared);\n    return range{dat.data() + ptr[i], dat.data()\
    \ + ptr[i + 1]};\n  }\n};\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate\
    \ <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\
    \u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void\
    \ build(u32 n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap\
    \ = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\
    \n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\
    \n    used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int\
    \ size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n\
    \    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) &\
    \ mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n\
    \    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\
    \n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\n  \
    \  return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"ds/to_small_key.hpp\"\n\
    \n// [30,10,20,30] -> [0,1,2,0] etc.\nstruct To_Small_Key {\n  int kind = 0;\n\
    \  HashMap<int> MP;\n  vc<u64> raw;\n  To_Small_Key(u32 n = 0) : MP(n) {}\n  void\
    \ reserve(u32 n) { MP.build(n); }\n  int size() { return MP.size(); }\n  u64 restore(int\
    \ i) { return raw[i]; }\n  int query(u64 x, bool set_if_not_exist) {\n    int\
    \ ans = MP.get(x, -1);\n    if (ans == -1 && set_if_not_exist) {\n      raw.eb(x);\n\
    \      MP[x] = ans = kind++;\n    }\n    return ans;\n  }\n};\n#line 3 \"ds/offline_query/offline_set_intersection.hpp\"\
    \n\n// given set S[0],...,S[N-1]\n// Q query: calc |S[i] cap S[j]|\n// M:=sum\
    \ of size\n// complexity: M sqrt{Q}/8\n//\n// https://codeforces.com/contest/2155/problem/F\n\
    // N,M,Q=300000, 300ms \u7A0B\u5EA6\nstruct Offline_Set_Intersection {\n  int\
    \ N;\n  To_Small_Key TSK;\n  bool calculated;\n  vc<pair<int, int>> dat;\n  HashMap<int>\
    \ query_id;\n  vc<pair<int, int>> unique_query;\n  vc<int> ids;\n\n  // N: \u96C6\
    \u5408\u306E\u500B\u6570, K: \u8981\u7D20\u306E\u7A2E\u985E\u6570\n  Offline_Set_Intersection(int\
    \ N) : N(N), calculated(0) {}\n\n  // x in S[i]\n  // \u540C\u3058\u8981\u7D20\
    \u3092 2 \u56DE\u767B\u9332\u3059\u308B\u3068\u58CA\u308C\u308B\uFF08\u691C\u67FB\
    \u3057\u306A\u3044\uFF09\n  void add(int i, int x) {\n    assert(!calculated &&\
    \ 0 <= i && i < N);\n    int k = TSK.query(x, true);\n    dat.eb(i, k);\n  }\n\
    \n  int get_qid(int i, int j) {\n    if (i > j) swap(i, j);\n    u64 k = u64(i)\
    \ << 32 | u64(j);\n    if (!query_id.count(k)) {\n      query_id[k] = len(unique_query);\n\
    \      unique_query.eb(i, j);\n    }\n    return query_id[k];\n  }\n\n  void query(int\
    \ i, int j) {\n    assert(!calculated && 0 <= i && i < N && 0 <= j && j < N);\n\
    \    ids.eb(get_qid(i, j));\n  }\n\n  vc<int> calc() {\n    assert(!calculated);\n\
    \    calculated = true;\n    int K = TSK.kind;\n    int Q = len(unique_query);\n\
    \    int B = sqrt(Q) / 8;\n    vc<int> F(K);\n    for (auto &[i, k] : dat) F[k]++;\n\
    \    vc<int> heavy;\n    FOR(k, K) if (F[k] >= B) heavy.eb(k);\n\n    // StoX\
    \ \u306F light only\n    CSR<int> StoX(N), XtoS(K), StoQ(N);\n    for (auto &[i,\
    \ k] : dat) {\n      XtoS.add(k, i);\n      if (F[k] < B) StoX.add(i, k);\n  \
    \  }\n    FOR(q, Q) {\n      auto [i, j] = unique_query[q];\n      StoQ.add(i,\
    \ q);\n    }\n    StoX.build(), XtoS.build(), StoQ.build();\n\n    vc<int> ANS(Q);\n\
    \n    // heavy\n    {\n      vc<u64> A(N);\n      vc<int> vis;\n      for (int\
    \ p = 0; p < len(heavy); p += 64) {\n        vis.clear();\n        // item [p,p+64)\n\
    \        for (int idx = p; idx < p + 64; ++idx) {\n          if (len(heavy) <=\
    \ idx) break;\n          for (auto &i : XtoS[heavy[idx]]) {\n            A[i]\
    \ ^= u64(1) << (idx - p);\n            vis.eb(i);\n          }\n        }\n  \
    \      for (int q = 0; q < Q; ++q) {\n          auto [i, j] = unique_query[q];\n\
    \          ANS[q] += popcnt(A[i] & A[j]);\n        }\n        for (int i : vis)\
    \ A[i] = 0;\n      }\n    }\n    // light\n    vc<int> A(N);\n    FOR(i, N) {\n\
    \      if (StoX[i].empty() || StoQ[i].empty()) continue;\n      for (int x : StoX[i])\
    \ {\n        for (int j : XtoS[x]) {\n          A[j]++;\n        }\n      }\n\
    \      for (int q : StoQ[i]) {\n        int j = unique_query[q].se;\n        ANS[q]\
    \ += A[j];\n      }\n      for (int x : StoX[i]) {\n        for (int j : XtoS[x])\
    \ {\n          A[j]--;\n        }\n      }\n    }\n    ANS = rearrange(ANS, ids);\n\
    \    return ANS;\n  }\n};\n"
  code: "#include \"ds/csr.hpp\"\n#include \"ds/to_small_key.hpp\"\n\n// given set\
    \ S[0],...,S[N-1]\n// Q query: calc |S[i] cap S[j]|\n// M:=sum of size\n// complexity:\
    \ M sqrt{Q}/8\n//\n// https://codeforces.com/contest/2155/problem/F\n// N,M,Q=300000,\
    \ 300ms \u7A0B\u5EA6\nstruct Offline_Set_Intersection {\n  int N;\n  To_Small_Key\
    \ TSK;\n  bool calculated;\n  vc<pair<int, int>> dat;\n  HashMap<int> query_id;\n\
    \  vc<pair<int, int>> unique_query;\n  vc<int> ids;\n\n  // N: \u96C6\u5408\u306E\
    \u500B\u6570, K: \u8981\u7D20\u306E\u7A2E\u985E\u6570\n  Offline_Set_Intersection(int\
    \ N) : N(N), calculated(0) {}\n\n  // x in S[i]\n  // \u540C\u3058\u8981\u7D20\
    \u3092 2 \u56DE\u767B\u9332\u3059\u308B\u3068\u58CA\u308C\u308B\uFF08\u691C\u67FB\
    \u3057\u306A\u3044\uFF09\n  void add(int i, int x) {\n    assert(!calculated &&\
    \ 0 <= i && i < N);\n    int k = TSK.query(x, true);\n    dat.eb(i, k);\n  }\n\
    \n  int get_qid(int i, int j) {\n    if (i > j) swap(i, j);\n    u64 k = u64(i)\
    \ << 32 | u64(j);\n    if (!query_id.count(k)) {\n      query_id[k] = len(unique_query);\n\
    \      unique_query.eb(i, j);\n    }\n    return query_id[k];\n  }\n\n  void query(int\
    \ i, int j) {\n    assert(!calculated && 0 <= i && i < N && 0 <= j && j < N);\n\
    \    ids.eb(get_qid(i, j));\n  }\n\n  vc<int> calc() {\n    assert(!calculated);\n\
    \    calculated = true;\n    int K = TSK.kind;\n    int Q = len(unique_query);\n\
    \    int B = sqrt(Q) / 8;\n    vc<int> F(K);\n    for (auto &[i, k] : dat) F[k]++;\n\
    \    vc<int> heavy;\n    FOR(k, K) if (F[k] >= B) heavy.eb(k);\n\n    // StoX\
    \ \u306F light only\n    CSR<int> StoX(N), XtoS(K), StoQ(N);\n    for (auto &[i,\
    \ k] : dat) {\n      XtoS.add(k, i);\n      if (F[k] < B) StoX.add(i, k);\n  \
    \  }\n    FOR(q, Q) {\n      auto [i, j] = unique_query[q];\n      StoQ.add(i,\
    \ q);\n    }\n    StoX.build(), XtoS.build(), StoQ.build();\n\n    vc<int> ANS(Q);\n\
    \n    // heavy\n    {\n      vc<u64> A(N);\n      vc<int> vis;\n      for (int\
    \ p = 0; p < len(heavy); p += 64) {\n        vis.clear();\n        // item [p,p+64)\n\
    \        for (int idx = p; idx < p + 64; ++idx) {\n          if (len(heavy) <=\
    \ idx) break;\n          for (auto &i : XtoS[heavy[idx]]) {\n            A[i]\
    \ ^= u64(1) << (idx - p);\n            vis.eb(i);\n          }\n        }\n  \
    \      for (int q = 0; q < Q; ++q) {\n          auto [i, j] = unique_query[q];\n\
    \          ANS[q] += popcnt(A[i] & A[j]);\n        }\n        for (int i : vis)\
    \ A[i] = 0;\n      }\n    }\n    // light\n    vc<int> A(N);\n    FOR(i, N) {\n\
    \      if (StoX[i].empty() || StoQ[i].empty()) continue;\n      for (int x : StoX[i])\
    \ {\n        for (int j : XtoS[x]) {\n          A[j]++;\n        }\n      }\n\
    \      for (int q : StoQ[i]) {\n        int j = unique_query[q].se;\n        ANS[q]\
    \ += A[j];\n      }\n      for (int x : StoX[i]) {\n        for (int j : XtoS[x])\
    \ {\n          A[j]--;\n        }\n      }\n    }\n    ANS = rearrange(ANS, ids);\n\
    \    return ANS;\n  }\n};"
  dependsOn:
  - ds/csr.hpp
  - ds/to_small_key.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: ds/offline_query/offline_set_intersection.hpp
  requiredBy: []
  timestamp: '2026-07-19 04:43:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/offline_set_intersection.hpp
layout: document
redirect_from:
- /library/ds/offline_query/offline_set_intersection.hpp
- /library/ds/offline_query/offline_set_intersection.hpp.html
title: ds/offline_query/offline_set_intersection.hpp
---
