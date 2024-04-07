#include <stdio.h>
#include "../Entidades/caballo.h"
#include <stdbool.h>
#include "caballoSys.h"
#include "../AccesoDatos/caballoAD.h"
#include "../InterfazUsuario/interfazGrafica.h"
#include "../AccesoDatos/caballoBD.h"


int altaCaballoSys(sCaballoNum lista)
{
    altaCaballoAD(lista);
    return 0;
}
void generaInformeCaballos(void)//acabado y funciona
{
    sCaballoNum lista;
    sCaballoNum *pLista = &lista;

    FILE *archivo2;

    char baseDatos[] = "hipodromo.db";
    char tabla[] = "caballos";
    char *msgcargalista=0;
    cargaListaCaballosBD(pLista, baseDatos, tabla, msgcargalista);
    muestraMensajeInfo(msgcargalista);
    archivo2=fopen("BaseDatos/infoCaballos.txt","wt");
        if (archivo2 == NULL)
        {
        muestraMensajeInfo( "No se puede abrir el archivo infoCaballos.txt.");
        exit( 1 );
        }

    fprintf(archivo2,"DIE\tVict.\tGanancias\tNombre\n");

    int i;
    for (i=0;i<lista.numcaballos;i++)
    {
        fprintf(archivo2,"%ld\t", lista.caballo[i].die);
        fprintf(archivo2,"%d\t", lista.caballo[i].victorias);
        fprintf(archivo2,"%f\t", lista.caballo[i].ganancias);
        fprintf(archivo2,"%s\n", lista.caballo[i].nombre);
    }
    fclose(archivo2);
}
int cargaListaCaballosSys(sCaballoNum *lista, char *archivo, char *mensaje)
{
    cargaListaCaballosAD(lista, archivo, mensaje);
    return 1;
}
bool guardaListaCaballosSys(sCaballoNum lista, char *archivo)
{
    guardaListaCaballosAD(lista, archivo);
    return true;
}
bool bajaCaballoSys(char nombre[DIM_NOMBRE_CABALLO], char baseDatos[], char tabla[], char *msg)
{
    if(bajaCaballoBD(nombre, baseDatos, tabla, msg)==0)
        return false;
    else
        return true;
}
bool actualizaCaballoSys(char nombre[],float premio, char *msg)
{
    if(actualizaCaballoBD(nombre, premio, msg)==0)
        return false;
    else
        return true;
}
