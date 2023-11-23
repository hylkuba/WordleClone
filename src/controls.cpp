/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 22.11.2023
*/

#include "controls.h"

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#endif

void CControls::waitForEnter() {
    while (true) {
        #ifdef _WIN32
            if (_kbhit()) {
                int key = _getch();
                if (key == 13) {  // Check if Enter key is pressed
                    break;
                }
            }
        #else
            // For non-Windows platforms, you may need to implement a different solution
            // based on terminal input handling libraries or system calls.
            // Example using standard input:
            char input;
            std::cin.get(input);
            if (input == '\n') {
                break;
            }
        #endif
    }
}

std::string CControls::guess() {
    
}