// https://codeforces.com/contest/892/problem/E
struct RollbackUnionFind {
  vc<int> dat; // parent or size
  vc<pair<int, int>> st;

  RollbackUnionFind(int n) : dat(n, -1) {}

  int operator[](int v) {
    while (dat[v] >= 0) v = dat[v];
    return v;
  }

  int size(int v) { return -dat[(*this)[v]]; }
  int time() { return len(st); }
  void rollback(int t) {
    for (int i = time(); i-- > t;) { dat[st[i].fi] = st[i].se; }
    st.resize(t);
  }
  bool merge(int a, int b) {
    a = (*this)[a], b = (*this)[b];
    if (a == b) return false;
    if (dat[a] > dat[b]) swap(a, b);
    st.eb(a, dat[a]);
    st.eb(b, dat[b]);
    dat[a] += dat[b];
    dat[b] = a;
    return true;
  }
};
