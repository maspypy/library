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
  bundledCode: "#line 1 \"ds/range_min_change.hpp\"\n/*\np \u3092\u30A4\u30F3\u30AF\
    \u30EA\u30E1\u30F3\u30C8\u3057\u306A\u304C\u3089\nright_change: ANS[i]:=min of\
    \ [i,p) \u3092\u7BA1\u7406\nleft_change: ANS[i]:=min of [p,i) \u3092\u7BA1\u7406\
    \ni \u306F [0,N+1) \u3067\u7A7A\u533A\u9593\u306B\u306F infty<T> \u3092\u5165\u308C\
    \u308B\n*/\ntemplate <typename T>\nstruct Range_Min_Change {\n  vc<T> A;\n  int\
    \ N, pl, pr;\n  bool prepared;\n  Range_Min_Change(vc<T>& A) : A(A), N(len(A)),\
    \ pl(0), pr(0), prepared(0) {}\n  template <typename F>\n  Range_Min_Change(int\
    \ N, F f) : N(len(A)), pl(0), pr(0), prepared(0) {\n    A.resize(N);\n    FOR(i,\
    \ N) A[i] = f(i);\n  }\n  vc<pair<int, T>> st_right;\n\n  template <typename F>\n\
    \  void right_change(int i, F f) {\n    assert(pr == i);\n    ++pr;\n    int R\
    \ = i;\n    f(i, i + 1, infty<T>, A[i]);\n    while (len(st_right) && st_right.back().se\
    \ >= A[i]) {\n      auto [L, x] = POP(st_right);\n      if (x != A[i]) f(L, R,\
    \ x, A[i]);\n      R = L;\n    }\n    st_right.eb(R, A[i]);\n  }\n\n  vc<tuple<int,\
    \ int, int, T, T>> event_left;\n\n  template <typename F>\n  void left_change(int\
    \ i, F f) {\n    assert(pl == i && prepared);\n    ++pl;\n    while (len(event_left)\
    \ && get<0>(event_left.back()) == i) {\n      auto [_, L, R, a, b] = POP(event_left);\n\
    \      f(L, R, b, a);\n    }\n  }\n\n  template <typename F>\n  void left_init(F\
    \ f) {\n    assert(!prepared);\n    prepared = 1;\n\n    vc<pair<int, T>> st;\n\
    \    for (int i = N; i--;) {\n      int R = i + 2;\n      event_left.eb(i, i +\
    \ 1, R, infty<T>, A[i]);\n      while (len(st) && st.back().se >= A[i]) {\n  \
    \      auto [RR, x] = POP(st);\n        if (x != A[i]) event_left.eb(i, R, RR,\
    \ x, A[i]);\n        R = RR;\n      }\n      st.eb(R, A[i]);\n    }\n\n    f(0,\
    \ 1, infty<T>);\n    int L = 1;\n    for (int k = len(st); k--;) {\n      auto\
    \ [R, x] = st[k];\n      f(L, R, x);\n      L = R;\n    }\n  }\n};\n"
  code: "/*\np \u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u306A\u304C\u3089\
    \nright_change: ANS[i]:=min of [i,p) \u3092\u7BA1\u7406\nleft_change: ANS[i]:=min\
    \ of [p,i) \u3092\u7BA1\u7406\ni \u306F [0,N+1) \u3067\u7A7A\u533A\u9593\u306B\
    \u306F infty<T> \u3092\u5165\u308C\u308B\n*/\ntemplate <typename T>\nstruct Range_Min_Change\
    \ {\n  vc<T> A;\n  int N, pl, pr;\n  bool prepared;\n  Range_Min_Change(vc<T>&\
    \ A) : A(A), N(len(A)), pl(0), pr(0), prepared(0) {}\n  template <typename F>\n\
    \  Range_Min_Change(int N, F f) : N(len(A)), pl(0), pr(0), prepared(0) {\n   \
    \ A.resize(N);\n    FOR(i, N) A[i] = f(i);\n  }\n  vc<pair<int, T>> st_right;\n\
    \n  template <typename F>\n  void right_change(int i, F f) {\n    assert(pr ==\
    \ i);\n    ++pr;\n    int R = i;\n    f(i, i + 1, infty<T>, A[i]);\n    while\
    \ (len(st_right) && st_right.back().se >= A[i]) {\n      auto [L, x] = POP(st_right);\n\
    \      if (x != A[i]) f(L, R, x, A[i]);\n      R = L;\n    }\n    st_right.eb(R,\
    \ A[i]);\n  }\n\n  vc<tuple<int, int, int, T, T>> event_left;\n\n  template <typename\
    \ F>\n  void left_change(int i, F f) {\n    assert(pl == i && prepared);\n   \
    \ ++pl;\n    while (len(event_left) && get<0>(event_left.back()) == i) {\n   \
    \   auto [_, L, R, a, b] = POP(event_left);\n      f(L, R, b, a);\n    }\n  }\n\
    \n  template <typename F>\n  void left_init(F f) {\n    assert(!prepared);\n \
    \   prepared = 1;\n\n    vc<pair<int, T>> st;\n    for (int i = N; i--;) {\n \
    \     int R = i + 2;\n      event_left.eb(i, i + 1, R, infty<T>, A[i]);\n    \
    \  while (len(st) && st.back().se >= A[i]) {\n        auto [RR, x] = POP(st);\n\
    \        if (x != A[i]) event_left.eb(i, R, RR, x, A[i]);\n        R = RR;\n \
    \     }\n      st.eb(R, A[i]);\n    }\n\n    f(0, 1, infty<T>);\n    int L = 1;\n\
    \    for (int k = len(st); k--;) {\n      auto [R, x] = st[k];\n      f(L, R,\
    \ x);\n      L = R;\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/range_min_change.hpp
  requiredBy: []
  timestamp: '2026-08-11 19:18:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/range_min_change.hpp
layout: document
redirect_from:
- /library/ds/range_min_change.hpp
- /library/ds/range_min_change.hpp.html
title: ds/range_min_change.hpp
---
