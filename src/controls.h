/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#pragma once

#include <string>

class CControls {
public:
    /**
     * @brief Construct a new CControls object
     * 
     */
    CControls() = default;
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CControls(const CControls &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CControls&
     */
    CControls & operator=(const CControls &) = delete;

    /**
     * @brief Destroy the CControls object set to default
     * 
     */
    ~CControls() = default;

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