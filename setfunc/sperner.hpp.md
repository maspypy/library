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
  bundledCode: "#line 1 \"setfunc/sperner.hpp\"\n\nnamespace Sperner {\n// Symmetric\
    \ Chain Decomposition\n\n// return: \u521D\u671F\u96C6\u5408, \u8DB3\u3057\u3066\
    \u3044\u304F\u3082\u306E, \u4F55\u756A\u76EE\ntemplate <typename F>\ntuple<vc<int>,\
    \ vc<int>, int> get_chain(int N, F check) {\n  vc<int> S, ADD;\n  int rk = 0;\n\
    \  for (int i = 0; i < N; ++i) {\n    if (check(i)) {\n      if (rk == int(ADD.size()))\
    \ {\n        ADD.emplace_back(i);\n        ++rk;\n      } else {\n        ADD.pop_back();\n\
    \        S.emplace_back(i);\n      }\n    } else {\n      ADD.emplace_back(i);\n\
    \    }\n  }\n  return {S, ADD, rk};\n}\n\ntemplate <typename F>\nint rm_element(int\
    \ N, F check) {\n  int ans = -1, rk = 0, length = 0;\n  for (int i = 0; i < N;\
    \ ++i) {\n    if (check(i)) {\n      if (rk == length) {\n        ans = i;\n \
    \       ++length, ++rk;\n      } else {\n        --length;\n      }\n    } else\
    \ {\n      ++length;\n    }\n  }\n  return ans;\n}\n\ntemplate <typename F>\n\
    int add_element(int N, F check) {\n  int ans = -1, rk = 0, length = 0;\n  for\
    \ (int i = 0; i < N; ++i) {\n    if (check(i)) {\n      if (rk == length) {\n\
    \        ++length, ++rk;\n      } else {\n        --length;\n      }\n    } else\
    \ {\n      if (rk == length) ans = i;\n      ++length;\n    }\n  }\n  return (rk\
    \ < length ? ans : -1);\n}\n};  // namespace Sperner\n"
  code: "\nnamespace Sperner {\n// Symmetric Chain Decomposition\n\n// return: \u521D\
    \u671F\u96C6\u5408, \u8DB3\u3057\u3066\u3044\u304F\u3082\u306E, \u4F55\u756A\u76EE\
    \ntemplate <typename F>\ntuple<vc<int>, vc<int>, int> get_chain(int N, F check)\
    \ {\n  vc<int> S, ADD;\n  int rk = 0;\n  for (int i = 0; i < N; ++i) {\n    if\
    \ (check(i)) {\n      if (rk == int(ADD.size())) {\n        ADD.emplace_back(i);\n\
    \        ++rk;\n      } else {\n        ADD.pop_back();\n        S.emplace_back(i);\n\
    \      }\n    } else {\n      ADD.emplace_back(i);\n    }\n  }\n  return {S, ADD,\
    \ rk};\n}\n\ntemplate <typename F>\nint rm_element(int N, F check) {\n  int ans\
    \ = -1, rk = 0, length = 0;\n  for (int i = 0; i < N; ++i) {\n    if (check(i))\
    \ {\n      if (rk == length) {\n        ans = i;\n        ++length, ++rk;\n  \
    \    } else {\n        --length;\n      }\n    } else {\n      ++length;\n   \
    \ }\n  }\n  return ans;\n}\n\ntemplate <typename F>\nint add_element(int N, F\
    \ check) {\n  int ans = -1, rk = 0, length = 0;\n  for (int i = 0; i < N; ++i)\
    \ {\n    if (check(i)) {\n      if (rk == length) {\n        ++length, ++rk;\n\
    \      } else {\n        --length;\n      }\n    } else {\n      if (rk == length)\
    \ ans = i;\n      ++length;\n    }\n  }\n  return (rk < length ? ans : -1);\n\
    }\n};  // namespace Sperner\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/sperner.hpp
  requiredBy: []
  timestamp: '2026-05-01 13:15:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/sperner.hpp
layout: document
redirect_from:
- /library/setfunc/sperner.hpp
- /library/setfunc/sperner.hpp.html
title: setfunc/sperner.hpp
---
