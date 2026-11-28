#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/add.hpp"
#include "ds/segtree/segtree.hpp"
#include "ds/wavelet_matrix/wavelet_matrix.hpp"

// キーは不変・重みは更新する。区間内の元配列を走査して件数と重みの和を別々に計算し、
// 順位は独立にソートする。重みが0や負でも件数に入ること、同一キーの別位置を混同しない
// ことを検証。multiply は加法モノイドなので重みの加算を意味する。
int main() {
  using WM = Wavelet_Matrix<int, true, SegTree<Monoid_Add<ll>>>;
  mt19937 rng(0x91C017u);
  constexpr int K = 9;
  const array<int, K> bound = {-100,-9,-8,-3,0,1,7,8,100};
  int queries = 0;
  auto require = [](bool ok, int id, int q, const char* kind) {
    if (!ok) {
      cerr << "wavelet weighted: case=" << id << " query=" << q << " op=" << kind << '\n';
      abort();
    }
  };
  WM wm;
  const vc<int> sizes = {0,1,2,3,7,31,32,63,64,65,127,128,129,65,2,0,64};
  for (int id = 0; id < 160; ++id) {
    int n = id < int(sizes.size()) ? sizes[id] : rng() % 135;
    vc<int> a(n);
    vc<ll> w(n);
    for (int i = 0; i < n; ++i) {
      a[i] = id % 6 == 1 ? -3 : int(rng() % 17) - 8;
      w[i] = int(rng() % 13) - 6;
    }
    wm.build(n, [&](int i) { return pair<int,ll>{a[i],w[i]}; });
    for (int q = 0; q < 180; ++q) {
      if (n > 0) {
        int i = rng() % n;
        ll z = int(rng() % 17) - 8;
        if (q % 2 == 0) wm.set(i,z), w[i] = z;
        else wm.multiply(i,z), w[i] += z;
      }
      int l = q % 7 == 0 ? 0 : rng() % (n + 1);
      int r = q % 7 == 0 ? n : rng() % (n + 1);
      if (l > r) swap(l,r);
      int y1 = bound[rng() % K], y2 = bound[rng() % K];
      if (y1 > y2) swap(y1,y2);
      pair<int,ll> range{0,0}, prefix{0,0};
      ll all_sum = 0;
      vc<int> vals;
      for (int i = l; i < r; ++i) {
        vals.push_back(a[i]);
        all_sum += w[i];
        if (a[i] < y2) {
          ++prefix.first;
          prefix.second += w[i];
          if (y1 <= a[i]) ++range.first, range.second += w[i];
        }
      }
      require(wm.count_and_prod(l,r,y1,y2) == range,id,q,"count_and_prod");
      require(wm.prefix_count_and_prod(l,r,y2) == prefix,id,q,"prefix_count_and_prod");
      require(wm.count(l,r,y1,y2) == range.first,id,q,"count");
      require(wm.prod(l,r,y1,y2) == range.second,id,q,"prod");
      require(wm.prod_all(l,r) == all_sum,id,q,"prod_all");
      if (!vals.empty()) {
        sort(vals.begin(),vals.end());
        int k = rng() % vals.size();
        require(wm.kth(l,r,k) == vals[k],id,q,"kth");
        require(wm.median<false>(l,r) == vals[(vals.size()-1)/2],id,q,"median lower");
        require(wm.median<true>(l,r) == vals[vals.size()/2],id,q,"median upper");
      }
      ++queries;
    }
  }
  cerr << "wavelet weighted: " << queries << " query groups PASS\n";
}
