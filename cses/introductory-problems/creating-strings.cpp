/**
 * https://cses.fi/problemset/task/1622
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

#define ABC_LEN 26

int fact(int n)
{
    int result = 1;

    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}

void perm(string &word, size_t idx, set<string> &buffer)
{
    if (idx == word.size()) {
        buffer.insert(word);
    }
    else {
        for (size_t i = idx; i < word.size(); ++i) {
            if (i == idx || word[i] != word[idx]) {
                swap(word[i], word[idx]);
                perm(word, idx + 1, buffer);
                swap(word[i], word[idx]);
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    cin >> word;

    set<string> buffer;

    int abc[ABC_LEN] = {};
    for (auto &&ch : word) {
        ++abc[ch - 'a'];
    }

    int cnt = fact(word.size());
    for (int i = 0; i < ABC_LEN; ++i) {
        cnt /= fact(abc[i]);
    }

    cout << cnt << '\n';

    perm(word, 0, buffer);
    for (auto &&p : buffer) {
        cout << p << '\n';
    }

    return 0;
}
