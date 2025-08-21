/*
Last Updated: 20250820
Initial Creation Date : 2025 08 20
Basic Hangman
*/

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cctype>
#include "game.h"

namespace hangman{
	Game::Game(const std::string& word) {
		secret_word = word;
		lives = 6;
		word_len = word.length();
		guessed_word = std::string(secret_word.length(), '_');
	}

	bool Game::player_guess(char l) {
		guessed_letters.push_back(l);

		bool found_letter = false;

		for (size_t i{}; i < word_len; ++i) {
			if (secret_word[i] == l) {
				guessed_word[i] = l;
				found_letter = true;
			}
		}
		
		if (!found_letter)
			lives--;

		return false;
	}

	bool Game::isWon() const {
		return guessed_word == secret_word;
	}

	bool Game::isOver() const {
		return lives == 0;
	}

	std::string Game::check_board() const {
		return guessed_word;
	}
	size_t Game::getLives() const {
		return lives;
	}

	const std::vector<char>& Game::get_guessed_letters() const {
		return guessed_letters;
	}
};

int main() {
	std::vector<std::string> words = { 
		"TWIZZLERS","AWESOME",
		"AI","MYSTERIOUS","RANDOM",
		"RHYTHM","TRYST","SHHHHHH","GRRRRRR" };

	std::random_device dev;
	std::mt19937 random(dev());
	std::uniform_int_distribution<> get_word(0, words.size() - 1);

	std::string word = words[get_word(random)];
	char guess{};

	hangman::Game new_game(word);
	std::cout << "Hangman:" << std::endl;
	std::cout << "-------------------------" << std::endl;
	while (!new_game.isOver() && !new_game.isWon()) {
		std::cout << "Word: " << new_game.check_board() << std::endl;
		std::cout << "Lives remaining: " << new_game.getLives() << std::endl;

		std::cout << "Guesses: ";
		for (char letter : new_game.get_guessed_letters()) {
			std::cout << letter << " ";
		}
		std::cout << std::endl;

		std::cout << "Guess a letter: ";
		std::cin >> guess;

		new_game.player_guess(toupper(guess));
		std::cout << "-------------------------" << std::endl;
	}

	if (new_game.isWon())
		std::cout << "You Won! The word was: " << word << std::endl;
	else 
		std::cout << "Game Over! The word was: " << word << std::endl;

	return 0;
}