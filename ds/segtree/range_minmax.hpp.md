---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/minmax.hpp
    title: alg/monoid/minmax.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/5_ai_generated_test/range_minmax.test.cpp
    title: test/5_ai_generated_test/range_minmax.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/segtree/range_minmax.hpp
  bundledCode: "#line 1 \"ds/segtree/range_minmax.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_minmax.hpp\n\
    \n#line 1 \"alg/monoid/minmax.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/minmax.hpp\n\
    \ntemplate <class X>\nstruct Monoid_MinMax {\n  using P = pair<X, X>;\n  using\
    \ value_type = P;\n  static constexpr P op(const P x, const P y) noexcept {\n\
    \    return {min(x.fi, y.fi), max(x.se, y.se)};\n  }\n  static constexpr P from_element(const\
    \ X x) { return {x, x}; }\n  static constexpr P id() { return {infty<X>, -infty<X>};\
    \ }\n  static constexpr bool commute = true;\n};\n#line 4 \"ds/segtree/range_minmax.hpp\"\
    \n\n// 2026/11/17 AI generated.\n\n// Range_Min / Range_Max \u3068\u540C\u3058\
    \ B \u5206\u6728\u3002\u5404\u30D6\u30ED\u30C3\u30AF\u306F min 64B + max 64B\u3002\
    \n// \u4F4D\u7F6E i \u306F Monoid_MinMax<T>::value_type (= pair<T,T>) \u3092\u6301\
    \u3064\u3002\n// \u521D\u671F\u5024\u306F monoid \u306E\u5358\u4F4D\u5143 {INF,\
    \ -INF}\u3002\u30B9\u30AB\u30E9\u30FC x \u306F {x,x} \u3068\u3057\u3066\u6271\u3046\
    \u3002\n// \u6709\u52B9\u306A\u5024\u57DF\u306F Monoid_MinMax<T>::id() \u306E\u756A\
    \u5175\u306B\u53CE\u307E\u308B\u7BC4\u56F2\u3068\u3059\u308B\u3002\n#if defined(__x86_64__)\
    \ && (defined(__GNUC__) || defined(__clang__)) && \\\n    !defined(RANGE_MINMAX_NO_AVX2)\n\
    #include <immintrin.h>\n#define RANGE_MINMAX_AVX2 1\n#else\n#define RANGE_MINMAX_AVX2\
    \ 0\n#endif\n\ntemplate <typename T>\nstruct Range_MinMax {\n  static_assert(is_same_v<T,\
    \ int> || is_same_v<T, ll>);\n  using MX = Monoid_MinMax<T>;\n  using value_type\
    \ = typename MX::value_type;\n  using X = value_type;\n\n  static constexpr T\
    \ INF = infty<T>;\n  static constexpr int B = 64 / sizeof(T);\n\n  struct alignas(64)\
    \ Block {\n    T mn[B], mx[B];\n  };\n  static_assert(sizeof(Block) == 128);\n\
    \n  int n = 0;\n\n private:\n  vc<vc<Block>> dat;\n  bool use_avx2 = false;\n\n\
    \  static X as_pair(T x) { return {x, x}; }\n  static X as_pair(X x) { return\
    \ x; }\n\n  static X op(X a, X b) {\n    return {min(a.first, b.first), max(a.second,\
    \ b.second)};\n  }\n\n  static T reduce_min_scalar(const T* p) {\n    T x = INF;\n\
    \    for (int j = 0; j < B; ++j) x = min(x, p[j]);\n    return x;\n  }\n\n  static\
    \ T reduce_max_scalar(const T* p) {\n    T x = -INF;\n    for (int j = 0; j <\
    \ B; ++j) x = max(x, p[j]);\n    return x;\n  }\n\n  static X range_scalar(const\
    \ Block& p, int l, int r) {\n    X x = MX::id();\n    for (int j = l; j < r; ++j)\
    \ {\n      x.first = min(x.first, p.mn[j]);\n      x.second = max(x.second, p.mx[j]);\n\
    \    }\n    return x;\n  }\n\n#if RANGE_MINMAX_AVX2\n  __attribute__((target(\"\
    avx2\"))) static __m256i min64(__m256i a, __m256i b) {\n    return _mm256_blendv_epi8(a,\
    \ b, _mm256_cmpgt_epi64(a, b));\n  }\n\n  __attribute__((target(\"avx2\"))) static\
    \ __m256i max64(__m256i a, __m256i b) {\n    return _mm256_blendv_epi8(a, b, _mm256_cmpgt_epi64(b,\
    \ a));\n  }\n\n  __attribute__((target(\"avx2\"))) static T reduce_min_avx2(const\
    \ T* p) {\n    if constexpr (is_same_v<T, int>) {\n      __m256i a = _mm256_loadu_si256((const\
    \ __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 8));\n\
    \      a = _mm256_min_epi32(a, b);\n      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n   \
    \   a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n      return _mm256_extract_epi32(a,\
    \ 0);\n    } else {\n      __m256i a = _mm256_loadu_si256((const __m256i*)p);\n\
    \      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));\n      a = min64(a,\
    \ b);\n      a = min64(a, _mm256_permute4x64_epi64(a, 0x4e));\n      a = min64(a,\
    \ _mm256_permute4x64_epi64(a, 0xb1));\n      return (T)_mm256_extract_epi64(a,\
    \ 0);\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) static T reduce_max_avx2(const\
    \ T* p) {\n    if constexpr (is_same_v<T, int>) {\n      __m256i a = _mm256_loadu_si256((const\
    \ __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 8));\n\
    \      a = _mm256_max_epi32(a, b);\n      a = _mm256_max_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      a = _mm256_max_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n   \
    \   a = _mm256_max_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n      return _mm256_extract_epi32(a,\
    \ 0);\n    } else {\n      __m256i a = _mm256_loadu_si256((const __m256i*)p);\n\
    \      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));\n      a = max64(a,\
    \ b);\n      a = max64(a, _mm256_permute4x64_epi64(a, 0x4e));\n      a = max64(a,\
    \ _mm256_permute4x64_epi64(a, 0xb1));\n      return (T)_mm256_extract_epi64(a,\
    \ 0);\n    }\n  }\n\n  // min/max \u4E21\u65B9\u306E\u90E8\u5206\u30D6\u30ED\u30C3\
    \u30AF\u3092\u30DE\u30B9\u30AF\u4ED8\u304D\u3067\u96C6\u7D04\u3059\u308B\u3002\
    \n  __attribute__((target(\"avx2\"))) static X range_avx2(\n      const Block&\
    \ p, int l, int r) {\n    if (l == 0 && r == B) {\n      return {reduce_min_avx2(p.mn),\
    \ reduce_max_avx2(p.mx)};\n    }\n    if constexpr (is_same_v<T, int>) {\n   \
    \   __m256i lo = _mm256_set1_epi32(l - 1);\n      __m256i hi = _mm256_set1_epi32(r);\n\
    \      __m256i ix = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);\n      __m256i\
    \ iy = _mm256_setr_epi32(8, 9, 10, 11, 12, 13, 14, 15);\n      __m256i mask0 =\
    \ _mm256_and_si256(\n          _mm256_cmpgt_epi32(ix, lo), _mm256_cmpgt_epi32(hi,\
    \ ix));\n      __m256i mask1 = _mm256_and_si256(\n          _mm256_cmpgt_epi32(iy,\
    \ lo), _mm256_cmpgt_epi32(hi, iy));\n      __m256i pos = _mm256_set1_epi32(INF);\n\
    \      __m256i neg = _mm256_set1_epi32(-INF);\n      __m256i a = _mm256_blendv_epi8(\n\
    \          pos, _mm256_loadu_si256((const __m256i*)p.mn), mask0);\n      __m256i\
    \ b = _mm256_blendv_epi8(\n          pos, _mm256_loadu_si256((const __m256i*)(p.mn\
    \ + 8)), mask1);\n      __m256i c = _mm256_blendv_epi8(\n          neg, _mm256_loadu_si256((const\
    \ __m256i*)p.mx), mask0);\n      __m256i d = _mm256_blendv_epi8(\n          neg,\
    \ _mm256_loadu_si256((const __m256i*)(p.mx + 8)), mask1);\n      a = _mm256_min_epi32(a,\
    \ b);\n      c = _mm256_max_epi32(c, d);\n      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      c = _mm256_max_epi32(c, _mm256_permute2x128_si256(c, c, 1));\n\
    \      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n      c = _mm256_max_epi32(c,\
    \ _mm256_shuffle_epi32(c, 0x4e));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a,\
    \ 0xb1));\n      c = _mm256_max_epi32(c, _mm256_shuffle_epi32(c, 0xb1));\n   \
    \   return {_mm256_extract_epi32(a, 0), _mm256_extract_epi32(c, 0)};\n    } else\
    \ {\n      __m256i lo = _mm256_set1_epi64x(l - 1);\n      __m256i hi = _mm256_set1_epi64x(r);\n\
    \      __m256i ix = _mm256_setr_epi64x(0, 1, 2, 3);\n      __m256i iy = _mm256_setr_epi64x(4,\
    \ 5, 6, 7);\n      __m256i mask0 = _mm256_and_si256(\n          _mm256_cmpgt_epi64(ix,\
    \ lo), _mm256_cmpgt_epi64(hi, ix));\n      __m256i mask1 = _mm256_and_si256(\n\
    \          _mm256_cmpgt_epi64(iy, lo), _mm256_cmpgt_epi64(hi, iy));\n      __m256i\
    \ pos = _mm256_set1_epi64x(INF);\n      __m256i neg = _mm256_set1_epi64x(-INF);\n\
    \      __m256i a = _mm256_blendv_epi8(\n          pos, _mm256_loadu_si256((const\
    \ __m256i*)p.mn), mask0);\n      __m256i b = _mm256_blendv_epi8(\n          pos,\
    \ _mm256_loadu_si256((const __m256i*)(p.mn + 4)), mask1);\n      __m256i c = _mm256_blendv_epi8(\n\
    \          neg, _mm256_loadu_si256((const __m256i*)p.mx), mask0);\n      __m256i\
    \ d = _mm256_blendv_epi8(\n          neg, _mm256_loadu_si256((const __m256i*)(p.mx\
    \ + 4)), mask1);\n      a = min64(a, b);\n      c = max64(c, d);\n      a = min64(a,\
    \ _mm256_permute4x64_epi64(a, 0x4e));\n      c = max64(c, _mm256_permute4x64_epi64(c,\
    \ 0x4e));\n      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));\n      c = max64(c,\
    \ _mm256_permute4x64_epi64(c, 0xb1));\n      return {(T)_mm256_extract_epi64(a,\
    \ 0), (T)_mm256_extract_epi64(c, 0)};\n    }\n  }\n#endif\n\n  // 1 \u500B\u306E\
    \u5B50\u306E\u96C6\u7D04\u5024\u306E\u5909\u5316\u3092\u89AA\u3078\u53CD\u6620\
    \u3002\u7247\u5074\u3060\u3051\u304C\u5F71\u97FF\u3092\u53D7\u3051\u308B\u5834\
    \u5408\u306F\n  // min/max \u306E\u5FC5\u8981\u306A\u5074\u3060\u3051\u518D\u8A08\
    \u7B97\u3059\u308B\u3002\n  template <typename FMIN, typename FMAX>\n  void set_by(int\
    \ i, X x, FMIN reduce_min, FMAX reduce_max) {\n    Block& leaf = dat[0][i / B];\n\
    \    const int j = i % B;\n    X old = {leaf.mn[j], leaf.mx[j]};\n    if (old\
    \ == x) return;\n    leaf.mn[j] = x.first;\n    leaf.mx[j] = x.second;\n\n   \
    \ for (int k = 0; k + 1 < (int)dat.size(); ++k) {\n      int b = i / B;\n    \
    \  Block& parent = dat[k + 1][b / B];\n      T& pmin = parent.mn[b % B];\n   \
    \   T& pmax = parent.mx[b % B];\n      X old_p = {pmin, pmax};\n      X new_p\
    \ = old_p;\n\n      if (x.first < old.first) {\n        new_p.first = min(old_p.first,\
    \ x.first);\n      } else if (x.first > old.first && old.first <= old_p.first)\
    \ {\n        new_p.first = reduce_min(dat[k][b].mn);\n      }\n      if (x.second\
    \ > old.second) {\n        new_p.second = max(old_p.second, x.second);\n     \
    \ } else if (x.second < old.second && old.second >= old_p.second) {\n        new_p.second\
    \ = reduce_max(dat[k][b].mx);\n      }\n\n      if (new_p == old_p) break;\n \
    \     pmin = new_p.first;\n      pmax = new_p.second;\n      old = old_p;\n  \
    \    x = new_p;\n      i = b;\n    }\n  }\n\n  template <typename F>\n  X prod_by(int\
    \ l, int r, F reduce) const {\n    X ans = MX::id();\n    for (const auto& level\
    \ : dat) {\n      if (l >= r) break;\n      int a = l / B, b = (r - 1) / B;\n\
    \      if (a == b) {\n        return op(ans, reduce(level[a], l % B, (r - 1) %\
    \ B + 1));\n      }\n      if (l % B) {\n        ans = op(ans, reduce(level[a],\
    \ l % B, B));\n        l = (a + 1) * B;\n      }\n      if (r % B) {\n       \
    \ ans = op(ans, reduce(level[b], 0, r % B));\n        r = b * B;\n      }\n  \
    \    l /= B;\n      r /= B;\n    }\n    return ans;\n  }\n\n#if RANGE_MINMAX_AVX2\n\
    \  __attribute__((target(\"avx2\"))) void set_avx2(int i, X x) {\n    set_by(i,\
    \ x, reduce_min_avx2, reduce_max_avx2);\n  }\n\n  __attribute__((target(\"avx2\"\
    ))) X prod_avx2(int l, int r) const {\n    return prod_by(l, r, range_avx2);\n\
    \  }\n#endif\n\n  template <typename F>\n  int descend_right(int k, int i, X sm,\
    \ F& check) const {\n    for (--k; k >= 0; --k) {\n      const auto& p = dat[k][i];\n\
    \      for (int j = 0; j < B; ++j) {\n        X y = op(sm, {p.mn[j], p.mx[j]});\n\
    \        if (!check(y)) {\n          i = B * i + j;\n          break;\n      \
    \  }\n        sm = y;\n      }\n    }\n    return min(i, n);\n  }\n\n  template\
    \ <typename F>\n  int descend_left(int k, int i, X sm, F& check) const {\n   \
    \ for (--k; k >= 0; --k) {\n      const auto& p = dat[k][i];\n      for (int j\
    \ = B - 1; j >= 0; --j) {\n        X y = op({p.mn[j], p.mx[j]}, sm);\n       \
    \ if (!check(y)) {\n          i = B * i + j;\n          break;\n        }\n  \
    \      sm = y;\n      }\n    }\n    return min(i + 1, n);\n  }\n\n public:\n \
    \ Range_MinMax() { build(0); }\n  Range_MinMax(int m) { build(m); }\n  Range_MinMax(const\
    \ vc<T>& a) { build(a); }\n  Range_MinMax(const vc<X>& a) { build(a); }\n\n  template\
    \ <typename F>\n  Range_MinMax(int m, F f) {\n    build(m, f);\n  }\n\n  void\
    \ build(int m) {\n    build(m, [](int) -> X { return MX::id(); });\n  }\n\n  void\
    \ build(const vc<T>& a) {\n    build((int)a.size(), [&](int i) -> T { return a[i];\
    \ });\n  }\n\n  void build(const vc<X>& a) {\n    build((int)a.size(), [&](int\
    \ i) -> X { return a[i]; });\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    assert(m >= 0);\n    n = m;\n    vc<X> cur(max(m, 1), MX::id());\n\
    \    for (int i = 0; i < m; ++i) cur[i] = as_pair(f(i));\n\n    dat.clear();\n\
    \    while (true) {\n      int sz = ((int)cur.size() + B - 1) / B;\n      dat.emplace_back(sz);\n\
    \      vc<X> nxt(sz, MX::id());\n      for (int b = 0; b < sz; ++b) {\n      \
    \  Block& p = dat.back()[b];\n        fill(p.mn, p.mn + B, INF);\n        fill(p.mx,\
    \ p.mx + B, -INF);\n        for (int j = 0; j < B && b * B + j < (int)cur.size();\
    \ ++j) {\n          p.mn[j] = cur[b * B + j].first;\n          p.mx[j] = cur[b\
    \ * B + j].second;\n        }\n        nxt[b] = {reduce_min_scalar(p.mn), reduce_max_scalar(p.mx)};\n\
    \      }\n      if (cur.size() == 1) break;\n      cur.swap(nxt);\n    }\n\n \
    \   use_avx2 = false;\n#if RANGE_MINMAX_AVX2\n    __builtin_cpu_init();\n    use_avx2\
    \ = __builtin_cpu_supports(\"avx2\");\n#endif\n  }\n\n  X get(int i) const {\n\
    \    assert(0 <= i && i < n);\n    const auto& p = dat[0][i / B];\n    return\
    \ {p.mn[i % B], p.mx[i % B]};\n  }\n\n  vc<X> get_all() const {\n    vc<X> a(n);\n\
    \    for (int i = 0; i < n; ++i) a[i] = get(i);\n    return a;\n  }\n\n  void\
    \ set(int i, const X& x) {\n    assert(0 <= i && i < n);\n#if RANGE_MINMAX_AVX2\n\
    \    if (use_avx2) return set_avx2(i, x);\n#endif\n    set_by(i, x, reduce_min_scalar,\
    \ reduce_max_scalar);\n  }\n\n  void set(int i, T x) { set(i, X{x, x}); }\n\n\
    \  void multiply(int i, const X& x) { set(i, op(get(i), x)); }\n  void multiply(int\
    \ i, T x) { multiply(i, X{x, x}); }\n\n  X prod(int l, int r) const {\n    assert(0\
    \ <= l && l <= r && r <= n);\n#if RANGE_MINMAX_AVX2\n    if (use_avx2) return\
    \ prod_avx2(l, r);\n#endif\n    return prod_by(l, r, range_scalar);\n  }\n\n \
    \ X prod_all() const {\n    const auto& p = dat.back()[0];\n    return {p.mn[0],\
    \ p.mx[0]};\n  }\n\n  template <typename F>\n  int max_right(F check, int L) const\
    \ {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n) return\
    \ n;\n    X sm = MX::id();\n    int i = L;\n    for (int k = 0; k < (int)dat.size();\
    \ ++k) {\n      if (i % B || k + 1 == (int)dat.size()) {\n        int b = i /\
    \ B;\n        for (int j = i % B; j < B; ++j) {\n          const auto& p = dat[k][b];\n\
    \          X y = op(sm, {p.mn[j], p.mx[j]});\n          if (!check(y)) {\n   \
    \         return descend_right(k, b * B + j, sm, check);\n          }\n      \
    \    sm = y;\n        }\n        i = b + 1;\n      } else {\n        i /= B;\n\
    \      }\n    }\n    return n;\n  }\n\n  template <typename F>\n  int min_left(F\
    \ check, int R) const {\n    assert(0 <= R && R <= n && check(MX::id()));\n  \
    \  if (R == 0) return 0;\n    X sm = MX::id();\n    int i = R;\n    for (int k\
    \ = 0; k < (int)dat.size(); ++k) {\n      if (i % B || k + 1 == (int)dat.size())\
    \ {\n        if (i == 0) return 0;\n        int b = (i - 1) / B;\n        for\
    \ (int j = (i - 1) % B; j >= 0; --j) {\n          const auto& p = dat[k][b];\n\
    \          X y = op({p.mn[j], p.mx[j]}, sm);\n          if (!check(y)) {\n   \
    \         return descend_left(k, b * B + j, sm, check);\n          }\n       \
    \   sm = y;\n        }\n        i = b;\n      } else {\n        i /= B;\n    \
    \  }\n    }\n    return 0;\n  }\n};\n\n#undef RANGE_MINMAX_AVX2\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_minmax.hpp\n\
    \n#include \"alg/monoid/minmax.hpp\"\n\n// 2026/11/17 AI generated.\n\n// Range_Min\
    \ / Range_Max \u3068\u540C\u3058 B \u5206\u6728\u3002\u5404\u30D6\u30ED\u30C3\u30AF\
    \u306F min 64B + max 64B\u3002\n// \u4F4D\u7F6E i \u306F Monoid_MinMax<T>::value_type\
    \ (= pair<T,T>) \u3092\u6301\u3064\u3002\n// \u521D\u671F\u5024\u306F monoid \u306E\
    \u5358\u4F4D\u5143 {INF, -INF}\u3002\u30B9\u30AB\u30E9\u30FC x \u306F {x,x} \u3068\
    \u3057\u3066\u6271\u3046\u3002\n// \u6709\u52B9\u306A\u5024\u57DF\u306F Monoid_MinMax<T>::id()\
    \ \u306E\u756A\u5175\u306B\u53CE\u307E\u308B\u7BC4\u56F2\u3068\u3059\u308B\u3002\
    \n#if defined(__x86_64__) && (defined(__GNUC__) || defined(__clang__)) && \\\n\
    \    !defined(RANGE_MINMAX_NO_AVX2)\n#include <immintrin.h>\n#define RANGE_MINMAX_AVX2\
    \ 1\n#else\n#define RANGE_MINMAX_AVX2 0\n#endif\n\ntemplate <typename T>\nstruct\
    \ Range_MinMax {\n  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\n  using\
    \ MX = Monoid_MinMax<T>;\n  using value_type = typename MX::value_type;\n  using\
    \ X = value_type;\n\n  static constexpr T INF = infty<T>;\n  static constexpr\
    \ int B = 64 / sizeof(T);\n\n  struct alignas(64) Block {\n    T mn[B], mx[B];\n\
    \  };\n  static_assert(sizeof(Block) == 128);\n\n  int n = 0;\n\n private:\n \
    \ vc<vc<Block>> dat;\n  bool use_avx2 = false;\n\n  static X as_pair(T x) { return\
    \ {x, x}; }\n  static X as_pair(X x) { return x; }\n\n  static X op(X a, X b)\
    \ {\n    return {min(a.first, b.first), max(a.second, b.second)};\n  }\n\n  static\
    \ T reduce_min_scalar(const T* p) {\n    T x = INF;\n    for (int j = 0; j < B;\
    \ ++j) x = min(x, p[j]);\n    return x;\n  }\n\n  static T reduce_max_scalar(const\
    \ T* p) {\n    T x = -INF;\n    for (int j = 0; j < B; ++j) x = max(x, p[j]);\n\
    \    return x;\n  }\n\n  static X range_scalar(const Block& p, int l, int r) {\n\
    \    X x = MX::id();\n    for (int j = l; j < r; ++j) {\n      x.first = min(x.first,\
    \ p.mn[j]);\n      x.second = max(x.second, p.mx[j]);\n    }\n    return x;\n\
    \  }\n\n#if RANGE_MINMAX_AVX2\n  __attribute__((target(\"avx2\"))) static __m256i\
    \ min64(__m256i a, __m256i b) {\n    return _mm256_blendv_epi8(a, b, _mm256_cmpgt_epi64(a,\
    \ b));\n  }\n\n  __attribute__((target(\"avx2\"))) static __m256i max64(__m256i\
    \ a, __m256i b) {\n    return _mm256_blendv_epi8(a, b, _mm256_cmpgt_epi64(b, a));\n\
    \  }\n\n  __attribute__((target(\"avx2\"))) static T reduce_min_avx2(const T*\
    \ p) {\n    if constexpr (is_same_v<T, int>) {\n      __m256i a = _mm256_loadu_si256((const\
    \ __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 8));\n\
    \      a = _mm256_min_epi32(a, b);\n      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n   \
    \   a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n      return _mm256_extract_epi32(a,\
    \ 0);\n    } else {\n      __m256i a = _mm256_loadu_si256((const __m256i*)p);\n\
    \      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));\n      a = min64(a,\
    \ b);\n      a = min64(a, _mm256_permute4x64_epi64(a, 0x4e));\n      a = min64(a,\
    \ _mm256_permute4x64_epi64(a, 0xb1));\n      return (T)_mm256_extract_epi64(a,\
    \ 0);\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) static T reduce_max_avx2(const\
    \ T* p) {\n    if constexpr (is_same_v<T, int>) {\n      __m256i a = _mm256_loadu_si256((const\
    \ __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 8));\n\
    \      a = _mm256_max_epi32(a, b);\n      a = _mm256_max_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      a = _mm256_max_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n   \
    \   a = _mm256_max_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n      return _mm256_extract_epi32(a,\
    \ 0);\n    } else {\n      __m256i a = _mm256_loadu_si256((const __m256i*)p);\n\
    \      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));\n      a = max64(a,\
    \ b);\n      a = max64(a, _mm256_permute4x64_epi64(a, 0x4e));\n      a = max64(a,\
    \ _mm256_permute4x64_epi64(a, 0xb1));\n      return (T)_mm256_extract_epi64(a,\
    \ 0);\n    }\n  }\n\n  // min/max \u4E21\u65B9\u306E\u90E8\u5206\u30D6\u30ED\u30C3\
    \u30AF\u3092\u30DE\u30B9\u30AF\u4ED8\u304D\u3067\u96C6\u7D04\u3059\u308B\u3002\
    \n  __attribute__((target(\"avx2\"))) static X range_avx2(\n      const Block&\
    \ p, int l, int r) {\n    if (l == 0 && r == B) {\n      return {reduce_min_avx2(p.mn),\
    \ reduce_max_avx2(p.mx)};\n    }\n    if constexpr (is_same_v<T, int>) {\n   \
    \   __m256i lo = _mm256_set1_epi32(l - 1);\n      __m256i hi = _mm256_set1_epi32(r);\n\
    \      __m256i ix = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);\n      __m256i\
    \ iy = _mm256_setr_epi32(8, 9, 10, 11, 12, 13, 14, 15);\n      __m256i mask0 =\
    \ _mm256_and_si256(\n          _mm256_cmpgt_epi32(ix, lo), _mm256_cmpgt_epi32(hi,\
    \ ix));\n      __m256i mask1 = _mm256_and_si256(\n          _mm256_cmpgt_epi32(iy,\
    \ lo), _mm256_cmpgt_epi32(hi, iy));\n      __m256i pos = _mm256_set1_epi32(INF);\n\
    \      __m256i neg = _mm256_set1_epi32(-INF);\n      __m256i a = _mm256_blendv_epi8(\n\
    \          pos, _mm256_loadu_si256((const __m256i*)p.mn), mask0);\n      __m256i\
    \ b = _mm256_blendv_epi8(\n          pos, _mm256_loadu_si256((const __m256i*)(p.mn\
    \ + 8)), mask1);\n      __m256i c = _mm256_blendv_epi8(\n          neg, _mm256_loadu_si256((const\
    \ __m256i*)p.mx), mask0);\n      __m256i d = _mm256_blendv_epi8(\n          neg,\
    \ _mm256_loadu_si256((const __m256i*)(p.mx + 8)), mask1);\n      a = _mm256_min_epi32(a,\
    \ b);\n      c = _mm256_max_epi32(c, d);\n      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a,\
    \ a, 1));\n      c = _mm256_max_epi32(c, _mm256_permute2x128_si256(c, c, 1));\n\
    \      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));\n      c = _mm256_max_epi32(c,\
    \ _mm256_shuffle_epi32(c, 0x4e));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a,\
    \ 0xb1));\n      c = _mm256_max_epi32(c, _mm256_shuffle_epi32(c, 0xb1));\n   \
    \   return {_mm256_extract_epi32(a, 0), _mm256_extract_epi32(c, 0)};\n    } else\
    \ {\n      __m256i lo = _mm256_set1_epi64x(l - 1);\n      __m256i hi = _mm256_set1_epi64x(r);\n\
    \      __m256i ix = _mm256_setr_epi64x(0, 1, 2, 3);\n      __m256i iy = _mm256_setr_epi64x(4,\
    \ 5, 6, 7);\n      __m256i mask0 = _mm256_and_si256(\n          _mm256_cmpgt_epi64(ix,\
    \ lo), _mm256_cmpgt_epi64(hi, ix));\n      __m256i mask1 = _mm256_and_si256(\n\
    \          _mm256_cmpgt_epi64(iy, lo), _mm256_cmpgt_epi64(hi, iy));\n      __m256i\
    \ pos = _mm256_set1_epi64x(INF);\n      __m256i neg = _mm256_set1_epi64x(-INF);\n\
    \      __m256i a = _mm256_blendv_epi8(\n          pos, _mm256_loadu_si256((const\
    \ __m256i*)p.mn), mask0);\n      __m256i b = _mm256_blendv_epi8(\n          pos,\
    \ _mm256_loadu_si256((const __m256i*)(p.mn + 4)), mask1);\n      __m256i c = _mm256_blendv_epi8(\n\
    \          neg, _mm256_loadu_si256((const __m256i*)p.mx), mask0);\n      __m256i\
    \ d = _mm256_blendv_epi8(\n          neg, _mm256_loadu_si256((const __m256i*)(p.mx\
    \ + 4)), mask1);\n      a = min64(a, b);\n      c = max64(c, d);\n      a = min64(a,\
    \ _mm256_permute4x64_epi64(a, 0x4e));\n      c = max64(c, _mm256_permute4x64_epi64(c,\
    \ 0x4e));\n      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));\n      c = max64(c,\
    \ _mm256_permute4x64_epi64(c, 0xb1));\n      return {(T)_mm256_extract_epi64(a,\
    \ 0), (T)_mm256_extract_epi64(c, 0)};\n    }\n  }\n#endif\n\n  // 1 \u500B\u306E\
    \u5B50\u306E\u96C6\u7D04\u5024\u306E\u5909\u5316\u3092\u89AA\u3078\u53CD\u6620\
    \u3002\u7247\u5074\u3060\u3051\u304C\u5F71\u97FF\u3092\u53D7\u3051\u308B\u5834\
    \u5408\u306F\n  // min/max \u306E\u5FC5\u8981\u306A\u5074\u3060\u3051\u518D\u8A08\
    \u7B97\u3059\u308B\u3002\n  template <typename FMIN, typename FMAX>\n  void set_by(int\
    \ i, X x, FMIN reduce_min, FMAX reduce_max) {\n    Block& leaf = dat[0][i / B];\n\
    \    const int j = i % B;\n    X old = {leaf.mn[j], leaf.mx[j]};\n    if (old\
    \ == x) return;\n    leaf.mn[j] = x.first;\n    leaf.mx[j] = x.second;\n\n   \
    \ for (int k = 0; k + 1 < (int)dat.size(); ++k) {\n      int b = i / B;\n    \
    \  Block& parent = dat[k + 1][b / B];\n      T& pmin = parent.mn[b % B];\n   \
    \   T& pmax = parent.mx[b % B];\n      X old_p = {pmin, pmax};\n      X new_p\
    \ = old_p;\n\n      if (x.first < old.first) {\n        new_p.first = min(old_p.first,\
    \ x.first);\n      } else if (x.first > old.first && old.first <= old_p.first)\
    \ {\n        new_p.first = reduce_min(dat[k][b].mn);\n      }\n      if (x.second\
    \ > old.second) {\n        new_p.second = max(old_p.second, x.second);\n     \
    \ } else if (x.second < old.second && old.second >= old_p.second) {\n        new_p.second\
    \ = reduce_max(dat[k][b].mx);\n      }\n\n      if (new_p == old_p) break;\n \
    \     pmin = new_p.first;\n      pmax = new_p.second;\n      old = old_p;\n  \
    \    x = new_p;\n      i = b;\n    }\n  }\n\n  template <typename F>\n  X prod_by(int\
    \ l, int r, F reduce) const {\n    X ans = MX::id();\n    for (const auto& level\
    \ : dat) {\n      if (l >= r) break;\n      int a = l / B, b = (r - 1) / B;\n\
    \      if (a == b) {\n        return op(ans, reduce(level[a], l % B, (r - 1) %\
    \ B + 1));\n      }\n      if (l % B) {\n        ans = op(ans, reduce(level[a],\
    \ l % B, B));\n        l = (a + 1) * B;\n      }\n      if (r % B) {\n       \
    \ ans = op(ans, reduce(level[b], 0, r % B));\n        r = b * B;\n      }\n  \
    \    l /= B;\n      r /= B;\n    }\n    return ans;\n  }\n\n#if RANGE_MINMAX_AVX2\n\
    \  __attribute__((target(\"avx2\"))) void set_avx2(int i, X x) {\n    set_by(i,\
    \ x, reduce_min_avx2, reduce_max_avx2);\n  }\n\n  __attribute__((target(\"avx2\"\
    ))) X prod_avx2(int l, int r) const {\n    return prod_by(l, r, range_avx2);\n\
    \  }\n#endif\n\n  template <typename F>\n  int descend_right(int k, int i, X sm,\
    \ F& check) const {\n    for (--k; k >= 0; --k) {\n      const auto& p = dat[k][i];\n\
    \      for (int j = 0; j < B; ++j) {\n        X y = op(sm, {p.mn[j], p.mx[j]});\n\
    \        if (!check(y)) {\n          i = B * i + j;\n          break;\n      \
    \  }\n        sm = y;\n      }\n    }\n    return min(i, n);\n  }\n\n  template\
    \ <typename F>\n  int descend_left(int k, int i, X sm, F& check) const {\n   \
    \ for (--k; k >= 0; --k) {\n      const auto& p = dat[k][i];\n      for (int j\
    \ = B - 1; j >= 0; --j) {\n        X y = op({p.mn[j], p.mx[j]}, sm);\n       \
    \ if (!check(y)) {\n          i = B * i + j;\n          break;\n        }\n  \
    \      sm = y;\n      }\n    }\n    return min(i + 1, n);\n  }\n\n public:\n \
    \ Range_MinMax() { build(0); }\n  Range_MinMax(int m) { build(m); }\n  Range_MinMax(const\
    \ vc<T>& a) { build(a); }\n  Range_MinMax(const vc<X>& a) { build(a); }\n\n  template\
    \ <typename F>\n  Range_MinMax(int m, F f) {\n    build(m, f);\n  }\n\n  void\
    \ build(int m) {\n    build(m, [](int) -> X { return MX::id(); });\n  }\n\n  void\
    \ build(const vc<T>& a) {\n    build((int)a.size(), [&](int i) -> T { return a[i];\
    \ });\n  }\n\n  void build(const vc<X>& a) {\n    build((int)a.size(), [&](int\
    \ i) -> X { return a[i]; });\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    assert(m >= 0);\n    n = m;\n    vc<X> cur(max(m, 1), MX::id());\n\
    \    for (int i = 0; i < m; ++i) cur[i] = as_pair(f(i));\n\n    dat.clear();\n\
    \    while (true) {\n      int sz = ((int)cur.size() + B - 1) / B;\n      dat.emplace_back(sz);\n\
    \      vc<X> nxt(sz, MX::id());\n      for (int b = 0; b < sz; ++b) {\n      \
    \  Block& p = dat.back()[b];\n        fill(p.mn, p.mn + B, INF);\n        fill(p.mx,\
    \ p.mx + B, -INF);\n        for (int j = 0; j < B && b * B + j < (int)cur.size();\
    \ ++j) {\n          p.mn[j] = cur[b * B + j].first;\n          p.mx[j] = cur[b\
    \ * B + j].second;\n        }\n        nxt[b] = {reduce_min_scalar(p.mn), reduce_max_scalar(p.mx)};\n\
    \      }\n      if (cur.size() == 1) break;\n      cur.swap(nxt);\n    }\n\n \
    \   use_avx2 = false;\n#if RANGE_MINMAX_AVX2\n    __builtin_cpu_init();\n    use_avx2\
    \ = __builtin_cpu_supports(\"avx2\");\n#endif\n  }\n\n  X get(int i) const {\n\
    \    assert(0 <= i && i < n);\n    const auto& p = dat[0][i / B];\n    return\
    \ {p.mn[i % B], p.mx[i % B]};\n  }\n\n  vc<X> get_all() const {\n    vc<X> a(n);\n\
    \    for (int i = 0; i < n; ++i) a[i] = get(i);\n    return a;\n  }\n\n  void\
    \ set(int i, const X& x) {\n    assert(0 <= i && i < n);\n#if RANGE_MINMAX_AVX2\n\
    \    if (use_avx2) return set_avx2(i, x);\n#endif\n    set_by(i, x, reduce_min_scalar,\
    \ reduce_max_scalar);\n  }\n\n  void set(int i, T x) { set(i, X{x, x}); }\n\n\
    \  void multiply(int i, const X& x) { set(i, op(get(i), x)); }\n  void multiply(int\
    \ i, T x) { multiply(i, X{x, x}); }\n\n  X prod(int l, int r) const {\n    assert(0\
    \ <= l && l <= r && r <= n);\n#if RANGE_MINMAX_AVX2\n    if (use_avx2) return\
    \ prod_avx2(l, r);\n#endif\n    return prod_by(l, r, range_scalar);\n  }\n\n \
    \ X prod_all() const {\n    const auto& p = dat.back()[0];\n    return {p.mn[0],\
    \ p.mx[0]};\n  }\n\n  template <typename F>\n  int max_right(F check, int L) const\
    \ {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n) return\
    \ n;\n    X sm = MX::id();\n    int i = L;\n    for (int k = 0; k < (int)dat.size();\
    \ ++k) {\n      if (i % B || k + 1 == (int)dat.size()) {\n        int b = i /\
    \ B;\n        for (int j = i % B; j < B; ++j) {\n          const auto& p = dat[k][b];\n\
    \          X y = op(sm, {p.mn[j], p.mx[j]});\n          if (!check(y)) {\n   \
    \         return descend_right(k, b * B + j, sm, check);\n          }\n      \
    \    sm = y;\n        }\n        i = b + 1;\n      } else {\n        i /= B;\n\
    \      }\n    }\n    return n;\n  }\n\n  template <typename F>\n  int min_left(F\
    \ check, int R) const {\n    assert(0 <= R && R <= n && check(MX::id()));\n  \
    \  if (R == 0) return 0;\n    X sm = MX::id();\n    int i = R;\n    for (int k\
    \ = 0; k < (int)dat.size(); ++k) {\n      if (i % B || k + 1 == (int)dat.size())\
    \ {\n        if (i == 0) return 0;\n        int b = (i - 1) / B;\n        for\
    \ (int j = (i - 1) % B; j >= 0; --j) {\n          const auto& p = dat[k][b];\n\
    \          X y = op({p.mn[j], p.mx[j]}, sm);\n          if (!check(y)) {\n   \
    \         return descend_left(k, b * B + j, sm, check);\n          }\n       \
    \   sm = y;\n        }\n        i = b;\n      } else {\n        i /= B;\n    \
    \  }\n    }\n    return 0;\n  }\n};\n\n#undef RANGE_MINMAX_AVX2\n"
  dependsOn:
  - alg/monoid/minmax.hpp
  isVerificationFile: false
  path: ds/segtree/range_minmax.hpp
  requiredBy: []
  timestamp: '2026-11-17 17:35:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/5_ai_generated_test/range_minmax.test.cpp
documentation_of: ds/segtree/range_minmax.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_minmax.hpp
- /library/ds/segtree/range_minmax.hpp.html
title: ds/segtree/range_minmax.hpp
---
