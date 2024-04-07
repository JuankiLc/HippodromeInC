#ifndef CABALLOIU_H_INCLUDED
#define CABALLOIU_H_INCLUDED
#define DIM_NOMBRE_CABALLO 20
#define NUM_CABALLOS 50


void altaCaballoIU();
void gestionMenuCaballos();
int menuCaballos(void);
void listadoCaballos(char archivo[]);
void cabeceraTabla(void);
void muestraCaballo(sCaballo caballo);
void actualizaCaballoIU();
void bajaCaballoIU();
void caballoMasRentableIU();
void caballoMasVictorioso();
void muestraListaCaballos(sCaballoNum lista);
void fusionaListaCaballos();
void fusionaCaballos();
void clasificaCaballos(void);
void creaarchivobd();

#endif // CABALLOIU_H_INCLUDED
