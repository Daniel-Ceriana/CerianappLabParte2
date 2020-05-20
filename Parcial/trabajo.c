#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "validaciones.h"
#include "servicios.h"
#include "trabajo.h"


/*
id de trabajo
id de mascota a la que se le asigna el trabajo
id de servicio ( osea el tipo de trabajo que se esta asignando)
fecha en la que se pidio el trabajo
isEmpty para saber si este id de trabajo esta siendo usado

*/


int altaTrabajo(eTrabajo* trabajos, int tamTrab, eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eServicio* servicios, int tamServ,eCliente* cliente,int tamCli)
{
    int retorno = -1;
    int indiceTrabajo;
    int auxIdMascota;
    int mascotaEncontrada;
    int auxServicio;
    int servicioEncontrado;
    int auxFechaDia;
    int auxFechaMes;
    int auxFechaAnio;
    indiceTrabajo = buscarSiguienteTrabajo(trabajos,tamTrab);
    system("cls");

    if(indiceTrabajo!=-1)
    {
        printf("El id de este trabajo sera: %d\n",indiceTrabajo);


        if(mostrarMascotas(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli)!=-1)
        {
            do
            {
                utn_getNumero(&auxIdMascota,"Ingrese un id de mascota valido: ","Error. Id de mascota invalido.\n",0,tamMasc,3);
                mascotaEncontrada= buscarPorId(mascotas,tamMasc,auxIdMascota);
            }
            while(mascotaEncontrada == -1);

            listarServicios(servicios,tamServ);

            do{
                servicioEncontrado = utn_getNumero(&auxServicio,"Ingrese el id del servicio correspondiente: ", "Ha ocurrido un error. Vuelva a intentarlo\n",servicios[0].idServicio,servicios[tamServ-1].idServicio,3);
            }while(servicioEncontrado == -1);


            utn_getNumero(&auxFechaDia,"Ingrese un dia: ","Error dia no valido. Reintente\n",1,31,10);

            utn_getNumero(&auxFechaMes,"Ingrese un mes: ","Error mes no valido. Reintente\n",1,12,10);

            utn_getNumero(&auxFechaAnio,"Ingrese un anio: ","Error anio no valido. Reintente\n",1900,2100,10);


            trabajos[indiceTrabajo].id=indiceTrabajo;
            trabajos[indiceTrabajo].idMascota=auxIdMascota;
            trabajos[indiceTrabajo].idServicio=auxServicio;
            trabajos[indiceTrabajo].isEmpty=0;
            trabajos[indiceTrabajo].fecha.dia=auxFechaDia;
            trabajos[indiceTrabajo].fecha.mes=auxFechaMes;
            trabajos[indiceTrabajo].fecha.anio=auxFechaAnio;

        }
        else
        {
            printf("No existen mascotas en el sistema\n\n");
        }

    }
    else
    {
        printf("sistema lleno de trabajos. No es posible ingresar mas");
    }


    return retorno;
}

int buscarSiguienteTrabajo(eTrabajo* Trabajos,int tamTrab)
{

    int retorno = -1;
    for(int i = 0; i<tamTrab; i++)
    {
        if(Trabajos[i].isEmpty)
        {
            Trabajos[i].isEmpty = 0;
            retorno = i;
            break;
        }
    }


    return retorno;
}

int listarTrabajos(eTrabajo* trabajos,int tamTrab,eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores, eServicio* servicios, int tamServ)
{
    int retorno=-1;
    int bandera = 1;

    system("cls");
    printf("*************Listar Trabajos*************\n");
    printf("ID-Trabajo        Servicio    Precio  Id-Mascota   Nombre      Tipo        Color       Edad    Fecha Ingresado\n");

    for(int i = 0; i<tamTrab;i++){
            if(trabajos[i].isEmpty == 0)
            {
                listarTrabajo(trabajos[i],tamTrab,mascotas,tamMasc,tipos,tamTipos,colores,tamColores,servicios,tamServ);
                bandera = 0;
                retorno = 0;
            }
    }

    if(bandera){
        printf("No hay trabajos cargadas en el sistema\n");
    }




return retorno;
}

void listarTrabajo(eTrabajo trabajo,int tamTrab,eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores, eServicio* servicios, int tamServ)
{
    //variables usadas para saber la descripcion de cada estructura
    int indiceMascota;
    indiceMascota = buscarPorId(mascotas,tamMasc,trabajo.idMascota);
    char descripcionTipo[20];
    cargarDescripcionTipo(descripcionTipo,mascotas[indiceMascota].idTipo,tipos,tamTipos);
    char descripcionColor[20];
    cargarDescripcionColor(descripcionColor,mascotas[indiceMascota].idColor,colores,tamColores);
    char descripcionServicio[25];
    cargarDescripcionServicio(descripcionServicio,trabajo.idServicio,servicios,tamServ);


    float precio;
    for(int i = 0; i< tamServ;i++){//recorro el array de servicios para saber el precio del servicio
        if(trabajo.idServicio == servicios[i].idServicio){
            precio = servicios[i].precio;
        }
    }




    printf("%-15d     %-3s      $%.2f     %d     ",trabajo.id,descripcionServicio,precio,trabajo.idMascota);
    printf("   %-7s    %s        %s       %d     ",mascotas[indiceMascota].nombreMascota,descripcionTipo,descripcionColor,mascotas[indiceMascota].edad);
    printf("%d/%d/%d\n",trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);


}





void inicializarTrabajos(eTrabajo* trabajos,int tamTrab)
{

    for (int i = 5; i< tamTrab; i++)
    {
        trabajos[i].isEmpty = 1;

    }
}

