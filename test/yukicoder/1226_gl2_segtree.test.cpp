#define PROBLEM "https://yukicoder.me/problems/no/1226"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/group_gl2.hpp"
#include "ds/segtree.hpp"
#include "alg/monoid_reverse.hpp"

using Re = double;
using C = complex<Re>;

void solve() {
  LL(N, Q);
  using Mono = Monoid_Reverse<Group_GL2<C>>;
  using X = typename Mono::value_type;

  const Re PI = asin(1) * 2;

  auto from_lt = [&](Re l, Re theta) -> X {
    theta = theta / 180 * PI;
    X A;
    C c = {cos(theta), sin(theta)};
    A[0][0] = 1;
    A[0][1] = l * c;
    A[1][0] = 0;
    A[1][1] = c;
    return A;
  };

  vc<Re> L(N, 1.0), T(N);
  vc<X> seg_raw(N, from_lt(1.0, 0.0));

  SegTree<Mono> seg(seg_raw);
  FOR(Q) {
    LL(t, i);
    --i;
    if (t == 0) {
      LL(t);
      T[i] = t;
      seg.set(i, from_lt(L[i], T[i]));
    }
    if (t == 1) {
      LL(x);
      L[i] = x;
      seg.set(i, from_lt(L[i], T[i]));
    }
    if (t == 2) {
      auto A = seg.prod(0, i + 1);
      C z = A[0][1];
      print(z.real(), z.imag());
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
