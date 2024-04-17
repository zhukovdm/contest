/**
 * https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/
 */

#include <vector>

using namespace std;

vector<int> solution(vector<int> &a, int k)
{
    vector<int> result;
    int sz = (int)a.size();
    if (sz != 0) {
        int shift = sz - (k % sz);
        for (int i = 0; i < sz; ++i) {
            result.push_back(a[(i + shift) % sz]);
        }
    }
    return result;
}
