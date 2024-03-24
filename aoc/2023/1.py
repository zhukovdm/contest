import sys
from typing import List

def main(args:List[str]):
    sum = 0
    with open(args[1]) as file:
        for line in file:
            digits = list(filter(lambda x: x.isdigit(), line))
            sum += int(digits[0]) * 10 + int(digits[-1])
    print(sum)

main(sys.argv)
