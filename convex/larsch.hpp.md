---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://noshi91.github.io/Library/algorithm/larsch.cpp.html
  bundledCode: "#line 2 \"convex/larsch.hpp\"\n\n// https://noshi91.github.io/Library/algorithm/larsch.cpp.html\n\
    template <class T>\nclass LARSCH {\n  struct reduce_row;\n  struct reduce_col;\n\
    \n  struct reduce_row {\n    int n;\n    std::function<T(int, int)> f;\n    int\
    \ cur_row;\n    int state;\n    std::unique_ptr<reduce_col> rec;\n\n    reduce_row(int\
    \ n_) : n(n_), f(), cur_row(0), state(0), rec() {\n      const int m = n / 2;\n\
    \      if (m != 0) { rec = std::make_unique<reduce_col>(m); }\n    }\n\n    void\
    \ set_f(std::function<T(int, int)> f_) {\n      f = f_;\n      if (rec) {\n  \
    \      rec->set_f([&](int i, int j) -> T { return f(2 * i + 1, j); });\n     \
    \ }\n    }\n\n    int get_argmin() {\n      const int cur_row_ = cur_row;\n  \
    \    cur_row += 1;\n      if (cur_row_ % 2 == 0) {\n        const int prev_argmin\
    \ = state;\n        const int next_argmin = [&]() {\n          if (cur_row_ +\
    \ 1 == n) {\n            return n - 1;\n          } else {\n            return\
    \ rec->get_argmin();\n          }\n        }();\n        state = next_argmin;\n\
    \        int ret = prev_argmin;\n        for (int j = prev_argmin + 1; j <= next_argmin;\
    \ j += 1) {\n          if (f(cur_row_, ret) > f(cur_row_, j)) { ret = j; }\n \
    \       }\n        return ret;\n      } else {\n        if (f(cur_row_, state)\
    \ <= f(cur_row_, cur_row_)) {\n          return state;\n        } else {\n   \
    \       return cur_row_;\n        }\n      }\n    }\n  };\n\n  struct reduce_col\
    \ {\n    int n;\n    std::function<T(int, int)> f;\n    int cur_row;\n    std::vector<int>\
    \ cols;\n    reduce_row rec;\n\n    reduce_col(int n_) : n(n_), f(), cur_row(0),\
    \ cols(), rec(n) {}\n\n    void set_f(std::function<T(int, int)> f_) {\n     \
    \ f = f_;\n      rec.set_f([&](int i, int j) -> T { return f(i, cols[j]); });\n\
    \    }\n\n    int get_argmin() {\n      const int cur_row_ = cur_row;\n      cur_row\
    \ += 1;\n      const auto cs = [&]() -> std::vector<int> {\n        if (cur_row_\
    \ == 0) {\n          return {{0}};\n        } else {\n          return {{2 * cur_row_\
    \ - 1, 2 * cur_row_}};\n        }\n      }();\n      for (const int j: cs) {\n\
    \        while ([&]() {\n          const int size = cols.size();\n          return\
    \ size != cur_row_ && f(size - 1, cols.back()) > f(size - 1, j);\n        }())\
    \ {\n          cols.pop_back();\n        }\n        if (cols.size() != n) { cols.push_back(j);\
    \ }\n      }\n      return cols[rec.get_argmin()];\n    }\n  };\n\n  std::unique_ptr<reduce_row>\
    \ base;\n\npublic:\n  LARSCH(int n, std::function<T(int, int)> f)\n      : base(std::make_unique<reduce_row>(n))\
    \ {\n    base->set_f(f);\n  }\n\n  int get_argmin() { return base->get_argmin();\
    \ }\n};\n"
  code: "#pragma once\n\n// https://noshi91.github.io/Library/algorithm/larsch.cpp.html\n\
    template <class T>\nclass LARSCH {\n  struct reduce_row;\n  struct reduce_col;\n\
    \n  struct reduce_row {\n    int n;\n    std::function<T(int, int)> f;\n    int\
    \ cur_row;\n    int state;\n    std::unique_ptr<reduce_col> rec;\n\n    reduce_row(int\
    \ n_) : n(n_), f(), cur_row(0), state(0), rec() {\n      const int m = n / 2;\n\
    \      if (m != 0) { rec = std::make_unique<reduce_col>(m); }\n    }\n\n    void\
    \ set_f(std::function<T(int, int)> f_) {\n      f = f_;\n      if (rec) {\n  \
    \      rec->set_f([&](int i, int j) -> T { return f(2 * i + 1, j); });\n     \
    \ }\n    }\n\n    int get_argmin() {\n      const int cur_row_ = cur_row;\n  \
    \    cur_row += 1;\n      if (cur_row_ % 2 == 0) {\n        const int prev_argmin\
    \ = state;\n        const int next_argmin = [&]() {\n          if (cur_row_ +\
    \ 1 == n) {\n            return n - 1;\n          } else {\n            return\
    \ rec->get_argmin();\n          }\n        }();\n        state = next_argmin;\n\
    \        int ret = prev_argmin;\n        for (int j = prev_argmin + 1; j <= next_argmin;\
    \ j += 1) {\n          if (f(cur_row_, ret) > f(cur_row_, j)) { ret = j; }\n \
    \       }\n        return ret;\n      } else {\n        if (f(cur_row_, state)\
    \ <= f(cur_row_, cur_row_)) {\n          return state;\n        } else {\n   \
    \       return cur_row_;\n        }\n      }\n    }\n  };\n\n  struct reduce_col\
    \ {\n    int n;\n    std::function<T(int, int)> f;\n    int cur_row;\n    std::vector<int>\
    \ cols;\n    reduce_row rec;\n\n    reduce_col(int n_) : n(n_), f(), cur_row(0),\
    \ cols(), rec(n) {}\n\n    void set_f(std::function<T(int, int)> f_) {\n     \
    \ f = f_;\n      rec.set_f([&](int i, int j) -> T { return f(i, cols[j]); });\n\
    \    }\n\n    int get_argmin() {\n      const int cur_row_ = cur_row;\n      cur_row\
    \ += 1;\n      const auto cs = [&]() -> std::vector<int> {\n        if (cur_row_\
    \ == 0) {\n          return {{0}};\n        } else {\n          return {{2 * cur_row_\
    \ - 1, 2 * cur_row_}};\n        }\n      }();\n      for (const int j: cs) {\n\
    \        while ([&]() {\n          const int size = cols.size();\n          return\
    \ size != cur_row_ && f(size - 1, cols.back()) > f(size - 1, j);\n        }())\
    \ {\n          cols.pop_back();\n        }\n        if (cols.size() != n) { cols.push_back(j);\
    \ }\n      }\n      return cols[rec.get_argmin()];\n    }\n  };\n\n  std::unique_ptr<reduce_row>\
    \ base;\n\npublic:\n  LARSCH(int n, std::function<T(int, int)> f)\n      : base(std::make_unique<reduce_row>(n))\
    \ {\n    base->set_f(f);\n  }\n\n  int get_argmin() { return base->get_argmin();\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/larsch.hpp
  requiredBy: []
  timestamp: '2022-12-03 09:41:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/larsch.hpp
layout: document
redirect_from:
- /library/convex/larsch.hpp
- /library/convex/larsch.hpp.html
title: convex/larsch.hpp
---
