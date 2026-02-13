#include "../include/tokenizer.h"
#include <sstream>
#include <algorithm> // For std::transform
#include <cctype> // For std::tolower

std::vector<std::string> tokenize(const std::string& text) {
    // Input: String of text, Output: Vector of lowercase words
    std::vector<std::string> tokens;
    std::stringstream ss(text);
    std::string word;

    while (ss >> word ) {
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        tokens.push_back(word);
    }
    return tokens;
}