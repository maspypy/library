---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/755/problem/F
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/my_bitset.hpp\"\n#include \"enumerate/bits.hpp\"\n\n// O(N\
    \ MAX(vals))\ntemplate <typename T>\nvc<int> subset_sum_solution_1(vc<T>& vals,\
    \ int target) {\n  int n = len(vals);\n  if (n == 0) return {};\n  int mx = MAX(vals);\n\
    \  int b = 0, sb = 0;\n  while (b < n && sb + vals[b] <= target) {\n    sb +=\
    \ vals[b++];\n  }\n  if (b == n && sb != target) return {};\n\n  int off = target\
    \ - mx + 1;\n  vc<int> dp(2 * mx, -1);\n  vv(int, PAR, n, 2 * mx, -1);\n  dp[sb\
    \ - off] = b;\n  FOR(i, b, n) {\n    auto newdp = dp;\n    auto& par = PAR[i];\n\
    \    int a = vals[i];\n    FOR(j, mx) {\n      if (chmax(newdp[j + a], dp[j]))\
    \ {\n        par[j + a] = -2;\n      }\n    }\n    FOR3_R(j, mx, 2 * mx) {\n \
    \     FOR3_R(k, max(dp[j], 0), newdp[j]) {\n        if (chmax(newdp[j - vals[k]],\
    \ k)) par[j - vals[k]] = k;\n      }\n    }\n    swap(dp, newdp);\n  }\n  if (dp[mx\
    \ - 1] == -1) return {};\n  vc<bool> use(n);\n  int i = n - 1, j = mx - 1;\n \
    \ while (i >= b) {\n    int p = PAR[i][j];\n    if (p == -2) {\n      use[i] =\
    \ !use[i];\n      j -= vals[i--];\n    }\n    elif (p == -1) { --i; }\n    else\
    \ {\n      use[p] = !use[p];\n      j += vals[p];\n    }\n  }\n  while (i >= 0)\
    \ {\n    use[i] = !use[i];\n    --i;\n  }\n  vc<int> I;\n  FOR(i, n) if (use[i])\
    \ I.eb(i);\n\n  ll sm = 0;\n  for (auto&& i : I) sm += vals[i];\n  assert(sm ==\
    \ target);\n\n  return I;\n}\n\n// O(N target / w)\ntemplate <typename T>\nvc<int>\
    \ subset_sum_solution_2(vc<T>& vals, int target) {\n  int n = len(vals);\n  auto\
    \ I = argsort(vals);\n  Bit_Array dp(1, 1);\n  vc<int> last(target + 1, -1);\n\
    \  FOR(k, n) {\n    int v = vals[I[k]];\n    if (v > target) continue;\n    Bit_Array\
    \ newdp = dp;\n    int new_size = len(dp) + v;\n    newdp.resize(new_size);\n\
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
  dependsOn: []
  isVerificationFile: false
  path: knapsack/subset_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: knapsack/subset_sum.hpp
layout: document
redirect_from:
- /library/knapsack/subset_sum.hpp
- /library/knapsack/subset_sum.hpp.html
title: knapsack/subset_sum.hpp
---
