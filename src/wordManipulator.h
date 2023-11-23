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

    std::set<std::string> wordList;

    size_t getRandomNumber(int max);
};