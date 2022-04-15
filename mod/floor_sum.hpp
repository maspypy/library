i128 floor_sum(ll L, ll R, ll a, ll b, ll mod) {
  /*
  sum_{x in [L,R)} floor(ax + b, mod)
  */
  assert(L <= R);
  i128 res = 0;
  b += L * a;
  ll N = R - L;
  while (N) {
    ll q;
    tie(q, a) = divmod(a, mod);
    res += i128(N) * (N - 1) / 2 * q;
    tie(q, b) = divmod(b, mod);
    res += i128(N) * q;
    tie(N, b) = divmod(a * N + b, mod);
    tie(a, mod) = mp(mod, a);
  }
  return res;
}

i128 mod_sum(ll L, ll R, ll a, ll b, ll mod){
  /*
  sum_{x in [L,R)} (ax + b mod mod)
  */
  i128 s = a * L + b;
  i128 t = a * (R-1) + b;
  i128 sum = (s+t) * (R-L) / 2;
  i128 fsum = floor_sum(L, R, a, b, mod);
  return sum - fsum * mod;
}