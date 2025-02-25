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
  bundledCode: "#line 1 \"other/timer.hpp\"\n\nstruct Timer {\n  bool started;\n \
    \ chrono::high_resolution_clock::time_point s;\n\n  Timer() : started(false) {}\n\
    \  void start() {\n    started = true;\n    s = chrono::high_resolution_clock::now();\n\
    \  }\n\n  // second from start\n  double operator()() {\n    assert(started);\n\
    \    chrono::high_resolution_clock::time_point t = chrono::high_resolution_clock::now();\n\
    \    chrono::duration<double> diff = t - s;\n    return diff.count();\n  }\n};\n"
  code: "\nstruct Timer {\n  bool started;\n  chrono::high_resolution_clock::time_point\
    \ s;\n\n  Timer() : started(false) {}\n  void start() {\n    started = true;\n\
    \    s = chrono::high_resolution_clock::now();\n  }\n\n  // second from start\n\
    \  double operator()() {\n    assert(started);\n    chrono::high_resolution_clock::time_point\
    \ t = chrono::high_resolution_clock::now();\n    chrono::duration<double> diff\
    \ = t - s;\n    return diff.count();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/timer.hpp
  requiredBy: []
  timestamp: '2025-02-25 18:00:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/timer.hpp
layout: document
redirect_from:
- /library/other/timer.hpp
- /library/other/timer.hpp.html
title: other/timer.hpp
---
