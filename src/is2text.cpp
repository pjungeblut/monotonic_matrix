#include <cstdio>
#include <tuple>
#include <vector>

std::tuple<std::size_t, std::size_t, std::size_t> get_coords(std::size_t idx,
    std::size_t n) {
  return std::make_tuple(idx / (n * n), idx % (n * n) / n, idx % n);
}

int main(int argc, char **argv) {
  // Check number of parameters.
  if (argc != 4) {
    fprintf(stderr, "Wrong number of arguments.\n");
    fprintf(stderr, "Expecting n, the dimension of the matrix, the name of the "
        "input file containing the independent set and the name of the output "
        "file for the text representation.\n");
    return 0;
  }

  // Read dimension.
  std::size_t n = atoi(argv[1]);
  std::vector<std::vector<std::size_t>> mat(n, std::vector<std::size_t>(n));

  // Open the input file.
  FILE *fin = fopen(argv[2], "r");
  if (fin == NULL) {
    fprintf(stderr, "Error opening input file: %s\n", argv[2]);
    return 0;
  }

  // Read vertices.
  std::size_t cells = 0;
  for (std::size_t idx = 0; idx < n * n * n; ++idx) {
    std::size_t in_is;
    if (!fscanf(fin, "%ld", &in_is)) {
      fprintf(stderr, "Malformed input file. Not enough vertices.\n");
      return 0;
    }
    if (in_is) {
      auto [i, j, k] = get_coords(idx, n);
      mat[i][j] = k + 1;
      ++cells;
    }
  }
  fclose(fin);

  // Opening the output file.
  FILE *fout = fopen(argv[3], "w");
  if (fout == NULL) {
    fprintf(stderr, "Error opening output file: %s\n", argv[3]);
    return 0;
  }

  // Print text representation.
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < n; ++j) {
      fprintf(fout, "%ld ", mat[n - i - 1][j]);
    }
    fprintf(fout, "\n");
  }
  fclose(fout);

  return 0;
}
