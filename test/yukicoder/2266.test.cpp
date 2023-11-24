#define PROBLEM "https://yukicoder.me/problems/no/2266"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/range_rational_count.hpp"

void solve() {
  u64 N, K;
  read(N, K);

  auto out = [&](u32 a, u32 b) -> void {
    string s = to_string(a) + "/" + to_string(b);
    print(s);
  };

  Range_Rational_Count X(N);
  u64 t = X.total;
  if (K < t) {
    auto [a, b] = X.kth(K);
    out(a, b);
  }
  elif (K == t) { out(1, 1); }
  elif (K < 2 * t) {
    auto [a, b] = X.kth(2 * t - K);
    out(b, a);
  }
  else {
    print(-1);
  }
}

signed main() {
  solve();
  return 0;
}
