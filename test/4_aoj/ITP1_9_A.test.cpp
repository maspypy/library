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
    for (auto&& token : split(S, " ")) {
      for (auto&& t : token)
        if (isupper(t)) t = tolower(t);
      ANS += token == T;
    }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
