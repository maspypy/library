// template/grid.hpp
auto isin = [&](int x, int y) -> bool {
  return (0 <= x && x < H && 0 <= y && y < W);
};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
auto idx = [&](int x, int y) -> int { return W * x + y; };