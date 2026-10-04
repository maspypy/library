template <typename STRING>
bool is_subsequence(const STRING& S, const STRING& T) {
  ll p = 0;
  for (auto&& s : S) {
    while (p < len(T) && T[p] != s) ++p;
    if (p == len(T)) return false;
    ++p;
  }
  return true;
}