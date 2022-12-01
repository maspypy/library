#pragma once

template <class Group>
struct Group_Reverse {
  using value_type = typename Group::value_type;
  using X = value_type;
  static constexpr X op(const X &x, const X &y) { return Group::op(y, x); }
  static constexpr X inverse(const X &x) { return Group::inverse(x); }
  static constexpr X unit() { return Group::unit(); }
  static const bool commute = Group::commute;
};
