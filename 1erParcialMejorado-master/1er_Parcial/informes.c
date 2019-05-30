#include <stdio.h>
///#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "validaciones.h"
#include "informes.h"
#define VACIO -1
#define LLENO 1

void informeA(Orquesta *eOrquesta, int cant)
{
    int i;
    char auxOrq[50];

    getDireccion(auxOrq,
                 "\n Ingrese lugar de las listas que desee ver: ",
                 "\n Error, vuelva a intentar.",
                 1,
                 51,
                 1);

    for(i=0; i<cant; i++)
    {
        if(eOrquesta[i].isEmpty == LLENO && strcmp(eOrquesta[i].lugar, auxOrq) == 0)
        {
            printf("\n ID de la orquesta: %d", eOrquesta[i].idOrquesta);
            printf("\n Nombre de la orquesta: %s", eOrquesta[i].nombreOrquesta);
            printf("\n Tipo de orquesta: %d", eOrquesta[i].tipoOrquesta);
            printf("\n Lugar de la orquesta: %s \n", eOrquesta[i].lugar);
        }
    }
}

void informeB(Musico *eMusico,
              Instrumento *eInstrumento,
              Orquesta *eOrquesta,
              int cantUno,
              int cantDos,
              int cantTres)
{
    int i;
    int j;
    int k;

    for(i=0; i<cantUno; i++)
    {
        if(eMusico[i].isEmpty == LLENO && eMusico[i].edad < 25)
        {
            printf("\n ID del musico: %d", eMusico[i].idMusico);
            printf("\n Nombre del musico: %s", eMusico[i].nombreMusico);
            printf("\n Apellido del musico: %s", eMusico[i].apellidoMusico);
            printf("\n Edad del musico: %d", eMusico[i].edad);

            for(j=0; j<cantDos; j++)
            {
                if(eInstrumento[j].isEmpty == LLENO && eInstrumento[j].idInstrumento == eMusico[i].idInstrumento)
                {
                    printf("\n Nombre de su instrumento: %s", eInstrumento[j].nombreInstrumento);
                }
            }
            for(k=0; k<cantTres; k++)
            {
                if(eOrquesta[k].isEmpty == LLENO && eOrquesta[k].idOrquesta == eMusico[i].idOrquesta)
                {
                    printf("\n Lugar de la orquesta: %s \n", eOrquesta[k].lugar);
                }
            }
        }
    }
}

void informeC(Orquesta *eOrquesta, Musico *eMusico, int cantUno, int cantDos)
{
    int i;
    int j;
    int contadorMus = 0;
    int flagUno = 0;
    Orquesta auxOrquesta[cantUno];

    for(i=0; i<cantUno; i++)
    {
        if(eOrquesta[i].isEmpty == LLENO )
        {
            flagUno = 1;
            auxOrquesta[i] = eOrquesta[i];
            contadorMus = 0;

            for(j=0; j<cantDos; j++)
            {
                if(flagUno != 0 &&
                   eOrquesta[i].idOrquesta == auxOrquesta[0].idOrquesta)
                {
                    if(eOrquesta[i].idOrquesta == eMusico[j].idOrquesta)
                    {
                        contadorMus ++;
                    }
                }
                else if(flagUno != 0 &&
                        eOrquesta[i].idOrquesta != auxOrquesta[0].idOrquesta)
                {
                    if(eOrquesta[i].idOrquesta == eMusico[j].idOrquesta)
                    {
                        contadorMus++;
                    }
                }
            }
        }
        if(contadorMus < 6 && eOrquesta[i].isEmpty == LLENO)
        {
            printf("\n ID de la orquesta: %d", eOrquesta[i].idOrquesta);
            printf("\n Nombre de la orquesta: %s", eOrquesta[i].nombreOrquesta);
            printf("\n Tipo de orquesta: %d", eOrquesta[i].tipoOrquesta);
            printf("\n Lugar de la orquesta: %s \n", eOrquesta[i].lugar);
        }
    }
}

void informeD(Orquesta *eOrquesta,
              Musico *eMusico,
              Instrumento *eInstrumento,
              int cantUno,
              int cantDos,
              int cantTres)
{
    int i;
    int j;
    int k;
    char idOrq[50];
    int auxId;

    getInt("\n Ingrese ID de la orquesta a la que quiere listar sus instrumentos: ",
           "\n Error, vuelva a intentar.",
           0,
           20,
           1,
           idOrq);
    auxId = atoi(idOrq);

    for(i=0; i<cantUno; i++)
    {
        if(eOrquesta[i].isEmpty == LLENO &&
           auxId == eOrquesta[i].idOrquesta)
        {
            for(j=0; j<cantDos; j++)
            {
                if(eMusico[j].isEmpty == LLENO &&
                   eMusico[j].idOrquesta == eOrquesta[i].idOrquesta)
                {
                    printf("\n Nombre del musico que toca el instrumento: %s", eMusico[j].nombreMusico);

                    for(k=0; k<cantTres; k++)
                    {
                        if (eInstrumento[k].isEmpty == LLENO &&
                            eMusico[j].idInstrumento == eInstrumento[k].idInstrumento)
                        {
                            printf("\n Nombre del instrumento: %s", eInstrumento[k].nombreInstrumento);
                            printf("\n Tipo de instrumento: %d \n", eInstrumento[k].tipoInstrumento);
                        }
                    }
                }
            }
        }
    }
}

void informeE(Orquesta *eOrquesta,
              Musico *eMusico,
              Instrumento *eInstrumento,
              int cantUno,
              int cantDos,
              int cantTres)
{
    int i;
    int j;
    int k;
    int contadorDeCuerdas = 0;
    int contadorDeViento = 0;
    int contadorDePercusion = 0;

    for (i=0; i<cantUno; i++)
    {
        if(eOrquesta[i].isEmpty == LLENO)
        {
            for (j=0; j<cantDos; j++)
            {
                if(eMusico[j].idOrquesta == eOrquesta[i].idOrquesta)
                {
                    for (k=0; k<cantTres; k++)
                    {
                        if(eInstrumento[k].idInstrumento == eMusico[j].idInstrumento)
                        {
                            if(eInstrumento[k].tipoInstrumento == 1)
                            {
                                contadorDeCuerdas ++;
                            }
                            if(eInstrumento[k].tipoInstrumento == 2 || eInstrumento[k].tipoInstrumento == 3)
                            {
                                contadorDeViento ++;
                            }
                            if(eInstrumento[k].tipoInstrumento == 4)
                            {
                                contadorDePercusion ++;
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0; i<cantUno; i++)
    {
        if(contadorDeCuerdas >= 4 && contadorDeViento >= 4 && contadorDePercusion >= 1)
        {
            printf("\n ID de la orquesta: %d", eOrquesta[i].idOrquesta);
            printf("\n Nombre de orquesta: %s", eOrquesta[i].nombreOrquesta);
            printf("\n Lugar de la orquesta: %s", eOrquesta[i].lugar);
            printf("\n Tipo de orquesta: %d \n", eOrquesta[i].tipoOrquesta);
            break;
        }
    }
}

void informeG(Musico *eMusico, Instrumento *eInstrumento, Orquesta *eOrquesta, int cantUno, int cantDos, int cantTres)
{
    int i;
    int j;
    int k;
    float contadorInstrumento = 0;
    int contadorOrquesta = 0;
    float promedio;

    for(i=0; i<cantUno; i++)
    {
        if(eMusico[i].isEmpty == LLENO)
        {
            for(j=0; j<cantDos; j++)
            {
                if(eInstrumento[j].isEmpty == LLENO && eMusico[i].idInstrumento == eInstrumento[j].idInstrumento)
                {
                    contadorInstrumento ++;
                }
            }
        }
    }
    for(k=0; k<cantTres; k++)
    {
        if(eOrquesta[k].isEmpty == LLENO)
        {
            contadorOrquesta ++;
        }
    }
    promedio = contadorInstrumento / contadorOrquesta;
    printf("\n El promedio de instrumentos por orquesta es: %.2f \n", promedio);
}

void informeH(Musico *eMusico,
              Instrumento *eInstrumento,
              int cantUno,
              int cantDos)
{
    int i;
    int j;
    int k;
    int z;
    Musico auxMusico;
    printf("\n  Ordenado alfabeticamente por apellido: \n");

    for(i = 1; i<cantUno; i++)
    {
        auxMusico = eMusico[i];
        j = i;

        while(j > 0 && strcmp(auxMusico.apellidoMusico, eMusico[j-1].apellidoMusico) < 0)
        {
            eMusico[j] = eMusico[j-1];
            j--;
        }
        eMusico[j] = auxMusico;
    }
    for (k=0; k<cantUno; k++)
    {
        if(eMusico[k].isEmpty == LLENO )
        {
            for(z=0; z<cantDos; z++)
            {
                if(eMusico[k].idInstrumento == eInstrumento[z].idInstrumento &&
                   eInstrumento[z].isEmpty == LLENO)
                {
                    if(eInstrumento[z].tipoInstrumento !=2 &&
                       eInstrumento[z].tipoInstrumento != 3 )
                    {
                        printf("\n Nombre del musico: %s", eMusico[k].nombreMusico);
                        printf("\n Apellido del musico: %s", eMusico[k].apellidoMusico);
                        printf("\n Edad del musico: %d", eMusico[k].edad);
                        printf("\n Tipo de intstrumento que toca: %d \n", eInstrumento[z].tipoInstrumento);
                    }
                }
            }
        }
    }
}
