
// グループ 1 にとって最適な stable matching が存在するのでそれをかえす.
// O((N+M)logM)
struct Stable_Matching {
  int N1, N2;
  vvc<tuple<int, int, int>> dat;
  vc<int> match_1, match_2;
  vc<int> val_1, val_2;

  Stable_Matching(int N1, int N2) : N1(N1), N2(N2), dat(N1) {}

  // x は価値, 大きい方が優先される
  void add(int v1, int v2, int x1, int x2) { dat[v1].eb(v2, x1, x2); }

  vc<pair<int, int>> calc() {
    FOR(v1, N1) {
      sort(all(dat[v1]),
           [&](auto& a, auto& b) -> bool { return get<1>(a) < get<1>(b); });
    }
    match_1.assign(N1, -1), match_2.assign(N2, -1);
    val_1.assign(N1, -infty<int>), val_2.assign(N2, -infty<int>);
    vc<int> que(N1);
    FOR(v, N1) que[v] = v;
    while (len(que)) {
      auto v1 = POP(que);
      match_1[v1] = -1, val_1[v1] = -infty<int>;
      if (dat[v1].empty()) continue;
      auto [v2, x1, x2] = POP(dat[v1]);
      if (!chmax(val_2[v2], x2)) {
        que.eb(v1);
        continue;
      }
      if (match_2[v2] != -1) que.eb(match_2[v2]);
      match_1[v1] = v2, match_2[v2] = v1, val_1[v1] = x1, val_2[v2] = x2;
    }
    vc<pair<int, int>> match;
    FOR(v1, N1) {
      int v2 = match_1[v1];
      if (v2 != -1) match.eb(v1, v2);
    }
    return match;
  }
};