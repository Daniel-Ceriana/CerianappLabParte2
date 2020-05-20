#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "servicios.h"



void listarServicio(eServicio servicio,int tamServ){

    printf("%-9d %-15s $%.2f\n",servicio.idServicio,servicio.descripcion,servicio.precio);

}

int listarServicios(eServicio* servicios,int tamServicios)
{
    int retorno = -1;
    printf("************Listar Servicios************\n\n");
    printf("ID        Descripcion     Precio\n\n");

    for(int i = 0; i<tamServicios; i++)
    {
        listarServicio(servicios[i],tamServicios);
        retorno =0;
    }

    return retorno;
}


int cargarDescripcionServicio(char* descripcion,int id,eServicio* servicios, int tamServ)
{

    int todoOk = 0;

    for( int i = 0; i< tamServ; i++){
        if(servicios[i].idServicio == id){
         strncpy(descripcion,servicios[i].descripcion, 20);
         todoOk = 1;
        }
    }

    return todoOk;
}
