// Source: https://github.com/maspypy/library/blob/main/string/split.hpp
vc<string> split(string S, string seps = " ,") {
  vc<string> res = {""};
  for (auto&& s : S) {
    if (count(all(seps), s))
      res.eb("");
    else
      res.back() += s;
  }
  return res;
}
