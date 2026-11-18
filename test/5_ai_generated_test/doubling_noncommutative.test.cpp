#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/doubling.hpp"

/*
対象: ds/doubling.hpp の Doubling::add, build, calc, max_step。
独立オラクル: next 配列を一歩ずつ辿り、文字列連結・重み和を逐次計算。
狙う不具合: 2冪の境界、bit を上位から処理するときの非可換な積の順序、
遷移先 -1 の停止処理、未登録遷移、自己ループ・周期、max_step の境界。
max_step の check は、単調な『累積文字数/非負重みが上限以下』のみを使う。
to=-1 の場合は add に恒等元を渡す（公開コメントの「add 不要」に従う）。
LOG=11 で step < 2048、乱択seed=0xD0B11A20261118ULL。
*/

struct Word_Monoid {
  using value_type = string;
  static string id() { return ""; }
  static string op(const string& a, const string& b) { return a + b; }
};

[[noreturn]] static void fail(int trial, int query, int start, int step,
                              const string& name) {
  cerr << "doubling mismatch trial=" << trial << " query=" << query
       << " start=" << start << " step=" << step << " " << name << '\n';
  abort();
}

int main() {
  constexpr int LOG = 11;
  constexpr int LIMIT = (1 << LOG) - 1;
  mt19937_64 rng(0xD0B11A20261118ULL);
  int queries = 0;
  for (int trial = 0; trial < 25; ++trial) {
    int n = (trial == 0 ? 0 : trial == 1 ? 1 : trial == 2 ? 2
             : trial == 3 ? 31 : trial == 4 ? 64 : int(rng() % 80) + 1);
    Doubling<Word_Monoid, LOG> dw(n);
    Doubling<Monoid_Add<ll>, LOG> ds(n);
    vector<int> nx(n, -1);
    vector<string> word(n);
    vector<ll> cost(n);
    for (int i = 0; i < n; ++i) {
      // 一部は add せず、デフォルトの -1 遷移を確かめる。
      if (rng() % 11 == 0) continue;
      int to = (rng() % 5 == 0 ? -1 : int(rng() % n));
      nx[i] = to;
      if (to >= 0) {
        word[i] = "{" + to_string(i) + "}";  // 頂点ごとに異なる非可換な要素
        cost[i] = 1 + ll(rng() % 7);
      }
      dw.add(i, to, word[i]);
      ds.add(i, to, cost[i]);
    }
    dw.build(); ds.build();
    if (!n) continue;

    auto slow = [&](int start, int steps) -> tuple<int, string, ll> {
      string s;
      ll w = 0;
      int at = start;
      for (int t = 0; t < steps && at != -1; ++t) {
        int old = at;
        at = nx[old];
        if (at == -1) break;
        s += word[old];
        w += cost[old];
      }
      return {at, s, w};
    };
    auto slow_max = [&](int start, int letters, ll budget, bool by_weight) {
      string s;
      ll w = 0;
      int at = start, answer = 0;
      for (int step = 0; step < LIMIT; ++step) {
        int nxt = nx[at];
        if (nxt == -1) break;
        if (by_weight && w + cost[at] > budget) break;
        if (!by_weight && int(s.size() + word[at].size()) > letters) break;
        s += word[at];
        w += cost[at];
        at = nxt;
        ++answer;
      }
      return answer;
    };

    for (int query = 0; query < 250; ++query) {
      int i = int(rng() % n);
      const int fixed[] = {0,1,2,3,7,8,15,16,31,32,63,64,127,128,
                           255,256,511,512,1023,1024,2046,2047};
      int step = query < int(size(fixed)) ? fixed[query] : int(rng() % 2048);
      auto [expected_at, expected_word, expected_sum] = slow(i, step);
      auto got_word = dw.calc(i, step);
      auto got_sum = ds.calc(i, step);
      if (got_word.first != expected_at || got_word.second != expected_word)
        fail(trial, query, i, step, "calc word");
      if (got_sum.first != expected_at || got_sum.second != expected_sum)
        fail(trial, query, i, step, "calc sum");

      // 2つの独立した単調条件に対して、限界歩数を全逐次走査で照合。
      const int letter_bound = int(rng() % 80);
      const ll budget = ll(rng() % 80);
      auto check_word = [&](int, const string& s) { return int(s.size()) <= letter_bound; };
      auto check_cost = [&](int, ll w) { return w <= budget; };
      auto k_word = dw.max_step(check_word, i);
      auto k_sum = ds.max_step(check_cost, i);
      if (k_word != slow_max(i, letter_bound, 0, false))
        fail(trial, query, i, step, "max_step word");
      if (k_sum != slow_max(i, 0, budget, true))
        fail(trial, query, i, step, "max_step sum");
      ++queries;
    }
  }
  cerr << "PASS doubling " << queries << " queries\n";
}
