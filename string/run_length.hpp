template <typename STRING = string>
vc<pair<typename STRING::value_type, ll>> run_length(STRING& S) {
  vc<pair<typename STRING::value_type, ll>> res;
  for (auto&& x: S) {
    if (res.empty() || res.back().fi != x) { res.emplace_back(x, 0); }
    res.back().se++;
  }
  return res;
}
