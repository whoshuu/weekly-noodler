(lambda __g, __print: [(__print(puns(1, 2, 3)), None)[1]
        for __g['puns'], puns.__name__ in
        [(lambda a, b, c: (lambda __l:
                        [(lambda __after: "Did you hear about the guy whose whole left side was cut off? He's all right now." if ((__l['a'] == __l['b']) or (__l['b'] < __l['c'])) else
                         (lambda __after: "I'm reading a book about anti-gravity. It's impossible to put down." if ((__l['a'] == __l['b']) and (__l['a'] == __l['c'])) else
                         (lambda __after: "Yesterday I accidentally swallowed some food coloring. The doctor says I'm OK, but I feel like I've dyed a little inside."
                         if (not (__l['b'] != __l['c'])) else "The roundest knight at king Arthur's round table was Sir Cumference.")(lambda: __after()))(lambda: __after()))(lambda: None)
        for __l['a'], __l['b'], __l['c'] in [(a, b, c)]][0])({}), 'puns')]][0])(globals(), __import__('__builtin__').__dict__['print'])