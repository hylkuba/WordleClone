/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#include "wordGen.h"

#include <iostream>
#include <fstream>
#include <random>

std::string CWordGen::getWord() {
    int lines = getLineCount();

    if(lines == -1) return "";

    size_t rnd = getRandomNumber(lines);

    std::string word;

    std::ifstream file(WORDURL);
    if (!file.is_open()) {
        std::cerr << "GetWord(). Error opening file: " << WORDURL << std::endl;
        return "";
    }

    for (size_t i = 0; i < rnd; i++) {
        std::getline(file, word);
    }

    if(word.size() != 5) return "";

    return word;
}

size_t CWordGen::getRandomNumber(int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, max);

    return distribution(gen);
}

int CWordGen::getLineCount() {
    std::ifstream file(WORDURL);

    if (!file.is_open()) {
        std::cerr << "GetLineCount(). Error opening file: " << WORDURL << std::endl;
        return -1;
    }

    int lineCount = 0;
    std::string line;

    while (std::getline(file, line)) {
        ++lineCount;
    }

    return lineCount;
}