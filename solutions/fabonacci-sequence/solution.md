# Fabonacci Sequence Solution

There is a reason no one has ever heard of Fabonacci. It isn't because he never existed. It's because even if he did exist, his sequence, while interesting in origination, is hardly original.

The Fabonacci Sequence is actually a set of sequences, with each one a strict subsequence of the next. Further, **each of them is a subsequence of the Fibonacci sequence**, only in reverse. Astute observers will have simply tried the next example:

```
fib(5)-----fib(4)-----fib(3)-----fib(2)-----fib(1)
     \           \          \         \----------------fib(0)
      \           \          \--------------fib(1)
       \           \-------------fib(2)-----fib(1)
        \                             \----------------fib(0)
         \------------fib(3)-----fib(2)-----fib(1)
                           \          \----------------fib(0)
                            \---------------fib(1)
```

and note that this Fabonacci Sequence is:

```
fab(1, 5) = 5
fab(2, 5) = 3
fab(3, 5) = 2
fab(4, 5) = 1
fab(5, 5) = 1
```

0 1 2 3 4 5
0 1 1 2 3 5

In other words:

```
fab(i, n) = fii(n - i + 1)
```

and that's it! It's pretty easy to see why Fabonacci never made it into the history books. This is [my preferred Fibonacci Sequence implementation](https://github.com/whoshuu/weekly-noodler/tree/master/solutions/fabonacci-sequence/fabonacci-sequence.cpp).
