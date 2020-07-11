#include <cstdio>
#include <tuple>
#include <vector>

std::tuple<std::size_t, std::size_t, std::size_t> get_coords(std::size_t idx,
    std::size_t n) {
  return std::make_tuple(idx / (n * n), idx % (n * n) / n, idx % n);
}

int main() {
  // Read dimension.
  std::size_t n;
  scanf("%ld", &n);
  std::vector<std::vector<std::size_t>> mat(n, std::vector<std::size_t>(n));

  // Read vertices.
  std::size_t cells = 0;
  for (std::size_t idx = 0; idx < n * n * n; ++idx) {
    std::size_t in_is;
    scanf("%ld", &in_is);
    if (in_is) {
      auto [i, j, k] = get_coords(idx, n);
      mat[i][j] = k + 1;
      ++cells;
    }
  }

  // Print text representation.
  printf("%ld %ld\n", n, cells);
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < n; ++j) {
      printf("%ld ", mat[n - i - 1][j]);
    }
    printf("\n");
  }
  return 0;
}
