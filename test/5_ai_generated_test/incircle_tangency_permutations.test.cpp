#include "my_template.hpp"
#include "geo/incircle.hpp"

// 非退化の整数座標三角形に対し、中心が三辺の内側にあり、各辺までの
// 符号付き距離が半径と一致することを検査する。辺長加重平均は使わない。
// 3-4-5三角形の閉形式、6通りの順序、行列式1の細長い三角形も検証。
// 整数の辺差と外積はllで表せる範囲に限定。乱数seedは固定。

namespace {
using P = Point<ll>;
using Tri = array<P, 3>;
int triangles = 0, calls = 0;

long double cross(P a, P b, P c) {
  return (long double)(b.x-a.x)*(c.y-a.y) - (long double)(b.y-a.y)*(c.x-a.x);
}

template<class Real>
void verify(const Tri& base, optional<array<long double, 3>> exact = nullopt) {
  long double orient = cross(base[0],base[1],base[2]);
  long double scale = 1;
  for (P p : base) scale = max({scale, fabsl(p.x), fabsl(p.y)});
  const long double eps = 32 * numeric_limits<Real>::epsilon() * scale;
  auto require = [&](bool ok, const char* label, long double observed, long double expected) {
    if (ok) return;
    cerr << "incircle " << label << " real_bytes=" << sizeof(Real)
         << " case=" << triangles << " got=" << setprecision(18) << observed
         << " want=" << expected << " tolerance=" << eps;
    for (P p : base) cerr << " (" << p.x << ',' << p.y << ')';
    cerr << '\n';
    abort();
  };
  array<int,3> ids{0,1,2};
  array<long double,3> baseline{};
  do {
    auto c = incircle<Real>(base[ids[0]],base[ids[1]],base[ids[2]]);
    array<long double,3> result{c.O.x,c.O.y,c.r};
    require(c.r > 0, "positive radius", c.r, 0);
    for (int j=0;j<3;++j) {
      P a=base[j], b=base[(j+1)%3];
      long double dx=b.x-a.x, dy=b.y-a.y;
      long double d=(dx*(result[1]-a.y) - dy*(result[0]-a.x))/hypotl(dx,dy);
      if (orient<0) d=-d;
      require(d>0 && fabsl(d-result[2])<=eps, "side distance", d,result[2]);
    }
    if (ids == array<int,3>{0,1,2}) baseline=result;
    for(int j=0;j<3;++j) {
      require(fabsl(result[j]-baseline[j])<=eps, "permutation", result[j],baseline[j]);
      if(exact) require(fabsl(result[j]-(*exact)[j])<=eps, "3-4-5", result[j],(*exact)[j]);
    }
    ++calls;
  } while(next_permutation(ids.begin(),ids.end()));
}

void test(const Tri& t, optional<array<long double,3>> exact = nullopt) {
  ++triangles;
  verify<double>(t,exact);
  verify<long double>(t,exact);
}
}  // namespace

int main() {
  for (ll s : {1LL, 19LL, 100000LL}) {
    for (ll y : {-1000000LL, 0LL, 1000000LL}) {
      test({P{0,y},P{3*s,y},P{0,y+4*s}},array<long double,3>{1.L*s,1.L*(y+s),1.L*s});
      test({P{0,y},P{-4*s,y},P{0,y+3*s}},array<long double,3>{-1.L*s,1.L*(y+s),1.L*s});
    }
  }
  for (ll n : {10LL, 1000LL, 100000LL}) test({P{0,0},P{n,1},P{n-1,1}});

  mt19937 rng(0x14c1c1);
  for (int i=0;i<3000;) {
    Tri t{};
    for (auto& p : t) p=P{int(rng()%2001)-1000,int(rng()%2001)-1000};
    if (cross(t[0],t[1],t[2])==0) continue;
    test(t);
    ++i;
  }
  cout << "incircle: " << triangles << " triangles, " << calls << " calls passed\n";
}
