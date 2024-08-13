#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/stern_brocot_tree.hpp"

void solve() {
  using SBT = Stern_Brocot_Tree;
  STR(S);
  if (S == "DECODE_PATH") {
    INT(n);
    vi A;
    FOR(n) {
      CHAR(s);
      INT(x);
      if (A.empty() && s == 'L') { A.eb(0); }
      A.eb(x);
    }
    auto [a, b] = SBT::from_path(A);
    print(a, b);
  }
  if (S == "ENCODE_PATH") {
    LL(a, b);
    vi A = SBT::get_path({a, b});
    vc<string> ANS;
    FOR(i, len(A)) {
      if (A[i] == 0) continue;
      string x = (i % 2 == 0 ? "R" : "L");
      ANS.eb(x);
      ANS.eb(to_string(A[i]));
    }
    print(len(ANS) / 2, ANS);
  }
  if (S == "LCA") {
    LL(a, b, c, d);
    auto [e, f] = SBT::LCA({a, b}, {c, d});
    print(e, f);
  }
  if (S == "ANCESTOR") {
    LL(k, a, b);
    auto [x, y] = SBT::LA({a, b}, k);
    if (x == -1) {
      print(-1);
    } else {
      print(x, y);
    }
  }
  if (S == "RANGE") {
    LL(a, b);
    auto [x, y] = SBT::range({a, b});
    print(x, y);
  }
}

signed main() {
  INT(T);
  FOR(T)
  solve();
  return 0;
}