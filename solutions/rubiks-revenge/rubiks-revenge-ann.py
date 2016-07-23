import copy

COLOR = {
    'White': 'White',
    'Yellow': 'Yellow',
    'Red': 'Red',
    'Blue': 'Blue',
    'Green': 'Green',
    'Orange': 'Orange'
}


class Face:
    def __init__(self, color):
        self.values = [[color, color, color],
                       [color, color, color],
                       [color, color, color]]

    def display(self):
        print self.values[0]
        print self.values[1]
        print self.values[2]
        print "\n"

    def rotate_clockwise(self):
        old_values = copy.deepcopy(self.values)
        # Corners
        self.values[0][0] = old_values[2][0]
        self.values[0][2] = old_values[0][0]
        self.values[2][2] = old_values[0][2]
        self.values[2][0] = old_values[2][2]
        # Sides
        self.values[0][1] = old_values[1][0]
        self.values[1][2] = old_values[0][1]
        self.values[2][1] = old_values[1][2]
        self.values[1][0] = old_values[2][1]

    def rotate_counter_clockwise(self):
        old_values = copy.deepcopy(self.values)
        # Corners
        self.values[0][0] = old_values[0][2]
        self.values[0][2] = old_values[2][2]
        self.values[2][2] = old_values[2][0]
        self.values[2][0] = old_values[0][0]
        # Sides
        self.values[0][1] = old_values[1][2]
        self.values[1][2] = old_values[2][1]
        self.values[2][1] = old_values[1][0]
        self.values[1][0] = old_values[0][1]

    def get_right_column(self):
        return [self.values[2][2], self.values[1][2], self.values[0][2]]

    def get_left_column(self):
        return [self.values[2][0], self.values[1][0], self.values[0][0]]

    def get_bottom_row(self):
        return self.values[2]

    def get_top_row(self):
        return self.values[0]

    def replace_right(self, row_list):
        right = copy.deepcopy(self.get_right_column())
        self.values[0][2] = row_list[0]
        self.values[1][2] = row_list[1]
        self.values[2][2] = row_list[2]
        return right

    def replace_left(self, row_list):
        left = copy.deepcopy(self.get_left_column())
        self.values[0][0] = row_list[0]
        self.values[1][0] = row_list[1]
        self.values[2][0] = row_list[2]
        return left

    def replace_bottom(self, row):
        bottom = copy.deepcopy(self.get_bottom_row())
        self.values[2] = row
        return bottom

    def replace_top(self, row):
        top = copy.deepcopy(self.get_top_row())
        self.values[0] = row
        return top

    def solid(self):
        return (self.values[0] == self.values[1]
                and self.values[1] == self.values[2]
                and self.values[0][0] == self.values[0][1]
                and self.values[0][1] == self.values[0][2])


class Cube:
    def __init__(self):
        self.front = Face(COLOR['White'])
        self.back = Face(COLOR['Yellow'])
        self.left = Face(COLOR['Orange'])
        self.right = Face(COLOR['Red'])
        self.top = Face(COLOR['Blue'])
        self.bottom = Face(COLOR['Green'])

    def display(self):
        for row in self.top.values:
            print row

        for i in range(0, 3):
            print (self.left.values[i], self.front.values[i],
                self.right.values[i], self.back.values[i])

        for row in self.bottom.values:
            print row

    def rotate_clockwise(self):
        self.front.rotate_clockwise()
        right_column_of_left_face = self.left.get_right_column()
        bottom_row_of_top_face = self.top.replace_bottom(
            right_column_of_left_face)
        left_column_of_right_face = self.right.replace_left(
            bottom_row_of_top_face)
        top_row_of_bottom_face = self.bottom.replace_top(
            left_column_of_right_face)
        self.left.replace_right(top_row_of_bottom_face)

    def turn_left(self):
        self.top.rotate_clockwise()
        self.bottom.rotate_counter_clockwise()
        old_front = copy.deepcopy(self.front)
        self.front = self.right
        self.right = self.back
        self.back = self.left
        self.left = old_front

    def check_solved(self):
        return (self.front.solid()
                and self.back.solid()
                and self.left.solid()
                and self.right.solid()
                and self.top.solid()
                and self.bottom.solid())


cube = Cube()

moves = 0
while True:
    cube.rotate_clockwise()
    cube.turn_left()
    moves += 1

    if cube.check_solved():
        break

print "It would have taken {} moves to return back to the solved cube!".format(
    moves)