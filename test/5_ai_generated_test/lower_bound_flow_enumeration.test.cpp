#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/maxflow_with_lower_bound.hpp"

// 対象: MaxFlow_with_Lower_Bound<int>::flow/get_flow_result。
// 独立オラクル: 各辺の流量 lo..hi を全列挙して流量保存則を判定し、
// 非負の s-t 流量の最大値を求める。並行辺、逆向き辺、固定流量、実現不能を含む。
// 入力は s != t、自己ループ無し、0 <= lo <= hi <= 3、n<=5、m<=6 に限定する。
// 固定seed 0xC0A11B0DULL。失敗時には全辺とオラクル結果を表示する。
namespace {
struct E { int u,v,lo,hi; };
int exhaustive(int n,int s,int t,const vector<E>& es) {
  vector<int> bal(n,0);
  int best=-1;
  auto dfs=[&](auto&& self,int i)->void {
    if(i==(int)es.size()) {
      for(int v=0;v<n;v++) if(v!=s&&v!=t&&bal[v]!=0) return;
      if(bal[s]+bal[t]!=0 || bal[t]<0) return;
      best=max(best,bal[t]);return;
    }
    const auto& e=es[i];
    for(int f=e.lo;f<=e.hi;f++) {
      bal[e.u]-=f;bal[e.v]+=f;
      self(self,i+1);
      bal[e.u]+=f;bal[e.v]-=f;
    }
  };
  dfs(dfs,0);
  return best;
}
[[noreturn]]void fail(int n,int s,int t,const vector<E>& es,int exp,int got,const char* msg) {
  cerr << "lower-bound flow: " << msg << " n=" << n << " s=" << s
       << " t=" << t << " expected=" << exp << " got=" << got << '\n';
  for(auto e:es)cerr<<e.u<<' '<<e.v<<' '<<e.lo<<' '<<e.hi<<'\n';
  abort();
}
void check(int n,int s,int t,const vector<E>& es) {
  int exp=exhaustive(n,s,t,es);
  MaxFlow_with_Lower_Bound<int> f(n,s,t);
  for(auto e:es) f.add(e.u,e.v,e.lo,e.hi);
  int got=f.flow();
  if(got!=exp)fail(n,s,t,es,exp,got,"flow value");
  if(got<0)return;
  auto res=f.get_flow_result();
  if(res.size()!=es.size())fail(n,s,t,es,exp,got,"result size");
  vector<int> bal(n,0);
  for(int i=0;i<(int)es.size();i++) {
    auto [u,v,x]=res[i];auto e=es[i];
    if(u!=e.u||v!=e.v||x<e.lo||x>e.hi)fail(n,s,t,es,exp,got,"edge flow");
    bal[u]-=x;bal[v]+=x;
  }
  for(int v=0;v<n;v++) if((v==s&&bal[v]!=-got)||(v==t&&bal[v]!=got)||(v!=s&&v!=t&&bal[v]!=0))
    fail(n,s,t,es,exp,got,"flow conservation");
}
}
int main(){
  check(2,0,1,{});
  check(2,0,1,{{0,1,1,1}});
  check(2,0,1,{{0,1,1,3},{1,0,0,2}});
  check(3,0,2,{{0,1,1,1}});
  check(3,0,2,{{0,1,1,2},{1,2,0,3},{0,2,0,2}});
  mt19937_64 rng(0xC0A11B0DULL);
  int cnt=5;
  for(int n=2;n<=5;n++)for(int rep=0;rep<650;rep++){
    int s=rng()%n,t=rng()%(n-1);if(t>=s)t++;
    int m=rng()%7;
    vector<E> es;
    for(int i=0;i<m;i++){
      int u=rng()%n,v=rng()%(n-1);if(v>=u)v++;
      int hi=rng()%4,lo=rng()%(hi+1);
      es.push_back({u,v,lo,hi});
    }
    check(n,s,t,es);cnt++;
  }
  cout<<"PASS lower_bound_flow_enumeration cases="<<cnt<<'\n';
}
