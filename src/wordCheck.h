/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#pragma once

#include "ui.h"

#include <string>

class CWordCheck {
public:
    /**
     * @brief Construct a new CWordCheck object
     * 
     */
    CWordCheck() = default;
    
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
private:
    CUi ui;
};