// return : (fx, x)
// f が評価される回数：2 + iter
// 幅が 1/phi^{iter} 倍になる. iter = 44: 1e-9.
template <typename Re, bool MINIMIZE, typename F>
pair<Re, Re> golden_search(F f, Re lx, Re rx, int iter = 50) {
  assert(lx <= rx);
  Re inv_phi = (sqrtl(5) - 1.0) * 0.5;
  Re inv_phi_2 = inv_phi * inv_phi;
  Re x1 = lx, x4 = rx;
  Re x2 = x1 + inv_phi_2 * (x4 - x1);
  Re x3 = x1 + inv_phi * (x4 - x1);
  Re y2 = f(x2), y3 = f(x3);
  auto comp = [&](Re a, Re b) -> bool {
    if constexpr (MINIMIZE)
      return a < b;
    else
      return a > b;
  };

  FOR(iter) {
    if (comp(y2, y3)) {
      x4 = x3, x3 = x2, y3 = y2;
      x2 = x1 + inv_phi_2 * (x4 - x1);
      y2 = f(x2);
    } else {
      x1 = x2, x2 = x3, y2 = y3;
      x3 = x1 + inv_phi * (x4 - x1);
      y3 = f(x3);
    }
  }
  return (comp(y2, y3) ? pair<Re, Re>{y2, x2} : pair<Re, Re>{y3, x3});
}