#include <iostream>
using namespace std;

unsigned long int factorial(unsigned long int num) {
    unsigned long int result = 1;
    for (unsigned long int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}

unsigned long int lottery_combinations(unsigned long int n, unsigned long int p) {
    return factorial(n) / (factorial(p) * factorial(n - p));
}

int main() {
    unsigned long int total_balls = 0, drawn_balls = 0;

    cout << "Enter the total number of lottery balls: ";
    cin >> total_balls;
    cout << "Enter the number of drawn balls: ";
    cin >> drawn_balls;

    if (total_balls <= 0 || drawn_balls <= 0) {
        cout << "The number of balls must be a positive number." << endl;
        return 0;
    }

    if (drawn_balls > total_balls) {
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
        return 0;
    }

    unsigned long int combinations = lottery_combinations(total_balls, drawn_balls);
    cout << "The probability of guessing all " << drawn_balls << " balls correctly is 1/" << combinations << endl;

    return 0;
}
