#include "alg/acted_set/from_monoid.hpp"
#include "ds/hashmap.hpp"

// 群 X の作用する集合 S、ハッシュ関数 H：S -> Z
// x in G, s, t in S に対して x^ns = t を解く
// [lb, ub) の最初の解をかえす。なければ -1 をかえす。
template <typename ActedSet, typename F, int MP_SIZE = 20>
ll discrete_log_acted(typename ActedSet::A x, typename ActedSet::S s,
                      typename ActedSet::S t, F H, ll lb, ll ub) {
  static HashMapLL<int, MP_SIZE> MP;
  MP.reset();
  using Group = typename ActedSet::Monoid_A;
  using G = typename Group::value_type;
  if (lb >= ub) return -1;
  auto xpow = [&](ll n) -> G {
    G p = x;
    G res = Group::unit();
    while (n) {
      if (n & 1) res = Group::op(res, p);
      p = Group::op(p, p);
      n /= 2;
    }
    return res;
  };
  s = ActedSet::act(s, xpow(lb));
  u64 LIM = ub - lb;

  ll K = sqrt(LIM) + 1;

  FOR(k, K + 1) {
    ll key = H(s);
    if (!MP.count(key)) MP[key] = k;
    if (k != K) s = ActedSet::act(s, x);
  }

  x = Group::inverse(xpow(K));
  FOR(k, K + 1) {
    ll key = H(t);
    if (MP.count(key)) {
      ll res = k * K + MP[key] + lb;
      return (res >= ub ? -1 : res);
    }
    t = ActedSet::act(t, x);
  }
  return -1;
}

// 群 X における log_a b の計算
// ハッシュ関数 H : X -> long long を持たせる
// [lb, ub) の最初の解をかえす、なければ -1
template <typename Group, typename F>
ll discrete_log_group(typename Group::X a, typename Group::X b, F H, ll lb,
                      ll ub) {
  using AM = ActedSet_From_Monoid<Group>;
  return discrete_log_acted<AM>(a, Group::unit(), b, H, lb, ub);
}