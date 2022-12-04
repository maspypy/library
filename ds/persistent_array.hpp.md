---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/persistent_unionfind.hpp
    title: ds/unionfind/persistent_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/persistent_queue.test.cpp
    title: test/library_checker/datastructure/persistent_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/persistent_unionfind.test.cpp
    title: test/library_checker/datastructure/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/persistent_array.hpp\"\n\r\ntemplate <typename T, int\
    \ shift = 4>\r\nstruct PersistentArray {\r\n  struct node;\r\n  using np = node*;\r\
    \n  struct node {\r\n    T data;\r\n    np ch[1 << shift] = {};\r\n  };\r\n\r\n\
    \  static constexpr int mask = (1 << shift) - 1;\r\n  np root = nullptr;\r\n \
    \ PersistentArray() {}\r\n  np get_root() { return root; }\r\n  T get(np t, int\
    \ idx) {\r\n    if (!t) return 0;\r\n    if (idx == 0) {\r\n      return t->data;\r\
    \n    } else {\r\n      return get(t->ch[idx & mask], idx >> shift);\r\n    }\r\
    \n  }\r\n\r\n  void destructive_set(np& t, int idx, T val) {\r\n    // \u7834\u58CA\
    \u7684\u306A\u5024\u306E\u5909\u66F4\u3002\u4E3B\u306B\u521D\u671F\u5316\u306B\
    \u4F7F\u3046\u3002\r\n    if (!t) t = new node();\r\n    if (idx == 0)\r\n   \
    \   t->data = val;\r\n    else {\r\n      destructive_set(t->ch[idx & mask], idx\
    \ >> shift, val);\r\n    }\r\n  }\r\n\r\n  np set(const np& t, int idx, T val)\
    \ {\r\n    // set \u3057\u305F\u3042\u3068\u306E\u6C38\u7D9A\u914D\u5217\u306E\
    \ root node pointer \u3092\u8FD4\u3059\r\n    np res = new node();\r\n    if (t)\
    \ {\r\n      memcpy(res->ch, t->ch, sizeof(t->ch));\r\n      res->data = t->data;\r\
    \n    }\r\n    if (idx == 0) {\r\n      res->data = val;\r\n    } else {\r\n \
    \     res->ch[idx & mask] = set(res->ch[idx & mask], idx >> shift, val);\r\n \
    \   }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, int shift = 4>\r\nstruct PersistentArray\
    \ {\r\n  struct node;\r\n  using np = node*;\r\n  struct node {\r\n    T data;\r\
    \n    np ch[1 << shift] = {};\r\n  };\r\n\r\n  static constexpr int mask = (1\
    \ << shift) - 1;\r\n  np root = nullptr;\r\n  PersistentArray() {}\r\n  np get_root()\
    \ { return root; }\r\n  T get(np t, int idx) {\r\n    if (!t) return 0;\r\n  \
    \  if (idx == 0) {\r\n      return t->data;\r\n    } else {\r\n      return get(t->ch[idx\
    \ & mask], idx >> shift);\r\n    }\r\n  }\r\n\r\n  void destructive_set(np& t,\
    \ int idx, T val) {\r\n    // \u7834\u58CA\u7684\u306A\u5024\u306E\u5909\u66F4\
    \u3002\u4E3B\u306B\u521D\u671F\u5316\u306B\u4F7F\u3046\u3002\r\n    if (!t) t\
    \ = new node();\r\n    if (idx == 0)\r\n      t->data = val;\r\n    else {\r\n\
    \      destructive_set(t->ch[idx & mask], idx >> shift, val);\r\n    }\r\n  }\r\
    \n\r\n  np set(const np& t, int idx, T val) {\r\n    // set \u3057\u305F\u3042\
    \u3068\u306E\u6C38\u7D9A\u914D\u5217\u306E root node pointer \u3092\u8FD4\u3059\
    \r\n    np res = new node();\r\n    if (t) {\r\n      memcpy(res->ch, t->ch, sizeof(t->ch));\r\
    \n      res->data = t->data;\r\n    }\r\n    if (idx == 0) {\r\n      res->data\
    \ = val;\r\n    } else {\r\n      res->ch[idx & mask] = set(res->ch[idx & mask],\
    \ idx >> shift, val);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/persistent_array.hpp
  requiredBy:
  - ds/unionfind/persistent_unionfind.hpp
  timestamp: '2022-12-05 07:33:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/persistent_unionfind.test.cpp
  - test/library_checker/datastructure/persistent_queue.test.cpp
documentation_of: ds/persistent_array.hpp
layout: document
redirect_from:
- /library/ds/persistent_array.hpp
- /library/ds/persistent_array.hpp.html
title: ds/persistent_array.hpp
---
