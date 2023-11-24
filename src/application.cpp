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
        std::cout << "For help, write \"11111\"" << std::endl;

        // Loop of guessing and answering
        while(true) {
            guessedWord = control.guess();

            // If user asks for help => Help him
            if(guessedWord == "11111") {

                continue;
            }
            wordHistory.push_back(guessedWord);

            if(!wordManipulator.legal(guessedWord)) continue;

            // Print all guessed words again
            system("clear");
            for (const std::string& word : wordHistory) {
                wordManipulator.check(wordToFind, word);
            }

            if(guessedWord == wordToFind) {
                ui.congrats();
                break;
            }
        }
        wordHistory.clear();

        std::cout << "Press ENTER to continue with another word!" << std::endl;
        control.waitForEnter();
        system("clear");
    }

    return 0;
}