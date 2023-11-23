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
        wordToFind = wordManipulator.getWord();
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
                for (size_t i = 0; i < wordToFind.size(); i++) {
                    ui.greenLetter(wordToFind[i]);
                }
                std::cout << std::endl;
                
                ui.congrats();
                break;
            }

            if(!wordManipulator.legal(guessedWord)) continue;
            // Print the guessed word with appropriate colors
            wordManipulator.check(wordToFind, guessedWord);

            ui.separationLine();
        }

        std::cout << "Press ENTER to continue with another word!" << std::endl;
        control.waitForEnter();
    }

    return 0;
}