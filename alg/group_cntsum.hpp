template <typename E = long long>
struct Group_CntSum {
  using value_type = pair<E, E>;
  using X = value_type;
  static constexpr X op(const X &x, const X &y) {
    return {x.fi + y.fi, x.se + y.se};
  }
  static constexpr X inverse(const X &x) { return {-x.fi, -x.se}; }
  static constexpr X unit() { return {0, 0}; }
  static constexpr bool commute = true;
};
