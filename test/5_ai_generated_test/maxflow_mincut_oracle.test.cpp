#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/maxflow.hpp"

/*
対象: flow/maxflow.hpp の add/flow/cut、静的な小グラフの最大流・最小カット。
AOJ等の既存テストは問題別入力であり、全s-tカットとの比較は実施していない。
独立oracle: source側の全頂点部分集合を列挙してカット容量を直接計算。
平行辺・0容量・逆向き容量・任意のsource/sinkを検証する。
n=2..7、非負小容量、自己ループなし、seed=0xF10C0FFEE2026ULL。
*/

namespace {
struct InputEdge {
  int u, v, cap, rev;
};
void fail(int n, int trial, int operation, const string& why) {
  cerr << "MaxFlow n=" << n << " trial=" << trial
       << " op=" << operation << " : " << why << '\n';
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
void static_cases(mt19937_64& rng) {
  int trial = 0;
  for (int n = 2; n <= 7; ++n) {
    for (int rep = 0; rep < 250; ++rep) {
      int s = int(rng() % n), t = int(rng() % n);
      if (t == s) t = (t + 1) % n;
      MaxFlow<int> mf(n, s, t);
      vector<InputEdge> edges;
      int m = int(rng() % 16);
      for (int i = 0; i < m; ++i) {
        int u = int(rng() % n), v = int(rng() % (n - 1));
        if (v >= u) ++v;
        int cap = int(rng() % 7), rev = int(rng() % 4);
        mf.add(u, v, cap, rev);
        edges.push_back({u, v, cap, rev});
      }
      verify(mf, n, s, t, edges, trial++, -1);
    }
  }
}
} // namespace

int main() {
  mt19937_64 rng(0xF10C0FFEE2026ULL);
  static_cases(rng);
  return 0;
}
