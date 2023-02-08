#include <stdio.h>
#include <windows.h>

DWORD WINAPI childThread(LPVOID parameter) {
    int num = (int) parameter;
    printf("\n> Child process : %d\nPID : %d\n", (num + 1), GetCurrentProcessId());

    Sleep(1200);
    return 0;
}