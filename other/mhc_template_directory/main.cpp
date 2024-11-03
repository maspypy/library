#include "my_template.hpp"
#include "other/io.hpp"

void solve(string OFFSET) {}

signed main() {
  INT(T);
  FOR(t, T) {
    string OFFSET = "Case #" + to_string(1 + t) + ":";
    solve(OFFSET);
  }
  return 0;
}
