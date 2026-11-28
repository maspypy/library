#include "my_template.hpp"
#include "ds/binary_trie_compressed.hpp"

// 圧縮辺の再分割と重複追加を、固定seedの小さい整数多重集合で照合。
// LOG=6 に限定する。永続版は古いrootからも分岐させ、保存時の値を比較する。
// 固定例の0と1は上位5bitを共有し、2回目のaddでmask()を通る。

template<bool Persistent>
void check() {
  using Trie = Binary_Trie_Compressed<6, Persistent>;
  Trie t;
  using NP = typename Trie::np;
  vc<NP> roots{t.new_root()};
  vc<vc<u64>> history(1);
  mt19937 rng(0x4bc4b5);
  for (int step = 0; step < 450; ++step) {
    int prev = len(roots) - 1;
    if constexpr (Persistent) if (step >= 3 && step % 3 == 0) prev = rng() % roots.size();
    u64 x = step < 3 ? step % 2 : rng() % 64;
    u32 n = 1 + (step < 3 ? 0 : rng() % 4);
    auto expected = history[prev];
    expected.insert(expected.end(), n, x);
    roots.push_back(t.add(roots[prev], x, n));
    history.push_back(expected);
    auto verify = [&](int ver, u64 key) {
      const auto& seq = history[ver];
      vc<u64> sorted;
      for (u64 y : seq) sorted.push_back(y ^ key);
      sort(sorted.begin(), sorted.end());
      NP root = roots[ver];
      for (u32 k = 0; k < sorted.size(); ++k) assert(t.kth(root, k, key) == sorted[k]);
      for (u64 hi = 0; hi <= 64; ++hi) {
        auto expected_count = lower_bound(sorted.begin(), sorted.end(), hi) - sorted.begin();
        assert(t.prefix_count(root, hi, key) == expected_count);
      }
      vc<u64> got;
      t.enumerate(root, [&](u64 y, u32 cnt, bool&) { got.insert(got.end(), cnt, y); });
      auto want = seq;
      sort(want.begin(), want.end());
      assert(got == want);
    };
    verify(len(roots) - 1, rng() % 64);
    if constexpr (Persistent) verify(rng() % roots.size(), rng() % 64);
  }
}

int main() {
  check<false>();
  check<true>();
  cout << "compressed binary trie: 900 updates passed\n";
}
