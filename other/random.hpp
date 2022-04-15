struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  ll operator()(ll a, ll b) {  // [a, b)
    uniform_int_distribution<ll> dist(a, b - 1);
    return dist(mt);
  }

  ll operator()(ll b) {  // [0, b)
    return (*this)(0, b);
  }
};