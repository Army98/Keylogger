
#include "common.h"


int processes(int delay) {

	while (true) {

		HWND activeWindow = GetForegroundWindow();
		DWORD processId;

		GetWindowThreadProcessId(activeWindow, &processId);

		char windowTitle[126];

		GetWindowTextA(activeWindow, windowTitle, sizeof(windowTitle));

		std::cout << "PID : " << processId << std::endl;
		std::cout << windowTitle << std::endl;

		std::cout << std::endl; 

		Sleep(delay);

	}

	return 0;

}