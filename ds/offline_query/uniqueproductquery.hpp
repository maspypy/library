#include "ds/segtree/segtree.hpp"

// [L, R) 内の要素 (long long)を UNIQUE した上で、f(x)の総積をとったものを計算。
// クエリ先読みソート＋セグ木
// クエリを全部 add(L,R) する
// calc(f) として呼ぶ
template <typename Mono>
struct UniqueProductQuery {
  using X = typename Mono::value_type;
  int N;
  vc<ll> key;
  vc<pair<int, int>> query;

  UniqueProductQuery(vc<ll>& key) : N(len(key)), key(key) {}

  void add(int L, int R) {
    assert(0 <= L && L <= R && R <= N);
    query.eb(L, R);
  }

  template <typename F>
  vc<X> calc(F f) {
    ll Q = len(query);
    vc<X> ANS(Q);
    vc<vc<int>> IDS(N + 1);
    FOR(q, Q) IDS[query[q].se].eb(q);
    SegTree<Mono> seg(N);

    unordered_map<ll, int> pos;
    pos.reserve(N);

    FOR(i, N) {
      ll x = key[i];
      if (pos.count(x)) { seg.set(pos[x], Mono::unit()); }
      pos[x] = i;
      seg.set(i, f(key[i]));
      for (auto&& q: IDS[i + 1]) {
        auto [L, R] = query[q];
        ANS[q] = seg.prod(L, R);
      }
    }
    return ANS;
  }

  vc<X> calc() {
    auto f = [&](ll k) -> X { return 1; };
    return calc(f);
  }
};
