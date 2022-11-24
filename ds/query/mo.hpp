struct Mo {
  vc<pair<int, int>> LR;
  void add(int L, int R) { LR.emplace_back(L, R); }

  template <typename AL, typename AR, typename EL, typename ER, typename O>
  void calc(const AL &add_left, const AR &add_right, const EL &erase_left,
            const ER &erase_right, const O &query) {
    int n = 1;
    for (auto &&[l, r]: LR) chmax(n, r);
    int q = (int)LR.size();
    int bs = n / min<int>(n, sqrt(q));
    vector<int> ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = LR[a].first / bs, bblock = LR[b].first / bs;
      if (ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? LR[a].second > LR[b].second
                          : LR[a].second < LR[b].second;
    });
    int l = 0, r = 0;
    for (auto idx: ord) {
      while (l > LR[idx].first) add_left(--l);
      while (r < LR[idx].second) add_right(r++);
      while (l < LR[idx].first) erase_left(l++);
      while (r > LR[idx].second) erase_right(--r);
      query(idx);
    }
  }

  template <typename A, typename E, typename O>
  void calc(const A &add, const E &erase, const O &query) {
    calc(add, add, erase, erase, query);
  }
};
