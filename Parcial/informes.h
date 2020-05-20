#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


#endif // INFORMES_H_INCLUDED

void informes(eTrabajo* trabajos, int tamTrab, eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eServicio* servicios, int tamServ,eCliente* cliente,int tamCli);
void informarSegunColor(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli);
void informarSegunTipo(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli);
int menuInformes();
void informarMenorEdad(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli);
void informarMascotasPorTipo(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli);
void informarCantidadColorYTipo(eMascota* mascotas, int tamMasc, eTipo* tipos, int tamTipos, eColor* colores, int tamColores,eCliente* cliente,int tamCli);
void informarColoresComunes(eMascota* mascotas, int tamMasc, eColor* colores, int tamColores);
