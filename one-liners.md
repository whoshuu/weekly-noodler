# One-liners

Coding error-free on an editor, under time pressure. Challenging? What if you’re only given a white-board. Is this a nightmare? No! It’s a Python Bee.

> A Python bee is like a spelling bee but instead of spelling words contestants are asked to spell functioning programs; one character at a time. An example question might be: “Write a function that, given two integers, returns their sum.” The goal is to spell out a Python function: “d–e–f–”… and so on.
Players must spell valid Python code and every character counts, including symbols and whitespace.

The tricky part - It’s easy to lose track of how many whitespaces you’ve spelt out. Since whitespaces in Python denote blocks of code, this is very important and can easily result in an erroneous program.

Obvious solution, let's write Python programs in **one line** (Note: without using `exec` :) )

### Examples

```python
def f(x):
    return x*4
print f(3)

# Solution:
print (lambda f: f(3))(lambda x: x*4)
```

```python
def fizz(n):
    if n % 3 == 0:
        return 'Fizz'
    else:
        return ''
print fizz(15)

# Solution:
(lambda __print, __g: [(__print(fizz(15)), None)[1]
    for __g['fizz'], fizz.__name__ in
    [(lambda n: (lambda __l:
               [(lambda __after: 'Fizz' if ((__l['n'] % 3) == 0) else '')(lambda: None)
    for __l['n'] in [(n)]][0])({}), 'fizz')]][0])(__import__('__builtin__').__dict__['print'], globals())
 ```

```python
def fizzbuzz(n):
    if n % 3 == 0 and n % 5 == 0:
        return 'FizzBuzz'
    elif n % 3 == 0:
        return 'Fizz'
    elif n % 5 == 0:
        return 'Buzz'
    else:
        return ''
print fizzbuzz(15)

# Solution:
(lambda __print, __g: [(__print(fizzbuzz(15)), None)[1]
    for __g['fizzbuzz'], fizzbuzz.__name__ in
    [(lambda n: (lambda __l:
               [(lambda __after: 'FizzBuzz' if (((__l['n'] % 3) == 0) and ((__l['n'] % 5) == 0)) else
                (lambda __after: 'Fizz' if ((__l['n'] % 3) == 0) else
                (lambda __after: 'Buzz' if ((__l['n'] % 5) == 0) else '')(lambda: __after()))(lambda: __after()))(lambda: None)
    for __l['n'] in [(n)]][0])({}), 'fizzbuzz')]][0])(__import__('__builtin__').__dict__['print'], globals())
```

Observe the pattern and repetition in those examples.

**Can you write a one-liner for the following code snippet?**


```python
def puns(a, b, c):
	if a==b or b<c:
		return "Did you hear about the guy whose whole left side was cut off? He's all right now."
	elif a==b and a==c:
		return "I'm reading a book about anti-gravity. It's impossible to put down."
	elif not b!=c:
		return "Yesterday I accidentally swallowed some food coloring. The doctor says I'm OK, but I feel like I've dyed a little inside."
	else:
		return "The roundest knight at king Arthur's round table was Sir Cumference."

print puns(1, 2, 3)
```
