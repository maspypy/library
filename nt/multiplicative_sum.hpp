#include "nt/primetable.hpp"
template <typename T, typename FUNC>
T multiplicative_sum(ll N, FUNC F, vc<T>& sum_lo, vc<T>& sum_hi) {
  // F(p^e) を与える関数に加え、事前に計算した prime sum を持たせる
  // black algorithm in
  // http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html
  ll sqN = sqrtl(N);
  auto P = primetable(sqN);
  auto get = [&](ll d) -> T {
    return (d <= sqN ? sum_lo[d] : sum_hi[double(N) / d]);
  };

  T ANS = T(1) + get(N); // 1 and prime

  // t = up_i^k のときに、(t, i, k, f(t), f(u)) を持たせる

  auto dfs = [&](auto self, ll t, ll i, ll k, T ft, T fu) -> void {
    T f_nxt = fu * F(P[i], k + 1);
    // 子ノードを全部加算
    ANS += f_nxt;
    ANS += ft * (get(double(N) / t) - get(P[i]));

    ll lim = sqrtl(double(N) / t);
    if (P[i] <= lim) { self(self, t * P[i], i, k + 1, f_nxt, fu); }
    FOR3(j, i + 1, len(P)) {
      if (P[j] > lim) break;
      self(self, t * P[j], j, 1, ft * F(P[j], 1), ft);
    }
  };
  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i, 1, F(P[i], 1), 1);
  return ANS;
}