#include "ds/hashmap.hpp"
// log_a b の計算
// ハッシュ関数 H : X -> long long を持たせる
// [lb, rb) の最初の解をかえす
// なければ -1
template <typename Group, typename X>
ll discrete_log(typename Group::X a, typename Group::X b,
                function<ll(typename Group::X)> H, ll lb, ll ub) {
  using X = typename Group::X;
  if (lb >= ub) return -1;
  {
    ll n = lb;
    X p = a;
    X x = Group::unit();
    while (n) {
      if (n & 1) x = Group::op(x, a);
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

  X p = Group::unit();
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