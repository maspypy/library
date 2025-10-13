#include "mod/mod_sqrt.hpp"
#include "nt/primetest.hpp"
#include "mod/primitive_root.hpp"

// a[i]+a[j] が distinct になるように a[i] を作る
// [0,p(p-1)) に p-1 個という簡単な方法がある.
struct Sidon_Sequence {
  u32 N, p, r;
  // positive にした
  vc<u32> exp, log;
  vc<u64> A;

  Sidon_Sequence(u32 N) : N(N) {
    p = max<ll>(3, N + 1);
    while (!primetest(p)) ++p;
    exp.resize(p - 1);
    log.resize(p);
    u32 r = primitive_root(p);
    exp[0] = 1;
    FOR(i, p - 2) exp[i + 1] = exp[i] * u64(r) % p;
    FOR(i, p - 1) log[exp[i]] = i;
    A.resize(N);
    for (u32 i = 0; i < N; ++i) {
      u64 a = i;
      u64 b = exp[i];
      u64 t = (a < b ? a - b + p - 1 : a - b);
      A[i] = (b + t * p) % (u64(p) * (p - 1));
    }
  }

  u64 operator[](int i) { return A[i]; }

  pair<int, int> query(u64 val) {
    u64 prod = exp[val % (p - 1)];
    u64 sm = val % p;
    u64 sq = (sm * sm + 4 * (p - prod)) % p;
    if (log[sq] & 1) return {-1, -1};
    assert(log[sq] % 2 == 0);
    u64 k = log[sq] / 2;
    u32 x = sm + exp[k], y = sm + p - exp[k];
    x += (x & 1) * p, y += (y & 1) * p;
    x = x / 2 % p, y = y / 2 % p;
    x = log[x], y = log[y];
    if (x < N && y < N && A[x] + A[y] == val) return {x, y};
    return {-1, -1};
  }
};
