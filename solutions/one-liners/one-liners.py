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


print (lambda a, b, c:
    "Did you hear about the guy whose whole left side was cut off? He's all right now."
    if (a == b or b < c) else
    ("Yesterday I accidentally swallowed some food coloring. The doctor says I'm OK, but I feel like I've dyed a little inside."
    if (b == c) else
    ("The roundest knight at king Arthur's round table was Sir Cumference.")))(1, 2, 3)
