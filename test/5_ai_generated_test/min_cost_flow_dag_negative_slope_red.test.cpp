#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/min_cost_flow.hpp"

// 対象: Min_Cost_Flow<int,ll,true>::slope。
// DAG=true では負の費用を持つ辺が合法。限界費用が -1 の場合でも
// slope は (流量0, 費用0) から開始すべきである。
// 最小例: 0->1 容量1 費用-1。流量0の費用0、流量1の費用-1。
// 現行実装は prev_cost_per_flow=-1 を未設定番兵として使うため、
// 最初の限界費用が-1と等しいと result.pop_back() して始点を消す。
// 修正前のCIには追加しない。失敗の事実と再現入力を保存する。
int main(){
  Min_Cost_Flow<int,long long,true> m(2,0,1);
  m.add(0,1,1,-1);
  auto got=m.slope(1);
  const vector<pair<int,long long>> want={{0,0},{1,-1}};
  if(got!=want){
    cerr<<"KNOWN RED min_cost_flow DAG slope with first marginal cost -1\n";
    cerr<<"expected: (0,0) (1,-1)\ngot:";
    for(auto [f,c]:got)cerr<<" ("<<f<<","<<c<<")";
    cerr<<'\n';
    return 1;
  }
  cout<<"PASS min_cost_flow_dag_negative_slope\n";
}
