/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1012
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <ranges>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

template <typename T>
class big_num {
public:
    std::vector<T> digits_;

    big_num()
    {
    }

    big_num(T num)
    {
        while (num > 0) {
            digits_.push_back(num % 10);
            num /= 10;
        }
    }

    big_num &operator*(T num)
    {
        T carry = 0;

        for (int i = 0; i < std::ssize(digits_); ++i) {
            T prod = digits_[i] * num + carry;
            digits_[i] = prod % 10;
            carry = prod / 10;
        }

        while (carry > 0) {
            digits_.push_back(carry % 10);
            carry /= 10;
        }

        return *this;
    }

    auto to_string() -> std::string
    {
        std::string result;
        for (auto &&digit : std::ranges::reverse_view(digits_)) {
            result += std::to_string(digit);
        };
        return result;
    }
};

template <typename T>
auto operator+(const big_num<T> &lhs, const big_num<T> &rhs) -> big_num<T>
{
    big_num<T> res;
    int i;
    T carry = 0;

    for (i = 0; i < std::min(std::ssize(lhs.digits_), std::ssize(rhs.digits_)); ++i) {
        T sum = lhs.digits_[i] + rhs.digits_[i] + carry;
        res.digits_.push_back(sum % 10);
        carry = sum / 10;
    }

    auto &longer_num = (std::ssize(lhs.digits_) > std::ssize(rhs.digits_)) ? lhs : rhs;

    for (; i < std::ssize(longer_num.digits_); ++i) {
        T sum = longer_num.digits_[i] + carry;
        res.digits_.push_back(sum % 10);
        carry = sum / 10;
    }

    while (carry > 0) {
        res.digits_.push_back(carry % 10);
        carry /= 10;
    }

    return res;
}

auto func(int n, int k) -> big_num<int>
{
    big_num<int> v0(1), vk(k - 1);

    for (int i = 2; i <= n; ++i) {
        auto v0_new = vk;
        auto vk_new = (v0 * (k - 1)) + (vk * (k - 1));
        v0 = std::move(v0_new);
        vk = std::move(vk_new);
    }

    return vk;
}

auto main(int, char **) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    auto x = func(n, k).to_string();
    std::cout << x << '\n';

    return 0;
}
