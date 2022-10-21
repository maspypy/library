#define FOR_nCk(s, n, k) \
  for (ll s = (1LL << (k)) - 1, tmp_var = 0; s < (1LL << (n)); \
       tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctzll(s) + 1)))
