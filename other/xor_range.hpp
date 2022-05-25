// lo <= a ^ x < hi となる x の区間 [li, ri) たちを返す
vc<pi> xor_range(ll a, ll lo, ll hi) {
  vc<pi> res;
  FOR(k, 64) {
    if (lo == hi) break;
    ll b = 1LL << k;
    if (lo & b) {
      res.eb((lo ^ a), (lo ^ a) + b);
      lo += b;
    }
    if (hi & b) {
      res.eb((hi - b) ^ a, ((hi - b) ^ a) + b);
      hi -= b;
    }
    if (a & b) a ^= b;
  }
  return res;
}
