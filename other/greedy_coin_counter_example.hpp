
// https://codeforces.com/problemset/problem/10/E
// 最小反例 or -1 を返す.
// O(N^3)
int greedy_coin_counter_example(vc<int> A) {
  int N = len(A);
  UNIQUE(A);
  reverse(all(A));
  assert(A.back() == 1);
  assert(A.back() < (1 << 30));
  /*
  https://graal.ens-lyon.fr/~abenoit/algo09/coins2.pdf

  c_i：降順, distinct を仮定.
  不等号は辞書順に関するもの, 最適とは大きさが最小の中で辞書順最適．
  M(x): 最適解, G(x): 貪欲解.

  最小反例 w の構造を考える
  M(w)：i,...,j を使う
  G(w)：i-1以前を何か使う
  最小反例より M(w-c[j])=G(w-c[j]) より G(w-c[j]) は i-1 以前を使わない.
  w-c[j]<c[i-1].

  M(w)=M(w-c[i])+c[i]=G(w-c[i])+c[i]
  >
  G(c[i-1]-1-c[i])+c[i]=G(c[i-1]-1)
  >=G(w-c[j])=M(w-c[j])
  M(w) と M(w-c[j]) の間なので G(c[i-1]-1) は i,...,j-1 について M と同じ.
  ----
  このことより i,j を決めると w が決まる.
  G(c[i-1]-1) を計算して, その [i,j] 部分をとってこればよい.
  よって最適解の候補は O(N^2) 種類になる.

  本当に最小反例になっているかの確認
  G(w): 計算
  M(w): c[i] を使ったあと M(w-c[i])=G(w-c[i])
  検証も O(N) でできる. 全体で O(N^3) 時間.
  */
  int ANS = -1;
  auto upd = [&](int ans) -> void { ANS = (ANS == -1 ? ans : min(ANS, ans)); };
  auto greedy = [&](int x) -> int {
    int cnt = 0;
    FOR(i, N) cnt += x / A[i], x %= A[i];
    return cnt;
  };

  vc<int> S(N);
  FOR(i, 1, N) {
    int x = A[i - 1] - 1;
    FOR(j, i, N) S[j] = x / A[j], x %= A[j];
    int sm = 0, M = 0;
    FOR(j, i, N) {
      sm += A[j] * S[j], M += S[j];
      if (M + 1 < greedy(sm + A[j])) upd(sm + A[j]);
    }
  }
  return ANS;
}