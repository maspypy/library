#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/suffix_array.hpp"

void solve() {
  STR(S);
  auto A = s_to_vi(S, 'a');
  Suffix_Array sa(S);
  print(sa.SA);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
