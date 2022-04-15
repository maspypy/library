ll mod_inv(ll val, ll mod) {
  int a = val, b = mod, u = 1, v = 0, t;
  while (b > 0) {
    t = a / b;
    swap(a -= t * b, b), swap(u -= t * v, v);
  }
  if(u < 0) u += mod;
  return u;
}
