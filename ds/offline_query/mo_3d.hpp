// https://codeforces.com/contest/940/problem/F
template <typename CHANGE>
struct Mo_3d {
  int n;
  vc<CHANGE> change;
  vc<tuple<int, int, int>> query;
  vector<pair<int, int>> lr;

  explicit Mo_3d() {}
  int size() { return query.size(); }

  void add_query(int l, int r) {
    int t = len(change) - 1;
    query.eb(t, l, r);
  }

  void add_change(CHANGE x) { change.eb(x); }

  vc<int> get_mo_order(ll block_sz) {
    constexpr ll K = 1 << 20;
    int Q = len(query);
    vi key(Q);
    FOR(q, Q) {
      auto [t, l, r] = query[q];
      t /= block_sz;
      l /= block_sz;
      ll x = r;
      if (l & 1) x = -x;
      x += l * K;
      if (t & 1) x = -x;
      x += t * K * K;
      key[q] = x;
    }
    return argsort(key);
  }

  template <typename F1, typename F2, typename F3, typename F4, typename F5,
            typename F6, typename F7>
  void calc(F1 ADD_L, F2 ADD_R, F3 RM_L, F4 RM_R, F5 ADD_T, F6 RM_T, F7 CALC,
            ll block_sz = -1) {
    if (block_sz == -1) {
      ll Q = max(1LL, len(query));
      while (block_sz * block_sz * block_sz < Q * Q) { block_sz++; }
    }
    auto I = get_mo_order(block_sz);
    ll t = -1, l = 0, r = 0;
    for (auto&& qid: I) {
      auto [nt, nl, nr] = query[qid];
      while (l > nl) ADD_L(--l);
      while (r < nr) ADD_R(r++);
      while (l < nl) RM_L(l++);
      while (r > nr) RM_R(--r);
      while (t < nt) ADD_T(change[++t], l, r);
      while (t > nt) RM_T(change[t--], l, r);
      CALC(qid);
    }
  }
};