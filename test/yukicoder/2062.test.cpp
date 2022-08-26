#define PROBLEM "https://yukicoder.me/problems/no/2062"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/product_of_one_plus_xn.hpp"

using mint = modint998;

const int P = 999630629;

void solve() {
  /*
  たいていは、f(S) = sum
  ときどき f(S) = sum - 999630629
  ・単純に sum の和をとる
  ・除外回数だけ、999630629 を引く
  */
  LL(N);
  VEC(int, A, N);
  ll SM = SUM(A);
  mint ANS = mint(SM) * mint(2).pow(N - 1);

  // 全体集合から除く値が LIM 以下だと除外
  ll LIM = SM - P;
  if (LIM < 0) return print(ANS);

  // 和が LIM 以下となる選び方を数える
  auto f = product_of_one_plus_xn<mint>(A, LIM + 1);
  f.resize(LIM + 1);
  mint k = SUM(f);
  ANS -= k * mint(P);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
