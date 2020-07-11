#include <algorithm>
#include <cstdio>
#include <vector>

std::size_t get_idx(std::size_t i, std::size_t j, std::size_t k, std::size_t n) {
  return i * n * n + j * n + k;
}

int main(int argc, char **argv) {
  // Check number of parameters and read dimension.
  if (argc != 3) {
    fprintf(stderr, "Wrong number of arguments.\n");
    fprintf(stderr, "Expecting the dimension n of the nxn-matrix and the name "
        "output file.\n");
    return 0;
  }
  std::size_t n = atoi(argv[1]);
  if (n < 1) {
    fprintf(stderr, "Invalid dimension: %ld\n", n);
    fprintf(stderr, "Matrix must be at least 1x1.\n");
    return 0;
  }

  // Open output file.
  FILE *fout = fopen(argv[2], "w");
  if (fout == NULL) {
    fprintf(stderr, "Could not open file: %s\n", argv[2]);
    return 0;
  }

  // Create graph.
  std::vector<std::vector<std::size_t>> adjlist(n * n * n);
  for (std::size_t i1 = 0; i1 < n; ++i1) {
    for (std::size_t j1 = 0; j1 < n; ++j1) {
      for (std::size_t k1 = 0; k1 < n; ++k1) {
        std::size_t idx1 = get_idx(i1, j1, k1, n);

        // Find all tripods conflicting in the (i,j)-plane.
        for (std::size_t i2 = 0; i2 < n; ++i2) {
          for (std::size_t j2 = 0; j2 < n; ++j2) {
            if (i2 > i1 && j2 > j1) continue;
            if (i2 < i1 && j2 < j1) continue;
            if (i2 == i1 && j2 == j1) continue;
            std::size_t idx2 = get_idx(i2, j2, k1, n);
            adjlist[idx1].push_back(idx2);
          }
        }

        // Find all tripods conflicting in the (i,k)-plane.
        for (std::size_t i2 = 0; i2 < n; ++i2) {
          for (std::size_t k2 = 0; k2 < n; ++k2) {
            if (i2 > i1 && k2 > k1) continue;
            if (i2 < i1 && k2 < k1) continue;
            if (i2 == i1 && k2 == k1) continue;
            std::size_t idx2 = get_idx(i2, j1, k2, n);
            adjlist[idx1].push_back(idx2);
          }
        }

        // Find all tripods conflicting in the (j,k)-plane.
        for (std::size_t j2 = 0; j2 < n; ++j2) {
          for (std::size_t k2 = 0; k2 < n; ++k2) {
            if (j2 > j1 && k2 > k1) continue;
            if (j2 < j1 && k2 < k1) continue;
            if (j2 == j1 && k2 == k1) continue;
            std::size_t idx2 = get_idx(i1, j2, k2, n);
            adjlist[idx1].push_back(idx2);
          }
        }
      }
    }
  }

  // Output graph in KaMIS format.
  // Edges need to be sorted.
  // Vertices are 1-indexed.
  std::size_t m = 0;
  for (auto &v : adjlist) {
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
    m += v.size();
  }
  fprintf(fout, "%ld %ld\n", n * n * n, m / 2);
  for (auto &v : adjlist) {
    for (std::size_t w : v) fprintf(fout, "%ld ", w + 1);
    fprintf(fout, "\n");
  }
  fclose(fout);
  
  return 0;
}
