
// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j
template <typename T, bool MINIMIZE>
struct Non_Adjacent_Selection {
  int N;
  vc<T> ANS;
  vc<pair<int, int>> history;

  Non_Adjacent_Selection(vc<T>& A) { calc(A); }

  void calc(vc<T> A) {
    if (MINIMIZE) {
      for (auto& x: A) x = -x;
    }
    N = len(A);
    vc<bool> rest(N + 2, 1);
    rest[0] = rest[N + 1] = 0;
    vc<pair<int, int>> range(N + 2);
    vc<int> left(N + 2), right(N + 2);
    vc<T> val(N + 2);
    pq<pair<T, int>> que;
    FOR(i, N + 2) { left[i] = i - 1, right[i] = i + 1; }
    FOR(i, N) {
      val[i + 1] = A[i], range[i + 1] = {i, i + 1};
      que.emplace(val[i + 1], i + 1);
    }

    ANS = {0};
    while (len(que)) {
      auto [add, i] = POP(que);
      if (!rest[i]) continue;
      ANS.eb(ANS.back() + add);
      int L = left[i], R = right[i];
      history.eb(range[i]);
      if (1 <= L) { right[left[L]] = i, left[i] = left[L]; }
      if (R <= N) { left[right[R]] = i, right[i] = right[R]; }
      if (rest[L] && rest[R]) {
        val[i] = val[L] + val[R] - val[i];
        que.emplace(val[i], i);
        range[i] = {range[L].fi, range[R].se};
      } else {
        rest[i] = 0;
      }
      rest[L] = rest[R] = 0;
    }

    if (MINIMIZE) {
      for (auto& x: ANS) x = -x;
    }
  }

  vc<int> restore(int n) {
    vc<int> F(N + 1);
    FOR(i, n) {
      auto [a, b] = history[i];
      F[a]++, F[b]--;
    }
    F = cumsum<int>(F, 0);
    vc<int> I;
    FOR(i, N) if (F[i] & 1) I.eb(i);
    return I;
  }
};