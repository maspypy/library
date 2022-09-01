#define PROBLEM "https://atcoder.jp/contests/abc229/tasks/abc229_h"

#include "my_template.hpp"
#include "other/io.hpp"

#include "game/dyrational.hpp"

void solve() {
  using X = DyRational<ll>;

  map<string, X> MP;
  auto dfs = [&](auto& dfs, string& s) -> X {
    if (MP.count(s)) return MP[s];
    X left = -X::infinity();
    X right = X::infinity();
    // 白を選び、上に進める
    FOR(i, len(s) - 1) {
      if (s[i] == '.' && s[i + 1] == 'W') {
        swap(s[i], s[i + 1]);
        chmax(left, dfs(dfs, s));
        swap(s[i], s[i + 1]);
      }
    }
    // 黒を食べる
    FOR(i, len(s)) {
      if (s[i] == 'B') {
        s[i] = '.';
        chmax(left, dfs(dfs, s));
        s[i] = 'B';
      }
    }
    // 黒を選び、上に進める
    FOR(i, len(s) - 1) {
      if (s[i] == '.' && s[i + 1] == 'B') {
        swap(s[i], s[i + 1]);
        chmin(right, dfs(dfs, s));
        swap(s[i], s[i + 1]);
      }
    }
    // 白を食べる
    FOR(i, len(s)) {
      if (s[i] == 'W') {
        s[i] = '.';
        chmin(right, dfs(dfs, s));
        s[i] = 'W';
      }
    }
    assert(left < right);
    MP[s] = X::find(left, right);
    return MP[s];
  };

  LL(N);
  vc<string> G(N);
  FOR(i, N) {
    STR(S);
    FOR(j, N) { G[j] += S[j]; }
  }
  X x(0);
  FOR(i, N) x += dfs(dfs, G[i]);
  print(x > X(0) ? "Takahashi" : "Snuke");
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}