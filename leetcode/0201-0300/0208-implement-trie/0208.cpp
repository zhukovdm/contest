/**
 * https://leetcode.com/problems/implement-trie-prefix-tree/
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
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

class Trie {
private:
    static const char BASE = 'a';
    static const std::size_t SIZE = 26;

    template <std::size_t N>
    class Node {
    public:
        bool term_;
        std::vector<Node *> edges_;

        Node() : term_(false), edges_(N, nullptr)
        {
        }

        auto add(int idx) -> Node *
        {
            return (edges_[idx] != nullptr) ? edges_[idx] : (edges_[idx] = new Node());
        }
    };

    Node<SIZE> *root_;

public:
    Trie() : root_(new Node<SIZE>()) /* ! */
    {
    }

    auto insert(string word) -> void
    {
        auto node = root_;

        for (auto &&l : word) {
            node = node->add((int)l - (int)BASE);
        }
        node->term_ = true;
    }

    auto search(string word) -> bool
    {
        auto node = root_;

        for (auto const &l : word) {
            node = node->edges_[(int)l - (int)BASE];
            if (node == nullptr) {
                return false;
            }
        }
        return node->term_;
    }

    auto startsWith(string prefix) -> bool
    {
        auto node = root_;

        for (auto const &l : prefix) {
            node = node->edges_[(int)l - (int)BASE];
            if (node == nullptr) {
                return false;
            }
        }
        return true;
    }
};

auto main(int, char **) -> int
{
    std::string word("word");

    Trie *t = new Trie();

    Trie t1;

    return 0;
}
