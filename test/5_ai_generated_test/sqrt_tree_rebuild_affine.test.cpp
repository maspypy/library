#include "my_template.hpp"
#include "ds/sqrt_tree.hpp"

// 非可換なアフィン合成を、各写像を添字順に直接作用させて検証。
// 0,1 上の値で写像を一意に比較し、同一オブジェクトの古い層の残留も検出する。
using P = pair<u64,u64>;
constexpr u64 MOD = 998244353;
struct Affine_Rebuild {
  using value_type=P;
  static P id() { return {1,0}; }
  static P op(P f, P g) { return {g.first*f.first%MOD,(g.first*f.second+g.second)%MOD}; }
};
int main() {
  SQRT_Tree<Affine_Rebuild> st;
  mt19937 rng(289);
  ll queries=0;
  const vc<int> sizes{129,129,0,1,7,8,9,63,64,65,4095,4096,4097,8200,8200,2,4099};
  for (int phase=0;phase<int(sizes.size());++phase) {
    const int n=sizes[phase];
    vc<P> a(n);
    for(int i=0;i<n;++i) {
      a[i]={2+rng()%1000003,(u64(phase)*10000+i+1)%MOD};
    }
    st.build(n,[&](int i){return a[i];});
    auto check=[&](int l,int r) {
      u64 x=0,y=1;
      for(int i=l;i<r;++i) {
        x=(a[i].first*x+a[i].second)%MOD;
        y=(a[i].first*y+a[i].second)%MOD;
      }
      auto [p,q]=st.prod(l,r);
      if(q!=x || (p+q)%MOD!=y) {
        cerr<<"phase="<<phase<<" n="<<n<<" l="<<l<<" r="<<r
            <<" expected="<<x<<','<<y<<" got="<<q<<','<<(p+q)%MOD<<'\n';
        abort();
      }
      ++queries;
    };
    if(n==129) { check(0,1); check(3,60); check(9,121); }
    if(n<=129) {
      for(int l=0;l<=n;++l) for(int r=l;r<=n;++r) check(l,r);
    } else {
      vc<int> ends{0,1,7,8,9,63,64,65,4094,4095,4096,4097,4098,n};
      for(int l:ends) for(int r:ends) if(l<=r && r<=n) check(l,r);
      for(int q=0;q<1000;++q) {
        int l=rng()%(n+1),r=rng()%(n+1);
        if(l>r) swap(l,r);
        check(l,r);
      }
    }
  }
  cout<<queries<<" queries passed\n";
}
