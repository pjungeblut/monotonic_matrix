# Monotonic Matrix Generator

A square matrix `A` of order `n` containing the elements from `{1,...,n}` is a *monotonic matrix* , such that:
* Each row of `A` is strictly increasing.
* Each column of `A` is strictly decreasing.
* For two cells `(i1,j1)` and `(i1,j2)` containing the same value `k` it is without loss of generality `i1 < i2` and `j1 < j2`. (This is the *positive slope condition*.)

One asks for the maximum number of occupied cells in such a matrix.
See [OEIS Sequence A070214](https://oeis.org/A070214) for the best known values and additional insights about the problem.
Below is an example for a `11x11` monotonic matrix with `38` occupied cells, which is the best value known today.

![n=11](https://pjungeblut.github.io/monotonic_matrices/images/monotonic_matrix_11.svg "Example of a monotonic matrix of order 11.")

We provide tools to find monotinic matrices for *relatively* large `n`.
The functionality is split into several programs:
* **`graph_gen`**: Generates a graph `G` on the vertex set `{1,...,n}^3`, such that an independent set in `G` corresponds to a monotonic matrix of order `n`. A large independent set can then be found using the included tool [KaMIS](https://karlsruhemis.github.io/).
* **`is2text`**: Converts the independent set found by KaMIS into a monotonic matrix and produces a text representation.
* **`text2svg`**: Converts the text representation of the matrix into a SVG image.

## Install and Uninstall

To install download the source (or clone this repository) and execute:
```
./install.sh
```
To remove all built files execute:
```
./cleanup.sh
```

## Usage
TODO

## License
All tools here are published under MIT license. However, please also see the license of [KaMIS](https://github.com/KarlsruheMIS/KaMIS#License)!
