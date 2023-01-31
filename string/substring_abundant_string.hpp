#include "string/run_length.hpp"

// 部分文字列の種類数が最大であるような 01 文字列の構成
// https://qoj.ac/contest/1096/problem/5434?v=1
// https://oeis.org/A094913
// https://www.mimuw.edu.pl/~rytter/MYPAPERS/paper.pdf
string substring_abundant_string(ll N) {
  ll N0 = N;
  N = 1;
  while ((1 << N) + (N - 1) < N0) ++N;

  string S = [&]() -> string {
    if (N == 1) return "01";
    if (N == 2) return "00110";

    auto SHIFT = [&](string x, string y) -> string {
      int n = len(x);
      x += x;
      FOR(i, n, n + n) {
        if (x.substr(i - len(y), len(y)) == y) { return x.substr(i - n, n); }
      }
      return "";
    };
    auto oplus = [&](string x, string y) -> string {
      int n = topbit(len(y));
      assert(len(x) == (1 << n) && len(y) == (1 << n));
      return x + SHIFT(y, x.substr(len(x) - n, n));
    };
    auto NOT = [&](string x) -> string {
      string y;
      for (auto&& s: x) y += (s == '0' ? '1' : '0');
      return y;
    };
    auto PSI = [&](string x) -> string {
      int a = 0;
      FOR(i, len(x)) {
        a ^= (x[i] - '0');
        x[i] = ('0' + a);
      }
      return x;
    };

    auto NEXT = [&](string x) -> string {
      x = PSI(x);
      return oplus(x, NOT(x));
    };

    auto otimes = [&](string x, string y) -> string {
      string t;
      FOR(topbit(len(x))) t += '0';
      x = SHIFT(x, t);
      y = SHIFT(y, t);
      rotate(x.begin(), x.end() - len(t), x.end());
      rotate(y.begin(), y.end() - len(t), y.end());

      int n = len(x);
      int x0 = 0, x1 = 0, y0 = 0, y1 = 1;
      for (auto&& [k, v]: run_length(x)) {
        if (k == '0') chmax(x0, v);
        if (k == '1') chmax(x1, v);
      }
      for (auto&& [k, v]: run_length(y)) {
        if (k == '0') chmax(y0, v);
        if (k == '1') chmax(y1, v);
      }
      string X, Y;
      for (auto&& [k, v]: run_length(x)) {
        if (k == '0' && v < x0) { X += string(v, k); }
        if (k == '0' && v == x0) { X += string(v - 1, k); }
        if (k == '1' && v < x1) { X += string(v, k); }
        if (k == '1' && v == x1) { X += string(v + 1, k); }
      }
      for (auto&& [k, v]: run_length(y)) {
        if (k == '0' && v < y0) { Y += string(v, k); }
        if (k == '0' && v == y0) { Y += string(v + 1, k); }
        if (k == '1' && v < y1) { Y += string(v, k); }
        if (k == '1' && v == y1) { Y += string(v - 1, k); }
      }
      return X + Y;
    };

    string x = "0011", y = "0011";
    FOR(i, 2, N - 1) {
      string t;
      FOR(i) t += '1';
      x = SHIFT(x, t);
      x = NEXT(x);
      y = SHIFT(y, t);
      y = NOT(NEXT(y));
    }
    x = otimes(x, y);
    FOR(i, N - 1) x += x[i];
    return x;
  }();
  return S.substr(0, N0);
}