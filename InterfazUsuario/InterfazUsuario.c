#include <stdio.h>
#include "../Entidades/caballo.h"
#include "interfazUsuario.h"
#include "../AccesoDatos/caballoAD.h"
#include "../InterfazSistema/caballoSys.h"
#include "interfazGrafica.h"
#include "caballoIU.h"
#include "../AccesoDatos/caballoBD.h"

#include <conio.h>

void inicInterfazUsuario()//rectangulos
{

    int cols, lines;
    int i;
    cols=120;
    lines=45;
    system("title Proyecto Integrador");
    system("mode con cols=120 lines=45");
//rectangulo alargado de arriba
    for (i=2;i<cols-2;i++)
    {
        gotoxy(i,1);
        printf("%c", 205);
    }
    for (i=2;i<cols-2;i++)
    {
        gotoxy(i,3);
        printf("%c", 205);
    }
    gotoxy(2,2);
    printf("%c", 186);
    gotoxy(cols-2,2);
    printf("%c", 186);
    gotoxy(2,1);
    printf("%c", 201);
    gotoxy(cols-2,1);
    printf("%c", 187);
    gotoxy(2,3);
    printf("%c", 200);
    gotoxy(cols-2,3);
    printf("%c", 188);
    gotoxy(52,2);
    printf("H I P O D R O M O");
//rectangulo grande izquierda
    for (i=2;i<cols/2-1;i++)
    {
        gotoxy(i,5);
        printf("%c", 196);
    }
    for (i=2;i<cols/2-1;i++)
    {
        gotoxy(i,lines-10);
        printf("%c", 196);
    }

    for (i=5;i<lines-10;i++)
    {
        gotoxy(2,i);
        printf("%c", 179);
    }
    for (i=5;i<lines-10;i++)
    {
        gotoxy(cols/2-1,i);
        printf("%c", 179);
    }
    gotoxy(2,5);
    printf("%c", 218);
    gotoxy((cols/2)-1,5);
    printf("%c", 191);
    gotoxy(2,lines-10);
    printf("%c", 192);
    gotoxy((cols/2)-1,lines-10);
    printf("%c", 217);
    for (i=2;i<cols/2-1;i++)//linea medio
    {
        gotoxy(i,7);
        printf("%c", 196);
    }
    gotoxy(2,7);
    printf("%c", 195);
    gotoxy((cols/2)-1,7);
    printf("%c", 180);
//rectangulos grande derecha
    for (i=cols/2+1;i<cols-2;i++)
    {
        gotoxy(i,5);
        printf("%c", 196);
    }
    for (i=cols/2+1;i<cols-2;i++)
    {
        gotoxy(i,lines-10);
        printf("%c", 196);
    }

    for (i=5;i<lines-10;i++)
    {
        gotoxy(cols/2+1,i);
        printf("%c", 179);
    }
    for (i=5;i<lines-10;i++)
    {
        gotoxy(cols-2,i);
        printf("%c", 179);
    }
    gotoxy((cols/2)+1,5);
    printf("%c", 218);
    gotoxy(cols-2,5);
    printf("%c", 191);
    gotoxy((cols/2)+1,lines-10);
    printf("%c", 192);
    gotoxy(cols-2,lines-10);
    printf("%c", 217);
    for (i=cols/2+1;i<cols-2;i++)//linea medio
    {
        gotoxy(i,7);
        printf("%c", 196);
    }
    gotoxy((cols/2)+1,7);
    printf("%c", 195);
    gotoxy(cols-2,7);
    printf("%c", 180);
//rectangulo alargado de abajo
    for (i=8;i<cols-8;i++)
    {
        gotoxy(i,lines-8);
        printf("%c", 196);
    }
    for (i=8;i<cols-8;i++)
    {
        gotoxy(i,lines-4);
        printf("%c", 196);
    }
    for (i=lines-8;i<lines-4;i++)
    {
        gotoxy(8,i);
        printf("%c", 179);
    }
    for (i=lines-8;i<lines-4;i++)
    {
        gotoxy(cols-8,i);
        printf("%c", 179);
    }
    gotoxy(8,lines-8);
    printf("%c", 218);
    gotoxy(cols-8,lines-8);
    printf("%c", 191);
    gotoxy(8,lines-4);
    printf("%c", 192);
    gotoxy(cols-8,lines-4);
    printf("%c", 217);
}
int menuPrincipal(void)// saca el indice
{
    int opcion;

    limpiarIzquierda();
    gotoxy(10,10);
    printf("1.Gestion de caballos");
    gotoxy(10,11);
    printf("2.Gestion de carreras");
    gotoxy(10,12);
    printf("3.Inicializa base de datos");
    gotoxy(10,13);
    printf("0.Fin del programa");

    opcion = leerOpcionValida("Seleccione una opcion:",3);

    return opcion;
}
void gestionMenuPrincipal(void)//sin acabar en esta version, llama al menu principal y a la gestion de caballos
{
    int opcion_usuario;
    muestraMensajeTitulo("MENU PRINCIPAL");

    opcion_usuario = menuPrincipal();
    while(opcion_usuario!=0)
    {
        switch (opcion_usuario)
        {
        case 1:
            gestionMenuCaballos();
            break;
        case 2:
            muestraMensajeInfo("Esta opcion todavia no esta implementada");
            getch();
            break;
        case 3:
            inicializaHipodromo("hipodromo.db", "BaseDatos/caballoslista.dat");
            getch();
            break;
        }
        opcion_usuario = menuPrincipal();
    }

}
void limpiarIzquierda()
{
    int lines,lines1;
    lines1=8;
    lines=45;

    while(lines1<=lines-11)
    {
        gotoxy(3,lines1);
        printf("                                                        ");
        lines1++;//limpia 56 cols
    }
}

