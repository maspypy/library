---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: ds/segtree/range_min.hpp
    title: ds/segtree/range_min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/segtree/range_max.hpp
  bundledCode: "#line 1 \"ds/segtree/range_max.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_max.hpp\n\
    #line 1 \"ds/segtree/range_min.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_min.hpp\n\
    \n// 2026/11/04 AI generated.\n\n#if defined(__x86_64__) && (defined(__GNUC__)\
    \ || defined(__clang__))\n#include <immintrin.h>\n#define RANGE_MIN_AVX2 1\n#else\n\
    #define RANGE_MIN_AVX2 0\n#endif\n\ntemplate <typename T>\nstruct Range_Min {\n\
    \  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\n  using value_type =\
    \ T;\n\n  static constexpr T INF = infty<T>;\n  static constexpr int B = 64 /\
    \ sizeof(T);\n\n  struct alignas(64) Block {\n    T a[B];\n  };\n  static_assert(sizeof(Block)\
    \ == 64);\n\n  int n = 0;\n\n private:\n  vc<vc<Block>> dat;\n  bool use_avx2\
    \ = false;\n\n  static T reduce_scalar(const T* p) {\n    T x = INF;\n    for\
    \ (int j = 0; j < B; ++j) x = min(x, p[j]);\n    return x;\n  }\n\n  static T\
    \ range_scalar(const T* p, int l, int r) {\n    T x = INF;\n    for (int j = l;\
    \ j < r; ++j) x = min(x, p[j]);\n    return x;\n  }\n\n#if RANGE_MIN_AVX2\n  __attribute__((target(\"\
    avx2\"))) static __m256i min64(__m256i a, __m256i b) {\n    return _mm256_blendv_epi8(a,\
    \ b, _mm256_cmpgt_epi64(a, b));\n  }\n\n  __attribute__((target(\"avx2\"))) static\
    \ T reduce_avx2(const T* p) {\n    if constexpr (is_same_v<T, int>) {\n      __m256i\
    \ a = _mm256_loadu_si256((const __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const\
    \ __m256i*)(p + 8));\n      a = _mm256_min_epi32(a, b);\n      a = _mm256_min_epi32(a,\
    \ _mm256_permute2x128_si256(a, a, 1));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a,\
    \ 0x4e));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n   \
    \   return _mm256_extract_epi32(a, 0);\n    } else {\n      __m256i a = _mm256_loadu_si256((const\
    \ __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));\n\
    \      a = min64(a, b);\n      a = min64(a, _mm256_permute4x64_epi64(a, 0x4e));\n\
    \      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));\n      return (T)_mm256_extract_epi64(a,\
    \ 0);\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) static T range_avx2(\n\
    \      const T* p, int l, int r) {\n    if constexpr (is_same_v<T, int>) {\n \
    \     __m256i lo = _mm256_set1_epi32(l - 1);\n      __m256i hi = _mm256_set1_epi32(r);\n\
    \      __m256i x = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);\n      __m256i y\
    \ = _mm256_setr_epi32(8, 9, 10, 11, 12, 13, 14, 15);\n      __m256i mx = _mm256_and_si256(\n\
    \          _mm256_cmpgt_epi32(x, lo), _mm256_cmpgt_epi32(hi, x));\n      __m256i\
    \ my = _mm256_and_si256(\n          _mm256_cmpgt_epi32(y, lo), _mm256_cmpgt_epi32(hi,\
    \ y));\n      __m256i inf = _mm256_set1_epi32(INF);\n      __m256i a =\n     \
    \     _mm256_blendv_epi8(inf, _mm256_loadu_si256((const __m256i*)p), mx);\n  \
    \    __m256i b = _mm256_blendv_epi8(\n          inf, _mm256_loadu_si256((const\
    \ __m256i*)(p + 8)), my);\n      a = _mm256_min_epi32(a, b);\n      a = _mm256_min_epi32(a,\
    \ _mm256_permute2x128_si256(a, a, 1));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a,\
    \ 0x4e));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n   \
    \   return _mm256_extract_epi32(a, 0);\n    } else {\n      __m256i lo = _mm256_set1_epi64x(l\
    \ - 1);\n      __m256i hi = _mm256_set1_epi64x(r);\n      __m256i x = _mm256_setr_epi64x(0,\
    \ 1, 2, 3);\n      __m256i y = _mm256_setr_epi64x(4, 5, 6, 7);\n      __m256i\
    \ mx = _mm256_and_si256(\n          _mm256_cmpgt_epi64(x, lo), _mm256_cmpgt_epi64(hi,\
    \ x));\n      __m256i my = _mm256_and_si256(\n          _mm256_cmpgt_epi64(y,\
    \ lo), _mm256_cmpgt_epi64(hi, y));\n      __m256i inf = _mm256_set1_epi64x(INF);\n\
    \      __m256i a =\n          _mm256_blendv_epi8(inf, _mm256_loadu_si256((const\
    \ __m256i*)p), mx);\n      __m256i b = _mm256_blendv_epi8(\n          inf, _mm256_loadu_si256((const\
    \ __m256i*)(p + 4)), my);\n      a = min64(a, b);\n      a = min64(a, _mm256_permute4x64_epi64(a,\
    \ 0x4e));\n      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));\n      return\
    \ (T)_mm256_extract_epi64(a, 0);\n    }\n  }\n#endif\n\n  // min \u56FA\u6709\u306E\
    \u66F4\u65B0\u6700\u9069\u5316\n  template <typename F>\n  void set_by(int i,\
    \ T x, F reduce) {\n    T& a = dat[0][i / B].a[i % B];\n    T old = a;\n    if\
    \ (old == x) return;\n    a = x;\n\n    for (int k = 0; k + 1 < (int)dat.size();\
    \ ++k) {\n      int b = i / B;\n      T& p = dat[k + 1][b / B].a[b % B];\n   \
    \   T old_p = p;\n      T new_p;\n\n      if (x < old) {\n        new_p = min(old_p,\
    \ x);\n      } else {\n        if (old > old_p) break;\n        new_p = reduce(dat[k][b].a);\n\
    \      }\n\n      if (new_p == old_p) break;\n      p = new_p;\n      old = old_p;\n\
    \      x = new_p;\n      i = b;\n    }\n  }\n\n  template <typename F>\n  T prod_by(int\
    \ l, int r, F reduce) const {\n    T ans = INF;\n    for (const auto& level :\
    \ dat) {\n      if (l >= r) break;\n      int a = l / B, b = (r - 1) / B;\n  \
    \    if (a == b) {\n        return min(ans, reduce(level[a].a, l % B, (r - 1)\
    \ % B + 1));\n      }\n      if (l % B) {\n        ans = min(ans, reduce(level[a].a,\
    \ l % B, B));\n        l = (a + 1) * B;\n      }\n      if (r % B) {\n       \
    \ ans = min(ans, reduce(level[b].a, 0, r % B));\n        r = b * B;\n      }\n\
    \      l /= B;\n      r /= B;\n    }\n    return ans;\n  }\n\n#if RANGE_MIN_AVX2\n\
    \  __attribute__((target(\"avx2\"))) void set_avx2(int i, T x) {\n    set_by(i,\
    \ x, reduce_avx2);\n  }\n\n  __attribute__((target(\"avx2\"))) T prod_avx2(int\
    \ l, int r) const {\n    return prod_by(l, r, range_avx2);\n  }\n#endif\n\n  //\
    \ k \u6BB5\u76EE\u306E\u5931\u6557\u3057\u305F\u8981\u7D20\u304B\u3089\u8449\u3078\
    \u964D\u308A\u308B\n  template <typename F>\n  int descend_right(int k, int i,\
    \ T sm, F& check) const {\n    for (--k; k >= 0; --k) {\n      const auto& v =\
    \ dat[k][i].a;\n      for (int j = 0; j < B; ++j) {\n        T y = min(sm, v[j]);\n\
    \        if (!check(y)) {\n          i = B * i + j;\n          break;\n      \
    \  }\n        sm = y;\n      }\n    }\n    return min(i, n);\n  }\n\n  template\
    \ <typename F>\n  int descend_left(int k, int i, T sm, F& check) const {\n   \
    \ for (--k; k >= 0; --k) {\n      const auto& v = dat[k][i].a;\n      for (int\
    \ j = B - 1; j >= 0; --j) {\n        T y = min(v[j], sm);\n        if (!check(y))\
    \ {\n          i = B * i + j;\n          break;\n        }\n        sm = y;\n\
    \      }\n    }\n    return min(i + 1, n);\n  }\n\n public:\n  Range_Min() { build(0);\
    \ }\n  Range_Min(int m) { build(m); }\n  Range_Min(const vc<T>& a) { build(a);\
    \ }\n\n  template <typename F>\n  Range_Min(int m, F f) {\n    build(m, f);\n\
    \  }\n\n  void build(int m) {\n    build(m, [](int) -> T { return INF; });\n \
    \ }\n\n  void build(const vc<T>& a) {\n    build((int)a.size(), [&](int i) ->\
    \ T { return a[i]; });\n  }\n\n  template <typename F>\n  void build(int m, F\
    \ f) {\n    assert(m >= 0);\n    n = m;\n    vc<T> cur(max(m, 1));\n    for (int\
    \ i = 0; i < m; ++i) cur[i] = f(i);\n    if (!m) cur[0] = INF;\n\n    dat.clear();\n\
    \    while (true) {\n      int sz = ((int)cur.size() + B - 1) / B;\n      dat.emplace_back(sz);\n\
    \      vc<T> nxt(sz);\n\n      for (int b = 0; b < sz; ++b) {\n        T* p =\
    \ dat.back()[b].a;\n        fill(p, p + B, INF);\n        for (int j = 0; j <\
    \ B && b * B + j < (int)cur.size(); ++j) {\n          p[j] = cur[b * B + j];\n\
    \        }\n        nxt[b] = reduce_scalar(p);\n      }\n      if (cur.size()\
    \ == 1) break;\n      cur.swap(nxt);\n    }\n\n    use_avx2 = false;\n#if RANGE_MIN_AVX2\n\
    \    __builtin_cpu_init();\n    use_avx2 = __builtin_cpu_supports(\"avx2\");\n\
    #endif\n  }\n\n  T get(int i) const {\n    assert(0 <= i && i < n);\n    return\
    \ dat[0][i / B].a[i % B];\n  }\n\n  vc<T> get_all() const {\n    vc<T> a(n);\n\
    \    for (int i = 0; i < n; ++i) {\n      a[i] = dat[0][i / B].a[i % B];\n   \
    \ }\n    return a;\n  }\n\n  void set(int i, const T& x) {\n    assert(0 <= i\
    \ && i < n);\n#if RANGE_MIN_AVX2\n    if (use_avx2) return set_avx2(i, x);\n#endif\n\
    \    set_by(i, x, reduce_scalar);\n  }\n\n  void multiply(int i, const T& x) {\
    \ set(i, min(get(i), x)); }\n\n  T prod(int l, int r) const {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n#if RANGE_MIN_AVX2\n    if (use_avx2) return prod_avx2(l,\
    \ r);\n#endif\n    return prod_by(l, r, range_scalar);\n  }\n\n  T prod_all()\
    \ const { return dat.back()[0].a[0]; }\n\n  template <typename F>\n  int max_right(F\
    \ check, int L) const {\n    assert(0 <= L && L <= n && check(INF));\n    if (L\
    \ == n) return n;\n    T sm = INF;\n    int i = L;\n\n    for (int k = 0; k <\
    \ (int)dat.size(); ++k) {\n      if (i % B || k + 1 == (int)dat.size()) {\n  \
    \      int b = i / B;\n        for (int j = i % B; j < B; ++j) {\n          T\
    \ y = min(sm, dat[k][b].a[j]);\n          if (!check(y)) {\n            return\
    \ descend_right(k, b * B + j, sm, check);\n          }\n          sm = y;\n  \
    \      }\n        i = b + 1;\n      } else {\n        i /= B;\n      }\n    }\n\
    \    return n;\n  }\n\n  template <typename F>\n  int min_left(F check, int R)\
    \ const {\n    assert(0 <= R && R <= n && check(INF));\n    if (R == 0) return\
    \ 0;\n    T sm = INF;\n    int i = R;\n\n    for (int k = 0; k < (int)dat.size();\
    \ ++k) {\n      if (i % B || k + 1 == (int)dat.size()) {\n        if (i == 0)\
    \ return 0;\n        int b = (i - 1) / B;\n        for (int j = (i - 1) % B; j\
    \ >= 0; --j) {\n          T y = min(dat[k][b].a[j], sm);\n          if (!check(y))\
    \ {\n            return descend_left(k, b * B + j, sm, check);\n          }\n\
    \          sm = y;\n        }\n        i = b;\n      } else {\n        i /= B;\n\
    \      }\n    }\n    return 0;\n  }\n};\n\n#undef RANGE_MIN_AVX2\n#line 3 \"ds/segtree/range_max.hpp\"\
    \n\ntemplate <typename T>\nstruct Range_Max {\n  static_assert(is_same_v<T, int>\
    \ || is_same_v<T, ll>);\n  using value_type = T;\n\n  Range_Min<T> seg;\n\n  Range_Max()\
    \ {}\n  Range_Max(int n) { build(n); }\n  Range_Max(const vc<T>& a) { build(a);\
    \ }\n\n  template <typename F>\n  Range_Max(int n, F f) {\n    build(n, f);\n\
    \  }\n\n  void build(int n) { seg.build(n); }\n\n  void build(const vc<T>& a)\
    \ {\n    build(len(a), [&](int i) -> T { return a[i]; });\n  }\n\n  template <typename\
    \ F>\n  void build(int n, F f) {\n    seg.build(n, [&](int i) -> T { return -f(i);\
    \ });\n  }\n\n  T get(int i) const { return -seg.get(i); }\n\n  vc<T> get_all()\
    \ const {\n    auto a = seg.get_all();\n    for (auto& x : a) x = -x;\n    return\
    \ a;\n  }\n\n  void set(int i, const T& x) { seg.set(i, -x); }\n\n  void multiply(int\
    \ i, const T& x) { seg.multiply(i, -x); }\n\n  T prod(int l, int r) const { return\
    \ -seg.prod(l, r); }\n\n  T prod_all() const { return -seg.prod_all(); }\n\n \
    \ template <typename F>\n  int max_right(F check, int L) const {\n    return seg.max_right([&](T\
    \ x) { return check(-x); }, L);\n  }\n\n  template <typename F>\n  int min_left(F\
    \ check, int R) const {\n    return seg.min_left([&](T x) { return check(-x);\
    \ }, R);\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_max.hpp\n\
    #include \"ds/segtree/range_min.hpp\"\n\ntemplate <typename T>\nstruct Range_Max\
    \ {\n  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\n  using value_type\
    \ = T;\n\n  Range_Min<T> seg;\n\n  Range_Max() {}\n  Range_Max(int n) { build(n);\
    \ }\n  Range_Max(const vc<T>& a) { build(a); }\n\n  template <typename F>\n  Range_Max(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  void build(int n) { seg.build(n); }\n\n\
    \  void build(const vc<T>& a) {\n    build(len(a), [&](int i) -> T { return a[i];\
    \ });\n  }\n\n  template <typename F>\n  void build(int n, F f) {\n    seg.build(n,\
    \ [&](int i) -> T { return -f(i); });\n  }\n\n  T get(int i) const { return -seg.get(i);\
    \ }\n\n  vc<T> get_all() const {\n    auto a = seg.get_all();\n    for (auto&\
    \ x : a) x = -x;\n    return a;\n  }\n\n  void set(int i, const T& x) { seg.set(i,\
    \ -x); }\n\n  void multiply(int i, const T& x) { seg.multiply(i, -x); }\n\n  T\
    \ prod(int l, int r) const { return -seg.prod(l, r); }\n\n  T prod_all() const\
    \ { return -seg.prod_all(); }\n\n  template <typename F>\n  int max_right(F check,\
    \ int L) const {\n    return seg.max_right([&](T x) { return check(-x); }, L);\n\
    \  }\n\n  template <typename F>\n  int min_left(F check, int R) const {\n    return\
    \ seg.min_left([&](T x) { return check(-x); }, R);\n  }\n};\n"
  dependsOn:
  - ds/segtree/range_min.hpp
  isVerificationFile: false
  path: ds/segtree/range_max.hpp
  requiredBy: []
  timestamp: '2026-11-04 21:29:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/range_max.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_max.hpp
- /library/ds/segtree/range_max.hpp.html
title: ds/segtree/range_max.hpp
---
