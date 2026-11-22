#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/binary_trie.hpp"

// 対象: Binary_Trie<LOG, true> の永続分岐と xor_val 付き kth/count。
// 独立オラクル: 旧バージョンごとに std::map<value,count> を丸ごとコピーし、
// XOR後の値を実際に並べてソートする。分岐した旧rootを再検査して破壊を検出。
// LOG=6と63、重複挿入・2以上の個数・高位ビット境界を使用する。
// 負の個数（削除）とLOG==64は既存実装の別契約・既知指摘と区別する。
// 固定seed 0xB1A7E2026ULL。失敗時はtrial,step,version,maskを出力。
namespace {
[[noreturn]] void fail(int log,int tr,int step,int version,u64 mask,const string& what){
  cerr<<"binary trie log="<<log<<" trial="<<tr<<" step="<<step
      <<" version="<<version<<" mask="<<mask<<" "<<what<<'\n';
  abort();
}
template<int LOG> void run(){
  using Trie=Binary_Trie<LOG,true,u64,u32>;
  using np=typename Trie::np;
  const u64 LIM=u64(1)<<LOG, MASK=LIM-1;
  mt19937_64 rng(0xB1A7E2026ULL+LOG);
  for(int trial=0;trial<52;trial++) {
    Trie t;
    vector<np> roots={t.new_root()};
    vector<map<u64,u32>> refs(1);
    if(t.prefix_count(roots[0],LIM,0)!=0)fail(LOG,trial,-1,0,0,"empty root count");
    for(int step=0;step<145;step++){
      int source=int(rng()%roots.size());
      u64 x;
      switch(step%11){
        case 0:x=0;break;
        case 1:x=MASK;break;
        case 2:x=LIM/2;break;
        case 3:x=LIM/2-1;break;
        case 4:x=1;break;
        default:x=rng()&MASK;break;
      }
      u32 cnt=u32(1+rng()%3);
      roots.push_back(t.add(roots[source],x,cnt));
      auto next=refs[source];next[x]+=cnt;refs.push_back(std::move(next));
      for(int check=0;check<3;check++){
        int v=check==0?int(roots.size()-1):int(rng()%roots.size());
        u64 mask=(check==0?(step%2?MASK:LIM/2):(rng()&MASK));
        vector<u64> transformed;
        u64 total=0;
        for(auto [val,num]:refs[v]){
          total+=num;
          for(u32 j=0;j<num;j++)transformed.push_back(val^mask);
        }
        sort(transformed.begin(),transformed.end());
        if(t.prefix_count(roots[v],LIM,mask)!=total)
          fail(LOG,trial,step,v,mask,"total prefix_count");
        for(int q=0;q<7;q++){
          u64 bound=(q==0?0:q==1?1:q==2?LIM/2:q==3?LIM-1:q==4?LIM:(rng()&MASK));
          u32 expected=lower_bound(transformed.begin(),transformed.end(),bound)-transformed.begin();
          if(t.prefix_count(roots[v],bound,mask)!=expected)
            fail(LOG,trial,step,v,mask,"prefix_count upper="+to_string(bound));
          u64 lo=(q<2?0:(rng()&MASK)),hi=(q<2?LIM:(rng()&MASK));
          if(lo>hi)swap(lo,hi);
          u32 cnt0=lower_bound(transformed.begin(),transformed.end(),hi)-
                   lower_bound(transformed.begin(),transformed.end(),lo);
          if(t.count(roots[v],lo,hi,mask)!=cnt0)
            fail(LOG,trial,step,v,mask,"count interval");
        }
        if(!transformed.empty()){
          int sz=transformed.size();
          for(int k:vector<int>{0,sz/2,sz-1,int(rng()%sz)}){
            if(t.kth(roots[v],k,mask)!=transformed[k])
              fail(LOG,trial,step,v,mask,"kth k="+to_string(k));
          }
          if(t.min(roots[v],mask)!=transformed.front()||
             t.max(roots[v],mask)!=transformed.back())
            fail(LOG,trial,step,v,mask,"min/max");
        }
        map<u64,u32> enumerated;
        t.enumerate(roots[v],[&](u64 val,u32 num,bool& end){
          if(num)enumerated[val]+=num;
          (void)end;
        });
        if(enumerated!=refs[v])fail(LOG,trial,step,v,mask,"enumerate distinct counts");
      }
    }
  }
  cout<<"PASS persistent binary trie LOG="<<LOG<<'\n';
}
}
int main(){run<6>();run<63>();}
