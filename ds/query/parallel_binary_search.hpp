/*
並列二分探索。(Q, ok, ng, init, upd, check)。
check が成り立つぎりぎりの upd回数を返す。
・void upd(t)：t 回目の update
・bool check(q)：クエリ q の判定
*/
template <typename F1, typename F2, typename F3>
vc<int> parallel_binary_search(int Q, int ok, int ng, F1 init, F2 upd,
                               F3 check) {
  int T = max(ok, ng);
  vc<int> OK(Q, ok), NG(Q, ng);
  while (1) {
    vc<int> check_t(Q, -1);
    FOR(q, Q) {
      int& t = check_t[q];
      if (abs(OK[q] - NG[q]) > 1) { t = (OK[q] + NG[q]) / 2; }
    }
    vc<int> indptr(T + 1);
    FOR(q, Q) {
      int& t = check_t[q];
      if (t != -1) indptr[t + 1]++;
    }
    FOR(t, T) indptr[t + 1] += indptr[t];
    int total = indptr.back();
    if (total == 0) break;
    auto counter = indptr;
    vc<int> csr(total);
    FOR(q, Q) {
      int& t = check_t[q];
      if (t != -1) { csr[counter[t]++] = q; }
    }

    init();
    int t = 0;
    for (auto&& q: csr) {
      while (t < check_t[q]) { upd(t++); }
      if (check(q))
        OK[q] = t;
      else
        NG[q] = t;
    }
  }
  return OK;
}