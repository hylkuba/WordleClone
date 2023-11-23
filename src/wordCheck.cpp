/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#include "wordCheck.h"

#include <iostream>

void CWordCheck::check(std::string wordToGuess, std::string guessedWord) {
    for (size_t i = 0; i < guessedWord.size(); i++) {
        if(guessedWord[i] == wordToGuess[i]) {
            ui.greenLetter(guessedWord[i]);
        } else if(exists(wordToGuess, guessedWord[i], i)) {
            ui.yellowLetter(guessedWord[i]);
        } else {
            ui.grayLetter(guessedWord[i]);
        }
    }
    std::cout << std::endl;
}

bool CWordCheck::exists(std::string wordToGuess, char c, int ignoreIndex) {
    for (size_t i = 0; i < wordToGuess.size(); i++) {
        if(i != ignoreIndex && wordToGuess[i] == c) return true;
    }
    
    return false;
}