---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: ds/to_small_key.hpp
    title: ds/to_small_key.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/static_range_frequency.hpp\"\n\n#line 2 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val, int LOG = 20, bool KEEP_IDS = false>\r\
    \nstruct HashMap {\r\n  static constexpr int N = (1 << LOG);\r\n  u64* key;\r\n\
    \  Val* val;\r\n  vc<int> IDS;\r\n  bitset<N> used;\r\n  const int shift;\r\n\
    \  const u64 r = 11995408973635179863ULL;\r\n  HashMap() : key(new u64[N]), val(new\
    \ Val[N]), shift(64 - LOG) {}\r\n  u32 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    int i = index(k);\r\n    if (!used[i]) {\r\n      used[i] =\
    \ 1, key[i] = k, val[i] = Val{};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\
    \n    }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value)\
    \ {\r\n    int i = index(k);\r\n    if (!used[i]) return default_value;\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\
    \n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  void reset() {\r\n    static_assert(KEEP_IDS);\r\
    \n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  //\
    \ f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\n  \
    \  static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) f(key[i], val[i]);\r\n\
    \  }\r\n};\r\n#line 2 \"ds/to_small_key.hpp\"\n\n// [30,10,20,30] -> [0,1,2,0]\
    \ etc.\ntemplate <int LOG = 20, bool USE_RESET = false>\nstruct To_Small_Key {\n\
    \  int kind = 0;\n  HashMap<int, LOG, true> MP;\n\n  int set_key(u64 x) {\n  \
    \  int idx = MP.index(x);\n    if (!MP.used[idx]) {\n      MP.used[idx] = 1;\n\
    \      MP.key[idx] = x;\n      MP.val[idx] = kind++;\n    }\n    return MP.val[idx];\n\
    \  }\n\n  int query(u64 x) { return MP.get(x, -1); }\n\n  void reset() {\n   \
    \ static_assert(USE_RESET);\n    MP.reset();\n  }\n};\n#line 3 \"ds/static_range_frequency.hpp\"\
    \n\ntemplate <int LOG, bool USE_RESET = false>\nstruct Static_Range_Frequency\
    \ {\n  vc<int> pos, indptr;\n  To_Small_Key<LOG, USE_RESET> S;\n\n  template <typename\
    \ T>\n  Static_Range_Frequency(vc<T>& A) {\n    build(len(A), [&](int i) -> u64\
    \ { return A[i]; });\n  }\n\n  template <typename F>\n  Static_Range_Frequency(int\
    \ N, F f) {\n    build(N, f);\n  }\n\n  template <typename F>\n  void build(int\
    \ N, F f) {\n    pos.resize(N);\n    vc<int> cnt(N + 1), dat(N);\n    FOR(i, N)\
    \ {\n      u64 x = f(i);\n      int k = S.set_key(x);\n      cnt[1 + k]++, dat[i]\
    \ = k;\n    }\n    FOR(k, N) cnt[1 + k] += cnt[k];\n    indptr = cnt;\n    FOR(i,\
    \ N) pos[cnt[dat[i]]++] = i;\n  }\n\n  int query(int L, int R, u64 x) {\n    int\
    \ k = S.query(x);\n    if (k == -1) return 0;\n    int a = indptr[k], b = indptr[k\
    \ + 1];\n    auto nl = lower_bound(pos.begin() + a, pos.begin() + b, L);\n   \
    \ auto nr = lower_bound(pos.begin() + a, pos.begin() + b, R);\n    return nr -\
    \ nl;\n  }\n\n  void reset() {\n    static_assert(USE_RESET);\n    S.reset();\n\
    \  }\n};\n"
  code: "\n#include \"ds/to_small_key.hpp\"\n\ntemplate <int LOG, bool USE_RESET =\
    \ false>\nstruct Static_Range_Frequency {\n  vc<int> pos, indptr;\n  To_Small_Key<LOG,\
    \ USE_RESET> S;\n\n  template <typename T>\n  Static_Range_Frequency(vc<T>& A)\
    \ {\n    build(len(A), [&](int i) -> u64 { return A[i]; });\n  }\n\n  template\
    \ <typename F>\n  Static_Range_Frequency(int N, F f) {\n    build(N, f);\n  }\n\
    \n  template <typename F>\n  void build(int N, F f) {\n    pos.resize(N);\n  \
    \  vc<int> cnt(N + 1), dat(N);\n    FOR(i, N) {\n      u64 x = f(i);\n      int\
    \ k = S.set_key(x);\n      cnt[1 + k]++, dat[i] = k;\n    }\n    FOR(k, N) cnt[1\
    \ + k] += cnt[k];\n    indptr = cnt;\n    FOR(i, N) pos[cnt[dat[i]]++] = i;\n\
    \  }\n\n  int query(int L, int R, u64 x) {\n    int k = S.query(x);\n    if (k\
    \ == -1) return 0;\n    int a = indptr[k], b = indptr[k + 1];\n    auto nl = lower_bound(pos.begin()\
    \ + a, pos.begin() + b, L);\n    auto nr = lower_bound(pos.begin() + a, pos.begin()\
    \ + b, R);\n    return nr - nl;\n  }\n\n  void reset() {\n    static_assert(USE_RESET);\n\
    \    S.reset();\n  }\n};"
  dependsOn:
  - ds/to_small_key.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: ds/static_range_frequency.hpp
  requiredBy: []
  timestamp: '2023-11-21 19:08:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/static_range_frequency.hpp
layout: document
redirect_from:
- /library/ds/static_range_frequency.hpp
- /library/ds/static_range_frequency.hpp.html
title: ds/static_range_frequency.hpp
---
