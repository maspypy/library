#define PROBLEM "https://yukicoder.me/problems/no/2166"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/from_log_differentiation.hpp"
#include "poly/multipoint.hpp"

const int mod = 998244353;

using mint = modint998;
using poly = vc<mint>;

using MAT = array<array<poly, 2>, 2>;

struct Mono {
  using value_type = MAT;
  using X = value_type;
  static X op(X x, X y) {
    // これは Nlog^2N なので、雑で大丈夫 → そうでもない説
    int nx = 0, ny = 0;
    FOR(i, 2) FOR(j, 2) chmax(nx, len(x[i][j]));
    FOR(i, 2) FOR(j, 2) chmax(ny, len(y[i][j]));
    int n = nx + ny - 1;
    int fft_len = 1;
    while (fft_len < n) fft_len *= 2;
    FOR(i, 2) FOR(j, 2) {
      x[i][j].resize(fft_len);
      ntt(x[i][j], false);
    }
    FOR(i, 2) FOR(j, 2) {
      y[i][j].resize(fft_len);
      ntt(y[i][j], false);
    }
    X z;
    FOR(i, 2) FOR(j, 2) z[i][j].resize(fft_len);

    FOR(i, 2) FOR(j, 2) FOR(k, 2) {
      FOR(p, fft_len) z[i][k][p] += x[i][j][p] * y[j][k][p];
    }
    FOR(i, 2) FOR(j, 2) {
      ntt(z[i][j], true);
      z[i][j].resize(n);
    }
    return z;
  }
  static X unit() {
    MAT x;
    x[0][0] = x[1][1] = {mint(1)};
    x[0][1] = x[1][0] = {};
    return x;
  }
  static constexpr bool commute = 0;
};

void solve_1(int Q) {
  VEC(pi, query, Q);

  auto make_mat = [&](ll K) -> MAT {
    MAT x;
    x[0][0] = {mint(-K - K), mint(2)};           // 2N-2K
    x[0][1] = {mint(-K * (K - 1) / 2), mint(K)}; // KN - K(K-1)/2
    x[1][0] = {mint(1)};
    x[1][1] = {};
    return x;
  };
  int MAX = 100'000;
  const int b_sz = 5000;
  const int b_num = ceil(MAX, b_sz) + 1;
  vvc<int> QID(b_num);
  FOR(q, Q) {
    auto [n, k] = query[q];
    QID[k / b_sz].eb(q);
  }

  auto prod_range = [&](int L, int R) -> MAT {
    assert(L < R);
    vc<MAT> dat(R - L);
    FOR(i, R - L) dat[i] = make_mat(L + i);
    reverse(all(dat));
    while (len(dat) > 1) {
      int n = len(dat);
      FOR(i, n) if (i % 2 == 1) { dat[i - 1] = Mono::op(dat[i - 1], dat[i]); }
      FOR(i, n) if (i % 2 == 0) dat[i / 2] = dat[i];
      dat.resize(ceil(n, 2));
    }
    return dat[0];
  };

  vc<int> ANS(Q);

  MAT suffix_prod = Mono::unit();
  FOR(b, b_num) {
    // suffix_prod に必要なものたちを ME する
    vc<mint> X;
    for (auto&& q: QID[b]) { X.eb(query[q].fi); }
    if (len(X)) {
      SubproductTree<mint> ST(X);
      auto Y0 = ST.evaluation(suffix_prod[0][0]);
      auto Y1 = ST.evaluation(suffix_prod[1][0]);
      FOR(t, len(X)) {
        int qid = QID[b][t];
        auto [N, K] = query[qid];
        N %= mod;
        pi p = {Y0[t].val, Y1[t].val};
        FOR(k, b * b_sz, K) {
          ll c = k * (N + N - k + 1) / 2 % mod;
          p = {(2 * (N - k) * p.fi + c * p.se) % mod, p.fi};
        }
        ANS[qid] = p.fi;
      }
    }
    suffix_prod = Mono::op(prod_range(b * b_sz, b * b_sz + b_sz), suffix_prod);
  }
  FOR(q, Q) print(ANS[q]);
}

mint solve_2(ll N, ll K) {
  if (K >= mod) return 0;
  assert(K <= mod);
  poly f = {mint(2 * N), mint(N)};
  poly g = {mint(1), mint(2), inv<mint>(2)};

  mint fa = [&]() -> mint {
    vc<mint> f = {1, 1};
    return prefix_product_of_poly(f, K).val;
  }();

  mint ANS = fa * from_log_differentiation_kth(K, f, g);
  return ANS;
}

void solve() {
  INT(T);
  if (T <= 10) {
    FOR(T) {
      LL(N, K);
      print(solve_2(N, K));
    }
    return;
  }
  return solve_1(T);
}

signed main() {
  solve();
  return 0;
}
