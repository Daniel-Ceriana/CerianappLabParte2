#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "validaciones.h"
#include "servicios.h"
#include "trabajo.h"


void mostrarTipo(eTipo* tipos,int tamTipo)
{

    printf("********Tipos de mascotas********\n");

    for(int i = 0; i< tamTipo; i++)
    {
        printf("id: %d.         Descripcion: %s \n",tipos[i].id, tipos[i].descripcion);
    }

}

void mostrarColor(eColor *colores, int tamColor)
{
    printf("********Colores********\n");

    for(int i = 0; i< tamColor; i++)
    {
        printf("id: %d.         Descripcion: %s \n",colores[i].id, colores[i].nombreColor);
    }
}




int altaMascota(eMascota* mascota,int tam, eTipo* tipo,int tamTipo, eColor* color,int tamColor,eCliente* cliente,int tamCli)
{

    int funciona = 0;
    char nombreMascota[20];
    int auxTipo;
    int auxColor;
    int auxEdad;
    int valorValido;
    int indiceValido;
    int indiceCliente;
    char auxNombre[20];
    char auxSexo;

    system("cls");
    printf("******Alta mascota******\n\n");


//verifico que la siguiente mascota a ingresar no sobrepase los limites del sistema

    indiceValido = buscarSiguiente(mascota,tam);
    indiceCliente = buscarSiguienteCliente(cliente,tamCli);

    printf("El id de la mascota sera: %d\n\n",indiceValido);

    if(indiceValido!= -1)
    {


        do
        {
            printf("ingrese el nombre de la mascota: ");
            myGets(nombreMascota,sizeof(nombreMascota));
        }
        while(nombreMascota[0]== '\0');

        mostrarTipo(tipo,tamTipo);
        do
        {
            valorValido = utn_getNumero(&auxTipo,"Ingrese el tipo de mascota: ","\nError. El valor ingresado no es valido\n",tipo[0].id,tipo[tamTipo-1].id,5);
        }
        while(valorValido < 0);

        mostrarColor(color,tamColor);
        do
        {
            valorValido = utn_getNumero(&auxColor,"Ingrese el color de mascota: ","\nError. El valor ingresado no es valido\n",color[0].id,color[tamColor-1].id,5);
        }
        while(valorValido < 0);

        do
        {
            valorValido = utn_getNumero(&auxEdad,"Ingrese el edad de mascota: ","\nError. El valor ingresado no es valido\n",0,125,5);
        }
        while(valorValido < 0);

        do
        {
            printf("ingrese el nombre del cliente: ");
            myGets(auxNombre,sizeof(auxNombre));
        }
        while(auxNombre[0]== '\0');
        do
        {
            myGets(&auxSexo,sizeof(auxSexo));
        }
        while(auxSexo!='f'&&auxSexo!='F'&&auxSexo!='m'&&auxSexo!='M');

        strcpy(mascota[indiceValido].nombreMascota, nombreMascota);
        mascota[indiceValido].id = indiceValido;
        mascota[indiceValido].idTipo = auxTipo;
        mascota[indiceValido].idColor = auxColor;
        mascota[indiceValido].edad = auxEdad;
        mascota[indiceValido].isEmpty = 0;
        mascota[indiceValido].idCliente = indiceCliente;
        cliente[indiceCliente].id =indiceCliente;
        cliente[indiceCliente].isEmpty = 0;
        strcpy(cliente[indiceCliente].nombre,auxNombre);
        cliente[indiceCliente].sexo = auxSexo;
        funciona = 1;
    }
    else
    {
        printf("\nSistema completo. No se pueden cargar mas mascotas\n");
    }


    return funciona;
}


void mostrarMascota(eMascota x,eTipo* tipos, int tamTipos, eColor* colores,int tamColores,eCliente* cliente,int tamCli)
{
    char descripcionTipo[20];
    cargarDescripcionTipo(descripcionTipo,x.idTipo,tipos,tamTipos);
    char descripcionColor[20];
    cargarDescripcionColor(descripcionColor,x.idColor,colores,tamColores);
    char nombreDuenio[20];
    cargarnombreDuenio(nombreDuenio,x.idCliente,cliente,tamCli);
    int indiceCliente;
    indiceCliente = buscarClientePorId(cliente,tamCli,x.idCliente);

    printf("%d %-10s      %-6s      %-8s      %-5d    %-15s  %c\n", x.id, x.nombreMascota, descripcionTipo, descripcionColor, x.edad,cliente[indiceCliente].nombre,cliente[indiceCliente].sexo);


}
int mostrarMascotas(eMascota* mascotas,int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli)
{
    int retorno = -1;
    int flag = 0;
    printf("\n\n**********Mascotas**********\n\n");
    printf("Id  Nombre        Tipo        Color        Edad    Nombre-Cliente   sexo \n\n");

    for(int i = 0; i <tam; i++)
    {
        if(mascotas[i].isEmpty == 0)  // si esta lleno
        {
            flag = 1;
            retorno = 0;
            mostrarMascota(mascotas[i], tipos, tamTipos,colores, tamColores,cliente,tamCli);
        }
    }
    if (flag == 0)
    {
        printf("No hay Mascotas que listar\n\n");
        retorno = -1;
    }

    return retorno;
}




/** \brief marca todos los valores del campo isEmpty a 1
 *
 * \param eMascota* mascotas vector de mascotas
 * \param int tam: tamanio del vector de mascotas
 *
 */

void inicializarMascotas(eMascota* mascotas,int tam)
{

    for (int i = 5; i< tam; i++)
    {
        mascotas[i].isEmpty = 1;

    }
}

int cargarDescripcionTipo(char descripcion[],int id,eTipo* tipos, int tam)
{

    int todoOk = 0;

    for( int i = 0; i< tam; i++)
    {
        if(tipos[i].id == id)
        {
            strncpy(descripcion,tipos[i].descripcion, 20);
            todoOk = 1;
        }
    }

    return todoOk;

}
int cargarDescripcionColor(char descripcion[],int id,eColor* color, int tam)
{

    int todoOk = 0;

    for( int i = 0; i< tam; i++)
    {
        if(color[i].id == id)
        {
            strncpy(descripcion,color[i].nombreColor, 20);
            todoOk = 1;
        }
    }

    return todoOk;

}


int cargarnombreDuenio(char* nombreDuenio,int id,eCliente* cliente, int tam)
{

    int todoOk = 0;

    for( int i = 0; i< tam; i++)
    {
        if(cliente[i].id == id)
        {
            strncpy(nombreDuenio,cliente[i].nombre, 20);
            todoOk = 1;
        }
    }

    return todoOk;
}


void bajaMascotas(eMascota* mascotas, int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente, int tamCli )
{

    system("cls");
    int idBaja;
    char baja;
    int hay;

    printf("*****Baja Mascota*****\n\n");

    hay = mostrarMascotas(mascotas,tam,tipos,tamTipos,colores,tamColores,cliente,tamCli);

    if(hay != -1)
    {
        utn_getNumero(&idBaja,"Ingrese el id de la mascota: ","Error. No se encuentra ese id",0,tam,5);


        if(mascotas[idBaja].isEmpty == 0)
        {

            printf("Confirma la baja?('s' para verificar) \n\n");
            mostrarMascota(mascotas[idBaja],tipos, tamTipos,colores, tamColores,cliente,tamCli);
            fflush(stdin);
            myGets(&baja,1);

            if(baja== 's'||baja == 'S')
            {
                mascotas[idBaja].isEmpty = 1;
                printf("\n\nSe le dio de baja a la mascota\n\n");
            }
            else
            {
                printf("\nSe ha cancelado la operacion\n");
            }

        }
        else
        {
            printf("Esa mascota ya fue dada de baja o no existe\n");
        }
    }
    else
    {
        printf("No hay mascotas en el sistema\n");
    }


}


int buscarSiguiente(eMascota* mascota,int tam)
{

    int retorno = -1;

    if(mascota !=NULL && tam > 0)
    {

        for(int i = 0; i<tam; i++)
        {
            if(mascota[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }



    return retorno;
}
int buscarSiguienteCliente(eCliente* cliente,int tam)
{

    int retorno = -1;

    if(cliente !=NULL && tam > 0)
    {

        for(int i = 5; i<tam; i++)
        {
            if(cliente[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }



    return retorno;
}




int buscarPorId(eMascota* mascotas,int tam,int idABuscar)
{

    int retorno = -1;

    if(mascotas!=NULL && tam > 0)
    {
        for(int i = 0; i<tam; i++)
        {
            if(mascotas[i].id == idABuscar && mascotas[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }



    return retorno;
}

int buscarClientePorId(eCliente* cliente,int tam,int idABuscar)
{

    int retorno = -1;

    if(cliente!=NULL && tam > 0)
    {
        for(int i = 0; i<tam; i++)
        {
            if(cliente[i].id == idABuscar && cliente[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }



    return retorno;
}


int listarMascotasOrdenadas(eMascota* mascotas, int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente, int tamCli)
{

    int retorno = -1;
    eMascota auxMascotas;


    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j<tam; j++)
        {
            if( mascotas[i].idTipo > mascotas[j].idTipo)
            {
                auxMascotas = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = auxMascotas;
                retorno = 0;
            }
            else if( mascotas[i].idTipo == mascotas[j].idTipo && strncmp(mascotas[i].nombreMascota,mascotas[j].nombreMascota,sizeof(mascotas[i].nombreMascota)> 0 ))
            {
                auxMascotas = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = auxMascotas;
                retorno = 0;
            }
        }
    }







    mostrarMascotas(mascotas,tam,tipos,tamTipos,colores,tamColores,cliente,tamCli);

    return retorno;
}


int modMascota(eMascota* mascota, int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores,eCliente* cliente, int tamCli)
{

    int retorno = -1;
    int idBuscado;
    int indice;
    int opcion;
    int valorValido;
    int auxTipo;
    int auxEdad;
    int noError;
    char confirmar;
    system("cls");
    printf("*********Modificar mascota*********\n");

    noError = mostrarMascotas(mascota,tam,tipos,tamTipos,colores,tamColores,cliente,tamCli);
    if(noError == 0)
    {

        utn_getNumero(&idBuscado,"Ingrese el id de la mascota a modificar: ","\nError. Mascota no encontrada\n",0,tam-1,5);
        indice = buscarPorId(mascota,tam,idBuscado);

        if(indice !=-1)
        {
            if(mascota[indice].isEmpty== 0)
            {
                system("cls");

                printf("\nId  Nombre      Tipo        Color       Edad \n\n");
                mostrarMascota(mascota[indice],tipos,tamTipos,colores,tam,cliente,tamCli);

                printf("\nConfirma mascota a modificar?'S' para afirmar\n");
                fflush(stdin);
                myGets(&confirmar,1);
                if(confirmar != 's'&& confirmar != 'S')
                {
                    printf("\nSe ha cancelado la operacion\n");
                }
                else
                {
                    opcion = menuModMascota();
                    switch(opcion)
                    {
                    case 1:
                        mostrarTipo(tipos,tamTipos);
                        do
                        {
                            valorValido = utn_getNumero(&auxTipo,"Ingrese el tipo de mascota: ","\nError. El valor ingresado no es valido\n",tipos[0].id,tipos[tamTipos-1].id,5);
                        }
                        while(valorValido < 0);

                        mascota[indice].idTipo = auxTipo;

                        retorno = 0;
                        break;
                    case 2:
                        do
                        {
                            valorValido = utn_getNumero(&auxEdad,"Ingrese la edad de la mascota: ","\nError. El valor ingresado no es valido\n",0,125,5);
                        }
                        while(valorValido < 0);

                        mascota[indice].edad = auxEdad;

                        retorno = 0;
                        break;

                    default:
                        printf("\nEl valor ingresado es invalido\n");
                        retorno = -1;
                        break;
                    }
                }
            }
            else
            {
                printf("\nError. La mascota buscada esta dada de baja o nunca existio\n");
                retorno = -1;
            }
        }
        else
        {
            printf("Error. No se ha ingresado un dato valido. Se ha cancelado a operacion\n");
        }
    }
    else
    {
        printf("\nNo puede modificar mascotas porque no hay ninguna en el sistema\n");
    }


    return retorno;
}

int menuModMascota()
{
    int opcion = -1;
    int auxIngreso;
    system("cls");
    printf("*********Modificar mascota*********\n\n");
    printf("1.Modificar tipo\n");
    printf("2.Modificar edad\n");

    do
    {
        auxIngreso = utn_getNumero(&opcion,"Ingrese un numero valido","Error. Se ha ingresado un numero invalido",1,2,5);
    }
    while(auxIngreso == -1);

    return opcion;
}

int mostrarMascotasSegunColor(eMascota* mascota, int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores,eCliente* cliente, int tamCli,int colorBuscado)
{
    int retorno = 0;
    for(int i = 0; i<tamColores; i++)
    {
        if(mascota[i].idColor == colorBuscado && mascota[i].isEmpty == 0)
        {
            mostrarMascota(mascota[i],tipos,tamTipos,colores,tamColores,cliente,tamCli);
            retorno++;
        }

    }

    return retorno;

}

int mostrarMascotasSegunTipo(eMascota* mascota,int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores, eCliente* cliente, int tamCli, int tipoBuscado)
{

    int retorno =0;
    for(int i = 0; i<tamTipos; i++)
    {
        if(mascota[i].idTipo == tipoBuscado && mascota[i].isEmpty == 0)
        {
            mostrarMascota(mascota[i],tipos,tamTipos,colores,tamColores,cliente,tamCli);
            retorno++;
        }

    }
    return retorno;
}
int buscarMenorEdad(eMascota* mascota,int tam)
{
    int anterior = 126;
    int retorno = -1;
    for(int i = 0 ; i<tam; i++)
    {
        if(mascota[i].edad < anterior && mascota[i].isEmpty ==0 )
        {
            anterior = mascota[i].edad;
            retorno = mascota[i].edad;
        }
    }

    return retorno;
}

void mostrarMascotasSegunEdad(eMascota* mascota,int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores, eCliente* cliente, int tamCli, int edadBuscada)
{
    for(int i = 0; i<tam; i++)
    {
        if(mascota[i].edad == edadBuscada && mascota[i].isEmpty == 0)
        {
            mostrarMascota(mascota[i],tipos,tamTipos,colores,tamColores,cliente,tamCli);
        }

    }
}



int contarMascotasDeMismoColorYTipo(eMascota* mascota,int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores, eCliente* cliente, int tamCli, int tipoBuscado, int colorBuscado)
{
    int contador=0;
    int retorno = -1;
    for(int i = 0; i< tam; i++)
    {
        if(mascota[i].idTipo == tipoBuscado && mascota[i].idColor == colorBuscado && mascota[i].isEmpty == 0)
        {
            contador++;
            retorno = contador;
        }

    }


return retorno;
}
