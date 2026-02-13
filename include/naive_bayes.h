#ifndef NAIVE_BAYES_H
#define NAIVE_BAYES_H

#include <string>
#include <vector>
#include <unordered_map> // like a Hash Table, use: unordered_map[key] = value;

class NaiveBayes {
private:
    std::unordered_map<std::string, int> human_word_count;
    std::unordered_map<std::string, int> bot_word_count;

    int total_human_words = 0;
    int total_bot_words = 0;

    int human_docs = 0;
    int bot_docs = 0;

public:
    void train(const std::string& text, const std::string& label);
    std::string predict(const std::string& text);
};

#endif