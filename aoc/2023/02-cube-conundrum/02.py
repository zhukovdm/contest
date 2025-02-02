"""
    https://adventofcode.com/2023/day/2
"""

import sys
from typing import List

def main(args: List[str]) -> None:
    with open(args[1]) as file:
        result = 0
        for line in file:
            r = 0
            g = 0
            b = 0
            for sep in [":", ";", ","]:
                line = line.replace(sep, " ")
            line = list(filter(lambda word: word != "", line.strip().split(" ")))
            for i in range(2, len(line), 2):
                inc = int(line[i])
                match line[i + 1]:
                    case "red":
                        r = max(r, inc)
                    case "green":
                        g = max(g, inc)
                    case "blue":
                        b = max(b, inc)
            result += r * g * b
        print(result)

main(sys.argv)
