#include <iostream>
#include <fstream>
#include "../include/naive_bayes.h"

int main() {
    NaiveBayes model;

    // Input file streams:
    std::ifstream human_file("data/human.txt");
    std::ifstream bot_file("data/bot.txt");

    std::string line;

    while (getline(human_file, line)) {
        model.train(line, "human"); // train defined in naive_bayes.cpp
    }
    while (getline(bot_file, line)) {
        model.train(line, "bot");
    }

    std::cout << "Training Complete! \n";

    std::string input;
    std::cout << "Enter text to classify: ";
    getline(std::cin, input);

    std::string result = model.predict(input);
    std::cout << "Predicted class: " << result << std::endl;

    return 0;
}