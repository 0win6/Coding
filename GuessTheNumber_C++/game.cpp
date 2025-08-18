#include <iostream>
#include <random>

using namespace std;

int main() {
	random_device device;
	mt19937 number(device());
	uniform_int_distribution<size_t> generate(1, 1000);
	size_t mystery = generate(number);
	size_t turns = 10, guess = 0;

	while (true && turns != 0) {
		cout << "Guess the number (Moves left: " << turns << "): ";
		cin >> guess;

		if (guess < 1 || guess > 1000) {
			cout << "Invalid input. Please enter between 1 and 1000." << endl;
			continue;
		} else if (guess == mystery) {
			cout << "You win! Mystery number is " << mystery << endl;
			return 0;
		} else {
			turns--;
			cout << (guess > mystery ? "Lower!" : "Higher!") << endl;
		}
	}

	cout << "Game Over. You Lose! The number is " << mystery << "." << endl;

	return 0;
}