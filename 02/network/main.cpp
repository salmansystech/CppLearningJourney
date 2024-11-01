#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";


std::vector<std::string> split(const std::string& s,
                               const char delimiter,
                               bool ignore_empty = false)
{
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

// Global data structure for storing the network
std::map<std::string, std::vector<std::string>> network;

// Recursive function to print the network starting from a given ID
void print_network(const std::string& id, int indent = 0) {
    for (int i = 0; i < indent; ++i) {
        std::cout << ".";
    }
    std::cout << id << std::endl;

    if (network.find(id) != network.end()) {
        for (const auto& recruit : network[id]) {
            print_network(recruit, indent + 2);
        }
    }
}

// Recursive function
int count_network(const std::string& id) {
    int count = 0;
    if (network.find(id) != network.end()) {
        for (const auto& recruit : network[id]) {
            count += 1 + count_network(recruit);
        }
    }
    return count;
}

// Recursive function
int depth_network(const std::string& id) {
    int max_depth = 0;
    if (network.find(id) != network.end()) {
        for (const auto& recruit : network[id]) {
            max_depth = std::max(max_depth, depth_network(recruit));
        }
    }
    return 1 + max_depth;
}

int main()
{


    while(true)
    {
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        // Allowing empty inputs
        if(parts.size() == 0)
        {
            continue;
        }

        std::string command = parts.at(0);

        if(command == "S" or command == "s")
        {
            if(parts.size() != 3)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            // TODO: Implement the command here!
             network[id1].push_back(id2);

        }
        else if(command == "P" or command == "p")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            print_network(id);

        }
        else if(command == "C" or command == "c")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            int count = count_network(id);
                       std::cout << count << std::endl;

        }
        else if(command == "D" or command == "d")
        {
            if(parts.size() != 2)
            {
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            int depth = depth_network(id);
                        std::cout << depth << std::endl;

        }
        else if(command == "Q" or command == "q")
        {
           return EXIT_SUCCESS;
        }
        else
        {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
