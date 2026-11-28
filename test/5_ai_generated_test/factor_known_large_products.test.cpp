#include "my_template.hpp"
#include "nt/factor.hpp"

// 小入力は試し割り、広い入力は試し割りで証明済みの素数から作った
// 既知の因数を使う。ライブラリの is_prime を正解判定に使わない。
using PF = vc<pair<ll,int>>;
PF trial(ll n) {
  PF a;
  for (ll p=2;p<=n/p;++p) {
    int e=0;
    while(n%p==0) { n/=p; ++e; }
    if(e) a.emplace_back(p,e);
  }
  if(n>1) a.emplace_back(n,1);
  return a;
}
ll cases=0, direct=0;
void check(ll n,const PF& want,bool check_direct) {
  auto got=factor(n);
  if(got!=want) {
    cerr<<"factor n="<<n<<'\n';
    for(auto [p,e]:got) cerr<<p<<'^'<<e<<' ';
    cerr<<'\n';
    abort();
  }
  ++cases;
  if(check_direct && n>1) {
    ll p=find_prime_factor(n);
    if(none_of(want.begin(),want.end(),[&](auto v){return v.first==p;})) {
      cerr<<"find_prime_factor n="<<n<<" got="<<p<<'\n';
      abort();
    }
    ++direct;
  }
}
ll prior_prime(ll p) {
  while(trial(p)!=PF{{p,1}}) --p;
  return p;
}
void known(vc<ll> xs) {
  sort(xs.begin(),xs.end());
  PF pf;
  ll n=1;
  for(ll p:xs) {
    assert(n<=infty<ll>/p);
    n*=p;
    if(!pf.empty() && pf.back().first==p) ++pf.back().second;
    else pf.emplace_back(p,1);
  }
  check(n,pf,true);
}
int main() {
  for(ll n=1;n<=12000;++n) check(n,trial(n),n<=256);
  for(ll n=(1LL<<30)-32;n<=(1LL<<30)+32;++n) check(n,trial(n),true);
  mt19937 rng(420044);
  vc<ll> large;
  for(int i=0;i<12;++i) large.push_back(prior_prime(2000000001LL-rng()%5000000));
  for(int i=0;i<12;++i) {
    const ll p=large[i],q=large[(i+1)%12];
    known({p}); known({p,p}); known({p,q}); known({2,p});
    known({101,101,p});
  }
  const ll a=prior_prime(1590001);
  known({a,a,a});
  known(vc<ll>(61,2));
  cout<<cases<<" factorizations, "<<direct<<" direct checks passed\n";
}
