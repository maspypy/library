
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

template <typename UINT>
struct all_k_subset {
  static_assert(is_unsigned<UINT>::value);
  struct iter {
    const UINT n, k, s;
    UINT t;
    iter(UINT s, UINT k) : n(UINT(1) << popcnt(s)), k(k), s(s), t((UINT(1) << k) - 1) {}
    __attribute__((target("bmi2"))) auto operator*() const { return _pdep_u64(t, s); }
    auto operator++() {
      if (k == 0) {
        t = UINT(-1);
      } else {
        UINT y = t + (-t & t);
        t = y | ((y ^ t) >> lowbit(t << 2));
      }
    }
    auto operator!=(const iter) const { return t < n; }
  };
  UINT s, k;
  all_k_subset(UINT s, UINT k) : s(s), k(k) { assert(s != UINT(-1)); }
  auto begin() { return iter(s, k); }
  auto end() { return iter(0, 0); }
};

// all_nCk関数の実装
auto all_nCk(int n, int k) { return all_k_subset<u32>((u32(1) << n) - 1, k); }