# Breaking Change

In the distant past, before credit cards and Paypal, people used to pay for goods and services using something called _cash_. Paying for a good or service with more than the exact amount of cash required would trigger a process where the buyer receives _change_ from the seller.

For instance, buying a $0.40 candy bar with $1.00 would entitle you to $0.60 in change. In the US coin system, there are `1`, `5`, `10`, and `25` cent coin denominations. To optimize for providing change using the fewest total number of coins, the seller would give you **two** `25` cent coins, and **one** `10` cent coin. To be more precise:

> The optimal change is the fewest number of coins in their various denominations that add up to an exact value.

Humans are quite good at this optimization, and with the US coin system, computers are pretty good at this too. In an **arbitrary** coin system however, things get a bit trickier.

Let's assume you're on Mars and the coins happen to be in `1`, `3`, and `4` cent denominations. You buy a $0.94 Martian candy bar from Musk Corporation with $1.00, and are entitled to $0.06 change.

Using the greedy approach where the largest coins are selected first, you would be handed **one** `4` cent coin, and **two** `1` cent coins, for a total of **three** coins. Upon inspection, the optimal change is actually just **two** `3` cent coins.

Obviously, we can't predict the future, so there's no way for us to know in advanced what coin system a future Martian civilization would adopt. We can, however, write software that can validate if a coin system can be used to produce optimal change using just the greedy algorithm.

Given a list of integers such as:

```
1, 3, 4, 8, 23
```

representing a hypothetical coin system, your goal is to determine whether the greedy algorithm always produces the optimal change. Further, for coin systems where the greedy algorithm fails, can you find the smallest amount of change it fails to produce optimally?

Assume that the smallest denomination is always `1`.
