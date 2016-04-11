# Breaking Change Solution

This problem is difficult without two key insights:

1. If a coin system is "broken", that is, if the greedy algorithm fails to always produce the optimal change, then there is an upper bound on the smallest test value that breaks that system.
2. Testing whether this smallest value can be optimally produced with the greedy algorithm does not, in fact, involve finding an optimal solution.

## Finding an upper bound

(Warning, long sloppy proof ahead)

For the first key insight, let's assume a coin system made up of the coins `1, c_2, ..., c_m, c_n` is in sorted order, and does not have the property that the greedy algorithm produces an optimal change.

By construction, there exists some value `x >= c_m + c_n` which we can represent optimally using a non-greedy algorithm. Assume (falsely as we'll see) that for all values `y` under `x`, that the greedy algorithm does produce an optimal solution. 

An optimal solution for `x` will have some combination of coins that is different from that produced by the greedy algorithm.

We know immediately that the greedy algorithm will have at least as many `c_n`'s as an optimal solution by definition of the greedy algorithm. We're only interested in the case where the coins in the representation is actually different. For every `c_n` in `x` that is in the optimal representation, we can remove it from both the optimal and greedy representations and be left with a uncompromised example. If `x` breaks our coin system, it will do so even after removing however many `c_n`'s as there are in its optimal representation.

Now consider the case for a coin `c_i` that is not `c_n` in the optimal representation of `x`. The greedy algorithm for `x` includes `c_n` because `x > c_n`. Thus, the greedy algorithm for `x - c_n` uses one less coin than the greedy algorithm for `x`.

Since `x - c_n` is less than `x`, the greedy algorithm for `x - c_n` is also optimal. What happens when we remove `c_i` from this value? We don't know if `x - c_n` contains `c_i`, but we do know that the optimal representation of `x - c_n - c_i` removes at least one coin from `x - c_n`.

This places an upper bound on the number of coins in the greedy representation of `x`. It can't be more than two coins larger than the optimal representation `x - c_n - c_i`. By definition, the optimal representation of `x - c_n - c_i` can't be larger than the greedy representation of `x - c_n - c_i`. Since this representation is greedy, we can remove `c_n`, the largest value, and still have a greedy representation, this time of `x - c_i`. So the greedy representation of `x` is no more than one coin larger than the greedy representation of `x - c_i`

Hang in there! We assumed that all `y` under `x` is optimal under the greedy algorithm, so this representation of `x - c_i` is optimal as well. Interesting! The greedy representation of `x` is no more than one coin larger than the optimal representation of `x - c_i`. Now's a good time to remember what `c_i` was in the first place.

Hint, it's some coin in the optimal representation of `x`. Adding it back into `x - c_i` increases our coin count by one, but also gives us `x` back. Here's the sweet reward for your patience: the greedy algorithm for `x` produces a representation that is no larger than the optimal representation of `x`.

But the greedy algorithm also produces a representation that is no smaller than the optimal one. If it's not smaller, and it's not larger, then it must be the **same**! Here's the ultimate conclusion:

> Either the greedy algorithm always produces the optimal change, or there's some test value below `c_m + c_n` that it fails to produce it for.

The clear benefit of this insight is that we have an immediate outer loop that is bounded by the size of the largest coin. We test all values (there's actually a lower bound, but that should be easy to figure out) up to the upper bound, and if they all check out, we know the coin system cannot be broken.

## A quick and dirty test

Finding the optimal representation in an arbitrary coin system is a hard problem. The good thing is that testing whether a value breaks a coin system doesn't involve finding any optimal representations.

For a value `x`, if the greedy representation `x` minus one coin is strictly larger than the greedy representation of `x - c` for all `c < x`, then `x` is a value that breaks the coin system. In math-y terms, if `f(x)` is the number of coins in the optimal representation of `x`, and `g(x)` is the greedy one, this condition is identical to:

```
g(x) - 1 > g(x - c)
g(x) > g(x - c) + 1
```

To see why, let's say we have an optimal representation of `x`. This representation is no more than one coin larger than the optimal representation of `x - c`:

```
f(x) <= f(x - c) + 1
```

which is by definition a lower bound on the greedy representation of `x - c`:

```
f(x - c) <= g(x - c)
```

so:

```
f(x) <= g(x - c) + 1
```

Combine this with the condition on `g(x)` we assumed and we have:

```
f(x) < g(x)
```

which proves irrevocably that the optimal representation is strictly better than the greedy one.

What's the payoff here? Well we only have to compute greedy algorithms, which is easy and best of all, cheap. In fact, we can precompute all greedy values between `1` and `c_n` and it will take just `O(c_n * n)`.

Checking the condition for whether a value breaks the coin system is an `O(n)` procedure after precomputing greedy solutions since there are `n` coins to loop through for an `x`. And since we only need to test up to `c_m + c_n` values, this will take us, again, just `O(c_n * n)`. 

And that's it! An upper bound combined with a simple test condition make this a pretty simple solution when it's all said and done. Here's [my solution](https://github.com/whoshuu/weekly-noodler/tree/master/solutions/breaking-change/breaking-change.cpp).
