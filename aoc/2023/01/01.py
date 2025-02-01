import sys, re
from typing import List

def main(args: List[str]) -> None:
    sum = 0
    dic = {
        "one": "1",
        "two": "2",
        "three": "3",
        "four": "4",
        "five": "5",
        "six": "6",
        "seven": "7",
        "eight": "8",
        "nine": "9"
    }
    reg = r"(?=(1|2|3|4|5|6|7|8|9|one|two|three|four|five|six|seven|eight|nine))"

    with open(args[1]) as file:
        for line in file:
            lst = [dic.get(word, word) for word in re.findall(reg, line)]
            sum += 10 * int(lst[0]) + int(lst[-1])

    print(sum)

main(sys.argv)
