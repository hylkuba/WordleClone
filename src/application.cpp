/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#include "application.h"

#include <iostream>

int CApplication::run() {
    system("clear");
    std::cout << "WELCOME To WORDLE" << std::endl;

    std::cout << "Press ENTER to start!" << std::endl;

    control.waitForEnter();

    while(true) {
        wordToFind = wordGen.getWord();
        if(wordToFind == "") {
            std::cout << "Trouble generating word right now. Fix needed!" << std::endl;
            return 1;
        }

        guessedWord = control.guess();

        std::cout << "Guessed Word: " << guessedWord << std::endl;
        control.waitForEnter();
    }

    return 0;
}