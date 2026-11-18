#include "my_template.hpp"
#include "other/io.hpp"
#include "string/count_subsequence.hpp"

/*
対象: string/count_subsequence.hpp の count_subsequence<mint>(S)。
戻り値は空列も含む「異なる部分列」の個数 (出現位置の選び方ではない)。
独立オラクル: 全部分集合を列挙し、得られる要素列を std::set に保存する。
狙う不具合: 重複文字の数え過ぎ、空列の扱い、0や負値を含む汎用整数列、
std::string 内の NUL/非ASCII文字、mint の剰余演算時の違い。
剰余環は簡素な別実装 Mod17 を用い、期待値を全列挙の個数 mod 17 から得る。
長さ60の全異値は 2^60、長い全同値は n+1 という独立した既知式で検証。
固定seed=0xC0A11720261118ULL、全探索は長さ<=12に制限する。
*/

struct Mod17 {
  int v;
  Mod17(long long x = 0) : v(int((x % 17 + 17) % 17)) {}
  Mod17& operator+=(Mod17 y) { v = (v + y.v) % 17; return *this; }
  friend Mod17 operator-(Mod17 a, Mod17 b) { return Mod17(a.v - b.v); }
};

[[noreturn]] static void fail(const string& label, int trial, long long got,
                              long long want) {
  cerr << "count_subsequence mismatch " << label << " trial=" << trial
       << " got=" << got << " want=" << want << '\n';
  abort();
}

template <class Seq>
static long long brute(const Seq& s) {
  const int n = int(s.size());
  assert(n <= 12);
  set<vector<int>> st;
  for (int mask = 0; mask < (1 << n); ++mask) {
    vector<int> b;
    for (int i = 0; i < n; ++i) if (mask >> i & 1) b.push_back(int(s[i]));
    st.insert(move(b));
  }
  return st.size();
}

template <class Seq>
static void check(Seq s, const string& label, int trial) {
  const ll expected = brute(s);
  ll got = count_subsequence<ll>(s);
  if (got != expected) fail(label, trial, got, expected);
  int modded = count_subsequence<Mod17>(s).v;
  if (modded != expected % 17) fail(label + " mod17", trial, modded, expected % 17);
}

int main() {
  mt19937_64 rng(0xC0A11720261118ULL);
  long long cases = 0;
  // 3値・長さ0..8の全文字列を検査する（3^9-1 / 2 個）。
  for (int n = 0; n <= 8; ++n) {
    int total = 1;
    for (int i = 0; i < n; ++i) total *= 3;
    for (int code = 0; code < total; ++code) {
      int x = code;
      vector<int> a(n);
      for (int& v : a) { v = x % 3 - 1; x /= 3; }
      check(a, "exhaustive integers", int(cases));
      ++cases;
    }
  }
  for (int trial = 0; trial < 1500; ++trial) {
    int n = int(rng() % 13);
    vector<int> a(n);
    for (int& x : a) x = int(rng() % 9) - 4;
    check(a, "random integers", trial);
    ++cases;
  }
  for (int trial = 0; trial < 500; ++trial) {
    const int n = int(rng() % 13);
    const unsigned char chars[] = {0, 1, 65, 127, 128, 255};
    string s;
    for (int i = 0; i < n; ++i) s.push_back(char(chars[rng() % 6]));
    check(s, "binary string", trial);
    ++cases;
  }
  // 容量上限でなく数理的期待値から確認する長いケース。
  vector<int> distinct(60);
  iota(distinct.begin(), distinct.end(), -29);
  if (count_subsequence<ll>(distinct) != (1LL << 60))
    fail("60 distinct", 0, count_subsequence<ll>(distinct), 1LL << 60);
  if (count_subsequence<Mod17>(distinct).v != (1LL << 60) % 17)
    fail("60 distinct mod17", 0, count_subsequence<Mod17>(distinct).v,
         (1LL << 60) % 17);
  vector<int> identical(100000, -7);
  if (count_subsequence<ll>(identical) != 100001)
    fail("100000 identical", 0, count_subsequence<ll>(identical), 100001);
  cerr << "PASS count_subsequence " << cases << " enumerated cases\n";
}
