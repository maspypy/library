#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/intervals.hpp"

// 対象: ds/intervals.hpp の Intervals_Fast<long long>。
// 現行 API の set, get（ERASE=true/false）, get_all, enumerate_range,
// enumerate_all, total_num, total_len を検証する。
//
// 独立 oracle: 各座標の値をそのまま vector に保持する。
// 隣接する同値要素をまとめた極大区間が enumerate/get の期待値となる。
// 代入・削除後の区間数と非 none の長さ合計も、配列から再計算する。
//
// 狙う不具合: 半開区間の off-by-one、左右境界での分割・併合漏れ、
// none_val への代入や get(...,true) による区間消去後の集計値破損、
// FastSet の 64 要素境界をまたぐ区間の列挙漏れ、早期終了の誤動作。
// N=0 での構築は先頭に境界 0 を挿入する実装の対象外とし、N>=1 のみ試す。
// 乱数は mt19937_64 の固定 seed 0x1A7E4A15ULL を使用し、CIで再現可能。

namespace {
using i64 = long long;
using Run = tuple<int, int, i64>;
constexpr i64 NONE = -(1LL << 50);

[[noreturn]] void fail(int n, int step, const string& op, const string& why) {
  cerr << "Intervals_Fast FAILED: n=" << n << " step=" << step << " op=" << op
       << " reason=" << why << '\n';
  abort();
}

struct Tester {
  int n;
  int step = 0;
  string op = "initial";
  vector<i64> a;
  Intervals_Fast<i64> ds;
  mt19937_64& rng;

  Tester(int n_, mt19937_64& rng_)
      : n(n_), a(n_, NONE), ds(n_, NONE), rng(rng_) {
    check();
  }

  void require(bool p, const string& message) {
    if (!p) fail(n, step, op, message);
  }

  vector<Run> runs() const {
    vector<Run> result;
    for (int l = 0; l < n;) {
      int r = l + 1;
      while (r < n && a[r] == a[l]) ++r;
      result.emplace_back(l, r, a[l]);
      l = r;
    }
    return result;
  }

  void check() {
    const auto expected = runs();
    int expected_num = 0, expected_len = 0;
    for (const auto& [l, r, x] : expected) {
      if (x != NONE) {
        ++expected_num;
        expected_len += r - l;
      }
    }
    require(ds.total_num == expected_num, "total_num");
    require(ds.total_len == expected_len, "total_len");
    require(ds.get_all() == a, "get_all");

    vector<Run> actual;
    ds.enumerate_all([&](int l, int r, i64 x, bool& end) {
      require(!end, "unexpected end flag in enumerate_all");
      actual.emplace_back(l, r, x);
    });
    require(
        actual == expected, "enumerate_all: maximal intervals / boundaries");

    // 全座標で get の返す区間が極大であることを検査する。
    for (const auto& [l, r, x] : expected) {
      for (int i = l; i < r; ++i) {
        const auto got = ds.get(i);
        require(got == Run(l, r, x), "get at i=" + to_string(i));
      }
    }

    // [L,R) の端点、L==R、非整列区間、および早期終了を検査する。
    const int L = int(rng() % (n + 1));
    const int R = L + int(rng() % (n - L + 1));
    vector<Run> clipped;
    for (const auto& [l, r, x] : expected) {
      if (max(l, L) < min(r, R)) {
        clipped.emplace_back(max(l, L), min(r, R), x);
      }
    }
    vector<Run> got;
    ds.enumerate_range(L, R, [&](int l, int r, i64 x, bool& end) {
      require(!end, "unexpected end flag in enumerate_range");
      got.emplace_back(l, r, x);
    });
    require(got == clipped,
        "enumerate_range [" + to_string(L) + "," + to_string(R) + ")");

    got.clear();
    const size_t limit = 1 + size_t(rng() % 3);
    ds.enumerate_range(L, R, [&](int l, int r, i64 x, bool& end) {
      got.emplace_back(l, r, x);
      if (got.size() == limit) end = true;
    });
    if (clipped.size() > limit) clipped.resize(limit);
    require(got == clipped, "enumerate_range early termination");
  }

  void set(int l, int r, i64 x) {
    op = "set(" + to_string(l) + "," + to_string(r) + "," + to_string(x) + ")";
    ds.set(l, r, x);
    for (int i = l; i < r; ++i) a[i] = x;
    ++step;
    check();
  }

  void get_and_maybe_erase(int i, bool erase) {
    op = "get(" + to_string(i) + ",ERASE=" + to_string(erase) + ")";
    int l = i, r = i + 1;
    while (l > 0 && a[l - 1] == a[i]) --l;
    while (r < n && a[r] == a[i]) ++r;
    const i64 old = a[i];
    const auto got = ds.get(i, erase);
    require(got == Run(l, r, old), "returned interval before erase");
    if (erase && old != NONE) {
      for (int j = l; j < r; ++j) a[j] = NONE;
    }
    ++step;
    check();
  }
};

void run_case(int n, mt19937_64& rng) {
  Tester t(n, rng);
  const i64 V[] = {NONE, -1000000000000LL, -17, -1, 0, 1, 17, 1000000000000LL};
  auto pick = [&]() -> i64 { return V[rng() % (sizeof(V) / sizeof(V[0]))]; };

  // 同じ値の再代入、全面消去、片側境界、空区間を明示的に踏む。
  t.set(0, n, 17);
  t.set(0, n, 17);
  t.set(0, n, NONE);
  t.set(0, 0, 1);
  t.set(n, n, 1);
  t.set(0, n, -17);
  t.set(n / 4, (3 * n) / 4, NONE);
  t.set(n / 4, (3 * n) / 4, 0);
  t.get_and_maybe_erase(n / 2, true);
  t.get_and_maybe_erase(n / 2, true);

  // 64-ary FastSet の単語・階層境界で、細かな区間の分割・再結合を確認。
  for (int i : {0, 1, 62, 63, 64, 65, 126, 127, 128, 129, 190, 191, 192, 193,
           254, 255, 256}) {
    if (i < n) t.set(i, i + 1, (i % 2 ? -1 : 1));
  }
  for (int i = 0; i < n; ++i) t.set(i, i + 1, (i % 2 ? 1 : 0));
  t.get_and_maybe_erase(n - 1, true);
  t.get_and_maybe_erase(0, true);
  t.set(0, n, NONE);

  // 乱択の区間代入・極大区間消去・照会を混在させる。
  for (int rep = 0; rep < 850; ++rep) {
    int kind = int(rng() % 12);
    if (kind <= 8) {
      int l = int(rng() % (n + 1));
      int r = int(rng() % (n + 1));
      if (l > r) swap(l, r);
      if (kind == 0) l = 0;
      if (kind == 1) r = n;
      if (kind == 2) r = l;
      t.set(l, r, pick());
    } else {
      const int i = int(rng() % n);
      t.get_and_maybe_erase(i, kind == 9 || kind == 10);
    }
  }
}
}  // namespace

int main() {
  mt19937_64 rng(0x1A7E4A15ULL);
  for (int n : {1, 2, 3, 4, 7, 8, 9, 31, 32, 33, 63, 64, 65, 66, 127, 128, 129,
           191, 192, 193, 255, 256, 257}) {
    run_case(n, rng);
  }
  cerr << "PASS: Intervals_Fast independent array oracle\n";
  return 0;
}
