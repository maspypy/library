---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/offline_query/add_remove_query.hpp
    title: ds/offline_query/add_remove_query.hpp
  - icon: ':x:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  - icon: ':x:'
    path: ds/unionfind/rollback_unionfind.hpp
    title: ds/unionfind/rollback_unionfind.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/other/io.hpp']' returned non-zero\
    \ exit status 1.\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/offline_query/add_remove_query.hpp\"\
    \n#include \"ds/rollback_array.hpp\"\n#include \"ds/unionfind/rollback_unionfind.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A0, N);\n  using P = pair<int, int>;\n\
    \n  vc<int> query;\n\n  Add_Remove_Query<P, true> X;\n  FOR(Q) {\n    LL(t);\n\
    \    if (t == 0) {\n      LL(a, b);\n      if (a > b) swap(a, b);\n      P e =\
    \ {a, b};\n      X.add(len(query), e);\n    }\n    if (t == 1) {\n      LL(a,\
    \ b);\n      if (a > b) swap(a, b);\n      P e = {a, b};\n      X.remove(len(query),\
    \ e);\n    }\n    if (t == 2) {\n      LL(v, x);\n      P p = {~v, x};\n     \
    \ X.add(len(query), p);\n    }\n    if (t == 3) {\n      LL(v);\n      query.eb(v);\n\
    \    }\n  }\n\n  auto upd = X.calc(len(query));\n  Q = len(query);\n  vi ANS(Q);\n\
    \  vc<int> I(len(upd));\n  iota(all(I), 0);\n\n  Rollback_Array<ll> A(A0);\n \
    \ Rollback_UnionFind uf(N);\n\n  auto dfs = [&](auto& dfs, vc<int>& I, int begin,\
    \ int end) -> void {\n    int a_time = A.time();\n    int uf_time = uf.time();\n\
    \n    vc<int> IL, IR;\n    int mid = (begin + end) / 2;\n    // \u533A\u9593\u3092\
    \u5B8C\u5168\u306B\u542B\u3080\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\
    \u3059\u308B\u3002\n    // \u90E8\u5206\u7684\u306B\u4EA4\u308F\u308B\u30AF\u30A8\
    \u30EA\u3092 J \u306B\u5165\u308C\u308B\n    for (auto&& i: I) {\n      auto [a,\
    \ b, X] = upd[i];\n      if (a <= begin && end <= b) {\n        // update\n  \
    \      auto [u, v] = X;\n        if (u < 0) {\n          int i = uf[~u];\n   \
    \       A.set(i, A.get(i) + v);\n        } else {\n          u = uf[u], v = uf[v];\n\
    \          if (u != v) {\n            uf.merge(u, v);\n            int r = uf[u];\n\
    \            A.set(r, A.get(u) + A.get(v));\n          }\n        }\n        continue;\n\
    \      }\n      if (a < mid) IL.eb(i);\n      if (mid < b) IR.eb(i);\n    }\n\
    \    if (begin + 1 == end) {\n      // \u6C42\u5024\u30AF\u30A8\u30EA\n      int\
    \ v = query[begin];\n      ANS[begin] = A.get(uf[v]);\n    } else {\n      dfs(dfs,\
    \ IL, begin, mid);\n      dfs(dfs, IR, mid, end);\n    }\n    A.rollback(a_time);\n\
    \    uf.rollback(uf_time);\n  };\n  dfs(dfs, I, 0, Q);\n\n  for (auto&& x: ANS)\
    \ print(x);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/offline_query/add_remove_query.hpp
  - ds/rollback_array.hpp
  - ds/unionfind/rollback_unionfind.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/add_remove_query.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/add_remove_query.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/add_remove_query.test.cpp
- /verify/test/library_checker/datastructure/add_remove_query.test.cpp.html
title: test/library_checker/datastructure/add_remove_query.test.cpp
---
