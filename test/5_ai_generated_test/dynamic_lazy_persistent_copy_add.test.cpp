/*
対象：ds/segtree/dynamic_lazy_segtree.hpp の永続版。
独立オラクル：各操作後の配列をコピーして全バージョンの内容を保存する。任意の過去版からset、multiply、apply、copy_intervalを分岐させる。
コピー元とコピー先が別の根について非零の加算作用を検証し、全区間和と過去版の不変性を照合する。
固定seed 0xDA7AF33、n<=21。自己コピーに非零作用を加えるケースは別の失敗期待テストで扱う。
*/
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/sum_add.hpp"
#include "ds/segtree/dynamic_lazy_segtree.hpp"

static mt19937_64 gen(0xDA7AF33ULL);
static int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }

static void verify(Dynamic_Lazy_SegTree<ActedMonoid_Sum_Add<long long>, true>& seg,
                   Dynamic_Lazy_SegTree<ActedMonoid_Sum_Add<long long>, true>::np root,
                   const vector<long long>& want, int trial, int step, int version) {
  int n = (int)want.size();
  for (int l = 0; l <= n; ++l) {
    long long s = 0;
    for (int r = l; r <= n; ++r) {
      if (r != l) s += want[r-1];
      long long actual = seg.prod(root, l, r);
      if (actual != s) {
        cerr << "dynamic_lazy mismatch trial=" << trial << " step=" << step
             << " version=" << version << " query=[" << l << ',' << r << ")"
             << " actual=" << actual << " expected=" << s << '\n';
        cerr << "array="; for (long long x : want) cerr << x << ',';
        cerr << '\n'; abort();
      }
    }
  }
}

int main() {
  using AM = ActedMonoid_Sum_Add<long long>;
  using Seg = Dynamic_Lazy_SegTree<AM, true>;
  for (int trial = 0; trial < 165; ++trial) {
    int n = randint(1, 21);
    Seg seg(0, n);
    vector<Seg::np> roots = {seg.new_root()};
    vector<vector<long long>> arrays = {vector<long long>(n, 0)};
    for (int step = 0; step < 60; ++step) {
      int i = randint(0, (int)roots.size()-1);
      auto root = roots[i];
      vector<long long> want = arrays[i];
      int op = randint(0, 3);
      int l = randint(0,n), r = randint(0,n);
      if (l > r) swap(l,r);
      if (op == 0) {
        int add = randint(-9,9);
        for (int k=l;k<r;++k) want[k] += add;
        root = seg.apply(root,l,r,add);
      } else if (op == 1) {
        int at = randint(0,n-1), val=randint(-30,30);
        want[at] = val;
        root = seg.set(root,at,val);
      } else if (op == 2) {
        int at = randint(0,n-1), val=randint(-10,10);
        want[at] += val;
        root = seg.multiply(root,at,val);
      } else {
        int j = randint(0,(int)roots.size()-1);
        // Self-copy with nonidentity action is covered by a separate RED test.
        if (roots[j] == root) {
          root=seg.apply(root,l,r,0);
        } else {
          long long add = randint(-7,7);
          for (int k=l;k<r;++k) want[k] = arrays[j][k] + add;
          root = seg.copy_interval(root,roots[j],l,r,add);
        }
      }
      roots.push_back(root);
      arrays.push_back(want);
      verify(seg,root,want,trial,step,(int)roots.size()-1);
      verify(seg,roots[0],arrays[0],trial,step,0);
      for (int rep=0;rep<2;++rep) {
        int v=randint(0,(int)roots.size()-1);
        verify(seg,roots[v],arrays[v],trial,step,v);
      }
    }
  }
  cout << "PASS dynamic_lazy_persistent_copy_add\n";
}
