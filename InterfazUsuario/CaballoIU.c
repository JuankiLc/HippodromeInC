#include <stdio.h>
#include "../Entidades/caballo.h"
#include <conio.h>
#include <stdbool.h>
#include "caballoIU.h"
#include "interfazUsuario.h"
#include "interfazGrafica.h"
#include "../InterfazSistema/caballoSys.h"
#include "../AccesoDatos/caballoBD.h"
#include "../AccesoDatos/caballoAD.h"





void altaCaballoIU()//Añade a la base de datos el caballo metido por teclado
{
    muestraMensajeTitulo("ALTA DEL CABALLO");
    sCaballoNum lista;
    lista.caballo=(sCaballo*)malloc(sizeof(sCaballo));
    //lista.numcaballos=1;
    limpiarIzquierda();

    muestraMensajeInfo("Introduzca nombre:");
    scanf("%s", lista.caballo[0].nombre);
    gotoxy(4,9);
    printf("Nombre:%s", lista.caballo[0].nombre);

    muestraMensajeInfo("Introduzca DIE:");
    scanf("%ld", &lista.caballo[0].die);
    gotoxy(4,10);
    printf("DIE:%ld", lista.caballo[0].die);

    muestraMensajeInfo("Introduzca nacionalidad:");
    scanf("%s", lista.caballo[0].nacionalidad);
    gotoxy(4,11);
    printf("Nombre:%s", lista.caballo[0].nacionalidad);

    muestraMensajeInfo("Edad:");
    scanf("%d", &lista.caballo[0].edad);
    gotoxy(4,12);
    printf("Victorias:%d", lista.caballo[0].edad);

    muestraMensajeInfo("Numero de victorias:");
    scanf("%d", &lista.caballo[0].victorias);
    gotoxy(4,13);
    printf("Victorias:%d", lista.caballo[0].victorias);

    muestraMensajeInfo("Ganancias:");
    scanf("%f", &lista.caballo[0].ganancias);
    gotoxy(4,14);
    printf("Ganancias:%f", lista.caballo[0].ganancias);
    altaCaballoSys(lista);

    return;
}
void gestionMenuCaballos()//gestiona el menu de los caballos
{
    int opcion_usuario;
    muestraMensajeTitulo("MENU CABALLOS");

   opcion_usuario = menuCaballos();

    while(opcion_usuario!=0)
    {
       switch (opcion_usuario)
    {
    case 1:
        listadoCaballos("hipodromo.db");
        getch();
        muestraMensajeTitulo("MENU CABALLOS");
        break;
    case 2:
        generaInformeCaballos();
        muestraMensajeInfo("El informe se ha generado con exito");
        getch();
        break;
    case 3:
        altaCaballoIU();
        getch();
        muestraMensajeTitulo("MENU CABALLOS");
        break;
    case 4:
        actualizaCaballoIU();
        getch();
        break;
    case 5:
        bajaCaballoIU();
        getch();
        break;
    case 6:
        caballoMasRentableIU();
        getch();
        break;
    case 7:
        caballoMasVictorioso();
        getch();
        break;
    /*case 8:
        fusionaListaCaballos();
        getch();
        muestraMensajeTitulo("MENU CABALLOS");
        break;
    case 9:
        fusionaCaballos();
        getch();
        muestraMensajeTitulo("MENU CABALLOS");
        break;
    case 10:
        clasificaCaballos();
        getch();
        muestraMensajeTitulo("MENU CABALLOS");
        break;*/
    }
    opcion_usuario = menuCaballos();
    }
    muestraMensajeTitulo("MENU PRINCIPAL");
}
int menuCaballos(void)//menu de los caballos
{
    int opcion;

    limpiarIzquierda();
    gotoxy(10,10);
    printf("1.Listado de caballos");
    gotoxy(10,11);
    printf("2.Informe de caballos");
    gotoxy(10,12);
    printf("3.Alta de un caballo");
    gotoxy(10,13);
    printf("4.Actualizar caballo");
    gotoxy(10,14);
    printf("5.Baja de un caballo");
    gotoxy(10,15);
    printf("6.Caballo mas rentable");
    gotoxy(10,16);
    printf("7.Caballo mas victorioso");
    gotoxy(10,17);
    printf("0.Menu anterior");

    opcion = leerOpcionValida("Seleccione una opcion:",7);

    return opcion;
}
void listadoCaballos(char basedatos[])//saca por pantalla los caballos de la base de datos despues de leerlos
{
    sCaballoNum lista;
    sCaballoNum *pLista = &lista;
    int lines;
    int i;
    lines=12;
    muestraMensajeTitulo("LISTADO CABALLOS");
    muestraMensajeInfo("                                        ");
    limpiarIzquierda();

    char tabla[] = "caballos";
    char *msgcargalista=0;
    cargaListaCaballosBD(pLista, basedatos, tabla, msgcargalista);

    muestraMensajeInfo(msgcargalista);
    cabeceraTabla();

        for (i=0;i<lista.numcaballos;i++)
    {
        gotoxy(4,lines);
        muestraCaballo(lista.caballo[i]);
        lines++;
    }
    muestraMensajeInfo("Pulse intro para continuar");
}
void cabeceraTabla(void)//imprime la cabecera de la tabla en pantalla
{
    gotoxy(4,10);
    printf("Nombre");
    gotoxy(14,10);
    printf("Nacion.");
    gotoxy(25,10);
    printf("DIE");
    gotoxy(31,10);
    printf("Vict.");
    gotoxy(39,10);
    printf("Edad");
    gotoxy(48,10);
    printf("Ganancias");

}
void muestraCaballo(sCaballo caballo)//saca el caballo que le metas por pantalla
{
    printf("%s\t", caballo.nombre);
    printf("%s\t", caballo.nacionalidad);
    printf("%ld\t", caballo.die);
    printf("%d\t", caballo.victorias);
    printf("%d\t", caballo.edad);
    printf("%.2f", caballo.ganancias);
}
void actualizaCaballoIU()//actualiza los datos del caballo que selecciones
{
    char ganador[50];
    float premio;
    char msg[100];

    listadoCaballos("hipodromo.db");

    muestraMensajeInfo("Teclee el nombre del caballo ganador: ");
    scanf("%s",ganador);

    muestraMensajeInfo("Teclee el premio obtenido: ");
    scanf("%f",&premio);

    actualizaCaballoSys(ganador, premio, msg);
    listadoCaballos("hipodromo.db");

    muestraMensajeInfo(msg);
}
void bajaCaballoIU()//elimina el caballo que selecciones
{
    char nombre[DIM_NOMBRE_CABALLO];
    char msg[100];

    listadoCaballos("hipodromo.db");
    muestraMensajeInfo("Teclee el nombre del caballo que desea dar de baja: ");
    scanf("%s", nombre);

    char baseDatos[] = "hipodromo.db";
    char tabla[] = "caballos";
    bajaCaballoSys(nombre, baseDatos, tabla, msg);
    listadoCaballos("hipodromo.db");

    muestraMensajeInfo(msg);
}
void caballoMasRentableIU()//saca por pantalla el caballo con mas ganancias
{
    sCaballoNum lista;
    sCaballoNum *pLista = &lista;
    int i;
    float masvalor;
    int indicecaballo;
    int lines=45;

    char baseDatos[]="hipodromo.db";
    char tabla[] = "caballos";
    char *msgcargalista=0;
    cargaListaCaballosBD(pLista, baseDatos, tabla, msgcargalista);
    muestraMensajeInfo(msgcargalista);

    masvalor=0;

    for (i=0;i<lista.numcaballos;i++)
    {
        if(lista.caballo[i].ganancias>masvalor)
        {
            masvalor=lista.caballo[i].ganancias;
            indicecaballo=i;
        }
    }
    limpiarIzquierda();
    cabeceraTabla();
    gotoxy(4,12);
    muestraCaballo(lista.caballo[indicecaballo]);
    gotoxy(10, lines-6);
    printf("                                                                          ");
    gotoxy(10, lines-6);
    printf("El caballo mas rentable es %s", lista.caballo[indicecaballo].nombre);
}
void caballoMasVictorioso()//saca por pantalla el caballo con mas victorias
{
    sCaballoNum lista;
    sCaballoNum *pLista = &lista;
    int i;
    float masvalor;
    int indicecaballo;
    int lines=45;

    char baseDatos[] = "hipodromo.db";
    char tabla[] = "caballos";
    char *msgcargalista=0;
    cargaListaCaballosBD(pLista, baseDatos, tabla, msgcargalista);
    muestraMensajeInfo(msgcargalista);

    masvalor=0;

    for (i=0;i<lista.numcaballos;i++)
    {
        if(lista.caballo[i].victorias>masvalor)
        {
            masvalor=lista.caballo[i].victorias;
            indicecaballo=i;
        }
    }
    limpiarIzquierda();
    cabeceraTabla();
    gotoxy(4,12);
    muestraCaballo(lista.caballo[indicecaballo]);
    gotoxy(10, lines-6);
    printf("                                                                          ");
    gotoxy(10, lines-6);
    printf("El caballo mas victorioso es %s", lista.caballo[indicecaballo].nombre);
}
void muestraListaCaballos(sCaballoNum lista)//similar a listado caballos
{
    int lines;
    int i;
    lines=12;
    muestraMensajeTitulo("LISTADO CABALLOS");
    muestraMensajeInfo("                                        ");
    limpiarIzquierda();

    cabeceraTabla();


        for (i=0;i<lista.numcaballos;i++)
    {
        gotoxy(4,lines);
        muestraCaballo(lista.caballo[i]);
        lines++;
    }
}
void creaarchivobd()
{
    sCaballoNum lista;
    sCaballoNum *pLista = &lista;
    char tabla[] = "caballos";
    char *msgcargalista=0;
    cargaListaCaballosBD(pLista, "hipodromo.db", tabla, msgcargalista);

    guardaListaCaballosAD(lista, "BaseDatos/caballoslista.dat");
    return;
}
/*void fusionaListaCaballos()//coge dos listas y añade los caballos iguales a una tercera
{
    sCaballoNum lista1;
    sCaballoNum *pLista1 = &lista1;
    sCaballoNum lista2;
    sCaballoNum *pLista2 = &lista2;
    sCaballoNum lista3;
    lista3.caballo=(sCaballo*)malloc(sizeof(sCaballo));
    char mensajecargacaballosSYS[100];

    char archivo1[]="BaseDatos/caballos1.dat";
    cargaListaCaballosSys(pLista1, archivo1, mensajecargacaballosSYS);
    char archivo2[]="BaseDatos/caballos2.dat";
    cargaListaCaballosSys(pLista2, archivo2, mensajecargacaballosSYS);

    int nummem=0;
    int num2=0;
    int num1;
    lista3.numcaballos=0;

    while(num2<lista2.numcaballos)
    {
        num1=0;

        while(num1<lista1.numcaballos)
        {
            if(lista2.caballo[num2].die==lista1.caballo[num1].die)
            {
                nummem++;
                lista3.caballo=(sCaballo*)realloc(lista3.caballo,nummem * sizeof(sCaballo));
                strcpy(lista3.caballo[lista3.numcaballos].nombre,lista1.caballo[num1].nombre);
                lista3.caballo[lista3.numcaballos].die=lista1.caballo[num1].die;
                lista3.caballo[lista3.numcaballos].victorias=lista1.caballo[num1].victorias+lista2.caballo[num2].victorias;
                lista3.caballo[lista3.numcaballos].ganancias=lista1.caballo[num1].ganancias+lista2.caballo[num2].ganancias;

                lista3.numcaballos++;
            }
            num1++;
        }
        num2++;
    }
    char archivo3[]="BaseDatos/caballos3.dat";
    guardaListaCaballosSys(lista3, archivo3);
    muestraListaCaballos(lista1);
    muestraMensajeInfo("Estos son los caballos del primer archivo(Intro para continuar)");
    getch();
    muestraListaCaballos(lista2);
    muestraMensajeInfo("Estos son los caballos del segundo archivo(Intro para continuar)");
    getch();
    muestraListaCaballos(lista3);
    muestraMensajeInfo("Estos son los caballos comunes a los dos archivos");

    free(lista3.caballo);
}*/
/*void fusionaCaballos()//fusiona los caballos iguales y añade los diferentes
{
    sCaballoNum lista1;
    sCaballoNum *pLista1 = &lista1;
    sCaballoNum lista2;
    sCaballoNum *pLista2 = &lista2;
    char mensajecargacaballosSYS[100];

    char archivo1[]="BaseDatos/caballos11.dat";
    cargaListaCaballosSys(pLista1, archivo1, mensajecargacaballosSYS);
    char archivo2[]="BaseDatos/caballos21.dat";
    cargaListaCaballosSys(pLista2, archivo2, mensajecargacaballosSYS);

    muestraListaCaballos(lista1);
    muestraMensajeInfo("Caballos del primer archivo antes de la comparacion(Intro para continuar)");
    getch();
    muestraListaCaballos(lista2);
    muestraMensajeInfo("Caballos del segundo archivo(Intro para continuar)");
    getch();

    int num2=0;
    int num1;
    //sCaballoNum listaalta;
    while(num2<lista2.numcaballos)
    {
        num1=0;

        while(num1<lista1.numcaballos)
        {
            if(lista2.caballo[num2].die==lista1.caballo[num1].die)
            {
                lista1.caballo[num1].victorias=lista1.caballo[num1].victorias+lista2.caballo[num2].victorias;
                lista1.caballo[num1].ganancias=lista1.caballo[num1].ganancias+lista2.caballo[num2].ganancias;
            break;
            }
            num1++;
        }
        if(num1==lista1.numcaballos)
        {
            lista1.caballo[lista1.numcaballos].die=lista2.caballo[num2].die;
            lista1.caballo[lista1.numcaballos].victorias=lista2.caballo[num2].victorias;
            lista1.caballo[lista1.numcaballos].ganancias=lista2.caballo[num2].ganancias;
            strcpy(lista1.caballo[lista1.numcaballos].nombre,lista2.caballo[num2].nombre);
            lista1.numcaballos++;

        }
        num2++;
    }
    //cargaListaCaballosSys(pLista1, archivo1);
    muestraListaCaballos(lista1);
    muestraMensajeInfo("Caballos comparados");
    free(lista1.caballo);
    free(lista2.caballo);

}*/
/*void clasificaCaballos(void)//hace un corte en base a las victorias que le metas y los añade a otro archivo
{
    sCaballoNum lista1;
    sCaballoNum *pLista1 = &lista1;
    sCaballoNum lista2;
    int nummem=0;
    lista2.caballo=(sCaballo*)malloc(sizeof(sCaballo));
    int victmin;
    char archivo[100];
    char archivo2[100];

    limpiarIzquierda();
    muestraMensajeInfo("Introduzca el requisito de victorias:");
    scanf("%d", &victmin);
    muestraMensajeInfo("Introduzca el nombre del archivo:");
    scanf("%s", archivo2);
    //strcat(archivo2,".dat");
    sprintf(archivo, "BaseDatos/%s.dat", archivo2);

    char archivo1[]="hipodromo.db";
    cargaListaCaballosBD(pLista1, archivo1);

    int num1=0;
    lista2.numcaballos=0;

    while(num1<lista1.numcaballos)
    {
        if(lista1.caballo[num1].victorias>=victmin)
        {
            nummem++;
            lista2.caballo=(sCaballo*)realloc(lista2.caballo,nummem * sizeof(sCaballo));
            strcpy(lista2.caballo[lista2.numcaballos].nombre, lista1.caballo[num1].nombre);
            lista2.caballo[lista2.numcaballos].die=lista1.caballo[num1].die;
            lista2.caballo[lista2.numcaballos].victorias=lista1.caballo[num1].victorias;
            lista2.caballo[lista2.numcaballos].ganancias=lista1.caballo[num1].ganancias;
            lista2.numcaballos ++;
        }
        num1++;
    }
    guardaListaCaballosSys(lista2, archivo);
    inicializaHipodromo("hipodromoclasificado.db", archivo);
    listadoCaballos("hipodromoclasificado.db");
    muestraMensajeInfo("Estos son los caballos clasificados");
    free(lista2.caballo);
}*/


