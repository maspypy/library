// template/beats_template.hpp
struct Beats {
  struct MonoX {
    struct X {
      bool fail;
      int size;
    };
    using value_type = X;
    static X op(X x, X y) {
      if (!x.size) return y;
      if (!y.size) return x;
      // fail は 0 のまま。
      return X({});
    }
    static constexpr X id() {
      // size を 0 にしておけばなんでもよい
      return X({});
    }
    static constexpr bool commute = ;
  };

  struct MonoA {
    // 作用モノイドは特に気にせず実装
    using value_type = ;
    using X = value_type;
    static X op(X x, X y) {}
    static constexpr X id() {}
    static constexpr bool commute = ;
  };

  using MX = MonoX;
  using MA = MonoA;
  using X_structure = MX;
  using A_structure = MA;
  using X = typename MX::value_type;
  using A = typename MA::value_type;

  template <typename T>
  static X from_element(T a) {
    // fail = 0, size = 1
    return X({});
  }

  static const X act(X x, const A& a) {
    assert(!x.fail);
    // 更新に失敗したら、x.fail = 1 として return x すること
  }
};
