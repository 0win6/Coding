/*
Last Updated: 20250818
Initial Creation Date : 2025 08 18
Basic Tic Tac Toe Game
*/

#include <iostream>
#include <limits>
#include "game.h"

const size_t SIZE = 3;

namespace tictactoe {

	void Game::player_move(char& ch) {
		int r{}, c{};

		while (true) {
			std::cout << "Player " << ch << " Enter your move (row,col)> ";
			std::cin >> r >> c;

			if (std::cin.fail()) {
				std::cout << "Invalid input. Please enter two numbers." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			if (r >= 1 && r <= 3 && c >= 1 && c <= 3) {
				r -= 1;
				c -= 1;

				if (board[r][c] == "") {
					board[r][c] = std::string(1,ch);
					break;
				}
				else 
					std::cout << "Cell already taken. Try again." << std::endl;
			}
			else
				std::cout << "Invalid move. Row and column must be between 1 and 3." << std::endl;
		}
	};

	bool Game::check_win() {
		for (int i = 0; i < size; ++i) {
			if (!board[i][0].empty() && board[i][0] == board[i][1] && board[i][1] == board[i][2])
				return true;
			if (!board[0][i].empty() && board[0][i] == board[1][i] && board[1][i] == board[2][i])
				return true;
		}

		if (!board[0][0].empty() && board[0][0] == board[1][1] && board[1][1] == board[2][2])
			return true;
		if (!board[0][2].empty() && board[0][2] == board[1][1] && board[1][1] == board[2][0])
			return true;

		return false;
	};

	void Game::display(std::ostream& os) {
		os << "\n    1   2   3" << std::endl;
		os << "  +---+---+---+" << std::endl;
		for (size_t i = 0; i < size; i++) {
			os << i + 1 << " |"
				<< " " << (board[i][0].empty() ? " " : board[i][0]) << " |"
				<< " " << (board[i][1].empty() ? " " : board[i][1]) << " |"
				<< " " << (board[i][2].empty() ? " " : board[i][2]) << " |" << std::endl;
			os << "  +---+---+---+" << std::endl;
		}
	};
}

int main() {
	tictactoe::Game game;
	char player = 'X';
	bool winner = false;
	int turn = 0;

	while (!winner and turn < 9){
		game.display(std::cout);
		game.player_move(player);
		winner = game.check_win();
		turn++;

		if (!winner)
			player = (player == 'X') ? 'O' : 'X';
	}

	game.display(std::cout);
	if (winner)
		std::cout << "\nCongratulations! Player " << player << " wins!" << std::endl;
	else
		std::cout << "\nDraw!" << std::endl;

	return 0;
}