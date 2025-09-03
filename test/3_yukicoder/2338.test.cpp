#define PROBLEM "https://yukicoder.me/problems/no/2338"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/offline_query/rectangle_add_point_sum.hpp"

void solve() {
  LL(N, M, Q);
  vc<int> P(N);
  vc<int> S(N);
  FOR(i, N) {
    read(P[i]);
    --P[i];
    STR(x);
    S[i] = (x == "AC" ? 1 : 0);
  }

  vvc<int> IDX(M);
  FOR(i, N) { IDX[P[i]].eb(i); }

  Rectangle_Add_Point_Sum<Monoid_Add<int>, int, true> AC, PENA;

  FOR(m, M) {
    auto I = IDX[m];
    int n = len(I);

    vc<int> NXT(n, N), PRE(n, -1);
    FOR(i, n) {
      if (i) chmax(PRE[i], PRE[i - 1]);
      if (S[I[i]]) PRE[i] = I[i];
    }

    int nxt_AC = N;
    FOR_R(i, len(I)) {
      int idx = I[i];
      int t = S[idx];
      if (t == 0) {
        // WA
        int a = PRE[i];
        int b = nxt_AC;
        if (b == N) continue;
        PENA.add_query(a + 1, idx + 1, b + 1, N + 1, 1);
      }
      if (t == 1) {
        // AC
        AC.add_query(0, idx + 1, idx + 1, nxt_AC + 1, 1);
        // print("AC", 0, idx + 1, idx + 1, nxt_AC + 1);
        nxt_AC = idx;
      }
    }
  }

  FOR(Q) {
    LL(L, R);
    --L;
    AC.sum_query(L, R);
    PENA.sum_query(L, R);
  }
  vc<int> ANS1 = AC.calc();
  vc<int> ANS2 = PENA.calc();
  FOR(i, Q) { print(ANS1[i], ANS2[i]); }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
