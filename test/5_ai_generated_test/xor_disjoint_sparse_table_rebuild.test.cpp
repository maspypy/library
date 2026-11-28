#include "my_template.hpp"
#include "ds/sparse_table/xor_disjoint_sparse_table.hpp"

// 同じインスタンスに同サイズ・縮小・拡大の build を重ねる。
// 非可換な文字列連結を使い、A[i ^ mask] を i の昇順に直接つないで照合する。
struct Concat_Xor_Rebuild {
  using value_type = string;
  static string id() { return ""; }
  static string op(const string& x, const string& y) { return x + y; }
};

int main() {
  Xor_Disjoint_Sparse_Table<Concat_Xor_Rebuild> st(vc<string>{"old0;", "old1;", "old2;", "old3;"});
  const vc<int> sizes{4, 1, 8, 8, 2, 32, 4, 16, 1, 64, 2, 4};
  mt19937 rng(290);
  ll checks = 0;
  for (int phase = 0; phase < int(sizes.size()); ++phase) {
    const int n = sizes[phase];
    vc<string> a(n);
    if (phase % 3 == 2) {
      st.build(n);
    } else {
      for (int i = 0; i < n; ++i) {
        if (i % 5 || i == 0) a[i] = to_string(phase) + ":" + to_string(i) + ";";
      }
      if (phase % 3 == 0) st.build(a);
      else st.build(n, [&](int i) { return a[i]; });
    }
    auto check = [&](int l, int r, int mask) {
      string expected;
      for (int i = l; i < r; ++i) expected += a[i ^ mask];
      const string got = st.prod(l, r, mask);
      if (got != expected) {
        cerr << "phase=" << phase << " n=" << n << " l=" << l << " r=" << r
             << " mask=" << mask << " expected=" << expected << " got=" << got << '\n';
        abort();
      }
      ++checks;
    };
    for (int mask = 0; mask < n; ++mask) {
      for (int l = 0; l <= n; ++l) {
        check(l, l, mask);
        if (l < n) check(l, l + 1, mask);
      }
      check(0, n, mask);
      if (n <= 16) {
        for (int l = 0; l < n; ++l) {
          for (int r = l + 2; r <= n; ++r) {
            if (l != 0 || r != n) check(l, r, mask);
          }
        }
      }
    }
    if (n > 16) {
      for (int q = 0; q < 4000; ++q) {
        int l = rng() % (n + 1), r = rng() % (n + 1);
        if (l > r) swap(l, r);
        check(l, r, rng() % n);
      }
    }
  }
  cout << checks << " range queries passed\n";
}
