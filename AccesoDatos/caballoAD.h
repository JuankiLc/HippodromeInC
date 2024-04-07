#ifndef CABALLOAD_H_INCLUDED
#define CABALLOAD_H_INCLUDED
#define DIM_NOMBRE_CABALLO 20
#define NUM_CABALLOS 50
#include <stdbool.h>


void escribeCaballoTXT(sCaballo caballo, FILE *ptr);
int altaCaballoAD(sCaballoNum lista);
bool cargaListaCaballosAD(sCaballoNum *lista, char *archivo, char *msgError);
bool guardaListaCaballosAD(sCaballoNum lista, char *archivo);
int getNumCaballos(char *archivo);
#endif // CABALLOAD_H_INCLUDED
