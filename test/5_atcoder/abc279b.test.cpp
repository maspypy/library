#define PROBLEM "https://atcoder.jp/contests/abc279/tasks/abc279_b"

#include "my_template.hpp"
#include "other/io.hpp"

#include "string/is_substring.hpp"

void solve() {
  STR(S, T);
  Yes(is_substring(T, S));
}

signed main() {
  solve();
  return 0;
}
