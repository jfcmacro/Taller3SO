/* CrearHilosWindows.c */

/* $Id: CrearHilosWindows.c,v 1.1.1.1 2003/06/19 19:00:15 fcardona Exp $ */

#include <Windows.h>
#include <stdio.h>

DWORD WINAPI 
funcion_hilo(LPVOID lpvThreadParam) {

  int valor = (int) lpvThreadParam;
  DWORD dwResultado = 0;

  
  
