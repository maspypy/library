#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/slide_split_sum.hpp"

/*
対象: ds/slide_split_sum.hpp の Slide_Split_Sum<ll>。
独立オラクル: std::multiset をソート済み配列に変換し、下位/上位の和と順位を直接計算する。
検証: insert / erase / query(k) / query_l / query_r / kth / get_all / clear。
削除対象は必ず多重集合に存在する。kth は 0 <= k < size の場合にのみ呼ぶ。
狙う不具合: 境界 k=0,size、重複値の遅延削除、左右ヒープの頻繁な移動、
同値跨ぎ、get_all 後の状態破損、clear 後の残留、sl/sr の集計ずれ。
乱択 seed=0x5A1DE20261118ULL。値域 [-50,50]、要素数最大80、計13000操作。
*/

[[noreturn]] static void fail(int t, int op, const string& msg) {
  cerr << "slide_split_sum mismatch t=" << t << " op=" << op << " " << msg << '\n';
  abort();
}

static void check(Slide_Split_Sum<ll>& ds, const multiset<ll>& ms,
                  int trial, int operation, mt19937_64& rng, bool exhaustive) {
  vector<ll> v(ms.begin(), ms.end());
  const int n = int(v.size());
  if (ds.size() != n) fail(trial, operation, "size");
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + v[i];
  if (ds.get_all() != v || ds.get_all() != v) fail(trial, operation, "get_all");

  vector<int> ks = {0, n, n / 2};
  if (n > 0) {
    ks.push_back(1);
    ks.push_back(n - 1);
  }
  if (exhaustive) {
    for (int k = 0; k <= n; ++k) ks.push_back(k);
  } else {
    for (int rep = 0; rep < 5; ++rep) ks.push_back(int(rng() % (n + 1)));
  }
  // 往復する k により、左右境界の移動と遅延削除をまとめて検証する。
  for (int k : ks) {
    auto [left, right] = ds.query(k);
    if (left != pref[k] || right != pref[n] - pref[k]) {
      fail(trial, operation, "query k=" + to_string(k) +
          " got=" + to_string(left) + "," + to_string(right) +
          " want=" + to_string(pref[k]) + "," + to_string(pref[n] - pref[k]));
    }
    if (ds.sl != left || ds.sr != right) fail(trial, operation, "sl/sr");
    if (ds.query_l(k) != pref[k]) fail(trial, operation, "query_l");
    if (ds.query_r(k) != pref[n] - pref[n - k]) fail(trial, operation, "query_r");
    if (ds.get_all() != v) fail(trial, operation, "get_all after slide");
  }
  if (n) {
    vector<int> indices = {0, n - 1, n / 2, int(rng() % n)};
    if (exhaustive) for (int k = 0; k < n; ++k) indices.push_back(k);
    for (int k : indices) {
      if (ds.kth(k) != v[k]) fail(trial, operation, "kth k=" + to_string(k));
    }
  }
}

int main() {
  mt19937_64 rng(0x5A1DE20261118ULL);
  Slide_Split_Sum<ll> ds;
  multiset<ll> ms;
  int op = 0;
  auto ins = [&](ll x) { ds.insert(x); ms.insert(x); ++op; };
  auto del = [&](ll x) {
    auto it = ms.find(x);
    if (it == ms.end()) fail(0, op, "invalid test erase");
    ds.erase(x);
    ms.erase(it);
    ++op;
  };
  check(ds, ms, 0, op, rng, true);
  for (ll x : {0LL, 0LL, 0LL, -50LL, 50LL, -50LL, 50LL, 0LL}) {
    ins(x);
    check(ds, ms, 0, op, rng, true);
  }
  del(0); del(-50); del(50); del(0);
  check(ds, ms, 0, op, rng, true);
  ds.clear(); ms.clear(); ++op;
  check(ds, ms, 0, op, rng, true);

  for (int trial = 1; trial <= 13; ++trial) {
    ds.clear(); ms.clear();
    for (int j = 0; j < 1000; ++j) {
      int action = int(rng() % 100);
      if ((action < 56 && ms.size() < 80) || ms.empty()) {
        ll x = (action % 5 == 0 ? 0 : ll(rng() % 101) - 50);
        ins(x);
      } else if (action < 88) {
        int at = int(rng() % ms.size());
        auto it = ms.begin();
        advance(it, at);
        del(*it);
      } else if (action < 91) {
        ds.clear(); ms.clear(); ++op;
      } else {
        // クエリだけの連続実行でも状態が変化しないことを検証する。
        ++op;
      }
      check(ds, ms, trial, op, rng, (j % 79 == 0 || j < 3));
    }
  }
  cerr << "PASS slide_split_sum " << op << " operations\n";
}
