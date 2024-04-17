/**
 * https://app.codility.com/programmers/trainings/9/sparse_binary_decomposition/
 */

bool is_set(int n, int i)
{
    return (n >> i) & 1;
}

int unset(int n, int i)
{
    return -1 & ~(1 << i) & n;
}

int solution(int n)
{
    for (int i = 1; i < 31; ++i) {
        if (is_set(n, i) && is_set(n, i - 1)) {
            n = unset(n, i);
        }
    }
    return n;
}
