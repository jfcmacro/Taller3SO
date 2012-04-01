/* CreateHilosWindows.c */
/* $Id: CreateHilosWindows.c,v 1.1.1.1 2003/06/19 19:00:15 fcardona Exp $ */
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>



DWORD WINAPI 
funcion_hilo(LPVOID lpParameter) { 

    int valor = (int) lpParameter;
    DWORD dwResultado = 0;

    printf("");
    fprintf(stdout, "Hola mundo desde el hilo: %d\r\n", valor);
    
    Sleep(valor * 1000); // Esta expresion esta en milisegundos
    
    dwResultado = (DWORD)100 * valor;
    return dwResultado;
}

int
main(int argc, char *argv[]) {

    int nHilos;
    DWORD dwResultado;
    int i;
    DWORD *tablaHilos;
    
    if (argc != 2) {
        fprintf(stderr, "Uso: %s nHilos\r\n", argv[0]);
        ExitProcess(10U);
    }
    
    nHilos = atoi(argv[1]);
    
    if (nHilos == 0) {
        fprintf(stderr, "Uso: %s nHilos\r\n", argv[0]);
        ExitProcess(10U);
    }  
    tablaHilos = (LPDWORD) malloc(sizeof(LPDWORD) * nHilos);
    
    for (i = 0; i < nHilos; i++) {
    
        CreateThread(NULL,
                     0,
                     funcion_hilo,
                     (LPVOID) i,
                     0,
                     (tablaHilos + i));
    }
    
    for (i = 0; i < nHilos; i++) {
        HANDLE hThread;
        
        hThread = OpenThread(THREAD_ALL_ACCESS,
                             FALSE,
                             *(tablaHilos + i));
        WaitForSingleObject(hThread, 0);
        GetExitCodeThread(hThread, &dwResultado);
        fprintf(stdout, "El hilo: %ld terminó: %ld\r\n",
                *(tablaHilos + i),
                dwResultado);
    }
                
    return 0;                     
}    

