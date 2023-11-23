/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#pragma once

#include <string>

#define WORDURL "src/fiveLetterWords.txt"

class CWordGen {
public:
    /**
     * @brief Construct a new CWordGen object
     * 
     */
    CWordGen() = default;
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CWordGen(const CWordGen &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CWordGen&
     */
    CWordGen & operator=(const CWordGen &) = delete;

    /**
     * @brief Destroy the CWordGen object set to default
     * 
     */
    ~CWordGen() = default;

    /**
     * @brief Gets a random string from a file
     * 
     * @return std::string Random word to guess
     * @return Return an empty string to indicate an error
     */
    std::string getWord();

private:
    /**
     * @brief Get the Random Number
     * 
     * @param max Max number in an interval (0, max)
     * @return int random number
     */
    int getRandomNumber(int max);

    /**
     * @brief Get the Line Count of a file
     * 
     * @return int Number of lines
     * @return Return -1 to indicate an error
     */
    int getLineCount();
};