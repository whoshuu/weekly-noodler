# Rubik's Revenge

A fascinating property of the Rubik's cube is that, from a solved state, any finite algorithm, when repeated over and over, will eventually solve the cube again. A proof of why is left to the reader (it's utterly satisfying to discover yourself).

On bus rides to and from middle school, us cubers would often challenge each other to a simple game. Two of us would exchange algorithms that were reasonably short and easy to remember, and see which one would get back to a solved state first.

This would go on for good while, until one of us discovered the complete game breaker. This algorithm is devastatingly simple, but not one of us had managed to complete the challenge in the time it took to get to or from school. We eventually banned it from the challenge.

Today, we have computers, and it's time we figured out exactly **how long** it would have taken us to complete the loop for this algorithm.

Imagine you're looking at a cube from the top (white) down (yellow is the furthest color from you). You rotate this face clockwise and then turn the entire cube 90 degrees to the left. Take a look at [this animation](http://jsfiddle.net/dep55top/) if you're having trouble visualizing this. That's the entire algorithm. Each iteration of the algorithm only counts as one move since turning the cube doesn't affect its state.

How many moves does it take for this algorithm to solve the cube again?

Bonus: does your answer change for a 4x4x4 cube?
