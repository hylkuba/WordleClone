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
        system("clear");
        wordToFind = wordManipulator.getWord();
        if(wordToFind == "") {
            std::cout << "Trouble generating word right now. Fix needed!" << std::endl;
            return 1;
        }

        ui.separationLine();
        std::cout << "Please guess a 5-letter word: " << std::endl;
        std::cout << "For help, write \"*****\"" << std::endl;


        int tries = 0;
        // Loop of guessing and answering
        while(true) {
            guessedWord = control.guess();

            // If user asks for help => Help him
            if(guessedWord == "*****") {
                if(tries < 3) {
                    std::cout << "Not eligable for help yet.\nYou need " << (3 - tries) << " more guesses" << std::endl;
                    continue;
                }
                wordManipulator.help();
                continue;
            }

            if(!wordManipulator.legal(guessedWord)) continue;
            
            wordHistory.push_back(guessedWord);

            tries++;

            // Print all guessed words again
            system("clear");
            for (const std::string& word : wordHistory) {
                wordManipulator.check(wordToFind, word);
            }

            if(guessedWord == wordToFind) {
                ui.congrats();

                wordManipulator.reset();
                break;
            }
        }
        wordHistory.clear();

        std::cout << "Press ENTER to continue with another word!" << std::endl;
        control.waitForEnter();
    }

    return 0;
}