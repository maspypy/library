#include "nt/primetable.hpp"

// f_pe：T(int p,int e), f(p^e)
// f_psum：[1, x] での f(p) の和
template <typename T, typename F1, typename F2>
T multiplicative_sum(ll N, F1 f_pe, F2 f_psum) {
  ll sqN = sqrtl(N);
  auto P = primetable<int>(sqN);

  T ANS = T(1) + f_psum(N); // 1 and prime
  // t = up_i^k のときに、(t, i, k, f(t), f(u)) を持たせる

  auto dfs = [&](auto self, ll t, ll i, ll k, T ft, T fu) -> void {
    T f_nxt = fu * f_pe(P[i], k + 1);
    // 子ノードを全部加算
    ANS += f_nxt;
    ANS += ft * (f_psum(double(N) / t) - f_psum(P[i]));

    ll lim = sqrtl(double(N) / t);
    if (P[i] <= lim) { self(self, t * P[i], i, k + 1, f_nxt, fu); }
    FOR3(j, i + 1, len(P)) {
      if (P[j] > lim) break;
      self(self, t * P[j], j, 1, ft * f_pe(P[j], 1), ft);
    }
  };
  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i, 1, f_pe(P[i], 1), 1);
  return ANS;
}