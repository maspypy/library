ll knight_distance(ll x, ll y) {
  x = abs(x), y = abs(y);
  if (x + y == 0) return 0;
  if (x + y == 1) return 3;
  if (x == 2 && y == 2) return 4;
  ll step = (max(x, y) + 1) / 2;
  chmax(step, (x + y + 2) / 3);
  step += (step ^ x ^ y) & 1;
  return step;
}
