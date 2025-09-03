#define PROBLEM "https://yukicoder.me/problems/no/3229"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/my_bitset.hpp"
#include "mod/mod_pow.hpp"

using BS = My_Bitset;
int matrix_rank(vc<BS> a, int N, int M) {
  int rk = 0;
  FOR(j, M) {
    if (rk == N) break;
    if (!a[rk][j]) {
      FOR(i, rk + 1, N) if (a[i][j]) {
        swap(a[rk], a[i]);
        break;
      }
    }
    if (!a[rk][j]) continue;
    FOR(i, rk + 1, N) {
      if (a[i][j]) {
        a[i] ^= a[rk];
      }
    }
    ++rk;
  }
  return rk;
}

void solve() {
  LL(N, M, K);
  swap(N, M);
  bool bl = 0;
  vc<BS> a(N, BS(M));
  FOR(i, N) {
    STR(S);
    FOR(j, M) a[i][j] = (S[j] - '0');
  }

  ll ANS = mod_pow(2, M - matrix_rank(a, N, M), K);
  print(ANS);
}

signed main() { solve(); }
