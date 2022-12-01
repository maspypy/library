#define PROBLEM "https://yukicoder.me/problems/no/426"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/segtree/segtree.hpp"
#include "linalg/mat_mul.hpp"
using mint = modint107;

using mat = vc<vc<mint>>;

struct Mono {
  using value_type = tuple<mat, mat, mat>;
  using X = value_type;
  static X op(X x, X y) {
    auto& [A, B, C] = x;
    auto& [D, E, F] = y;
    auto P = mat_mul(D, A);
    auto Q = mat_mul(mat_mul(C, E), A);
    FOR(i, 2) FOR(j, 3) Q[i][j] += B[i][j];
    auto R = mat_mul(C, F);
    return {P, Q, R};
  }
  static X unit() {
    mat P(3), Q(2), R(2);
    P[0] = {1, 0, 0};
    P[1] = {0, 1, 0};
    P[2] = {0, 0, 1};
    Q[0] = {0, 0, 0};
    Q[1] = {0, 0, 0};
    R[0] = {1, 0};
    R[1] = {0, 1};
    return {P, Q, R};
  }
  static constexpr bool commute = false;
};

void solve() {
  LL(N);
  VEC(mint, a, 3);
  VEC(mint, b, 2);
  vc<mat> P(N), Q(N), R(N);
  FOR(i, N) {
    P[i] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    mint s = 6 * i + 6;
    Q[i] = {{s, s + 1, s + 2}, {s + 3, s + 4, s + 5}};
    R[i] = {{1, 0}, {0, 1}};
  }
  vc<tuple<mat, mat, mat>> seg_raw(N);
  FOR(i, N) seg_raw[i] = {P[i], Q[i], R[i]};
  SegTree<Mono> seg(seg_raw);

  LL(T);
  FOR(T) {
    STR(s);
    if (s == "ga") {
      LL(idx);
      vc<mint> x = a;
      {
        auto [P, Q, R] = seg.prod(0, idx);
        vc<mint> y(3);
        FOR(i, 3) FOR(j, 3) y[i] += P[i][j] * x[j];
        swap(x, y);
      }
      print(x);
    }
    if (s == "gb") {
      LL(idx);
      vc<mint> x = a;
      {
        auto [P, Q, R] = seg.prod(0, idx);
        vc<mint> y(3);
        FOR(i, 3) FOR(j, 3) y[i] += P[i][j] * x[j];
        swap(x, y);
      }
      {
        auto [P, Q, R] = seg.prod(idx, N);
        vc<mint> y(2);
        FOR(i, 2) FOR(j, 3) y[i] += Q[i][j] * x[j];
        FOR(i, 2) FOR(j, 2) y[i] += R[i][j] * b[j];
        swap(x, y);
      }
      print(x);
    }
    if (s == "a") {
      LL(i);
      FOR(row, 3) {
        LL(a, b, c);
        P[i][row] = {a, b, c};
      }
      mint s = 6 * i + 6;
      Q[i] = {{s, s + 1, s + 2}, {s + 3, s + 4, s + 5}};
      Q[i] = mat_mul(Q[i], P[i]);
      seg.set(i, {P[i], Q[i], R[i]});
    }
    if (s == "b") {
      LL(i);
      --i;
      FOR(row, 2) {
        LL(a, b);
        R[i][row] = {a, b};
      }
      seg.set(i, {P[i], Q[i], R[i]});
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
