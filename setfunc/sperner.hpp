
namespace Sperner {
// Symmetric Chain Decomposition

// return: 初期集合, 足していくもの, 何番目
template <typename F>
tuple<vc<int>, vc<int>, int> get_chain(int N, F check) {
  vc<int> S, ADD;
  int rk = 0;
  for (int i = 0; i < N; ++i) {
    if (check(i)) {
      if (rk == int(ADD.size())) {
        ADD.emplace_back(i);
        ++rk;
      } else {
        ADD.pop_back();
        S.emplace_back(i);
      }
    } else {
      ADD.emplace_back(i);
    }
  }
  return {S, ADD, rk};
}

template <typename F>
int rm_element(int N, F check) {
  int ans = -1, rk = 0, length = 0;
  for (int i = 0; i < N; ++i) {
    if (check(i)) {
      if (rk == length) {
        ans = i;
        ++length, ++rk;
      } else {
        --length;
      }
    } else {
      ++length;
    }
  }
  return ans;
}

template <typename F>
int add_element(int N, F check) {
  int ans = -1, rk = 0, length = 0;
  for (int i = 0; i < N; ++i) {
    if (check(i)) {
      if (rk == length) {
        ++length, ++rk;
      } else {
        --length;
      }
    } else {
      if (rk == length) ans = i;
      ++length;
    }
  }
  return (rk < length ? ans : -1);
}
};  // namespace Sperner
