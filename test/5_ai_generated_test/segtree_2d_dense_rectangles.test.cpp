// 非2冪・細長・空の矩形について、密な2Dセグ木の行列構築・一点代入を検証。
// 長方形の積は元の2D配列を二重ループで直接走査する。
// 加算と gcd を別々に用い、空の幅や高さでは単位元を確認する。
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/add.hpp"
#include "alg/monoid/gcd.hpp"
#include "ds/segtree/segtree_2d_dense.hpp"

template<class M>
long long run(int mode) {
  std::mt19937 rng(284202 + mode);
  long long count = 0;
  const std::vector<int> sides = {0,1,2,3,4,5,7,8,9,15,16,17};
  for (int h : sides) for (int w : sides) {
    vc<vc<ll>> a(h, vc<ll>(w));
    auto value = [&]() -> ll {
      if (rng() % 4 == 0) return 0;
      int k = int(rng() % 25);
      return mode ? 6 * k : k - 12;
    };
    for (auto& row : a) for (ll& x : row) x = value();
    SegTree_2D_Dense<M> assigned(h, w);
    auto matrix = a;
    SegTree_2D_Dense<M> built(matrix);
    int step = -1;
    auto check = [&](const auto& g, int xl, int xr, int yl, int yr) {
      ll expected = 0;
      for (int x = xl; x < xr; ++x) for (int y = yl; y < yr; ++y) {
        expected = mode ? std::gcd(expected,g[x][y]) : expected + g[x][y];
      }
      ll got = assigned.prod(xl,xr,yl,yr);
      ll b = h ? built.prod(xl,xr,yl,yr) : built.prod(0,0,0,0);
      count += 2;
      if (got != expected || b != expected) {
        std::cerr << "mode=" << mode << " shape=" << h << "x" << w << " step=" << step
                  << " rect=" << xl << "," << xr << "," << yl << "," << yr
                  << " built=" << b << " assigned=" << got << " want=" << expected << '\n';
        std::abort();
      }
    };
    for (int x = 0; x < h; ++x) for (int y = 0; y < w; ++y)
      assigned.set(x,y,a[x][y]);
    auto all_rectangles = [&]() {
      for (int xl = 0; xl <= h; ++xl) for (int xr = xl; xr <= h; ++xr)
        for (int yl = 0; yl <= w; ++yl) for (int yr = yl; yr <= w; ++yr)
          check(a,xl,xr,yl,yr);
    };
    all_rectangles();
    if (!h || !w) continue;
    for (step = 0; step < 35; ++step) {
      int x = step % 5 == 0 ? h-1 : rng()%h;
      int y = step % 5 == 0 ? w-1 : rng()%w;
      ll z = step % 5 == 0 ? 0 : value();
      a[x][y] = z;
      assigned.set(x,y,z);
      built.set(x,y,z);
      check(a,x,x+1,y,y+1);
      check(a,0,h,0,w);
      check(a,x,x,0,w);
      check(a,0,h,y,y);
      int xl=rng()%(h+1), xr=rng()%(h+1), yl=rng()%(w+1), yr=rng()%(w+1);
      check(a,std::min(xl,xr),std::max(xl,xr),std::min(yl,yr),std::max(yl,yr));
    }
    all_rectangles();
  }
  return count;
}
int main() {
  auto add=run<Monoid_Add<ll>>(0), gcd=run<Monoid_Gcd<ll>>(1);
  std::cout << "add=" << add << " gcd=" << gcd << '\n';
}
