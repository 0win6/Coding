#pragma once
#ifndef _GAME_H_
#define _GAME_H_

namespace hangman {
	class Game {
		std::string secret_word = {};
		size_t lives = {};
		size_t word_len = {};
		std::string guessed_word = {};
		std::vector<char> guessed_letters;
	public:
		Game(const std::string& word);
		virtual ~Game() = default;

		bool player_guess(char l);

		bool isOver() const;
		bool isWon() const;

		std::string check_board() const;
		size_t getLives() const;
		const std::vector<char>& get_guessed_letters() const;
	};
};

#endif