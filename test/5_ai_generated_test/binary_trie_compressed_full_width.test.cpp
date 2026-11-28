#include "my_template.hpp"
#include "ds/binary_trie_compressed.hpp"

// 型幅全体を使う契約で、葉への64/32bit圧縮辺と分割後の木の両方を検査。
// u64/u32の最上位bit・全bit 1・重複を使い、元の配列をXOR後に直接ソートする。
// prefix_count は表現できる上端のみを使い、上端 UINT_MAX はその値自体を含まない。

template<class U, bool Persistent>
void check_width() {
  constexpr int D = numeric_limits<U>::digits;
  constexpr U top = U(1) << (D-1), max_value = numeric_limits<U>::max();
  using Trie = Binary_Trie_Compressed<D, Persistent, U, u32>;
  Trie t;
  auto root = t.new_root();
  vc<U> values;
  mt19937_64 rng(0x6432ddULL);
  auto verify = [&](auto r, const vc<U>& a) {
    vc<U> got;
    t.enumerate(r, [&](U x, u32 n, bool&) { got.insert(got.end(), n, x); });
    vc<U> orig = a;
    sort(orig.begin(), orig.end());
    assert(got == orig);
    for (U key : {U(0), U(1), top, max_value, U(rng())}) {
      auto b = a;
      for (U& x : b) x ^= key;
      sort(b.begin(), b.end());
      for (u32 k = 0; k < b.size(); ++k) assert(t.kth(r, k, key) == b[k]);
      for (U lim : {U(0), U(1), U(top-1), top, U(top+1), max_value, U(rng())}) {
        auto expected = lower_bound(b.begin(), b.end(), lim) - b.begin();
        assert(t.prefix_count(r, lim, key) == expected);
      }
    }
  };
  verify(root, values);
  root = t.add(root, U(0));
  values.push_back(U(0));
  verify(root, values);
  auto original = root;
  for (int i=0; i<100; ++i) {
    const U edge[] = {U(1), top, max_value, U(top+1), U(top-1), U(0)};
    U x = i < 6 ? edge[i] : U(rng());
    root = t.add(root, x, 2);
    values.insert(values.end(), 2, x);
    verify(root, values);
  }
  if constexpr (Persistent) verify(original, vc<U>{0});
}

int main() {
  check_width<u64, false>();
  check_width<u64, true>();
  check_width<u32, false>();
  check_width<u32, true>();
  cout << "compressed binary trie full width: 404 updates passed\n";
}
