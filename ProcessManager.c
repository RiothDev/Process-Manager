#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include "ChildThread.h"

#define MAX_PROCESS 10

int _tmain(int argc, char** argv) {
    HANDLE threadArr[MAX_PROCESS];
    DWORD idArr[MAX_PROCESS];

    int n;

    printf("> Processes to create : ");
    scanf("%d", &n);

    if(n > MAX_PROCESS) {
        printf("> The number of processes is very high!\n");
        exit(1);
    }

    for(int i = 0; i < n; i++) {
        threadArr[i] = CreateThread(NULL, 0, childThread, (LPVOID) i, 0, &idArr[i]);

        if(threadArr[i] == NULL) {
            printf("> Error trying to create child process : %d\n", GetLastError());
            exit(1);
        }
    }

    WaitForMultipleObjects(n, threadArr, TRUE, INFINITE);

    for(int i = 0; i < n; i++) {
        CloseHandle(threadArr[i]);
    }

    printf("> All processes finished successfully!\n");

    return 0;
}