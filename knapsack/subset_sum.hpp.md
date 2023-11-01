---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/my_bitset.hpp
    title: ds/my_bitset.hpp
  - icon: ':question:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/4_2.test.cpp
    title: test/yukicoder/4_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/755/problem/F
  bundledCode: "#line 2 \"ds/my_bitset.hpp\"\n\n// https://codeforces.com/contest/914/problem/F\n\
    // https://yukicoder.me/problems/no/142\n// \u308F\u305A\u304B\u306B\u666E\u901A\
    \u306E bitset \u3088\u308A\u9045\u3044\u3068\u304D\u3082\u3042\u308B\u3088\u3046\
    \u3060\u304C\uFF0C\n// \u56FA\u5B9A\u9577\u306B\u3057\u305F\u304F\u306A\u3044\u3068\
    \u304D\u3084 slice \u64CD\u4F5C\u304C\u5FC5\u8981\u306A\u3068\u304D\u306B\u4F7F\
    \u3046\nstruct My_Bitset {\n  using T = My_Bitset;\n  int N;\n  vc<u64> dat;\n\
    \n  // x \u3067\u57CB\u3081\u308B\n  My_Bitset(int N = 0, int x = 0) : N(N) {\n\
    \    assert(x == 0 || x == 1);\n    u64 v = (x == 0 ? 0 : -1);\n    dat.assign((N\
    \ + 63) >> 6, v);\n    if (N) dat.back() >>= (64 * len(dat) - N);\n  }\n\n  int\
    \ size() { return N; }\n\n  void resize(int size) {\n    dat.resize((size + 63)\
    \ >> 6);\n    int remainingBits = size & 63;\n    if (remainingBits != 0) {\n\
    \      u64 mask = (u64(1) << remainingBits) - 1;\n      dat.back() &= mask;\n\
    \    }\n    N = size;\n  }\n\n  // thanks to chatgpt!\n  class Proxy {\n  public:\n\
    \    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}\n    operator bool() const\
    \ { return (dat[index >> 6] >> (index & 63)) & 1; }\n\n    Proxy &operator=(u64\
    \ value) {\n      dat[index >> 6] &= ~(u64(1) << (index & 63));\n      dat[index\
    \ >> 6] |= (value & 1) << (index & 63);\n      return *this;\n    }\n    void\
    \ flip() {\n      dat[index >> 6] ^= (u64(1) << (index & 63)); // XOR to flip\
    \ the bit\n    }\n\n  private:\n    vc<u64> &dat;\n    int index;\n  };\n\n  Proxy\
    \ operator[](int i) { return Proxy(dat, i); }\n\n  T &operator&=(const T &p) {\n\
    \    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] &= p.dat[i];\n    return *this;\n\
    \  }\n  T &operator|=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat))\
    \ dat[i] |= p.dat[i];\n    return *this;\n  }\n  T &operator^=(const T &p) {\n\
    \    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] ^= p.dat[i];\n    return *this;\n\
    \  }\n  T operator&(const T &p) const { return T(*this) &= p; }\n  T operator|(const\
    \ T &p) const { return T(*this) |= p; }\n  T operator^(const T &p) const { return\
    \ T(*this) ^= p; }\n\n  int count() {\n    int ans = 0;\n    for (u64 val: dat)\
    \ ans += popcnt(val);\n    return ans;\n  }\n\n  int next(int i) {\n    chmax(i,\
    \ 0);\n    if (i >= N) return N;\n    int k = i >> 6;\n    {\n      u64 x = dat[k];\n\
    \      int s = i & 63;\n      x = (x >> s) << s;\n      if (x) return (k << 6)\
    \ | lowbit(x);\n    }\n    FOR(idx, k + 1, len(dat)) {\n      if (dat[idx] ==\
    \ 0) continue;\n      return (idx << 6) | lowbit(dat[idx]);\n    }\n    return\
    \ N;\n  }\n\n  int prev(int i) {\n    chmin(i, N - 1);\n    if (i <= -1) return\
    \ -1;\n    int k = i >> 6;\n    if ((i & 63) < 63) {\n      u64 x = dat[k];\n\
    \      x &= (u64(1) << ((i & 63) + 1)) - 1;\n      if (x) return (k << 6) | topbit(x);\n\
    \      --k;\n    }\n    FOR_R(idx, k + 1) {\n      if (dat[idx] == 0) continue;\n\
    \      return (idx << 6) | topbit(dat[idx]);\n    }\n    return -1;\n  }\n\n \
    \ My_Bitset range(int L, int R) {\n    assert(L <= R);\n    My_Bitset p(R - L);\n\
    \    int rm = (R - L) & 63;\n    FOR(rm) {\n      p[R - L - 1] = bool((*this)[R\
    \ - 1]);\n      --R;\n    }\n    int n = (R - L) >> 6;\n    int hi = L & 63;\n\
    \    int lo = 64 - hi;\n    int s = L >> 6;\n    if (hi == 0) {\n      FOR(i,\
    \ n) { p.dat[i] ^= dat[s + i]; }\n    } else {\n      FOR(i, n) { p.dat[i] ^=\
    \ (dat[s + i] >> hi) ^ (dat[s + i + 1] << lo); }\n    }\n    return p;\n  }\n\n\
    \  int count_range(int L, int R) {\n    assert(L <= R);\n    int cnt = 0;\n  \
    \  while ((L < R) && (L & 63)) cnt += (*this)[L++];\n    while ((L < R) && (R\
    \ & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r = R >> 6;\n    FOR(i, l,\
    \ r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n  // [L,R) \u306B p \u3092\
    \u4EE3\u5165\n  void assign_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N\
    \ == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63)) { (*this)[L++]\
    \ = bool(p[a++]); }\n    while (L < R && (R & 63)) { (*this)[--R] = bool(p[--b]);\
    \ }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int\
    \ s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i,\
    \ n) dat[l + i] = p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int\
    \ lo = 64 - hi;\n      FOR(i, n) dat[l + i] = (p.dat[s + i] >> hi) | (p.dat[1\
    \ + s + i] << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 xor\n  void xor_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n\
    \      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n  \
    \    dat[R >> 6] ^= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] ^= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n \
    \   }\n  }\n\n  // [L,R) \u306B p \u3092 and\n  void and_to_range(int L, int R,\
    \ My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while\
    \ (L < R && (L & 63)) {\n      if (!p[a++]) (*this)[L++] = 0;\n    }\n    while\
    \ (L < R && (R & 63)) {\n      if (!p[--b]) (*this)[--R] = 0;\n    }\n    // p[a:b]\
    \ \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t\
    \ = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l +\
    \ i] &= p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64\
    \ - hi;\n      FOR(i, n) dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i]\
    \ << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 or\n  void or_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      dat[L >> 6] |= u64(p[a]) << (L & 63);\n\
    \      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n  \
    \    dat[R >> 6] |= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] |= p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n \
    \   }\n  }\n\n  string to_string() const {\n    string S;\n    FOR(i, N) S +=\
    \ '0' + (dat[i >> 6] >> (i & 63) & 1);\n    return S;\n  }\n\n  // bitset \u306B\
    \u4ED5\u69D8\u3092\u5408\u308F\u305B\u308B\n  void set(int i) { (*this)[i] = 1;\
    \ }\n  void reset(int i) { (*this)[i] = 0; }\n  void flip(int i) { (*this)[i].flip();\
    \ }\n  void set() { fill(all(dat), 0); }\n  void reset() {\n    fill(all(dat),\
    \ u64(-1));\n    resize(N);\n  }\n\n  int _Find_first() { return next(0); }\n\
    \  int _Find_next(int p) { return next(p + 1); }\n};\n#line 1 \"enumerate/bits.hpp\"\
    \ntemplate <typename F>\nvoid enumerate_bits_32(u32 s, F f) {\n  while (s) {\n\
    \    int i = __builtin_ctz(s);\n    f(i);\n    s ^= 1 << i;\n  }\n}\n\ntemplate\
    \ <typename F>\nvoid enumerate_bits_64(u64 s, F f) {\n  while (s) {\n    int i\
    \ = __builtin_ctzll(s);\n    f(i);\n    s ^= u64(1) << i;\n  }\n}\n\ntemplate\
    \ <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F\
    \ f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n\
    \    p = b._Find_next(p);\n  }\n}\n#line 3 \"knapsack/subset_sum.hpp\"\n\n// O(N\
    \ MAX(vals))\ntemplate <typename T>\nvc<int> subset_sum_solution_1(vc<T>& vals,\
    \ int target) {\n  int n = len(vals);\n  int mx = MAX(vals);\n  int b = 0, sb\
    \ = 0;\n  while (b < n && sb + vals[b] <= target) { sb += vals[b++]; }\n  if (b\
    \ == n && sb != target) return {};\n\n  int off = target - mx + 1;\n  vc<int>\
    \ dp(2 * mx, -1);\n  vv(int, PAR, n, 2 * mx, -1);\n  dp[sb - off] = b;\n  FOR3(i,\
    \ b, n) {\n    auto newdp = dp;\n    auto& par = PAR[i];\n    int a = vals[i];\n\
    \    FOR(j, mx) {\n      if (chmax(newdp[j + a], dp[j])) { par[j + a] = -2; }\n\
    \    }\n    FOR3_R(j, mx, 2 * mx) {\n      FOR3_R(k, max(dp[j], 0), newdp[j])\
    \ {\n        if (chmax(newdp[j - vals[k]], k)) par[j - vals[k]] = k;\n      }\n\
    \    }\n    swap(dp, newdp);\n  }\n  if (dp[mx - 1] == -1) return {};\n  vc<bool>\
    \ use(n);\n  int i = n - 1, j = mx - 1;\n  while (i >= b) {\n    int p = PAR[i][j];\n\
    \    if (p == -2) {\n      use[i] = !use[i];\n      j -= vals[i--];\n    }\n \
    \   elif (p == -1) { --i; }\n    else {\n      use[p] = !use[p];\n      j += vals[p];\n\
    \    }\n  }\n  while (i >= 0) {\n    use[i] = !use[i];\n    --i;\n  }\n  vc<int>\
    \ I;\n  FOR(i, n) if (use[i]) I.eb(i);\n\n  ll sm = 0;\n  for (auto&& i: I) sm\
    \ += vals[i];\n  assert(sm == target);\n\n  return I;\n}\n\n// O(N target / w)\n\
    template <typename T>\nvc<int> subset_sum_solution_2(vc<T>& vals, int target)\
    \ {\n  int n = len(vals);\n  auto I = argsort(vals);\n  My_Bitset dp(1, 1);\n\
    \  vc<int> last(target + 1, -1);\n  FOR(k, n) {\n    int v = vals[I[k]];\n   \
    \ if (v > target) continue;\n    My_Bitset newdp = dp;\n    int new_size = min<int>(len(dp)\
    \ + v, target + 1);\n    newdp.resize(new_size);\n    dp.resize(new_size - v);\n\
    \    newdp.or_to_range(v, new_size, dp);\n    // update \u3057\u305F\u3068\u3053\
    \u308D\u3092\u30E1\u30E2\n    FOR(i, len(newdp.dat)) {\n      u64 upd = (i < len(dp.dat)\
    \ ? dp.dat[i] : u64(0)) ^ newdp.dat[i];\n      enumerate_bits_64(upd, [&](int\
    \ p) -> void { last[(i << 6) | p] = I[k]; });\n    }\n    swap(dp, newdp);\n \
    \ }\n  if (target >= len(dp) || !dp[target]) return {};\n  vc<int> ANS;\n  while\
    \ (target > 0) {\n    int i = last[target];\n    ANS.eb(i);\n    target -= vals[i];\n\
    \  }\n  return ANS;\n}\n\n// O(sum^{1.5} / w)\n// sum=10^6 \u3067 150ms\uFF1A\
    https://codeforces.com/contest/755/problem/F\ntemplate <typename T>\nvc<int> subset_sum_solution_3(vc<T>&\
    \ vals, int target) {\n  int SM = SUM<int>(vals);\n  int N = len(vals);\n  vvc<int>\
    \ IDS(SM + 1);\n  FOR(i, N) IDS[vals[i]].eb(i);\n  vc<pair<int, int>> par(N, {-1,\
    \ -1});\n  vc<int> grp_vals;\n  vvc<int> raw_idx;\n  FOR(x, 1, SM + 1) {\n   \
    \ auto& I = IDS[x];\n    while (len(I) >= 3) {\n      int a = POP(I), b = POP(I);\n\
    \      int c = len(par);\n      par.eb(a, b);\n      IDS[2 * x].eb(c);\n    }\n\
    \    for (auto& i: I) {\n      grp_vals.eb(x);\n      raw_idx.eb(i);\n    }\n\
    \  }\n  auto I = subset_sum_solution_2<int>(grp_vals, target);\n  vc<int> ANS;\n\
    \  for (auto& i: I) {\n    vc<int> st = {i};\n    while (len(st)) {\n      auto\
    \ c = POP(st);\n      if (c < N) {\n        ANS.eb(c);\n        continue;\n  \
    \    }\n      auto [a, b] = par[c];\n      st.eb(a), st.eb(b);\n    }\n  }\n \
    \ return ANS;\n}\n\ntemplate <typename T>\nvc<int> subset_sum_solution_4(vc<T>&\
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
    \ (t + 1 < len(dp2) && dp1[s] + dp2[t + 1] <= target) { ++t; }\n    if (dp1[s]\
    \ + dp2[t] == target) {\n      vc<int> I1 = restore(0, M, dp1[s]);\n      vc<int>\
    \ I2 = restore(M, N, dp2[t]);\n      I1.insert(I1.end(), all(I2));\n      return\
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
  code: "#include \"ds/my_bitset.hpp\"\n#include \"enumerate/bits.hpp\"\n\n// O(N\
    \ MAX(vals))\ntemplate <typename T>\nvc<int> subset_sum_solution_1(vc<T>& vals,\
    \ int target) {\n  int n = len(vals);\n  int mx = MAX(vals);\n  int b = 0, sb\
    \ = 0;\n  while (b < n && sb + vals[b] <= target) { sb += vals[b++]; }\n  if (b\
    \ == n && sb != target) return {};\n\n  int off = target - mx + 1;\n  vc<int>\
    \ dp(2 * mx, -1);\n  vv(int, PAR, n, 2 * mx, -1);\n  dp[sb - off] = b;\n  FOR3(i,\
    \ b, n) {\n    auto newdp = dp;\n    auto& par = PAR[i];\n    int a = vals[i];\n\
    \    FOR(j, mx) {\n      if (chmax(newdp[j + a], dp[j])) { par[j + a] = -2; }\n\
    \    }\n    FOR3_R(j, mx, 2 * mx) {\n      FOR3_R(k, max(dp[j], 0), newdp[j])\
    \ {\n        if (chmax(newdp[j - vals[k]], k)) par[j - vals[k]] = k;\n      }\n\
    \    }\n    swap(dp, newdp);\n  }\n  if (dp[mx - 1] == -1) return {};\n  vc<bool>\
    \ use(n);\n  int i = n - 1, j = mx - 1;\n  while (i >= b) {\n    int p = PAR[i][j];\n\
    \    if (p == -2) {\n      use[i] = !use[i];\n      j -= vals[i--];\n    }\n \
    \   elif (p == -1) { --i; }\n    else {\n      use[p] = !use[p];\n      j += vals[p];\n\
    \    }\n  }\n  while (i >= 0) {\n    use[i] = !use[i];\n    --i;\n  }\n  vc<int>\
    \ I;\n  FOR(i, n) if (use[i]) I.eb(i);\n\n  ll sm = 0;\n  for (auto&& i: I) sm\
    \ += vals[i];\n  assert(sm == target);\n\n  return I;\n}\n\n// O(N target / w)\n\
    template <typename T>\nvc<int> subset_sum_solution_2(vc<T>& vals, int target)\
    \ {\n  int n = len(vals);\n  auto I = argsort(vals);\n  My_Bitset dp(1, 1);\n\
    \  vc<int> last(target + 1, -1);\n  FOR(k, n) {\n    int v = vals[I[k]];\n   \
    \ if (v > target) continue;\n    My_Bitset newdp = dp;\n    int new_size = min<int>(len(dp)\
    \ + v, target + 1);\n    newdp.resize(new_size);\n    dp.resize(new_size - v);\n\
    \    newdp.or_to_range(v, new_size, dp);\n    // update \u3057\u305F\u3068\u3053\
    \u308D\u3092\u30E1\u30E2\n    FOR(i, len(newdp.dat)) {\n      u64 upd = (i < len(dp.dat)\
    \ ? dp.dat[i] : u64(0)) ^ newdp.dat[i];\n      enumerate_bits_64(upd, [&](int\
    \ p) -> void { last[(i << 6) | p] = I[k]; });\n    }\n    swap(dp, newdp);\n \
    \ }\n  if (target >= len(dp) || !dp[target]) return {};\n  vc<int> ANS;\n  while\
    \ (target > 0) {\n    int i = last[target];\n    ANS.eb(i);\n    target -= vals[i];\n\
    \  }\n  return ANS;\n}\n\n// O(sum^{1.5} / w)\n// sum=10^6 \u3067 150ms\uFF1A\
    https://codeforces.com/contest/755/problem/F\ntemplate <typename T>\nvc<int> subset_sum_solution_3(vc<T>&\
    \ vals, int target) {\n  int SM = SUM<int>(vals);\n  int N = len(vals);\n  vvc<int>\
    \ IDS(SM + 1);\n  FOR(i, N) IDS[vals[i]].eb(i);\n  vc<pair<int, int>> par(N, {-1,\
    \ -1});\n  vc<int> grp_vals;\n  vvc<int> raw_idx;\n  FOR(x, 1, SM + 1) {\n   \
    \ auto& I = IDS[x];\n    while (len(I) >= 3) {\n      int a = POP(I), b = POP(I);\n\
    \      int c = len(par);\n      par.eb(a, b);\n      IDS[2 * x].eb(c);\n    }\n\
    \    for (auto& i: I) {\n      grp_vals.eb(x);\n      raw_idx.eb(i);\n    }\n\
    \  }\n  auto I = subset_sum_solution_2<int>(grp_vals, target);\n  vc<int> ANS;\n\
    \  for (auto& i: I) {\n    vc<int> st = {i};\n    while (len(st)) {\n      auto\
    \ c = POP(st);\n      if (c < N) {\n        ANS.eb(c);\n        continue;\n  \
    \    }\n      auto [a, b] = par[c];\n      st.eb(a), st.eb(b);\n    }\n  }\n \
    \ return ANS;\n}\n\ntemplate <typename T>\nvc<int> subset_sum_solution_4(vc<T>&\
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
    \ (t + 1 < len(dp2) && dp1[s] + dp2[t + 1] <= target) { ++t; }\n    if (dp1[s]\
    \ + dp2[t] == target) {\n      vc<int> I1 = restore(0, M, dp1[s]);\n      vc<int>\
    \ I2 = restore(M, N, dp2[t]);\n      I1.insert(I1.end(), all(I2));\n      return\
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
  - ds/my_bitset.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: knapsack/subset_sum.hpp
  requiredBy: []
  timestamp: '2023-10-29 05:43:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/4_2.test.cpp
documentation_of: knapsack/subset_sum.hpp
layout: document
redirect_from:
- /library/knapsack/subset_sum.hpp
- /library/knapsack/subset_sum.hpp.html
title: knapsack/subset_sum.hpp
---
