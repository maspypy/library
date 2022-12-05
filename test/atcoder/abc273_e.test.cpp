#define PROBLEM "https://atcoder.jp/contests/abc273/tasks/abc273_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/dynamic_array.hpp"

void solve() {
  Dynamic_Array<int, true, 5'000'000> X(0);
  using np = typename decltype(X)::np;

  LL(Q);
  vi ANS;

  np A = X.new_node();
  int A_size = 0;
  map<int, np> note;
  map<int, int> note_size;

  FOR(Q) {
    STR(S);
    if (S == "ADD") {
      INT(x);
      A = X.set(A, A_size++, x);
    }
    if (S == "DELETE") {
      if (A_size) --A_size;
    }
    if (S == "SAVE") {
      INT(y);
      note[y] = A;
      note_size[y] = A_size;
    }
    if (S == "LOAD") {
      INT(z);
      A = MP[z];
      A_size = note_size[z];
    }
    ll x = -1;
    if (A_size) x = X.get(A, A_size - 1);
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
