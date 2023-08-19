template <typename CHAR>
struct Trie {
  using MP = map<CHAR, int>;
  int n_node;
  vector<MP> TO;
  vector<int> PAR;
  vector<int> BFS;
  vector<int> FAIL;

  Trie() : n_node(1), TO({MP()}), PAR({-1}) {}

  template <typename STRING>
  int add(STRING S) {
    int v = 0;
    for (auto&& s: S) {
      if (!TO[v].count(s)) {
        TO[v][s] = create_node();
        PAR[TO[v][s]] = v;
      }
      v = TO[v][s];
    }
    return v;
  }

  int create_node() {
    TO.eb(MP());
    PAR.eb(-1);
    return n_node++;
  }
};