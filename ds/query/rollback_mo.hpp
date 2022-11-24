// https://codeforces.com/contest/620/problem/F
struct Rollback_Mo {
  vc<pair<int, int>> LR;
  void add(int L, int R) { LR.emplace_back(L, R); }

  template <typename AL, typename AR, typename F1, typename F2, typename F3,
            typename O>
  void calc(AL add_left, AR add_right, F1 reset, F2 save, F3 rollback,
            O query) {
    const int Q = len(LR);
    if (Q == 0) return;
    int N = 0;
    for (auto &&[L, R]: LR) chmax(N, R);
    const int b_num = sqrt(Q);
    const int b_sz = ceil(N, b_num);
    vvc<int> QID((N - 1) / b_sz + 1);
    // 左端の属するブロックで分類
    // 左端と右端が同じブロックに属するものは、先に処理してしまう。
    auto naive = [&](int qid) -> void {
      save();
      auto [L, R] = LR[qid];
      FOR(i, L, R) add_right(i);
      query(qid);
      rollback();
    };

    FOR(qid, Q) {
      auto [L, R] = LR[qid];
      int iL = L / b_sz, iR = R / b_sz;
      if (iL == iR) {
        naive(qid);
        continue;
      }
      QID[iL].eb(qid);
    }

    FOR(iL, len(QID)) {
      auto &I = QID[iL];
      if (I.empty()) continue;
      sort(all(I),
           [&](auto &a, auto &b) -> bool { return LR[a].se < LR[b].se; });
      int LMAX = 0;
      for (auto &&qid: I) {
        auto [L, R] = LR[qid];
        chmax(LMAX, L);
      }
      reset();
      int l = LMAX, r = LMAX;
      for (auto &&qid: I) {
        auto [L, R] = LR[qid];
        while (r < R) add_right(r++);
        save();
        while (L < l) add_left(--l);
        query(qid);
        rollback();
        l = LMAX;
      }
    }
  }
};