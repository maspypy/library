// \sum_j[x^j]f^i を i=0,1,...,m
template <typename mint>
vc<mint> power_projection(vc<mint> wt, vc<mint> f, int m) {
  assert(len(f) == len(wt));
  if (f.empty()) { return vc<mint>(m + 1, mint(0)); }
  if (f[0] != mint(0)) {
    mint c = f[0];
    f[0] = 0;
    vc<mint> A = power_projection(wt, f, m);
    FOR(p, m + 1) A[p] *= fact_inv<mint>(p);
    vc<mint> B(m + 1);
    mint pow = 1;
    FOR(q, m + 1) B[q] = pow * fact_inv<mint>(q), pow *= c;
    A = convolution<mint>(A, B);
    A.resize(m + 1);
    FOR(i, m + 1) A[i] *= fact<mint>(i);
    return A;
  }

  int n = 1;
  while (n < len(f)) n *= 2;

  for (auto& x: f) x = -x;
  f.resize(n), wt.resize(n);
  reverse(all(wt));
  vc<mint>&P = wt, &Q = f;
  P.resize(4 * n), Q.resize(4 * n);

  vc<mint> W(n);
  {
    // bit reverse order
    vc<int> btr(n);
    int log = topbit(n);
    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }
    int t = mint::ntt_info().fi;
    mint r = mint::ntt_info().se;
    mint dw = r.inverse().pow((1 << t) / (2 * n));
    mint w = 1;
    for (auto& i: btr) { W[i] = w, w *= dw; }
  }

  int k = 1;
  while (n > 1) {
    /*
    FFT step
    04.. -> 048c
    15.. -> 159d
    .... -> 26ae
    .... -> 37bf
    */

    auto doubling_y = [&](vc<mint>& A, int l, int r) -> void {
      mint z = W[k / 2].inverse();
      vc<mint> f(k);
      FOR(i, l, r) {
        FOR(j, k) f[j] = A[2 * n * j + i];
        ntt(f, 1);
        mint r = 1;
        FOR(j, 1, k) r *= z, f[j] *= r;
        ntt(f, 0);
        FOR(j, k) A[2 * n * (k + j) + i] = f[j];
      }
    };

    auto FFT_x = [&](vc<mint>& A, int l, int r) -> void {
      vc<mint> f(2 * n);
      FOR(j, l, r) {
        move(A.begin() + 2 * n * j, A.begin() + 2 * n * (j + 1), f.begin());
        ntt(f, 0);
        move(all(f), A.begin() + 2 * n * j);
      }
    };

    if (n <= k) {
      doubling_y(P, 0, n), doubling_y(Q, 1, n);
      FFT_x(P, 0, 2 * k), FFT_x(Q, 0, 2 * k);
    } else {
      FFT_x(P, 0, k), FFT_x(Q, 0, k);
      doubling_y(P, 0, 2 * n), doubling_y(Q, 0, 2 * n);
    }
    FOR(i, 2 * n * k) Q[i] += 1;
    FOR(i, 2 * n * k, 4 * n * k) Q[i] -= 1;

    /*
    048c -> 0248????
    159d -> ....????
    26ae
    37bf
    */
    vc<mint> F(2 * n), G(2 * n), f(n), g(n);
    FOR(j, 2 * k) {
      move(P.begin() + 2 * n * j, P.begin() + 2 * n * j + 2 * n, F.begin());
      move(Q.begin() + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());
      FOR(i, n) {
        f[i] = W[i] * (F[2 * i] * G[2 * i + 1] - F[2 * i + 1] * G[2 * i]);
        g[i] = G[2 * i] * G[2 * i + 1];
      }
      ntt(f, 1), ntt(g, 1);
      fill(f.begin() + n / 2, f.end(), mint(0));
      fill(g.begin() + n / 2, g.end(), mint(0));
      move(all(f), P.begin() + n * j);
      move(all(g), Q.begin() + n * j);
    }
    fill(P.begin() + 2 * n * k, P.end(), mint(0));
    fill(Q.begin() + 2 * n * k, Q.end(), mint(0));
    FOR(j, 4 * k) Q[n * j] = 0;
    n /= 2, k *= 2;
  }
  FOR(i, k) P[i] = P[2 * i];
  P.resize(k);
  mint c = mint(1) / mint(k);
  for (auto& x: P) x *= c;
  ntt(P, 1);
  reverse(all(P));
  P.resize(m + 1);
  return P;
}