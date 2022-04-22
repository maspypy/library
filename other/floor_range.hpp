#define floor_range(q, l, r, n) \
  for (ll q = 1, l = (n) / (q + 1) + 1, r = (n) / q + 1;\
  q <= (n); q = (q == (n) ? (n) + 1 : (n) / ((n) / (q + 1))), l = (n) / (q + 1) + 1, r = (n) / q + 1)
