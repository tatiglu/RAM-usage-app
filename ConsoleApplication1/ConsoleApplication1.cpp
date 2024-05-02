#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    setlocale(LC_ALL, "RU");

    while (true) {
        system("cls");  
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);

        DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
        DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

        std::cout << "Общий объем ОЗУ: " << totalPhysMem / 1024 / 1024 << " МБ" << std::endl;
        std::cout << "Использовано ОЗУ: " << physMemUsed / 1024 / 1024 << " МБ" << std::endl;
        std::cout << "Свободно ОЗУ: " << memInfo.ullAvailPhys / 1024 / 1024 << " МБ" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(5)); 
    }

    return 0;
}