bool is_set(int n, int i)
{
    return (n >> i) & 1;
}

int set(int n, int i)
{
    return n | (1 << i);
}

int unset(int n, int i)
{
    return -1 & ~(1 << i) & n;
}

int solution(int n)
{
    int r = 0;

    for (int i = 1; i < 31; ++i) {
        if (is_set(n, i) && is_set(n, i - 1)) {
            r = set(r, i);
            n = unset(n, i);
        }
    }

    return r;
}
