#include "nt/factor.hpp"
#include "nt/spf_table.hpp"

template <typename mint>
mint all_lcm(vc<int> A, bool use_spf) {
  if (A.empty()) return 1;
  map<int, int> MP;
  int mx = MAX(A);
  vc<int> spf;
  if (use_spf) spf = spf_table(mx);
  for (auto&& n: A) {
    auto pfs = (use_spf ? factor_by_spf(n, spf) : factor(n));
    for (auto&& [p, e]: pfs) chmax(MP[p], e);
  }
  mint x = 1;
  for (auto&& [p, e]: MP) { x *= mint(p).pow(e); }
  return x;
}
