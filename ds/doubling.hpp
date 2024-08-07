#include "alg/monoid/add.hpp"

// 状態 a から 1 回操作すると、状態 b に遷移し、モノイドの元 x を加える。
// 行き先がない場合：-1 （add 不要）
template <typename Monoid, int LOG>
struct Doubling {
  using X = typename Monoid::value_type;
  int N;
  bool is_prepared;
  vvc<int> TO;
  vvc<X> DP;

  Doubling(int N) : N(N), is_prepared(0) {
    TO.assign(LOG, vc<int>(N, -1));
    DP.assign(LOG, vc<X>(N, Monoid::unit()));
  }

  void add(int i, int to, X x) {
    assert(!is_prepared);
    assert(-1 <= to && to < N);
    TO[0][i] = to;
    DP[0][i] = x;
  }

  void build() {
    assert(!is_prepared);
    is_prepared = 1;
    FOR(k, LOG - 1) {
      FOR(v, N) {
        int w = TO[k][v];
        if (w == -1) {
          TO[k + 1][v] = -1;
          DP[k + 1][v] = DP[k][v];
          continue;
        }
        TO[k + 1][v] = TO[k][w];
        DP[k + 1][v] = Monoid::op(DP[k][v], DP[k][w]);
      }
    }
  }

  // (to, val)
  pair<int, X> calc(int i, ll step) {
    assert(is_prepared);
    assert(0 <= step && step < (1LL << LOG));
    X x = Monoid::unit();
    while (step && i != -1) {
      int k = topbit(step);
      step ^= 1LL << k;
      x = Monoid::op(x, DP[k][i]);
      i = TO[k][i];
    }
    return {i, x};
  }

  // check(to, monoid_sum)
  template <typename F>
  ll max_step(F check, int i) {
    assert(is_prepared);
    X x = Monoid::unit();
    ll step = 0;
    assert(check(i, x));
    FOR_R(k, LOG) {
      int j = TO[k][i];
      if (j == -1) continue;
      X y = Monoid::op(x, DP[k][i]);
      if (check(j, y)) {
        step |= 1LL << k;
        i = j;
        x = y;
        assert(i != -1);
      }
    }
    return step;
  }

  void debug() {
    print("TO");
    FOR(k, LOG) print(TO[k]);
    print("DP");
    FOR(k, LOG) print(DP[k]);
  }
};
