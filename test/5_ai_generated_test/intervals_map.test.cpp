#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/intervals.hpp"

// 対象: ds/intervals.hpp の map版 Intervals<int, long long>。
// 既存の Intervals_Fast テストとは異なる、座標圧縮しない実装を検査する。
// 独立oracleは有限区間[-B,B)の1マス配列。外側は常にnone_val。
// 半開区間の境界・隣接区間併合・get(...,true)・区間列挙削除・
// total_num/total_len・空範囲・負座標・番兵に接する区間の誤りを検出する。
// 値は {-777, -2, -1, 0, 1, 2, 3}、-777を未設定値とする。
// すべてのsetは [-B,B) 内で行い、番兵近傍の大域更新は行わない。
// 乱択seed=20261120。未定義/契約外の不正区間は与えない。

using ISet = Intervals<int, long long>;
using ll = long long;
static constexpr int NONE = -777;
using Segment = std::tuple<ll, ll, int>;

static void run_one(int B, std::mt19937_64 &rng) {
  ISet ds(NONE);
  std::vector<int> a(2 * B, NONE);
  const int n = static_cast<int>(a.size());
  auto to_index = [&](ll x) { return int(x + B); };
  auto expect_get = [&](ll x) -> Segment {
    int p = to_index(x);
    assert(0 <= p && p < n);
    int value = a[p], l = p, r = p + 1;
    while (l > 0 && a[l - 1] == value) --l;
    while (r < n && a[r] == value) ++r;
    ll xl = (l == 0 && value == NONE ? ISet::LLIM : ll(l - B));
    ll xr = (r == n && value == NONE ? ISet::RLIM : ll(r - B));
    return {xl, xr, value};
  };
  auto fail = [&](const char *message, int it, ll l, ll r) {
    std::cerr << "Intervals map: " << message << " B=" << B << " iteration=" << it
              << " l=" << l << " r=" << r << "\n";
    std::abort();
  };
  // ERASE=true は none_val の同値区間を再併合しないことがある。
  // そのため列挙の「分割数」ではなく、[L,R)を正しく被覆して値が合うかを検査。
  auto validate_enum = [&](ll L, ll R, const std::vector<Segment> &parts,
                           int it, const char *message) {
    ll cur = L;
    for (auto [l, r, v] : parts) {
      if (l != cur || l >= r || r > R) fail(message, it, l, r);
      for (ll x = l; x < r; ++x) {
        if (a[to_index(x)] != v) fail(message, it, l, r);
      }
      cur = r;
    }
    if (cur != R) fail(message, it, L, R);
  };
  auto validate_get = [&](ll x, Segment got, int it, const char *message) {
    auto [l, r, v] = got;
    if (!(ISet::LLIM <= l && l <= x && x < r && r <= ISet::RLIM))
      fail(message, it, x, x + 1);
    if (v != a[to_index(x)]) fail(message, it, x, x + 1);
    if (v != NONE && got != expect_get(x))
      fail(message, it, x, x + 1); // 実値の区間は極大区間になる。
    for (ll y = std::max(l, ll(-B)); y < std::min(r, ll(B)); ++y)
      if (a[to_index(y)] != v) fail(message, it, x, x + 1);
  };
  auto check = [&](int it) {
    int num = 0;
    ll length = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != NONE) {
        ++length;
        if (i == 0 || a[i - 1] != a[i]) ++num;
      }
    }
    if (ds.total_num != num || ds.total_len != length)
      fail("total_num/total_len", it, -B, B);
    for (int rep = 0; rep < 5; ++rep) {
      ll L = ll(rng() % (n + 1)) - B;
      ll R = ll(rng() % (n + 1)) - B;
      if (L > R) std::swap(L, R);
      std::vector<Segment> actual;
      ds.enumerate_range(L, R, [&](ll l, ll r, int v, bool &end) {
        actual.emplace_back(l, r, v);
      });
      validate_enum(L, R, actual, it, "enumerate_range");
    }
    for (int rep = 0; rep < 5; ++rep) {
      ll x = ll(rng() % n) - B;
      validate_get(x, ds.get(x), it, "get");
    }
    if (it % 43 == 0) {
      for (ll x = -B; x < B; ++x)
        validate_get(x, ds.get(x), it, "all get");
      std::vector<Segment> actual;
      ds.enumerate_all([&](ll l, ll r, int value, bool &end) {
        ll L = std::max(l, ll(-B)), R = std::min(r, ll(B));
        if (L < R) actual.emplace_back(L, R, value);
      });
      validate_enum(-B, B, actual, it, "enumerate_all");
    }
  };
  check(-1);
  static constexpr int values[] = {NONE, -2, -1, 0, 1, 2, 3};
  for (int it = 0; it < 2200; ++it) {
    int mode = rng() % 12;
    ll L = ll(rng() % (n + 1)) - B, R = ll(rng() % (n + 1)) - B;
    if (L > R) std::swap(L, R);
    if (mode <= 5) {
      int value = values[rng() % 7];
      if (mode == 0) L = -B;
      if (mode == 1) R = B;
      if (mode == 2) R = L;
      ds.set(L, R, value);
      for (ll x = L; x < R; ++x) a[to_index(x)] = value;
    } else if (mode <= 7) {
      std::vector<Segment> actual;
      ds.enumerate_range(L, R, [&](ll l, ll r, int v, bool &end) {
        actual.emplace_back(l, r, v);
      }, true);
      validate_enum(L, R, actual, it, "enumerate erase callback");
      for (ll x = L; x < R; ++x) a[to_index(x)] = NONE;
    } else if (mode <= 9) {
      ll x = ll(rng() % n) - B;
      Segment actual = ds.get(x, true);
      validate_get(x, actual, it, "get erase return");
      auto [l, r, v] = actual;
      if (v != NONE) {
        for (ll y = l; y < r; ++y) a[to_index(y)] = NONE;
      }
    } else if (mode == 10) {
      std::vector<Segment> actual;
      ds.enumerate_range(L, R, [&](ll l, ll r, int v, bool &end) {
        actual.emplace_back(l, r, v);
        end = true;
      });
      if (actual.size() != (L == R ? 0u : 1u))
        fail("enumerate early stop size", it, L, R);
      if (!actual.empty()) {
        auto [l, r, value] = actual[0];
        if (l != L || r > R || l >= r) fail("enumerate early stop bounds", it, L, R);
        validate_enum(l, r, actual, it, "enumerate early stop value");
      }
    } else {
      ds.set(-B, B, NONE);
      std::fill(a.begin(), a.end(), NONE);
    }
    check(it);
  }
}

int main() {
  std::mt19937_64 rng(20261120);
  for (int B : {1, 2, 7, 17, 65}) run_one(B, rng);
  std::cerr << "PASS intervals_map\n";
}
