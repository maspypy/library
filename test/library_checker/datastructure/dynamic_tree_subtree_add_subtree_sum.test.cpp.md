---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/ds/link_cut_tree.hpp
    title: graph/ds/link_cut_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
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
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/ds/link_cut_tree.hpp\"\
    \n\n/*\nsm \u306F lazy \u53CD\u6620\u6E08\n\u305F\u3060\u3057 light edge \u304B\
    \u3089\u306E lazy_light - cancel \u306F\u672A\u53CD\u6620\n*/\nstruct Node {\n\
    \  using np = Node *;\n  // \u30C7\u30D5\u30A9\u30EB\u30C8\n  np l, r, p;\n  int\
    \ idx, size; // size \u306F heavy path \u306E\u9802\u70B9\u6570\n  bool rev;\n\
    \  struct X {\n    ll cnt, sum;\n  };\n\n  using VX = X;\n  // \u76EE\u7684\u3054\
    \u3068\u306B\u5B9A\u7FA9\u3059\u308B.\n  X x, vx, mid;\n  ll lazy, lazy_light,\
    \ cancel;\n\n  Node(int i = 0)\n      : l(nullptr),\n        r(nullptr),\n   \
    \     p(nullptr),\n        idx(i),\n        size(1),\n        rev(0),\n      \
    \  x({1, 0}),\n        vx({1, 0}),\n        mid({0, 0}),\n        lazy(0),\n \
    \       lazy_light(0),\n        cancel(0) {}\n\n  void update() {\n    size =\
    \ 1;\n    x.cnt = vx.cnt + mid.cnt, x.sum = vx.sum + mid.sum;\n    if (l) { size\
    \ += l->size, x.sum += l->x.sum, x.cnt += l->x.cnt; }\n    if (r) { size += r->size,\
    \ x.sum += r->x.sum, x.cnt += r->x.cnt; }\n  }\n\n  void push() {\n    if (rev)\
    \ {\n      if (l) l->reverse();\n      if (r) r->reverse();\n    }\n    if (lazy)\
    \ {\n      if (l) l->apply(lazy);\n      if (r) r->apply(lazy);\n    }\n    rev\
    \ = 0;\n    lazy = 0;\n  }\n\n  void apply(ll a) {\n    vx.sum += a;\n    x.sum\
    \ += a * (x.cnt);\n    lazy += a;\n    lazy_light += a;\n    mid.sum += (mid.cnt\
    \ * a);\n  }\n\n  // data \u306E reverse \u3082\u884C\u3046\n  void reverse()\
    \ {\n    rev ^= 1;\n    swap(l, r);\n  }\n\n  // LCT \u5185\u3067 expose, update\
    \ \u3092\u884C\u3046\u306E\u3067\u3053\u3053\u306F\u5909\u66F4\u3060\u3051\n \
    \ void set(X x) { vx = x; }\n\n  void add_light(np c) {\n    mid.cnt += c->x.cnt,\
    \ mid.sum += c->x.sum;\n    assert(c->cancel == 0);\n    c->cancel = lazy_light;\n\
    \  }\n  void erase_light(np c) {\n    c->apply(lazy_light - (c->cancel));\n  \
    \  c->cancel = 0;\n    mid.cnt -= c->x.cnt, mid.sum -= c->x.sum;\n  }\n\n  //\
    \ b->x \u306B subtree value \u304C\u5165\u3063\u3066\u3044\u308B.\n  void change_light(np\
    \ a, np b) {\n    b->cancel = a->cancel;\n    a->cancel = 0;\n  }\n};\n\nvoid\
    \ solve() {\n  LL(N, Q);\n  Link_Cut_Tree<Node> LCT(N);\n  VEC(ll, A, N);\n  FOR(i,\
    \ N) { LCT.set(i, {1, A[i]}); }\n  FOR(N - 1) {\n    INT(a, b);\n    LCT.link(a,\
    \ b);\n  }\n\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c,\
    \ d);\n      LCT.cut(a, b);\n      LCT.link(c, d);\n    }\n    if (t == 1) {\n\
    \      LL(v, p, x);\n      LCT.cut(v, p);\n      LCT[v]->apply(x);\n      LCT[v]->push();\n\
    \      LCT.link(v, p);\n    }\n    if (t == 2) {\n      LL(c, p);\n      LCT.cut(c,\
    \ p);\n      print(LCT[c]->x.sum);\n      LCT.link(c, p);\n    }\n  }\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/ds/link_cut_tree.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_tree_subtree_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_tree_subtree_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_tree_subtree_add_subtree_sum.test.cpp
- /verify/test/library_checker/datastructure/dynamic_tree_subtree_add_subtree_sum.test.cpp.html
title: test/library_checker/datastructure/dynamic_tree_subtree_add_subtree_sum.test.cpp
---
