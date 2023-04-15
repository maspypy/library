#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/binary_trie.hpp"
#include "random/base.hpp"

void test() {
  const int LOG = 5;
  Binary_Trie<LOG, false, 100> X;

  FOR(100) {
    vector<int> A;
    X.reset();
    auto root = X.new_root();
    FOR(1000) {
      int t = RNG(0, 5);
      if (t == 0) { // add
        int x = RNG(0, 1 << LOG);
        A.eb(x);
        root = X.add(root, x);
      }
      if (t == 1) { // get all
        sort(all(A));
        vc<int> B;
        X.enumerate(root, [&](int k, int cnt) -> void { FOR(cnt) B.eb(k); });
        assert(A == B);
      }
      if (t == 2 && len(A)) { // erase
        int k = RNG(len(A));
        int x = A[k];
        swap(A[k], A.back());
        A.pop_back();
        X.add(root, x, -1);
      }
      if (t == 3 && len(A)) { // kth
        int k = RNG(len(A));
        int xor_val = RNG(0, 1 << LOG);
        vc<int> B;
        for (auto&& x: A) B.eb(x ^ xor_val);
        sort(all(B));
        assert(B[k] == int(X.kth(root, k, xor_val)));
      }
      if (t == 4) { // freq
        int lo = RNG(0, 1 << LOG);
        int hi = RNG(0, 1 << LOG);
        int xor_val = RNG(0, 1 << LOG);
        if (lo > hi) swap(lo, hi);
        ++hi;
        int cnt = 0;
        for (auto&& x: A) {
          int y = x ^ xor_val;
          if (lo <= y && y < hi) ++cnt;
        }
        assert(cnt == X.count(root, lo, hi, xor_val));
      }
    }
  }
}

void solve() {
  INT(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();

  return 0;
}
