// find max true
template <typename F>
ll exp_search(F check, ll ok) {
  ll d = 1;
  while (check(ok + d)) {
    ok += d;
    d += d;
  }
  ll ng = ok + d;
  while (ok + 1 < ng) {
    ll x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
