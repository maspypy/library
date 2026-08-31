#include "ds/csr.hpp"
#include "mod/mod_inv.hpp"

// p-subset で総和が 0 mod p のものを作る
// return: indices
vc<int> EGZ_prime(int p, vc<ll> A) {
  assert(len(A) == p + p - 1);
  for (auto& x : A) x = bmod<ll>(x, p);
  CSR<int> ids(p);
  FOR(i, len(A)) { ids.add(A[i], i); }
  ids.build();

  A.clear();
  FOR(x, p) FOR(len(ids[x])) A.eb(x);

  [&]() -> void {
    FOR(i, p) {
      if (A[i] == A[i + p - 1]) {
        A = {A.begin() + i, A.begin() + i + p};
        return;
      }
    }
    int t = 0;
    FOR(i, p) t = (t + p - A[i]) % p;
    vc<int> par(p, -1);
    auto exist = [&](int i) -> bool { return (i == 0 || par[i] != -1); };
    FOR(i, p - 1) {
      if (exist(t)) break;
      int d = A[i + p] - A[i];
      ll L = 0, R = mod_inv(d, p) * t % p;
      while (L + 1 < R) {
        ll M = (L + R) / 2;
        (exist(M * d % p) ? L : R) = M;
      }
      par[R * d % p] = i;
    }
    while (t != 0) {
      int i = par[t];
      int d = A[i + p] - A[i];
      t = (t + p - d) % p;
      A[i] = A[i + p];
    }
    A.resize(p);
  }();
  vc<int> CNT(p);
  for (auto& x : A) CNT[x]++;
  vc<int> res;
  FOR(x, p) {
    for (int i : ids[x]) {
      if (CNT[x]) --CNT[x], res.eb(i);
    }
  }
  return res;
}

// N-subset で総和が 0 mod p のものを作る
// return: indices
vc<int> EGZ(int N, vc<ll> A) {
  for (auto& x : A) x = bmod<ll>(x, N);
  assert(len(A) == 2 * N - 1);
  if (N == 1) return {0};
  int p = 2;
  while (N % p != 0) ++p;
  if (N == p) return EGZ_prime(N, A);

  // p is a prime factor
  int M = N / p;
  vc<int> ids;
  vc<int> yet;
  vi nxt_val;
  int k = 0;
  // p-EGZ * (2M-1)
  vc<int> used(2 * p - 1);
  FOR(2 * M - 1) {
    while (len(yet) < 2 * p - 1) {
      yet.eb(k++);
    }
    vc<ll> B = rearrange(A, yet);
    vc<int> way = EGZ_prime(p, B);
    FOR(i, 2 * p - 1) used[i] = 0;
    for (int i : way) used[i] = 1;
    vc<int> nxt;
    ll x = 0;
    FOR(i, 2 * p - 1) {
      if (used[i]) {
        x += A[yet[i]];
        ids.eb(yet[i]);
      } else {
        nxt.eb(yet[i]);
      }
    }
    swap(yet, nxt);
    assert(x % p == 0);
    nxt_val.eb(x / p);
  }
  vc<int> I = EGZ(M, nxt_val);
  vc<int> res;
  for (int i : I) {
    FOR(j, p * i, p * i + p) res.eb(ids[j]);
  }
  return res;
}