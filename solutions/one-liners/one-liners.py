"""
Can you write a one-liner for the following code snippet?

def puns(a, b, c):
    if a==b or b<c:
        return "Did you hear about the guy whose whole left side was cut off? He's all right now."
    elif a==b and a==c:
        ######### don't think this case will ever happen
        return "I'm reading a book about anti-gravity. It's impossible to put down."
    elif not b!=c:
        ######### logically, if b == c
        return "Yesterday I accidentally swallowed some food coloring. The doctor says I'm OK, but I feel like I've dyed a little inside."
    else:
        return "The roundest knight at king Arthur's round table was Sir Cumference."

print puns(1, 2, 3)
"""


(lambda __print, __g: [(__print(puns(1, 2, 3)), None)[1]
    for __g['puns'], puns.__name__ in
    [(lambda a, b, c: (lambda __l:
               [(lambda __after: ("Did you hear about the guy whose whole left side was cut off? "
                    "He's all right now.")
                 if ((__l['n'][0] == __l['n'][1]) or (__l['n'][1] < __l['n'][2])) else
                (lambda __after: ("Yesterday I accidentally swallowed some food coloring. The "
                    "doctor says I'm OK, but I feel like I've dyed a little inside.")
                 if (__l['n'][1] == __l['n'][2]) else
                "The roundest knight at king Arthur's round table was Sir Cumference.")
    (lambda: __after()))(lambda: None)
    for __l['n'] in [(a, b, c)]][0])({}), 'puns')]][0])(__import__('__builtin__').__dict__['print'], globals())


assert puns(1, 2, 3) == "Did you hear about the guy whose whole left side was cut off? He's all right now."
assert puns(1, 2, 2) == "Yesterday I accidentally swallowed some food coloring. The doctor says I'm OK, but I feel like I've dyed a little inside."
assert puns(1, 2, 1) == "The roundest knight at king Arthur's round table was Sir Cumference."
