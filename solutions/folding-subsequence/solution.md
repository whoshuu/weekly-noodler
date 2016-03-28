# Folding Subsequence Solution

The "folding" terminology in this question is not just to throw off people trying to Google the answer, it's also meant to prime a mental visualization of the problem.

Let's take an example sequence:

```
3, 6, 1, 2, 4, 3, 5, 5, 6, 1, 8, 3
```

and plot it like so:

```
    3
     -----
          6
 ---------
1
 -
  2
   ---
      4
     -
    3
     ---
        5
        5
         -
          6
 ---------
1
 -------------
              8
     ---------
    3
```

What happens when you crunch these numbers vertically? One can imagine you might end up with something like this:

```
    3
     -----
          6
 ---------
1
 -----
      4
     -
    3
     -----
          6
 ---------
1
 -------------
              8
     ---------
    3
```

The numbers between two edges vanish because they don't define any edges themselves. This is precisely the folding subsequence of maximum length 9 given in the problem statement. The problem is reduced to finding the edges that are furthest away from each other, and removing the stuff in between. Here's a [sample implementation](https://github.com/whoshuu/weekly-noodler/tree/master/solutions/folding-subsequence/folding-subsequence.cpp).
