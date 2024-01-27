#include "ds/hashmap.hpp"

// [30,10,20,30] -> [0,1,2,0] etc.
struct To_Small_Key {
  int kind = 0;
  HashMap<int> MP;

  To_Small_Key(u32 n = 0) : MP(n) {}

  int set_key(u64 x) {
    if (!MP.count(x)) MP[x] = kind++;
    return MP[x];
  }

  int query(u64 x) { return MP.get(x, -1); }
};