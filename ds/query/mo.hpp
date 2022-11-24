struct Mo {
  vc<pair<int, int>> LR;
  void add(int L, int R) { LR.emplace_back(L, R); }

  template <typename AL, typename AR, typename EL, typename ER, typename O>
  void calc(const AL &add_left, const AR &add_right, const EL &erase_left,
            const ER &erase_right, const O &query) {
    int n = 1;
    for (auto &&[l, r]: lr) chmax(n, r);
    int q = (int)lr.size();
    int bs = n / min<int>(n, sqrt(q));
    vector<int> ord(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) {
      int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
      if (ablock != bblock) return ablock < bblock;
      return (ablock & 1) ? lr[a].second > lr[b].second
                          : lr[a].second < lr[b].second;
    });
    int l = 0, r = 0;
    for (auto idx: ord) {
      while (l > lr[idx].first) add_left(--l);
      while (r < lr[idx].second) add_right(r++);
      while (l < lr[idx].first) erase_left(l++);
      while (r > lr[idx].second) erase_right(--r);
      query(idx);
    }
  }

  template <typename A, typename E, typename O>
  void calc(const A &add, const E &erase, const O &query) {
    calc(add, add, erase, erase, query);
  }
};
