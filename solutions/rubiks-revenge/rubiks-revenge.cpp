#include <array>
#include <iostream>

enum class Color {
    White,
    Yellow,
    Red,
    Blue,
    Green,
    Orange
};

using Row = std::array<Color, 3>;

std::ostream& operator<<(std::ostream& os, const Color& color) {
    switch(color) {
      case(Color::White):
        os << "W";
        break;
      case(Color::Yellow):
        os << "Y";
        break;
      case(Color::Red):
        os << "R";
        break;
      case(Color::Blue):
        os << "B";
        break;
      case(Color::Green):
        os << "G";
        break;
      case(Color::Orange):
        os << "O";
        break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Row& row) {
    for (const auto& color : row) {
        os << color;
    }

    return os;
}

class Face {
  public:
    Face(const Color& color) {
        values_.fill({{color, color, color}});
    }

    void display() {
        for (const auto& row : values_) {
            std::cout << row << std::endl;
        }
    }

    void rotate_clockwise() {
        const auto old = values_;
        // Corners
        values_[0][0] = old[2][0];
        values_[0][2] = old[0][0];
        values_[2][2] = old[0][2];
        values_[2][0] = old[2][2];
        // Sides
        values_[0][1] = old[1][0];
        values_[1][2] = old[0][1];
        values_[2][1] = old[1][2];
        values_[1][0] = old[2][1];
    }

    void rotate_counter_clockwise() {
        const auto old = values_;
        // Corners
        values_[0][0] = old[0][2];
        values_[0][2] = old[2][2];
        values_[2][2] = old[2][0];
        values_[2][0] = old[0][0];
        // Sides
        values_[0][1] = old[1][2];
        values_[1][2] = old[2][1];
        values_[2][1] = old[1][0];
        values_[1][0] = old[0][1];
    }

    Row get_right_column() const {
        return {{values_[2][2], values_[1][2], values_[0][2]}};
    }

    Row get_left_column() const {
        return {{values_[2][0], values_[1][0], values_[0][0]}};
    }

    Row get_bottom_row() const {
        return values_[2];
    }

    Row get_top_row() const {
        return values_[0];
    }

    Row replace_right(const Row& row) {
        const auto right = get_right_column();
        values_[0][2] = row[0];
        values_[1][2] = row[1];
        values_[2][2] = row[2];
        return right;
    }

    Row replace_left(const Row& row) {
        const auto left = get_left_column();
        values_[0][0] = row[0];
        values_[1][0] = row[1];
        values_[2][0] = row[2];
        return left;
    }

    Row replace_bottom(const Row& row) {
        const auto bottom = get_bottom_row();
        values_[2] = row;
        return bottom;
    }

    Row replace_top(const Row& row) {
        const auto top = get_top_row();
        values_[0] = row;
        return top;
    }

    bool solid() const {
        return values_[0] == values_[1] && values_[1] == values_[2] &&
               values_[0][0] == values_[0][1] && values_[0][1] == values_[0][2];
    }

    std::array<Row, 3> values_;
};

class Cube {
  public:
    Cube() : front_(Color::White), back_(Color::Yellow), left_(Color::Orange), right_(Color::Red),
             top_(Color::Blue), bottom_(Color::Green) {}

    void display() {
        for (const auto& row : top_.values_) {
            std::cout << "   " << row << std::endl;
        }

        for (int i = 0; i < 3; ++i) {
            std::cout << left_.values_[i] << front_.values_[i] << right_.values_[i]
                      << back_.values_[i] << std::endl;
        }

        for (const auto& row : bottom_.values_) {
            std::cout << "   " << row << std::endl;
        }
    }

    void rotate_clockwise() {
        front_.rotate_clockwise();
        const auto right_column_of_left_face = left_.get_right_column();
        const auto bottom_row_of_top_face = top_.replace_bottom(right_column_of_left_face);
        const auto left_column_of_right_face = right_.replace_left(bottom_row_of_top_face);
        const auto top_row_of_bottom_face = bottom_.replace_top(left_column_of_right_face);
        left_.replace_right(top_row_of_bottom_face);
    }

    void turn_left() {
        top_.rotate_clockwise();
        bottom_.rotate_counter_clockwise();
        const auto front = front_;
        front_ = right_;
        right_ = back_;
        back_ = left_;
        left_ = front;
    }

    bool check_solved() const {
        return front_.solid() && back_.solid() && left_.solid() && right_.solid() && top_.solid() &&
               bottom_.solid();
    }

    Face front_;
    Face back_;
    Face left_;
    Face right_;
    Face top_;
    Face bottom_;
};

int main() {
    Cube cube;

    int moves = 0;
    while (true) {
        cube.rotate_clockwise();
        cube.turn_left();
        cube.display();
        ++moves;
        if (cube.check_solved()) {
            break;
        }
    }
    std::cout << "It would have taken " << moves << " moves to return back to the solved cube!"
              << std::endl;
}
