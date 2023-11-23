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
     * @brief 
     * 
     * @return std::string 
     */
    std::string generateRandomString();
};