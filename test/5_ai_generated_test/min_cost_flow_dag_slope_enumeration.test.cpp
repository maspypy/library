#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/min_cost_flow.hpp"

// 負費用付き DAG の slope(limit) を、各辺の整数流量の全列挙で検証。
// TST-0051 の最小反例とは別に、複数の限界費用・等しい傾きの圧縮・
// flow limit による打切りまで、同一ケースの全 limit について検証する。
// 一つのインスタンスに slope を繰り返し呼ばない。
struct Edge { int u, v, cap, cost; };
using Knot = pair<int,ll>;
static bool check(int n, const vc<Edge>& e, int case_id) {
  constexpr ll INF = numeric_limits<ll>::max();
  int cap = 0;
  for (auto x : e) if (x.u == 0) cap += x.cap;
  vc<ll> best(cap+1, INF);
  vc<int> net(n);
  auto dfs = [&](auto&& self, size_t i, ll cost) -> void {
    if (i == e.size()) {
      for (int v=1; v+1<n; ++v) if (net[v]) return;
      if (net[0] >= 0 && net[n-1] == -net[0])
        best[net[0]] = min(best[net[0]],cost);
      return;
    }
    const auto [u,v,c,w] = e[i];
    for (int f=0; f<=c; ++f) {
      net[u]+=f; net[v]-=f;
      self(self,i+1,cost+ll(f)*w);
      net[u]-=f; net[v]+=f;
    }
  };
  dfs(dfs,0,0);
  for (int lim=0; lim<=cap+1; ++lim) {
    vc<Knot> want{{0,0}};
    for (int f=1; f<=lim && f<=cap && best[f]!=INF; ++f) {
      const ll d = best[f]-best[f-1];
      if (f>1 && best[f-1]-best[f-2]==d) want.pop_back();
      want.emplace_back(f,best[f]);
    }
    Min_Cost_Flow<int,ll,true> m(n,0,n-1);
    for (auto x : e) m.add(x.u,x.v,x.cap,x.cost);
    const auto got=m.slope(lim);
    if (got==want) continue;
    cerr<<"case="<<case_id<<" n="<<n<<" limit="<<lim<<'\n';
    for (auto [u,v,c,w]:e) cerr<<"edge "<<u<<' '<<v<<' '<<c<<' '<<w<<'\n';
    for (auto [f,c]:want) cerr<<"want "<<f<<' '<<c<<'\n';
    for (auto [f,c]:got) cerr<<"got "<<f<<' '<<c<<'\n';
    return false;
  }
  return true;
}
int main() {
  // -1,-1,-1,0,3 を順に通る。limit 1..3 は既知番兵バグの影響を受ける。
  if (!check(3,{{0,1,2,-3},{1,2,2,2},{0,2,1,-1},{0,2,1,0},{0,2,1,3}},0)) return 1;
  mt19937 rng(20261124);
  for (int k=1; k<=800; ++k) {
    int n=2+rng()%4, q=rng()%8;
    vc<Edge> e;
    for (int i=0;i<q;++i) {
      int u=rng()%(n-1),v=u+1+rng()%(n-1-u);
      e.push_back({u,v,int(rng()%3),int(rng()%9)-4});
    }
    if (!check(n,e,k)) return 1;
  }
  cout<<"PASS: 801 DAGs and all flow limits\n";
}
