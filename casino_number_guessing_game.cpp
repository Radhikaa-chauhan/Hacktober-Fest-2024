#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Player {
public:
    string name;
    double balance;

    Player(string name, double initialBalance) : name(name), balance(initialBalance) {}
};

class Game {
public:
    int minNumber;
    int maxNumber;
    double multiplier;

    Game(int min, int max, double mult) : minNumber(min), maxNumber(max), multiplier(mult) {}

    int generateRandomNumber() {
        return rand() % (maxNumber - minNumber + 1) + minNumber;
    }

    void play(Player& player) {
        int guess;
        int randomNumber = generateRandomNumber();

        cout << "Guess a number between " << minNumber << " and " << maxNumber << ": ";
        cin >> guess;

        if (guess == randomNumber) {
            player.balance *= multiplier;
            cout << "You win! Your new balance is: $" << player.balance << endl;
        } else {
            player.balance /= 2;
            cout << "You lose! The correct number was " << randomNumber << ". Your new balance is: $" << player.balance << endl;
        }
    }
};

int main() {
    string playerName;
    double initialBalance;

    cout << "Enter your name: ";
    cin >> playerName;
    cout << "Enter your initial balance: $";
    cin >> initialBalance;

    Player player(playerName, initialBalance);

    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    while (player.balance > 0) {
        cout << "\nChoose a difficulty level:" << endl;
        cout << "1. Easy (1-10, multiplier: 2)" << endl;
        cout << "2. Medium (1-50, multiplier: 3)" << endl;
        cout << "3. Hard (1-100, multiplier: 5)" << endl;
        cout << "99. Exit" << endl;

        int difficulty;
        cout << "enter your choice: ";
        cin >> difficulty;

        Game game(1, 10, 2); // Default values
        switch (difficulty) {
            case 1:
                game = Game(1, 10, 2);
                break;
            case 2:
                game = Game(1, 50, 3);
                break;
            case 3:
                game = Game(1, 100, 5);
                break;
            case 99:
                cout << "you walk out with $" << initialBalance;
                return 0;
            default:
                cout << "Invalid difficulty level." << endl;
                continue;
        }

        game.play(player);
    }

    cout << "You're out of money! Game over." << endl;

    return 0;
}
