---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_automaton.hpp
    title: string/suffix_automaton.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.16/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.16/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.16/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.16/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/suffix_automaton.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"string/suffix_automaton.hpp\"\
    \n\n/*\n\u5BFE\u8C61: Suffix_Automaton<3> \u306E build, next, len_range \u3068\
    \ Node::occ/min_pos/max_pos\u3002\n\u65E2\u5B58\u306E number_of_substrings \u306E\
    \u691C\u8A3C\u306F\u9577\u3055\u548C\u306E\u307F\u306A\u306E\u3067\u3001\n\u51FA\
    \u73FE\u4F4D\u7F6E\u3001\u9077\u79FB\u3067\u8868\u3055\u308C\u308B\u6700\u9577\
    suffix\u3001\u540C\u4E00object\u306E\u518Dbuild\u3092\u76F4\u63A5\u691C\u8A3C\u3059\
    \u308B\u3002\n\u72EC\u7ACB oracle: std::map<string, vector<int>> \u306B\u5168\
    substring\u3068\u305D\u306E\u7D42\u7AEF\u4F4D\u7F6E\u3092\u5217\u6319\u3002\n\
    S \u306E\u7A7A\u6587\u5B57\u3001\u53CD\u5FA9\u6587\u5B57\u3001\u6700\u5C0F\u5468\
    \u671F\u3001\u591A\u7A2E\u985E\u306E\u6587\u5B57\u3001\u975E\u5B58\u5728\u306E\
    \u691C\u7D22\u6587\u5B57\u5217\u3092\u542B\u3081\u308B\u3002\n\u4E71\u6570seed:\
    \ 0x5AFF1A2026ULL\u3002\u30A2\u30EB\u30D5\u30A1\u30D9\u30C3\u30C8\u306F a,b,c\
    \ \u306E\u307F\uFF08off='a'\uFF09\u3002\n\u5168\u63A2\u7D22\u306F |S|<=6\u3001\
    random\u306F |S|<=45\u3002\u30CD\u30C3\u30C8\u30EF\u30FC\u30AF\u3084\u5165\u529B\
    \u3092\u7528\u3044\u306A\u3044\u3002\n*/\nnamespace {\nusing SA = Suffix_Automaton<3>;\n\
    void fail(const string& s, const string& q, const string& why) {\n  cerr << \"\
    Suffix_Automaton S='\" << s << \"' query='\" << q\n       << \"': \" << why <<\
    \ '\\n';\n  abort();\n}\nmap<string, vector<int>> enumerate(const string& s) {\n\
    \  map<string, vector<int>> e;\n  for (int r = 0; r <= int(s.size()); ++r) e[\"\
    \"].push_back(r);\n  for (int l = 0; l < int(s.size()); ++l) {\n    for (int r\
    \ = l + 1; r <= int(s.size()); ++r) {\n      e[s.substr(l, r - l)].push_back(r);\n\
    \    }\n  }\n  return e;\n}\nvoid check_query(const SA& sa, const map<string,\
    \ vector<int>>& e,\n                 const string& s, const string& q) {\n  pair<int,\
    \ int> p = {0, 0};\n  for (char c : q) p = sa.next(p, c - 'a');\n  int best =\
    \ 0;\n  string chosen;\n  for (int k = 1; k <= int(q.size()); ++k) {\n    string\
    \ suffix = q.substr(q.size() - k);\n    if (e.count(suffix)) best = k, chosen\
    \ = suffix;\n  }\n  if (p.second != best) fail(s, q, \"longest matched suffix\
    \ got=\" +\n                                  to_string(p.second) + \" expected=\"\
    \ + to_string(best));\n  if (p.first < 0 || p.first >= sa.n_node) fail(s, q, \"\
    invalid node index\");\n  auto [lo, hi] = sa.len_range(p.first);\n  if (!(lo <=\
    \ best && best < hi)) fail(s, q, \"length not in node range\");\n  const auto&\
    \ nd = sa.nodes[p.first];\n  const auto& ends = e.at(chosen);\n  if (nd.occ !=\
    \ int(ends.size()) || nd.min_pos != ends.front() ||\n      nd.max_pos != ends.back())\
    \ {\n    fail(s, q, \"occ/min_pos/max_pos differs from substring enumeration,\
    \ node=\" +\n                    to_string(p.first));\n  }\n}\nvoid check_source(SA&\
    \ sa, const string& s, mt19937_64& rng) {\n  sa.build(s, 'a');\n  auto e = enumerate(s);\n\
    \  if (int(sa.pos.size()) != int(s.size()) + 1 ||\n      int(sa.nodes.size())\
    \ != sa.n_node) fail(s, \"\", \"size inconsistency\");\n  if (sa.nodes[0].occ\
    \ != int(s.size()) + 1 ||\n      sa.nodes[0].min_pos != 0 || sa.nodes[0].max_pos\
    \ != int(s.size()))\n    fail(s, \"\", \"root endpos is inconsistent\");\n  ll\
    \ distinct = 0;\n  for (int i = 1; i < sa.n_node; ++i) {\n    auto [l, r] = sa.len_range(i);\n\
    \    if (!(1 <= l && l < r)) fail(s, \"\", \"invalid state length range\");\n\
    \    distinct += r - l;\n    if (!(0 <= sa.nodes[i].link && sa.nodes[i].link <\
    \ i))\n      fail(s, \"\", \"suffix-link topological order\");\n  }\n  if (distinct\
    \ != ll(e.size()) - 1) fail(s, \"\", \"distinct substring count\");\n  for (const\
    \ auto& [word, ends] : e) {\n    // substring\u304C\u5B58\u5728\u3059\u308B\u5834\
    \u5408\u3001best=word.size()\u3067\u3001endpos\u60C5\u5831\u3092\u76F4\u63A5\u6BD4\
    \u8F03\u3067\u304D\u308B\u3002\n    check_query(sa, e, s, word);\n  }\n  for (int\
    \ t = 0; t < 45; ++t) {\n    string q;\n    int qn = int(rng() % 25);\n    for\
    \ (int i = 0; i < qn; ++i) q += char('a' + rng() % 3);\n    check_query(sa, e,\
    \ s, q);\n  }\n}\nvoid exhaustive(SA& sa, int n, string& s, mt19937_64& rng) {\n\
    \  if (int(s.size()) == n) {\n    check_source(sa, s, rng);\n    return;\n  }\n\
    \  for (char c = 'a'; c <= 'c'; ++c) {\n    s.push_back(c);\n    exhaustive(sa,\
    \ n, s, rng);\n    s.pop_back();\n  }\n}\n} // namespace\n\nint main() {\n  mt19937_64\
    \ rng(0x5AFF1A2026ULL);\n  SA sa;\n  for (int n = 0; n <= 6; ++n) {\n    string\
    \ s;\n    exhaustive(sa, n, s, rng);\n  }\n  for (int rep = 0; rep < 180; ++rep)\
    \ {\n    int n = int(rng() % 46);\n    string s;\n    for (int i = 0; i < n; ++i)\
    \ s += char('a' + rng() % 3);\n    check_source(sa, s, rng);\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - string/suffix_automaton.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/suffix_automaton_occ_next.test.cpp
  requiredBy: []
  timestamp: '2026-11-23 00:27:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/suffix_automaton_occ_next.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/suffix_automaton_occ_next.test.cpp
- /verify/test/5_ai_generated_test/suffix_automaton_occ_next.test.cpp.html
title: test/5_ai_generated_test/suffix_automaton_occ_next.test.cpp
---
