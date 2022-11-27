// A：定数
// Sparse Laurent Polynomial f(x) を与える
// [x^p] f(x)/(1-x)^A をたくさん求める
// O(AN) 時間
template <int A, typename T>
struct Coefficient_Query_2D {
  vc<tuple<ll, T>> F;
  vc<ll> QUERY;

  Coefficient_Query_2D() {}
  void add(ll x, T c) { F.eb(x, c); }
  void query(ll p) { QUERY.eb(p); }

  vc<T> calc() {
    // x 昇順にクエリ処理する
    const int Q = len(QUERY);
    vc<int> I(Q);
    iota(all(I), 0);
    sort(all(I), [&](auto& a, auto& b) -> bool { return QUERY[a] < QUERY[b]; });
    sort(all(F), [&](auto& a, auto& b) -> bool { return a.se < b.se; });

    array<T, A> dat{};
    vc<T> res(Q);
    int ptr = 0;
    for (auto&& qid: I) {
      auto p = QUERY[qid];
      // x <= p となる F の加算
      while (ptr < len(F) && F[ptr].fi <= p) {
        auto& [a, w] = F[ptr++];
        // c(p-i+1)...(p-i+A-1)
        vc<T> f(A);
        f[0] = w;
        FOR(i, A - 1) { FOR_R(j, i + 1) f[j + 1] += f[j] * T(-a + 1 + i); }
        reverse(all(f));
        FOR(i, len(f)) dat[i] += f[i];
      }
      T sm = 0;
      T pow_p = 1;
      FOR(i, A) {
        sm += pow_p * dat[i];
        pow_p *= T(p);
      }
      res[qid] = sm;
    }
    return res;
  }
};