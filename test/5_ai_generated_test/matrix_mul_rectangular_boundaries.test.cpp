#include "my_template.hpp"
#include "linalg/matrix_mul.hpp"

// 非正方行列で内積長16/17・法2^30の境界をまたぐ。
// 法つきの期待値は毎項剰余を取る。空Bは列数を推定できないので寸法を明示。
using Mat = vc<vc<ll>>;
ll calls=0, entries=0;

template<class T, class Read>
void check(const vc<vc<T>>& a, const vc<vc<T>>& b, const Mat& ans,
           int n, int m, int k, ll mod, Read read) {
  auto compare = [&](const auto& got, bool inferred) {
    ++calls;
    assert(int(got.size())==n);
    for(int i=0;i<n;++i) {
      assert(int(got[i].size())==k);
      for(int j=0;j<k;++j) {
        if(read(got[i][j])!=ans[i][j]) {
          cerr<<"n,m,k="<<n<<','<<m<<','<<k<<" mod="<<mod<<" inferred="<<inferred
              <<" i,j="<<i<<','<<j<<" expected="<<ans[i][j]<<" got="<<read(got[i][j])<<'\n';
          abort();
        }
        ++entries;
      }
    }
  };
  compare(matrix_mul(a,b,n,m,k),false);
  if(m) compare(matrix_mul(a,b),true);
}
template<int MOD>
void modular(int n,int m,int k,int mode,mt19937& rng) {
  using T=modint<MOD>;
  Mat x(n,vc<ll>(m)),y(m,vc<ll>(k)),ans(n,vc<ll>(k));
  vc<vc<T>> a(n,vc<T>(m)),b(m,vc<T>(k));
  auto gen=[&]() -> ll { return mode==0 ? MOD-1 : mode==1 ? rng()%MOD : rng()%2 ? MOD-1-rng()%7 : 0; };
  for(int i=0;i<n;++i) for(int j=0;j<m;++j) a[i][j]=x[i][j]=gen();
  for(int i=0;i<m;++i) for(int j=0;j<k;++j) b[i][j]=y[i][j]=gen();
  for(int i=0;i<n;++i) for(int j=0;j<k;++j) for(int t=0;t<m;++t)
    ans[i][j]=(ans[i][j]+x[i][t]*y[t][j])%MOD;
  check(a,b,ans,n,m,k,MOD,[](const T& v){return v.val;});
}
int main() {
  mt19937 rng(480016);
  vc<array<int,3>> shapes;
  for(int m:{0,1,2,15,16,17,18,31,32,33,65})
    for(int n:{0,1,2,5}) for(int k:{0,1,3,8}) shapes.push_back({n,m,k});
  for(int t=0;t<80;++t) shapes.push_back({int(rng()%10),int(rng()%71),int(rng()%10)});
  for(auto [n,m,k]:shapes) for(int mode=0;mode<3;++mode) {
    modular<998244353>(n,m,k,mode,rng);
    modular<1073741823>(n,m,k,mode,rng);
    modular<1073741824>(n,m,k,mode,rng);
    modular<1073741825>(n,m,k,mode,rng);
    modular<2147483647>(n,m,k,mode,rng);
    Mat a(n,vc<ll>(m)),b(m,vc<ll>(k)),ans(n,vc<ll>(k));
    for(auto& row:a) for(auto& v:row) v=ll(rng()%2000001)-1000000;
    for(auto& row:b) for(auto& v:row) v=ll(rng()%2000001)-1000000;
    for(int i=0;i<n;++i) for(int j=0;j<k;++j) for(int t=0;t<m;++t)
      ans[i][j]+=a[i][t]*b[t][j];
    check(a,b,ans,n,m,k,0,[](ll v){return v;});
  }
  cout<<calls<<" products, "<<entries<<" entries passed\n";
}
