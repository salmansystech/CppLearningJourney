#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>

std::string filename;
std::map<std::string, std::pair<int, std::set<int>>> word_count;

void read_file() {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error! The file " << filename << " cannot be opened." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    int line_number = 0;
    while (std::getline(file, line)) {
        line_number++;
        std::istringstream iss(line);
        std::string word;
        std::set<std::string> words_in_line;
        while (iss >> word) {
            words_in_line.insert(word);
        }
        for (const auto& w : words_in_line) {
            word_count[w].first++;
            word_count[w].second.insert(line_number);
        }
    }
}

void print_results() {

    for (const auto& entry : word_count) {
        std::cout << entry.first << " " << entry.second.first << ": ";
        for (auto it = entry.second.second.begin(); it != entry.second.second.end(); ++it) {
            if (it != entry.second.second.begin()) std::cout << ", ";
            std::cout << *it;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Input file: ";
    std::cin >> filename;
    read_file();
    print_results();
    return EXIT_SUCCESS;
}
