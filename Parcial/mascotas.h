#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED


typedef struct{

int id;
char nombre[20];
char sexo;
int isEmpty;



}eCliente;




typedef struct{

int id;
char descripcion[20];

}eTipo;

typedef struct{

int id;
char nombreColor[20];

}eColor;


typedef struct{
int id;
int isEmpty;
char nombreMascota[20];
int idTipo;
int idColor;
int edad;
int idCliente;

}eMascota;



#endif // MASCOTAS_H_INCLUDED
/** \brief Muestra los tipos de mascota en un listado
 *
 * \param eTipo * tipos: array de tipos de mascota
 * \param int tamTipo: tamanio del array de tipo de mascota
 *
 */

void mostrarTipo(eTipo* tipos,int tamTipo);


/** \brief Muestra los colores de mascota en un listado
 *
 * \param eColor* colore: array de colores
 * \param int tamColor: Tamanio del array de colores
 * \return retorna 0 si salio todo bien o -1 si hubo error
 *
 */

void mostrarColor(eColor* colores, int tamColor);


/** \brief da de alta a la mascota pidiendo completar una serie de daots
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param int idSiguiente: id necesario para asignarle a la siguiente mascota
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* color : array de colores
 * \param int tamColor: tamanio del array de colores
  * \param eCliente cliente : vector de clientes
 * \param int tamCli: tamanio del vector de clientes
 * \return
 *
 */

int altaMascota(eMascota* mascota,int tam, eTipo* tipo,int tamTipo,eColor* color, int tamColor,eCliente* cliente,int tamCli);


/** \brief  muestra las mascotas del vector de mascotas
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* color : array de colores
 * \param int tamColor: tamanio del array de colores
 * \return
 *
 */


int mostrarMascotas(eMascota* mascotas,int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli);


/** \brief muestra una mascota del dato recibido
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* colores : array de colores
 * \param int tamColores: tamanio del array de colores
 *
 */

void mostrarMascota(eMascota x,eTipo* tipos, int tamTipos, eColor* colores,int tamColores,eCliente* cliente,int tamCli);

/** \brief modifica la mascota elegida por el id
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* color : array de colores
 * \param int tamColor: tamanio del array de colores
 * \return retorna 0 si esta todo bien o -1 si hubo error
 *
 */
int modMascota(eMascota* mascota, int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores,eCliente* cliente, int tamCli);


/** \brief inicializa el vector de mascotas
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 *
 */

void inicializarMascotas(eMascota* mascotas,int tam);

/** \brief
 *
 * \param char descripcion. descripcion de tipo
 * \param int id
 * \param eTipo* tipos : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \return retorna 0 si esta todo bien o -1 si hubo error
 *
 */

int cargarDescripcionTipo(char descripcion[],int id,eTipo* tipos, int tam);
/** \brief
 *
 * \param char descripcion. descripcion de tipo
 * \param int id
 * \param eTipo* tipos : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \return retorna 0 si esta todo bien o -1 si hubo error
 *
 */


int cargarDescripcionColor(char descripcion[],int id,eColor* color, int tam);

/** \brief
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* color : array de colores
 * \param int tamColor: tamanio del array de colores
 * \return retorna 0 si esta todo bien o -1 si hubo error
 *
 */

void bajaMascotas(eMascota* mascotas, int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente, int tamCli );


int cargarnombreDuenio(char* nombreDuenio,int id,eCliente* cliente, int tam);
int buscarClientePorId(eCliente* cliente,int tam,int idABuscar);



/** \brief
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \return retorna el indice siguiente vacio o -1 si no encuentra
 *
 */

int buscarSiguiente(eMascota* mascota,int tam);

/** \brief
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param int idABuscar : id a buscar
 * \return retorna el indice del id buscado o -1 si no encuentra
 *
 */

int buscarPorId(eMascota* mascotas,int tam,int idABuscar);


/** \brief
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* color : array de colores
 * \param int tamColor: tamanio del array de colores
 * \return retorna 0 si esta todo bien o -1 si hubo error
 *
 */

int listarMascotasOrdenadas(eMascota* mascotas, int tam, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente, int tamCli);

/** \brief despliega un menu de opciones y pide un retorno del usuario
 *
 * \return retorna la opcion elegida
 *
 */

int menuModMascota();

/** \brief
 *
 * \param eMascota mascota: Array de mascotas
 * \param int tam: tamanio del array de mascotas
 * \param eTipo* tipo : array de tipo
 * \param int tamTipo: tamanio del array de tipos
 * \param eColor* color : array de colores
 * \param int tamColor: tamanio del array de colores
 * \return retorna 0 si esta todo bien o -1 si hubo error
 *
 */

int modMascota(eMascota* mascota, int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores,eCliente* cliente, int tamCli);

int buscarSiguienteCliente(eCliente* cliente,int tam);

int mostrarMascotasSegunColor(eMascota* mascota, int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores,eCliente* cliente, int tamCli,int colorBuscado);
void mostrarMascotasSegunEdad(eMascota* mascota,int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores, eCliente* cliente, int tamCli, int edadBuscada);
int contarMascotasDeMismoColorYTipo(eMascota* mascota,int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores, eCliente* cliente, int tamCli, int tipoBuscado, int colorBuscado);
int mostrarMascotasSegunTipo(eMascota* mascota,int tam, eTipo* tipos, int tamTipos,eColor* colores, int tamColores, eCliente* cliente, int tamCli, int tipoBuscado);
int buscarMenorEdad(eMascota* mascota,int tam);
