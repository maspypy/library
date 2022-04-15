#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "my_template.hpp"
#include "other/io.hpp"

void sol_1() {
  LL(Q);
  map<ll, ll> A;
  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(k, v);
      A[k] = v;
    } else {
      LL(k);
      print(A[k]);
    }
  }
}

void sol_2() {
  LL(Q);
  unordered_map<ll, ll> A;
  A.reserve(Q);
  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(k, v);
      A[k] = v;
    } else {
      LL(k);
      print(A[k]);
    }
  }
}

void sol_3() {
  LL(Q);
  using T = tuple<ll, ll, ll>;
  vc<T> query(Q);
  vi key;
  key.reserve(Q);
  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(k, v);
      query[q] = {t, k, v};
      key.eb(k);
    } else {
      LL(k);
      query[q] = {t, k, 0};
      key.eb(k);
    }
  }
  UNIQUE(key);
  vi A(len(key));
  FOR(q, Q) {
    auto [t, k, v] = query[q];
    k = LB(key, k);
    if (t == 0) {
      A[k] = v;
    } else {
      print(A[k]);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  // sol_1();
  // sol_2();
  sol_3();

  return 0;
}
