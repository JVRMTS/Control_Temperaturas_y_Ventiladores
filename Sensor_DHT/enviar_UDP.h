/*
 * Archivo para enviar paquetes por el puerto UDP
 * JMTS
 * 10 de enero de 2024
 */

#include "AsyncUDP.h"

AsyncUDP udp;

IPAddress enviarA(192,168,1,24);
int puerto = 9999;

//Datos que vamos a enviar
String datos;

void envioDatos(){
  datos = t + '&' + h + '&' + s + '&' + ub;
  if(udp.connect(IPAddress(enviarA), puerto)) {
    udp.print(datos);
  }
}
