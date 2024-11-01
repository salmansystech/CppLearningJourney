#include <iostream>
#include <fstream>
#include <map>
#include <string>

std::map<std::string, int> player_points;
std::string filename;

void read_points() {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error! The file " << filename << " cannot be opened." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(':');
        std::string name = line.substr(0, pos);
        int points = std::stoi(line.substr(pos + 1));
        player_points[name] += points;
    }
}

int main() {
    std::cout << "Input file: ";
    std::cin >> filename;
    read_points();
    std::cout << "Final scores:" << std::endl;
    for (const auto& entry : player_points) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
    return EXIT_SUCCESS;
}
