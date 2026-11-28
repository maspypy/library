#include "my_template.hpp"
#include "string/manacher.hpp"

// 文字間と文字上の各中心から愚直に伸ばし、空回文を除いた [l,r) を比較。
// 等値のほか、同じ剰余類を等値とするコールバックでも照合する。
ll cases=0, centers=0;
template<class Match>
vc<pair<int,int>> expand(int n,Match match) {
  vc<pair<int,int>> a;
  for(int c=0;c<2*n-1;++c) {
    int l=c/2,r=(c+1)/2;
    while(l>=0 && r<n && match(l,r)) { --l; ++r; }
    if(l+1<r) a.emplace_back(l+1,r);
  }
  return a;
}
template<class S>
void check(const S& s) {
  const int n=s.size();
  auto eq=[&](int i,int j){return s[i]==s[j];};
  auto cls=[&](int i,int j){return s[i]%3==s[j]%3;};
  const auto a=expand(n,eq), b=expand(n,cls);
  if(manacher(s)!=a || manacher(n,eq)!=a || manacher(n,cls)!=b) {
    cerr<<"case="<<cases<<" n="<<n<<'\n';
    abort();
  }
  ++cases;
  centers+=max(0,2*n-1);
}

// Colored Tiles の行区間を固定。各列を色列 v[i] とみなし、
// v[i] == reverse(v[j]) の比較だけで得た区間から長方形を数える。
ll check_grid(int h,int w,int mask) {
  vc<vc<int>> a(h,vc<int>(w));
  for(auto& row:a) for(int& x:row) { x=mask&1; mask>>=1; }
  int total=0, brute=0;
  for(int top=0;top<h;++top) for(int bot=top;bot<h;++bot) {
    auto match=[&](int i,int j) {
      for(int r=top;r<=bot;++r) if(a[r][i]!=a[top+bot-r][j]) return false;
      return true;
    };
    auto got=manacher(w,match);
    if(got!=expand(w,match)) abort();
    for(auto [l,r]:got) total+=(r-l+1)/2;
    // 中心拡張とは別に、長方形すべての180度回転を直接調べる。
    for(int l=0;l<w;++l) for(int r=l;r<w;++r) {
      bool ok=true;
      for(int i=top;i<=bot;++i) for(int j=l;j<=r;++j)
        if(a[i][j]!=a[top+bot-i][l+r-j]) ok=false;
      brute+=ok;
    }
  }
  if(total!=brute) abort();
  return h*(h+1)/2;
}

int main() {
  for(int n=0,p=1;n<=9;++n,p*=3) {
    for(int mask=0;mask<p;++mask) {
      string s(n,'\0');
      int z=mask;
      for(char& c:s) { c=char(z%3); z/=3; }
      check(s);
    }
  }
  mt19937 rng(3709);
  for(int i=0;i<400;++i) {
    vc<int> a(rng()%257);
    for(auto& x:a) x=int(rng()%17)-8;
    check(a);
  }
  for(int n:{511,512,513,1023,1024,1025})
    for(int k:{1,2,3,7}) {
      vc<int> a(n);
      for(int i=0;i<n;++i) a[i]=i%k;
      check(a);
      a[n/2]=-1;
      check(a);
    }
  ll grids=0,row_pairs=0;
  for(int h=1;h<=3;++h) for(int w=1;w<=5;++w) {
    if(h*w>12) continue;
    for(int s=0;s<(1<<(h*w));++s) {
      row_pairs+=check_grid(h,w,s);
      ++grids;
    }
  }
  cout<<grids<<" grids, "<<row_pairs<<" row pairs passed\n";
  cout<<cases<<" inputs, "<<centers<<" centers x 3 checks passed\n";
}
