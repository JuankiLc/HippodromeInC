#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../Entidades/caballo.h"
#include "interfazGrafica.h"


void muestraMensajeInfo(char *msg)//escribe el mensaje que pongas
{
    int lines=45;
    gotoxy(10,lines-6);
    printf("                                                                           ");
    gotoxy(10,lines-6);
    printf("%s", msg);
}
void muestraMensajeTitulo(char *msg)//escribe el mensaje que pongas
{
    gotoxy(5,6);
    printf("                                                ");
    gotoxy(5,6);
    printf("%s", msg);
}
void setColorTexto(WORD colors)//colorea la pantalla
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colors);
}

void gotoxy(int x, int y)//define gotoxy
{
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
short int leerOpcionValida(char *mensaje, char num)
{
    muestraMensajeInfo(mensaje);
    short int opcion= getch()-48;

    while ((opcion<0)|(num<opcion))
    {
        muestraMensajeInfo("Opcion no valida (Pulsa intro para continuar)");
        getch();
        muestraMensajeInfo(mensaje);
        opcion= (short int) getch()-48;
    }

    return opcion;
}
short int leerOpcionValidaScanf(char *mensaje, char num)
{
    muestraMensajeInfo(mensaje);
    int opcion;
    scanf("%d", &opcion);
    while ((opcion<0)|(num<opcion))
    {
        free((int*)opcion);
        muestraMensajeInfo("Opcion no valida (Pulsa intro para continuar)");
        getch();
        muestraMensajeInfo(mensaje);
        scanf("%d", &opcion);
    }

    return opcion;
}
