// sum_[1,N] sigma_0(n)
ll sigma_0_sum(ll N) {
  assert(N <= (1LL << 50));
  ll sq = sqrtl(N);
  ll ANS = 0;
  for (int d = 1; d <= sq; ++d) { ANS += ll(double(N) / d); }
  return 2 * ANS - sq * sq;
}
