#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
  // Check for the correct number of arguments.
  if (argc != 3) {
    std::cerr << "Wrong number of arguments." << std::endl;
    std::cerr << "Expecting paths to input and output files." << std::endl;
    return 0;
  }

  // Open input file containing graph in KaMIS format.
  std::ifstream fin(argv[1]);
  if (!fin.good()) {
    std::cerr << "Error opening input file: " << argv[1] << std::endl;
    return 0;
  }

  // Open output file for graph in "We Got You Covered" format.
  std::ofstream fout(argv[2]);
  if (!fout.good()) {
    std::cerr << "Error opening output file: " << argv[2] << std::endl;
    return 0;
  }

  // Convert metadata.
  std::size_t n, m;
  fin >> n >> m;
  fout << "p td " << n << " " << m << std::endl;

  // Convert adjacencies.
  for (std::size_t v = 1; v <= n; ++v) {
    std::string line;
    std::getline(fin, line);
    std::stringstream ss;
    ss << line;
    std::size_t w;
    while (ss >> w) {
      if (v < w) {
        fout << v << " " << w << std::endl;
      }
    }
  }

  return 0;
}
