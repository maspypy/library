template <typename STRING = string, typename CHAR = char>
vc<pair<CHAR, int>> run_length(STRING& S) {
  vc<pair<CHAR, int>> res;
  for (auto&& x: S) {
    if (res.empty() || res.back().fi != x) { res.emplace_back(x, 0); }
    res.back().se++;
  }
  return res;
}
