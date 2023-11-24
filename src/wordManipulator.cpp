/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#include "wordManipulator.h"

#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <ctime>

CWordManipulator::CWordManipulator() {
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

    correctWord = "_____";
}

void CWordManipulator::check(std::string wordToGuess, std::string guessedWord) {
    for (size_t i = 0; i < guessedWord.size(); i++) {
        if(guessedWord[i] == wordToGuess[i]) {
            greenLetter(guessedWord[i]);
            letterCorrectPos.insert(std::make_pair(guessedWord[i], i));
            correctWord[i] = guessedWord[i];
        } else if(exists(wordToGuess, guessedWord[i], i)) {
            yellowLetter(guessedWord[i]);
            letterWrongPos.insert(std::make_pair(guessedWord[i], i));
        } else {
            grayLetter(guessedWord[i]);
            letterNotPos.insert(guessedWord[i]);
        }
    }
    std::cout << std::endl;
}

std::string CWordManipulator::getWord() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::size_t randomIndex = std::rand() % wordList.size();
    auto it = std::begin(wordList);
    std::advance(it, randomIndex);

    return *it;
}

bool CWordManipulator::exists(std::string wordToGuess, char c, size_t ignoreIndex) {
    for (size_t i = 0; i < wordToGuess.size(); i++) {
        if(i != ignoreIndex && wordToGuess[i] == c) return true;
    }
    
    return false;
}

bool CWordManipulator::legal(const std::string word) {
    if(wordList.find(word) != wordList.end()) return true;

    std::cout << "This word is not in the dictionary" << std::endl;
    separationLine();

    return false;
}

void CWordManipulator::reset() {
    letterCorrectPos.clear();
    letterWrongPos.clear();
    letterNotPos.clear();
    possibleWords.clear();
    correctWord = "_____";
}

void CWordManipulator::help() {
    // Outer loop of words
    possibleWords.clear();
    for (const std::string& word : wordList) {
        bool possible = true;

        // Inner loop of characters
        for (size_t i = 0; i < word.size(); i++)
        {
            // If we know that letter on specific position is green
            if(correctWord[i] != '_') {
                if(word[i] != correctWord[i]) {
                    possible = false;
                    break;
                }
            }
            
            // Check if the letter of the word is already out of options
            if(letterNotPos.find(word[i]) != letterNotPos.end()) {
                possible = false;
                break;
            }

            if(letterWrongPos.find(std::make_pair(word[i], i)) != letterWrongPos.end()) {
                possible = false;
                break;
            }
        }

        // Check if all yellow letters are in current word
        if(possible) {
            possible = allCharsPresent(word);
        }

        if(possible) {
            possibleWords.insert(word);
        }
    }

    system("clear");
    std::cout << "Possible options" << std::endl;
    for(const std::string& word : possibleWords) {
        for (size_t i = 0; i < correctWord.size(); i++)
        {
            if(word[i] == correctWord[i]) {
                greenLetter(word[i]);
            } else {
                grayLetter(word[i]);
            }
        }
        std::cout << std::endl;
    }
}

bool CWordManipulator::allCharsPresent(const std::string& str) {
    for (const auto& pair : letterWrongPos) {
        char character = pair.first;
        if (str.find(character) == std::string::npos) {
            return false;
        }
    }
    return true;
}