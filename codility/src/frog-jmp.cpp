auto solution(int x, int y, int d) -> int
{
    int offset = y - x;
    if (offset <= 0) {
        return 0;
    }
    int steps = offset / d;
    if (steps * d < offset) {
        steps += 1;
    }
    return steps;
}
