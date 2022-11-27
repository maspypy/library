#include "ds/hashmap.hpp"
// log_a b の計算
// ハッシュ関数 H : X -> long long を持たせる
// [lb, ub) の最初の解をかえす
// なければ -1
template <typename Group>
ll discrete_log(typename Group::X a, typename Group::X b,
                function<ll(typename Group::X)> H, ll lb, ll ub) {
  using G = typename Group::X;
  if (lb >= ub) return -1;
  {
    ll n = lb;
    G p = a;
    G x = Group::unit();
    while (n) {
      if (n & 1) x = Group::op(x, p);
      p = Group::op(p, p);
      n /= 2;
    }
    x = Group::inverse(x);
    b = Group::op(b, x);
  }
  ll LIM = ub - lb;

  ll K = 1;
  while (K * K < LIM) ++K;

  static HashMapLL<int, 20> MP;
  MP.reset();

  G p = Group::unit();
  FOR(k, K + 1) {
    auto key = H(p);
    if (!MP.count(key)) MP[key] = k;
    if (k != K) p = Group::op(p, a);
  }
  p = Group::inverse(p);
  FOR(k, K + 1) {
    auto key = H(b);
    if (MP.count(key)) {
      ll res = k * K + MP[key] + lb;
      return (res >= ub ? -1 : res);
    }
    b = Group::op(b, p);
  }
  return -1;
}

// yuki1648
// G 集合 X がある。
// a in G, x, y in X に対して a^nx=y を解く
// ハッシュ関数 H : X -> long long を持たせる
// [lb, ub) の最初の解をかえす
// なければ -1
template <typename GSet>
ll discrete_log_gset(typename GSet::X a, typename GSet::S x, typename GSet::S y,
                     function<ll(typename GSet::S)> H, ll lb, ll ub) {
  using Group = typename GSet::Monoid;
  using G = typename Group::value_type;
  if (lb >= ub) return -1;
  auto apow = [&](ll n) -> G {
    G p = a;
    G res = Group::unit();
    while (n) {
      if (n & 1) res = Group::op(res, p);
      p = Group::op(p, p);
      n /= 2;
    }
    return res;
  };
  x = GSet::act(x, apow(lb));
  ll LIM = ub - lb;

  ll K = 1;
  while (K * K < LIM) ++K;

  static HashMapLL<int, 20> MP;
  MP.reset();

  FOR(k, K + 1) {
    auto key = H(x);
    if (!MP.count(key)) MP[key] = k;
    if (k != K) x = GSet::act(x, a);
  }

  a = Group::inverse(apow(K));
  FOR(k, K + 1) {
    auto key = H(y);
    if (MP.count(key)) {
      ll res = k * K + MP[key] + lb;
      return (res >= ub ? -1 : res);
    }
    y = GSet::act(y, a);
  }
  return -1;
}