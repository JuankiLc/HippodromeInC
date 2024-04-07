#ifndef CABALLOSYS_H_INCLUDED
#define CABALLOSYS_H_INCLUDED
#include <stdbool.h>
#define DIM_NOMBRE_CABALLO 20


int altaCaballoSys(sCaballoNum lista);
void generaInformeCaballos(void);
int cargaListaCaballosSys(sCaballoNum *lista, char *archivo, char *mensaje);
bool guardaListaCaballosSys(sCaballoNum lista, char *archivo);
bool bajaCaballoSys(char nombre[DIM_NOMBRE_CABALLO], char baseDatos[], char tabla[], char *msg);
bool actualizaCaballoSys(char nombre[],float premio, char *msg);

#endif // CABALLOSYS_H_INCLUDED
