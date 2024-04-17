/**
 * https://app.codility.com/programmers/trainings/5/parity_degree/
 */

int solution(int n)
{
    int cnt = 0;
    while ((n & 1) == 0) {
        ++cnt;
        n >>= 1;
    }
    return cnt;
}
