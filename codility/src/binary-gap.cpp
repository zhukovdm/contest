#include <algorithm>
using namespace std;

int solution(int N)
{
    int max_gap = 0, gap_idx = (int)1e9;
    for (int i = 0; i < 32; ++i) {
        if (N >> i & 1) {
            max_gap = max(max_gap, i - gap_idx - 1);
            gap_idx = i;
        }
    }
    return max_gap;
}
