#include "string/lyndon.hpp"
#include "string/zalgorithm.hpp"

// suffix X,Y について, Y<X かつ Y notin prefix(X) となる Y がない X たち.
// 長さの列を返す. 互いに border になっている.
// donimate という呼称は見かけはしたけど標準的でない気がする
vc<int> non_dominated_suffix(string S) {
  // Lyndon のところが候補なのだが, どうやって計算しよう.
  // たぶん Duval algo の中を見ればいいんだけど
  // 考えるのが面倒なので Z algorithm で判定してみるか.
  int N = len(S);
  Incremental_Lyndon_Factorization<char> LDN;
  FOR(i, N) LDN.add(S[i]);
  string RS = {S.rbegin(), S.rend()};
  vc<int> Z = zalgorithm(RS);

  vc<int> ANS;
  vc<int> cut = LDN.factorize();
  while (len(cut) >= 2) {
    int r = POP(cut);
    int l = cut.back();
    int n = r - l;
    int m = N - r;
    if (Z[n] < m) break;
    ANS.eb(n + m);
  }
  return ANS;
}
