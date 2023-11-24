/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#pragma once

#include "ui.h"

#include <string>
#include <set>

#define WORDURL "src/fiveLetterWords.txt"

class CWordManipulator : public CUi {
public:
    /**
     * @brief Construct a new CWordManipulator object
     * 
     */
    CWordManipulator();
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CWordManipulator(const CWordManipulator &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CWordManipulator&
     */
    CWordManipulator & operator=(const CWordManipulator &) = delete;

    /**
     * @brief Destroy the CWordManipulator object set to default
     * 
     */
    ~CWordManipulator() = default;

    /**
     * @brief Checking correctness of guessed word
     * 
     * @param wordToGuess 
     * @param guessedWord 
     */
    void check(std::string wordToGuess, std::string guessedWord);

    /**
     * @brief Check whether the passed word is legal within txt file
     * 
     * @param word 
     * @return true 
     * @return false 
     */
    bool legal(const std::string word);

    /**
     * @brief Get a random word
     * 
     * @return std::string 
     */
    std::string getWord();

    /**
     * @brief Clears all maps
     * 
     */
    void reset();

    /**
     * @brief Prints possible word combinations based on received input
     * 
     */
    void help();
private:
    /**
     * @brief Checks whether specific character exists in a wordToGuess
     * 
     * @param wordToGuess 
     * @param c 
     * @param ignoreIndex 
     * @return true 
     * @return false 
     */
    bool exists(std::string wordToGuess, char c, size_t ignoreIndex);

    /**
     * @brief Checks if all yellow characters are present in a word
     * 
     * @param str 
     * @return true 
     * @return false 
     */
    bool allCharsPresent(const std::string& str);

    /**
     * @brief Set of all possible words from a txt file
     * 
     */
    std::set<std::string> wordList;

    /**
     * @brief Set that contains information of valid characters
     * 
     */
    std::set<std::pair<char, int>> letterCorrectPos;

    /**
     * @brief Correct word gotten from green letters represented by __a__
     * 
     */
    std::string correctWord;

    /**
     * @brief Set that contains information of valid characters on different positions
     * 
     */
    std::set<std::pair<char, int>> letterWrongPos;

    /**
     * @brief Set that contains invalid characters
     * 
     */
    std::set<char> letterNotPos;

    /**
     * @brief Set of possible words
     * 
     */
    std::set<std::string> possibleWords;
};