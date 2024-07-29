template <typename STRING = string>
vc<pair<typename STRING::value_type, int>> run_length(STRING& S) {
  vc<pair<typename STRING::value_type, int>> res;
  for (auto&& x: S) {
    if (res.empty() || res.back().fi != x) { res.emplace_back(x, 0); }
    res.back().se++;
  }
  return res;
}
