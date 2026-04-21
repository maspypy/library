// https://codeforces.com/contest/2219/problem/E
// struct State {
//   using score_type = int;
//   using action_type = int;
//   score_type score;
//   BS A;
//   State(int x, const BS& A) : score(x), A(A) {}

//   u64 hash() {
//     u64 x = 0;
//     FOR(i, len(A)) if (A[i]) x ^= base[i];
//     x ^= base[5000 + len(A)];
//     return x;
//   };
//   bool is_terminal() { return len(A) == 1; }

//   template <class F>
//   void generate_next_states(F f) {
//     // child を作って
//     // child.memo = action;
//     // f(child);
//     int n = len(A);
//     assert(n >= 2);
//     BS B = A;
//     B[0] = 0;
//     B.resize(n - 1);
//     B.prefix_xor_sum();
//     f(0, State(score + B.count(), B));
//     B.flip_range(0, n - 1);
//     f(1, State(score + B.count(), B));
//   }
// };

template <class State>
struct BeamSearch {
  using action_type = typename State::action_type;

  struct Node {
    State state;
    int par;
    action_type act;
  };

  vector<vector<Node>> layers;
  int best_dep = -1, best_idx = -1;
  bool finished = false;

  void run(const State& init_state, int beam_width) {
    assert(!finished);
    finished = true;

    layers.clear();
    layers.push_back({Node{init_state, -1, action_type{}}});
    best_dep = 0;
    best_idx = 0;

    auto update_best = [&](int dep, int idx) -> void {
      if (layers[dep][idx].state.score >
          layers[best_dep][best_idx].state.score) {
        best_dep = dep;
        best_idx = idx;
      }
    };

    while (true) {
      int dep = (int)layers.size() - 1;
      auto& cur = layers.back();

      unordered_map<u64, Node> mp;

      for (int i = 0; i < (int)cur.size(); ++i) {
        if (cur[i].state.is_terminal()) continue;
        cur[i].state.generate_next_states(
            [&](const action_type& act, State nxt_state) {
              u64 h = nxt_state.hash();
              Node nxt{nxt_state, i, act};
              auto it = mp.find(h);
              if (it == mp.end() || it->second.state.score < nxt.state.score) {
                mp.insert_or_assign(h, move(nxt));
              }
            });
      }

      if (mp.empty()) break;

      vector<Node> cand;
      cand.reserve(mp.size());
      for (auto& [h, node] : mp) cand.push_back(move(node));

      if ((int)cand.size() > beam_width) {
        nth_element(cand.begin(), cand.begin() + beam_width, cand.end(),
                    [](const Node& a, const Node& b) {
                      return a.state.score > b.state.score;
                    });
        cand.erase(cand.begin() + beam_width, cand.end());
      }
      sort(cand.begin(), cand.end(), [](const Node& a, const Node& b) {
        return a.state.score > b.state.score;
      });

      layers.push_back(move(cand));
      ++dep;

      for (int i = 0; i < (int)layers[dep].size(); ++i) {
        update_best(dep, i);
      }
    }
  }

  const State& get_best_state() const {
    assert(finished);
    return layers[best_dep][best_idx].state;
  }

  vector<action_type> get_actions() const {
    assert(finished);
    vector<action_type> actions;
    int dep = best_dep, idx = best_idx;
    while (dep > 0) {
      actions.push_back(layers[dep][idx].act);
      idx = layers[dep][idx].par;
      --dep;
    }
    reverse(actions.begin(), actions.end());
    return actions;
  }
};
