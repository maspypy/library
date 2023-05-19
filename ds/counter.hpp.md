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
  bundledCode: "#line 1 \"ds/counter.hpp\"\n\ntemplate <int KEY_MAX, int CNT_MAX,\
    \ bool BS = false>\nstruct Counter {\n  static constexpr int thresh = (BS ? sqrt(CNT_MAX)\
    \ : 0);\n  int mx;\n  vc<int> freq;\n  vc<int> freq_cnt;\n  vc<bitset<KEY_MAX>>\
    \ key; // freq -> key\n\n  Counter() : mx(0), freq(KEY_MAX), freq_cnt(CNT_MAX\
    \ + 1), key(thresh + 1) {\n    freq_cnt[0] = KEY_MAX;\n    key[0].set();\n  }\n\
    \n  void insert(int k) {\n    if (mx == freq[k]) ++mx;\n    key[min(thresh, freq[k])][k]\
    \ = 0;\n    freq_cnt[freq[k]]--, freq[k]++, freq_cnt[freq[k]]++;\n    key[min(thresh,\
    \ freq[k])][k] = 1;\n  }\n  void add(int k) { insert(k); }\n\n  void erase(int\
    \ k) {\n    if (mx == freq[k] && freq_cnt[freq[k]] == 1) --mx;\n    key[min(thresh,\
    \ freq[k])][k] = 0;\n    freq_cnt[freq[k]]--, freq[k]--, freq_cnt[freq[k]]++;\n\
    \    key[min(thresh, freq[k])][k] = 1;\n  }\n  void remove(int k) { erase(k);\
    \ }\n\n  int operator[](int x) { return freq[x]; }\n\n  int max_freq() { return\
    \ mx; }\n  int max_freq_key() {\n    static_assert(BS);\n    if (mx < thresh)\
    \ return key[mx]._Find_first();\n    bitset<KEY_MAX>& b = key[thresh];\n    int\
    \ p = b._Find_first();\n    while (1) {\n      if (freq[p] == mx) return p;\n\
    \      p = b._Find_next(p);\n    }\n    assert(0);\n    return -1;\n  }\n};\n"
  code: "\ntemplate <int KEY_MAX, int CNT_MAX, bool BS = false>\nstruct Counter {\n\
    \  static constexpr int thresh = (BS ? sqrt(CNT_MAX) : 0);\n  int mx;\n  vc<int>\
    \ freq;\n  vc<int> freq_cnt;\n  vc<bitset<KEY_MAX>> key; // freq -> key\n\n  Counter()\
    \ : mx(0), freq(KEY_MAX), freq_cnt(CNT_MAX + 1), key(thresh + 1) {\n    freq_cnt[0]\
    \ = KEY_MAX;\n    key[0].set();\n  }\n\n  void insert(int k) {\n    if (mx ==\
    \ freq[k]) ++mx;\n    key[min(thresh, freq[k])][k] = 0;\n    freq_cnt[freq[k]]--,\
    \ freq[k]++, freq_cnt[freq[k]]++;\n    key[min(thresh, freq[k])][k] = 1;\n  }\n\
    \  void add(int k) { insert(k); }\n\n  void erase(int k) {\n    if (mx == freq[k]\
    \ && freq_cnt[freq[k]] == 1) --mx;\n    key[min(thresh, freq[k])][k] = 0;\n  \
    \  freq_cnt[freq[k]]--, freq[k]--, freq_cnt[freq[k]]++;\n    key[min(thresh, freq[k])][k]\
    \ = 1;\n  }\n  void remove(int k) { erase(k); }\n\n  int operator[](int x) { return\
    \ freq[x]; }\n\n  int max_freq() { return mx; }\n  int max_freq_key() {\n    static_assert(BS);\n\
    \    if (mx < thresh) return key[mx]._Find_first();\n    bitset<KEY_MAX>& b =\
    \ key[thresh];\n    int p = b._Find_first();\n    while (1) {\n      if (freq[p]\
    \ == mx) return p;\n      p = b._Find_next(p);\n    }\n    assert(0);\n    return\
    \ -1;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/counter.hpp
  requiredBy: []
  timestamp: '2023-05-20 05:16:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/counter.hpp
layout: document
redirect_from:
- /library/ds/counter.hpp
- /library/ds/counter.hpp.html
title: ds/counter.hpp
---
