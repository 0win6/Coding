################
# Last updated: 20250817
################

def game_board():
    return [ [" " for _ in range(3)] for _ in range(3)]

board = game_board()

def display(board):
    print("\n   1   2   3")
    for i, row in enumerate(board):
        print(f" {i + 1} " + " | ".join(row))
        if i < 2:
            print("  ---+---+---")

display(board)

def player_move(board, player):
    while True:
        try:
            move = input(f"Player {player}, enter your move (row and column): ")
            row, col = map(int, move.split(','))

            row -= 1
            col -= 1

            if board[row][col] == " ":
                board[row][col] = player
                break
            else:
                print("Cell already taken. Try again.")
        except (ValueError):
            print("Invalid input. Please enter row and column as two numbers between 1 and 3.")