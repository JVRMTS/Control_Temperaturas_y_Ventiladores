/* 
 * Fichero de configuración para el reloj con envío de datos por POST y actualización via OTA
 * Creado el 27/12/2021
 * @JMTS - www.jmts.es
 */

// Configuración de la Ubicación, la IP y da nombre al puerto de actualizacion via OTA
byte ub = 1;                        // Ubicación (1-despacho) (2-salon) (3-dormitorio) (4-resumen) (5-pruebas)
int finIP = 20+ub;                  // Se hace así para que no haya problemas con la base de datos y no tener que modificarla
IPAddress ip(192,168,1,finIP);      // Se configura la dirección IP en base a la ubicación
IPAddress gateway(192,168,1,1);     // Puerta de enlace
IPAddress subnet(255,255,255,0);    // Mascara de red
IPAddress primaryDNS(8, 8, 8, 8);   // DNS primario de Google necesario para el envío de registros a la base de datos
IPAddress secondaryDNS(8, 8, 4, 4); // DNS secundario de Google necesario para el envío de registros a la base de datos

// Configuración de la Ubicación
// tambien da nombre al puerto de actualizacion via OTA
char* ubicacion(){
  char *ubic;
  switch (ub) {
    case 1:
      ubic = "DESPACHO";
    break;
    case 2:
      ubic = "SALON";
    break;
    case 3:
      ubic = "DORMITORIO";
    break;
    case 4:
      ubic = "CENTRAL";
    break;
    case 5:
      ubic = "PRUEBAS";
    break;
  }
  return ubic;
}

//Configuración de la WiFi
const char *ssid = "****";
const char *password = "****";

//Password para la actualización via OTA
char *passwordOTA = "****";

//Configuración del Servidor Web
String dominio = "tu_dominio.com";
String url = "http://" + dominio + "/config/inse_post.php"; //Dirección web del servidor
