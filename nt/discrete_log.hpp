#include "alg/acted_set/from_monoid.hpp"
#include "ds/hashmap.hpp"

// モノイド X の作用する集合 S、ハッシュ関数 H：S -> Z
// x in X, s, t in S に対して x^ns = t を解く
// [lb, ub) の最初の解をかえす。なければ -1 をかえす。
template <typename ActedSet, typename F, int MP_SIZE = 20>
ll discrete_log_acted(typename ActedSet::A x, typename ActedSet::S s,
                      typename ActedSet::S t, F H, ll lb, ll ub) {
  static HashMap<bool, MP_SIZE> MP;
  MP.reset();
  using Mono = typename ActedSet::Monoid_A;
  using X = typename Mono::value_type;
  using S = typename ActedSet::S;

  if (lb >= ub) return -1;
  auto xpow = [&](ll n) -> X {
    X p = x;
    X res = Mono::unit();
    while (n) {
      if (n & 1) res = Mono::op(res, p);
      p = Mono::op(p, p);
      n /= 2;
    }
    return res;
  };

  auto Ht = H(t);
  s = ActedSet::act(s, xpow(lb));
  u64 LIM = ub - lb;

  ll K = sqrt(LIM) + 1;

  FOR(k, K) {
    t = ActedSet::act(t, x);
    MP[H(t)] = 1;
  }

  X y = xpow(K);
  int failed = 0;
  FOR(k, K + 1) {
    S s1 = ActedSet::act(s, y);
    if (MP.count(H(s1))) {
      FOR(i, K) {
        if (H(s) == Ht) {
          ll ans = k * K + i + lb;
          return (ans >= ub ? -1 : ans);
        }
        s = ActedSet::act(s, x);
      }
      if (failed) return -1;
      failed = 1;
    }
    s = s1;
  }
  return -1;
}

// 群 X における log_a b の計算
// ハッシュ関数 H : X -> long long を持たせる
// [lb, ub) の最初の解をかえす、なければ -1
template <typename Monoid, typename F>
ll discrete_log_monoid(typename Monoid::X a, typename Monoid::X b, F H, ll lb,
                       ll ub) {
  using AM = ActedSet_From_Monoid<Monoid>;
  return discrete_log_acted<AM>(a, Monoid::unit(), b, H, lb, ub);
}