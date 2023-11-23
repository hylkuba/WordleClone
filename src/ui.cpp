/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#include "ui.h"

#include <iostream>

void CUi::separationLine() {
    // Function to print a separation line
    std::cout << "----------------------------------------" << std::endl;
}

void CUi::greenLetter(char c) {
    // Function to print a green letter
    std::cout << "\033[1;32m" << c << "\033[0m";  // Green text
}

void CUi::yellowLetter(char c) {
    // Function to print a yellow letter
    std::cout << "\033[1;33m" << c << "\033[0m";  // Yellow text
}

void CUi::grayLetter(char c) {
    // Function to print a gray letter
    std::cout << "\033[1;30m" << c << "\033[0m";  // Gray text
}

void CUi::congrats() {
    // Function to print a congratulations message
    std::cout << "Congratulations! You guessed the word!" << std::endl;
}
