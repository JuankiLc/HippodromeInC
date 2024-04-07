#include <stdio.h>
#include "../Entidades/caballo.h"
#include <stdbool.h>
#include "caballoAD.h"
#include "../InterfazUsuario/interfazGrafica.h"
#include "../InterfazSistema/caballoSys.h"
#include "../InterfazUsuario/caballoIU.h"
#include "../InterfazUsuario/interfazUsuario.h"
#include "caballoBD.h"
#include <stdlib.h>

void escribeCaballoTXT(sCaballo caballo, FILE *ptr)
{
    fprintf(ptr,"%s\t", caballo.nacionalidad);
    fprintf(ptr,"%ld\t", caballo.die);
    fprintf(ptr,"%d\t", caballo.victorias);
    fprintf(ptr,"%f\t", caballo.ganancias);
    fprintf(ptr,"%d\t", caballo.edad);
    fprintf(ptr,"%s\n", caballo.nombre);


}
int altaCaballoAD(sCaballoNum lista)
{
    char mensaje[100];
    insertaCaballoBD("hipodromo.db", "caballos", lista.caballo[0], mensaje);
    muestraMensajeInfo(mensaje);
    return 0;
}
bool cargaListaCaballosAD(sCaballoNum *lista, char *archivo, char *msgError)
{
    FILE *ptr = fopen(archivo, "rb");

    if (ptr == NULL)
    {
        msgError="El archivo no se puedee abrir correctamente";
        return false;
    }
    else
    {
        lista->numcaballos=getNumCaballos(archivo);
        /*printf("%d", lista->numcaballos);
        getch();*/
        lista->caballo=(sCaballo*)malloc(lista->numcaballos * sizeof(sCaballo));
        for(lista->numcaballos=0; (fread(&lista->caballo[lista->numcaballos], sizeof (sCaballo), 1, ptr)==1); lista->numcaballos++);
    }
    fclose(ptr);

    return true;

}
bool guardaListaCaballosAD(sCaballoNum lista, char *archivo)
{
    int i;
    FILE *ptr = fopen(archivo, "wb");

    if (ptr == NULL)
    {
        muestraMensajeInfo( "No se puede abrir el archivo caballos.dat.");
        return false;
    }
    for (i=0; (i<lista.numcaballos); i++)
    {
        fwrite(&lista.caballo[i], sizeof (sCaballo), 1, ptr);
    }
    fclose(ptr);
    return true;
}
int getNumCaballos(char *archivo)
{
    int numCaballos;
    FILE *ptr = fopen(archivo, "rb");

    if (ptr == NULL)
    {
        muestraMensajeInfo( "No se puede abrir el archivo caballos.dat.");
        return false;
    }

    fseek(ptr, 0, SEEK_END);
    numCaballos = ftell(ptr)/sizeof(sCaballo);

    return numCaballos;
}
