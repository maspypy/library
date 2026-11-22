#include "my_template.hpp"
#include "other/io.hpp"
#include "string/suffix_automaton.hpp"

/*
対象: Suffix_Automaton<3> の build, next, len_range と Node::occ/min_pos/max_pos。
既存の number_of_substrings の検証は長さ和のみなので、
出現位置、遷移で表される最長suffix、同一objectの再buildを直接検証する。
独立 oracle: std::map<string, vector<int>> に全substringとその終端位置を列挙。
S の空文字、反復文字、最小周期、多種類の文字、非存在の検索文字列を含める。
乱数seed: 0x5AFF1A2026ULL。アルファベットは a,b,c のみ（off='a'）。
全探索は |S|<=6、randomは |S|<=45。ネットワークや入力を用いない。
*/
namespace {
using SA = Suffix_Automaton<3>;
void fail(const string& s, const string& q, const string& why) {
  cerr << "Suffix_Automaton S='" << s << "' query='" << q
       << "': " << why << '\n';
  abort();
}
map<string, vector<int>> enumerate(const string& s) {
  map<string, vector<int>> e;
  for (int r = 0; r <= int(s.size()); ++r) e[""].push_back(r);
  for (int l = 0; l < int(s.size()); ++l) {
    for (int r = l + 1; r <= int(s.size()); ++r) {
      e[s.substr(l, r - l)].push_back(r);
    }
  }
  return e;
}
void check_query(const SA& sa, const map<string, vector<int>>& e,
                 const string& s, const string& q) {
  pair<int, int> p = {0, 0};
  for (char c : q) p = sa.next(p, c - 'a');
  int best = 0;
  string chosen;
  for (int k = 1; k <= int(q.size()); ++k) {
    string suffix = q.substr(q.size() - k);
    if (e.count(suffix)) best = k, chosen = suffix;
  }
  if (p.second != best) fail(s, q, "longest matched suffix got=" +
                                  to_string(p.second) + " expected=" + to_string(best));
  if (p.first < 0 || p.first >= sa.n_node) fail(s, q, "invalid node index");
  auto [lo, hi] = sa.len_range(p.first);
  if (!(lo <= best && best < hi)) fail(s, q, "length not in node range");
  const auto& nd = sa.nodes[p.first];
  const auto& ends = e.at(chosen);
  if (nd.occ != int(ends.size()) || nd.min_pos != ends.front() ||
      nd.max_pos != ends.back()) {
    fail(s, q, "occ/min_pos/max_pos differs from substring enumeration, node=" +
                    to_string(p.first));
  }
}
void check_source(SA& sa, const string& s, mt19937_64& rng) {
  sa.build(s, 'a');
  auto e = enumerate(s);
  if (int(sa.pos.size()) != int(s.size()) + 1 ||
      int(sa.nodes.size()) != sa.n_node) fail(s, "", "size inconsistency");
  if (sa.nodes[0].occ != int(s.size()) + 1 ||
      sa.nodes[0].min_pos != 0 || sa.nodes[0].max_pos != int(s.size()))
    fail(s, "", "root endpos is inconsistent");
  ll distinct = 0;
  for (int i = 1; i < sa.n_node; ++i) {
    auto [l, r] = sa.len_range(i);
    if (!(1 <= l && l < r)) fail(s, "", "invalid state length range");
    distinct += r - l;
    if (!(0 <= sa.nodes[i].link && sa.nodes[i].link < i))
      fail(s, "", "suffix-link topological order");
  }
  if (distinct != ll(e.size()) - 1) fail(s, "", "distinct substring count");
  for (const auto& [word, ends] : e) {
    // substringが存在する場合、best=word.size()で、endpos情報を直接比較できる。
    check_query(sa, e, s, word);
  }
  for (int t = 0; t < 45; ++t) {
    string q;
    int qn = int(rng() % 25);
    for (int i = 0; i < qn; ++i) q += char('a' + rng() % 3);
    check_query(sa, e, s, q);
  }
}
void exhaustive(SA& sa, int n, string& s, mt19937_64& rng) {
  if (int(s.size()) == n) {
    check_source(sa, s, rng);
    return;
  }
  for (char c = 'a'; c <= 'c'; ++c) {
    s.push_back(c);
    exhaustive(sa, n, s, rng);
    s.pop_back();
  }
}
} // namespace

int main() {
  mt19937_64 rng(0x5AFF1A2026ULL);
  SA sa;
  for (int n = 0; n <= 6; ++n) {
    string s;
    exhaustive(sa, n, s, rng);
  }
  for (int rep = 0; rep < 180; ++rep) {
    int n = int(rng() % 46);
    string s;
    for (int i = 0; i < n; ++i) s += char('a' + rng() % 3);
    check_source(sa, s, rng);
  }
  return 0;
}
