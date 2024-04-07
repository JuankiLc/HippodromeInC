#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "InterfazUsuario/interfazGrafica.h"

int main1()
{

    long die;
    int vict;
    float gan;
    long dietexto;
    int victtexto;
    int gantexto;

    setColorTexto(13);
    //system("title Proyecto Integrador");
    //system("mode con cols=50 lines=50");
    gotoxy(2,2);
    printf("%c", 218);
    gotoxy(48,2);
    printf("%c", 191);

    gotoxy(2,40);
    printf("%c", 192);
    gotoxy(48,40);
    printf("%c", 217);

    gotoxy(20,5);
    printf("Hipodromo\n");

    gotoxy(15,10);
    printf("DIE:\n");
    gotoxy(20,10);
    scanf("%ld", &die);

    gotoxy(15,12);
    printf("Victorias:\n");
    gotoxy(26,12);
    scanf("%d", &vict);

    gotoxy(15,14);
    printf("Ganancias:\n");
    gotoxy(26,14);
    scanf("%f", &gan);

     FILE* ptr;
    ptr = fopen("caballo1.txt",  "rt");

    fscanf(ptr, "%ld", &dietexto);
    fscanf(ptr, "%d", &victtexto);
    fscanf(ptr, "%d", &gantexto);

    fclose(ptr);

    gotoxy(15,16);
    printf("DIE caballo 1: %ld\n", dietexto);
    gotoxy(15,18);
    printf("Victorias caballo 1: %d\n", victtexto);
    gotoxy(15,20);
    printf("Ganancias caballo 1: %d\n", gantexto);



    return 0;
}
