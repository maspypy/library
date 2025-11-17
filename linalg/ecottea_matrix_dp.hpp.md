---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':x:'
    path: string/split.hpp
    title: string/split.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc022/tasks/agc022_e
    - https://atcoder.jp/contests/toyota2023spring-final/tasks/toyota2023spring_final_f
    - https://maspypy.com/ecottea_dp_estimate_method
  bundledCode: "#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template\
    \ <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n\
    \ != 0);\n  return 1.0 / n;\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n\
    \  static const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static\
    \ vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1]\
    \ * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int\
    \ n) {\n  static vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while\
    \ (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n\
    }\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return\
    \ (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head,\
    \ class... Tail>\nmint multinomial(Head &&head, Tail &&...tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n    return (d == 0 ?\
    \ mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n\
    #line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr\
    \ u32 umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n\
    \  static modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n\
    \  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod)\
    \ {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x)\
    \ : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n \
    \ constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const\
    \ modint &other) const { return val < other.val; }\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += umod - p.val) >=\
    \ umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  modint operator-() const { return modint::raw(val ? mod - val : u32(0));\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    if (n < 0) return inverse().pow(-n);\n    assert(n >= 0);\n\
    \    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1004535809) return {21, 582313106};\n    if (mod == 1012924417) return {21,\
    \ 368093570};\n    if (mod == 1224736769) return {24, 1191450770};\n    if (mod\
    \ == 2013265921) return {27, 244035102};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\n\
    template <int mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %=\
    \ mod;\n  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 1 \"string/split.hpp\"\nvc<string>\
    \ split(string S, char sep = ',') {\r\n  vc<string> res = {\"\"};\r\n  for (auto&&\
    \ s: S) {\r\n    if (s == sep)\r\n      res.eb(\"\");\r\n    else\r\n      res.back()\
    \ += s;\r\n  }\r\n  return res;\r\n}\r\n\r\nvc<string> split(string S, string\
    \ seps = \" ,\") {\r\n  vc<string> res = {\"\"};\r\n  for (auto&& s: S) {\r\n\
    \    if (count(all(seps), s))\r\n      res.eb(\"\");\r\n    else\r\n      res.back()\
    \ += s;\r\n  }\r\n  return res;\r\n}\r\n#line 3 \"linalg/ecottea_matrix_dp.hpp\"\
    \n\n// https://maspypy.com/ecottea_dp_estimate_method\n// https://atcoder.jp/contests/agc022/tasks/agc022_e\n\
    // https://atcoder.jp/contests/toyota2023spring-final/tasks/toyota2023spring_final_f\n\
    template <typename mint, int d>\nstruct ecottea_matrix_dp {\n  using MAT = array<array<mint,\
    \ d>, d>;\n  string alphabet;\n  map<char, MAT> matrix;\n  array<mint, d> X;\n\
    \  int rank;\n\n  // naive(n): map<string,mint>\n  template <typename F>\n  void\
    \ build(string alphabet_, F naive, int max_append = -1) {\n    alphabet = alphabet_;\n\
    \    vc<string> lst;\n    if (max_append == -1) max_append = d - 1;\n    lst.eb(\"\
    \");\n    for (int p = 0; p < len(lst); ++p) {\n      string S = lst[p];\n   \
    \   if (max_append < len(S)) break;\n      for (auto& a : alphabet) lst.eb(S +\
    \ a);\n    }\n    int n = len(lst);\n\n    auto get = [&](string S) -> vc<mint>\
    \ {\n      vc<mint> ANS(n);\n      FOR(j, n) ANS[j] = naive(lst[j] + S);\n   \
    \   return ANS;\n    };\n\n    vv(mint, mat, d, n);\n    vc<string> basis;\n \
    \   vc<int> pivot(d, infty<int>);\n    vv(mint, way, d, d);\n    deque<string>\
    \ que;\n    que.eb(\"\");\n\n    auto reduce = [&](vc<mint>& A) -> vc<mint> {\n\
    \      vc<mint> cf(d);\n      FOR(i, len(basis)) {\n        mint x = A[pivot[i]];\n\
    \        FOR(j, pivot[i], n) { A[j] -= x * mat[i][j]; }\n        FOR(j, len(basis))\
    \ { cf[j] -= x * way[i][j]; }\n      }\n      return cf;\n    };\n\n    while\
    \ (len(que)) {\n      int p = len(basis);\n      string S = POP(que);\n      vc<mint>\
    \ row = get(S);\n      vc<mint> cf = reduce(row);\n      int k = n;\n      FOR_R(j,\
    \ n) if (row[j] != 0) k = j;\n      if (k == n) continue;\n      if (p == d) {\n\
    \        print(\"dim>d\");\n        assert(0);\n      }\n      cf[p] += 1;\n \
    \     mint c = mint(1) / row[k];\n      FOR(j, n) row[j] *= c;\n      FOR(j, p\
    \ + 1) cf[j] *= c;\n      basis.eb(S);\n      pivot[p] = k, mat[p] = row, way[p]\
    \ = cf;\n      ++p;\n\n      auto I = argsort(pivot);\n      way = rearrange(way,\
    \ I);\n      mat = rearrange(mat, I);\n      pivot = rearrange(pivot, I);\n  \
    \    for (auto& ch : alphabet) {\n        que.eb(ch + S);\n      }\n    }\n  \
    \  rank = len(basis);\n\n    for (auto& ch : alphabet) {\n      MAT ans{};\n \
    \     FOR(i, len(basis)) {\n        vc<mint> row = get(ch + basis[i]);\n     \
    \   vc<mint> cf = reduce(row);\n        FOR(j, n) assert(row[j] == 0);\n     \
    \   FOR(j, len(cf)) ans[i][j] = -cf[j];\n      }\n      matrix[ch] = ans;\n  \
    \  }\n    FOR(i, len(basis)) X[i] = naive(basis[i]);\n    return;\n  }\n\n  string\
    \ to_string(mint x) {\n    int a = x.val;\n    int b = a - (mint::get_mod());\n\
    \    return ::to_string(abs(a) <= abs(b) ? a : b);\n  }\n  string to_string()\
    \ {\n    string out;\n    out += alphabet + \".\";\n    FOR(i, d) out += to_string(X[i].val)\
    \ + \".\";\n    for (auto& ch : alphabet) {\n      FOR(i, d) FOR(j, d) { out +=\
    \ to_string(matrix[ch][i][j].val) + \".\"; }\n    }\n    out.pop_back();\n   \
    \ return out;\n  }\n  void build_from_string(string S) {\n    auto dat = split(S,\
    \ '.');\n    alphabet = dat[0];\n    int p = 1;\n    FOR(i, d) X[i] = stoi(dat[p++]);\n\
    \    for (auto& ch : alphabet) {\n      FOR(i, d) FOR(j, d) { matrix[ch][i][j]\
    \ = stoi(dat[p++]); }\n    }\n  }\n\n  // ? \u306F\u5168\u90E8\u306E\u91CD\u306D\
    \u5408\u308F\u305B\u3068\u3057\u3066\n  mint solve(string S) {\n    // \u884C\u30D9\
    \u30AF\u30C8\u30EB\u306B\u884C\u5217\u3092\u304B\u3051\u3066\u3044\u3063\u3066\
    \u7B2C0\u6210\u5206\u3092\u3068\u308B\n    MAT ques{};\n    for (auto& [ch, A]\
    \ : matrix) {\n      FOR(i, d) FOR(j, d) ques[i][j] += A[i][j];\n    }\n    matrix['?']\
    \ = ques;\n    array<mint, d> dp = X;\n    for (auto& ch : S) {\n      array<mint,\
    \ d> newdp{};\n      assert(matrix.count(ch));\n      MAT& mat = matrix[ch];\n\
    \      FOR(i, d) FOR(j, d) newdp[i] += mat[i][j] * dp[j];\n      swap(dp, newdp);\n\
    \    }\n    return dp[0];\n  }\n};\n"
  code: "#include \"mod/modint.hpp\"\n#include \"string/split.hpp\"\n\n// https://maspypy.com/ecottea_dp_estimate_method\n\
    // https://atcoder.jp/contests/agc022/tasks/agc022_e\n// https://atcoder.jp/contests/toyota2023spring-final/tasks/toyota2023spring_final_f\n\
    template <typename mint, int d>\nstruct ecottea_matrix_dp {\n  using MAT = array<array<mint,\
    \ d>, d>;\n  string alphabet;\n  map<char, MAT> matrix;\n  array<mint, d> X;\n\
    \  int rank;\n\n  // naive(n): map<string,mint>\n  template <typename F>\n  void\
    \ build(string alphabet_, F naive, int max_append = -1) {\n    alphabet = alphabet_;\n\
    \    vc<string> lst;\n    if (max_append == -1) max_append = d - 1;\n    lst.eb(\"\
    \");\n    for (int p = 0; p < len(lst); ++p) {\n      string S = lst[p];\n   \
    \   if (max_append < len(S)) break;\n      for (auto& a : alphabet) lst.eb(S +\
    \ a);\n    }\n    int n = len(lst);\n\n    auto get = [&](string S) -> vc<mint>\
    \ {\n      vc<mint> ANS(n);\n      FOR(j, n) ANS[j] = naive(lst[j] + S);\n   \
    \   return ANS;\n    };\n\n    vv(mint, mat, d, n);\n    vc<string> basis;\n \
    \   vc<int> pivot(d, infty<int>);\n    vv(mint, way, d, d);\n    deque<string>\
    \ que;\n    que.eb(\"\");\n\n    auto reduce = [&](vc<mint>& A) -> vc<mint> {\n\
    \      vc<mint> cf(d);\n      FOR(i, len(basis)) {\n        mint x = A[pivot[i]];\n\
    \        FOR(j, pivot[i], n) { A[j] -= x * mat[i][j]; }\n        FOR(j, len(basis))\
    \ { cf[j] -= x * way[i][j]; }\n      }\n      return cf;\n    };\n\n    while\
    \ (len(que)) {\n      int p = len(basis);\n      string S = POP(que);\n      vc<mint>\
    \ row = get(S);\n      vc<mint> cf = reduce(row);\n      int k = n;\n      FOR_R(j,\
    \ n) if (row[j] != 0) k = j;\n      if (k == n) continue;\n      if (p == d) {\n\
    \        print(\"dim>d\");\n        assert(0);\n      }\n      cf[p] += 1;\n \
    \     mint c = mint(1) / row[k];\n      FOR(j, n) row[j] *= c;\n      FOR(j, p\
    \ + 1) cf[j] *= c;\n      basis.eb(S);\n      pivot[p] = k, mat[p] = row, way[p]\
    \ = cf;\n      ++p;\n\n      auto I = argsort(pivot);\n      way = rearrange(way,\
    \ I);\n      mat = rearrange(mat, I);\n      pivot = rearrange(pivot, I);\n  \
    \    for (auto& ch : alphabet) {\n        que.eb(ch + S);\n      }\n    }\n  \
    \  rank = len(basis);\n\n    for (auto& ch : alphabet) {\n      MAT ans{};\n \
    \     FOR(i, len(basis)) {\n        vc<mint> row = get(ch + basis[i]);\n     \
    \   vc<mint> cf = reduce(row);\n        FOR(j, n) assert(row[j] == 0);\n     \
    \   FOR(j, len(cf)) ans[i][j] = -cf[j];\n      }\n      matrix[ch] = ans;\n  \
    \  }\n    FOR(i, len(basis)) X[i] = naive(basis[i]);\n    return;\n  }\n\n  string\
    \ to_string(mint x) {\n    int a = x.val;\n    int b = a - (mint::get_mod());\n\
    \    return ::to_string(abs(a) <= abs(b) ? a : b);\n  }\n  string to_string()\
    \ {\n    string out;\n    out += alphabet + \".\";\n    FOR(i, d) out += to_string(X[i].val)\
    \ + \".\";\n    for (auto& ch : alphabet) {\n      FOR(i, d) FOR(j, d) { out +=\
    \ to_string(matrix[ch][i][j].val) + \".\"; }\n    }\n    out.pop_back();\n   \
    \ return out;\n  }\n  void build_from_string(string S) {\n    auto dat = split(S,\
    \ '.');\n    alphabet = dat[0];\n    int p = 1;\n    FOR(i, d) X[i] = stoi(dat[p++]);\n\
    \    for (auto& ch : alphabet) {\n      FOR(i, d) FOR(j, d) { matrix[ch][i][j]\
    \ = stoi(dat[p++]); }\n    }\n  }\n\n  // ? \u306F\u5168\u90E8\u306E\u91CD\u306D\
    \u5408\u308F\u305B\u3068\u3057\u3066\n  mint solve(string S) {\n    // \u884C\u30D9\
    \u30AF\u30C8\u30EB\u306B\u884C\u5217\u3092\u304B\u3051\u3066\u3044\u3063\u3066\
    \u7B2C0\u6210\u5206\u3092\u3068\u308B\n    MAT ques{};\n    for (auto& [ch, A]\
    \ : matrix) {\n      FOR(i, d) FOR(j, d) ques[i][j] += A[i][j];\n    }\n    matrix['?']\
    \ = ques;\n    array<mint, d> dp = X;\n    for (auto& ch : S) {\n      array<mint,\
    \ d> newdp{};\n      assert(matrix.count(ch));\n      MAT& mat = matrix[ch];\n\
    \      FOR(i, d) FOR(j, d) newdp[i] += mat[i][j] * dp[j];\n      swap(dp, newdp);\n\
    \    }\n    return dp[0];\n  }\n};"
  dependsOn:
  - mod/modint.hpp
  - mod/modint_common.hpp
  - string/split.hpp
  isVerificationFile: false
  path: linalg/ecottea_matrix_dp.hpp
  requiredBy: []
  timestamp: '2025-09-01 23:33:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/ecottea_matrix_dp.hpp
layout: document
redirect_from:
- /library/linalg/ecottea_matrix_dp.hpp
- /library/linalg/ecottea_matrix_dp.hpp.html
title: linalg/ecottea_matrix_dp.hpp
---
