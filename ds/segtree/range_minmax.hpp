// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_min.hpp

#include "alg/monoid/minmax.hpp"

// 2026/11/17 AI generated.

// Range_Min / Range_Max と同じ B 分木。各ブロックは min 64B + max 64B。
// 位置 i は Monoid_MinMax<T>::value_type (= pair<T,T>) を持つ。
// 初期値は monoid の単位元 {INF, -INF}。スカラー x は {x,x} として扱う。
// 有効な値域は Monoid_MinMax<T>::id() の番兵に収まる範囲とする。
#if defined(__x86_64__) && (defined(__GNUC__) || defined(__clang__)) && \
    !defined(RANGE_MINMAX_NO_AVX2)
#include <immintrin.h>
#define RANGE_MINMAX_AVX2 1
#else
#define RANGE_MINMAX_AVX2 0
#endif

template <typename T>
struct Range_MinMax {
  static_assert(is_same_v<T, int> || is_same_v<T, ll>);
  using MX = Monoid_MinMax<T>;
  using value_type = typename MX::value_type;
  using X = value_type;

  static constexpr T INF = infty<T>;
  static constexpr int B = 64 / sizeof(T);

  struct alignas(64) Block {
    T mn[B], mx[B];
  };
  static_assert(sizeof(Block) == 128);

  int n = 0;

 private:
  vc<vc<Block>> dat;
  bool use_avx2 = false;

  static X as_pair(T x) { return {x, x}; }
  static X as_pair(X x) { return x; }

  static X op(X a, X b) {
    return {min(a.first, b.first), max(a.second, b.second)};
  }

  static T reduce_min_scalar(const T* p) {
    T x = INF;
    for (int j = 0; j < B; ++j) x = min(x, p[j]);
    return x;
  }

  static T reduce_max_scalar(const T* p) {
    T x = -INF;
    for (int j = 0; j < B; ++j) x = max(x, p[j]);
    return x;
  }

  static X range_scalar(const Block& p, int l, int r) {
    X x = MX::id();
    for (int j = l; j < r; ++j) {
      x.first = min(x.first, p.mn[j]);
      x.second = max(x.second, p.mx[j]);
    }
    return x;
  }

#if RANGE_MINMAX_AVX2
  __attribute__((target("avx2"))) static __m256i min64(__m256i a, __m256i b) {
    return _mm256_blendv_epi8(a, b, _mm256_cmpgt_epi64(a, b));
  }

  __attribute__((target("avx2"))) static __m256i max64(__m256i a, __m256i b) {
    return _mm256_blendv_epi8(a, b, _mm256_cmpgt_epi64(b, a));
  }

  __attribute__((target("avx2"))) static T reduce_min_avx2(const T* p) {
    if constexpr (is_same_v<T, int>) {
      __m256i a = _mm256_loadu_si256((const __m256i*)p);
      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 8));
      a = _mm256_min_epi32(a, b);
      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a, a, 1));
      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));
      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));
      return _mm256_extract_epi32(a, 0);
    } else {
      __m256i a = _mm256_loadu_si256((const __m256i*)p);
      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));
      a = min64(a, b);
      a = min64(a, _mm256_permute4x64_epi64(a, 0x4e));
      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));
      return (T)_mm256_extract_epi64(a, 0);
    }
  }

  __attribute__((target("avx2"))) static T reduce_max_avx2(const T* p) {
    if constexpr (is_same_v<T, int>) {
      __m256i a = _mm256_loadu_si256((const __m256i*)p);
      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 8));
      a = _mm256_max_epi32(a, b);
      a = _mm256_max_epi32(a, _mm256_permute2x128_si256(a, a, 1));
      a = _mm256_max_epi32(a, _mm256_shuffle_epi32(a, 0x4e));
      a = _mm256_max_epi32(a, _mm256_shuffle_epi32(a, 0xb1));
      return _mm256_extract_epi32(a, 0);
    } else {
      __m256i a = _mm256_loadu_si256((const __m256i*)p);
      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));
      a = max64(a, b);
      a = max64(a, _mm256_permute4x64_epi64(a, 0x4e));
      a = max64(a, _mm256_permute4x64_epi64(a, 0xb1));
      return (T)_mm256_extract_epi64(a, 0);
    }
  }

  // min/max 両方の部分ブロックをマスク付きで集約する。
  __attribute__((target("avx2"))) static X range_avx2(
      const Block& p, int l, int r) {
    if (l == 0 && r == B) {
      return {reduce_min_avx2(p.mn), reduce_max_avx2(p.mx)};
    }
    if constexpr (is_same_v<T, int>) {
      __m256i lo = _mm256_set1_epi32(l - 1);
      __m256i hi = _mm256_set1_epi32(r);
      __m256i ix = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);
      __m256i iy = _mm256_setr_epi32(8, 9, 10, 11, 12, 13, 14, 15);
      __m256i mask0 = _mm256_and_si256(
          _mm256_cmpgt_epi32(ix, lo), _mm256_cmpgt_epi32(hi, ix));
      __m256i mask1 = _mm256_and_si256(
          _mm256_cmpgt_epi32(iy, lo), _mm256_cmpgt_epi32(hi, iy));
      __m256i pos = _mm256_set1_epi32(INF);
      __m256i neg = _mm256_set1_epi32(-INF);
      __m256i a = _mm256_blendv_epi8(
          pos, _mm256_loadu_si256((const __m256i*)p.mn), mask0);
      __m256i b = _mm256_blendv_epi8(
          pos, _mm256_loadu_si256((const __m256i*)(p.mn + 8)), mask1);
      __m256i c = _mm256_blendv_epi8(
          neg, _mm256_loadu_si256((const __m256i*)p.mx), mask0);
      __m256i d = _mm256_blendv_epi8(
          neg, _mm256_loadu_si256((const __m256i*)(p.mx + 8)), mask1);
      a = _mm256_min_epi32(a, b);
      c = _mm256_max_epi32(c, d);
      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a, a, 1));
      c = _mm256_max_epi32(c, _mm256_permute2x128_si256(c, c, 1));
      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));
      c = _mm256_max_epi32(c, _mm256_shuffle_epi32(c, 0x4e));
      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));
      c = _mm256_max_epi32(c, _mm256_shuffle_epi32(c, 0xb1));
      return {_mm256_extract_epi32(a, 0), _mm256_extract_epi32(c, 0)};
    } else {
      __m256i lo = _mm256_set1_epi64x(l - 1);
      __m256i hi = _mm256_set1_epi64x(r);
      __m256i ix = _mm256_setr_epi64x(0, 1, 2, 3);
      __m256i iy = _mm256_setr_epi64x(4, 5, 6, 7);
      __m256i mask0 = _mm256_and_si256(
          _mm256_cmpgt_epi64(ix, lo), _mm256_cmpgt_epi64(hi, ix));
      __m256i mask1 = _mm256_and_si256(
          _mm256_cmpgt_epi64(iy, lo), _mm256_cmpgt_epi64(hi, iy));
      __m256i pos = _mm256_set1_epi64x(INF);
      __m256i neg = _mm256_set1_epi64x(-INF);
      __m256i a = _mm256_blendv_epi8(
          pos, _mm256_loadu_si256((const __m256i*)p.mn), mask0);
      __m256i b = _mm256_blendv_epi8(
          pos, _mm256_loadu_si256((const __m256i*)(p.mn + 4)), mask1);
      __m256i c = _mm256_blendv_epi8(
          neg, _mm256_loadu_si256((const __m256i*)p.mx), mask0);
      __m256i d = _mm256_blendv_epi8(
          neg, _mm256_loadu_si256((const __m256i*)(p.mx + 4)), mask1);
      a = min64(a, b);
      c = max64(c, d);
      a = min64(a, _mm256_permute4x64_epi64(a, 0x4e));
      c = max64(c, _mm256_permute4x64_epi64(c, 0x4e));
      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));
      c = max64(c, _mm256_permute4x64_epi64(c, 0xb1));
      return {(T)_mm256_extract_epi64(a, 0), (T)_mm256_extract_epi64(c, 0)};
    }
  }
#endif

  // 1 個の子の集約値の変化を親へ反映。片側だけが影響を受ける場合は
  // min/max の必要な側だけ再計算する。
  template <typename FMIN, typename FMAX>
  void set_by(int i, X x, FMIN reduce_min, FMAX reduce_max) {
    Block& leaf = dat[0][i / B];
    const int j = i % B;
    X old = {leaf.mn[j], leaf.mx[j]};
    if (old == x) return;
    leaf.mn[j] = x.first;
    leaf.mx[j] = x.second;

    for (int k = 0; k + 1 < (int)dat.size(); ++k) {
      int b = i / B;
      Block& parent = dat[k + 1][b / B];
      T& pmin = parent.mn[b % B];
      T& pmax = parent.mx[b % B];
      X old_p = {pmin, pmax};
      X new_p = old_p;

      if (x.first < old.first) {
        new_p.first = min(old_p.first, x.first);
      } else if (x.first > old.first && old.first <= old_p.first) {
        new_p.first = reduce_min(dat[k][b].mn);
      }
      if (x.second > old.second) {
        new_p.second = max(old_p.second, x.second);
      } else if (x.second < old.second && old.second >= old_p.second) {
        new_p.second = reduce_max(dat[k][b].mx);
      }

      if (new_p == old_p) break;
      pmin = new_p.first;
      pmax = new_p.second;
      old = old_p;
      x = new_p;
      i = b;
    }
  }

  template <typename F>
  X prod_by(int l, int r, F reduce) const {
    X ans = MX::id();
    for (const auto& level : dat) {
      if (l >= r) break;
      int a = l / B, b = (r - 1) / B;
      if (a == b) {
        return op(ans, reduce(level[a], l % B, (r - 1) % B + 1));
      }
      if (l % B) {
        ans = op(ans, reduce(level[a], l % B, B));
        l = (a + 1) * B;
      }
      if (r % B) {
        ans = op(ans, reduce(level[b], 0, r % B));
        r = b * B;
      }
      l /= B;
      r /= B;
    }
    return ans;
  }

#if RANGE_MINMAX_AVX2
  __attribute__((target("avx2"))) void set_avx2(int i, X x) {
    set_by(i, x, reduce_min_avx2, reduce_max_avx2);
  }

  __attribute__((target("avx2"))) X prod_avx2(int l, int r) const {
    return prod_by(l, r, range_avx2);
  }
#endif

  template <typename F>
  int descend_right(int k, int i, X sm, F& check) const {
    for (--k; k >= 0; --k) {
      const auto& p = dat[k][i];
      for (int j = 0; j < B; ++j) {
        X y = op(sm, {p.mn[j], p.mx[j]});
        if (!check(y)) {
          i = B * i + j;
          break;
        }
        sm = y;
      }
    }
    return min(i, n);
  }

  template <typename F>
  int descend_left(int k, int i, X sm, F& check) const {
    for (--k; k >= 0; --k) {
      const auto& p = dat[k][i];
      for (int j = B - 1; j >= 0; --j) {
        X y = op({p.mn[j], p.mx[j]}, sm);
        if (!check(y)) {
          i = B * i + j;
          break;
        }
        sm = y;
      }
    }
    return min(i + 1, n);
  }

 public:
  Range_MinMax() { build(0); }
  Range_MinMax(int m) { build(m); }
  Range_MinMax(const vc<T>& a) { build(a); }
  Range_MinMax(const vc<X>& a) { build(a); }

  template <typename F>
  Range_MinMax(int m, F f) {
    build(m, f);
  }

  void build(int m) {
    build(m, [](int) -> X { return MX::id(); });
  }

  void build(const vc<T>& a) {
    build((int)a.size(), [&](int i) -> T { return a[i]; });
  }

  void build(const vc<X>& a) {
    build((int)a.size(), [&](int i) -> X { return a[i]; });
  }

  template <typename F>
  void build(int m, F f) {
    assert(m >= 0);
    n = m;
    vc<X> cur(max(m, 1), MX::id());
    for (int i = 0; i < m; ++i) cur[i] = as_pair(f(i));

    dat.clear();
    while (true) {
      int sz = ((int)cur.size() + B - 1) / B;
      dat.emplace_back(sz);
      vc<X> nxt(sz, MX::id());
      for (int b = 0; b < sz; ++b) {
        Block& p = dat.back()[b];
        fill(p.mn, p.mn + B, INF);
        fill(p.mx, p.mx + B, -INF);
        for (int j = 0; j < B && b * B + j < (int)cur.size(); ++j) {
          p.mn[j] = cur[b * B + j].first;
          p.mx[j] = cur[b * B + j].second;
        }
        nxt[b] = {reduce_min_scalar(p.mn), reduce_max_scalar(p.mx)};
      }
      if (cur.size() == 1) break;
      cur.swap(nxt);
    }

    use_avx2 = false;
#if RANGE_MINMAX_AVX2
    __builtin_cpu_init();
    use_avx2 = __builtin_cpu_supports("avx2");
#endif
  }

  X get(int i) const {
    assert(0 <= i && i < n);
    const auto& p = dat[0][i / B];
    return {p.mn[i % B], p.mx[i % B]};
  }

  vc<X> get_all() const {
    vc<X> a(n);
    for (int i = 0; i < n; ++i) a[i] = get(i);
    return a;
  }

  void set(int i, const X& x) {
    assert(0 <= i && i < n);
#if RANGE_MINMAX_AVX2
    if (use_avx2) return set_avx2(i, x);
#endif
    set_by(i, x, reduce_min_scalar, reduce_max_scalar);
  }

  void set(int i, T x) { set(i, X{x, x}); }

  void multiply(int i, const X& x) { set(i, op(get(i), x)); }
  void multiply(int i, T x) { multiply(i, X{x, x}); }

  X prod(int l, int r) const {
    assert(0 <= l && l <= r && r <= n);
#if RANGE_MINMAX_AVX2
    if (use_avx2) return prod_avx2(l, r);
#endif
    return prod_by(l, r, range_scalar);
  }

  X prod_all() const {
    const auto& p = dat.back()[0];
    return {p.mn[0], p.mx[0]};
  }

  template <typename F>
  int max_right(F check, int L) const {
    assert(0 <= L && L <= n && check(MX::id()));
    if (L == n) return n;
    X sm = MX::id();
    int i = L;
    for (int k = 0; k < (int)dat.size(); ++k) {
      if (i % B || k + 1 == (int)dat.size()) {
        int b = i / B;
        for (int j = i % B; j < B; ++j) {
          const auto& p = dat[k][b];
          X y = op(sm, {p.mn[j], p.mx[j]});
          if (!check(y)) {
            return descend_right(k, b * B + j, sm, check);
          }
          sm = y;
        }
        i = b + 1;
      } else {
        i /= B;
      }
    }
    return n;
  }

  template <typename F>
  int min_left(F check, int R) const {
    assert(0 <= R && R <= n && check(MX::id()));
    if (R == 0) return 0;
    X sm = MX::id();
    int i = R;
    for (int k = 0; k < (int)dat.size(); ++k) {
      if (i % B || k + 1 == (int)dat.size()) {
        if (i == 0) return 0;
        int b = (i - 1) / B;
        for (int j = (i - 1) % B; j >= 0; --j) {
          const auto& p = dat[k][b];
          X y = op({p.mn[j], p.mx[j]}, sm);
          if (!check(y)) {
            return descend_left(k, b * B + j, sm, check);
          }
          sm = y;
        }
        i = b;
      } else {
        i /= B;
      }
    }
    return 0;
  }
};

#undef RANGE_MINMAX_AVX2
