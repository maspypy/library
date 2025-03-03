
// Find A suth that: A[0]=s, A[N]=t, dist(A[i],A[i+1])==D[i]. (integer points)
// empty if it does not exists.
// https://atcoder.jp/contests/abc135/tasks/abc135_e
// https://codeforces.com/contest/2068/problem/H
vc<pi> manhattan_path(pi s, pi t, vi D) {
  int N = len(D);
  ll S = SUM<ll>(D);
  ll a = t.fi - s.fi, b = t.se - s.se;
  if ((S + a + b) % 2 != 0) {
    return {};
  }

  auto nxt_range = [&](ll l, ll r, ll d) -> pi {
    // 目的地から [l,r] に居て d 進む
    if (r <= d)
      return {d - r, d + r};
    elif (d <= l) { return {l - d, r + d}; }
    ll a = 0, b = r + d;
    if ((b - a) & 1)
      ++a;
    return {a, b};
  };

  vi L(N + 1), R(N + 1);
  L[0] = R[0] = abs(a) + abs(b);
  FOR(i, N) { tie(L[i + 1], R[i + 1]) = nxt_range(L[i], R[i], D[i]); }
  if (L[N] != 0) {
    return {};
  }

  // dist from (a,b)
  vi A(N + 1);
  FOR_R(i, N) {
    auto [s, t] = nxt_range(A[i + 1], A[i + 1], D[i]);
    A[i] = max(L[i], s);
  }

  auto step = [&](auto &step, ll a, ll b, ll X, ll Y) -> pi {
    // (a,b) から X すすむ
    // (0,0) から Y の位置に行きたいです
    if (a < 0) {
      auto [dx, dy] = step(step, -a, b, X, Y);
      return {-dx, dy};
    }
    if (b < 0) {
      auto [dx, dy] = step(step, a, -b, X, Y);
      return {dx, -dy};
    }
    assert(a >= 0 && b >= 0);
    if (a > b) {
      auto [dx, dy] = step(step, b, a, X, Y);
      return {dy, dx};
    }
    ll k = (a + b + X - Y) / 2;
    if (k <= b) {
      ll dy = -k;
      ll dx = X - abs(dy);
      return {dx, dy};
    }
    assert(k <= a + b);
    ll dx = b - k;
    ll dy = -(X - abs(dx));
    return {dx, dy};
  };

  vc<pi> point;
  point.eb(0, 0);
  FOR(i, N) {
    auto [x, y] = point[i];
    ll d = D[i];
    auto [dx, dy] = step(step, x - a, y - b, d, A[i + 1]);
    x += dx, y += dy;
    point.eb(x, y);
  }
  for (auto &[x, y] : point)
    x += s.fi, y += s.se;
  return point;
}
