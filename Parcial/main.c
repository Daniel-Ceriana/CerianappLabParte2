#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "validaciones.h"
#include "servicios.h"
#include "trabajo.h"
#include "informes.h"

#define TAM 5
#define TAMCLIENTES 5
#define TAMTRABAJOS 5



int menu();

int main()
{

    int tamTipos = 5;
    int tamColores = 5;
    int tamServicios = 3;



    //eTrabajo trabajos[TAMTRABAJOS];
        //Hardcode tipos de mascota
    eTipo tipos[] = { {1000,"Ave"}, {1001, "Perro"}, {1002, "Gato"}, { 1003,"Roedor"}, {1004, "Pez"} };

//Hardcode colores
    eColor colores[] = {{5000,"Negro"}, {5001,"Blanco"},{5002, "Gris"},{5003, "Rojo"}, {5004,"Azul"}};

//Hardcode servicios
    eServicio servicios[] = {{20000,"Corte", 250}, {20001,"Desparasitado", 300}, {20002,"Castrado",400}};
//Hardcode clientes
    eCliente clientes[]={{0,"Daniel",'m',0},{1,"Ignacio",'m',0},{2,"Ana",'f',0},{3,"Laura",'f',0},{4,"Facundo",'m',0}          };


//hardcode mascotas
    eMascota mascota[] = {{0,0,"Pepe",1001,5000,15,1},
        {1,0,"Luna",1001,5000,10,0},
        {2,0,"Jorgito",1002,5001,13,3},
        {3,0,"Lulu",1004,5002,32,2},
        {4,0,"Pollito",1000,5003,2,0}};


        /*

           int id;
    int idMascota;
    int idServicio;
    int isEmpty;
    eFecha fecha;
        */

    eTrabajo trabajos[] = { {0,0,20000,0,{13,2,2000}}, {1,2,20001,0,{14,8,2001}},{2,3,20001,0,{16,6,2003}},{3,1,20002,0,{13,8,2001}},{4,0,20000,0,{19,10,2001}}               };


    inicializarMascotas(mascota, TAM);
    inicializarTrabajos(trabajos,TAMTRABAJOS);



    int opcion;
    int continuar = 1;


    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            if(!altaMascota(mascota,TAM,tipos,tamTipos,colores,tamColores,clientes,TAMCLIENTES))
            {
                printf("\nHa ocurrido un error al intentar cargar la mascota\n");
            }
            break;
        case 2:
            modMascota(mascota,TAM,tipos,tamTipos,colores,tamColores,clientes,TAMCLIENTES);
            break;
        case 3:
            bajaMascotas(mascota,TAM,tipos,tamTipos,colores,tamColores,clientes,TAMCLIENTES);

            break;
        case 4:
            listarMascotasOrdenadas(mascota,TAM,tipos,tamTipos,colores,tamColores,clientes,TAMCLIENTES);
            //mostrarMascotas(mascota,);
            break;
        case 5:
            mostrarTipo(tipos, tamTipos);
            break;
        case 6:
            mostrarColor(colores,tamColores);
            break;
        case 7:
            listarServicios(servicios,tamServicios);
            break;
        case 8:
            altaTrabajo(trabajos,TAMTRABAJOS,mascota,TAM,tipos,tamTipos,colores,tamColores,servicios,tamServicios,clientes,TAMCLIENTES);
            break;
        case 9:
            listarTrabajos(trabajos,TAMTRABAJOS,mascota,TAM,tipos,tamTipos,colores,tamColores,servicios,tamServicios);
            break;
        case 10:
            informes(trabajos,TAMTRABAJOS,mascota,TAM,tipos,tamTipos,colores,tamColores,servicios,tamServicios,clientes,TAMCLIENTES);
            break;
        case 11:
            continuar = 0;
            break;
        default:
            printf("\nHa ocurrido un error, vuelva a intentarlo\n");
            break;
        }
        system("pause");


    }
    while(continuar);

    return 0;
}

int menu()
{
    system("cls");
    int opcion = -1;
    printf("1.Alta mascota \n");
    printf("2.Modificar mascota \n");
    printf("3.Baja mascota \n");
    printf("4.Listar mascotas \n");
    printf("5.Listar tipos \n");
    printf("6.Listar colores \n");
    printf("7.Listar servicios \n");
    printf("8.Alta trabajo \n");
    printf("9.Listar trabajos \n");
    printf("10.Informes \n");
    printf("11.Salir \n");

    utn_getNumero(&opcion,"Ingrese un numero del 1 al 10: ","Error. Vuelva a intentarlo\n",1,10,5);

    return opcion;
}
