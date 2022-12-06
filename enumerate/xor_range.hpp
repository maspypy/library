// lo <= (x ^ a) < hi となる x の区間 [L, R) の列挙
template <typename F>
void xor_range(u64 a, u64 lo, u64 hi, F query) {
  FOR(k, 64) {
    if (lo == hi) break;
    ll b = 1LL << k;
    if (lo & b) { query((lo ^ a), (lo ^ a) + b), lo += b; }
    if (hi & b) { query((hi - b) ^ a, ((hi - b) ^ a) + b), hi -= b; }
    if (a & b) a ^= b;
  }
}
