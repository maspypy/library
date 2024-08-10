#define PROBLEM "https://atcoder.jp/contests/abc365/tasks/abc365_a"
#include "my_template.hpp"
#include "other/io.hpp"
#include "datetime/datetime.hpp"

void solve() {
  LL(N);
  ll ANS = 365 + (DateTime::is_leap_year(N));
  print(ANS);
}

int main() {
  solve();
  return 0;
}
