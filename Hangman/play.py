################
# Last updated: 20250818
# Intial Creation Date : 2025 08 18
# Hang Man
################

import random
words = ["TWIZZLERS","AWESOME","AI","MYSTERIOUS","RANDOM","RHYTHM","TRYST","SHHHHHH","GRRRRRR"]
secret_word = random.choice(words)

lives = 6
word_size = len(secret_word)

def create_board():
    return ["_" for char in secret_word]

def player_guess():
    return input("Guess a letter: ").upper()

def check_board(board, guess, lives):
    guessed = guess in board
    if guessed:
        print("\nYou already guessed that letter.")
        return False, lives

    found = False
    for i in range(word_size):
        if secret_word[i] == guess:
            board[i] = guess
            found = True

    if not found:
        lives -= 1
        print(f"Wrong guess! Lives left: {lives}")
    return found, lives
    
board = create_board()

while lives > 0 and "_" in board:
    print("\n"+" ".join(board))
    guess = player_guess()

    found, lives = check_board(board, guess, lives)

if "_" not in board:
    print("\nCongratulations! You Won!")
    print("The word was: ",secret_word)
else:
    print("You Lost!")