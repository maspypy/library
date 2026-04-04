
// KMP[n]: longest border length of S[0,n) or 0.
// https://codeforces.com/contest/2209/problem/E
template <typename STRING>
vector<int> kmp(const STRING& S) {
  int N = len(S);
  vc<int> ANS(N + 1);
  FOR(n, 2, N + 1) {
    int k = ANS[n - 1];
    while (k > 0 && S[k] != S[n - 1]) k = ANS[k];
    ANS[n] = k + (S[k] == S[n - 1]);
  }
  return ANS;
}
