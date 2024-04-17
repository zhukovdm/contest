/**
 * https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/
 */

#include <vector>

using namespace std;

auto solution(vector<int> &a) -> int
{
    int result = 0;
    for (auto &&item : a) {
        result ^= item;
    }
    return result;
}
