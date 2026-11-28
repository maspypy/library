#include "my_template.hpp"
#include "geo/convex_hull.hpp"

// 小点集合から支持線を全探索。単調鎖を使わずに外周を組み立てる。
// 重複座標の代表 index は規定せず、座標列だけを比較する。
using P=Point<ll>;
i128 cross(P a,P b,P c) {
  return (i128(b.x)-a.x)*(i128(c.y)-a.y)-(i128(b.y)-a.y)*(i128(c.x)-a.x);
}
vc<P> oracle(vc<P> a,bool keep,string mode) {
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());
  int n=a.size();
  if(n<=1) return a;
  bool line=all_of(a.begin(),a.end(),[&](P p){return cross(a.front(),a.back(),p)==0;});
  if(line) return keep?a:vc<P>{a.front(),a.back()};
  vc<int> next(n,-1);
  for(int i=0;i<n;++i) for(int j=0;j<n;++j) {
    if(i==j) continue;
    auto lo=min(a[i],a[j]),hi=max(a[i],a[j]);
    bool ok=true;
    for(int k=0;k<n;++k) {
      i128 c=cross(a[i],a[j],a[k]);
      if(c<0) ok=false;
      if(c==0 && k!=i && k!=j) {
        bool between=lo<a[k] && a[k]<hi;
        if(keep==between) ok=false;
      }
    }
    if(ok) { assert(next[i]==-1); next[i]=j; }
  }
  vc<P> full;
  int i=0;
  do {
    full.push_back(a[i]);
    assert(next[i]>=0 && int(full.size())<=n);
    i=next[i];
  } while(i!=0);
  auto turn=max_element(full.begin(),full.end());
  if(mode=="lower") return vc<P>(full.begin(),turn+1);
  if(mode=="upper") {
    vc<P> r{full.front()};
    for(auto j=full.end();j!=turn;){--j;r.push_back(*j);}
    return r;
  }
  return full;
}
ll calls=0;
template<bool keep>
void check(vc<P> a,int phase) {
  bool line=a.size()<3 || all_of(a.begin(),a.end(),[&](P p){return cross(a.front(),a.back(),p)==0;});
  for(bool sorted:{false,true}) {
    if(sorted) sort(a.begin(),a.end());
    for(string mode:{"full","lower","upper"}) {
      // 全点共線の keep/full の往復列は仕様を固定せず、片鎖のみを検査。
      if(keep && line && mode=="full" && a.size()>2) continue;
      auto expect=oracle(a,keep,mode);
      vc<P> got;
      for(int i:convex_hull<ll,keep>(a,mode,sorted)) {
        assert(0<=i && i<int(a.size())); got.push_back(a[i]);
      }
      if(got!=expect) {
        cerr<<"phase="<<phase<<" keep="<<keep<<" sorted="<<sorted<<" mode="<<mode<<'\n';
        abort();
      }
      ++calls;
    }
  }
}
int main() {
  mt19937 rng(4504);
  for(int mask=1;mask<512;++mask) {
    vc<P> a;
    for(int i=0;i<9;++i) if(mask>>i&1) a.emplace_back(i/3-1,i%3-1);
    shuffle(a.begin(),a.end(),rng);
    check<true>(a,mask);
    for(int j=int(a.size())-1;j>=0;--j) if(rng()%2) a.push_back(a[j]);
    shuffle(a.begin(),a.end(),rng);
    check<false>(a,mask);
  }
  for(int t=0;t<2000;++t) {
    vc<P> a;
    for(int j=1+rng()%16;j;--j) {
      ll x=int(rng()%11)-5,y=int(rng()%11)-5;
      if(t%7==0) y=2*x;
      else if(t%7==1) x=0;
      if(t%3==0) { x+=4'000'000'000'000'000'000LL; y-=4'000'000'000'000'000'000LL; }
      a.emplace_back(x,y);
    }
    check<false>(a,512+t);
    sort(a.begin(),a.end()); a.erase(unique(a.begin(),a.end()),a.end());
    shuffle(a.begin(),a.end(),rng);
    check<true>(a,512+t);
  }
  cout<<calls<<" hull calls passed\n";
}
