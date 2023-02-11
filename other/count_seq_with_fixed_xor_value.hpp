// [0, LIM)^N のうちで、xor = X となるものの個数
template <typename mint>
mint count_seq_with_fixed_xor(ll N, ll LIM, ll X) {
  assert(LIM >= 1);
  --LIM; // closed
  if (LIM == 0) return (X == 0 ? 1 : 0);
  int LOG = topbit(LIM) + 1;
  if (X >> LOG) return 0;
  mint res = 0;
  bool ok = 1;
  FOR_R(k, LOG) {
    int LIM1 = LIM >> k & 1;
    int X1 = X >> k & 1;
    if (LIM1) {
      ll mk = LIM - (LIM >> k << k);
      mint a = mint(2).pow(k), b = mk + 1;
      tie(a, b) = mp(a + b, a - b);
      a = a.pow(N), b = b.pow(N);
      tie(a, b) = mp(a + b, a - b);
      a *= inv<mint>(2), b *= inv<mint>(2);
      mint now = (X1 ? b : a);
      if ((N & 1) == X1) now -= mint(mk + 1).pow(N);
      now /= mint(2).pow(k);
      res += now;
    }
    if (LIM1 * (N & 1) != X1) {
      ok = 0;
      break;
    }
  }
  if (ok) res += mint(1);
  return res;
}

// [0, LIM)^N のうちで、xor = X となるものの個数。N = 0,1,...,nmax
template <typename mint>
vc<mint> count_seq_with_fixed_xor_iota(ll nmax, ll LIM, ll X) {
  assert(LIM >= 1);
  --LIM; // closed
  vc<mint> res(nmax + 1);
  if (LIM == 0) {
    if (X == 0) fill(all(res), mint(1));
    return res;
  }
  int LOG = topbit(LIM) + 1;
  if (X >> LOG) return res;
  vc<bool> ok(nmax + 1, 1);
  mint x2 = inv<mint>(2);
  mint px2 = x2.pow(LOG);
  FOR_R(k, LOG) {
    px2 += px2;
    int LIM1 = LIM >> k & 1;
    int X1 = X >> k & 1;
    if (LIM1) {
      ll mk = LIM - (LIM >> k << k);
      mint a = mint(2).pow(k), b = mk + 1;
      tie(a, b) = mp(a + b, a - b);
      mint pa = 1, pb = 1, pc = 1;
      FOR(n, nmax + 1) {
        if (ok[n]) {
          mint x = (X1 ? (pa - pb) : (pa + pb)) * x2;
          if ((n & 1) == X1) x -= pc;
          res[n] += x * px2;
        }
        pa *= a, pb *= b, pc *= mint(mk + 1);
      }
    }
    FOR(n, nmax + 1) {
      if (LIM1 * (n & 1) != X1) { ok[n] = 0; }
    }
  }
  FOR(n, nmax + 1) if (ok[n]) res[n] += mint(1);
  return res;
}