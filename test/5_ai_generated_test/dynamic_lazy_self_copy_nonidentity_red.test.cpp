/*
対象：ds/segtree/dynamic_lazy_segtree.hpp の copy_interval。
仕様上、同じ根をコピー元・先に指定しても非恒等作用aは区間へ適用される必要がある。
長さ3の各要素が2の根に、同じ根から区間全体を+5してコピーすると各要素7が期待値。
現行実装は root==other で即返すため期待値21に対して6を返す。既知不具合を固定する失敗期待テスト。修正前にCIへ投入しない。
*/
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/sum_add.hpp"
#include "ds/segtree/dynamic_lazy_segtree.hpp"

int main() {
  using AM = ActedMonoid_Sum_Add<long long>;
  Dynamic_Lazy_SegTree<AM,true> seg(0,3);
  auto root = seg.new_root();
  root = seg.apply(root,0,3,2);
  const auto before = seg.prod(root,0,3);
  // Contract: destination[l:r) <- source[l:r) acted by +5.
  // Source and destination roots happen to be the same. Persistent copy
  // must make a new version with 7 at each of the three positions.
  auto copied = seg.copy_interval(root,root,0,3,5);
  const auto expected = 3LL*7;
  const auto actual = seg.prod(copied,0,3);
  if (before != 6 || seg.prod(root,0,3) != 6 || actual != expected) {
    cerr << "KNOWN RED: self-copy with nonidentity action ignored: "
         << "old=" << before << " copied=" << actual
         << " expected=" << expected << '\n';
    return 1;
  }
  cout << "PASS dynamic_lazy_self_copy_nonidentity\n";
}
