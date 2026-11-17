#include "my_template.hpp"
#include "ds/segtree/range_minmax.hpp"


template<class T>void check_all() {
  mt19937_64 mt(70042+sizeof(T));
  using P=pair<T,T>;
  using D=Range_MinMax<T>;
  constexpr T INF=infty<T>;
  const P ID={INF,-INF};
  auto oper=[&](P a,P b){return P{min(a.first,b.first),max(a.second,b.second)};};
  int checks=0;
  for(int n:{0,1,2,3,4,7,8,9,15,16,17,31,32,33,63,64,65,127,128,129,255,256,257,511,512,513,1000,4096}) {
    vector<P> v(n,ID);
    D d(n);
    assert(d.n==n);
    assert(d.prod(0,n)==ID);
    for(int i=0;i<n;i++)assert(d.get(i)==ID);
    for(int it=0;it<(n<=513?850:250);it++){
      int mode=mt()%9;
      auto scalar=[&]()->T {return (T)((int)(mt()%1000001)-500000);};
      int i=(n?mt()%n:0);
      if(n && mode<=3){
        if(mode==0){T x=scalar();d.set(i,x);v[i]={x,x};}
        if(mode==1){T a=scalar(),b=scalar();if(a>b)swap(a,b);d.set(i,P{a,b});v[i]={a,b};}
        if(mode==2){T x=scalar();d.multiply(i,x);v[i]=oper(v[i],P{x,x});}
        if(mode==3){T a=scalar(),b=scalar();if(a>b)swap(a,b);d.multiply(i,P{a,b});v[i]=oper(v[i],P{a,b});}
        assert(d.get(i)==v[i]);
      } else if(mode==4) {
        if(n && mt()%5==0){d.set(i,ID);v[i]=ID;}
        assert(d.get_all()==v);
      } else if(mode==5) {
        if(n && mt()%20==0){
          if(mt()%2){d.build(n,[&](int j){return v[j];});}
          else {d.build(v);}
        }
      }
      int l=mt()%(n+1),r=mt()%(n+1);if(l>r)swap(l,r);
      P ans=ID;
      for(int j=l;j<r;j++)ans=oper(ans,v[j]);
      P got=d.prod(l,r);
      if(got!=ans){cerr<<"PROD FAIL type="<<sizeof(T)<<" n="<<n<<" it="<<it<<" l="<<l<<" r="<<r<<" got="<<got.first<<","<<got.second<<" exp="<<ans.first<<","<<ans.second<<"\n";abort();}
      P all=ID;for(auto x:v)all=oper(all,x);
      assert(d.prod_all()==all);
      checks++;
      if(it%3==0){
        int L=mt()%(n+1),R=mt()%(n+1);
        T bound=(T)(mt()%500001);
        auto pred=[&](P p) {return p.first>=-bound&&p.second<=bound;};
        int expR=L;
        P cur=ID;
        for(;expR<n;expR++){P nxt=oper(cur,v[expR]);if(!pred(nxt))break;cur=nxt;}
        int expL=R;
        cur=ID;
        for(;expL>0;){P nxt=oper(v[expL-1],cur);if(!pred(nxt))break;cur=nxt;--expL;}
        int gotR=d.max_right(pred,L),gotL=d.min_left(pred,R);
        if(gotR!=expR||gotL!=expL){cerr<<"BOUNDARY FAIL type="<<sizeof(T)<<" n="<<n<<" it="<<it<<" L="<<L<<" R="<<R<<" bound="<<bound<<" gotR="<<gotR<<" expR="<<expR<<" gotL="<<gotL<<" expL="<<expL<<"\n";abort();}
      }
    }
    // Rebuild from scalar values and from pair-producing lambda.
    vector<T> values(n);
    for(auto& x:values)x=(T)((int)(mt()%1000001)-500000);
    d.build(values);
    for(int i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));
    d.build(n,[&](int i){return values[i];});
    for(int i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));
    d.build(n,[&](int i)->P{return {values[i],values[i]};});
    for(int i=0;i<n;i++)assert(d.get(i)==P(values[i],values[i]));
    d.build(n);assert(d.prod_all()==ID);
  }
  D empty;assert(empty.prod(0,0)==ID);assert(empty.prod_all()==ID);
  cerr<<"PASS "<<sizeof(T)*8<<"-bit "<<checks<<" operations\n";
}
int main(){check_all<int>();check_all<ll>();}
