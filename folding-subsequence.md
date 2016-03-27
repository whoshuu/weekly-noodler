# Folding Subsequence

This problem actually goes by another name, but to throw off cheaters, I'll use "folding" to describe the following property:

> A folding sequence is a sequence of numbers where the difference between consecutive numbers in the sequence alternate in sign. A difference of 0 is defined to have no sign, so any sequence with consecutive repeating numbers is by definition a non-folding sequence.

To illustrate, these are folding sequences:

```
1
1, 2
1, 2, 1
1, 5, 3, 4, 2
6, 3, 5, 4, 5
```

and these are non-folding sequences:

```
1, 1
1, 2, 3
1, 5, 3, 4, 6
```

The problem is to write a program, taking a sequence of integers, that determines what the length of the **longest folding subsequence** is. For example, this sequence:

```
3, 6, 1, 2, 4, 3, 5, 5, 6, 1, 8, 3
```

has a maximum folding subsequence length of 9 (`3, 6, 1, 4, 3, 6, 1, 8, 3` is an example folding subsequence).

For thoroughness, the algorithm should produce these outputs for the following sequences:

```
1             -> 1
1, 2          -> 2
1, 2, 1       -> 3
1, 2, 2, 1    -> 3
1, 2, 1, 2, 1 -> 5
1, 2, 3, 2, 3 -> 4
```

Can you write an algorithm that does this in O(n)?
