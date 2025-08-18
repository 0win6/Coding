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

def tie(board):
    for row in board:
        if " " in row:
            return False
    return True

def get_winner(board):
    for r in board:
        if r[0] != " " and r[0] == r[1] == r[2]:
            return r[0]
        
    for c in range(3):
        if board[0][c] != " " and board[0][c] == board[1][c] == board[2][c]:
            return board[0][c]
    
    if board[0][0] != " " and board[0][0] == board[1][1] == board[2][2]:
        return board[0][0]
    if board[0][2] != " " and board[0][2] == board[1][1] == board[2][0]:
        return board[0][2]
    
    return None

def tictactoe():
    board = game_board()
    player = "X"
    winner = None

    while True:
        display(board)

        player_move(board,player)

        winner = get_winner(board)
        if winner:
            display(board)
            print(f"\n Player {winner} wins!")
            break
        elif tie(board):
            display(board)
            print("\n Draw!")
            break

        player = "O" if player == "X" else "X"

tictactoe()