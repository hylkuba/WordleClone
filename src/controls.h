/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#pragma once

#include <string>

class CControls {
public:
    /**
     * @brief Initiates loop that stops when the key "ENTER" is pressed
     * 
     */
    void waitForEnter();

    /**
     * @brief User inputs a 5 letter word
     * 
     * @return std::string guessed word
     */
    std::string guess();
};