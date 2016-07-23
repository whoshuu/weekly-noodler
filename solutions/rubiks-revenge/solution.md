# Rubik's Revenge Solution

This is a problem in bookkeeping and proper modelling than anything else. Since you shouldn't expect the algorithm to be computationally expensive, it's wise to choose the simplest, most intuitive class design for the Rubik's cube.

I chose to do this using a class that represents the entire cube, and gave that six member fields representing each face of the cube. A face is just a 3x3 matrix of colors, which can be represented using an `enum` in C++.

There are two relevant operations that need to be performed on the cube.

The first operation is a clockwise rotation of the front face on the cube. Imagine a cube in front of you, this rotation does only two things:

1. The front face colors are shifted 90 degrees to the left.
2. Each other face besides the front and back ones lose three colors to the face in the clockwise direction and gain three colors from the face in the counter clockwise direction.

and that's it. Note that the back face is totally unchanged -- this would be a good unit test to write if you take the test driven development route.

The second operation is turning the entire cube to the left. If you define a face's color matrix as the way the face looks if you're seeing it straight on, then it's easy to break down what happens in a turning operation:

1. The front, left, right, and back faces just swap with each other. What was originally the right face is now the front face, what was the back face is now the right face, and so on.
2. The top face is rotated clockwise.
3. The bottom face is rotated counter clockwise.

Since this operation doesn't change the **relative** positioning of each face and color, this actually doesn't count as a move.

Everytime you perform these two operations, you tick up a counter for number of moves just once, and check if the cube is solved. Simply continuing until this process is complete gives us the final answer: it takes 1260 moves to return the cube to the solved position! Assuming a generous constant time of 1 second per move, this would have taken us 21 minutes to do! You can see the full implementation [here](https://github.com/whoshuu/weekly-noodler/tree/master/solutions/rubiks-revenge/rubiks-revenge.cpp).

Bonus: A 4x4x4 cube would have taken the same number of moves to complete the algorithm. In fact, such a cube is exactly identical to a 3x3x3 cube as long as the middle is never twisted.
