#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int number=0;
    int guess=0;
    int attempts=0;

    srand(time(0));  
    number = rand() % 100 + 1;  

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have selected a number between 1 and 100.\n";
    cout << "Start guessing:\n";

    cin >> guess;
    attempts++;

    while (guess != number) {
        if (guess > number) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Too low! Try again: ";
        }
        cin >> guess;
        attempts++;
    }

    cout << " Correct! You guessed the number in " << attempts << " attempts.\n";
    cout << "Thanks for playing! \n";

    return 0;
}
