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
  bundledCode: "#line 1 \"ds/binary_trie/binarytrie.hpp\"\ntemplate <int LOG = 30>\n\
    struct BinaryTrie {\n  struct Node {\n    ll cnt = 0;\n    int ch[2] = {-1, -1};\n\
    \  };\n  vector<Node> ns;\n\n  BinaryTrie() : ns(1) {}\n\n  ll size() const {\
    \ return ns[0].cnt; }\n  ll operator[](int k) const { return find_kth(k, 0); }\n\
    \  ll find_kth(ll k, ll xor_add = 0) const {\n    assert(0 <= k && k < size());\n\
    \    ll idx = 0;\n    ll val = 0;\n    FOR_R(i, LOG) {\n      ll c = xor_add >>\
    \ i & 1;\n      ll low_ch = ns[idx].ch[c];\n      ll low_cnt = (low_ch >= 0 ?\
    \ ns[low_ch].cnt : 0);\n      if (k < low_cnt) {\n        idx = low_ch;\n    \
    \  } else {\n        k -= low_cnt;\n        idx = ns[idx].ch[c ^ 1];\n       \
    \ val ^= 1LL << i;\n      }\n      assert(idx >= 0);\n    }\n    return val;\n\
    \  }\n\n  void add(ll val, ll cnt = 1) {\n    assert(0 <= val && val < (1LL <<\
    \ LOG));\n    int idx = 0;\n    FOR_R(i, LOG) {\n      ns[idx].cnt += cnt;\n \
    \     assert(ns[idx].cnt >= 0);\n      int &nxt = ns[idx].ch[val >> i & 1];\n\
    \      if (nxt == -1) {\n        idx = nxt = ns.size();\n        ns.emplace_back();\n\
    \      } else {\n        idx = nxt;\n      }\n    }\n    ns[idx].cnt += cnt;\n\
    \    assert(ns[idx].cnt >= 0);\n    return;\n  }\n\n  ll lower_bound(ll val, ll\
    \ xor_add = 0) {\n    assert(0 <= val);\n    if (val >= (1LL << LOG)) return size();\n\
    \    int idx = 0;\n    ll cnt = 0;\n    FOR_R(i, LOG) {\n      int b = val >>\
    \ i & 1, c = xor_add >> i & 1;\n      int ch = ns[idx].ch[c];\n      cnt += (b\
    \ & (ch >= 0) ? ns[ch].cnt : 0);\n      idx = ns[idx].ch[b ^ c];\n      if (idx\
    \ < 0 or ns[idx].cnt == 0) break;\n    }\n    return cnt;\n  }\n\n  ll count(ll\
    \ val) const {\n    assert(0 <= val && val < (1LL << LOG));\n    int idx = 0;\n\
    \    FOR_R(i, LOG) {\n      idx = ns[idx].ch[val >> i & 1];\n      if (idx < 0\
    \ or ns[idx].cnt == 0) return 0;\n    }\n    return ns[idx].cnt;\n  }\n\n  ll\
    \ count(ll L, ll R, ll xor_add = 0) {\n    assert(0 <= L && L <= R && R <= (1LL\
    \ << LOG));\n    return lower_bound(R, xor_add) - lower_bound(L, xor_add);\n \
    \ }\n\n  ll min(ll xor_add = 0) { return find_kth(0, xor_add); }\n  ll max(ll\
    \ xor_add = 0) { return find_kth(size() - 1, xor_add); }\n\n  void debug() {\n\
    \    FOR(i, len(ns)) print(i, \"cnt\", ns[i].cnt, \"ch\", ns[i].ch[0], ns[i].ch[1]);\n\
    \  }\n};\n"
  code: "template <int LOG = 30>\nstruct BinaryTrie {\n  struct Node {\n    ll cnt\
    \ = 0;\n    int ch[2] = {-1, -1};\n  };\n  vector<Node> ns;\n\n  BinaryTrie()\
    \ : ns(1) {}\n\n  ll size() const { return ns[0].cnt; }\n  ll operator[](int k)\
    \ const { return find_kth(k, 0); }\n  ll find_kth(ll k, ll xor_add = 0) const\
    \ {\n    assert(0 <= k && k < size());\n    ll idx = 0;\n    ll val = 0;\n   \
    \ FOR_R(i, LOG) {\n      ll c = xor_add >> i & 1;\n      ll low_ch = ns[idx].ch[c];\n\
    \      ll low_cnt = (low_ch >= 0 ? ns[low_ch].cnt : 0);\n      if (k < low_cnt)\
    \ {\n        idx = low_ch;\n      } else {\n        k -= low_cnt;\n        idx\
    \ = ns[idx].ch[c ^ 1];\n        val ^= 1LL << i;\n      }\n      assert(idx >=\
    \ 0);\n    }\n    return val;\n  }\n\n  void add(ll val, ll cnt = 1) {\n    assert(0\
    \ <= val && val < (1LL << LOG));\n    int idx = 0;\n    FOR_R(i, LOG) {\n    \
    \  ns[idx].cnt += cnt;\n      assert(ns[idx].cnt >= 0);\n      int &nxt = ns[idx].ch[val\
    \ >> i & 1];\n      if (nxt == -1) {\n        idx = nxt = ns.size();\n       \
    \ ns.emplace_back();\n      } else {\n        idx = nxt;\n      }\n    }\n   \
    \ ns[idx].cnt += cnt;\n    assert(ns[idx].cnt >= 0);\n    return;\n  }\n\n  ll\
    \ lower_bound(ll val, ll xor_add = 0) {\n    assert(0 <= val);\n    if (val >=\
    \ (1LL << LOG)) return size();\n    int idx = 0;\n    ll cnt = 0;\n    FOR_R(i,\
    \ LOG) {\n      int b = val >> i & 1, c = xor_add >> i & 1;\n      int ch = ns[idx].ch[c];\n\
    \      cnt += (b & (ch >= 0) ? ns[ch].cnt : 0);\n      idx = ns[idx].ch[b ^ c];\n\
    \      if (idx < 0 or ns[idx].cnt == 0) break;\n    }\n    return cnt;\n  }\n\n\
    \  ll count(ll val) const {\n    assert(0 <= val && val < (1LL << LOG));\n   \
    \ int idx = 0;\n    FOR_R(i, LOG) {\n      idx = ns[idx].ch[val >> i & 1];\n \
    \     if (idx < 0 or ns[idx].cnt == 0) return 0;\n    }\n    return ns[idx].cnt;\n\
    \  }\n\n  ll count(ll L, ll R, ll xor_add = 0) {\n    assert(0 <= L && L <= R\
    \ && R <= (1LL << LOG));\n    return lower_bound(R, xor_add) - lower_bound(L,\
    \ xor_add);\n  }\n\n  ll min(ll xor_add = 0) { return find_kth(0, xor_add); }\n\
    \  ll max(ll xor_add = 0) { return find_kth(size() - 1, xor_add); }\n\n  void\
    \ debug() {\n    FOR(i, len(ns)) print(i, \"cnt\", ns[i].cnt, \"ch\", ns[i].ch[0],\
    \ ns[i].ch[1]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/binary_trie/binarytrie.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/binary_trie/binarytrie.hpp
layout: document
redirect_from:
- /library/ds/binary_trie/binarytrie.hpp
- /library/ds/binary_trie/binarytrie.hpp.html
title: ds/binary_trie/binarytrie.hpp
---
