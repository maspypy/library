---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/2219/problem/E
  bundledCode: "#line 1 \"heuristic/beam_search.hpp\"\n// https://codeforces.com/contest/2219/problem/E\n\
    // struct State {\n//   using score_type = int;\n//   using action_type = int;\n\
    //   score_type score;\n//   BS A;\n//   State(int x, const BS& A) : score(x),\
    \ A(A) {}\n\n//   u64 hash() {\n//     u64 x = 0;\n//     FOR(i, len(A)) if (A[i])\
    \ x ^= base[i];\n//     x ^= base[5000 + len(A)];\n//     return x;\n//   };\n\
    //   bool is_terminal() { return len(A) == 1; }\n\n//   template <class F>\n//\
    \   void generate_next_states(F f) {\n//     // child \u3092\u4F5C\u3063\u3066\
    \n//     // child.memo = action;\n//     // f(child);\n//     int n = len(A);\n\
    //     assert(n >= 2);\n//     BS B = A;\n//     B[0] = 0;\n//     B.resize(n\
    \ - 1);\n//     B.prefix_xor_sum();\n//     f(0, State(score + B.count(), B));\n\
    //     B.flip_range(0, n - 1);\n//     f(1, State(score + B.count(), B));\n//\
    \   }\n// };\n\ntemplate <class State>\nstruct BeamSearch {\n  using action_type\
    \ = typename State::action_type;\n\n  struct Node {\n    State state;\n    int\
    \ par;\n    action_type act;\n  };\n\n  vector<vector<Node>> layers;\n  int best_dep\
    \ = -1, best_idx = -1;\n  bool finished = false;\n\n  void run(const State& init_state,\
    \ int beam_width) {\n    assert(!finished);\n    finished = true;\n\n    layers.clear();\n\
    \    layers.push_back({Node{init_state, -1, action_type{}}});\n    best_dep =\
    \ 0;\n    best_idx = 0;\n\n    auto update_best = [&](int dep, int idx) -> void\
    \ {\n      if (layers[dep][idx].state.score >\n          layers[best_dep][best_idx].state.score)\
    \ {\n        best_dep = dep;\n        best_idx = idx;\n      }\n    };\n\n   \
    \ while (true) {\n      int dep = (int)layers.size() - 1;\n      auto& cur = layers.back();\n\
    \n      unordered_map<u64, Node> mp;\n\n      for (int i = 0; i < (int)cur.size();\
    \ ++i) {\n        if (cur[i].state.is_terminal()) continue;\n        cur[i].state.generate_next_states(\n\
    \            [&](const action_type& act, State nxt_state) {\n              u64\
    \ h = nxt_state.hash();\n              Node nxt{nxt_state, i, act};\n        \
    \      auto it = mp.find(h);\n              if (it == mp.end() || it->second.state.score\
    \ < nxt.state.score) {\n                mp.insert_or_assign(h, move(nxt));\n \
    \             }\n            });\n      }\n\n      if (mp.empty()) break;\n\n\
    \      vector<Node> cand;\n      cand.reserve(mp.size());\n      for (auto& [h,\
    \ node] : mp) cand.push_back(move(node));\n\n      if ((int)cand.size() > beam_width)\
    \ {\n        nth_element(cand.begin(), cand.begin() + beam_width, cand.end(),\n\
    \                    [](const Node& a, const Node& b) {\n                    \
    \  return a.state.score > b.state.score;\n                    });\n        cand.erase(cand.begin()\
    \ + beam_width, cand.end());\n      }\n      sort(cand.begin(), cand.end(), [](const\
    \ Node& a, const Node& b) {\n        return a.state.score > b.state.score;\n \
    \     });\n\n      layers.push_back(move(cand));\n      ++dep;\n\n      for (int\
    \ i = 0; i < (int)layers[dep].size(); ++i) {\n        update_best(dep, i);\n \
    \     }\n    }\n  }\n\n  const State& get_best_state() const {\n    assert(finished);\n\
    \    return layers[best_dep][best_idx].state;\n  }\n\n  vector<action_type> get_actions()\
    \ const {\n    assert(finished);\n    vector<action_type> actions;\n    int dep\
    \ = best_dep, idx = best_idx;\n    while (dep > 0) {\n      actions.push_back(layers[dep][idx].act);\n\
    \      idx = layers[dep][idx].par;\n      --dep;\n    }\n    reverse(actions.begin(),\
    \ actions.end());\n    return actions;\n  }\n};\n"
  code: "// https://codeforces.com/contest/2219/problem/E\n// struct State {\n// \
    \  using score_type = int;\n//   using action_type = int;\n//   score_type score;\n\
    //   BS A;\n//   State(int x, const BS& A) : score(x), A(A) {}\n\n//   u64 hash()\
    \ {\n//     u64 x = 0;\n//     FOR(i, len(A)) if (A[i]) x ^= base[i];\n//    \
    \ x ^= base[5000 + len(A)];\n//     return x;\n//   };\n//   bool is_terminal()\
    \ { return len(A) == 1; }\n\n//   template <class F>\n//   void generate_next_states(F\
    \ f) {\n//     // child \u3092\u4F5C\u3063\u3066\n//     // child.memo = action;\n\
    //     // f(child);\n//     int n = len(A);\n//     assert(n >= 2);\n//     BS\
    \ B = A;\n//     B[0] = 0;\n//     B.resize(n - 1);\n//     B.prefix_xor_sum();\n\
    //     f(0, State(score + B.count(), B));\n//     B.flip_range(0, n - 1);\n//\
    \     f(1, State(score + B.count(), B));\n//   }\n// };\n\ntemplate <class State>\n\
    struct BeamSearch {\n  using action_type = typename State::action_type;\n\n  struct\
    \ Node {\n    State state;\n    int par;\n    action_type act;\n  };\n\n  vector<vector<Node>>\
    \ layers;\n  int best_dep = -1, best_idx = -1;\n  bool finished = false;\n\n \
    \ void run(const State& init_state, int beam_width) {\n    assert(!finished);\n\
    \    finished = true;\n\n    layers.clear();\n    layers.push_back({Node{init_state,\
    \ -1, action_type{}}});\n    best_dep = 0;\n    best_idx = 0;\n\n    auto update_best\
    \ = [&](int dep, int idx) -> void {\n      if (layers[dep][idx].state.score >\n\
    \          layers[best_dep][best_idx].state.score) {\n        best_dep = dep;\n\
    \        best_idx = idx;\n      }\n    };\n\n    while (true) {\n      int dep\
    \ = (int)layers.size() - 1;\n      auto& cur = layers.back();\n\n      unordered_map<u64,\
    \ Node> mp;\n\n      for (int i = 0; i < (int)cur.size(); ++i) {\n        if (cur[i].state.is_terminal())\
    \ continue;\n        cur[i].state.generate_next_states(\n            [&](const\
    \ action_type& act, State nxt_state) {\n              u64 h = nxt_state.hash();\n\
    \              Node nxt{nxt_state, i, act};\n              auto it = mp.find(h);\n\
    \              if (it == mp.end() || it->second.state.score < nxt.state.score)\
    \ {\n                mp.insert_or_assign(h, move(nxt));\n              }\n   \
    \         });\n      }\n\n      if (mp.empty()) break;\n\n      vector<Node> cand;\n\
    \      cand.reserve(mp.size());\n      for (auto& [h, node] : mp) cand.push_back(move(node));\n\
    \n      if ((int)cand.size() > beam_width) {\n        nth_element(cand.begin(),\
    \ cand.begin() + beam_width, cand.end(),\n                    [](const Node& a,\
    \ const Node& b) {\n                      return a.state.score > b.state.score;\n\
    \                    });\n        cand.erase(cand.begin() + beam_width, cand.end());\n\
    \      }\n      sort(cand.begin(), cand.end(), [](const Node& a, const Node& b)\
    \ {\n        return a.state.score > b.state.score;\n      });\n\n      layers.push_back(move(cand));\n\
    \      ++dep;\n\n      for (int i = 0; i < (int)layers[dep].size(); ++i) {\n \
    \       update_best(dep, i);\n      }\n    }\n  }\n\n  const State& get_best_state()\
    \ const {\n    assert(finished);\n    return layers[best_dep][best_idx].state;\n\
    \  }\n\n  vector<action_type> get_actions() const {\n    assert(finished);\n \
    \   vector<action_type> actions;\n    int dep = best_dep, idx = best_idx;\n  \
    \  while (dep > 0) {\n      actions.push_back(layers[dep][idx].act);\n      idx\
    \ = layers[dep][idx].par;\n      --dep;\n    }\n    reverse(actions.begin(), actions.end());\n\
    \    return actions;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: heuristic/beam_search.hpp
  requiredBy: []
  timestamp: '2026-04-22 03:33:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: heuristic/beam_search.hpp
layout: document
redirect_from:
- /library/heuristic/beam_search.hpp
- /library/heuristic/beam_search.hpp.html
title: heuristic/beam_search.hpp
---
