#include <iostream>
#include <vector>

int find_max_folds(std::vector<int> input) {
    if (input.size() <= 1) {
        // Handles null and single element case
        return input.size();
    }

    // At this point we know input has at least 2 elements
    int sign = 0;
    int max_folds = 1;

    for (auto left = input.cbegin(); left != input.cend() - 1; ++left) {
        auto right = left + 1;
        // Always skip consecutive elements
        if (*left != *right) {
            // If a fold hasn't been found yet
            if (sign == 0) {
                if (*right > *left) {
                    sign = 1;
                } else {
                    sign = -1;
                }
                ++max_folds;
            }

            if ((*right - *left) * sign < 0) {
                sign *= -1;
                ++max_folds;
            }
        }
    }

    return max_folds;
}

int main() {
    std::cout << find_max_folds(std::vector<int>{}) << std::endl;
    std::cout << find_max_folds(std::vector<int>{1}) << std::endl;
    std::cout << find_max_folds(std::vector<int>{1, 1}) << std::endl;
    std::cout << find_max_folds(std::vector<int>{1, 2}) << std::endl;
    std::cout << find_max_folds(std::vector<int>{1, 2, 1}) << std::endl;
    std::cout << find_max_folds(std::vector<int>{1, 2, 2, 1}) << std::endl;
    std::cout << find_max_folds(std::vector<int>{1, 2, 1, 2, 1}) << std::endl;
    std::cout << find_max_folds(std::vector<int>{1, 2, 3, 2, 3}) << std::endl;
    std::cout << find_max_folds(std::vector<int>{3, 6, 1, 2, 4, 3, 5, 5, 6, 1, 8, 3}) << std::endl;
}
