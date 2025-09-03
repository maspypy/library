#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A"
#include "my_template.hpp"
#include "other/io2.hpp"
#include "string/split.hpp"

void solve() {
  STR(T);
  string S;
  ll ANS = 0;
  while (getline(cin, S)) {
    for (auto&& token: split(S, ' ')) {
      for (auto&& t: token)
        if (isupper(t)) t = tolower(t);
      ANS += token == T;
    }
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
