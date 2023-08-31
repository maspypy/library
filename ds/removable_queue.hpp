template <typename QUE_TYPE>
struct Removable_Queue {
  using QUE = QUE_TYPE;
  using T = typename QUE::value_type;

  QUE que, rm_que;

  Removable_Queue() {}
  Removable_Queue(vc<T>& dat) : que(all(dat)) {}

  void push(T x) { que.push(x); }
  int size() { return len(que) - len(rm_que); }

  T pop() {
    refresh();
    return POP(que);
  }
  T top() {
    refresh();
    return que.top();
  }

  void remove(T x) { rm_que.push(x); }

private:
  void refresh() {
    while (len(rm_que) && rm_que.top() == que.top()) {
      rm_que.pop(), que.pop();
    }
  }
};
