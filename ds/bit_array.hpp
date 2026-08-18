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
      p[R - L - 1] = bool((*this)[R - 1]);
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

  // [L,R) に p を代入
  void assign_to_range(int L, int R, const Bit_Array &p) {
    assert(0 <= L && L <= R && R <= N);
    assert(p.N == R - L);
    int a = 0, b = p.N;
    while (L < R && (L & 63)) {
      (*this)[L++] = bool(p[a++]);
    }
    while (L < R && (R & 63)) {
      (*this)[--R] = bool(p[--b]);
    }
    // p[a:b] を [L:R] に
    int l = L >> 6, r = R >> 6;
    int s = a >> 6;
    int n = r - l;
    if (!(a & 63)) {
      FOR(i, n) dat[l + i] = p.dat[s + i];
    } else {
      int hi = a & 63;
      int lo = 64 - hi;
      FOR(i, n) dat[l + i] = (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);
    }
  }

  // [L,R) に p を xor
  void xor_to_range(int L, int R, const Bit_Array &p) {
    assert(0 <= L && L <= R && R <= N);
    assert(p.N == R - L);
    int a = 0, b = p.N;
    while (L < R && (L & 63)) {
      dat[L >> 6] ^= u64(p[a]) << (L & 63);
      ++a, ++L;
    }
    while (L < R && (R & 63)) {
      --b, --R;
      dat[R >> 6] ^= u64(p[b]) << (R & 63);
    }
    // p[a:b] を [L:R] に
    int l = L >> 6, r = R >> 6;
    int s = a >> 6;
    int n = r - l;
    if (!(a & 63)) {
      FOR(i, n) dat[l + i] ^= p.dat[s + i];
    } else {
      int hi = a & 63;
      int lo = 64 - hi;
      FOR(i, n) dat[l + i] ^= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);
    }
  }

  // [L,R) に p を and
  void and_to_range(int L, int R, const Bit_Array &p) {
    assert(0 <= L && L <= R && R <= N);
    assert(p.N == R - L);
    int a = 0, b = p.N;
    while (L < R && (L & 63)) {
      if (!p[a]) (*this)[L] = 0;
      a++, L++;
    }
    while (L < R && (R & 63)) {
      --b, --R;
      if (!p[b]) (*this)[R] = 0;
    }
    // p[a:b] を [L:R] に
    int l = L >> 6, r = R >> 6;
    int s = a >> 6;
    int n = r - l;
    if (!(a & 63)) {
      FOR(i, n) dat[l + i] &= p.dat[s + i];
    } else {
      int hi = a & 63;
      int lo = 64 - hi;
      FOR(i, n) dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);
    }
  }

  // [L,R) に p を or
  void or_to_range(int L, int R, const Bit_Array &p) {
    assert(0 <= L && L <= R && R <= N);
    assert(p.N == R - L);
    int a = 0, b = p.N;
    while (L < R && (L & 63)) {
      dat[L >> 6] |= u64(p[a]) << (L & 63);
      ++a, ++L;
    }
    while (L < R && (R & 63)) {
      --b, --R;
      dat[R >> 6] |= u64(p[b]) << (R & 63);
    }
    // p[a:b] を [L:R] に
    int l = L >> 6, r = R >> 6;
    int s = a >> 6;
    int n = r - l;
    if (!(a & 63)) {
      FOR(i, n) dat[l + i] |= p.dat[s + i];
    } else {
      int hi = a & 63;
      int lo = 64 - hi;
      FOR(i, n) dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);
    }
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