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
    - https://dic.kimiyuki.net/d-edge-shortest-path-monge
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/larsch.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/larsch.hpp\"\r\n#include \"seq/monotone_minima.hpp\"\r\n\r\n\
    // \u5B9A\u7FA9\u57DF [0, N] \u306E\u7BC4\u56F2\u3067 f \u306E monge \u6027\u3092\
    \u78BA\u8A8D\r\ntemplate <typename T, typename F>\r\nbool check_monge(int N, F\
    \ f) {\r\n  FOR(l, N + 1) FOR(k, l) FOR(j, k) FOR(i, j) {\r\n    T lhs = f(i,\
    \ l) + f(j, k);\r\n    T rhs = f(i, k) + f(j, l);\r\n    if (lhs < rhs) return\
    \ false;\r\n  }\r\n  return true;\r\n}\r\n\r\ntemplate <ll INF, typename F>\r\n\
    vi monge_shortest_path(int N, F f) {\r\n  vi dp(N + 1, INF);\r\n  dp[0] = 0;\r\
    \n  LARSCH<ll> larsch(N, [&](int i, int j) {\r\n    ++i;\r\n    if (i <= j) return\
    \ INF;\r\n    return dp[j] + f(j, i);\r\n  });\r\n  FOR3(r, 1, N + 1) {\r\n  \
    \  ll l = larsch.get_argmin();\r\n    dp[r] = dp[l] + f(l, r);\r\n  }\r\n  return\
    \ dp;\r\n}\r\n\r\ntemplate <typename T, typename F>\r\nvc<vc<T>> monge_shortest_path_d_edge_dense(int\
    \ N, F f, T INF, int d_max) {\r\n  vv(T, DP, d_max + 1, N + 1, INF);\r\n  DP[0][0]\
    \ = 0;\r\n  FOR(d, d_max) {\r\n    auto& dp = DP[d];\r\n    auto& newdp = DP[d\
    \ + 1];\r\n    auto g = [&](int r, int l) -> T {\r\n      //      print(l, r);\r\
    \n      if (r <= l) return INF;\r\n      return dp[l] + f(l, r);\r\n    };\r\n\
    \    auto ret = monotone_minima<T>(N + 1, N + 1, g);\r\n    FOR(j, N + 1) newdp[j]\
    \ = ret[j].se;\r\n  }\r\n  return DP;\r\n}\r\n\r\n/*\r\nhttps://dic.kimiyuki.net/d-edge-shortest-path-monge\r\
    \n\u4E0A\u51F8\u95A2\u6570 calc_L(lambda) \u306E\u6700\u5927\u5024\u3092\u6C42\
    \u3081\u308B\u554F\u984C\u306B\u5E30\u7740\r\n|f| \u306E\u4E0A\u9650 f_lim \u3082\
    \u6E21\u3059\r\n*/\r\ntemplate <ll INF, typename F>\r\nll monge_shortest_path_d_edge(ll\
    \ N, F f, ll d, ll f_lim) {\r\n  auto calc_L = [&](ll lambda) -> ll {\r\n    auto\
    \ cost = [&](int frm, int to) -> ll { return f(frm, to) + lambda; };\r\n    auto\
    \ dp = monge_shortest_path<INF>(N, cost);\r\n    return dp.back() - lambda * d;\r\
    \n  };\r\n\r\n  ll ANS = -INF;\r\n  ll L = -3 * f_lim - 10;\r\n  ll R = 3 * f_lim\
    \ + 10;\r\n  ll x = binary_search([&](ll x) { return calc_L(x - 1) <= calc_L(x);\
    \ }, L, R);\r\n  return calc_L(x);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/monge.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/monge.hpp
layout: document
redirect_from:
- /library/seq/monge.hpp
- /library/seq/monge.hpp.html
title: seq/monge.hpp
---
