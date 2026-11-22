#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/acted_monoid/sum_add.hpp"
#include "ds/segtree/rollback_lazy_segtree.hpp"

// 対象: Rollback_Lazy_SegTree<ActedMonoid_Sum_Add<ll>>。
// independent oracle: std::vector<ll> の更新履歴を毎時刻コピーして保存する。
// set/multiply(点への加算)/apply/get/prod/get_all/prod_all と、
// monotoneな sum<=lim による max_right/min_left を混ぜる。
// read-onlyのはずの query が内部pushで履歴を増やす場合もあるため、
// クエリ直後の時刻を保存した rollback を反復する。
// 非負値のみを使用し二分探索述語の単調性を満たす。
// n=0,1、2の冪の前後のサイズ、空区間、全区間、再build を検証する。
// seed: 0xF273B6D1。データ値と部分和は ll の安全範囲に限定。
using Segment = Rollback_Lazy_SegTree<ActedMonoid_Sum_Add<ll>>;
struct Checkpoint {
  pair<int, int> time;
  vector<ll> vals;
};

[[noreturn]] void fail(int n, int trial, int step, const string& what,
                       ll expected, ll actual) {
  cerr << "rollback_lazy_segtree: n=" << n << " trial=" << trial
       << " step=" << step << " " << what << " expected=" << expected
       << " actual=" << actual << '\n';
  abort();
}

void verify(Segment& seg, const vector<ll>& a, int trial, int step,
            mt19937& rng, bool thorough) {
  int n = (int)a.size();
  ll total = accumulate(a.begin(), a.end(), 0LL);
  if (seg.prod_all() != total)
    fail(n, trial, step, "prod_all", total, seg.prod_all());
  int reps = thorough ? 22 : 5;
  for (int k = 0; k < reps; ++k) {
    int l = int(rng() % (n + 1)), r = int(rng() % (n + 1));
    if (l > r) swap(l, r);
    ll expected = accumulate(a.begin() + l, a.begin() + r, 0LL);
    ll actual = seg.prod(l, r);
    if (actual != expected)
      fail(n, trial, step, "prod[" + to_string(l) + "," + to_string(r) + ")", expected, actual);

    int from = int(rng() % (n + 1));
    int to = int(rng() % (n + 1));
    ll limit = ll(rng() % (total + 3));
    auto check = [&](ll x) { return x <= limit; };
    int mr = from;
    ll sum = 0;
    while (mr < n && sum + a[mr] <= limit) sum += a[mr++];
    actual = seg.max_right(check, from);
    if (actual != mr)
      fail(n, trial, step, "max_right(start=" + to_string(from) + ")", mr, actual);

    int ml = to;
    sum = 0;
    while (ml > 0 && sum + a[ml - 1] <= limit) sum += a[--ml];
    actual = seg.min_left(check, to);
    if (actual != ml)
      fail(n, trial, step, "min_left(end=" + to_string(to) + ")", ml, actual);
  }
  if (thorough) {
    auto all = seg.get_all();
    if (all != a) {
      cerr << "rollback_lazy_segtree: get_all mismatch n=" << n
           << " trial=" << trial << " step=" << step << '\n';
      abort();
    }
    for (int i = 0; i < n; ++i)
      if (seg.get(i) != a[i])
        fail(n, trial, step, "get(" + to_string(i) + ")", a[i], seg.get(i));
  }
}

int main() {
  mt19937 rng(0xF273B6D1);
  for (int n : {0, 1, 2, 3, 7, 8, 9, 15, 16, 17, 31, 32, 33}) {
    for (int trial = 0; trial < 12; ++trial) {
      vector<ll> a(n);
      for (ll& x : a) x = ll(rng() % 9);
      Segment seg;
      // 両形式でbuildして、再build後の旧履歴混入をチェックする。
      seg.build(n, [&](int i) -> ll { return i + 1; });
      seg.build(a);
      vector<Checkpoint> history = {{seg.time(), a}};
      for (int step = 0; step < 420; ++step) {
        int op = int(rng() % 12);
        if (op == 0 && history.size() > 1) {
          int idx = int(rng() % history.size());
          seg.rollback(history[idx].time);
          a = history[idx].vals;
          history.resize(idx + 1);
        } else if (n > 0 && (op == 1 || op == 2)) {
          int pos = int(rng() % n);
          ll x = ll(rng() % 40);
          if (op == 1) {
            seg.set(pos, x);
            a[pos] = x;
          } else {
            seg.multiply(pos, x);
            a[pos] += x;
          }
        } else if (op <= 6) {
          int l = int(rng() % (n + 1)), r = int(rng() % (n + 1));
          if (l > r) swap(l, r);
          ll increment = ll(rng() % 10);
          seg.apply(l, r, increment);
          for (int i = l; i < r; ++i) a[i] += increment;
        } else {
          // 明示的な取得操作を多数混ぜ、pushによる内部履歴も巻き戻す。
          int l = int(rng() % (n + 1)), r = int(rng() % (n + 1));
          if (l > r) swap(l, r);
          ll expected = accumulate(a.begin() + l, a.begin() + r, 0LL);
          ll actual = seg.prod(l, r);
          if (actual != expected) fail(n, trial, step, "query", expected, actual);
        }
        verify(seg, a, trial, step, rng, (step % 17 == 0));
        history.push_back({seg.time(), a});
      }
      seg.rollback(history[0].time);
      verify(seg, history[0].vals, trial, 421, rng, true);
    }
  }
  return 0;
}
