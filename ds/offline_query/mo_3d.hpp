// https://codeforces.com/contest/940/problem/F
// https://codeforces.com/contest/1476/problem/G
struct Mo_3d {
  vc<tuple<int, int, int>> query;

  void add_query(int t, int l, int r) { query.eb(t, l, r); }

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
    vc<int> I = argsort(key);

    // ランダムケースで5パーセント程度
    auto cost = [&](int a, int b) -> int {
      auto [t1, x1, y1] = query[I[a]];
      auto [t2, x2, y2] = query[I[b]];
      return abs(t1 - t2) + abs(x1 - x2) + abs(y1 - y2);
    };
    FOR(k, Q - 5) {
      if (cost(k, k + 2) + cost(k + 1, k + 3)
          < cost(k, k + 1) + cost(k + 2, k + 3)) {
        swap(I[k + 1], I[k + 2]);
      }
      if (cost(k, k + 3) + cost(k + 1, k + 4)
          < cost(k, k + 1) + cost(k + 3, k + 4)) {
        swap(I[k + 1], I[k + 3]);
      }
    }
    return I;
  }

  template <typename F1, typename F2, typename F3, typename F4, typename F5,
            typename F6, typename F7>
  void calc(F1 ADD_L, F2 ADD_R, F3 RM_L, F4 RM_R, F5 ADD_CHANGE, F6 RM_CHANGE,
            F7 CALC, ll block_sz = -1) {
    if (block_sz == -1) {
      ll Q = max(1LL, len(query));
      while (block_sz * block_sz * block_sz < Q * Q) { block_sz++; }
    }
    auto I = get_mo_order(block_sz);
    ll t = 0, l = 0, r = 0;
    for (auto&& qid: I) {
      auto [nt, nl, nr] = query[qid];
      while (l > nl) ADD_L(--l);
      while (r < nr) ADD_R(r++);
      while (l < nl) RM_L(l++);
      while (r > nr) RM_R(--r);
      while (t < nt) ADD_CHANGE(t++, l, r);
      while (t > nt) RM_CHANGE(--t, l, r);
      CALC(qid);
    }
  }
};