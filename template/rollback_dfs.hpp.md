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
  bundledCode: "#line 1 \"template/rollback_dfs.hpp\"\n// template/rollback_dfs.hpp\n\
    auto upd = X.calc(len(query));\nvi ANS(len(query));\nvc<int> I(len(upd));\niota(all(I),\
    \ 0);\nauto dfs = [&](auto& dfs, vc<int>& upd_query_I, int begin, int end) ->\
    \ void {\n  if (begin == end) return;\n  // snapshot\n  ;\n  vc<int> IL, IR;\n\
    \  int mid = (begin + end) / 2;\n  for (auto&& i : upd_query_I) {\n    auto [a,\
    \ b, X] = upd[i];\n    if (a <= begin && end <= b) {\n      // X \u3067\u8868\u3055\
    \u308C\u308B update query \u3092\u51E6\u7406\u3059\u308B\n      ;\n      ;\n \
    \   } else {\n      if (a < mid) IL.eb(i);\n      if (mid < b) IR.eb(i);\n   \
    \ }\n  }\n  if (begin + 1 == end) {\n    // \u6C42\u5024\u30AF\u30A8\u30EA\n \
    \   int qid = begin;\n    ;\n    ;  // \u3053\u3053\u3067\u51FA\u529B\u3057\u3066\
    \u3057\u307E\u3063\u3066\u3082\u3088\u3044\n  } else {\n    dfs(dfs, IL, begin,\
    \ mid);\n    dfs(dfs, IR, mid, end);\n  }\n  // rollback\n  ;\n};\ndfs(dfs, I,\
    \ 0, len(query));\n"
  code: "// template/rollback_dfs.hpp\nauto upd = X.calc(len(query));\nvi ANS(len(query));\n\
    vc<int> I(len(upd));\niota(all(I), 0);\nauto dfs = [&](auto& dfs, vc<int>& upd_query_I,\
    \ int begin, int end) -> void {\n  if (begin == end) return;\n  // snapshot\n\
    \  ;\n  vc<int> IL, IR;\n  int mid = (begin + end) / 2;\n  for (auto&& i : upd_query_I)\
    \ {\n    auto [a, b, X] = upd[i];\n    if (a <= begin && end <= b) {\n      //\
    \ X \u3067\u8868\u3055\u308C\u308B update query \u3092\u51E6\u7406\u3059\u308B\
    \n      ;\n      ;\n    } else {\n      if (a < mid) IL.eb(i);\n      if (mid\
    \ < b) IR.eb(i);\n    }\n  }\n  if (begin + 1 == end) {\n    // \u6C42\u5024\u30AF\
    \u30A8\u30EA\n    int qid = begin;\n    ;\n    ;  // \u3053\u3053\u3067\u51FA\u529B\
    \u3057\u3066\u3057\u307E\u3063\u3066\u3082\u3088\u3044\n  } else {\n    dfs(dfs,\
    \ IL, begin, mid);\n    dfs(dfs, IR, mid, end);\n  }\n  // rollback\n  ;\n};\n\
    dfs(dfs, I, 0, len(query));"
  dependsOn: []
  isVerificationFile: false
  path: template/rollback_dfs.hpp
  requiredBy: []
  timestamp: '2026-08-17 09:25:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/rollback_dfs.hpp
layout: document
redirect_from:
- /library/template/rollback_dfs.hpp
- /library/template/rollback_dfs.hpp.html
title: template/rollback_dfs.hpp
---
