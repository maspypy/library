#define PROBLEM "https://yukicoder.me/problems/no/1292"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashset.hpp"

void solve() {
  HashSetLL<18> MP;
  STR(S);
  ll A = 0;
  ll B = 1;
  ll C = 1LL << 20;

  MP.insert(A + B + C);
  for (auto&& x: S) {
    if (x == 'a') { A = -A + B + C; }
    if (x == 'b') { B = -B + C + A; }
    if (x == 'c') { C = -C + A + B; }
    MP.insert(A + B + C);
  }
  print(len(MP));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
