#!/usr/bin/python3
""" 0. N queens """
from sys import argv


def validate() -> None:
    """checking num"""
    if (len(argv) != 2):
        print('Usage: nqueens N') or exit(1)
    try:
        num = int(argv[1])
    except ValueError:
        print('N must be a number') or exit(1)
    if (num < 4):
        print('N must be at least 4') or exit(1)
    nqueens(0, num)


def nqueens(j: int, num: int) -> None:
    """algo"""
    table = [num * [0] for i in range(num)]
    col = []
    diag_right = []
    diag_left = []
    dd = []
    create_table(j, num, 0, table, diag_right, diag_left, col, dd)


def create_table(j: int, num: int, bol: int, table: int, diag_right: list,
                 diag_left: list, col: list, dd: list) -> None:
    """testing"""
    if bol == 0:
        i = 0
    else:
        i = num - 1
    while (i < num):
        flag = 0
        while (j < num):
            if check(num, i, j, diag_right, diag_left, col):
                table[i][j] = 1
                diag_right.append(i - j)
                diag_left.append((num - 1) - (i + j))
                col.append(j)
                dd.append([i, j])
                flag = 1
                break
            j += 1
        if flag == 0:
            try:
                idx = table[i - 1].index(1)
            except ValueError:
                return
            table[i - 1][idx] = 0
            diag_right.pop()
            diag_left.pop()
            col.pop()
            dd.pop()
            i -= 1
            j = idx + 1
            continue
        j = 0
        i += 1
    if i == num and flag == 0:
        return
    print(dd)
    idx = table[i - 1].index(1)
    table[i - 1][idx] = 0
    diag_right.pop()
    diag_left.pop()
    col.pop()
    dd.pop()
    create_table(idx + 1, num, 1, table, diag_right, diag_left, col, dd)


def check(num: int, i: int, j: int,
          right: list, left: list, col: list) -> bool:
    """validating"""
    # Diagonal right
    if (i - j) in right:
        return (False)
    # Diagonal left
    if ((num - 1) - (j + i)) in left:
        return (False)
    # Column
    if j in col:
        return (False)
    return (True)


if __name__ == '__main__':
    validate()
