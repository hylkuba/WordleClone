/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#include "wordCheck.h"

#include <iostream>
#include <fstream>

CWordCheck::CWordCheck() {
    std::string word;

    std::ifstream file(WORDURL);
    if (!file.is_open()) {
        std::cerr << "GetWord(). Error opening file: " << WORDURL << std::endl;
        return;
    }

    while(std::getline(file, word)) {
        if(word.size() != 5) return;

        wordList.insert(word);
    }

    std::cout << "size: " << wordList.size();
}

void CWordCheck::check(std::string wordToGuess, std::string guessedWord) {
    for (size_t i = 0; i < guessedWord.size(); i++) {
        if(guessedWord[i] == wordToGuess[i]) {
            greenLetter(guessedWord[i]);
        } else if(exists(wordToGuess, guessedWord[i], i)) {
            yellowLetter(guessedWord[i]);
        } else {
            grayLetter(guessedWord[i]);
        }
    }
    std::cout << std::endl;
}

bool CWordCheck::exists(std::string wordToGuess, char c, size_t ignoreIndex) {
    for (size_t i = 0; i < wordToGuess.size(); i++) {
        if(i != ignoreIndex && wordToGuess[i] == c) return true;
    }
    
    return false;
}

bool CWordCheck::legal(const std::string word) {
    std::string line;

    std::ifstream file(WORDURL);
    if (!file.is_open()) {
        std::cerr << "GetWord(). Error opening file: " << WORDURL << std::endl;
        return false;
    }

    while(std::getline(file, line)) {
        if(line == word) return true;
    }

    std::cout << "This word is not in dictionary" << std::endl;
    separationLine();

    return false;
}