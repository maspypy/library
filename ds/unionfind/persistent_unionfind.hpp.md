---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/pds/array.hpp
    title: ds/pds/array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/pds/array.hpp\"\n\r\ntemplate <typename T, int shift\
    \ = 4>\r\nstruct PersistentArray {\r\n  struct node;\r\n  using np = node*;\r\n\
    \  struct node {\r\n    T data;\r\n    np ch[1 << shift] = {};\r\n  };\r\n\r\n\
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
    \   }\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"ds/unionfind/persistent_unionfind.hpp\"\
    \n\r\nstruct PersistentUnionFind {\r\n  using PA = PersistentArray<int>;\r\n \
    \ int n;\r\n  PA data; // root OR (-size)\r\n  using np = PA::np;\r\n\r\n  PersistentUnionFind(int\
    \ n) : n(n) {}\r\n  np init() {\r\n    np t = data.get_root();\r\n    FOR(i, n)\
    \ data.destructive_set(t, i, -1);\r\n    return t;\r\n  }\r\n\r\n  pair<bool,\
    \ np> merge(np t, int x, int y) {\r\n    x = root(t, x), y = root(t, y);\r\n \
    \   if (x == y) return {0, t};\r\n    if (data.get(t, x) > data.get(t, y)) swap(x,\
    \ y);\r\n    int new_sz = data.get(t, x) + data.get(t, y);\r\n    np set_x_sz\
    \ = data.set(t, x, new_sz);\r\n    np set_y_par = data.set(set_x_sz, y, x);\r\n\
    \    return {1, set_y_par};\r\n  }\r\n\r\n  int root(np t, int x) {\r\n    int\
    \ par_or_sz = data.get(t, x);\r\n    if (par_or_sz < 0) return x;\r\n    return\
    \ root(t, par_or_sz);\r\n  }\r\n\r\n  bool same(np t, int x, int y) { return root(t,\
    \ x) == root(t, y); }\r\n  int size(np t, int x) { return -data.get(t, root(t,\
    \ x)); }\r\n};\n"
  code: "#include \"ds/pds/array.hpp\"\r\n\r\nstruct PersistentUnionFind {\r\n  using\
    \ PA = PersistentArray<int>;\r\n  int n;\r\n  PA data; // root OR (-size)\r\n\
    \  using np = PA::np;\r\n\r\n  PersistentUnionFind(int n) : n(n) {}\r\n  np init()\
    \ {\r\n    np t = data.get_root();\r\n    FOR(i, n) data.destructive_set(t, i,\
    \ -1);\r\n    return t;\r\n  }\r\n\r\n  pair<bool, np> merge(np t, int x, int\
    \ y) {\r\n    x = root(t, x), y = root(t, y);\r\n    if (x == y) return {0, t};\r\
    \n    if (data.get(t, x) > data.get(t, y)) swap(x, y);\r\n    int new_sz = data.get(t,\
    \ x) + data.get(t, y);\r\n    np set_x_sz = data.set(t, x, new_sz);\r\n    np\
    \ set_y_par = data.set(set_x_sz, y, x);\r\n    return {1, set_y_par};\r\n  }\r\
    \n\r\n  int root(np t, int x) {\r\n    int par_or_sz = data.get(t, x);\r\n   \
    \ if (par_or_sz < 0) return x;\r\n    return root(t, par_or_sz);\r\n  }\r\n\r\n\
    \  bool same(np t, int x, int y) { return root(t, x) == root(t, y); }\r\n  int\
    \ size(np t, int x) { return -data.get(t, root(t, x)); }\r\n};"
  dependsOn:
  - ds/pds/array.hpp
  isVerificationFile: false
  path: ds/unionfind/persistent_unionfind.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/unionfind/persistent_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/persistent_unionfind.hpp
- /library/ds/unionfind/persistent_unionfind.hpp.html
title: ds/unionfind/persistent_unionfind.hpp
---
