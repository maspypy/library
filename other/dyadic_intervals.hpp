// 昇順とは限らない，両端から呼ばれる
template <typename F>
void dyadic_intervals(ll L, ll R, F f) {
  FOR(k, 64) {
    if (L == R) break;
    ll b = 1LL << k;
    if (L & b) f(L, L + b), L += b;
    if (R & b) f(R - b, R), R -= b;
  }
}
