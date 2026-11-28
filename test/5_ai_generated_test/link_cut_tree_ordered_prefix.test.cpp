// TST-0026: link/cut を挟んだ森林上の非可換な経路 prefix 探索。
// 隣接行列から BFS で唯一の経路を復元し、頂点ラベルを順番に連結する。
// check は「目標文字列の prefix かつ長さ上限以下」。延長で false から true
// には戻らない。最初の頂点で失敗・中途の文字不一致・全経路成功を両方向で確認。
// evert を挟まず根と親を照合し、探索や link/cut の根に対する副作用も確認する。
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/ds/link_cut_tree.hpp"
#include "graph/ds/lct_node_monoid.hpp"

struct Concat {
  using value_type = std::string;
  static value_type id() { return {}; }
  static value_type op(const value_type& a, const value_type& b) { return a + b; }
  static constexpr bool commute = false;
};

int main() {
  constexpr unsigned seed = 772902;
  std::mt19937 gen(seed);
  long long checks = 0;
  for (int round = 0; round < 121; ++round) {
    int n = 1 + round % 13;
    Link_Cut_Tree<LCT_Node_Monoid<Concat>> t(n);
    std::vector<std::vector<bool>> edge(n, std::vector<bool>(n));
    std::vector<char> label(n);
    std::vector<int> root(n), q;
    std::iota(root.begin(), root.end(), 0);
    auto bfs = [&](int s) {
      std::vector<int> par(n, -2);
      q.assign(1, s);
      par[s] = -1;
      for (size_t i = 0; i < q.size(); ++i)
        for (int j = 0; j < n; ++j)
          if (edge[q[i]][j] && par[j] == -2) {
            par[j] = q[i];
            q.push_back(j);
          }
      return par;
    };
    auto reroot = [&](int s) {
      bfs(s);
      for (int x : q) root[x] = s;
    };
    auto assign = [&](int s) {
      label[s] = 'a' + gen() % 4;
      t.set(s, std::string(1, label[s]));
      reroot(s);
    };
    for (int i = 0; i < n; ++i) assign(i);
    for (int step = 0; step < 160; ++step) {
      int a = gen() % n, b = gen() % n;
      auto eq = [&](auto got, auto want, const char* phase) {
        ++checks;
        if (got != want) {
          std::cerr << "seed=" << seed << " round=" << round << " n=" << n
                    << " step=" << step << " a=" << a << " b=" << b
                    << " " << phase << " got=" << got << " want=" << want << '\n';
          std::abort();
        }
      };
      switch (gen() % 5) {
        case 0: case 1:
          if (root[a] != root[b]) {
            int r = root[a];
            t.link(a, b);
            edge[a][b] = edge[b][a] = true;
            reroot(r);
          }
          break;
        case 2: {
          std::vector<std::pair<int, int>> edges;
          for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
              if (edge[i][j]) edges.emplace_back(i, j);
          if (!edges.empty()) {
            auto [x, y] = edges[gen() % edges.size()];
            t.cut(x, y);
            edge[x][y] = edge[y][x] = false;
            reroot(x);
            reroot(y);
            eq(t.get_root(x), x, "cut root x");
            eq(t.get_root(y), y, "cut root y");
          }
          break;
        }
        case 3: assign(a); break;
        case 4: t.evert(a); reroot(a); break;
      }
      // 現在の成分から終点を選ぶ。孤立点でも長さ1のパスを調べる。
      bfs(a);
      b = q[gen() % q.size()];
      for (int dir = 0; dir < 2; ++dir) {
        auto par = bfs(a);
        std::vector<int> path;
        for (int x = b; x != -1; x = par[x]) path.push_back(x);
        std::reverse(path.begin(), path.end());
        std::string word;
        for (int x : path) word += label[x];
        eq(t.get_root(b), root[b], "before path");
        eq(t.prod_path(a, b), word, "ordered product");
        reroot(a);
        std::string target = word;
        for (size_t k = 0; k <= path.size(); ++k) {
          eq(t.max_path([&](const std::string& s) {
            return s.size() <= k && target.compare(0, s.size(), s) == 0;
          }, a, b), k ? path[k - 1] : -1, "prefix cap");
        }
        size_t k = gen() % path.size();
        target[k] = 'z';  // 長さではなく文字不一致で打ち切る
        eq(t.max_path([&](const std::string& s) {
          return target.compare(0, s.size(), s) == 0;
        }, a, b), k ? path[k - 1] : -1, "prefix mismatch");
        eq(t.get_root(b), a, "search root");
        eq(t.get_parent(b), path.size() == 1 ? -1 : path[path.size() - 2], "parent after search");
        eq(t.get_root(b), a, "parent preserves root");
        std::swap(a, b);
      }
    }
  }
  std::cout << "LCT checks=" << checks << '\n';
}
