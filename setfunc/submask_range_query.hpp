#include "random/shuffle.hpp"
#include "alg/monoid/add.hpp"
#include "alg/monoid/xor.hpp"

// O((4/3)^LOG) per query
template <typename Monoid>
struct SubMask_Range_Query {
  using MX = Monoid;
  using X = typename MX::value_type;
  const int LOG;
  vc<X> S;
  array<u32, 3> mask;
  /*
  0: [x0,x1] -> [x0,x1] -> [x0,x0+x1]
  1: [x0,x1] -> [x0+x1,x0] -> [x0,x0+x1]
  2: [x0,x1] -> [x0+x1,x1] -> [x0,x0+x1]
  */

  SubMask_Range_Query(int LOG) : LOG(LOG), mask{} {
    S.assign(1 << LOG, MX::unit());
    init_by_random();
  }

  void init_by_random() {
    FOR(i, LOG) { mask[RNG(0, 3)] |= 1 << i; }
  }

  void init_by_query(vc<u32>& ADD, vc<u32>& GET) {
    mask[0] = mask[1] = mask[2] = 0;
    auto eval = [&]() -> ll {
      ll ans = 0;
      for (u32 x : ADD) {
        u32 s = 0;
        s ^= (~x) & mask[1];
        s ^= x & mask[2];
        ans += 1 << popcnt(s);
      }
      for (auto& x : GET) {
        u32 s = 0;
        s ^= x & mask[0];
        s ^= (~x) & mask[2];
        ans += 1 << popcnt(s);
      }
      return ans;
    };
    vc<int> I(LOG);
    FOR(i, LOG) I[i] = i;
    shuffle(I);
    array<ll, 3> c;
    for (int i : I) {
      FOR(k, 3) { mask[k] |= 1 << i, c[k] = eval(), mask[k] &= ~(1 << i); }
      int k = min_element(all(c)) - c.begin();
      mask[k] |= 1 << i;
    }
  }

  void add(u32 i, X x) {
    u32 base = i & mask[0];
    u32 s = ((~i) & mask[1]) | (i & mask[2]);
    for (u32 t : all_subset<u32>(s)) {
      S[base | t] = MX::op(S[base | t], x);
    }
  }

  X get_sum(u32 i) {
    u32 base = (~i) & mask[1];
    u32 s = (i & mask[0]) | ((~i) & mask[2]);
    if constexpr (is_same_v<Monoid_Add<X>, MX>) {
      X ANS = 0;
      for (u32 t : all_subset<u32>(s)) {
        ANS += S[base | t] * popcnt_sgn(t & mask[2]);
      }
      return ANS;
    } else if constexpr (is_same_v<Monoid_Xor<X>, MX>) {
      X ANS = 0;
      for (u32 t : all_subset<u32>(s)) {
        ANS ^= S[base | t];
      }
      return ANS;
    } else {
      X a[] = {MX::unit(), MX::unit()};
      for (u32 t : all_subset<u32>(s)) {
        int k = __builtin_parity(t & mask[2]);
        a[k] = MX::op(a[k], S[base | t]);
      }
      return MX::op(a[0], MX::inverse(a[1]));
    }
  }
};
