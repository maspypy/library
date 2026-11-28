---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/offline_query/offline_set_intersection.hpp
    title: ds/offline_query/offline_set_intersection.hpp
  - icon: ':heavy_check_mark:'
    path: flow/bipartite_matching.hpp
    title: flow/bipartite_matching.hpp
  - icon: ':heavy_check_mark:'
    path: graph/all_cycle_common_vertices.hpp
    title: graph/all_cycle_common_vertices.hpp
  - icon: ':warning:'
    path: graph/bipartite_balanced_edge_coloring.hpp
    title: graph/bipartite_balanced_edge_coloring.hpp
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_edge_coloring.hpp
    title: graph/bipartite_edge_coloring.hpp
  - icon: ':warning:'
    path: graph/bitset/transitive_closure.hpp
    title: graph/bitset/transitive_closure.hpp
  - icon: ':warning:'
    path: graph/bitset/transitive_reduction.hpp
    title: graph/bitset/transitive_reduction.hpp
  - icon: ':warning:'
    path: graph/cactus.hpp
    title: graph/cactus.hpp
  - icon: ':warning:'
    path: graph/degree_sequence.hpp
    title: graph/degree_sequence.hpp
  - icon: ':heavy_check_mark:'
    path: graph/find_odd_cycle.hpp
    title: graph/find_odd_cycle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/incremental_scc.hpp
    title: graph/incremental_scc.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum_antichain.hpp
    title: graph/maximum_antichain.hpp
  - icon: ':heavy_check_mark:'
    path: graph/reachability.hpp
    title: graph/reachability.hpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  - icon: ':heavy_check_mark:'
    path: graph/twosat.hpp
    title: graph/twosat.hpp
  - icon: ':heavy_check_mark:'
    path: nt/EGZ.hpp
    title: nt/EGZ.hpp
  - icon: ':warning:'
    path: string/enumerate_occurrences.hpp
    title: string/enumerate_occurrences.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/EGZ.test.cpp
    title: test/1_mytest/EGZ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/all_cycle_common_vertex.test.cpp
    title: test/1_mytest/all_cycle_common_vertex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_odd_cycle.test.cpp
    title: test/1_mytest/find_odd_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/incremental_scc.test.cpp
    title: test/1_mytest/incremental_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching_ve.test.cpp
    title: test/1_mytest/matching_ve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/scc_tournament.test.cpp
    title: test/1_mytest/scc_tournament.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tutte.test.cpp
    title: test/1_mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
    title: test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/bipartitematching.test.cpp
    title: test/2_library_checker/graph/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/incremental_scc.test.cpp
    title: test/2_library_checker/graph/incremental_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/scc.test.cpp
    title: test/2_library_checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/other/twosat.test.cpp
    title: test/2_library_checker/other/twosat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1170.test.cpp
    title: test/3_yukicoder/1170.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1293.test.cpp
    title: test/3_yukicoder/1293.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1479.test.cpp
    title: test/3_yukicoder/1479.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1744.test.cpp
    title: test/3_yukicoder/1744.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1745.test.cpp
    title: test/3_yukicoder/1745.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1813.test.cpp
    title: test/3_yukicoder/1813.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/0275.test.cpp
    title: test/4_aoj/0275.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/1566.test.cpp
    title: test/4_aoj/1566.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/2251_2.test.cpp
    title: test/4_aoj/2251_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/csr.hpp
  bundledCode: "#line 1 \"ds/csr.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/csr.hpp\n\
    \ntemplate <typename T>\nstruct CSR {\n  int n;\n  bool prepared;\n  vc<int> ptr;\n\
    \  vc<int> I;\n  vc<T> dat;\n\n  CSR(int n = 0) : n(n), prepared(false) {}\n \
    \ void reserve(int n) { dat.reserve(n); }\n\n  void add(int i, const T& x) {\n\
    \    assert(0 <= i && i < n && !prepared);\n    I.eb(i), dat.eb(x);\n  }\n\n \
    \ void build() {\n    assert(!prepared);\n    prepared = 1;\n    ptr.assign(n\
    \ + 1, 0);\n    for (auto& i : I) ptr[1 + i]++;\n    FOR(i, len(ptr) - 1) ptr[i\
    \ + 1] += ptr[i];\n    vc<T> tmp(len(dat));\n    FOR(k, len(dat)) {\n      int\
    \ i = I[k];\n      tmp[ptr[i]++] = dat[k];\n    }\n    swap(dat, tmp);\n    ptr.pop_back();\n\
    \    ptr.insert(ptr.begin(), 0);\n    I.clear();\n  }\n\n  struct range {\n  \
    \  T *first, *last;\n    T* begin() const { return first; }\n    T* end() const\
    \ { return last; }\n    bool empty() const { return first == last; }\n    int\
    \ size() const { return last - first; }\n  };\n\n  range operator[](int i) {\n\
    \    assert(prepared);\n    return range{dat.data() + ptr[i], dat.data() + ptr[i\
    \ + 1]};\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/csr.hpp\n\ntemplate\
    \ <typename T>\nstruct CSR {\n  int n;\n  bool prepared;\n  vc<int> ptr;\n  vc<int>\
    \ I;\n  vc<T> dat;\n\n  CSR(int n = 0) : n(n), prepared(false) {}\n  void reserve(int\
    \ n) { dat.reserve(n); }\n\n  void add(int i, const T& x) {\n    assert(0 <= i\
    \ && i < n && !prepared);\n    I.eb(i), dat.eb(x);\n  }\n\n  void build() {\n\
    \    assert(!prepared);\n    prepared = 1;\n    ptr.assign(n + 1, 0);\n    for\
    \ (auto& i : I) ptr[1 + i]++;\n    FOR(i, len(ptr) - 1) ptr[i + 1] += ptr[i];\n\
    \    vc<T> tmp(len(dat));\n    FOR(k, len(dat)) {\n      int i = I[k];\n     \
    \ tmp[ptr[i]++] = dat[k];\n    }\n    swap(dat, tmp);\n    ptr.pop_back();\n \
    \   ptr.insert(ptr.begin(), 0);\n    I.clear();\n  }\n\n  struct range {\n   \
    \ T *first, *last;\n    T* begin() const { return first; }\n    T* end() const\
    \ { return last; }\n    bool empty() const { return first == last; }\n    int\
    \ size() const { return last - first; }\n  };\n\n  range operator[](int i) {\n\
    \    assert(prepared);\n    return range{dat.data() + ptr[i], dat.data() + ptr[i\
    \ + 1]};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/csr.hpp
  requiredBy:
  - graph/maximum_antichain.hpp
  - graph/bitset/transitive_reduction.hpp
  - graph/bitset/transitive_closure.hpp
  - graph/all_cycle_common_vertices.hpp
  - graph/degree_sequence.hpp
  - graph/find_odd_cycle.hpp
  - graph/reachability.hpp
  - graph/bipartite_balanced_edge_coloring.hpp
  - graph/bipartite_edge_coloring.hpp
  - graph/strongly_connected_component.hpp
  - graph/incremental_scc.hpp
  - graph/twosat.hpp
  - graph/cactus.hpp
  - ds/offline_query/offline_set_intersection.hpp
  - string/enumerate_occurrences.hpp
  - flow/bipartite_matching.hpp
  - nt/EGZ.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/4_aoj/2251_2.test.cpp
  - test/4_aoj/1566.test.cpp
  - test/4_aoj/0275.test.cpp
  - test/1_mytest/all_cycle_common_vertex.test.cpp
  - test/1_mytest/matching_ve.test.cpp
  - test/1_mytest/tutte.test.cpp
  - test/1_mytest/incremental_scc.test.cpp
  - test/1_mytest/EGZ.test.cpp
  - test/1_mytest/scc_tournament.test.cpp
  - test/1_mytest/find_odd_cycle.test.cpp
  - test/3_yukicoder/1170.test.cpp
  - test/3_yukicoder/1744.test.cpp
  - test/3_yukicoder/1745.test.cpp
  - test/3_yukicoder/1293.test.cpp
  - test/3_yukicoder/1479.test.cpp
  - test/3_yukicoder/1813.test.cpp
  - test/2_library_checker/graph/scc.test.cpp
  - test/2_library_checker/graph/bipartitematching.test.cpp
  - test/2_library_checker/graph/incremental_scc.test.cpp
  - test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
  - test/2_library_checker/other/twosat.test.cpp
documentation_of: ds/csr.hpp
layout: document
redirect_from:
- /library/ds/csr.hpp
- /library/ds/csr.hpp.html
title: ds/csr.hpp
---
