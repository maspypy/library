#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fastset.hpp"

// 対象: ds/fastset.hpp の insert/erase/next/prev/any/enumerate/reset/fill_one/build。
// 独立oracleは vector<unsigned char> の単純な0/1状態と線形走査。
// 特に64-ary階層境界 (63,64,65,4095,4096,4097) と空集合を重点確認する。
// 区間一括erase後の上位ビット伝播、再build後の古いビット、重複更新、
// enumerate の列挙順・読取時早期終了も検査。固定seed 20261120。
// enumerate(...,true)のcallbackからFastSet自体を変更しない（公開契約）。

static void test_size(int n, std::mt19937_64 &rng) {
  FastSet fs(n);
  std::vector<unsigned char> v(n, 0);

  auto enumerate_oracle = [&](int l, int r) {
    std::vector<int> out;
    for (int x = l; x < r; ++x) if (v[x]) out.push_back(x);
    return out;
  };
  auto next_oracle = [&](int x) {
    for (int i = std::max(x, 0); i < n; ++i) if (v[i]) return i;
    return n;
  };
  auto prev_oracle = [&](int x) {
    for (int i = std::min(x, n - 1); i >= 0; --i) if (v[i]) return i;
    return -1;
  };
  auto fail = [&](const char *msg, int it, int l, int r) {
    std::cerr << "FastSet " << msg << " n=" << n << " iteration=" << it << " l=" << l << " r=" << r << "\n";
    std::abort();
  };
  auto check = [&](int it) {
    if (fs.size() != n) fail("size", it, 0, n);
    for (int x : {-3, -1, 0, 1, 62, 63, 64, 65, 127, 128, n / 2, n - 1, n}) {
      if (x <= n && fs.next(x) != next_oracle(x)) fail("next", it, x, 0);
      if (x >= -1 && fs.prev(x) != prev_oracle(x)) fail("prev", it, x, 0);
    }
    for (int rep = 0; rep < 5; ++rep) {
      int l = rng() % (n + 1), r = rng() % (n + 1);
      if (l > r) std::swap(l, r);
      bool any = !enumerate_oracle(l, r).empty();
      if (fs.any(l, r) != any) fail("any", it, l, r);
      std::vector<int> actual;
      fs.enumerate(l, r, [&](int x, bool &end) { actual.push_back(x); }, false);
      if (actual != enumerate_oracle(l, r)) fail("enumerate", it, l, r);
    }
    if (n <= 130 || it % 73 == 0) {
      std::string expected(n, '0');
      for (int i = 0; i < n; ++i) {
        if (static_cast<bool>(fs[i]) != static_cast<bool>(v[i])) fail("membership", it, i, i + 1);
        if (v[i]) expected[i] = '1';
      }
      if (fs.to_string() != expected) fail("to_string", it, 0, n);
    }
  };

  check(-1);
  const int OPS = n <= 257 ? 850 : 190;
  for (int it = 0; it < OPS; ++it) {
    int mode = rng() % 16;
    int x = n ? rng() % n : 0;
    int l = rng() % (n + 1), r = rng() % (n + 1);
    if (l > r) std::swap(l, r);
    if (n && mode <= 3) {
      if (mode < 2) { fs.insert(x); v[x] = 1; }
      else { fs.erase(x); v[x] = 0; }
    } else if (mode == 4) {
      fs.fill_one();
      std::fill(v.begin(), v.end(), 1);
    } else if (mode == 5) {
      fs.reset();
      std::fill(v.begin(), v.end(), 0);
    } else if (mode == 6) {
      fs.build(n);
      std::fill(v.begin(), v.end(), 0);
    } else if (mode == 7 || mode == 8) {
      for (auto &b : v) b = (rng() & 1);
      fs.build(n, [&](int i) { return v[i] != 0; });
    } else if (mode <= 12) {
      std::vector<int> expected = enumerate_oracle(l, r), actual;
      fs.enumerate(l, r, [&](int y, bool &end) { actual.push_back(y); }, true);
      if (actual != expected) fail("enumerate erase result", it, l, r);
      for (int y : expected) v[y] = 0;
    } else if (mode == 13) {
      std::vector<int> expected = enumerate_oracle(l, r), actual;
      if (expected.size() > 2) expected.resize(2);
      fs.enumerate(l, r, [&](int y, bool &end) {
        actual.push_back(y);
        if (actual.size() == 2) end = true;
      });
      if (actual != expected) fail("enumerate early stop", it, l, r);
    } else if (mode == 14) {
      // ワード境界に集中して削除／再追加する。
      for (int z : {0, 63, 64, 65, 127, 128, 4095, 4096, n - 1}) {
        if (0 <= z && z < n) {
          fs.remove(z); v[z] = 0;
          fs.add(z); v[z] = 1;
        }
      }
    }
    check(it);
  }
  fs.reset();
  std::fill(v.begin(), v.end(), 0);
  check(OPS);
  fs.fill_one();
  std::fill(v.begin(), v.end(), 1);
  check(OPS + 1);
}

int main() {
  std::mt19937_64 rng(20261120);
  for (int n : {0, 1, 2, 3, 7, 31, 32, 63, 64, 65, 66, 127, 128, 129, 255, 256, 257,
                4095, 4096, 4097}) {
    test_size(n, rng);
  }
  std::cerr << "PASS fastset_bulk_erase_rebuild\n";
}
