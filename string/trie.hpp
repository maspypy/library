template <int sigma, int off='a'>
struct Trie {
  int n_node;
  vector<array<int, sigma>> TO;
  vector<int> PAR;
  vector<ll> node_value;
  vector<int> BFS;
  vector<int> FAIL;

  Trie()
      : n_node(1), TO({array<int, sigma>()}), PAR({-1}), node_value({0}) {
        FOR(s, sigma) TO[0][s] = -1;
      }

  int create_node() {
    TO.eb(array<int, sigma>());
    FOR(s, sigma) TO.back()[s] = -1;
    PAR.eb(-1);
    node_value.eb(0);
    return n_node++;
  }

  int add(string S, ll val = 1) {
    int v = 0;
    for (auto&& ss : S) {
      int s = ss - off;
      if (TO[v][s] == -1) {
        TO[v][s] = create_node();
        PAR[TO[v][s]] = v;
      }
      v = TO[v][s];
    }
    node_value[v] += val;
    return v;
  }

  int add(vector<int> S, ll val = 1) {
    int v = 0;
    for (auto&& s : S) {
      if (TO[v][s] == -1) {
        TO[v][s] = create_node();
        PAR[TO[v][s]] = v;
      }
      v = TO[v][s];
    }
    node_value[v] += val;
    return v;
  }

  void make_failure() {
    FAIL.assign(n_node, 0);
    BFS.reserve(n_node);
    deque<int> que;
    que.emplace_back(0);
    BFS.emplace_back(0);
    while (!que.empty()) {
      int v = que.front();
      que.pop_front();
      node_value[v] += node_value[FAIL[v]];
      for (int s = 0; s < sigma; ++s) {
        if (TO[v][s] == -1) continue;
        int w = TO[v][s];
        que.emplace_back(w);
        BFS.emplace_back(w);
        if (v == 0) continue;
        int f = FAIL[v];
        while (f && TO[f][s] == -1) f = FAIL[f];
        if (TO[f][s] == -1)
          FAIL[w] = 0;
        else
          FAIL[w] = TO[f][s];
      }
    }
    FORIN(v, BFS) {
      FOR(s, sigma) if (TO[v][s] == -1) {
        int f = FAIL[v];
        TO[v][s] = TO[f][s];
        if (TO[v][s] == -1) TO[v][s] = 0;
      }
    }
  }
};
