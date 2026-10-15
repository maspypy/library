// Source: https://github.com/maspypy/library/blob/main/convex/larsch.hpp
// 制約きつい https://codeforces.com/contest/2183/problem/H
template <class T, class F>
class LARSCH {
  struct reduce_row;
  struct reduce_col;
  struct ColMap {
    const ColMap* parent = nullptr;
    const std::vector<int>* v = nullptr;

    inline int map(int j) const {
      int x = v ? (*v)[j] : j;
      return parent ? parent->map(x) : x;
    }
  };

  struct Eval {
    const F* f = nullptr;
    long long a = 1;  // row = a*i + b
    long long b = 0;
    const ColMap* cm = nullptr;

    inline T operator()(int i, int j) const {
      int ii = int(a * i + b);
      int jj = cm ? cm->map(j) : j;
      return (*f)(ii, jj);
    }
  };

  struct reduce_row {
    int n;
    Eval e;
    int cur_row = 0;
    int state = 0;
    std::unique_ptr<reduce_col> rec;

    reduce_row(int n_, const Eval& e_) : n(n_), e(e_) {
      int m = n / 2;
      if (m) {
        Eval eo = e;
        eo.b = e.a + e.b;
        eo.a = 2 * e.a;
        rec = std::make_unique<reduce_col>(m, eo);
      }
    }

    inline void reset() {
      cur_row = 0;
      state = 0;
      if (rec) rec->reset();
    }

    inline int get_argmin() {
      int i = cur_row++;
      if ((i & 1) == 0) {
        int prev = state;
        int next = (i + 1 == n ? n - 1 : rec->get_argmin());
        state = next;
        int ret = prev;
        for (int j = prev + 1; j <= next; ++j) {
          if (e(i, ret) > e(i, j)) ret = j;
        }
        return ret;
      } else {
        return (e(i, state) <= e(i, i)) ? state : i;
      }
    }
  };

  struct reduce_col {
    int n;
    Eval e;
    int cur_row = 0;
    std::vector<int> cols;
    ColMap cm_here;
    reduce_row rec;

    reduce_col(int n_, const Eval& e_)
        : n(n_),
          e(e_),
          cols(),
          cm_here{e.cm, &cols},
          rec(n_, Eval{e.f, e.a, e.b, &cm_here}) {
      cols.reserve(n);
    }

    inline void reset() {
      cur_row = 0;
      cols.clear();
      rec.reset();
    }

    inline void push_col(int j, int i) {
      while (!cols.empty()) {
        int size = (int)cols.size();
        if (size == i) break;
        int last = cols.back();
        if (e(size - 1, last) > e(size - 1, j))
          cols.pop_back();
        else
          break;
      }
      if ((int)cols.size() != n) cols.push_back(j);
    }

    inline int get_argmin() {
      int i = cur_row++;
      if (i == 0) {
        cols.clear();
        cols.push_back(0);
      } else {
        push_col(2 * i - 1, i);
        push_col(2 * i, i);
      }
      return cols[rec.get_argmin()];
    }
  };

  F f_;
  ColMap root_cm_;
  Eval root_eval_;
  std::unique_ptr<reduce_row> base_;

 public:
  explicit LARSCH(int n, F f)
      : f_(std::move(f)),
        root_cm_{nullptr, nullptr},
        root_eval_{&f_, 1, 0, &root_cm_} {
    base_ = std::make_unique<reduce_row>(n, root_eval_);
  }

  inline void reset() { base_->reset(); }
  inline int get_argmin() { return base_->get_argmin(); }
};
