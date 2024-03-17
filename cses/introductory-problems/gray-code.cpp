/**
 * https://cses.fi/problemset/task/2205
 */

#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

void gray1(std::vector<int> &buffer, int level, bool reflect)
{
    if (level == 0) {
        for (auto &&digit : buffer) {
            std::cout << digit;
        }
        std::cout << '\n';
    }
    else {

        auto fst = (reflect) ? 1 : 0;
        auto snd = 1 - fst;

        buffer.push_back(fst);
        gray1(buffer, level - 1, false);
        buffer.pop_back();

        buffer.push_back(snd);
        gray1(buffer, level - 1, true);
        buffer.pop_back();
    }
}

auto gray2(std::string &word, int level) -> void
{
    if (level >= 0) {
        gray2(word, level - 1);

        auto idx = word.size() - level - 1;

        word[idx] = (word[idx] == '0') ? '1' : '0';
        std::cout << word << '\n';

        gray2(word, level - 1);
    }
}

auto main(int, char **) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int level;
    std::cin >> level;

    std::vector<int> buffer;

    gray1(buffer, level, false);

    // int level;
    // std::cin >> level;

    // std::string word(level, '0');

    // std::cout << word << '\n';
    // gray2(word, level - 1);

    return 0;
}
