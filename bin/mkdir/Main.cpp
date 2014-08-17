/* AMAYA OS 2014 */
/*
 * Copyright (C) 2014 Daniel Martin
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int argi;
    /* Obtenemos los argumentos de la linea de comandos */
    if(argc < 2) { /* Si hay menos de 2 avisa al usuario */
        printf("uso: %s DIRECTORIO\n", argv[0]);
        return EXIT_FAILURE;
    }
    for (argi=1; argv[argi]; argi++) {
      if (argv[argi][0]!='/') { /* Necesito una ruta.... */
        printf("ERROR ! ");
        printf(argv[argi]);
        printf(" No es una ruta\r\n");
        return EXIT_SUCCESS;
      }
    }
        
    for (i=1; argv[i]; i++) {
      /* Función mkdir */
      mkdir(argv[i], S_IWUSR | S_IRUSR);
    }
    return EXIT_SUCCESS; /* Todo ha salido bien */
}
