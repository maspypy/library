#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/min_cost_flow.hpp"

// 対象: Min_Cost_Flow<int,ll,false>::flow/slope/edges。
// 独立オラクル: 辺ごとの流量0..capを全列挙し、保存則を満たす流量Fごとの
// 最小費用を求める。返却する増分費用の曲線も線形補間して検査する。
// 今回は DAG=false、辺の費用は非負に限定。負費用DAGの slope バグは別のREDテストに分離。
// 固定seed 0x5A0710ECULL。n<=5、m<=7、cap<=2、費用は0..5。
namespace {
struct E { int u,v,c,price; };
struct Brute { vector<long long> best; int maxflow; };
Brute enumerate(int n,const vector<E>& es){
  vector<int> bal(n);
  vector<long long> ans(32,(1LL<<60));
  auto dfs=[&](auto&& self,int i,long long cost)->void{
    if(i==(int)es.size()){
      for(int v=1;v<n-1;v++)if(bal[v])return;
      if(bal[0]+bal[n-1]||bal[n-1]<0)return;
      int f=bal[n-1];if(f<(int)ans.size()) ans[f]=min(ans[f],cost);
      return;
    }
    E e=es[i];
    for(int f=0;f<=e.c;f++){
      bal[e.u]-=f;bal[e.v]+=f;
      self(self,i+1,cost+1LL*f*e.price);
      bal[e.u]+=f;bal[e.v]-=f;
    }
  };
  dfs(dfs,0,0);
  int mx=0;for(int i=0;i<(int)ans.size();i++)if(ans[i]<(1LL<<50))mx=i;
  if(ans[0]!=0){cerr<<"oracle cost(0) unexpected "<<ans[0]<<'\n';abort();}
  for(int f=0;f<=mx;f++)if(ans[f]>=(1LL<<50))abort();
  return {ans,mx};
}
[[noreturn]]void fail(int n,const vector<E>& es,int lim,const string& what){
  cerr<<"min cost flow n="<<n<<" limit="<<lim<<" "<<what<<'\n';
  for(E e:es)cerr<<e.u<<' '<<e.v<<' '<<e.c<<' '<<e.price<<'\n';
  abort();
}
template<bool DAG>void check(int n,const vector<E>& es){
  auto oracle=enumerate(n,es);
  for(int limit=0;limit<=5;limit++){
    Min_Cost_Flow<int,ll,DAG> mf(n,0,n-1);
    for(E e:es)mf.add(e.u,e.v,e.c,e.price);
    auto [gotflow,gotcost]=mf.flow(limit);
    int expflow=min(limit,oracle.maxflow);
    ll expcost=oracle.best[expflow];
    if(gotflow!=expflow||gotcost!=expcost)
      fail(n,es,limit,"flow expected="+to_string(expflow)+","+to_string(expcost)+
           " got="+to_string(gotflow)+","+to_string(gotcost));
    auto edges=mf.edges();if(edges.size()!=es.size())fail(n,es,limit,"size mismatch");
    vector<int> bal(n);
    ll sum=0;
    for(int i=0;i<(int)es.size();i++){
      auto e=edges[i];E x=es[i];
      if(e.frm!=x.u||e.to!=x.v||e.cap!=x.c||e.cost!=x.price||e.flow<0||e.flow>x.c)
        fail(n,es,limit,"invalid individual flow");
      bal[e.frm]-=e.flow;bal[e.to]+=e.flow;
      sum+=1LL*e.flow*e.cost;
    }
    if(bal[0]!=-gotflow||bal[n-1]!=gotflow||sum!=gotcost)
      fail(n,es,limit,"returned edge flow conservation/cost");
    for(int v=1;v+1<n;v++)if(bal[v])fail(n,es,limit,"intermediate flow conservation");
  }
  Min_Cost_Flow<int,ll,DAG> mf(n,0,n-1);
  for(E e:es)mf.add(e.u,e.v,e.c,e.price);
  auto slope=mf.slope(5);
  if(slope.empty()||slope.front()!=pair<int,ll>(0,0)||slope.back().first!=min(5,oracle.maxflow))
    fail(n,es,5,"slope endpoints");
  for(int i=1;i<(int)slope.size();i++){
    auto [fa,ca]=slope[i-1];auto [fb,cb]=slope[i];
    if(fa>=fb||ca!=oracle.best[fa]||cb!=oracle.best[fb])fail(n,es,5,"slope breakpoints");
    if((cb-ca)%(fb-fa)!=0)fail(n,es,5,"nonintegral marginal cost");
    ll delta=(cb-ca)/(fb-fa);
    for(int f=fa;f<=fb;f++)if(oracle.best[f]!=ca+(f-fa)*delta)
      fail(n,es,5,"slope interpolation at f="+to_string(f));
  }
}
}
int main(){
  check<false>(2,{});
  check<false>(2,{{0,1,2,0},{0,1,2,4}});
  check<false>(3,{{0,1,2,3},{1,2,2,4},{0,2,1,5}});
  mt19937_64 rng(0x5A0710ECULL);
  int total=3;
  for(int n=2;n<=5;n++) for(int rep=0;rep<450;rep++){
    int m=rng()%8;
    vector<E> general;
    for(int i=0;i<m;i++){
      int u=rng()%n,v=rng()%(n-1);if(v>=u)v++;
      general.push_back({u,v,int(rng()%3),int(rng()%6)});
    }
    check<false>(n,general);
    total++;
  }
  cout<<"PASS min_cost_flow_nonnegative_enumeration cases="<<total<<'\n';
}
