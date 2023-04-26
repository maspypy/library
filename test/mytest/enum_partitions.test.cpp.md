---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n\n#include \"enumerate/partition.hpp\"\
    \n#include \"seq/famous/partition_number.hpp\"\n\nusing mint = modint998;\n\n\
    void test() {\n  FOR(N, 1, 10) {\n    vc<mint> P = partition_number<mint>(N);\n\
    \    set<vc<int>> ss;\n    auto f = [&](vc<int>& P) -> void {\n      assert(SUM<int>(P)\
    \ == N);\n      assert(!ss.count(P));\n      ss.insert(P);\n    };\n    enumerate_partition<decltype(f)>(N,\
    \ f);\n    assert(P[N] == len(ss));\n  }\n  FOR(N, 1, 10) {\n    FOR(LIM_len,\
    \ 10) FOR(LIM_val, 10) {\n      int a = 0;\n      auto f = [&](vc<int>& P) ->\
    \ void {\n        if (len(P) <= LIM_len && MAX(P) <= LIM_val) ++a;\n      };\n\
    \      int b = 0;\n      auto g = [&](vc<int>& P) -> void {\n        assert(len(P)\
    \ <= LIM_len && MAX(P) <= LIM_val);\n        ++b;\n      };\n      enumerate_partition<decltype(f)>(N,\
    \ f);\n      enumerate_partition<decltype(g)>(N, g, LIM_len, LIM_val);\n     \
    \ assert(a == b);\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n\
    }\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/enum_partitions.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/enum_partitions.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/enum_partitions.test.cpp
- /verify/test/mytest/enum_partitions.test.cpp.html
title: test/mytest/enum_partitions.test.cpp
---
