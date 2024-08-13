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
        vc<int> dp_init(N + 1, infty<int>);
        dp_init[0] = 0;
        auto F = [&](int i, int a, int g) -> int { return min(a, g + 1); };
        auto G = [&](int i, int g, int a) -> int { return min(g, a); };

        vc<int> dp = palindrome_decomposition_dp<int, int>(S, dp_init,
                                                           infty<int>, F, G);
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
        vc<int> dp_init(N + 1);
        dp_init[0] = 1;
        auto F = [&](int i, int a, int g) -> int { return a + g; };
        auto G = [&](int i, int g, int a) -> int { return g + a; };

        vc<int> dp = palindrome_decomposition_dp<int, int>(S, dp_init, 0, F, G);
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