#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/gomory_hu_tree.hpp"

// 対象: gomory_hu_tree<ll>(undirected Graph<ll,0>)。
// 独立オラクル: 元グラフについて各頂点対s,tの全s-t cutを
// 2^n通りの頂点部分集合から列挙し、最小カット容量を計算する。
// 出力の木上のs-tパスで最小の辺容量がその値と一致するかを確認する。
// TreeにN-1辺があり、頂点数と連結性も正しいことを確認する。
// N=1、非連結、0容量、並行辺、辺の向きの入替え、カットの同点を含む。
// ループはMaxFlowの公開APIの自明な前提が不確かなので生成しない。
// 固定seed: 0x6A0F07E3。n<=7, m<=14, 小容量で指数オラクルを実行。
struct Arc {
  int a,b;
  ll cap;
};

[[noreturn]] void fail(int n,int trial,int a,int b,ll got,ll expected,
                       const vector<Arc>& arcs,const string& why){
  cerr << "gomory_hu: n=" << n << " trial=" << trial << " s=" << a << " t=" << b
       << " " << why << " actual=" << got << " expected=" << expected << '\n';
  for(auto e: arcs) cerr << "edge " << e.a << " " << e.b << " " << e.cap << '\n';
  abort();
}

ll brute_min_cut(int n, int s, int t, const vector<Arc>& arcs) {
  ll result = (1LL << 60);
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (!(mask & (1 << s)) || (mask & (1 << t))) continue;
    ll sum = 0;
    for (auto [a,b,cap] : arcs)
      if (bool(mask & (1 << a)) != bool(mask & (1 << b))) sum += cap;
    result = min(result, sum);
  }
  return result;
}

void check(int n, const vector<Arc>& arcs, int trial) {
  Graph<ll, 0> G(n);
  for (auto [a,b,cap] : arcs) G.add(a,b,cap);
  G.build();
  auto H = gomory_hu_tree(G);
  if (H.N != n || (int)H.edges.size() != n-1)
    fail(n, trial, -1,-1,H.edges.size(),n-1,arcs,"not a spanning tree");
  vector<vector<pair<int,ll>>> adj(n);
  for (auto e:H.edges) {
    if(e.frm<0||e.frm>=n||e.to<0||e.to>=n||e.to==e.frm||e.cost<0)
      fail(n,trial,e.frm,e.to,e.cost,0,arcs,"invalid tree edge");
    adj[e.frm].push_back({e.to,e.cost});
    adj[e.to].push_back({e.frm,e.cost});
  }
  for (int s=0;s<n;++s) {
    vector<ll> min_path(n,-1);
    queue<int> q;
    min_path[s]=(1LL<<60);
    q.push(s);
    while(!q.empty()) {
      int v=q.front();q.pop();
      for (auto [to,w] : adj[v]) if(min_path[to]==-1) {
        min_path[to]=min(min_path[v],w);
        q.push(to);
      }
    }
    for(int t=s+1;t<n;++t) {
      ll expected=brute_min_cut(n,s,t,arcs);
      if (min_path[t]!=expected)
        fail(n,trial,s,t,min_path[t],expected,arcs,"tree path minimum != s-t mincut");
    }
  }
}

int main() {
  mt19937 rng(0x6A0F07E3);
  check(1, {}, -1);
  check(4, {}, -2);
  check(4, {{0,1,0},{0,1,2},{1,2,3},{2,3,1},{0,3,0}}, -3);
  for (int n=2;n<=4;++n) {
    vector<pair<int,int>> pairs;
    for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)pairs.push_back({i,j});
    int radix=(n==4?3:4),states=1;
    for(size_t i=0;i<pairs.size();++i) states*=radix;
    for(int mask=0;mask<states;++mask) {
      int z=mask;
      vector<Arc> arcs;
      for(auto [a,b]:pairs) {
        int digit=z%radix; z/=radix;
        if (digit>0) arcs.push_back({a,b,digit==1?1:digit==2?4:8});
      }
      check(n,arcs,mask);
    }
  }
  for (int n=2;n<=7;++n) {
    for (int trial=0;trial<850;++trial) {
      vector<Arc> arcs;
      int m=int(rng()%15);
      for(int j=0;j<m;++j) {
        int a=int(rng()%n),b=int(rng()%(n-1));
        if (b>=a) ++b;
        if (rng()%2) swap(a,b);
        ll cap=ll(rng()%11);
        arcs.push_back({a,b,cap});
      }
      check(n,arcs,trial);
    }
  }
  return 0;
}
