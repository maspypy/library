#pragma once

// composition of bitwise operation
// 0 -> a, -1 -> b
template <typename UINT>
struct Bitwise_Function {
  static_assert(is_same_v<UINT, u32> || is_same_v<UINT, u64>);
  using value_type = pair<UINT, UINT>;
  using X = value_type;
  static X op(X x, X y) { return {eval(y, x.fi), eval(y, x.se)}; }
  static UINT eval(X f, UINT x) { return (f.fi & (~x)) | (f.se & x); }
  static X func_or(UINT x) { return {x, UINT(-1)}; }
  static X func_and(UINT x) { return {0, x}; }
  static X func_xor(UINT x) { return {x, UINT(-1) ^ x}; }
  static constexpr X unit() { return {UINT(0), UINT(-1)}; }
  static constexpr bool commute = 0;
};
