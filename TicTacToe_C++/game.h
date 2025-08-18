/*
Last Updated: 20250818
Initial Creation Date : 2025 08 18
Basic Tic Tac Toe Game
*/

#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <string>

namespace tictactoe {

	class Game {
		static constexpr size_t size = 3;
		std::string board[size][size] = {};
	public:
		Game() {};
		virtual ~Game() = default;

		void player_move(char& ch);
		bool check_win();
		void display(std::ostream& os);
	};

}

#endif // !_GAME_H_
