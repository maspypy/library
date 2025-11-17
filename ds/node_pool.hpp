// マルチテストケースに弱いので static で確保すること
template <class Node>
struct Node_Pool {
  struct Slot {
    union alignas(Node) {
      Slot* next;
      unsigned char storage[sizeof(Node)];
    };
  };
  using np = Node*;

  static constexpr int CHUNK_SIZE = 1 << 12;

  vc<unique_ptr<Slot[]>> chunks;
  Slot* cur = nullptr;
  int cur_used = 0;
  Slot* free_head = nullptr;

  Node_Pool() { alloc_chunk(); }

  template <class... Args>
  np create(Args&&... args) {
    Slot* s = new_slot();
    return ::new (s) Node(forward<Args>(args)...);
  }

  np clone(const np x) {
    assert(x);
    Slot* s = new_slot();
    return ::new (s) Node(*x);  // コピーコンストラクタ呼び出し
  }

  void destroy(np x) {
    if (!x) return;
    x->~Node();
    auto s = reinterpret_cast<Slot*>(x);
    s->next = free_head;
    free_head = s;
  }

  void reset() {
    free_head = nullptr;
    if (!chunks.empty()) {
      cur = chunks[0].get();
      cur_used = 0;
    }
  }

 private:
  void alloc_chunk() {
    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));
    cur = chunks.back().get();
    cur_used = 0;
  }

  Slot* new_slot() {
    if (free_head) {
      Slot* s = free_head;
      free_head = free_head->next;
      return s;
    }
    if (cur_used == CHUNK_SIZE) alloc_chunk();
    return &cur[cur_used++];
  }
};