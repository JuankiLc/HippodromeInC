#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

void inicializaHipodromo(const char basedatos[], char archivo1[]);
bool insertaCaballoBD(const char basedatos[], char nombreTabla[], sCaballo caballo, char *mensaje);
bool bajaCaballoBD(char nombre[DIM_NOMBRE_CABALLO], char baseDatos[], char tabla[], char *msg);
bool actualizaCaballoBD(char nombre[],float premio, char *msg);
bool cargaListaCaballosBD(sCaballoNum *lista, char basedatos[], char tabla[], char *msg);
