#pragma once

// https://noshi91.github.io/Library/algorithm/larsch.cpp.html
template <class T>
class LARSCH {
  struct reduce_row;
  struct reduce_col;

  struct reduce_row {
    int n;
    std::function<T(int, int)> f;
    int cur_row;
    int state;
    std::unique_ptr<reduce_col> rec;

    reduce_row(int n_) : n(n_), f(), cur_row(0), state(0), rec() {
      const int m = n / 2;
      if (m != 0) { rec = std::make_unique<reduce_col>(m); }
    }

    void set_f(std::function<T(int, int)> f_) {
      f = f_;
      if (rec) {
        rec->set_f([&](int i, int j) -> T { return f(2 * i + 1, j); });
      }
    }

    int get_argmin() {
      const int cur_row_ = cur_row;
      cur_row += 1;
      if (cur_row_ % 2 == 0) {
        const int prev_argmin = state;
        const int next_argmin = [&]() {
          if (cur_row_ + 1 == n) {
            return n - 1;
          } else {
            return rec->get_argmin();
          }
        }();
        state = next_argmin;
        int ret = prev_argmin;
        for (int j = prev_argmin + 1; j <= next_argmin; j += 1) {
          if (f(cur_row_, ret) > f(cur_row_, j)) { ret = j; }
        }
        return ret;
      } else {
        if (f(cur_row_, state) <= f(cur_row_, cur_row_)) {
          return state;
        } else {
          return cur_row_;
        }
      }
    }
  };

  struct reduce_col {
    int n;
    std::function<T(int, int)> f;
    int cur_row;
    std::vector<int> cols;
    reduce_row rec;

    reduce_col(int n_) : n(n_), f(), cur_row(0), cols(), rec(n) {}

    void set_f(std::function<T(int, int)> f_) {
      f = f_;
      rec.set_f([&](int i, int j) -> T { return f(i, cols[j]); });
    }

    int get_argmin() {
      const int cur_row_ = cur_row;
      cur_row += 1;
      const auto cs = [&]() -> std::vector<int> {
        if (cur_row_ == 0) {
          return {{0}};
        } else {
          return {{2 * cur_row_ - 1, 2 * cur_row_}};
        }
      }();
      for (const int j: cs) {
        while ([&]() {
          const int size = cols.size();
          return size != cur_row_ && f(size - 1, cols.back()) > f(size - 1, j);
        }()) {
          cols.pop_back();
        }
        if (cols.size() != n) { cols.push_back(j); }
      }
      return cols[rec.get_argmin()];
    }
  };

  std::unique_ptr<reduce_row> base;

public:
  LARSCH(int n, std::function<T(int, int)> f)
      : base(std::make_unique<reduce_row>(n)) {
    base->set_f(f);
  }

  int get_argmin() { return base->get_argmin(); }
};
