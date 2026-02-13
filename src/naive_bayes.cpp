// Goal: Compute P(class | text) ∝ P(class) * Π P(word | class)
// to avoid underflow: log P(class) + Σ log P(word | class)

#include "../include/naive_bayes.h"
#include "../include/tokenizer.h"
#include <cmath> // for log

// C++ Syntax Note: When defining member functions of a class outside the class definition, we use the scope resolution operator :: to specify that the function belongs to the class. For example, void NaiveBayes::train(...) indicates that the train function is a member of the NaiveBayes class.
void NaiveBayes::train(const std::string& text, const std::string& label) {
    std::vector<std::string> tokens = tokenize(text); // Tokenizer defined in tokenizer.cpp, declared in tokenizer.h

    if (label == "human") {
        human_docs++; // This is a counter for the number of human documents we've seen, used to calculate P(class)
        for (const auto& word : tokens) { // const auto& means the compiler will automatically deduce the type of word, and we use a reference (&) to avoid copying the string, and const to indicate that we won't modify it.
            human_word_count[word]++; // Feature of unordered_map: if word not in map, it will be default-initialized to 0, so we can safely increment it.
            total_human_words++;
        }
    }
    else if (label == "bot") {
        bot_docs++;
        for (const auto& word : tokens) {
            bot_word_count[word]++;
            total_bot_words++;
        }
    }
}

std::string NaiveBayes::predict(const std::string& text) {
    std::vector<std::string> tokens = tokenize(text);

    double log_human = std::log((double)human_docs / (human_docs + bot_docs)); // Double forces floating point division
    double log_bot = std::log((double)bot_docs / (human_docs + bot_docs));

    for (const auto& word : tokens) {
        // Laplace smoothing (add one to handle unseen events)
        double human_prob = (human_word_count[word] + 1.0) / (total_human_words + human_word_count.size());
        double bot_prob = (bot_word_count[word] + 1.0) / (total_bot_words + bot_word_count.size());

        log_human += std::log(human_prob);
        log_bot += std::log(bot_prob);
    }
    return (log_human > log_bot) ? "human" : "bot"; // C++ Ternary Operator: condition ? value_if_true : value_if_false
}