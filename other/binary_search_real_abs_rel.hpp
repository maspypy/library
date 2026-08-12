
// 絶対誤差または相対誤差を小さくするときに回数を頑張って減らす
// ok, ng が非負であることを仮定
template <typename F>
double binary_search_real_abs_rel(F check, double ok, double ng, double eps) {
  using Re = double;
  Re l, r;
  bool l_is_ok;
  if (ok > ng) {
    l = ng, r = ok, l_is_ok = false;
  } else {
    l = ok, r = ng, l_is_ok = true;
  }
  auto upd = [&](Re x) -> void { (check(x) ^ l_is_ok ? r : l) = x; };

  if (l <= 1 && 1 <= r) upd(1);

  if (1 <= l) {
    // 相対誤差を狙う
    while (r / l > 1.0 + eps) upd(sqrt(l) * sqrt(r));
    return sqrt(l) * sqrt(r);
  } else {
    // 絶対誤差を狙う
    while (r - l > eps) upd((l + r) / 2);
    return (l + r) / 2;
  }
}
