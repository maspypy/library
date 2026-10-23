---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/bit_array.hpp
    title: ds/bit_array.hpp
  - icon: ':warning:'
    path: poly/mod_2/convolution.hpp
    title: poly/mod_2/convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/poly/mod_2/power_projection.hpp
  bundledCode: "#line 1 \"poly/mod_2/power_projection.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/poly/mod_2/power_projection.hpp\n\
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
    \      a ^= a << (1 << 5);\n    }\n    resize(N);\n  }\n};\n#line 1 \"poly/mod_2/convolution.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/poly/mod_2/convolution.hpp\n\
    #include <wmmintrin.h>\n\n#line 1 \"ds/bit_array.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/bit_array.hpp\n\
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
    \      a ^= a << (1 << 5);\n    }\n    resize(N);\n  }\n};\n#line 5 \"poly/mod_2/convolution.hpp\"\
    \n\nconstexpr int CLMUL_TH = 8;\n\n__attribute__((target(\"pclmul\"))) void clmul_naive(\n\
    \    const u64* a, int n, const u64* b, int m, u64* c) {\n  FOR(i, n) FOR(j, m)\
    \ {\n    __m128i A = _mm_set_epi64x(0, a[i]);\n    __m128i B = _mm_set_epi64x(0,\
    \ b[j]);\n    __m128i C = _mm_clmulepi64_si128(A, B, 0x00);\n\n    alignas(16)\
    \ u64 w[2];\n    _mm_store_si128((__m128i*)w, C);\n\n    c[i + j] ^= w[0];\n \
    \   c[i + j + 1] ^= w[1];\n  }\n}\n\n// a,b: n words, n \u306F 2 \u51AA\n// c:\
    \ 2n words, \u547C\u3073\u51FA\u3057\u6642\u70B9\u3067\u5168\u90E8 0\n// scratch:\
    \ 4n words\n__attribute__((target(\"pclmul\"))) void clmul_karatsuba_rec(\n  \
    \  const u64* a, const u64* b, u64* c, int n, u64* scratch) {\n  if (n <= CLMUL_TH)\
    \ {\n    clmul_naive(a, n, b, n, c);\n    return;\n  }\n\n  int m = n / 2;\n\n\
    \  // z0 = a0*b0\n  clmul_karatsuba_rec(a, b, c, m, scratch);\n  // z2 = a1*b1\n\
    \  clmul_karatsuba_rec(a + m, b + m, c + 2 * m, m, scratch);\n  u64* sa = scratch;\n\
    \  u64* sb = scratch + m;\n  u64* z1 = scratch + 2 * m;\n  u64* sub = scratch\
    \ + 4 * m;\n  FOR(i, m) {\n    sa[i] = a[i] ^ a[m + i];\n    sb[i] = b[i] ^ b[m\
    \ + i];\n  }\n  fill(z1, z1 + 2 * m, u64(0));\n  clmul_karatsuba_rec(sa, sb, z1,\
    \ m, sub);\n  FOR(i, 2 * m) z1[i] ^= c[i] ^ c[2 * m + i];\n  FOR(i, 2 * m) c[m\
    \ + i] ^= z1[i];\n}\n\n// c \u306F A+B words \u4EE5\u4E0A\u3042\u308A\u3001\u3042\
    \u3089\u304B\u3058\u3081 0 \u306B\u3057\u3066\u304A\u304F\u3002\n__attribute__((target(\"\
    pclmul\"))) void clmul_rec(\n    const u64* a, int A, const u64* b, int B, u64*\
    \ c) {\n  if (A > B) {\n    clmul_rec(b, B, a, A, c);\n    return;\n  }\n\n  //\
    \ A <= B\n  if (A <= CLMUL_TH) {\n    clmul_naive(a, A, b, B, c);\n    return;\n\
    \  }\n\n  if (2 * A <= B) {\n    // b = b0 + x^(B-A) b1\n    // |b0| = B-A, |b1|\
    \ = A\n    int M = B - A;\n\n    clmul_rec(a, A, b, M, c);\n    clmul_rec(a, A,\
    \ b + M, A, c + M);\n    return;\n  }\n\n  // A <= B < 2A\n  assert(A <= B &&\
    \ B < 2 * A);\n  int n = 1;\n  while (n < B) n <<= 1;\n  vc<u64> x(n), y(n), z(2\
    \ * n), scratch(4 * n);\n  copy(a, a + A, x.begin());\n  copy(b, b + B, y.begin());\n\
    \  clmul_karatsuba_rec(x.data(), y.data(), z.data(), n, scratch.data());\n  FOR(i,\
    \ A + B) c[i] ^= z[i];\n}\n\n__attribute__((target(\"pclmul\"))) Bit_Array convolution(\n\
    \    const Bit_Array& a, const Bit_Array& b) {\n  int na = a.size(), nb = b.size();\n\
    \  if (!na || !nb) return {};\n\n  int A = len(a.dat), B = len(b.dat);\n  // clmul_rec\
    \ \u306F A+B words \u306B\u66F8\u304D\u8FBC\u3080\u53EF\u80FD\u6027\u304C\u3042\
    \u308B\u3002\n  Bit_Array res(64 * (A + B));\n  clmul_rec(a.dat.data(), A, b.dat.data(),\
    \ B, res.dat.data());\n  res.resize(na + nb - 1);\n  return res;\n}\n#line 4 \"\
    poly/mod_2/power_projection.hpp\"\n\n// ANS[i] = sum_j wt[j] [x^j] f(x)^i, 0 <=\
    \ i <= m\nBit_Array power_projection(Bit_Array wt, Bit_Array f, int m) {\n  assert(f.size()\
    \ == wt.size());\n  assert(m >= 0);\n\n  int sz = f.size();\n  if (sz == 0) return\
    \ Bit_Array(m + 1);\n\n  int N = sz - 1;\n\n  // g[N-j] = wt[j]\n  Bit_Array g(sz);\n\
    \  FOR(j, sz) g[N - j] = wt[j];\n\n  Bit_Array ANS(m + 1);\n  auto dfs = [&](auto&\
    \ dfs, Bit_Array f, Bit_Array g, int m, int i0,\n                 int step) ->\
    \ void {\n    int N = f.size() - 1;\n    /*\n    [x^N] f(x)^i g(x), 0 <= i <=\
    \ m \u3092\n    ANS[i0], ANS[i0+step], ... \u306B\u66F8\u304D\u3053\u3080\n  \
    \  */\n    if (m == 0) {\n      ANS[i0] = g[N];\n      return;\n    }\n\n    int\
    \ n = N / 2;\n    {  // even case\n      Bit_Array nxtf = f.slice(0, n + 1);\n\
    \      Bit_Array nxtg(n + 1);\n      FOR(i, n + 1) nxtg[n - i] = g[N - 2 * i];\n\
    \n      dfs(dfs, nxtf, nxtg, m / 2, i0, step * 2);\n    }\n    {  // odd case\n\
    \      g = convolution(f, g);\n      g.resize(N + 1);\n\n      Bit_Array nxtf\
    \ = f.slice(0, n + 1);\n      Bit_Array nxtg(n + 1);\n      FOR(i, n + 1) nxtg[n\
    \ - i] = g[N - 2 * i];\n\n      dfs(dfs, nxtf, nxtg, (m - 1) / 2, i0 + step, step\
    \ * 2);\n    }\n  };\n\n  dfs(dfs, f, g, m, 0, 1);\n  return ANS;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/poly/mod_2/power_projection.hpp\n\
    #include \"ds/bit_array.hpp\"\n#include \"poly/mod_2/convolution.hpp\"\n\n// ANS[i]\
    \ = sum_j wt[j] [x^j] f(x)^i, 0 <= i <= m\nBit_Array power_projection(Bit_Array\
    \ wt, Bit_Array f, int m) {\n  assert(f.size() == wt.size());\n  assert(m >= 0);\n\
    \n  int sz = f.size();\n  if (sz == 0) return Bit_Array(m + 1);\n\n  int N = sz\
    \ - 1;\n\n  // g[N-j] = wt[j]\n  Bit_Array g(sz);\n  FOR(j, sz) g[N - j] = wt[j];\n\
    \n  Bit_Array ANS(m + 1);\n  auto dfs = [&](auto& dfs, Bit_Array f, Bit_Array\
    \ g, int m, int i0,\n                 int step) -> void {\n    int N = f.size()\
    \ - 1;\n    /*\n    [x^N] f(x)^i g(x), 0 <= i <= m \u3092\n    ANS[i0], ANS[i0+step],\
    \ ... \u306B\u66F8\u304D\u3053\u3080\n    */\n    if (m == 0) {\n      ANS[i0]\
    \ = g[N];\n      return;\n    }\n\n    int n = N / 2;\n    {  // even case\n \
    \     Bit_Array nxtf = f.slice(0, n + 1);\n      Bit_Array nxtg(n + 1);\n    \
    \  FOR(i, n + 1) nxtg[n - i] = g[N - 2 * i];\n\n      dfs(dfs, nxtf, nxtg, m /\
    \ 2, i0, step * 2);\n    }\n    {  // odd case\n      g = convolution(f, g);\n\
    \      g.resize(N + 1);\n\n      Bit_Array nxtf = f.slice(0, n + 1);\n      Bit_Array\
    \ nxtg(n + 1);\n      FOR(i, n + 1) nxtg[n - i] = g[N - 2 * i];\n\n      dfs(dfs,\
    \ nxtf, nxtg, (m - 1) / 2, i0 + step, step * 2);\n    }\n  };\n\n  dfs(dfs, f,\
    \ g, m, 0, 1);\n  return ANS;\n}"
  dependsOn:
  - ds/bit_array.hpp
  - poly/mod_2/convolution.hpp
  isVerificationFile: false
  path: poly/mod_2/power_projection.hpp
  requiredBy: []
  timestamp: '2026-10-23 11:03:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/mod_2/power_projection.hpp
layout: document
redirect_from:
- /library/poly/mod_2/power_projection.hpp
- /library/poly/mod_2/power_projection.hpp.html
title: poly/mod_2/power_projection.hpp
---
