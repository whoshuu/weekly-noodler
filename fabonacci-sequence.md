# Fabonacci Sequence

Everyone knows the Fibonacci Sequence:

```
fib(n) = fib(n - 1) + fib(n -2)
```

where:

```
fib(0) = 0
fib(1) = 1
```

are the base numbers used to generate the entire sequence. Forgotten in the annals of mathematics history is his fabulous, but jealous, brother Fabonacci. Fabonacci boasted a sequence of numbers even more spectacular than the Fibonacci Sequence.

Using the outdated 13th century programming language Python (this was before the superior language C++ was invented), he easily solved the Fibonacci Sequence thusly:

```python
def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n - 1) + fib (n - 2)
```

Plugging in larger and larger values of `n`, his ancient eMachines desktop quickly ran into stack overflow issues. But amid the chaos he found order, and his Fabonacci Sequence was born.

Given a fixed `n`, the Fabonacci number `fab(i, n)`, where `i > 0`, is defined as the number of calls to `fib(i)` that are made when running the above algorithm. 

For instance, if `n` is 4, the call graph looks like this:

```
fib(4)-----fib(3)-----fib(2)-----fib(1)
     \          \          \----------------fib(0)
      \          \---------------fib(1)
       \--------------fib(2)-----fib(1)
                           \----------------fib(0)
```

which means the Fabonacci Sequence (remembering that we ignore `i = 0`) for `n = 4` is:

```
3, 2, 1
```

More specifically:

```
fab(1, 4) = 3
fab(2, 4) = 2
fab(3, 4) = 1
```

Fabonacci, delighted by his discovery, scrambled to write down his algorithm but did not have space in the margins of one of his books for what was, in his estimation, a 1 million LoC program.

Can you write down his algorithm for producing the Fabonacci Sequence for any input `n`?
