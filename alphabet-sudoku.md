# Alphabet Sudoku

Sudoku is a puzzle game where a 9x9 grid must be filled up such that the 9 3x3 subgrids contain all the digits from 1 to 9. Additionally, no two identical numbers can occupy the same row or column in the entire grid.

This particular variant of the game uses letters instead of numbers, and a slight simplification of the rules. Given a 3x3 grid such as:

```
A C

 A
```

a solution might be:

```
ABC
BCA
CAB
```

Write a program that reads in 3x3 grids in the format above (three lines, `A`, `B`, or `C` can occupy any square but the input is guaranteed to be solvable), and solves it by printing out a solution grid. Then, solve these inputs:

1.
```
AB

 AB
```

2.
```
AB

  A
```

3.
```
  C
  B
C
```

4.
```

  C
A
```

5.
```
C
  A

```

Bonus A: Write a program that solves up to a 26x26 grid using all of the letters. Is the algorithm fundamentally different?
Bonus B: Write a program to determine if a particular input has a unique solution. 
