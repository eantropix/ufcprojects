from parity import parity_check
from types import Board

def is_solvable(puzzle_board: Board) -> bool:
    return parity_check(puzzle_board)

def main():
    puzzle_board = [
        [1, 2, 3],
        [5, 6, 0],
        [7, 8, 4]
    ]
    print(is_solvable(puzzle_board))