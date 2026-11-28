// maspy-ai-test: expand
#include "my_template.hpp"
#include "string/suffix_array.hpp"

// Suffix_Array の lcp と lcp_range を全 3 種類のRMQで照合する。
// 元の整数列の接尾辞を直接ソートし、LCPは1文字ずつ比較する。
// lcp_range(i,k) は長さkの接頭辞が実際に取れる 0<=k<=N-i に限定。
// 3値の長さ1..7を全列挙し、静的区間積のブロック境界をまたぐ長さも追加。
// stringはunsigned charとして比較。NUL・128・255の並びと負の整数を使う。

namespace {
using Seq = vc<int>;
long long checks = 0, inputs = 0;

void require(bool ok, const Seq& s, int backend, bool bytes, const char* api,
             int i = -1, int j = -1, int got_l = 0, int got_r = 0,
             int want_l = 0, int want_r = 0) {
  if (ok) return;
  cerr << api << " backend=" << backend << " bytes=" << bytes
       << " i=" << i << " j=" << j << " got=" << got_l << ',' << got_r
       << " expected=" << want_l << ',' << want_r << " input:";
  for (auto x : s) cerr << ' ' << x;
  cerr << '\n';
  abort();
}

template<int Mode, class Input>
void check(const Input& data, const Seq& s, const Seq& order, const vvc<int>& lcs,
           const vc<vc<pair<int, int>>>& ranges, bool bytes) {
  Suffix_Array<Mode> obj(data);
  int n = int(s.size());
  require(obj.SA == order, s, Mode, bytes, "SA");
  for (int k = 0; k < n; ++k) {
    require(obj.ISA[order[k]] == k, s, Mode, bytes, "ISA", k);
  }
  if (bytes) {
    // lcp_range自体が遅延構築を行う経路。整数列では先にlcpを呼ぶ。
    auto got = obj.lcp_range(n - 1, 0);
    require(got == pair<int, int>{0, n}, s, Mode, bytes, "first lcp_range",
            n - 1, 0, got.first, got.second, 0, n);
    ++checks;
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      int got = obj.lcp(i, j);
      require(got == lcs[i][j], s, Mode, bytes, "lcp", i, j, got, 0, lcs[i][j], 0);
      ++checks;
    }
    if (i == n) continue;
    for (int k = 0; k <= n - i; ++k) {
      auto got = obj.lcp_range(i, k);
      auto want = ranges[i][k];
      require(got == want, s, Mode, bytes, "lcp_range", i, k,
              got.first, got.second, want.first, want.second);
      ++checks;
    }
  }
}

template<class Input>
void test(const Input& data, const Seq& s, bool bytes) {
  ++inputs;
  int n = int(s.size());
  Seq order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return lexicographical_compare(s.begin()+i, s.end(), s.begin()+j, s.end());
  });

  vvc<int> lcs(n+1, vc<int>(n+1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int k = 0;
      while (i+k < n && j+k < n && s[i+k] == s[j+k]) ++k;
      lcs[i][j] = k;
    }
  }
  vc<vc<pair<int, int>>> ranges(n);
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k <= n-i; ++k) {
      int l = n, r = 0;
      for (int j = 0; j < n; ++j) {
        if (lcs[i][order[j]] >= k) l = min(l, j), r = max(r, j+1);
      }
      ranges[i].emplace_back(l, r);
    }
  }

  check<0>(data, s, order, lcs, ranges, bytes);
  check<1>(data, s, order, lcs, ranges, bytes);
  check<2>(data, s, order, lcs, ranges, bytes);
}

void test_symbols(const Seq& symbols) {
  const array<int, 3> ints{INT_MIN, -17, INT_MAX}, bytes{0, 128, 255};
  Seq a, b;
  string str;
  for (int i : symbols) {
    a.push_back(ints[i]);
    b.push_back(bytes[i]);
    str.push_back(static_cast<char>(bytes[i]));
  }
  test(a, a, false);
  test(str, b, true);
}
}  // namespace

int main() {
  for (int n = 1, limit = 3; n <= 7; ++n, limit *= 3) {
    for (int id = 0; id < limit; ++id) {
      Seq symbols(n);
      int t = id;
      for (int& x : symbols) x = t % 3, t /= 3;
      test_symbols(symbols);
    }
  }
  for (int n : {15, 16, 17, 31, 32, 33, 63, 64, 65, 97}) {
    Seq symbols(n, 2);
    test_symbols(symbols);
    for (int i = 0; i < n; ++i) symbols[i] = (i % 7 < 6 ? i % 2 : 2);
    test_symbols(symbols);
  }
  cout << "suffix_array: " << inputs << " inputs, " << checks << " queries passed\n";
}
