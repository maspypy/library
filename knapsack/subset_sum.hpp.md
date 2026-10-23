---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/bit_array.hpp
    title: ds/bit_array.hpp
  - icon: ':question:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/subset_sum.test.cpp
    title: test/1_mytest/subset_sum.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/4_2.test.cpp
    title: test/3_yukicoder/4_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/755/problem/F
    - https://github.com/maspypy/library/blob/main/knapsack/subset_sum.hpp
  bundledCode: "#line 1 \"knapsack/subset_sum.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/knapsack/subset_sum.hpp\n\
    #line 1 \"ds/bit_array.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/bit_array.hpp\n\
    /*\n01 \u5217\u3092\u7BA1\u7406\u3059\u308B\uFF0E\u5185\u90E8\u3067\u306F 64 bit\
    \ \u3054\u3068\u306B\u307E\u3068\u3081\u3066\u4FDD\u6301\u3059\u308B\uFF0E\u4E3B\
    \u306A\u7528\u9014\u3068\u3057\u3066\uFF0C\n- \u53EF\u5909\u9577\u3067\u30B9\u30E9\
    \u30A4\u30B9\u64CD\u4F5C\u304C\u53EF\u80FD\u306A bitset\n- F_2 \u4E0A\u306E\u591A\
    \u9805\u5F0F\n\u306A\u3069\u3092\u60F3\u5B9A\u3057\u3066\u3044\u308B\uFF0E\n*/\n\
    struct Bit_Array {\n  using T = Bit_Array;\n  int N;\n  vc<u64> dat;\n\n  // x\
    \ \u3067\u57CB\u3081\u308B\n  Bit_Array(int N = 0, int x = 0) : N(N) {\n    assert(0\
    \ <= N && N <= INT_MAX - 63);\n    assert(x == 0 || x == 1);\n    u64 v = (x ==\
    \ 0 ? 0 : -1);\n    dat.assign((N + 63) >> 6, v);\n    resize(N);\n  }\n\n  int\
    \ size() const { return N; }\n\n  void resize(int n) {\n    assert(0 <= n && n\
    \ <= INT_MAX - 63);\n    dat.resize((n + 63) >> 6);\n    int r = n & 63;\n   \
    \ if (r) dat.back() &= full_mask(r);\n    N = n;\n  }\n\n  void fill0() { fill(all(dat),\
    \ u64(0)); }\n  void fill1() {\n    fill(all(dat), u64(-1));\n    resize(N);\n\
    \  }\n\n  void push_back(bool b) {\n    resize(N + 1);\n    (*this)[N - 1] = b;\n\
    \  }\n\n  static T from_string(const string &S) {\n    int N = len(S);\n    T\
    \ ANS(N);\n    FOR(i, N) ANS[i] = (S[i] == '1');\n    return ANS;\n  }\n\n  class\
    \ Proxy {\n   public:\n    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}\n  \
    \  operator bool() const { return (dat[index >> 6] >> (index & 63)) & 1; }\n \
    \   Proxy &operator=(bool value) {\n      u64 mask = u64(1) << (index & 63);\n\
    \      if (value)\n        dat[index >> 6] |= mask;\n      else\n        dat[index\
    \ >> 6] &= ~mask;\n      return *this;\n    }\n    Proxy &operator=(const Proxy\
    \ &p) { return *this = bool(p); }\n\n    // bit operations\n    Proxy &operator^=(bool\
    \ x) {\n      if (x) dat[index >> 6] ^= u64(1) << (index & 63);\n      return\
    \ *this;\n    }\n    Proxy &operator|=(bool x) {\n      if (x) dat[index >> 6]\
    \ |= u64(1) << (index & 63);\n      return *this;\n    }\n    Proxy &operator&=(bool\
    \ x) {\n      if (!x) dat[index >> 6] &= ~(u64(1) << (index & 63));\n      return\
    \ *this;\n    }\n    // finite field F_2\n    Proxy &operator+=(bool x) { return\
    \ *this ^= x; }\n    Proxy &operator-=(bool x) { return *this ^= x; }\n    Proxy\
    \ &operator*=(bool x) { return *this &= x; }\n    Proxy &operator/=(bool x) {\n\
    \      assert(x);\n      return *this;\n    }\n    bool inverse() const {\n  \
    \    assert(bool(*this));\n      return true;\n    }\n    void flip() { *this\
    \ ^= true; }\n\n   private:\n    vc<u64> &dat;\n    int index;\n  };\n\n  Proxy\
    \ operator[](int i) {\n    assert(0 <= i && i < N);\n    return Proxy(dat, i);\n\
    \  }\n  bool operator[](int i) const {\n    assert(0 <= i && i < N);\n    return\
    \ (dat[i >> 6] >> (i & 63)) & 1;\n  }\n\n  bool operator==(const T &p) const {\n\
    \    if (N != p.N) return false;\n    FOR(i, len(dat)) if (dat[i] != p.dat[i])\
    \ return false;\n    return true;\n  }\n\n  T &operator&=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] &= p.dat[i];\n    return *this;\n  }\n\
    \  T &operator|=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i]\
    \ |= p.dat[i];\n    return *this;\n  }\n  T &operator^=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] ^= p.dat[i];\n    return *this;\n  }\n\
    \  T operator&(const T &p) const { return T(*this) &= p; }\n  T operator|(const\
    \ T &p) const { return T(*this) |= p; }\n  T operator^(const T &p) const { return\
    \ T(*this) ^= p; }\n  T operator~() const {\n    T p = (*this);\n    p.flip_range(0,\
    \ N);\n    return p;\n  }\n\n  void set_minus_inplace(const T &other) {\n    assert(N\
    \ == other.N);\n    FOR(i, len(dat)) dat[i] = dat[i] & (~other.dat[i]);\n  }\n\
    \n  T set_minus(T other) const {\n    assert(N == other.N);\n    FOR(i, len(dat))\
    \ other.dat[i] = dat[i] & ~other.dat[i];\n    return other;\n  }\n\n  int count()\
    \ const {\n    int ans = 0;\n    for (u64 val : dat) ans += popcnt(val);\n   \
    \ return ans;\n  }\n\n  // size of set intersection, not modulo 2\n  int dot(const\
    \ T &p) const {\n    assert(N == p.N);\n    int ans = 0;\n    FOR(i, len(dat))\
    \ ans += popcnt(dat[i] & p.dat[i]);\n    return ans;\n  }\n\n  // minimum j >=\
    \ i with (*this)[j] = 1, or N if none\n  int next(int i) const {\n    chmax(i,\
    \ 0);\n    if (i >= N) return N;\n    int k = i >> 6;\n    {\n      u64 x = dat[k];\n\
    \      int s = i & 63;\n      x = (x >> s) << s;\n      if (x) return (k << 6)\
    \ | lowbit(x);\n    }\n    FOR(idx, k + 1, len(dat)) {\n      if (dat[idx] ==\
    \ 0) continue;\n      return (idx << 6) | lowbit(dat[idx]);\n    }\n    return\
    \ N;\n  }\n\n  // maximum j <= i with (*this)[j] = 1, or -1 if none\n  int prev(int\
    \ i) const {\n    chmin(i, N - 1);\n    if (i <= -1) return -1;\n    int k = i\
    \ >> 6;\n    if ((i & 63) < 63) {\n      u64 x = dat[k];\n      x &= (u64(1) <<\
    \ ((i & 63) + 1)) - 1;\n      if (x) return (k << 6) | topbit(x);\n      --k;\n\
    \    }\n    FOR_R(idx, k + 1) {\n      if (dat[idx] == 0) continue;\n      return\
    \ (idx << 6) | topbit(dat[idx]);\n    }\n    return -1;\n  }\n\n  Bit_Array slice(int\
    \ L, int R) const {\n    assert(0 <= L && L <= R && R <= N);\n    Bit_Array p(R\
    \ - L);\n    int rm = (R - L) & 63;\n    FOR(rm) {\n      int j = R - L - 1;\n\
    \      p.dat[j >> 6] |= u64((dat[(R - 1) >> 6] >> ((R - 1) & 63)) & 1)\n     \
    \                  << (j & 63);\n      --R;\n    }\n    int n = (R - L) >> 6;\n\
    \    int hi = L & 63;\n    int lo = 64 - hi;\n    int s = L >> 6;\n    if (hi\
    \ == 0) {\n      FOR(i, n) { p.dat[i] = dat[s + i]; }\n    } else {\n      FOR(i,\
    \ n) { p.dat[i] = (dat[s + i] >> hi) | (dat[s + i + 1] << lo); }\n    }\n    return\
    \ p;\n  }\n\n  int count_range(int L, int R) const {\n    assert(0 <= L && L <=\
    \ R && R <= N);\n    int cnt = 0;\n    while ((L < R) && (L & 63)) cnt += (*this)[L++];\n\
    \    while ((L < R) && (R & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r =\
    \ R >> 6;\n    FOR(i, l, r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n \
    \ /*\n  OP = 0: assign, 1: or, 2: xor, 3: and.\n  \u81EA\u5DF1\u53C2\u7167\u304B\
    \u3064\u91CD\u8907\u3059\u308B\u533A\u9593\u3060\u3051\u3092\u9000\u907F\u3059\
    \u308B\u3002\u975E\u91CD\u8907\u306E\u5834\u5408\u306F\u5165\u529B\u30FB\u51FA\
    \u529B\u3092\u76F4\u63A5\n  \u6271\u3044\u3001\u901A\u5E38\u30B1\u30FC\u30B9\u306E\
    \ word loop \u3092\u5358\u7D14\u306B\u4FDD\u3064\u3002\n  */\n  template <int\
    \ OP>\n  void apply_to_range(\n      int L, int R, const Bit_Array &other, int\
    \ L1 = -1, int R1 = -1) {\n    static_assert(0 <= OP && OP < 4);\n    assert(0\
    \ <= L && L <= R && R <= N);\n    if (L1 == -1) L1 = 0, R1 = other.N;\n    assert(0\
    \ <= L1 && L1 <= R1 && R1 <= other.N);\n    assert(R - L == R1 - L1);\n\n    if\
    \ (&other == this && max(L, L1) < min(R, R1)) {\n      Bit_Array tmp = other.slice(L1,\
    \ R1);\n      apply_to_range<OP>(L, R, tmp);\n      return;\n    }\n\n    auto\
    \ apply_bit = [&](int i, bool x) {\n      u64 bit = u64(x) << (i & 63);\n    \
    \  if constexpr (OP == 0)\n        dat[i >> 6] = (dat[i >> 6] & ~(u64(1) << (i\
    \ & 63))) | bit;\n      if constexpr (OP == 1) dat[i >> 6] |= bit;\n      if constexpr\
    \ (OP == 2) dat[i >> 6] ^= bit;\n      if constexpr (OP == 3) dat[i >> 6] &= ~(u64(!x)\
    \ << (i & 63));\n    };\n    auto apply_word = [&](int i, u64 x) {\n      if constexpr\
    \ (OP == 0) dat[i] = x;\n      if constexpr (OP == 1) dat[i] |= x;\n      if constexpr\
    \ (OP == 2) dat[i] ^= x;\n      if constexpr (OP == 3) dat[i] &= x;\n    };\n\
    \    auto get_bit = [&](int i) -> bool {\n      return (other.dat[i >> 6] >> (i\
    \ & 63)) & 1;\n    };\n\n    while (L < R && (L & 63)) apply_bit(L++, get_bit(L1++));\n\
    \    int n = (R - L) >> 6;\n    int l = L >> 6, s = L1 >> 6, sh = L1 & 63;\n \
    \   if (sh == 0) {\n      FOR(i, n) apply_word(l + i, other.dat[s + i]);\n   \
    \ } else {\n      int lo = 64 - sh;\n      FOR(i, n) {\n        apply_word(\n\
    \            l + i, (other.dat[s + i] >> sh) | (other.dat[s + i + 1] << lo));\n\
    \      }\n    }\n    L += 64 * n, L1 += 64 * n;\n    while (L < R) apply_bit(L++,\
    \ get_bit(L1++));\n  }\n\n  void assign_to_range(\n      int L, int R, const Bit_Array\
    \ &other, int L1 = -1, int R1 = -1) {\n    apply_to_range<0>(L, R, other, L1,\
    \ R1);\n  }\n  void or_to_range(\n      int L, int R, const Bit_Array &other,\
    \ int L1 = -1, int R1 = -1) {\n    apply_to_range<1>(L, R, other, L1, R1);\n \
    \ }\n  void xor_to_range(\n      int L, int R, const Bit_Array &other, int L1\
    \ = -1, int R1 = -1) {\n    apply_to_range<2>(L, R, other, L1, R1);\n  }\n  void\
    \ and_to_range(\n      int L, int R, const Bit_Array &other, int L1 = -1, int\
    \ R1 = -1) {\n    apply_to_range<3>(L, R, other, L1, R1);\n  }\n\n  // p \u306F\
    \ [i:N) \u306B\u3057\u304B\u306A\u3044\u3068\u3057\u3066 p \u3092 xor \u3059\u308B\
    \n  // \u884C\u5217\u57FA\u672C\u5909\u5F62\u306A\u3069\u3067\u5229\u7528\u53EF\
    \u80FD\n  void xor_suffix(int i, const Bit_Array &p) {\n    assert(N == p.N &&\
    \ 0 <= i && i < N);\n    FOR(k, i / 64, len(dat)) { dat[k] ^= p.dat[k]; }\n  }\n\
    \n  // [L,R) \u3092 1 \u306B\u5909\u66F4\n  void set_range(int L, int R) {\n \
    \   assert(0 <= L && L <= R && R <= N);\n    while (L < R && (L & 63)) set(L++);\n\
    \    while (L < R && (R & 63)) set(--R);\n    FOR(i, L >> 6, R >> 6) dat[i] =\
    \ u64(-1);\n  }\n\n  // [L,R) \u3092 0 \u306B\u5909\u66F4\n  void reset_range(int\
    \ L, int R) {\n    assert(0 <= L && L <= R && R <= N);\n    while (L < R && (L\
    \ & 63)) reset(L++);\n    while (L < R && (R & 63)) reset(--R);\n    FOR(i, L\
    \ >> 6, R >> 6) dat[i] = u64(0);\n  }\n\n  // [L,R) \u3092 flip\n  void flip_range(int\
    \ L, int R) {\n    assert(0 <= L && L <= R && R <= N);\n    while (L < R && (L\
    \ & 63)) flip(L++);\n    while (L < R && (R & 63)) flip(--R);\n    FOR(i, L >>\
    \ 6, R >> 6) dat[i] ^= u64(-1);\n  }\n\n  // bitset \u306B\u4ED5\u69D8\u3092\u5408\
    \u308F\u305B\u308B\n  void set(int i) { (*this)[i] = 1; }\n  void reset(int i)\
    \ { (*this)[i] = 0; }\n  void flip(int i) { (*this)[i].flip(); }\n  void set()\
    \ { set_range(0, N); }\n  void reset() { reset_range(0, N); }\n  void flip() {\
    \ flip_range(0, N); }\n  bool any() const {\n    FOR(i, len(dat)) {\n      if\
    \ (dat[i]) return true;\n    }\n    return false;\n  }\n\n  bool has_intersection(const\
    \ T &other) const {\n    assert(N == other.N);\n    FOR(i, len(dat)) if (dat[i]\
    \ & other.dat[i]) return true;\n    return false;\n  }\n\n  template <typename\
    \ F>\n  void enumerate_intersection(const T &other, F f) const {\n    assert(N\
    \ == other.N);\n    bool end = false;\n    FOR(i, len(dat)) {\n      u64 x = dat[i]\
    \ & other.dat[i];\n      while (x) {\n        int k = lowbit(x);\n        f(64\
    \ * i + k, end);\n        if (end) return;\n        x &= x - 1;\n      }\n   \
    \ }\n  }\n\n  bool ALL() const {\n    int r = N & 63;\n    if (r != 0 && dat.back()\
    \ != full_mask(r)) return 0;\n    for (int i = 0; i < N / 64; ++i)\n      if (dat[i]\
    \ != u64(-1)) return false;\n    return true;\n  }\n\n  Bit_Array reversed() const\
    \ {\n    int M = ceil(N, 64) * 64;\n    Bit_Array a = *this;\n    a.resize(M);\n\
    \    reverse(all(a.dat));\n    for (u64 &x : a.dat) x = bit_reverse(x);\n    return\
    \ a.slice(M - N, M);\n  }\n\n  // bs[i]==true \u3067\u3042\u308B\u3088\u3046\u306A\
    \ i \u5168\u4F53\n  vc<int> collect_idx() const {\n    vc<int> I;\n    FOR(i,\
    \ N) if ((*this)[i]) I.eb(i);\n    return I;\n  }\n\n  bool is_subset(const T\
    \ &other) const {\n    assert(other.N == N);\n    FOR(i, len(dat)) {\n      u64\
    \ a = dat[i], b = other.dat[i];\n      if ((a & b) != a) return false;\n    }\n\
    \    return true;\n  }\n\n  int _Find_first() const { return next(0); }\n  int\
    \ _Find_next(int p) const { return next(p + 1); }\n\n  template <typename F>\n\
    \  void enumerate(int L, int R, F f) const {\n    assert(0 <= L && L <= R && R\
    \ <= N);\n    if (L == R) return;\n    int p = ((*this)[L] ? L : _Find_next(L));\n\
    \    while (p < R) {\n      f(p);\n      p = _Find_next(p);\n    }\n  }\n\n  inline\
    \ static string TO_STR[256];\n  string to_string() const {\n    if (TO_STR[0].empty())\
    \ precompute();\n    string S;\n    for (u64 x : dat) {\n      FOR(i, 8) S +=\
    \ TO_STR[(x >> (8 * i) & 255)];\n    }\n    S.resize(N);\n    return S;\n  }\n\
    \n  static void precompute() {\n    FOR(s, 256) {\n      string x;\n      FOR(i,\
    \ 8) x += '0' + (s >> i & 1);\n      TO_STR[s] = x;\n    }\n  }\n\n  void prefix_xor_sum()\
    \ {\n    int carry = 0;\n    for (u64 &a : dat) {\n      a ^= carry;\n      carry\
    \ = __builtin_parityll(a);\n      a ^= a << (1 << 0);\n      a ^= a << (1 << 1);\n\
    \      a ^= a << (1 << 2);\n      a ^= a << (1 << 3);\n      a ^= a << (1 << 4);\n\
    \      a ^= a << (1 << 5);\n    }\n    resize(N);\n  }\n};\n#line 1 \"enumerate/bits.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/enumerate/bits.hpp\n\
    template <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int\
    \ R, F&& f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename\
    \ UINT, typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n#line 4 \"knapsack/subset_sum.hpp\"\
    \n\n// O(N MAX(vals))\ntemplate <typename T>\nvc<int> subset_sum_solution_1(vc<T>&\
    \ vals, int target) {\n  int n = len(vals);\n  if (n == 0) return {};\n  int mx\
    \ = MAX(vals);\n  int b = 0, sb = 0;\n  while (b < n && sb + vals[b] <= target)\
    \ {\n    sb += vals[b++];\n  }\n  if (b == n && sb != target) return {};\n\n \
    \ int off = target - mx + 1;\n  vc<int> dp(2 * mx, -1);\n  vv(int, PAR, n, 2 *\
    \ mx, -1);\n  dp[sb - off] = b;\n  FOR(i, b, n) {\n    auto newdp = dp;\n    auto&\
    \ par = PAR[i];\n    int a = vals[i];\n    FOR(j, mx) {\n      if (chmax(newdp[j\
    \ + a], dp[j])) {\n        par[j + a] = -2;\n      }\n    }\n    FOR3_R(j, mx,\
    \ 2 * mx) {\n      FOR3_R(k, max(dp[j], 0), newdp[j]) {\n        if (chmax(newdp[j\
    \ - vals[k]], k)) par[j - vals[k]] = k;\n      }\n    }\n    swap(dp, newdp);\n\
    \  }\n  if (dp[mx - 1] == -1) return {};\n  vc<bool> use(n);\n  int i = n - 1,\
    \ j = mx - 1;\n  while (i >= b) {\n    int p = PAR[i][j];\n    if (p == -2) {\n\
    \      use[i] = !use[i];\n      j -= vals[i--];\n    }\n    elif (p == -1) { --i;\
    \ }\n    else {\n      use[p] = !use[p];\n      j += vals[p];\n    }\n  }\n  while\
    \ (i >= 0) {\n    use[i] = !use[i];\n    --i;\n  }\n  vc<int> I;\n  FOR(i, n)\
    \ if (use[i]) I.eb(i);\n\n  ll sm = 0;\n  for (auto&& i : I) sm += vals[i];\n\
    \  assert(sm == target);\n\n  return I;\n}\n\n// O(N target / w)\ntemplate <typename\
    \ T>\nvc<int> subset_sum_solution_2(vc<T>& vals, int target) {\n  int n = len(vals);\n\
    \  auto I = argsort(vals);\n  Bit_Array dp(1, 1);\n  vc<int> last(target + 1,\
    \ -1);\n  FOR(k, n) {\n    int v = vals[I[k]];\n    if (v > target) continue;\n\
    \    Bit_Array newdp = dp;\n    int new_size = len(dp) + v;\n    newdp.resize(new_size);\n\
    \    newdp.or_to_range(v, new_size, dp);\n    if (len(newdp) > target + 1) newdp.resize(target\
    \ + 1);\n    // update \u3057\u305F\u3068\u3053\u308D\u3092\u30E1\u30E2\n    FOR(i,\
    \ len(newdp.dat)) {\n      u64 upd = (i < len(dp.dat) ? dp.dat[i] : u64(0)) ^\
    \ newdp.dat[i];\n      enumerate_all_bit<u64>(upd,\n                         \
    \    [&](int p) -> void { last[(i << 6) | p] = I[k]; });\n    }\n    swap(dp,\
    \ newdp);\n  }\n  if (target >= len(dp) || !dp[target]) return {};\n  vc<int>\
    \ ANS;\n  while (target > 0) {\n    int i = last[target];\n    ANS.eb(i);\n  \
    \  target -= vals[i];\n  }\n  return ANS;\n}\n\n// O(sum^{1.5} / w)\n// sum=10^6\
    \ \u3067 150ms\uFF1Ahttps://codeforces.com/contest/755/problem/F\ntemplate <typename\
    \ T>\nvc<int> subset_sum_solution_3(vc<T>& vals, int target) {\n  int SM = SUM<int>(vals);\n\
    \  int N = len(vals);\n  vvc<int> IDS(SM + 1);\n  FOR(i, N) IDS[vals[i]].eb(i);\n\
    \  vc<pair<int, int>> par(N, {-1, -1});\n  vc<int> grp_vals;\n  vc<int> raw_idx;\n\
    \  FOR(x, 1, SM + 1) {\n    auto& I = IDS[x];\n    while (len(I) >= 3) {\n   \
    \   int a = POP(I), b = POP(I);\n      int c = len(par);\n      par.eb(a, b);\n\
    \      IDS[2 * x].eb(c);\n    }\n    for (auto& i : I) {\n      grp_vals.eb(x);\n\
    \      raw_idx.eb(i);\n    }\n  }\n  auto I = subset_sum_solution_2<int>(grp_vals,\
    \ target);\n  vc<int> ANS;\n  for (auto& i : I) {\n    vc<int> st = {raw_idx[i]};\n\
    \    while (len(st)) {\n      auto c = POP(st);\n      if (c < N) {\n        ANS.eb(c);\n\
    \        continue;\n      }\n      auto [a, b] = par[c];\n      st.eb(a), st.eb(b);\n\
    \    }\n  }\n  return ANS;\n}\n\ntemplate <typename T>\nvc<int> subset_sum_solution_4(vc<T>&\
    \ vals, T target) {\n  if (target <= 0) return {};\n  int N = len(vals);\n  int\
    \ M = N / 2;\n\n  auto calc = [&](int L, int R) -> vc<T> {\n    int n = R - L;\n\
    \    vc<T> dp = {0};\n    FOR(i, n) {\n      T a = vals[L + i];\n      vc<T> dp1(len(dp));\n\
    \      FOR(k, len(dp)) dp1[k] = dp[k] + a;\n      vc<T> newdp;\n      merge(all(dp),\
    \ all(dp1), back_inserter(newdp));\n      swap(dp, newdp);\n    }\n    return\
    \ dp;\n  };\n\n  auto restore = [&](int L, int R, T v) -> vc<int> {\n    int n\
    \ = R - L;\n    vc<T> dp(1 << n);\n    FOR(i, n) FOR(s, 1 << i) dp[s | 1 << i]\
    \ = dp[s] + vals[L + i];\n    FOR(s, 1 << n) {\n      if (dp[s] == v) {\n    \
    \    vc<int> I;\n        FOR(i, n) if (s >> i & 1) I.eb(L + i);\n        return\
    \ I;\n      }\n    }\n    assert(0);\n    return {};\n  };\n\n  auto dp1 = calc(0,\
    \ M);\n  auto dp2 = calc(M, N);\n  int t = 0;\n  FOR_R(s, len(dp1)) {\n    while\
    \ (t + 1 < len(dp2) && dp1[s] + dp2[t + 1] <= target) {\n      ++t;\n    }\n \
    \   if (dp1[s] + dp2[t] == target) {\n      vc<int> I1 = restore(0, M, dp1[s]);\n\
    \      vc<int> I2 = restore(M, N, dp2[t]);\n      concat(I1, I2);\n      return\
    \ I1;\n    }\n  }\n  return {};\n}\n\ntemplate <typename T>\nvc<int> subset_sum(vc<T>&\
    \ vals, T target) {\n  if (target <= 0) return {};\n  int n = len(vals);\n  if\
    \ (n == 0) return {};\n  int mx = MAX(vals);\n\n  // \u3057\u304D\u3044\u5024\u306E\
    \u8ABF\u6574\u3092\u3057\u3066\u3044\u306A\u3044\n  // solution 1: O(N mx))\n\
    \  // solution 2: O(N target / w)\n  // solution 3: O(sum^1.5 / w)\n  // solution\
    \ 4: O(2^(N/2))\n  double x1 = double(len(vals)) * mx;\n  double x2 = double(len(vals))\
    \ * target / 500.0;\n  double x3 = pow(SUM<double>(vals), 1.5) / 500.0;\n  double\
    \ x4 = pow(2.0, 0.5 * len(vals));\n  double mi = min({x1, x2, x3, x4});\n  if\
    \ (x1 == mi) return subset_sum_solution_1(vals, target);\n  if (x2 == mi) return\
    \ subset_sum_solution_2(vals, target);\n  if (x3 == mi) return subset_sum_solution_3(vals,\
    \ target);\n  return subset_sum_solution_4(vals, target);\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/knapsack/subset_sum.hpp\n\
    #include \"ds/bit_array.hpp\"\n#include \"enumerate/bits.hpp\"\n\n// O(N MAX(vals))\n\
    template <typename T>\nvc<int> subset_sum_solution_1(vc<T>& vals, int target)\
    \ {\n  int n = len(vals);\n  if (n == 0) return {};\n  int mx = MAX(vals);\n \
    \ int b = 0, sb = 0;\n  while (b < n && sb + vals[b] <= target) {\n    sb += vals[b++];\n\
    \  }\n  if (b == n && sb != target) return {};\n\n  int off = target - mx + 1;\n\
    \  vc<int> dp(2 * mx, -1);\n  vv(int, PAR, n, 2 * mx, -1);\n  dp[sb - off] = b;\n\
    \  FOR(i, b, n) {\n    auto newdp = dp;\n    auto& par = PAR[i];\n    int a =\
    \ vals[i];\n    FOR(j, mx) {\n      if (chmax(newdp[j + a], dp[j])) {\n      \
    \  par[j + a] = -2;\n      }\n    }\n    FOR3_R(j, mx, 2 * mx) {\n      FOR3_R(k,\
    \ max(dp[j], 0), newdp[j]) {\n        if (chmax(newdp[j - vals[k]], k)) par[j\
    \ - vals[k]] = k;\n      }\n    }\n    swap(dp, newdp);\n  }\n  if (dp[mx - 1]\
    \ == -1) return {};\n  vc<bool> use(n);\n  int i = n - 1, j = mx - 1;\n  while\
    \ (i >= b) {\n    int p = PAR[i][j];\n    if (p == -2) {\n      use[i] = !use[i];\n\
    \      j -= vals[i--];\n    }\n    elif (p == -1) { --i; }\n    else {\n     \
    \ use[p] = !use[p];\n      j += vals[p];\n    }\n  }\n  while (i >= 0) {\n   \
    \ use[i] = !use[i];\n    --i;\n  }\n  vc<int> I;\n  FOR(i, n) if (use[i]) I.eb(i);\n\
    \n  ll sm = 0;\n  for (auto&& i : I) sm += vals[i];\n  assert(sm == target);\n\
    \n  return I;\n}\n\n// O(N target / w)\ntemplate <typename T>\nvc<int> subset_sum_solution_2(vc<T>&\
    \ vals, int target) {\n  int n = len(vals);\n  auto I = argsort(vals);\n  Bit_Array\
    \ dp(1, 1);\n  vc<int> last(target + 1, -1);\n  FOR(k, n) {\n    int v = vals[I[k]];\n\
    \    if (v > target) continue;\n    Bit_Array newdp = dp;\n    int new_size =\
    \ len(dp) + v;\n    newdp.resize(new_size);\n    newdp.or_to_range(v, new_size,\
    \ dp);\n    if (len(newdp) > target + 1) newdp.resize(target + 1);\n    // update\
    \ \u3057\u305F\u3068\u3053\u308D\u3092\u30E1\u30E2\n    FOR(i, len(newdp.dat))\
    \ {\n      u64 upd = (i < len(dp.dat) ? dp.dat[i] : u64(0)) ^ newdp.dat[i];\n\
    \      enumerate_all_bit<u64>(upd,\n                             [&](int p) ->\
    \ void { last[(i << 6) | p] = I[k]; });\n    }\n    swap(dp, newdp);\n  }\n  if\
    \ (target >= len(dp) || !dp[target]) return {};\n  vc<int> ANS;\n  while (target\
    \ > 0) {\n    int i = last[target];\n    ANS.eb(i);\n    target -= vals[i];\n\
    \  }\n  return ANS;\n}\n\n// O(sum^{1.5} / w)\n// sum=10^6 \u3067 150ms\uFF1A\
    https://codeforces.com/contest/755/problem/F\ntemplate <typename T>\nvc<int> subset_sum_solution_3(vc<T>&\
    \ vals, int target) {\n  int SM = SUM<int>(vals);\n  int N = len(vals);\n  vvc<int>\
    \ IDS(SM + 1);\n  FOR(i, N) IDS[vals[i]].eb(i);\n  vc<pair<int, int>> par(N, {-1,\
    \ -1});\n  vc<int> grp_vals;\n  vc<int> raw_idx;\n  FOR(x, 1, SM + 1) {\n    auto&\
    \ I = IDS[x];\n    while (len(I) >= 3) {\n      int a = POP(I), b = POP(I);\n\
    \      int c = len(par);\n      par.eb(a, b);\n      IDS[2 * x].eb(c);\n    }\n\
    \    for (auto& i : I) {\n      grp_vals.eb(x);\n      raw_idx.eb(i);\n    }\n\
    \  }\n  auto I = subset_sum_solution_2<int>(grp_vals, target);\n  vc<int> ANS;\n\
    \  for (auto& i : I) {\n    vc<int> st = {raw_idx[i]};\n    while (len(st)) {\n\
    \      auto c = POP(st);\n      if (c < N) {\n        ANS.eb(c);\n        continue;\n\
    \      }\n      auto [a, b] = par[c];\n      st.eb(a), st.eb(b);\n    }\n  }\n\
    \  return ANS;\n}\n\ntemplate <typename T>\nvc<int> subset_sum_solution_4(vc<T>&\
    \ vals, T target) {\n  if (target <= 0) return {};\n  int N = len(vals);\n  int\
    \ M = N / 2;\n\n  auto calc = [&](int L, int R) -> vc<T> {\n    int n = R - L;\n\
    \    vc<T> dp = {0};\n    FOR(i, n) {\n      T a = vals[L + i];\n      vc<T> dp1(len(dp));\n\
    \      FOR(k, len(dp)) dp1[k] = dp[k] + a;\n      vc<T> newdp;\n      merge(all(dp),\
    \ all(dp1), back_inserter(newdp));\n      swap(dp, newdp);\n    }\n    return\
    \ dp;\n  };\n\n  auto restore = [&](int L, int R, T v) -> vc<int> {\n    int n\
    \ = R - L;\n    vc<T> dp(1 << n);\n    FOR(i, n) FOR(s, 1 << i) dp[s | 1 << i]\
    \ = dp[s] + vals[L + i];\n    FOR(s, 1 << n) {\n      if (dp[s] == v) {\n    \
    \    vc<int> I;\n        FOR(i, n) if (s >> i & 1) I.eb(L + i);\n        return\
    \ I;\n      }\n    }\n    assert(0);\n    return {};\n  };\n\n  auto dp1 = calc(0,\
    \ M);\n  auto dp2 = calc(M, N);\n  int t = 0;\n  FOR_R(s, len(dp1)) {\n    while\
    \ (t + 1 < len(dp2) && dp1[s] + dp2[t + 1] <= target) {\n      ++t;\n    }\n \
    \   if (dp1[s] + dp2[t] == target) {\n      vc<int> I1 = restore(0, M, dp1[s]);\n\
    \      vc<int> I2 = restore(M, N, dp2[t]);\n      concat(I1, I2);\n      return\
    \ I1;\n    }\n  }\n  return {};\n}\n\ntemplate <typename T>\nvc<int> subset_sum(vc<T>&\
    \ vals, T target) {\n  if (target <= 0) return {};\n  int n = len(vals);\n  if\
    \ (n == 0) return {};\n  int mx = MAX(vals);\n\n  // \u3057\u304D\u3044\u5024\u306E\
    \u8ABF\u6574\u3092\u3057\u3066\u3044\u306A\u3044\n  // solution 1: O(N mx))\n\
    \  // solution 2: O(N target / w)\n  // solution 3: O(sum^1.5 / w)\n  // solution\
    \ 4: O(2^(N/2))\n  double x1 = double(len(vals)) * mx;\n  double x2 = double(len(vals))\
    \ * target / 500.0;\n  double x3 = pow(SUM<double>(vals), 1.5) / 500.0;\n  double\
    \ x4 = pow(2.0, 0.5 * len(vals));\n  double mi = min({x1, x2, x3, x4});\n  if\
    \ (x1 == mi) return subset_sum_solution_1(vals, target);\n  if (x2 == mi) return\
    \ subset_sum_solution_2(vals, target);\n  if (x3 == mi) return subset_sum_solution_3(vals,\
    \ target);\n  return subset_sum_solution_4(vals, target);\n}\n"
  dependsOn:
  - ds/bit_array.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: knapsack/subset_sum.hpp
  requiredBy: []
  timestamp: '2026-10-23 11:03:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/subset_sum.test.cpp
  - test/3_yukicoder/4_2.test.cpp
documentation_of: knapsack/subset_sum.hpp
layout: document
redirect_from:
- /library/knapsack/subset_sum.hpp
- /library/knapsack/subset_sum.hpp.html
title: knapsack/subset_sum.hpp
---
