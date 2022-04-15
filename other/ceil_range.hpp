#define ceil_range(q, l, r, n) \
  for (ll q = 1, l = n, r = (1LL<<60);\
  q <= n; q = (q == n ? n + 1 : ceil(n, ceil(n, q) - 1)), l = ceil(n, q), r = ceil(n, q - 1))
