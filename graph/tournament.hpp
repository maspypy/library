// https://official.contest.yandex.ru/opencupXXII/contest/30766/problems/K
// a → b 辺があるかどうかを判定する bool check(int, int) を渡す。
template <typename F>
vc<int> hamiltonian_path_in_tournament(int n, F check) {
  vc<int> P(n);
  iota(all(P), 0);
  sort(all(P), [&](auto& x, auto& y) { return check(x, y); });
  return P;
}
