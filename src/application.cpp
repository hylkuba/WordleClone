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

    // Loop of generating words
    while(true) {
        wordToFind = wordGen.getWord();
        if(wordToFind == "") {
            std::cout << "Trouble generating word right now. Fix needed!" << std::endl;
            return 1;
        }

        ui.separationLine();
        std::cout << "Please guess a 5-letter word: " << std::endl;

        // Loop of guessing and answering
        while(true) {
            guessedWord = control.guess();
            
            if(guessedWord == wordToFind) {
                ui.congrats();
                break;
            }

            // Print the guessed word with appropriate colors
            wordCheck.check(wordToFind, guessedWord);

            ui.separationLine();
        }

        control.waitForEnter();
    }

    return 0;
}