---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/xor/transpose.hpp
    title: linalg/xor/transpose.hpp
  - icon: ':x:'
    path: linalg/xor/vector_space.hpp
    title: linalg/xor/vector_space.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"linalg/xor/transpose.hpp\"\n\n// n x m \u884C\
    \u5217\u306E transpose\u3002O((n+m)log(n+m)) \u6642\u9593\u3002\n// https://github.com/dsnet/matrix-transpose\n\
    template <typename UINT>\nvc<UINT> transpose(int n, int m, vc<UINT>& A, bool keep_A\
    \ = 1) {\n  assert(max(n, m) <= numeric_limits<UINT>::digits);\n  assert(len(A)\
    \ == n);\n  vc<UINT> tmp;\n  if (keep_A) tmp = A;\n  int LOG = 0;\n  while ((1\
    \ << LOG) < max(n, m)) ++LOG;\n  A.resize(1 << LOG);\n  int width = 1 << LOG;\n\
    \  UINT mask = 1;\n  FOR(i, LOG) mask = mask | (mask << (1 << i));\n  FOR(t, LOG)\
    \ {\n    width >>= 1;\n    mask = mask ^ (mask >> width);\n    FOR(i, 1 << t)\
    \ {\n      FOR(j, width) {\n        UINT* x = &A[width * (2 * i + 0) + j];\n \
    \       UINT* y = &A[width * (2 * i + 1) + j];\n        *x = ((*y << width) &\
    \ mask) ^ *x;\n        *y = ((*x & mask) >> width) ^ *y;\n        *x = ((*y <<\
    \ width) & mask) ^ *x;\n      }\n    }\n  }\n  A.resize(m);\n  if (!keep_A) return\
    \ A;\n  swap(A, tmp);\n  return tmp;\n}\n#line 3 \"linalg/xor/vector_space.hpp\"\
    \n\ntemplate <typename UINT, int MAX_DIM>\nstruct Vector_Space {\n  static_assert(is_same_v<UINT,\
    \ u32> || is_same_v<UINT, u64> ||\n                is_same_v<UINT, u128>);\n \
    \ int dim;\n  array<UINT, MAX_DIM> dat;\n\n  Vector_Space() : dim(0), dat{} {}\n\
    \  Vector_Space(array<UINT, MAX_DIM> dat) : dat(dat) {\n    dim = 0;\n    FOR(i,\
    \ MAX_DIM) dim += (dat[i] != 0);\n  }\n\n  vc<UINT> to_vec() {\n    vc<UINT> ANS;\n\
    \    FOR(i, MAX_DIM) if (dat[i]) ANS.eb(dat[i]);\n    return ANS;\n  }\n\n  int\
    \ size() { return dim; }\n  u64 add_element(UINT v) {\n    FOR_R(i, MAX_DIM) {\
    \ chmin(v, v ^ dat[i]); }\n    if (v == 0) return 0;\n    FOR(i, MAX_DIM) {\n\
    \      if (dat[i] != 0) chmin(dat[i], dat[i] ^ v);\n    }\n    dat[topbit(v)]\
    \ = v;\n    ++dim;\n    return v;\n  }\n\n  bool contain(UINT v) {\n    for (UINT\
    \ w : dat) {\n      chmin(v, v ^ w);\n    }\n    return v == 0;\n  }\n\n  UINT\
    \ lower_bound(UINT x) {\n    int d = dim;\n    u32 ans = 0, now = 0;\n    FOR_R(i,\
    \ MAX_DIM) {\n      if (dat[i] == 0) continue;\n      --d;\n      SHOW(now, ans,\
    \ dat[i], x);\n      if ((now ^ dat[i]) < x) {\n        ans += UINT(1) << d;\n\
    \        now ^= dat[i];\n      }\n    }\n    if (now < x) ans += 1;\n    return\
    \ ans;\n  }\n\n  UINT kth(UINT k) {\n    assert(k < (UINT(1) << dim));\n    int\
    \ d = 0;\n    UINT ans = 0;\n    FOR(i, MAX_DIM) {\n      if (dat[i] == 0) continue;\n\
    \      if (k >> d & 1) ans ^= dat[i];\n      ++d;\n    }\n    return ans;\n  }\n\
    \n  UINT get_max(UINT xor_val = 0) {\n    UINT res = xor_val;\n    for (auto&&\
    \ x : dat) chmax(res, res ^ x);\n    return res;\n  }\n\n  UINT get_min(UINT xor_val\
    \ = 0) {\n    UINT res = xor_val;\n    for (auto&& x : dat) chmin(res, res ^ x);\n\
    \    return res;\n  }\n\n  static Vector_Space merge(Vector_Space x, Vector_Space\
    \ y) {\n    if (len(x) < len(y)) swap(x, y);\n    for (auto v : y.dat) {\n   \
    \   x.add_element(v);\n    }\n    return x;\n  }\n\n  static Vector_Space intersection(Vector_Space&\
    \ x, Vector_Space& y) {\n    // \u3068\u308A\u3042\u3048\u305A\n    static_assert(is_same_v<UINT,\
    \ u32>);\n    Vector_Space<u64, MAX_DIM * 2> z;\n    for (auto v : x.dat) {\n\
    \      if (v) z.add_element(v | static_cast<u64>(v) << MAX_DIM);\n    }\n    for\
    \ (auto v : y.dat) {\n      if (v) z.add_element(static_cast<u64>(v) << MAX_DIM);\n\
    \    }\n    Vector_Space<UINT, MAX_DIM> ANS;\n    for (auto& v : z.dat) {\n  \
    \    if (v <= u32(-1)) ANS.add_element(v);\n    }\n    return ANS;\n  }\n\n  static\
    \ array<UINT, MAX_DIM> transpose(array<UINT, MAX_DIM> A) {\n    constexpr int\
    \ L = numeric_limits<UINT>::digits;\n    array<UINT, L> B;\n    FOR(i, MAX_DIM)\
    \ B[i] = A[i];\n    int LOG = 0;\n    while ((1 << LOG) < L) ++LOG;\n    int width\
    \ = 1 << LOG;\n    UINT mask = -1;\n    FOR(t, LOG) {\n      width >>= 1;\n  \
    \    mask = mask ^ (mask >> width);\n      FOR(i, 1 << t) {\n        FOR(j, width)\
    \ {\n          UINT* x = &B[width * (2 * i + 0) + j];\n          UINT* y = &B[width\
    \ * (2 * i + 1) + j];\n          *x = ((*y << width) & mask) ^ *x;\n         \
    \ *y = ((*x & mask) >> width) ^ *y;\n          *x = ((*y << width) & mask) ^ *x;\n\
    \        }\n      }\n    }\n    FOR(i, MAX_DIM) A[i] = B[i];\n    return A;\n\
    \  }\n\n  Vector_Space orthogonal_space() {\n    array<u64, MAX_DIM> T = transpose(dat);\n\
    \    array<u64, MAX_DIM> ANS{};\n    FOR_R(j, MAX_DIM) {\n      if (T[j] >> j\
    \ & 1) continue;\n      ANS[j] = (UINT(1) << j) | T[j];\n    }\n    return Vector_Space(ANS);\n\
    \  }\n};\n#line 2 \"alg/monoid/merge_vector_space.hpp\"\n\ntemplate <typename\
    \ UINT, int MAX_DIM>\nstruct Merge_Vector_Space {\n  using value_type = Vector_Space<UINT,\
    \ MAX_DIM>;\n  using X = value_type;\n  static X op(X x, X y) {\n    if (len(x)\
    \ < len(y)) swap(x, y);\n    for (UINT v : y.dat) {\n      x.add_element(v);\n\
    \    }\n    return x;\n  }\n  static constexpr X unit() { return {}; }\n  static\
    \ constexpr bool commute = 1;\n};\n"
  code: "#include \"linalg/xor/vector_space.hpp\"\n\ntemplate <typename UINT, int\
    \ MAX_DIM>\nstruct Merge_Vector_Space {\n  using value_type = Vector_Space<UINT,\
    \ MAX_DIM>;\n  using X = value_type;\n  static X op(X x, X y) {\n    if (len(x)\
    \ < len(y)) swap(x, y);\n    for (UINT v : y.dat) {\n      x.add_element(v);\n\
    \    }\n    return x;\n  }\n  static constexpr X unit() { return {}; }\n  static\
    \ constexpr bool commute = 1;\n};\n"
  dependsOn:
  - linalg/xor/vector_space.hpp
  - other/bit.hpp
  - linalg/xor/transpose.hpp
  isVerificationFile: false
  path: alg/monoid/merge_vector_space.hpp
  requiredBy: []
  timestamp: '2026-07-28 12:25:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/merge_vector_space.hpp
layout: document
redirect_from:
- /library/alg/monoid/merge_vector_space.hpp
- /library/alg/monoid/merge_vector_space.hpp.html
title: alg/monoid/merge_vector_space.hpp
---
