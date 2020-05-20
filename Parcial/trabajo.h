#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{

    int dia;
    int mes;
    int anio;


} eFecha;
typedef struct
{

    int id;
    int idMascota;
    int idServicio;
    int isEmpty;
    eFecha fecha;


} eTrabajo;

#endif // TRABAJO_H_INCLUDED


/** \brief da de alta un trabajo
 *
 * \param eTrabajo* trabajos
 * \param int tamTrab
 * \param eMascota* mascotas
 * \param int tamMasc
 * \param eTipo* tipos
 * \param int tamTipos
 * \param eColor* colores
 * \param int tamColores
 * \param eServicio* servicios
 * \param int tamServ
 * \return retorna 0 si todo salio correctamente o -1 si hubo algun error
 *
 */
int altaTrabajo(eTrabajo* trabajos, int tamTrab, eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eServicio* servicios, int tamServ,eCliente* cliente,int tamCli);


/** \brief busca el indice en el array de trabajos que este sin usar
 *
 * \param eTrabajo* trabajos estructura trabajos
 * \param int tramTrab tamanio de la estructura trabajos
 * \return retorna el primer indice encontrado que este vacio o -1 si no hay disponibles
 *
 */
int buscarSiguienteTrabajo(eTrabajo* Trabajos,int tamTrab);

/** \brief imprime en pantalla un trabajo
 *
 * \param eTrabajo* trabajos
 * \param int tamTrab
 * \param eMascota* mascotas
 * \param int tamMasc
 * \param eTipo* tipos
 * \param int tamTipos
 * \param eColor* colores
 * \param int tamColores
 * \param eServicio* servicios
 * \param int tamServ
 *
 */


void listarTrabajo(eTrabajo trabajo,int tamTrab,eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores, eServicio* servicios, int tamServ);


/** \brief imprime en pantalla todos los trabajos encontrados
 *
 * \param eTrabajo* trabajos
 * \param int tamTrab
 * \param eMascota* mascotas
 * \param int tamMasc
 * \param eTipo* tipos
 * \param int tamTipos
 * \param eColor* colores
 * \param int tamColores
 * \param eServicio* servicios
 * \param int tamServ
 * \return 0 si todo salio bien o -1 si hubo error
 *
 */

int listarTrabajos(eTrabajo* trabajos,int tamTrab,eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores, eServicio* servicios, int tamServ);

/** \brief marca todos los valores del campo isEmpty a 1
 *
 * \param eMascota* mascotas vector de mascotas
 * \param int tam: tamanio del vector de mascotas
 *
 */
void inicializarTrabajos(eTrabajo* trabajos,int tamTrab);
