#include <stdio.h>
#include <stdlib.h>
#include "misqlite3.h"
#include "../InterfazUsuario/interfazGrafica.h"

sqlite3 * abreBaseDatos(const char nombre[], char *mensaje)
{
    int rc;
    sqlite3 *db;

    rc = sqlite3_open(nombre, &db);
    if ( SQLITE_OK != rc )
    {
        sprintf (mensaje, "No puedo abrir la base de datos:%s", sqlite3_errmsg(db));
        exit(0);
    }
    else
        //sprintf (mensaje, "Base de datos abierta con exito");

    return db;
}
