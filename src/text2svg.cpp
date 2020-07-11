#include <cstddef>
#include <cstdio>
#include <string>
#include <vector>

const std::size_t BLOCK_SIZE = 25;
const std::string COLORS[] = {
  "ffffff",
  "ed7b7b",
  "89d8e8",
  "9ce6be",
  "f0ddc9",
  "9cace6",
  "ebb2e0",
  "faacb2",
  "ffcc99",
  "f4f5c1",
  "88b389",
  "a875d1",
  "bababa",
  "9d9ff2",
  "77d49f"
};
const std::size_t NUM_COLORS = sizeof(COLORS) / sizeof(std::string) - 1;

int main() {
  // Read matrix dimension.
  std::size_t n, s;
  scanf("%ld %ld", &n, &s);

  // Read matrix.
  std::vector<std::vector<std::size_t>> mat(n, std::vector<std::size_t>(n));
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < n; ++j) {
      scanf("%ld", &mat[i][j]);
    }
  }

  // Build SVG.
  std::size_t dim = BLOCK_SIZE * n;
  printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%ld\" "
      "height=\"%ld\" version=\"1.0\">\n", dim, dim);
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < n; ++j) {
      std::size_t x = j * BLOCK_SIZE;
      std::size_t y = i * BLOCK_SIZE;
      std::string color = mat[i][j] <= NUM_COLORS
          ? COLORS[mat[i][j]]
          : COLORS[(mat[i][j] - 1) % NUM_COLORS + 1];
      printf("<rect x=\"%ld\" y=\"%ld\" width=\"%ld\" height=\"%ld\" "
          "fill=\"#%s\" stroke=\"black\"/>\n",
          x, y, BLOCK_SIZE, BLOCK_SIZE, color.c_str());
      if (mat[i][j]) {
        printf("<text x=\"%lf\" y=\"%lf\" dominant-baseline=\"central\" "
            "text-anchor=\"middle\">%ld</text>\n",
            x + BLOCK_SIZE / 2.0, y + BLOCK_SIZE / 2.0, mat[i][j]);
      }
    }
  }
  printf("</svg>\n");
  return 0;
}
