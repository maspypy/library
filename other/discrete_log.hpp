// log_a b の計算
// 「*」 が定義されたクラス、ハッシュ関数 H を持たせる
// lb 以上の解をかえす
template <typename X>
ll discrete_log(X a, X b, ll LIM, function<ll(X)> H, int lb = 0) {
  {
    int n = lb;
    X p = a;
    while (n) {
      if (n & 1) b /= p;
      p *= p;
      n /= 2;
    }
  }

  ll K = 1;
  while (K * K < LIM) ++K;

  unordered_map<ll, int> MP;
  MP.reserve(K + 1);
  X p = 1;
  FOR(k, K + 1) {
    auto key = H(p);
    if (!MP.count(key)) MP[key] = k;
    if (k != K) p = p * a;
  }
  p = X(1) / p;
  FOR(k, K + 1) {
    auto key = H(b);
    if (MP.count(key)) return k * K + MP[key] + lb;
    b *= p;
  }
  return -1;
}
