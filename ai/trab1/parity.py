from types import Board

def parity_check(puzzle_board: Board) -> bool:
    # An 8 puzzle board. For each item in the matrix, check how many items are smaller than it and to the right of it. If the total number of inversions is odd, then the puzzle is unsolvable.
    count = 0
    for i in range(len(puzzle_board)):
        for j in range(len(puzzle_board[i])):
            current_value = puzzle_board[i][j]
            if current_value == 0:
                continue
            for k in range(i, len(puzzle_board)):
                for l in range(j, len(puzzle_board[i])):
                    if current_value < puzzle_board[k][l]:
                        count += 1
    return count % 2 == 0