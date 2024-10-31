#include <iostream>
#include <limits>

using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number < 0) {
        cout << "Error! The number must be non-negative." << endl;
        return 1;
    }

    long long cube = static_cast<long long>(number) * number * number;

    if (cube > numeric_limits<int>::max()) {
        cout << "Error! The cube of " << number << " is too large to fit in an int." << endl;
    } else {
        int result = static_cast<int>(cube);
        if (result == number * number * number) {
            cout << "The cube of " << number << " is " << result << "." << endl;
        } else {
            cout << "Error! The cube of " << number << " is not " << result << "." << endl;
        }
    }

    return 0;
}
