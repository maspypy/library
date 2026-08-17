#include "random/shuffle.hpp"
#include "alg/monoid/add.hpp"
#include "alg/monoid/xor.hpp"
#include "enumerate/bits.hpp"

// O((4/3)^LOG) per query
template <typename Monoid>
struct Boolean_Range_Add_Point_Get {
  using MX = Monoid;
  using X = typename MX::value_type;

  const int LOG;
  vc<X> S;
  array<u32, 3> mask;

  /*
  0: [x0,x1]
  1: [x0+x1,x0]
  2: [x0+x1,x1]
  */

  Boolean_Range_Add_Point_Get(int LOG) : LOG(LOG), mask{} {
    S.assign(1 << LOG, MX::unit());
    init_by_random();
  }

  void init_by_random() {
    mask[0] = mask[1] = mask[2] = 0;
    FOR(i, LOG) { mask[RNG(0, 3)] |= u32(1) << i; }
  }

  void init_by_query(const vc<pair<u32, u32>>& ADD, const vc<u32>& GET) {
    for (auto& [lo, hi] : ADD) assert((lo & ~hi) == 0);
    mask[0] = mask[1] = mask[2] = 0;

    auto eval = [&]() -> ll {
      ll ans = 0;

      for (auto& [lo, hi] : ADD) {
        u32 s = 0;
        s ^= (lo ^ hi) & mask[0];
        s ^= lo & mask[1];
        s ^= (~hi) & mask[2];
        ans += 1 << popcnt(s);
      }

      for (u32 i : GET) {
        u32 s = 0;
        s ^= (~i) & mask[1];
        s ^= i & mask[2];
        ans += 1 << popcnt(s);
      }

      return ans;
    };

    vc<int> I(LOG);
    FOR(i, LOG) I[i] = i;
    shuffle(I);

    array<ll, 3> c;
    for (int i : I) {
      FOR(k, 3) {
        mask[k] |= u32(1) << i, c[k] = eval(), mask[k] &= ~(u32(1) << i);
      }
      int k = min_element(all(c)) - c.begin();
      mask[k] |= u32(1) << i;
    }
  }

  void add(u32 lo, u32 hi, X x) {
    assert((lo & ~hi) == 0);

    u32 a = 0;
    u32 s = 0;
    u32 b = 0;

    a ^= lo & mask[0];
    s ^= (lo ^ hi) & mask[0];

    a ^= (~hi) & mask[1];
    s ^= lo & mask[1];
    b ^= lo & mask[1];

    a ^= lo & mask[2];
    s ^= (~hi) & mask[2];
    b ^= (~hi) & mask[2];

    enumerate_all_subset<u32, true>(s, [&](u32 t) -> void {
      X y = (__builtin_parity(t & b) ? MX::inverse(x) : x);
      S[a | t] = MX::op(S[a | t], y);
    });
  }

  X get(u32 i) {
    u32 a = i & mask[0];
    u32 s = 0;

    s ^= (~i) & mask[1];
    s ^= i & mask[2];

    X ANS = MX::unit();
    enumerate_all_subset<u32, true>(
        s, [&](u32 t) -> void { ANS = MX::op(ANS, S[a | t]); });
    return ANS;
  }
};