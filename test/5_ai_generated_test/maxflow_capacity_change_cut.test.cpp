#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/maxflow.hpp"

/*
対象: MaxFlow<int>::change_capacity 後の flow と cut。
元の小グラフの容量を変更するたびに、全s-tカットを独立に列挙する。
旧実装では、最大流の値が正しくても cut() が直前の到達集合を使い、
現在の容量に対して最小でないカットを返す例がある。
最初に3頂点の既知反例を再現し、その修正後は数千回の乱択容量変更を試す。
非負容量、source != sink、自己ループなし、rev_cap=0、n=2..7。
seed=0xF10C0FFEE2026ULL。テスト失敗は誤検出として無効化しない。
*/

namespace {
vector<string> operation_history;
struct InputEdge {
  int u, v, cap, rev;
};
void fail(int n, int trial, int operation, const string& why) {
  cerr << "MaxFlow n=" << n << " trial=" << trial
       << " op=" << operation << " : " << why << '\n';
  for (const auto& h : operation_history) cerr << "  " << h << '\n';
  abort();
}
int cut_value(const vector<InputEdge>& edges, int mask) {
  int ans = 0;
  for (const auto& e : edges) {
    bool a = (mask >> e.u & 1), b = (mask >> e.v & 1);
    if (a && !b) ans += e.cap;
    if (b && !a) ans += e.rev;
  }
  return ans;
}
int brute_mincut(int n, int s, int t, const vector<InputEdge>& edges) {
  int best = numeric_limits<int>::max();
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (!(mask >> s & 1) || (mask >> t & 1)) continue;
    best = min(best, cut_value(edges, mask));
  }
  return best;
}
void verify(MaxFlow<int>& mf, int n, int s, int t,
            const vector<InputEdge>& edges, int trial, int step) {
  int expected = brute_mincut(n, s, t, edges);
  int got = mf.flow();
  if (got != expected) fail(n, trial, step, "flow=" + to_string(got) +
                                                  " mincut=" + to_string(expected));
  if (mf.flow() != got) fail(n, trial, step, "repeated flow changed");
  const auto [value, side] = mf.cut();
  if (value != expected || int(side.size()) != n)
    fail(n, trial, step, "cut return value or length mismatch");
  if (side[s] != 0 || side[t] != 1)
    fail(n, trial, step, "cut side for source/sink");
  int mask = 0;
  for (int v = 0; v < n; ++v) {
    if (side[v] != 0 && side[v] != 1) fail(n, trial, step, "nonbinary cut");
    if (side[v] == 0) mask |= 1 << v;
  }
  if (cut_value(edges, mask) != expected)
    fail(n, trial, step, "returned cut has capacity=" + to_string(cut_value(edges, mask)) + " but minimum=" + to_string(expected) + " source-side-mask=" + to_string(mask));
}
// 3 頂点で再現する既知のカット集合の回帰条件。
// 2->1 の容量を 9 から 7 に減らすと最大流は 14 から 13 に減る。
// 切断集合の真の最小値は {2} 側の 6+7=13 だが、旧実装では
// 残余到達集合の再計算がなく {1,2} 側の 6+8=14 を返す場合がある。
void known_capacity_reduction_cut_regression() {
  MaxFlow<int> mf(3, 2, 0);
  vector<InputEdge> edges = {{2, 0, 6, 0}, {2, 1, 9, 0}, {1, 0, 8, 0}};
  for (const auto& e : edges) mf.add(e.u, e.v, e.cap);
  verify(mf, 3, 2, 0, edges, -1, 0);
  mf.change_capacity(1, 7);
  edges[1].cap = 7;
  verify(mf, 3, 2, 0, edges, -1, 1);
}
void dynamic_cases(mt19937_64& rng) {
  int trial = 0;
  for (int n = 2; n <= 7; ++n) {
    for (int rep = 0; rep < 70; ++rep) {
      operation_history.clear();
      int s = int(rng() % n), t = int(rng() % n);
      if (t == s) t = (t + 1) % n;
      MaxFlow<int> mf(n, s, t);
      operation_history.push_back("source " + to_string(s) + " sink " + to_string(t));
      vector<InputEdge> edges;
      int m = 1 + int(rng() % 14);
      for (int i = 0; i < m; ++i) {
        int u = int(rng() % n), v = int(rng() % (n - 1));
        if (v >= u) ++v;
        int cap = int(rng() % 7);
        mf.add(u, v, cap);
        edges.push_back({u, v, cap, 0});
        operation_history.push_back("add " + to_string(u) + " " + to_string(v) + " " + to_string(cap));
      }
      verify(mf, n, s, t, edges, trial, -1);
      for (int step = 0; step < 40; ++step) {
        int id = int(rng() % m);
        int after = (step % 9 == 0 ? 0 :
                     step % 9 == 1 ? 8 : int(rng() % 9));
        mf.change_capacity(id, after);
        operation_history.push_back("change_capacity " + to_string(id) + " " + to_string(after));
        edges[id].cap = after;
        verify(mf, n, s, t, edges, trial, step);
      }
      ++trial;
    }
  }
}
} // namespace

int main() {
  mt19937_64 rng(0xF10C0FFEE2026ULL);
  known_capacity_reduction_cut_regression();
  dynamic_cases(rng);
  return 0;
}
