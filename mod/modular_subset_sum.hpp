#include "alg/monoid_rollinghash.hpp"
#include "other/random.hpp"
#include "ds/segtree.hpp"

/*
計算量：(|vals| + mod) * log^2(mod)
・can(x) または [x] で bool を返す。
・restore(x) で復元。
*/
struct Modular_Subset_Sum {
  int mod;
  vc<int>& vals;
  vc<int> par;

  Modular_Subset_Sum(int mod, vc<int>& vals) : mod(mod), vals(vals) {
    par.assign(mod, -1);

    using Mono = Monoid_Rolling_Hash;
    RandomNumberGenerator RNG;
    const ll base = RNG(0, (1LL << 61) - 1);
    vc<pair<modint61, modint61>> seg_raw(mod + mod);
    FOR(i, mod + mod) seg_raw[i] = {base, 0};
    SegTree<Mono> seg(seg_raw);

    auto add = [&](int x, int i) -> void {
      par[x] = i;
      seg.set(x, {base, 1});
      seg.set(x + mod, {base, 1});
    };

    add(0, -1);

    FOR(i, len(vals)) {
      ll val = vals[i];
      val %= mod;
      vc<pair<int, int>> LR;
      LR.eb(0, mod);
      vc<int> ADD;
      while (len(LR)) {
        auto [L, R] = LR.back();
        LR.pop_back();
        if (L == R) continue;
        modint61 x1 = seg.prod(L, R).se;
        modint61 x2 = seg.prod(mod + L - val, mod + R - val).se;
        if (x1 == x2) continue;
        if (R == L + 1) {
          // 対称差 L が見つかった
          if (!can(L)) ADD.eb(L);
          continue;
        }
        ll M = (L + R) / 2;
        LR.eb(L, M);
        LR.eb(M, R);
      }
      for (auto&& a: ADD) add(a, i);
    }
  }

  bool can(int x) { return (x == 0 || par[x] != -1); }
  bool operator[](int x) { return can(x); }
  vc<int> restore(int x) {
    vc<int> res;
    while (x) {
      int i = par[x];
      res.eb(i);
      x -= vals[i];
      if (x < 0) x += mod;
    }
    reverse(all(res));
    return res;
  }
};
