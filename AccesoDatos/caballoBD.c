#include <stdio.h>
#include "../Entidades/caballo.h"
#include <stdlib.h>
#include <stdbool.h>
#include "../AccesoDatos/caballoAD.h"
#include "caballoBD.h"
#include "misqlite3.h"
#include <string.h>
#include "../InterfazUsuario/interfazGrafica.h"


void inicializaHipodromo(const char basedatos[], char archivo1[])
{
    int rc;
    sqlite3 *db;
    char *consulta;
    char *zErrMsg = 0;
    char mensaje[100];
    char mensajecargalistacaballosAD[100];

    char *mensajeabrebase=0;
    db  = abreBaseDatos(basedatos, mensajeabrebase);
    muestraMensajeInfo(mensajeabrebase);

    consulta = "CREATE TABLE caballos (" \
               "nacionalidad TEXT NOT NULL," \
               "die INT NOT NULL," \
               "victorias INT NOT NULL," \
               "ganancias REAL NOT NULL," \
               "edad INT NOT NULL," \
               "nombre TEXT NOT NULL);";

    rc = sqlite3_exec(db, consulta, 0, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        sprintf (mensaje, "Error de SQL: %s.", zErrMsg);
        muestraMensajeInfo(mensaje);
        sqlite3_free (zErrMsg);
    }
    else
        sprintf (mensaje, "Tabla creada correctamente.");
        muestraMensajeInfo(mensaje);

    sCaballoNum lista;
    sCaballoNum *pLista = &lista;

    sqlite3_close(db);

    cargaListaCaballosAD(pLista, archivo1, mensajecargalistacaballosAD);

    /*printf("%s\t", lista.caballo[1].nombre);
    printf("%s\t", lista.caballo[1].nacionalidad);
    printf("%ld\t", lista.caballo[1].die);
    printf("%d\t", lista.caballo[1].victorias);
    printf("%d\t", lista.caballo[1].edad);
    printf("%.2f", lista.caballo[1].ganancias);
    getch();*/
    /*consulta = "TRUNCATE TABLE caballos;";

    rc = sqlite3_exec(db, consulta, 0, 0, &zErrMsg);

    if(rc != SQLITE_OK)
    {
        sprintf (mensaje, "Error de SQL: %s.", zErrMsg);
        muestraMensajeInfo(mensaje);
        sqlite3_free (zErrMsg);
    }*/

    int i;

    for(i=0; (i<lista.numcaballos); i++)
    {
        char mensaje[100];
        insertaCaballoBD(basedatos, "caballos", lista.caballo[i], mensaje);
        muestraMensajeInfo(mensaje);
    }

    muestraMensajeInfo("El hipodromo se ha inicializado correctamente.");
    return;
}
bool insertaCaballoBD(const char basedatos[], char nombreTabla[], sCaballo caballo, char *mensaje)
{
    int rc;
    sqlite3 *db;
    char consulta[100];
    char *zErrMsg = 0;

    char *mensajeabrebase=0;
    db  = abreBaseDatos(basedatos, mensajeabrebase);
    muestraMensajeInfo(mensajeabrebase);
    sprintf(consulta, "INSERT INTO '%s' VALUES('%s', %ld, %d, %f, %d, '%s');",
            nombreTabla, caballo.nacionalidad, caballo.die, caballo.victorias, caballo.ganancias, caballo.edad, caballo.nombre);

    rc = sqlite3_exec(db, consulta, 0, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        sprintf (mensaje, "Error de SQL: %s.", zErrMsg);
        sqlite3_free (zErrMsg);
        sqlite3_close(db);
        return false;
    }
    else
        sprintf (mensaje, "Registro insertado correctamente.");
    sqlite3_close(db);
    return true;
}
bool bajaCaballoBD(char nombre[DIM_NOMBRE_CABALLO], char baseDatos[], char tabla[], char *msg)
{
    int rc;
    sqlite3 *db;
    char consulta[100];
    char *zErrMsg = 0;

    char *mensajeabrebase=0;
    db  = abreBaseDatos(baseDatos, mensajeabrebase);
    muestraMensajeInfo(mensajeabrebase);
    sprintf(consulta, "DELETE FROM '%s' WHERE nombre = '%s';", tabla, nombre);

    rc = sqlite3_exec(db, consulta, 0, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        sprintf (msg, "Error de SQL: %s.\n", zErrMsg);
        sqlite3_free (zErrMsg);
        sqlite3_close(db);
        return false;
    }
    else
        sprintf (msg, "Registro eliminado correctamente.\n");
    sqlite3_close(db);
    return true;
}
bool actualizaCaballoBD(char nombre[],float premio, char *msg)
{
    int rc;
    sqlite3 *db;
    char consulta[100];
    char *zErrMsg = 0;

    char *mensajeabrebase=0;
    db  = abreBaseDatos("hipodromo.db", mensajeabrebase);
    muestraMensajeInfo(mensajeabrebase);

    sprintf(consulta, "UPDATE caballos SET victorias =  victorias+1 ,ganancias = ganancias+%f WHERE nombre = '%s';", premio, nombre);

    rc = sqlite3_exec(db, consulta, 0, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        sprintf (msg, "Error de SQL: %s.", zErrMsg);
        sqlite3_free (zErrMsg);
        sqlite3_close(db);
        return false;
    }
    else
        sprintf (msg, "Registro actualizado correctamente.");
    sqlite3_close(db);
    return true;
}
bool cargaListaCaballosBD(sCaballoNum *lista, char basedatos[], char tabla[], char *msg)
{
    lista->caballo = (sCaballo*) malloc(sizeof (sCaballo));

    sqlite3_stmt *ppStmt;
    sqlite3 *db;
    char *zErrMsg = 0;

    char *mensajeabrebase=0;
    db = abreBaseDatos(basedatos, mensajeabrebase);
    muestraMensajeInfo(mensajeabrebase);

    if(db == NULL)
    {
        sqlite3_close(db);
        return false;
    }

    char consulta[100];

    sprintf(consulta, "SELECT * FROM '%s';", tabla);

    int rc = sqlite3_prepare_v2(db, consulta, -1, &ppStmt, 0);

    if(rc!=SQLITE_OK)
    {
        sprintf (msg, "Error de SQL: %s.\n", sqlite3_errmsg(db));
        sqlite3_free (zErrMsg);
        sqlite3_close(db);
        return false;
    }

    int i = 0;

    while(SQLITE_ROW == sqlite3_step(ppStmt))
    {
        lista->caballo = (sCaballo*) realloc(lista->caballo, (sizeof(sCaballo)*(1+i)));

        strcpy(lista->caballo[i].nacionalidad, (char*)sqlite3_column_text(ppStmt, 0));
        lista->caballo[i].die = sqlite3_column_int(ppStmt, 1);
        lista->caballo[i].victorias = sqlite3_column_int(ppStmt, 2);
        lista->caballo[i].ganancias = sqlite3_column_double(ppStmt, 3);
        lista->caballo[i].edad = sqlite3_column_int(ppStmt, 4);
        strcpy(lista->caballo[i].nombre, (char*)sqlite3_column_text(ppStmt, 5));
        i++;
    }
    lista->numcaballos = i;

    sqlite3_finalize(ppStmt);

    if(rc!=SQLITE_OK)
    {
        sprintf (msg, "Error de SQL: %s.\n", zErrMsg);
        sqlite3_free (zErrMsg);
        sqlite3_close(db);
        return false;
    }
    sqlite3_close(db);
    return true;
}
