---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/decremental_fastset.test.cpp
    title: test/1_mytest/decremental_fastset.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/other/timer.hpp
  bundledCode: "#line 1 \"other/timer.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/other/timer.hpp\n\
    \nstruct Timer {\n  bool started;\n  chrono::high_resolution_clock::time_point\
    \ s;\n\n  Timer() : started(false) {}\n  void start() {\n    started = true;\n\
    \    s = chrono::high_resolution_clock::now();\n  }\n\n  // second from start\n\
    \  double operator()() {\n    assert(started);\n    chrono::high_resolution_clock::time_point\
    \ t = chrono::high_resolution_clock::now();\n    chrono::duration<double> diff\
    \ = t - s;\n    return diff.count();\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/other/timer.hpp\n\
    \nstruct Timer {\n  bool started;\n  chrono::high_resolution_clock::time_point\
    \ s;\n\n  Timer() : started(false) {}\n  void start() {\n    started = true;\n\
    \    s = chrono::high_resolution_clock::now();\n  }\n\n  // second from start\n\
    \  double operator()() {\n    assert(started);\n    chrono::high_resolution_clock::time_point\
    \ t = chrono::high_resolution_clock::now();\n    chrono::duration<double> diff\
    \ = t - s;\n    return diff.count();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/timer.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/decremental_fastset.test.cpp
documentation_of: other/timer.hpp
layout: document
redirect_from:
- /library/other/timer.hpp
- /library/other/timer.hpp.html
title: other/timer.hpp
---
