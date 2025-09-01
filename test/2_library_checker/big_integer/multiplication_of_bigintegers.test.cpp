#define PROBLEM "https://judge.yosupo.jp/problem/multiplication_of_big_integers"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  auto get = [&]() -> B {
    STR(S);
    return B(S);
  };
  B ANS = get() + get();
  print(ANS.to_string());
}

signed main() {
  INT(T);
  FOR(T) solve();

  return 0;
}
