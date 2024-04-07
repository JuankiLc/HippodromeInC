#ifndef INTERFAZGRAFICA_H_INCLUDED
#define INTERFAZGRAFICA_H_INCLUDED
#include <windows.h>
void muestraMensajeInfo(char *msg);
void setColorTexto(WORD colors);
void gotoxy(int x, int y);
short int leerOpcionValida(char *mensaje, char num);
void muestraMensajeTitulo(char *msg);

#endif // INTERFAZGRAFICA_H_INCLUDED
