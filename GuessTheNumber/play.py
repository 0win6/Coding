################
# Last updated: 20250818
# Intial Creation Date : 2025 08 18
# Basic Guess The Number
################
import random

mystery = random.randint(1,1000)

def guessthenumber(number):
    turns = 10
    while True and turns > 0:
        try:
            move = input(f"Guess the number (Moves left: {turns}): ")
            guess = int(move)

            if not 1 <= guess <= 1000:
                raise ValueError
            
            if guess == number:
                print(f"You win! Mystery number is {number}")
                break
            else:
                turns -= 1
                if turns == 0:
                    print("Game Over. You Lose!")
                if guess > number:
                    print("Lower!")
                else:
                    print("Higher!")
        except (ValueError):
            print("Invalid input. Please enter between 1 and 1000.")

guessthenumber(mystery)