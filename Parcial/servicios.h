#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{

    int idServicio;
    char descripcion[25];
    float precio;


}eServicio;

#endif // SERVICIOS_H_INCLUDED
/** \brief lista los servicios
 *
 * \param eServicio* servicios : puntero al vector de servicios
 * \param int tamServicios : tamanio del vector de servicios
 * \return retorna 0 si salio todo bien o -1 si hubo error
 *
 */

int listarServicios(eServicio* servicios,int tamServicios);

/** \brief lista un servicio determinado
 *
 * \param eServicio servicio
 * \param int tamServ : tamanio del vector de servicios
 *
 */

void listarServicio(eServicio servicio,int tamServ);

/** \brief asigna a un vector de caracteres la descripcion de un servicio
 *
 * \param char* descripcion: puntero a un vector de caracteres
 * \param int id : id del servicio
 * \return int tamServ : tamanio del vector de servicios
 *
 */

int cargarDescripcionServicio(char* descripcion,int id,eServicio* servicios, int tamServ);
