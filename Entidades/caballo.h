#define DIM_NOMBRE_CABALLO 20
#define DIM_NACIONALIDAD 5
#include <stdio.h>

typedef struct caballostr
{
   char  nacionalidad[DIM_NACIONALIDAD];
   long  die;
   int   victorias;
   float ganancias;
   int   edad;
   char  nombre[DIM_NOMBRE_CABALLO];
} sCaballo;

typedef struct caballonumstr
{
    int numcaballos;
    sCaballo *caballo;
} sCaballoNum;
