#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "validaciones.h"
#include "servicios.h"
#include "trabajo.h"
#include "informes.h"



void informes(eTrabajo* trabajos, int tamTrab, eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eServicio* servicios, int tamServ,eCliente* cliente,int tamCli)
{

    int opcion;
    int noError;

    noError = listarTrabajos(trabajos,tamTrab,mascotas,tamMasc,tipos,tamTipos,colores,tamColores,servicios,tamServ);
    if(noError == 0){

        opcion = menuInformes();

        switch(opcion)
        {
            case 1:
                informarSegunColor(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli);
                break;
            case 2:
                informarSegunTipo(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli);
                break;
            case 3:
                informarMenorEdad(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli);
                break;
            case 4:
                informarMascotasPorTipo(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli);
                break;
            case 5:
                informarCantidadColorYTipo(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli);
                break;
            case 6:
                informarColoresComunes(mascotas,tamMasc,colores,tamColores);
                break;
            case 7:
                break;
            default:
                break;
        }


}


}



int menuInformes(){


    system("cls");
    int opcion = -1;
    printf("1.Mostrar mascotas segun color\n");
    printf("2.Mostrar mascotas segun tipo \n");
    printf("3.Informar mascotas menores mascotas \n");
    printf("4.Mascotas separadas por tipo \n");
    printf("5.Contar mascotas segun color y tipo \n");
    printf("6.Color o colores mas comunes \n");
    printf("7.Salir\n");

    utn_getNumero(&opcion,"Ingrese un numero valido","Error.Numero ingresado no es valido\n",1,7,5);




return opcion;
}



void informarSegunColor(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli)
{

    system("cls");
    int valorValido;
    int auxColor;
    mostrarColor(colores,tamColores);
    do
    {
        valorValido = utn_getNumero(&auxColor,"Ingrese el color de mascota: ","\nError. El valor ingresado no es valido\n",colores[0].id,colores[tamColores-1].id,5);
    }
    while(valorValido < 0);

   mostrarMascotasSegunColor(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli,auxColor);

}

void informarSegunTipo(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli)
{

    system("cls");
    int valorValido;
    int auxTipo;
    mostrarTipo(tipos,tamTipos);
    do
    {
        valorValido = utn_getNumero(&auxTipo,"Ingrese el tipo de mascota: ","\nError. El valor ingresado no es valido\n",tipos[0].id,tipos[tamTipos-1].id,5);
    }
    while(valorValido < 0);

    mostrarMascotasSegunTipo(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli,auxTipo);

}

void informarMenorEdad(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli)
{
    system("cls");
    int auxEdad;
    printf("********************Informar menores mascotas********************\n");
    printf("Id  Nombre        Tipo        Color        Edad    Nombre-Cliente   sexo \n\n");

    auxEdad = buscarMenorEdad(mascotas,tamMasc);
    if(auxEdad != -1)
    {
        mostrarMascotasSegunEdad(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli,auxEdad);
    }
    system("pause");

}



void informarMascotasPorTipo(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli)
{
    system("cls");

    printf("***********************Mostrar mascotas por tipo*********************** \n\n");

    int flag = 0 ;

    for(int i = 0; i<tamTipos; i++){
        printf("--------------------------------\n");
        printf("Tipo: %s\n", tipos[i].descripcion);
        for( int j =0; j< tamMasc; j++ ){
            if(mascotas[j].isEmpty == 0 && mascotas[j].idTipo == tipos[i].id){
                mostrarMascota(mascotas[j],tipos,tamTipos,colores,tamColores,cliente,tamCli);
                flag = 1;
            }

        }
    }
    if(flag == 0){
        printf("\n\nNo se encontraron mascotas\n\n");
    }

}

void informarCantidadColorYTipo(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli)
{
    system("cls");
    int valorValido;
    int auxTipo;
    int auxColor;
    int cantidad;
    printf("*******************Cantidad de mascotas segun color y tipo*******************\n\n");

    mostrarColor(colores,tamColores);
    do
    {
        valorValido = utn_getNumero(&auxColor,"Ingrese el color de mascota: ","\nError. El valor ingresado no es valido\n",colores[0].id,colores[tamColores-1].id,5);
    }
    while(valorValido < 0);


    mostrarTipo(tipos,tamTipos);
    do
    {
        valorValido = utn_getNumero(&auxTipo,"Ingrese el tipo de mascota: ","\nError. El valor ingresado no es valido\n",tipos[0].id,tipos[tamTipos-1].id,5);
    }
    while(valorValido < 0);


    cantidad = contarMascotasDeMismoColorYTipo(mascotas,tamMasc,tipos,tamTipos,colores,tamColores,cliente,tamCli,auxTipo,auxColor);

    printf("Hay %d mascotas de ese color y tipo\n\n",cantidad);

}

void informarColoresComunes(eMascota* mascotas, int tamMasc, eColor* colores, int tamColores)
{

    int cantidad[tamColores];
    int indice;
    for(int i = 0; i< tamColores; i++){
        cantidad[i] = 0;
    }

    for(int i = 0; i<tamColores; i++){

        for( int j =0; j< tamMasc; j++ ){
            if(mascotas[j].isEmpty == 0 && mascotas[j].idColor == colores[i].id){
                cantidad[i]++;
            }

        }
    }




        for(int i = 0; i<tamColores; i++){

            for( int j =0; j< tamMasc; j++ ){
                if(cantidad[i]>cantidad[j])
                {
                    indice = i;
                }

            }
        }


    char descripcionColor[20];
    cargarDescripcionColor(descripcionColor,indice,colores,tamColores);

    printf("Hay %d mascotas de color %s",cantidad[indice], descripcionColor);

}


