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
