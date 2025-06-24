#include "ds/hashmap.hpp"

// [30,10,20,30] -> [0,1,2,0] etc.
struct To_Small_Key {
  int kind = 0;
  HashMap<int> MP;
  vc<u64> raw;
  To_Small_Key(u32 n = 0) : MP(n) {}
  void reserve(u32 n) { MP.build(n); }
  int size() { return MP.size(); }
  u64 restore(int i) { return raw[i]; }
  int query(u64 x, bool set_if_not_exist) {
    int ans = MP.get(x, -1);
    if (ans == -1 && set_if_not_exist) {
      raw.eb(x);
      MP[x] = ans = kind++;
    }
    return ans;
  }
};