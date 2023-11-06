#include "ds/hashmap.hpp"

// [30,10,20,30] -> [0,1,2,0] etc.
template <int LOG = 20, bool USE_RESET = false>
struct To_Small_Key {
  int kind = 0;
  HashMap<int, LOG, true> MP;

  int set_key(u64 x) {
    int idx = MP.index(x);
    if (!MP.used[idx]) {
      MP.used[idx] = 1;
      MP.dat[idx] = {u64(x), kind++};
    }
    return MP.dat[idx].se;
  }

  int query(u64 x) { return MP.get(x, -1); }

  void reset() {
    static_assert(USE_RESET);
    MP.reset();
  }
};