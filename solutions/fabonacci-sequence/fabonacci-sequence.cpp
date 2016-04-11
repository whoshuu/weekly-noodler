#include <cstdint>
#include <iostream>
#include <unordered_map>


std::int64_t fib(std::int64_t n) {
    static std::unordered_map<std::int64_t, std::int64_t> cache;

    if (n <= 1) {
        return n;
    }

    if (cache.find(n) != cache.end()) {
        return cache.at(n);
    }

    if (cache.find(n - 1) == cache.end()) {
        cache[n - 1] = fib(n - 1);
    }

    if (cache.find(n - 2) == cache.end()) {
        cache[n - 2] = fib(n - 2);
    }

    return cache[n - 1] + cache[n - 2];
}

std::int64_t fab(std::int64_t i, std::int64_t n) {
    return fib(n - i + 1);
}

int main() {
    std::int64_t n = 50;
    for (std::int64_t i = 1 ; i <= n; ++i) {
        std::cout << fab(i, n) << std::endl;
    }
}
