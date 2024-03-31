/*
 * Archivo para recibir paquetes por el puerto UDP
 * basado en el ejemplo de AsyncUDP server
 * @JMTS - www.jmts.es
 * 10 de enero de 2024
 */

#include "AsyncUDP.h"

// Creamos el objeto UDP
AsyncUDP udp;

// Definimos el separador de la cadena
#define separador '&'

// Configuramos el puerto a utilizar
unsigned int Port = 9999;

// Definimos la cadena de datos
String StrTramaUdp;

// Definimos las ip's que nos envían datos
IPAddress ip1(192,168,1,21);  // Despacho
IPAddress ip2(192,168,1,22);  // Salón
IPAddress ip3(192,168,1,23);  // Dormitorio

// Definimos la variable para comparar las ip's
IPAddress remoto;

// Definimos las variables que mostraremos en pantalla
String t1;
String h1;
String s1;

// Definimos la función para recibir y extraer los datos que llegan por UDP
String getValue(String data, char separator, int index);
void recibirDatos();

// Iniciamos el puerto UDP
void configurarUdp(){
  udp.listen(9999);
}

// Se ejecutara la función recibirDatos() si la opción es menor que 4
void datos(){
  if(mostrar < 4){
    recibirDatos();
    }
}

// Recibimos los datos por UDP y generamos las variables a mostrar.
void recibirDatos(){
  if(udp.listen(9999)) {
    udp.onPacket([](AsyncUDPPacket packet) {
      char* tmpStr = (char*) malloc(packet.length() + 1);
      memcpy(tmpStr, packet.data(), packet.length());
      tmpStr[packet.length()] = '\0'; // ensure null termination
      StrTramaUdp = String(tmpStr);
      free(tmpStr); // Strign(char*) crea una copia para que podamos eliminar la nuestra
      remoto = IPAddress(packet.remoteIP());

      if (remoto == ip1){
        String temp1 = getValue(StrTramaUdp, '&', 0);
        String hum1 = getValue(StrTramaUdp, '&', 1);
        String sen1 = getValue(StrTramaUdp, '&', 2);
        if (mostrar == 1){
          t1 = temp1;
          h1 = hum1;
          s1 = sen1;
        }
      }
      else if (remoto == ip2){
        String temp2 = getValue(StrTramaUdp, '&', 0);
        String hum2 = getValue(StrTramaUdp, '&', 1);
        String sen2 = getValue(StrTramaUdp, '&', 2);
        if (mostrar == 2) {
          t1 = temp2;
          h1 = hum2;
          s1 = sen2;
        }
      }
      else if (remoto == ip3){
        String temp3 = getValue(StrTramaUdp, '&', 0);
        String hum3 = getValue(StrTramaUdp, '&', 1);
        String sen3 = getValue(StrTramaUdp, '&', 2);
        if (mostrar == 3) {
          t1 = temp3;
          h1 = hum3;
          s1 = sen3;
        }
      }
    });
  }
}

// Recorremos la cadena UDP para extraer los datos
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
