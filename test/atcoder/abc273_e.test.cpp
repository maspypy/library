#define PROBLEM "https://atcoder.jp/contests/abc273/tasks/abc273_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/persistent_array.hpp"

void solve() {
  PersistentArray<int> PA;
  using np = PersistentArray<int>::np;

  map<int, np> MP;
  map<int, int> sz;

  LL(Q);
  vi ANS;

  np now = PA.get_root();
  int now_sz = 0;

  FOR(Q) {
    STR(S);
    if (S == "ADD") {
      INT(x);
      now = PA.set(now, now_sz++, x);
    }
    if (S == "DELETE") {
      if (now_sz >= 1) --now_sz;
    }
    if (S == "SAVE") {
      INT(y);
      MP[y] = now;
      sz[y] = now_sz;
    }
    if (S == "LOAD") {
      INT(z);
      now = MP[z];
      now_sz = sz[z];
    }
    ll x = -1;
    if (now_sz) x = PA.get(now, now_sz - 1);
    ANS.eb(x);
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
