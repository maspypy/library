---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "template/rerooting_dp.hpp"

    // template/rerooting_dp.hpp

    struct Data {};

    Data id = {};

    auto f_ee = [&](const Data &x, const Data &y) -> Data {};

    auto f_ev = [&](const Data &x, int v) -> Data {};

    auto f_ve = [&](const Data &x, int r, int nxt_r) -> Data { return x; };

    Rerooting_DP<decltype(tree), Data> dp(tree, f_ee, f_ev, f_ve, id);

    '
  code: '// template/rerooting_dp.hpp

    struct Data {};

    Data id = {};

    auto f_ee = [&](const Data &x, const Data &y) -> Data {};

    auto f_ev = [&](const Data &x, int v) -> Data {};

    auto f_ve = [&](const Data &x, int r, int nxt_r) -> Data { return x; };

    Rerooting_DP<decltype(tree), Data> dp(tree, f_ee, f_ev, f_ve, id);

    '
  dependsOn: []
  isVerificationFile: false
  path: template/rerooting_dp.hpp
  requiredBy: []
  timestamp: '2026-09-13 15:10:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/rerooting_dp.hpp
layout: document
redirect_from:
- /library/template/rerooting_dp.hpp
- /library/template/rerooting_dp.hpp.html
title: template/rerooting_dp.hpp
---
