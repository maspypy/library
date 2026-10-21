#include "my_template.hpp"
#include "other/io.hpp"

#include "other/bit.hpp"

/*
01 列を管理する．内部では 64 bit ごとにまとめて保持する．主な用途として，
- 可変長でスライス操作が可能な bitset
- F_2 上の多項式
などを想定している．
*/
struct Bit_Array {
  using T = Bit_Array;
  int N;
  vc<u64> dat;

  // x で埋める
  Bit_Array(int N = 0, int x = 0) : N(N) {
    assert(N >= 0);
    assert(x == 0 || x == 1);
    u64 v = (x == 0 ? 0 : -1);
    dat.assign((N + 63) >> 6, v);
    resize(N);
  }

  int size() const { return N; }

  void resize(int n) {
    assert(n >= 0);
    dat.resize((n + 63) >> 6);
    int r = n & 63;
    if (r) dat.back() &= full_mask(r);
    N = n;
  }

  void fill0() { fill(all(dat), u64(0)); }
  void fill1() {
    fill(all(dat), u64(-1));
    resize(N);
  }

  void push_back(bool b) {
    resize(N + 1);
    (*this)[N - 1] = b;
  }

  static T from_string(const string &S) {
    int N = len(S);
    T ANS(N);
    FOR(i, N) ANS[i] = (S[i] == '1');
    return ANS;
  }

  class Proxy {
   public:
    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}
    operator bool() const { return (dat[index >> 6] >> (index & 63)) & 1; }
    Proxy &operator=(bool value) {
      u64 mask = u64(1) << (index & 63);
      if (value)
        dat[index >> 6] |= mask;
      else
        dat[index >> 6] &= ~mask;
      return *this;
    }
    Proxy &operator=(const Proxy &p) { return *this = bool(p); }

    // bit operations
    Proxy &operator^=(bool x) {
      if (x) dat[index >> 6] ^= u64(1) << (index & 63);
      return *this;
    }
    Proxy &operator|=(bool x) {
      if (x) dat[index >> 6] |= u64(1) << (index & 63);
      return *this;
    }
    Proxy &operator&=(bool x) {
      if (!x) dat[index >> 6] &= ~(u64(1) << (index & 63));
      return *this;
    }
    // finite field F_2
    Proxy &operator+=(bool x) { return *this ^= x; }
    Proxy &operator-=(bool x) { return *this ^= x; }
    Proxy &operator*=(bool x) { return *this &= x; }
    Proxy &operator/=(bool x) {
      assert(x);
      return *this;
    }
    bool inverse() const {
      assert(bool(*this));
      return true;
    }
    void flip() { *this ^= true; }

   private:
    vc<u64> &dat;
    int index;
  };

  Proxy operator[](int i) {
    assert(0 <= i && i < N);
    return Proxy(dat, i);
  }
  bool operator[](int i) const {
    assert(0 <= i && i < N);
    return (dat[i >> 6] >> (i & 63)) & 1;
  }

  bool operator==(const T &p) const {
    if (N != p.N) return false;
    FOR(i, len(dat)) if (dat[i] != p.dat[i]) return false;
    return true;
  }

  T &operator&=(const T &p) {
    assert(N == p.N);
    FOR(i, len(dat)) dat[i] &= p.dat[i];
    return *this;
  }
  T &operator|=(const T &p) {
    assert(N == p.N);
    FOR(i, len(dat)) dat[i] |= p.dat[i];
    return *this;
  }
  T &operator^=(const T &p) {
    assert(N == p.N);
    FOR(i, len(dat)) dat[i] ^= p.dat[i];
    return *this;
  }
  T operator&(const T &p) const { return T(*this) &= p; }
  T operator|(const T &p) const { return T(*this) |= p; }
  T operator^(const T &p) const { return T(*this) ^= p; }
  T operator~() const {
    T p = (*this);
    p.flip_range(0, N);
    return p;
  }

  void set_minus_inplace(const T &other) {
    assert(N == other.N);
    FOR(i, len(dat)) dat[i] = dat[i] & (~other.dat[i]);
  }

  T set_minus(T other) const {
    assert(N == other.N);
    FOR(i, len(dat)) other.dat[i] = dat[i] & ~other.dat[i];
    return other;
  }

  int count() const {
    int ans = 0;
    for (u64 val : dat) ans += popcnt(val);
    return ans;
  }

  // size of set intersection, not modulo 2
  int dot(const T &p) const {
    assert(N == p.N);
    int ans = 0;
    FOR(i, len(dat)) ans += popcnt(dat[i] & p.dat[i]);
    return ans;
  }

  // minimum j >= i with (*this)[j] = 1, or N if none
  int next(int i) const {
    chmax(i, 0);
    if (i >= N) return N;
    int k = i >> 6;
    {
      u64 x = dat[k];
      int s = i & 63;
      x = (x >> s) << s;
      if (x) return (k << 6) | lowbit(x);
    }
    FOR(idx, k + 1, len(dat)) {
      if (dat[idx] == 0) continue;
      return (idx << 6) | lowbit(dat[idx]);
    }
    return N;
  }

  // maximum j <= i with (*this)[j] = 1, or -1 if none
  int prev(int i) const {
    chmin(i, N - 1);
    if (i <= -1) return -1;
    int k = i >> 6;
    if ((i & 63) < 63) {
      u64 x = dat[k];
      x &= (u64(1) << ((i & 63) + 1)) - 1;
      if (x) return (k << 6) | topbit(x);
      --k;
    }
    FOR_R(idx, k + 1) {
      if (dat[idx] == 0) continue;
      return (idx << 6) | topbit(dat[idx]);
    }
    return -1;
  }

  Bit_Array slice(int L, int R) const {
    assert(0 <= L && L <= R && R <= N);
    Bit_Array p(R - L);
    int rm = (R - L) & 63;
    FOR(rm) {
      int j = R - L - 1;
      p.dat[j >> 6] |= u64((dat[(R - 1) >> 6] >> ((R - 1) & 63)) & 1)
                       << (j & 63);
      --R;
    }
    int n = (R - L) >> 6;
    int hi = L & 63;
    int lo = 64 - hi;
    int s = L >> 6;
    if (hi == 0) {
      FOR(i, n) { p.dat[i] = dat[s + i]; }
    } else {
      FOR(i, n) { p.dat[i] = (dat[s + i] >> hi) | (dat[s + i + 1] << lo); }
    }
    return p;
  }

  int count_range(int L, int R) const {
    assert(0 <= L && L <= R && R <= N);
    int cnt = 0;
    while ((L < R) && (L & 63)) cnt += (*this)[L++];
    while ((L < R) && (R & 63)) cnt += (*this)[--R];
    int l = L >> 6, r = R >> 6;
    FOR(i, l, r) cnt += popcnt(dat[i]);
    return cnt;
  }

  /*
  OP = 0: assign, 1: or, 2: xor, 3: and.
  自己参照かつ重複する区間だけを退避する。非重複の場合は入力・出力を直接
  扱い、通常ケースの word loop を単純に保つ。
  */
  template <int OP>
  void apply_to_range(
      int L, int R, const Bit_Array &other, int L1 = -1, int R1 = -1) {
    static_assert(0 <= OP && OP < 4);
    assert(0 <= L && L <= R && R <= N);
    if (L1 == -1) L1 = 0, R1 = other.N;
    assert(0 <= L1 && L1 <= R1 && R1 <= other.N);
    assert(R - L == R1 - L1);

    if (&other == this && max(L, L1) < min(R, R1)) {
      Bit_Array tmp = other.slice(L1, R1);
      apply_to_range<OP>(L, R, tmp);
      return;
    }

    auto apply_bit = [&](int i, bool x) {
      u64 bit = u64(x) << (i & 63);
      if constexpr (OP == 0)
        dat[i >> 6] = (dat[i >> 6] & ~(u64(1) << (i & 63))) | bit;
      if constexpr (OP == 1) dat[i >> 6] |= bit;
      if constexpr (OP == 2) dat[i >> 6] ^= bit;
      if constexpr (OP == 3) dat[i >> 6] &= ~(u64(!x) << (i & 63));
    };
    auto apply_word = [&](int i, u64 x) {
      if constexpr (OP == 0) dat[i] = x;
      if constexpr (OP == 1) dat[i] |= x;
      if constexpr (OP == 2) dat[i] ^= x;
      if constexpr (OP == 3) dat[i] &= x;
    };
    auto get_bit = [&](int i) -> bool {
      return (other.dat[i >> 6] >> (i & 63)) & 1;
    };

    while (L < R && (L & 63)) apply_bit(L++, get_bit(L1++));
    int n = (R - L) >> 6;
    int l = L >> 6, s = L1 >> 6, sh = L1 & 63;
    if (sh == 0) {
      FOR(i, n) apply_word(l + i, other.dat[s + i]);
    } else {
      int lo = 64 - sh;
      FOR(i, n) {
        apply_word(
            l + i, (other.dat[s + i] >> sh) | (other.dat[s + i + 1] << lo));
      }
    }
    L += 64 * n, L1 += 64 * n;
    while (L < R) apply_bit(L++, get_bit(L1++));
  }

  void assign_to_range(
      int L, int R, const Bit_Array &other, int L1 = -1, int R1 = -1) {
    apply_to_range<0>(L, R, other, L1, R1);
  }
  void or_to_range(
      int L, int R, const Bit_Array &other, int L1 = -1, int R1 = -1) {
    apply_to_range<1>(L, R, other, L1, R1);
  }
  void xor_to_range(
      int L, int R, const Bit_Array &other, int L1 = -1, int R1 = -1) {
    apply_to_range<2>(L, R, other, L1, R1);
  }
  void and_to_range(
      int L, int R, const Bit_Array &other, int L1 = -1, int R1 = -1) {
    apply_to_range<3>(L, R, other, L1, R1);
  }

  // p は [i:N) にしかないとして p を xor する
  // 行列基本変形などで利用可能
  void xor_suffix(int i, const Bit_Array &p) {
    assert(N == p.N && 0 <= i && i < N);
    FOR(k, i / 64, len(dat)) { dat[k] ^= p.dat[k]; }
  }

  // [L,R) を 1 に変更
  void set_range(int L, int R) {
    assert(0 <= L && L <= R && R <= N);
    while (L < R && (L & 63)) set(L++);
    while (L < R && (R & 63)) set(--R);
    FOR(i, L >> 6, R >> 6) dat[i] = u64(-1);
  }

  // [L,R) を 0 に変更
  void reset_range(int L, int R) {
    assert(0 <= L && L <= R && R <= N);
    while (L < R && (L & 63)) reset(L++);
    while (L < R && (R & 63)) reset(--R);
    FOR(i, L >> 6, R >> 6) dat[i] = u64(0);
  }

  // [L,R) を flip
  void flip_range(int L, int R) {
    assert(0 <= L && L <= R && R <= N);
    while (L < R && (L & 63)) flip(L++);
    while (L < R && (R & 63)) flip(--R);
    FOR(i, L >> 6, R >> 6) dat[i] ^= u64(-1);
  }

  // bitset に仕様を合わせる
  void set(int i) { (*this)[i] = 1; }
  void reset(int i) { (*this)[i] = 0; }
  void flip(int i) { (*this)[i].flip(); }
  void set() { set_range(0, N); }
  void reset() { reset_range(0, N); }
  void flip() { flip_range(0, N); }
  bool any() const {
    FOR(i, len(dat)) {
      if (dat[i]) return true;
    }
    return false;
  }

  bool has_intersection(const T &other) const {
    assert(N == other.N);
    FOR(i, len(dat)) if (dat[i] & other.dat[i]) return true;
    return false;
  }

  template <typename F>
  void enumerate_intersection(const T &other, F f) const {
    assert(N == other.N);
    bool end = false;
    FOR(i, len(dat)) {
      u64 x = dat[i] & other.dat[i];
      while (x) {
        int k = lowbit(x);
        f(64 * i + k, end);
        if (end) return;
        x &= x - 1;
      }
    }
  }

  bool ALL() const {
    int r = N & 63;
    if (r != 0 && dat.back() != full_mask(r)) return 0;
    for (int i = 0; i < N / 64; ++i)
      if (dat[i] != u64(-1)) return false;
    return true;
  }

  Bit_Array reversed() const {
    int M = ceil(N, 64) * 64;
    Bit_Array a = *this;
    a.resize(M);
    reverse(all(a.dat));
    for (u64 &x : a.dat) x = bit_reverse(x);
    return a.slice(M - N, M);
  }

  // bs[i]==true であるような i 全体
  vc<int> collect_idx() const {
    vc<int> I;
    FOR(i, N) if ((*this)[i]) I.eb(i);
    return I;
  }

  bool is_subset(const T &other) const {
    assert(other.N == N);
    FOR(i, len(dat)) {
      u64 a = dat[i], b = other.dat[i];
      if ((a & b) != a) return false;
    }
    return true;
  }

  int _Find_first() const { return next(0); }
  int _Find_next(int p) const { return next(p + 1); }

  template <typename F>
  void enumerate(int L, int R, F f) const {
    assert(0 <= L && L <= R && R <= N);
    if (L == R) return;
    int p = ((*this)[L] ? L : _Find_next(L));
    while (p < R) {
      f(p);
      p = _Find_next(p);
    }
  }

  inline static string TO_STR[256];
  string to_string() const {
    if (TO_STR[0].empty()) precompute();
    string S;
    for (u64 x : dat) {
      FOR(i, 8) S += TO_STR[(x >> (8 * i) & 255)];
    }
    S.resize(N);
    return S;
  }

  static void precompute() {
    FOR(s, 256) {
      string x;
      FOR(i, 8) x += '0' + (s >> i & 1);
      TO_STR[s] = x;
    }
  }

  void prefix_xor_sum() {
    int carry = 0;
    for (u64 &a : dat) {
      a ^= carry;
      carry = __builtin_parityll(a);
      a ^= a << (1 << 0);
      a ^= a << (1 << 1);
      a ^= a << (1 << 2);
      a ^= a << (1 << 3);
      a ^= a << (1 << 4);
      a ^= a << (1 << 5);
    }
    resize(N);
  }
};
