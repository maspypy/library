---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/poker.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool\
    \ done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 3 \"other/poker.hpp\"\n\n\
    namespace poker {\n\n// rank: 0=2, 1=3, ..., 8=T, 9=J, 10=Q, 11=K, 12=A\n// suit:\
    \ 0=C, 1=D, 2=H, 3=S\n// card = 4 * rank + suit\n\nenum class Category : u8 {\n\
    \  HIGH_CARD,\n  ONE_PAIR,\n  TWO_PAIR,\n  THREE_OF_A_KIND,\n  STRAIGHT,\n  FLUSH,\n\
    \  FULL_HOUSE,\n  FOUR_OF_A_KIND,\n  STRAIGHT_FLUSH\n};\n\ninline constexpr array<string_view,\
    \ 9> CATEGORY_NAMES = {\n    \"HIGH_CARD\", \"ONE_PAIR\",   \"TWO_PAIR\",    \
    \   \"THREE_OF_A_KIND\", \"STRAIGHT\",\n    \"FLUSH\",     \"FULL_HOUSE\", \"\
    FOUR_OF_A_KIND\", \"STRAIGHT_FLUSH\",\n};\n\nconstexpr string_view RANKS = \"\
    23456789TJQKA\";\nconstexpr string_view SUITS = \"CDHS\";\n\nu8 make_card(int\
    \ rank, int suit) {\n  assert(0 <= rank && rank < 13);\n  return u8(rank << 2\
    \ | suit);\n}\nint rank(u8 card) { return card >> 2; }\nint suit(u8 card) { return\
    \ card & 3; }\n// 2C,3C,...,9C,TC,JC,QC,KC,AC\nu8 from_string(string X) {\n  return\
    \ make_card(RANKS.find(X[0]), SUITS.find(X[1]));\n}\nstring to_string(u8 card)\
    \ {\n  string result;\n  result += RANKS[rank(card)];\n  result += SUITS[suit(card)];\n\
    \  return result;\n}\n\nconstexpr array<int8_t, 1 << 13> make_straight_high_table()\
    \ {\n  array<int8_t, 1 << 13> table{};\n  for (auto& x : table) x = -1;\n  //\
    \ 23456, 34567, ..., TJQKA\n  for (int low = 0; low <= 8; ++low) {\n    table[0b11111\
    \ << low] = low + 4;\n  }\n  // A2345: 5-high straight\n  table[(1 << 12) | 0b1111]\
    \ = 3;\n  return table;\n}\n\ninline constexpr auto STRAIGHT_HIGH = make_straight_high_table();\n\
    \nu32 category_high(Category X, u32 a = 0, u32 b = 0, u32 c = 0, u32 d = 0,\n\
    \                  u32 e = 0) {\n  return (u32(X) << 20) | (a << 16) | ((b) <<\
    \ 12) | (c << 8) | (d << 4) | (e);\n}\nu32 category_distinct(Category X, u32 mask)\
    \ {\n  u32 value = u32(X) << 20;\n  int shift = 16;\n  while (mask) {\n    int\
    \ r = topbit(mask);\n    value |= topbit(mask) << shift;\n    mask ^= 1u << r,\
    \ shift -= 4;\n  }\n  return value;\n}\n\nu32 evaluate5(u8 c0, u8 c1, u8 c2, u8\
    \ c3, u8 c4) {\n  int r0 = rank(c0), r1 = rank(c1), r2 = rank(c2), r3 = rank(c3),\
    \ r4 = rank(c4);\n  bool flush = ((c0 ^ c1) | (c0 ^ c2) | (c0 ^ c3) | (c0 ^ c4))\
    \ % 4 == 0;\n  u32 mask = (1u << r0) | (1u << r1) | (1u << r2) | (1u << r3) |\
    \ (1u << r4);\n  const u64 C = (1ULL << (4 * r0)) + (1ULL << (4 * r1)) + (1ULL\
    \ << (4 * r2)) +\n                (1ULL << (4 * r3)) + (1ULL << (4 * r4));\n\n\
    \  if (popcnt(mask) == 5) {\n    int s = STRAIGHT_HIGH[mask];\n    if (flush)\
    \ {\n      if (s >= 0) {\n        return category_high(Category::STRAIGHT_FLUSH,\
    \ s);\n      }\n      return category_distinct(Category::FLUSH, mask);\n    }\n\
    \    if (s >= 0) {\n      return category_high(Category::STRAIGHT, s);\n    }\n\
    \    return category_distinct(Category::HIGH_CARD, mask);\n  }\n\n  int quad =\
    \ -1;\n  int trip = -1;\n  int high_pair = -1;\n  int low_pair = -1;\n  int singles[3];\n\
    \  int p = 0;\n\n  for (int r = 12; r >= 0; --r) {\n    int cnt = (C >> (4 * r))\
    \ & 15;\n    if (cnt == 4) {\n      quad = r;\n    }\n    elif (cnt == 3) { trip\
    \ = r; }\n    elif (cnt == 2) { (high_pair == -1 ? high_pair : low_pair) = r;\
    \ }\n    elif (cnt == 1) { singles[p++] = r; }\n  }\n\n  if (quad >= 0) {\n  \
    \  return category_high(Category::FOUR_OF_A_KIND, quad, singles[0]);\n  }\n\n\
    \  if (trip >= 0 && high_pair >= 0) {\n    return category_high(Category::FULL_HOUSE,\
    \ trip, high_pair);\n  }\n\n  if (trip >= 0) {\n    return category_high(Category::THREE_OF_A_KIND,\
    \ trip, singles[0],\n                         singles[1]);\n  }\n\n  if (low_pair\
    \ >= 0) {\n    return category_high(Category::TWO_PAIR, high_pair, low_pair, singles[0]);\n\
    \  }\n  return category_high(Category::ONE_PAIR, high_pair, singles[0], singles[1],\n\
    \                       singles[2]);\n}\n}  // namespace poker\n"
  code: "\n#include \"other/bit.hpp\"\n\nnamespace poker {\n\n// rank: 0=2, 1=3, ...,\
    \ 8=T, 9=J, 10=Q, 11=K, 12=A\n// suit: 0=C, 1=D, 2=H, 3=S\n// card = 4 * rank\
    \ + suit\n\nenum class Category : u8 {\n  HIGH_CARD,\n  ONE_PAIR,\n  TWO_PAIR,\n\
    \  THREE_OF_A_KIND,\n  STRAIGHT,\n  FLUSH,\n  FULL_HOUSE,\n  FOUR_OF_A_KIND,\n\
    \  STRAIGHT_FLUSH\n};\n\ninline constexpr array<string_view, 9> CATEGORY_NAMES\
    \ = {\n    \"HIGH_CARD\", \"ONE_PAIR\",   \"TWO_PAIR\",       \"THREE_OF_A_KIND\"\
    , \"STRAIGHT\",\n    \"FLUSH\",     \"FULL_HOUSE\", \"FOUR_OF_A_KIND\", \"STRAIGHT_FLUSH\"\
    ,\n};\n\nconstexpr string_view RANKS = \"23456789TJQKA\";\nconstexpr string_view\
    \ SUITS = \"CDHS\";\n\nu8 make_card(int rank, int suit) {\n  assert(0 <= rank\
    \ && rank < 13);\n  return u8(rank << 2 | suit);\n}\nint rank(u8 card) { return\
    \ card >> 2; }\nint suit(u8 card) { return card & 3; }\n// 2C,3C,...,9C,TC,JC,QC,KC,AC\n\
    u8 from_string(string X) {\n  return make_card(RANKS.find(X[0]), SUITS.find(X[1]));\n\
    }\nstring to_string(u8 card) {\n  string result;\n  result += RANKS[rank(card)];\n\
    \  result += SUITS[suit(card)];\n  return result;\n}\n\nconstexpr array<int8_t,\
    \ 1 << 13> make_straight_high_table() {\n  array<int8_t, 1 << 13> table{};\n \
    \ for (auto& x : table) x = -1;\n  // 23456, 34567, ..., TJQKA\n  for (int low\
    \ = 0; low <= 8; ++low) {\n    table[0b11111 << low] = low + 4;\n  }\n  // A2345:\
    \ 5-high straight\n  table[(1 << 12) | 0b1111] = 3;\n  return table;\n}\n\ninline\
    \ constexpr auto STRAIGHT_HIGH = make_straight_high_table();\n\nu32 category_high(Category\
    \ X, u32 a = 0, u32 b = 0, u32 c = 0, u32 d = 0,\n                  u32 e = 0)\
    \ {\n  return (u32(X) << 20) | (a << 16) | ((b) << 12) | (c << 8) | (d << 4) |\
    \ (e);\n}\nu32 category_distinct(Category X, u32 mask) {\n  u32 value = u32(X)\
    \ << 20;\n  int shift = 16;\n  while (mask) {\n    int r = topbit(mask);\n   \
    \ value |= topbit(mask) << shift;\n    mask ^= 1u << r, shift -= 4;\n  }\n  return\
    \ value;\n}\n\nu32 evaluate5(u8 c0, u8 c1, u8 c2, u8 c3, u8 c4) {\n  int r0 =\
    \ rank(c0), r1 = rank(c1), r2 = rank(c2), r3 = rank(c3), r4 = rank(c4);\n  bool\
    \ flush = ((c0 ^ c1) | (c0 ^ c2) | (c0 ^ c3) | (c0 ^ c4)) % 4 == 0;\n  u32 mask\
    \ = (1u << r0) | (1u << r1) | (1u << r2) | (1u << r3) | (1u << r4);\n  const u64\
    \ C = (1ULL << (4 * r0)) + (1ULL << (4 * r1)) + (1ULL << (4 * r2)) +\n       \
    \         (1ULL << (4 * r3)) + (1ULL << (4 * r4));\n\n  if (popcnt(mask) == 5)\
    \ {\n    int s = STRAIGHT_HIGH[mask];\n    if (flush) {\n      if (s >= 0) {\n\
    \        return category_high(Category::STRAIGHT_FLUSH, s);\n      }\n      return\
    \ category_distinct(Category::FLUSH, mask);\n    }\n    if (s >= 0) {\n      return\
    \ category_high(Category::STRAIGHT, s);\n    }\n    return category_distinct(Category::HIGH_CARD,\
    \ mask);\n  }\n\n  int quad = -1;\n  int trip = -1;\n  int high_pair = -1;\n \
    \ int low_pair = -1;\n  int singles[3];\n  int p = 0;\n\n  for (int r = 12; r\
    \ >= 0; --r) {\n    int cnt = (C >> (4 * r)) & 15;\n    if (cnt == 4) {\n    \
    \  quad = r;\n    }\n    elif (cnt == 3) { trip = r; }\n    elif (cnt == 2) {\
    \ (high_pair == -1 ? high_pair : low_pair) = r; }\n    elif (cnt == 1) { singles[p++]\
    \ = r; }\n  }\n\n  if (quad >= 0) {\n    return category_high(Category::FOUR_OF_A_KIND,\
    \ quad, singles[0]);\n  }\n\n  if (trip >= 0 && high_pair >= 0) {\n    return\
    \ category_high(Category::FULL_HOUSE, trip, high_pair);\n  }\n\n  if (trip >=\
    \ 0) {\n    return category_high(Category::THREE_OF_A_KIND, trip, singles[0],\n\
    \                         singles[1]);\n  }\n\n  if (low_pair >= 0) {\n    return\
    \ category_high(Category::TWO_PAIR, high_pair, low_pair, singles[0]);\n  }\n \
    \ return category_high(Category::ONE_PAIR, high_pair, singles[0], singles[1],\n\
    \                       singles[2]);\n}\n}  // namespace poker\n"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: other/poker.hpp
  requiredBy: []
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/poker.hpp
layout: document
redirect_from:
- /library/other/poker.hpp
- /library/other/poker.hpp.html
title: other/poker.hpp
---
