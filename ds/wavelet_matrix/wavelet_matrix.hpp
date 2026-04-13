#include "ds/bit_vector.hpp"
#include "ds/dummy_data_structure.hpp"

template <typename Y, typename SEGTREE>
struct Uncompressed_Wavelet_Matrix {
  using Mono = typename SEGTREE::MX;
  using T = typename Mono::value_type;
  static_assert(Mono::commute);
  static_assert(is_same_v<Y, int> || is_same_v<Y, ll>);
  int n = 0, log = 0;
  vc<int> mid;
  vc<Bit_Vector> bv;
  vc<SEGTREE> seg;
  Y limit;

  Uncompressed_Wavelet_Matrix() = default;

  // f(i) = {A[i], dat[i]}
  template <typename F>
  Uncompressed_Wavelet_Matrix(int n, F f, int log = -1) {
    build(n, f, log);
  }
  Uncompressed_Wavelet_Matrix(const vc<Y>& A, int log = -1) {
    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);
    build(
        len(A), [&](int i) -> pair<Y, T> { return {A[i], Mono::unit()}; }, log);
  }

  template <typename F>
  void build(int n, F f, int log = -1) {
    this->n = n;
    vc<Y> A(n);
    vc<T> S(n);
    FOR(i, n) tie(A[i], S[i]) = f(i);
    if (log == -1) {
      log = (n == 0 ? 0 : topbit(MAX(A)) + 1);
    } else {
      for (auto& x : A) assert(0 <= x && topbit(x) < log);
    }
    this->log = log;
    limit = Y(1) << log;
    if constexpr (is_same_v<Y, int>) assert(0 <= log && log <= 30);
    if constexpr (is_same_v<Y, ll>) assert(0 <= log && log <= 62);
    mid.resize(log), bv.assign(log, Bit_Vector(n));
    vc<Y> A0(n), A1(n);
    vc<T> S0(n), S1(n);
    seg.resize(log + 1);
    seg[log].build(S);
    for (int d = log - 1; d >= 0; --d) {
      int p0 = 0, p1 = 0;
      for (int i = 0; i < n; ++i) {
        if (A[i] >> d & 1) {
          bv[d].set(i), A1[p1] = A[i], S1[p1] = S[i], p1++;
        } else {
          A0[p0] = A[i], S0[p0] = S[i], p0++;
        }
      }
      swap(A, A0), swap(S, S0);
      move(A1.begin(), A1.begin() + p1, A.begin() + p0);
      move(S1.begin(), S1.begin() + p1, S.begin() + p0);
      mid[d] = p0, bv[d].build(), seg[d].build(S);
    }
  }

  tuple<int, int, int, int> get_subtree(int d, int L, int R) const {
    assert(1 <= d && d <= log);
    int a = bv[d - 1].count_prefix(L), b = bv[d - 1].count_prefix(R);
    return {L - a, R - b, mid[d - 1] + a, mid[d - 1] + b};
  }

  template <typename F>
  void work_point(F f, int i) {
    assert(0 <= i && i < n);
    f(log, i);
    FOR_R(d, log) {
      int a = bv[d].count_prefix(i);
      if (bv[d][i]) {
        i = mid[d] + a;
      } else {
        i = i - a;
      }
      f(d, i);
    }
  }

  template <typename F>
  void work_prefix(F f, int L, int R, Y y) const {
    chmin(y, limit);
    if (y == 0) return;
    if (y == limit) {
      f(log, L, R);
      return;
    }
    FOR_R(d, log) {
      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);
      if (y >> d & 1) {
        f(d, L0, R0);
        L = L1, R = R1;
      } else {
        L = L0, R = R0;
      }
    }
  }

  template <typename F>
  void work_range(F f, int L, int R, Y y1, Y y2) const {
    chmin(y2, limit);
    if (y1 >= y2) return;
    assert(0 <= y1 && y1 <= y2 && y2 <= limit);
    if (y1 == 0) return work_prefix(f, L, R, y2);
    auto dfs = [&](auto& dfs, int d, int L, int R, Y y1, Y y2) -> void {
      if (y1 == y2) return;
      if (y1 == 0 && y2 == Y(1) << d) {
        f(d, L, R);
        return;
      }
      assert(d > 0);
      auto [L0, R0, L1, R1] = get_subtree(d, L, R);
      Y m = (Y(1) << (d - 1));

      if (y2 <= m) {
        dfs(dfs, d - 1, L0, R0, y1, y2);
      } else if (y1 >= m) {
        dfs(dfs, d - 1, L1, R1, y1 - m, y2 - m);
      } else {
        dfs(dfs, d - 1, L0, R0, y1, m);
        dfs(dfs, d - 1, L1, R1, 0, y2 - m);
      }
    };
    dfs(dfs, log, L, R, y1, y2);
  }

  // [L,R) x [0,y)
  int prefix_count(int L, int R, Y y) const {
    int cnt = 0;
    work_prefix([&](int d, int a, int b) { cnt += b - a; }, L, R, y);
    return cnt;
  }

  // [L,R) x [y1,y2)
  int count(int L, int R, Y y1, Y y2) const {
    return prefix_count(L, R, y2) - prefix_count(L, R, y1);
  }

  // [L,R) x [0,y)
  T prefix_prod(int L, int R, Y y) const {
    T ans = Mono::unit();
    work_prefix(
        [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); }, L,
        R, y);
    return ans;
  }
  // [L,R) x [y1,y2)
  T prod(int L, int R, Y y1, Y y2) const {
    T ans = Mono::unit();
    work_range(
        [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); }, L,
        R, y1, y2);
    return ans;
  }
  T prod_all(int L, int R) const { return seg[log].prod(L, R); }

  // [L,R) x [0,y)
  pair<int, T> prefix_count_and_prod(int L, int R, Y y) const {
    pair<int, T> ans = {0, Mono::unit()};
    work_prefix(
        [&](int d, int a, int b) {
          ans.fi += b - a;
          ans.se = Mono::op(ans.se, seg[d].prod(a, b));
        },
        L, R, y);
    return ans;
  }
  // [L,R) x [y1,y2)
  pair<int, T> count_and_prod(int L, int R, Y y1, Y y2) const {
    pair<int, T> ans = {0, Mono::unit()};
    work_range(
        [&](int d, int a, int b) {
          ans.fi += b - a;
          ans.se = Mono::op(ans.se, seg[d].prod(a, b));
        },
        L, R, y1, y2);
    return ans;
  }

  Y kth(int L, int R, int k) const {
    assert(0 <= k && k < R - L);
    Y ans = 0;
    for (int d = log - 1; d >= 0; --d) {
      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);
      if (k < R0 - L0) {
        L = L0, R = R0;
      } else {
        ans |= Y(1) << d;
        k -= R0 - L0, L = L1, R = R1;
      }
    }
    return ans;
  }

  template <bool upper>
  Y median(int L, int R) const {
    assert(0 <= L && L < R && R <= n);
    int k = (upper ? (R - L) / 2 : (R - L - 1) / 2);
    return kth(L, R, k);
  }

  void set(int i, T t) {
    assert(0 <= i && i < n);
    work_point([&](int d, int i) { seg[d].set(i, t); }, i);
  }
  void multiply(int i, T t) {
    assert(0 <= i && i < n);
    work_point([&](int d, int i) { seg[d].multiply(i, t); }, i);
  }
  void add(int i, T t) {
    assert(0 <= i && i < n);
    work_point([&](int d, int i) { seg[d].add(i, t); }, i);
  }

  // [L,R) x [0,y) での check(y, cnt, prod) が true となる最大の (Y,cnt,prod)
  template <typename F>
  tuple<Y, int, T> max_right(F check, int L, int R) const {
    assert(limit < infty<Y>);
    int cnt = 0;
    Y y = 0;
    T t = Mono::unit();
    T t_all = seg[log].prod(L, R);
    assert(check(0, 0, Mono::unit()));
    if (check(limit, R - L, t_all)) {
      y = binary_search([&](Y y) -> bool { return check(y, R - L, t_all); },
                        limit, infty<Y> + 1);
      return {y, R - L, t_all};
    }
    for (int d = log - 1; d >= 0; --d) {
      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);
      Y y1 = y | Y(1) << d;
      int cnt1 = cnt + R0 - L0;
      T t1 = Mono::op(t, seg[d].prod(L0, R0));
      if (check(y1, cnt1, t1)) {
        y = y1, cnt = cnt1, t = t1, L = L1, R = R1;
      } else {
        L = L0, R = R0;
      }
    }
    return {y, cnt, t};
  }
};

template <typename Y, typename SEGTREE>
struct Compressed_Wavelet_Matrix {
  using Mono = typename SEGTREE::MX;
  using T = typename Mono::value_type;

  int n = 0;
  vc<Y> key;
  Uncompressed_Wavelet_Matrix<int, SEGTREE> wm;

  Compressed_Wavelet_Matrix() = default;

  // f(i) = {A[i], dat[i]}
  template <typename F>
  Compressed_Wavelet_Matrix(int n, F f) {
    build(n, f);
  }

  Compressed_Wavelet_Matrix(const vc<Y>& A) {
    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);
    build(A);
  }

  template <typename F>
  void build(int n, F f) {
    this->n = n;
    vc<Y> A(n);
    vc<T> S(n);
    FOR(i, n) tie(A[i], S[i]) = f(i);

    key = A;
    UNIQUE(key);

    wm.build(n, [&](int i) -> pair<int, T> {
      int k = LB(key, A[i]);
      return {k, S[i]};
    });
  }

  void build(const vc<Y>& A) {
    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);
    n = len(A);
    key = A;
    UNIQUE(key);

    wm.build(n, [&](int i) -> pair<int, T> {
      int k = LB(key, A[i]);
      return {k, Mono::unit()};
    });
  }

  Y kth(int L, int R, int k) const { return key[wm.kth(L, R, k)]; }

  template <bool upper>
  Y median(int L, int R) const {
    return key[wm.template median<upper>(L, R)];
  }

  // [L,R) x [-inf,y)
  int prefix_count(int L, int R, Y y) const {
    return wm.prefix_count(L, R, LB(key, y));
  }

  // [L,R) x [y1,y2)
  int count(int L, int R, Y y1, Y y2) const {
    return wm.count(L, R, LB(key, y1), LB(key, y2));
  }

  // [L,R) x [-inf,y)
  T prefix_prod(int L, int R, Y y) const {
    return wm.prefix_prod(L, R, LB(key, y));
  }

  // [L,R) x [y1,y2)
  T prod(int L, int R, Y y1, Y y2) const {
    return wm.prod(L, R, LB(key, y1), LB(key, y2));
  }

  T prod_all(int L, int R) const { return wm.prod_all(L, R); }

  // [L,R) x [-inf,y)
  pair<int, T> prefix_count_and_prod(int L, int R, Y y) const {
    return wm.prefix_count_and_prod(L, R, LB(key, y));
  }

  // [L,R) x [y1,y2)
  pair<int, T> count_and_prod(int L, int R, Y y1, Y y2) const {
    return wm.count_and_prod(L, R, LB(key, y1), LB(key, y2));
  }

  void set(int i, T t) { wm.set(i, t); }

  void multiply(int i, T t) { wm.multiply(i, t); }

  void add(int i, T t) { wm.add(i, t); }
};

template <typename Y, bool compress, typename SEGTREE = Dummy_Data_Structure>
using Wavelet_Matrix =
    conditional_t<compress, Compressed_Wavelet_Matrix<Y, SEGTREE>,
                  Uncompressed_Wavelet_Matrix<Y, SEGTREE>>;
