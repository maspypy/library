// マルチテストケースに弱いので static で確保すること
template <class Node>
struct Node_Pool {
  union Slot {
    Node node;
    Slot* next;

    Slot() {}
    ~Slot() {}
  };
  using np = Node*;

  static constexpr int CHUNK_SIZE = 1 << 12;

  vc<unique_ptr<Slot[]>> chunks;
  int chunk_id = 0;
  int pos = 0;
  Slot* free_head = nullptr;

  template <class... Args>
  np create(Args&&... args) {
    Slot* s = new_slot();
    return ::new (&s->node) Node(forward<Args>(args)...);
  }

  np clone(const np x) {
    assert(x);
    Slot* s = new_slot();
    return ::new (&s->node) Node(*x);
  }

  void destroy(np x) {
    if (!x) return;
    x->~Node();
    Slot* s = reinterpret_cast<Slot*>(x);
    s->next = free_head;
    free_head = s;
  }

  // 全 node を無効化する。
  // 確保済み chunk は解放せず、次回以降に再利用する。
  void reset() {
    free_head = nullptr;
    chunk_id = 0;
    pos = 0;
  }

 private:
  void alloc_chunk() { chunks.eb(make_unique<Slot[]>(CHUNK_SIZE)); }

  Slot* new_slot() {
    if (free_head) {
      Slot* s = free_head;
      free_head = free_head->next;
      return s;
    }

    if (chunk_id == len(chunks)) alloc_chunk();

    Slot* s = &chunks[chunk_id][pos++];
    if (pos == CHUNK_SIZE) {
      ++chunk_id;
      pos = 0;
    }
    return s;
  }
};