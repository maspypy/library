template <int LOG = 30>
struct Binary_Trie {
  struct Node {
    ll cnt = 0;
    int ch[2] = {-1, -1};
  };
  vector<Node> ns;

  Binary_Trie() : ns(1) {}

  ll size() const { return ns[0].cnt; }
  ll operator[](int k) const { return find_kth(k, 0); }
  ll find_kth(ll k, ll xor_add = 0) const {
    assert(0 <= k && k < size());
    ll idx = 0;
    ll val = 0;
    FOR_R(i, LOG) {
      ll c = xor_add >> i & 1;
      ll low_ch = ns[idx].ch[c];
      ll low_cnt = (low_ch >= 0 ? ns[low_ch].cnt : 0);
      if (k < low_cnt) {
        idx = low_ch;
      } else {
        k -= low_cnt;
        idx = ns[idx].ch[c ^ 1];
        val ^= 1LL << i;
      }
      assert(idx >= 0);
    }
    return val;
  }

  void add(ll val, ll cnt = 1) {
    assert(0 <= val && val < (1LL << LOG));
    int idx = 0;
    FOR_R(i, LOG) {
      ns[idx].cnt += cnt;
      assert(ns[idx].cnt >= 0);
      int &nxt = ns[idx].ch[val >> i & 1];
      if (nxt == -1) {
        idx = nxt = ns.size();
        ns.emplace_back();
      } else {
        idx = nxt;
      }
    }
    ns[idx].cnt += cnt;
    assert(ns[idx].cnt >= 0);
    return;
  }

  ll lower_bound(ll val, ll xor_add = 0) {
    assert(0 <= val);
    if (val >= (1LL << LOG)) return size();
    int idx = 0;
    ll cnt = 0;
    FOR_R(i, LOG) {
      int b = val >> i & 1, c = xor_add >> i & 1;
      int ch = ns[idx].ch[c];
      cnt += (b & (ch >= 0) ? ns[ch].cnt : 0);
      idx = ns[idx].ch[b ^ c];
      if (idx < 0 or ns[idx].cnt == 0) break;
    }
    return cnt;
  }

  ll count(ll val) const {
    assert(0 <= val && val < (1LL << LOG));
    int idx = 0;
    FOR_R(i, LOG) {
      idx = ns[idx].ch[val >> i & 1];
      if (idx < 0 or ns[idx].cnt == 0) return 0;
    }
    return ns[idx].cnt;
  }

  ll count(ll L, ll R, ll xor_add = 0) {
    assert(0 <= L && L <= R && R <= (1LL << LOG));
    return lower_bound(R, xor_add) - lower_bound(L, xor_add);
  }

  ll min(ll xor_add = 0) { return find_kth(0, xor_add); }
  ll max(ll xor_add = 0) { return find_kth(size() - 1, xor_add); }

  void debug() {
    FOR(i, len(ns)) print(i, "cnt", ns[i].cnt, "ch", ns[i].ch[0], ns[i].ch[1]);
  }
};
