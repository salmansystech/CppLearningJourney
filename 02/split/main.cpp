#include <iostream>
#include <string>
#include <vector>

// Splits the input string by the given separator and returns the parts in a vector.
std::vector<std::string> split(const std::string& str, char separator, bool ignore_empty = false) {
    std::vector<std::string> result;
    std::string current_part;

    for (char ch : str) {
        if (ch == separator) {
            if (!ignore_empty || !current_part.empty()) {
                result.push_back(current_part);
            }
            current_part.clear();
        } else {
            current_part += ch;
        }
    }

    if (!ignore_empty || !current_part.empty()) {
        result.push_back(current_part);
    }

    return result;
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector<std::string> parts = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for (auto part : parts) {
        std::cout << part << std::endl;
    }

    std::vector<std::string> parts_no_empty = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for (auto part : parts_no_empty) {
        std::cout << part << std::endl;
    }
}
