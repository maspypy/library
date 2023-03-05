#include "nt/factor.hpp"
#include "nt/lpf_table.hpp"

template <typename mint>
mint all_lcm(vc<int> A, bool use_lpf) {
  if (A.empty()) return 1;
  map<int, int> MP;
  int mx = MAX(A);
  vc<int> lpf;
  if (use_lpf) lpf = lpf_table(mx);
  for (auto&& n: A) {
    auto pfs = (use_lpf ? factor_by_lpf(n, lpf) : factor(n));
    for (auto&& [p, e]: pfs) chmax(MP[p], e);
  }
  mint x = 1;
  for (auto&& [p, e]: MP) { x *= mint(p).pow(e); }
  return x;
}
