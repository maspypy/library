---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/slope_trick/slope_super.hpp
    title: convex/slope_trick/slope_super.hpp
  - icon: ':heavy_check_mark:'
    path: ds/binary_trie.hpp
    title: ds/binary_trie.hpp
  - icon: ':x:'
    path: ds/meldable_heap.hpp
    title: ds/meldable_heap.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_acted_monoid.hpp
    title: ds/splaytree/splaytree_acted_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_acted_set.hpp
    title: ds/splaytree/splaytree_acted_set.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_basic.hpp
    title: ds/splaytree/splaytree_basic.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_commutative_monoid.hpp
    title: ds/splaytree/splaytree_commutative_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_monoid.hpp
    title: ds/splaytree/splaytree_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: geo/polygon_triangulation.hpp
    title: geo/polygon_triangulation.hpp
  - icon: ':x:'
    path: graph/shortest_path/K_shortest_walk.hpp
    title: graph/shortest_path/K_shortest_walk.hpp
  - icon: ':warning:'
    path: seq/cycle_decomposition.hpp
    title: seq/cycle_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/binary_trie.test.cpp
    title: test/1_mytest/binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/cf702_F_splay.test.cpp
    title: test/1_mytest/cf702_F_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  - icon: ':x:'
    path: test/1_mytest/slope_super.test.cpp
    title: test/1_mytest/slope_super.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/splay.test.cpp
    title: test/1_mytest/splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/splay_am.test.cpp
    title: test/1_mytest/splay_am.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/splay_cm.test.cpp
    title: test/1_mytest/splay_cm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/splay_monoid.test.cpp
    title: test/1_mytest/splay_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_reverse_range_sum.test.cpp
    title: test/2_library_checker/data_structure/range_reverse_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/set_xor_min.test.cpp
    title: test/2_library_checker/data_structure/set_xor_min.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/K_shortest_walk.test.cpp
    title: test/2_library_checker/graph/K_shortest_walk.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1154.test.cpp
    title: test/3_yukicoder/1154.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1441.test.cpp
    title: test/3_yukicoder/1441.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1752.test.cpp
    title: test/3_yukicoder/1752.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/1508.test.cpp
    title: test/4_aoj/1508.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\ntemplate <class Node>\nstruct Node_Pool\
    \ {\n  struct Slot {\n    union alignas(Node) {\n      Slot* next;\n      unsigned\
    \ char storage[sizeof(Node)];\n    };\n  };\n  using np = Node*;\n\n  static constexpr\
    \ int CHUNK_SIZE = 1 << 16;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur =\
    \ nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool()\
    \ { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&... args)\
    \ {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
    \  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n    auto\
    \ s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head = s;\n\
    \  }\n\n  void reset() {\n    free_head = nullptr;\n    if (!chunks.empty()) {\n\
    \      cur = chunks[0].get();\n      cur_used = 0;\n    }\n  }\n\n private:\n\
    \  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n"
  code: "template <class Node>\nstruct Node_Pool {\n  struct Slot {\n    union alignas(Node)\
    \ {\n      Slot* next;\n      unsigned char storage[sizeof(Node)];\n    };\n \
    \ };\n  using np = Node*;\n\n  static constexpr int CHUNK_SIZE = 1 << 16;\n\n\
    \  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur = nullptr;\n  int cur_used = 0;\n\
    \  Slot* free_head = nullptr;\n\n  Node_Pool() { alloc_chunk(); }\n\n  template\
    \ <class... Args>\n  np create(Args&&... args) {\n    Slot* s = new_slot();\n\
    \    return ::new (s) Node(forward<Args>(args)...);\n  }\n\n  void destroy(np\
    \ x) {\n    if (!x) return;\n    x->~Node();\n    auto s = reinterpret_cast<Slot*>(x);\n\
    \    s->next = free_head;\n    free_head = s;\n  }\n\n  void reset() {\n    free_head\
    \ = nullptr;\n    if (!chunks.empty()) {\n      cur = chunks[0].get();\n     \
    \ cur_used = 0;\n    }\n  }\n\n private:\n  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/node_pool.hpp
  requiredBy:
  - seq/cycle_decomposition.hpp
  - ds/binary_trie.hpp
  - ds/meldable_heap.hpp
  - ds/splaytree/splaytree_basic.hpp
  - ds/splaytree/splaytree_acted_set.hpp
  - ds/splaytree/splaytree.hpp
  - ds/splaytree/splaytree_acted_monoid.hpp
  - ds/splaytree/splaytree_commutative_monoid.hpp
  - ds/splaytree/splaytree_monoid.hpp
  - convex/slope_trick/slope_super.hpp
  - geo/polygon_triangulation.hpp
  - graph/shortest_path/K_shortest_walk.hpp
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1154.test.cpp
  - test/3_yukicoder/1441.test.cpp
  - test/3_yukicoder/1752.test.cpp
  - test/2_library_checker/data_structure/set_xor_min.test.cpp
  - test/2_library_checker/data_structure/range_reverse_range_sum.test.cpp
  - test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - test/2_library_checker/graph/K_shortest_walk.test.cpp
  - test/1_mytest/splay_am.test.cpp
  - test/1_mytest/splay.test.cpp
  - test/1_mytest/splay_monoid.test.cpp
  - test/1_mytest/slope_super.test.cpp
  - test/1_mytest/binary_trie.test.cpp
  - test/1_mytest/splay_cm.test.cpp
  - test/1_mytest/cf702_F_splay.test.cpp
  - test/1_mytest/polygon_triangulation.test.cpp
  - test/4_aoj/1508.test.cpp
documentation_of: ds/node_pool.hpp
layout: document
redirect_from:
- /library/ds/node_pool.hpp
- /library/ds/node_pool.hpp.html
title: ds/node_pool.hpp
---
