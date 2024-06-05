#include "string/lyndon.hpp"

// ANS[i] := length of lex-min suffix of S[0,i)
vc<int> lex_min_suffix_for_all_prefix(string S) {
  int N = len(S);
  Incremental_Lyndon_Factorization<char> LD;
  FOR(i, N) LD.add(S[i]);
  return LD.minimum_suffix_len;
}