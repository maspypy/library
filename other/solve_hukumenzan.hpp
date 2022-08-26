// a + b = c を解く
vc<tuple<ll, ll, ll>> solve_hukumenzan(string A, string B, string C) {
  using T = tuple<ll, ll, ll>;
  vc<T> res;
  vc<char> v;
  for (auto&& x: A + B + C) v.eb(x);
  UNIQUE(v);
  if (len(v) > 10) return res;
  vc<int> I(10);
  iota(all(I), 0);
  do {
    map<char, int> MP;
    FOR(i, len(v)) MP[v[i]] = I[i];
    if (MP[A[0]] == 0) continue;
    if (MP[B[0]] == 0) continue;
    if (MP[C[0]] == 0) continue;
    ll a = 0, b = 0, c = 0;
    for (auto&& x: A) a = 10 * a + MP[x];
    for (auto&& x: B) b = 10 * b + MP[x];
    for (auto&& x: C) c = 10 * c + MP[x];
    if (a + b == c) res.eb(a, b, c);
  } while (next_permutation(all(I)));
  return res;
}