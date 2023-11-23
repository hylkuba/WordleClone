/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#pragma once

class CUi {
public:
    /**
     * @brief Prints dash (-) symbols as a separator
     * 
     */
    void separationLine();

    /**
     * @brief Prints character in green color. Represents a letter that is in correct position in wanted word
     * 
     * @param c Character to be displayed
     */
    void greenLetter(char c);

    /**
     * @brief Prints character in yellow color. Represents a letter that is in wanted word, but in a different position
     * 
     * @param c Character to be displayed
     */
    void yellowLetter(char c);

    /**
     * @brief Prints character in gray color. Represents a letter that is not in the wanted word
     * 
     * @param c Character to be displayed
     */
    void grayLetter(char c);

    /**
     * @brief Congratulations message
     * 
     */
    void congrats();
};