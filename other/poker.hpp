
#include "other/bit.hpp"

namespace poker {

// rank: 0=2, 1=3, ..., 8=T, 9=J, 10=Q, 11=K, 12=A
// suit: 0=C, 1=D, 2=H, 3=S
// card = 4 * rank + suit

enum class Category : u8 {
  HIGH_CARD,
  ONE_PAIR,
  TWO_PAIR,
  THREE_OF_A_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  STRAIGHT_FLUSH
};

inline constexpr array<string_view, 9> CATEGORY_NAMES = {
    "HIGH_CARD", "ONE_PAIR",   "TWO_PAIR",       "THREE_OF_A_KIND", "STRAIGHT",
    "FLUSH",     "FULL_HOUSE", "FOUR_OF_A_KIND", "STRAIGHT_FLUSH",
};

constexpr string_view RANKS = "23456789TJQKA";
constexpr string_view SUITS = "CDHS";

u8 make_card(int rank, int suit) {
  assert(0 <= rank && rank < 13);
  return u8(rank << 2 | suit);
}
int rank(u8 card) { return card >> 2; }
int suit(u8 card) { return card & 3; }
// 2C,3C,...,9C,TC,JC,QC,KC,AC
u8 from_string(string X) {
  return make_card(RANKS.find(X[0]), SUITS.find(X[1]));
}
string to_string(u8 card) {
  string result;
  result += RANKS[rank(card)];
  result += SUITS[suit(card)];
  return result;
}

constexpr array<int8_t, 1 << 13> make_straight_high_table() {
  array<int8_t, 1 << 13> table{};
  for (auto& x : table) x = -1;
  // 23456, 34567, ..., TJQKA
  for (int low = 0; low <= 8; ++low) {
    table[0b11111 << low] = low + 4;
  }
  // A2345: 5-high straight
  table[(1 << 12) | 0b1111] = 3;
  return table;
}

inline constexpr auto STRAIGHT_HIGH = make_straight_high_table();

u32 category_high(Category X, u32 a = 0, u32 b = 0, u32 c = 0, u32 d = 0,
                  u32 e = 0) {
  return (u32(X) << 20) | (a << 16) | ((b) << 12) | (c << 8) | (d << 4) | (e);
}
u32 category_distinct(Category X, u32 mask) {
  u32 value = u32(X) << 20;
  int shift = 16;
  while (mask) {
    int r = topbit(mask);
    value |= topbit(mask) << shift;
    mask ^= 1u << r, shift -= 4;
  }
  return value;
}

u32 evaluate5(u8 c0, u8 c1, u8 c2, u8 c3, u8 c4) {
  int r0 = rank(c0), r1 = rank(c1), r2 = rank(c2), r3 = rank(c3), r4 = rank(c4);
  bool flush = ((c0 ^ c1) | (c0 ^ c2) | (c0 ^ c3) | (c0 ^ c4)) % 4 == 0;
  u32 mask = (1u << r0) | (1u << r1) | (1u << r2) | (1u << r3) | (1u << r4);
  const u64 C = (1ULL << (4 * r0)) + (1ULL << (4 * r1)) + (1ULL << (4 * r2)) +
                (1ULL << (4 * r3)) + (1ULL << (4 * r4));

  if (popcnt(mask) == 5) {
    int s = STRAIGHT_HIGH[mask];
    if (flush) {
      if (s >= 0) {
        return category_high(Category::STRAIGHT_FLUSH, s);
      }
      return category_distinct(Category::FLUSH, mask);
    }
    if (s >= 0) {
      return category_high(Category::STRAIGHT, s);
    }
    return category_distinct(Category::HIGH_CARD, mask);
  }

  int quad = -1;
  int trip = -1;
  int high_pair = -1;
  int low_pair = -1;
  int singles[3];
  int p = 0;

  for (int r = 12; r >= 0; --r) {
    int cnt = (C >> (4 * r)) & 15;
    if (cnt == 4) {
      quad = r;
    }
    elif (cnt == 3) { trip = r; }
    elif (cnt == 2) { (high_pair == -1 ? high_pair : low_pair) = r; }
    elif (cnt == 1) { singles[p++] = r; }
  }

  if (quad >= 0) {
    return category_high(Category::FOUR_OF_A_KIND, quad, singles[0]);
  }

  if (trip >= 0 && high_pair >= 0) {
    return category_high(Category::FULL_HOUSE, trip, high_pair);
  }

  if (trip >= 0) {
    return category_high(Category::THREE_OF_A_KIND, trip, singles[0],
                         singles[1]);
  }

  if (low_pair >= 0) {
    return category_high(Category::TWO_PAIR, high_pair, low_pair, singles[0]);
  }
  return category_high(Category::ONE_PAIR, high_pair, singles[0], singles[1],
                       singles[2]);
}
}  // namespace poker
