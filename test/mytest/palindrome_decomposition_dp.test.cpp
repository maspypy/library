#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "string/palindrome_decomposition_dp.hpp"

void test_min_palindrome_decomposition() {
  FOR(N, 30) {
    FOR(K, 1, 5) {
      FOR(10) {
        string S;
        FOR(N) {
          char c = 'a' + RNG(0, K);
          S += c;
        }
        vv(int, is_pal, N + 1, N + 1);
        FOR_R(L, N + 1) {
          FOR(R, N + 1) {
            if (R - L <= 1) {
              is_pal[L][R] = 1;
              continue;
            }
            is_pal[L][R] = (S[L] == S[R - 1]) && is_pal[L + 1][R - 1];
          }
        }
        vc<int> DP(N + 1, infty<int>);
        DP[0] = 0;
        FOR(R, 1, N + 1) {
          FOR(L, R) {
            if (is_pal[L][R]) chmin(DP[R], DP[L] + 1);
          }
        }
        vc<int> dp = palindrome_decomposition_dp<int>(
            S, infty<int>, 0, [&](int x, int y) -> int { return min(x, y); },
            [&](int x) -> int { return x + 1; });
        assert(dp == DP);
      }
    }
  }
}

void test_cnt_palindrome_decomposition() {
  FOR(N, 30) {
    FOR(K, 1, 5) {
      FOR(10) {
        string S;
        FOR(N) {
          char c = 'a' + RNG(0, K);
          S += c;
        }
        vv(int, is_pal, N + 1, N + 1);
        FOR_R(L, N + 1) {
          FOR(R, N + 1) {
            if (R - L <= 1) {
              is_pal[L][R] = 1;
              continue;
            }
            is_pal[L][R] = (S[L] == S[R - 1]) && is_pal[L + 1][R - 1];
          }
        }
        vc<int> DP(N + 1, 0);
        DP[0] = 1;
        FOR(R, 1, N + 1) {
          FOR(L, R) {
            if (is_pal[L][R]) DP[R] += DP[L];
          }
        }
        vc<int> dp = palindrome_decomposition_dp<int>(
            S, 0, 1, [&](int x, int y) -> int { return x + y; },
            [&](int x) -> int { return x; });
        assert(dp == DP);
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_min_palindrome_decomposition();
  test_cnt_palindrome_decomposition();
  solve();
  return 0;
}
