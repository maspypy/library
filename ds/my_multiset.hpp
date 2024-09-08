
#include "ds/segtree/dynamic_segtree_sparse.hpp"

// key,cnt は long long, sum は i128
struct My_Multiset {
  struct Mono {
    using value_type = pair<ll, i128>; // cnt, sum
    using X = value_type;
    static X op(X x, X y) { return {x.fi + y.fi, x.se + y.se}; }
    static constexpr X unit() { return {0, 0}; }
    static constexpr bool commute = 1;
  };
  Dynamic_SegTree_Sparse<Mono, false> seg;
  using np = typename decltype(seg)::np;

  My_Multiset(int NODES) : seg(NODES, -infty<ll>, infty<ll>) {}

  void reset() { seg.reset(); }
  np new_root() { return seg.new_root(); }
  np add(np c, ll k, ll cnt = 1) { return seg.multiply(c, k, {cnt, i128(k) * cnt}); }

  pair<ll, i128> get_range(np c, ll L, ll R) { return seg.prod(c, L, R); }
  pair<ll, i128> get_all(np c) { return seg.prod_all(c); }

  // (k-th val or infty), sum
  pair<ll, i128> prefix_kth(np c, ll k) {
    auto [cnt, sm] = seg.prod_all(c);
    assert(k <= cnt);
    if (k == cnt) return {infty<ll>, sm};
    ll key = seg.max_right(
        c, [&](auto e) -> bool { return e.fi <= k; }, -infty<ll>);
    tie(cnt, sm) = seg.prod(c, -infty<ll>, key);
    return {key, sm + key * (k - cnt)};
  }

  // (k-th val or -infty), sum
  pair<ll, i128> suffix_kth(np c, ll k) {
    auto [cnt, sm] = seg.prod_all(c);
    assert(k <= cnt);
    if (k == cnt) return {-infty<ll>, sm};
    auto [a, b] = prefix_kth(c, cnt - 1 - k);
    return {a, sm - b - a};
  }
};