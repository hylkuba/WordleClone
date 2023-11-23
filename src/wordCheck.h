/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#pragma once

#include "ui.h"

#include <string>
#include <set>

#define WORDURL "src/fiveLetterWords.txt"

class CWordCheck : public CUi {
public:
    /**
     * @brief Construct a new CWordCheck object
     * 
     */
    CWordCheck();
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CWordCheck(const CWordCheck &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CWordCheck&
     */
    CWordCheck & operator=(const CWordCheck &) = delete;

    /**
     * @brief Destroy the CWordCheck object set to default
     * 
     */
    ~CWordCheck() = default;

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
};