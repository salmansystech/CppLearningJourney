#include <iostream>
#include <string>
#include <algorithm>
#include <random>

int main()
{
    // This is a random number generator that should be given as parameter to the
    // function of the algorithm library to shuffle letters
    std::minstd_rand generator;

    std::cout << "Enter some text. Quit by entering the word \"END\"." << std::endl;
    std::string word;

    while (std::cin >> word)
    {
        if (word == "END")
        {
            return EXIT_SUCCESS;
        }

        // If the word has more than 2 characters, shuffle the letters between the first and last letters
        if (word.length() > 2)
        {
            // Extract the middle part of the word
            std::string middle = word.substr(1, word.length() - 2);

            // Shuffle the middle part
            std::shuffle(middle.begin(), middle.end(), generator);

            // Reconstruct the word with the shuffled middle part
            word = word.front() + middle + word.back();
        }

        std::cout << word << std::endl;
    }

    return EXIT_SUCCESS;
}
