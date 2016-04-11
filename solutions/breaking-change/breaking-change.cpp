#include <cassert>
#include <iostream>
#include <random>
#include <set>
#include <unordered_map>
#include <utility>


std::set<int> random_coin_system() {
    std::random_device random;
    std::mt19937 generator(random());
    std::uniform_int_distribution<int> distribution(2, 500000);

    std::set<int> coins;
    coins.insert(1);
    while (coins.size() < 50) {
        coins.insert(distribution(generator));
    }

    return coins;
}

std::pair<int, int> range_to_test(const std::set<int>& coins) {
    assert(coins.size() >= 3);
    auto first = coins.begin();
    ++first;
    ++first;
    return std::pair<int, int>{*first + 2, *(coins.rbegin()) + *(++coins.rbegin())};
}

int greedy(const std::set<int>& coins, const int starting_value,
           std::unordered_map<int, int>& cache) {
    int number_of_coins = 0;

    if (cache.find(starting_value) != cache.end()) {
        return cache.at(starting_value);
    }

    int value = starting_value;

    while (value > 0) {
        if (cache.find(value) != cache.end()) {
            number_of_coins += cache.at(value);
            value = 0;
        } else {
            auto coin = *(--coins.upper_bound(value));
            value -= coin;
            ++number_of_coins;
        }

        if (cache.find(starting_value - value) == cache.end()) {
            cache[starting_value - value] = number_of_coins;
        }
    }

    return number_of_coins;
}

bool check_if_breaks(const std::set<int>& coins, const int starting_value,
                    std::unordered_map<int, int>& cache) {
    auto starting_greedy = greedy(coins, starting_value, cache);
    bool b = false;
    for (auto coin : coins) {
        if (coin <= starting_value) {
            auto g = greedy(coins, starting_value - coin, cache);

            b |= (starting_greedy > g + 1);
        }
    }
    return b;
}

int main() {
    auto coins = random_coin_system();
    auto range = range_to_test(coins);

    std::unordered_map<int, int> cache;

    bool b = false;
    for (int test = range.first; test < range.second; ++test) {
        if (check_if_breaks(coins, test , cache)) {
            std::cout << "Test value of " << test << " breaks the greedy algorithm" << std::endl;
            break;
        }
    }

    for (const auto coin : coins) {
        std::cout << coin << " ";
    }

    if (b) {
        std::cout << "has the property that the greedy algorithm always produces the optimal change"
                  << std::endl;
    } else {
        std::cout << "does not have the property that the greedy algorithm always produces the "
                     "optimal change"
                  << std::endl;
    }
}
