#include "nt/array_on_floor.hpp"
#include "nt/mobius_table.hpp"
#include "enumerate/floor_range.hpp"

template <typename T>
struct Mertens {
  Array_On_Floor<T> sum;
  Mertens() {}
  Mertens(u64 N, u64 K = -1) { build(N, K); }
  void build(u64 N, u64 K = -1) {
    sum = Array_On_Floor<T>(N);
    if (K == u64(-1)) { K = pow(N, 0.67); }
    vc<T> A = mobius_table<T>(K);
    FOR(k, 1, K) A[k + 1] += A[k];
    FOR(i, len(sum)) {
      u64 n = sum.get_floor(i);
      if (n <= K) {
        sum.dat[i] = A[n];
        continue;
      }
      T ans = 1;
      floor_range(n, [&](u64 q, u64 l, u64 r) -> void {
        if (q == n) return;
        ans -= sum[q] * T(r - l);
      });
      sum.dat[i] = ans;
    }
  }
  T operator[](u64 n) { return sum[n]; }
};
