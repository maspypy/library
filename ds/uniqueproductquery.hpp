#include "alg/group_add.hpp"
#include "ds/segtree.hpp"
#include "pds/segtree.hpp"

// sample：https://codeforces.com/contest/703/problem/D
// [L, R) 内の要素 (long long)を UNIQUE した上で、f(x) の総積をとったものを計算。
// クエリ先読みソート＋セグ木
// ・クエリを全部 add(L, R) する
// ・calc(f) として呼ぶ
template <typename Mono=Group_Add<int>>
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
      if (pos.count(x)) {
        seg.set(pos[x], Mono::unit);
      }
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



// sample：https://codeforces.com/contest/703/problem/D
// key = long long
// [L, R) 内の要素 (long long) を UNIQUE した上で、
// f(k),の総積をとったものを計算。 f: key -> Monoid value
// Online 化したものの、メモリ定数倍が重い
template <typename Monoid = Group_Add<int>>
struct OnlineUniqueProductQuery {
  using X = typename Monoid::value_type;
  int N;
  vc<ll> key;
  vc<pair<int, int>> query;
  vc<int> times;
  PersistentSegTree<Monoid> seg;

  template <typename F>
  OnlineUniqueProductQuery(vc<ll>& key, F f) : N(len(key)), key(key), seg(N) {
    times.eb(seg.time());
    unordered_map<ll, int> pos;
    pos.reserve(N);
    FOR(i, N) {
      ll x = key[i];
      int t = seg.time();
      if (pos.count(x)) { t = seg.set(t, pos[x], Monoid::unit); }
      pos[x] = i;
      t = seg.set(t, i, f(key[i]));
      times.eb(t);
    }
  }
  
  X prod(int L, int R) {
    int t = times[R];
    return seg.prod(t, L, R);
  }
};
