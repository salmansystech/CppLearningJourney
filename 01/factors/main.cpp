#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int number;
    cout << "Enter a positive number: ";
    cin >> number;

    if (number <= 0) {
        cout << "Only positive numbers accepted" << endl;
    } else {
        int closestFactor1 = 1, closestFactor2 = number;
        int limit = static_cast<int>(sqrt(number));

        for (int i = 1; i <= limit; ++i) {
            if (number % i == 0) {
                closestFactor1 = i;
                closestFactor2 = number / i;
            }
        }

        cout << number << " = " << closestFactor1 << " * " << closestFactor2 << endl;
    }

    return 0;
}
