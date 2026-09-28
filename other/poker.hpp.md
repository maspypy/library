---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/poker.hpp\"\n\n\nnamespace poker {\n\n// rank: 0=2,\
    \ 1=3, ..., 8=T, 9=J, 10=Q, 11=K, 12=A\n// suit: 0=C, 1=D, 2=H, 3=S\n// card =\
    \ 4 * rank + suit\n\nenum class Category : u8 {\n  HIGH_CARD,\n  ONE_PAIR,\n \
    \ TWO_PAIR,\n  THREE_OF_A_KIND,\n  STRAIGHT,\n  FLUSH,\n  FULL_HOUSE,\n  FOUR_OF_A_KIND,\n\
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
  code: "\n\nnamespace poker {\n\n// rank: 0=2, 1=3, ..., 8=T, 9=J, 10=Q, 11=K, 12=A\n\
    // suit: 0=C, 1=D, 2=H, 3=S\n// card = 4 * rank + suit\n\nenum class Category\
    \ : u8 {\n  HIGH_CARD,\n  ONE_PAIR,\n  TWO_PAIR,\n  THREE_OF_A_KIND,\n  STRAIGHT,\n\
    \  FLUSH,\n  FULL_HOUSE,\n  FOUR_OF_A_KIND,\n  STRAIGHT_FLUSH\n};\n\ninline constexpr\
    \ array<string_view, 9> CATEGORY_NAMES = {\n    \"HIGH_CARD\", \"ONE_PAIR\", \
    \  \"TWO_PAIR\",       \"THREE_OF_A_KIND\", \"STRAIGHT\",\n    \"FLUSH\",    \
    \ \"FULL_HOUSE\", \"FOUR_OF_A_KIND\", \"STRAIGHT_FLUSH\",\n};\n\nconstexpr string_view\
    \ RANKS = \"23456789TJQKA\";\nconstexpr string_view SUITS = \"CDHS\";\n\nu8 make_card(int\
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
  dependsOn: []
  isVerificationFile: false
  path: other/poker.hpp
  requiredBy: []
  timestamp: '2026-09-28 10:13:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/poker.hpp
layout: document
redirect_from:
- /library/other/poker.hpp
- /library/other/poker.hpp.html
title: other/poker.hpp
---
