#include <iostream>
#include <string>

using namespace std;

int main() {
    string longer_string;
    string shorter_string;

    cout << "Enter a (longer) string: ";
    getline(cin, longer_string);

    cout << "Enter a (shorter) string to be found: ";
    getline(cin, shorter_string);

    size_t pos = 0;
    bool found = false;
    string result;

    while ((pos = longer_string.find(shorter_string, pos)) != string::npos) {
        if (found) {
            result += ", ";
        }
        result += to_string(pos);
        found = true;
        pos += 1; // Move past the current match to find overlapping occurrences
    }

    if (!found) {
        result = "Not found";
    } else {
        result = "Found at " + result;
    }

    cout << result << endl;
    return 0;
}
