vc<string> split(string S, char sep = ',') {
  vc<string> res = {""};
  for (auto&& s: S) {
    if (s == sep)
      res.eb("");
    else
      res.back() += s;
  }
  return res;
}

vc<string> split(string S, string seps = " ,") {
  vc<string> res = {""};
  for (auto&& s: S) {
    if (count(all(seps), s))
      res.eb("");
    else
      res.back() += s;
  }
  return res;
}
