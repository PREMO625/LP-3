# N-Queens Problem - DAA Viva Preparation

## Problem Statement

Design an `n x n` N-Queens matrix with the first queen already placed.
The position of the first queen is given as input. Use backtracking to place
the remaining queens and generate every valid final matrix.

No two queens may share:

- a row
- a column
- a diagonal

## Program Overview

The C++ program:

1. Reads the number of queens, `n`.
2. Reads the first queen's row and column using 1-based positions.
3. Keeps that queen fixed during the search.
4. Places one queen in each remaining row using backtracking.
5. Prints every complete valid matrix and the total number of solutions.

The program stores only the column of the queen in each row:

```cpp
vector<int> queenColumn(n);
```

For example, `queenColumn[2] = 4` means that the queen in row `2` is in
column `4` using zero-based indexing.

## Important Functions

### `safe()`

```cpp
bool safe(int row, int col, const vector<int>& queenColumn)
```

This checks whether a queen can be placed at `(row, col)`.

Two queens conflict when:

```cpp
queenColumn[r] == col
```

They are in the same column, or when:

```cpp
abs(queenColumn[r] - col) == row - r
```

They are on the same diagonal.

The `abs()` function is provided by `<cstdlib>`.

### `solve()`

```cpp
void solve(int row, int n, int fixedRow, int fixedCol,
           vector<int>& queenColumn, int& solutions)
```

This function:

- tries columns for the current row
- skips every column except the input column when it reaches `fixedRow`
- places a queen only when `safe()` returns `true`
- recursively solves the next row
- prints the matrix when all rows are complete

The first queen is not moved because of this condition:

```cpp
if (row == fixedRow && col != fixedCol)
    continue;
```

## Top Viva Questions and Answers

### 1. What is the N-Queens problem?

It is the problem of placing `n` queens on an `n x n` chessboard so that no
two queens attack each other.

### 2. What is the specific requirement of this program?

The first queen is placed at an input row and column. The program uses
backtracking to place the remaining queens and prints all valid matrices.

### 3. Why is backtracking used?

Backtracking builds a solution step by step. If a partial placement cannot
lead to a valid solution, the algorithm abandons that choice and tries
another column.

### 4. Why is one queen considered per row?

The algorithm processes one row at a time, so at most one queen is placed in
each row. This automatically prevents row conflicts.

### 5. How is the first queen kept fixed?

The first queen's row and column are read from input. When the recursion
reaches that row, all other columns are skipped.

### 6. How are column conflicts checked?

The `queenColumn` vector stores the column used by every previously placed
queen. A candidate is rejected if its column is already present.

### 7. How are diagonal conflicts checked?

Two queens are on the same diagonal when the difference between their columns
equals the difference between their rows:

```cpp
abs(queenColumn[r] - col) == row - r
```

### 8. Why does `safe()` check only previous rows?

Rows are processed from top to bottom. Future rows do not contain queens yet,
so only already placed queens can conflict with the current candidate.

### 9. What is the base case?

When `row == n`, every row has a queen. The matrix is complete and is printed
as one valid solution.

### 10. What happens during backtracking?

After a recursive call returns, the loop tries another column for the current
row. The next recursive attempt overwrites the previous column choice.

### 11. Why is a board matrix not stored?

The program stores only queen columns and prints each solution immediately.
This reduces memory usage compared with storing every complete matrix.

### 12. What does `Q` represent?

`Q` represents a queen and `.` represents an empty cell. The output loop
prints `Q` when the current column matches `queenColumn[r]`.

### 13. What input validation is performed?

The program checks that:

- `n` is positive
- the first queen's row is between `1` and `n`
- the first queen's column is between `1` and `n`

Invalid input causes an error message and program termination.

### 14. Why are input positions 1-based?

Users normally number rows and columns starting from `1`. The program
converts them to zero-based indexes using `row - 1` and `col - 1`.

### 15. What happens if the fixed queen cannot lead to a solution?

The program prints no solution matrix and reports:

```text
Total solutions: 0
```

The input position itself can be valid while still making a complete
N-Queens solution impossible.

### 16. What are the results for small values of `n`?

- `n = 1`: one solution for the only valid position
- `n = 2`: no solutions
- `n = 3`: no solutions
- `n = 4`: normally two solutions, but a fixed first queen may reduce this
  number

### 17. What is the time complexity?

The backtracking search has factorial/exponential worst-case behavior,
commonly expressed as `O(n!)`. Each safety check scans previous rows, so a
more detailed upper-bound description is `O(n * n!)`.

### 18. What is the auxiliary space complexity?

The `queenColumn` vector and recursion stack both use `O(n)` space. The
program does not store all solution matrices.

### 19. What is the purpose of the `solutions` variable?

It counts complete valid matrices. It is passed by reference so recursive
calls update the same counter.

### 20. What is the state-space tree?

Each level represents a row. Each branch represents a possible column for the
queen in that row. A path reaching level `n` represents a complete solution.

### 21. What is a promising position?

A position is promising when the new queen does not conflict with any queen
already placed in an earlier row.

### 22. Why does backtracking improve over brute force?

Brute force would generate many complete boards before checking them.
Backtracking rejects unsafe partial boards early.

### 23. What happens if the first queen is placed in a different position?

The same algorithm can be run with another row and column. The result may
contain a different number of valid solutions, including zero.

### 24. Is N-Queens an optimization problem?

No. The usual N-Queens problem is a constraint-satisfaction problem because
the goal is to find arrangements satisfying all constraints.

### 25. Can the program stop after finding one solution?

Yes. The recursive function could return a boolean and stop after the first
complete matrix. The current program continues so that it can generate all
valid matrices.

## Example

For:

```text
n = 4
first queen row = 1
first queen column = 2
```

The output is:

```text
.Q..
...Q
Q...
..Q.
```

The total is:

```text
Total solutions: 1
```

## Quick Revision

- First queen position is input.
- Positions entered by the user are 1-based.
- Internally, indexes are zero-based.
- One row is processed at a time.
- `safe()` checks columns and diagonals.
- `solve()` performs recursive backtracking.
- The fixed queen cannot be moved.
- `row == n` means a complete solution.
- Solutions are printed immediately, not stored.
- Auxiliary space is `O(n)`.
- Worst-case search is factorial/exponential.
