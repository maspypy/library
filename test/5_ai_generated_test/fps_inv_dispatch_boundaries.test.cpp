// maspy-ai-test: expand
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_inv.hpp"

// scripts/expander.py で展開してからコンパイルする（畳み込みの依存に重複includeがある）。
// 独立オラクル: 返された逆元 g に対し F*g = 1 mod x^N を愚直な整数畳み込みで検査。
// 打切り長と非零項数を別に動かし、NTT対応法・任意法のディスパッチ境界、
// 2冪前後の長さ、空入力、定数項が1でない場合を検査する。
template <int P>
int check_mod(int threshold, mt19937& rng) {
  using Mint = modint<P>;
  int checks = 0;
  auto run = [&](int n, int nz) {
    vc<Mint> f(n);
    if (n > 0) {
      int c = 3;
      f[0] = c;
      vc<int> pos(n - 1);
      iota(pos.begin(), pos.end(), 1);
      shuffle(pos.begin(), pos.end(), rng);
      for (int i = 0; i + 1 < nz; ++i)
        f[pos[i]] = 1 + rng() % (P - 1);
    }
    auto verify = [&](const vc<Mint>& g, const char* mode) {
      auto fail = [&](int k) {
        cerr << "fps_inv: mod=" << P << " n=" << n << " nz=" << nz
             << " mode=" << mode << " coefficient=" << k << '\n';
        abort();
      };
      if (int(g.size()) != n) fail(-1);
      for (int k = 0; k < n; ++k) {
        u64 v = 0;
        for (int i = 0; i <= k; ++i)
          v = (v + u64(f[i].val) * g[k-i].val) % P;
        if (v != u64(k == 0)) fail(k);
      }
      ++checks;
    };
    verify(fps_inv(f), "dispatch");
    verify(fps_inv_sparse(f), "sparse");
    verify(fps_inv_dense(f), "dense");
  };
  run(0,0);
  for (int n : {1,2,3,31,32,33,127,128,129,255,256,257,511,512,513,1023,1024,1025}) {
    run(n,1);
    run(n,n);
  }
  for (int n : {1023,1024,1025})
    for (int nz : {threshold - 1, threshold, threshold + 1})
      run(n,nz);
  return checks;
}
int main() {
  mt19937 rng(0xF9517u);
  const int a = check_mod<998244353>(160,rng);
  const int b = check_mod<1000000007>(820,rng);
  const int c = check_mod<8>(820,rng);
  cerr << "fps_inv: " << a+b+c << " calls PASS\n";
}
