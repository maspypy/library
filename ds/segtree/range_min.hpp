
// 2026/11/04 AI generated.

#if defined(__x86_64__) && (defined(__GNUC__) || defined(__clang__))
#include <immintrin.h>
#define RANGE_MIN_AVX2 1
#else
#define RANGE_MIN_AVX2 0
#endif

template <typename T>
struct Range_Min {
  static_assert(is_same_v<T, int> || is_same_v<T, ll>);
  using value_type = T;

  static constexpr T INF = infty<T>;
  static constexpr int B = 64 / sizeof(T);

  struct alignas(64) Block {
    T a[B];
  };
  static_assert(sizeof(Block) == 64);

  int n = 0;

 private:
  vc<vc<Block>> dat;
  bool use_avx2 = false;

  static T reduce_scalar(const T* p) {
    T x = INF;
    for (int j = 0; j < B; ++j) x = min(x, p[j]);
    return x;
  }

  static T range_scalar(const T* p, int l, int r) {
    T x = INF;
    for (int j = l; j < r; ++j) x = min(x, p[j]);
    return x;
  }

#if RANGE_MIN_AVX2
  __attribute__((target("avx2"))) static __m256i min64(__m256i a, __m256i b) {
    return _mm256_blendv_epi8(a, b, _mm256_cmpgt_epi64(a, b));
  }

  __attribute__((target("avx2"))) static T reduce_avx2(const T* p) {
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

  __attribute__((target("avx2"))) static T range_avx2(
      const T* p, int l, int r) {
    if constexpr (is_same_v<T, int>) {
      __m256i lo = _mm256_set1_epi32(l - 1);
      __m256i hi = _mm256_set1_epi32(r);
      __m256i x = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);
      __m256i y = _mm256_setr_epi32(8, 9, 10, 11, 12, 13, 14, 15);
      __m256i mx = _mm256_and_si256(
          _mm256_cmpgt_epi32(x, lo), _mm256_cmpgt_epi32(hi, x));
      __m256i my = _mm256_and_si256(
          _mm256_cmpgt_epi32(y, lo), _mm256_cmpgt_epi32(hi, y));
      __m256i inf = _mm256_set1_epi32(INF);
      __m256i a =
          _mm256_blendv_epi8(inf, _mm256_loadu_si256((const __m256i*)p), mx);
      __m256i b = _mm256_blendv_epi8(
          inf, _mm256_loadu_si256((const __m256i*)(p + 8)), my);
      a = _mm256_min_epi32(a, b);
      a = _mm256_min_epi32(a, _mm256_permute2x128_si256(a, a, 1));
      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0x4e));
      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));
      return _mm256_extract_epi32(a, 0);
    } else {
      __m256i lo = _mm256_set1_epi64x(l - 1);
      __m256i hi = _mm256_set1_epi64x(r);
      __m256i x = _mm256_setr_epi64x(0, 1, 2, 3);
      __m256i y = _mm256_setr_epi64x(4, 5, 6, 7);
      __m256i mx = _mm256_and_si256(
          _mm256_cmpgt_epi64(x, lo), _mm256_cmpgt_epi64(hi, x));
      __m256i my = _mm256_and_si256(
          _mm256_cmpgt_epi64(y, lo), _mm256_cmpgt_epi64(hi, y));
      __m256i inf = _mm256_set1_epi64x(INF);
      __m256i a =
          _mm256_blendv_epi8(inf, _mm256_loadu_si256((const __m256i*)p), mx);
      __m256i b = _mm256_blendv_epi8(
          inf, _mm256_loadu_si256((const __m256i*)(p + 4)), my);
      a = min64(a, b);
      a = min64(a, _mm256_permute4x64_epi64(a, 0x4e));
      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));
      return (T)_mm256_extract_epi64(a, 0);
    }
  }
#endif

  // min 固有の更新最適化
  template <typename F>
  void set_by(int i, T x, F reduce) {
    T& a = dat[0][i / B].a[i % B];
    T old = a;
    if (old == x) return;
    a = x;

    for (int k = 0; k + 1 < (int)dat.size(); ++k) {
      int b = i / B;
      T& p = dat[k + 1][b / B].a[b % B];
      T old_p = p;
      T new_p;

      if (x < old) {
        new_p = min(old_p, x);
      } else {
        if (old > old_p) break;
        new_p = reduce(dat[k][b].a);
      }

      if (new_p == old_p) break;
      p = new_p;
      old = old_p;
      x = new_p;
      i = b;
    }
  }

  template <typename F>
  T prod_by(int l, int r, F reduce) const {
    T ans = INF;
    for (const auto& level : dat) {
      if (l >= r) break;
      int a = l / B, b = (r - 1) / B;
      if (a == b) {
        return min(ans, reduce(level[a].a, l % B, (r - 1) % B + 1));
      }
      if (l % B) {
        ans = min(ans, reduce(level[a].a, l % B, B));
        l = (a + 1) * B;
      }
      if (r % B) {
        ans = min(ans, reduce(level[b].a, 0, r % B));
        r = b * B;
      }
      l /= B;
      r /= B;
    }
    return ans;
  }

#if RANGE_MIN_AVX2
  __attribute__((target("avx2"))) void set_avx2(int i, T x) {
    set_by(i, x, reduce_avx2);
  }

  __attribute__((target("avx2"))) T prod_avx2(int l, int r) const {
    return prod_by(l, r, range_avx2);
  }
#endif

  // k 段目の失敗した要素から葉へ降りる
  template <typename F>
  int descend_right(int k, int i, T sm, F& check) const {
    for (--k; k >= 0; --k) {
      const auto& v = dat[k][i].a;
      for (int j = 0; j < B; ++j) {
        T y = min(sm, v[j]);
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
  int descend_left(int k, int i, T sm, F& check) const {
    for (--k; k >= 0; --k) {
      const auto& v = dat[k][i].a;
      for (int j = B - 1; j >= 0; --j) {
        T y = min(v[j], sm);
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
  Range_Min() { build(0); }
  Range_Min(int m) { build(m); }
  Range_Min(const vc<T>& a) { build(a); }

  template <typename F>
  Range_Min(int m, F f) {
    build(m, f);
  }

  void build(int m) {
    build(m, [](int) -> T { return INF; });
  }

  void build(const vc<T>& a) {
    build((int)a.size(), [&](int i) -> T { return a[i]; });
  }

  template <typename F>
  void build(int m, F f) {
    assert(m >= 0);
    n = m;
    vc<T> cur(max(m, 1));
    for (int i = 0; i < m; ++i) cur[i] = f(i);
    if (!m) cur[0] = INF;

    dat.clear();
    while (true) {
      int sz = ((int)cur.size() + B - 1) / B;
      dat.emplace_back(sz);
      vc<T> nxt(sz);

      for (int b = 0; b < sz; ++b) {
        T* p = dat.back()[b].a;
        fill(p, p + B, INF);
        for (int j = 0; j < B && b * B + j < (int)cur.size(); ++j) {
          p[j] = cur[b * B + j];
        }
        nxt[b] = reduce_scalar(p);
      }
      if (cur.size() == 1) break;
      cur.swap(nxt);
    }

    use_avx2 = false;
#if RANGE_MIN_AVX2
    __builtin_cpu_init();
    use_avx2 = __builtin_cpu_supports("avx2");
#endif
  }

  T get(int i) const {
    assert(0 <= i && i < n);
    return dat[0][i / B].a[i % B];
  }

  vc<T> get_all() const {
    vc<T> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = dat[0][i / B].a[i % B];
    }
    return a;
  }

  void set(int i, const T& x) {
    assert(0 <= i && i < n);
#if RANGE_MIN_AVX2
    if (use_avx2) return set_avx2(i, x);
#endif
    set_by(i, x, reduce_scalar);
  }

  void multiply(int i, const T& x) { set(i, min(get(i), x)); }

  T prod(int l, int r) const {
    assert(0 <= l && l <= r && r <= n);
#if RANGE_MIN_AVX2
    if (use_avx2) return prod_avx2(l, r);
#endif
    return prod_by(l, r, range_scalar);
  }

  T prod_all() const { return dat.back()[0].a[0]; }

  template <typename F>
  int max_right(F check, int L) const {
    assert(0 <= L && L <= n && check(INF));
    if (L == n) return n;
    T sm = INF;
    int i = L;

    for (int k = 0; k < (int)dat.size(); ++k) {
      if (i % B || k + 1 == (int)dat.size()) {
        int b = i / B;
        for (int j = i % B; j < B; ++j) {
          T y = min(sm, dat[k][b].a[j]);
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
    assert(0 <= R && R <= n && check(INF));
    if (R == 0) return 0;
    T sm = INF;
    int i = R;

    for (int k = 0; k < (int)dat.size(); ++k) {
      if (i % B || k + 1 == (int)dat.size()) {
        if (i == 0) return 0;
        int b = (i - 1) / B;
        for (int j = (i - 1) % B; j >= 0; --j) {
          T y = min(dat[k][b].a[j], sm);
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

#undef RANGE_MIN_AVX2
