/* Fichero de configuración para el reloj con envío de datos por POST y actualización via OTA
 * Creado el 27/12/2023
 * por @JMTS
 */

// Configuración de la Ubicación, la IP y da nombre al puerto de actualizacion via OTA
byte ub = 5;                        // Ubicación (1-despacho) (2-salon) (3-dormitorio) (4-resumen) (5-pruebas)
int finIP = 20+ub;                  // Se hace así para que no haya problemas con la base de datos
IPAddress ip(192,168,1,finIP);      // Se configura la dirección IP en base a la ubicación
IPAddress gateway(192,168,1,1);     // Puerta de enlace
IPAddress subnet(255,255,255,0);    // Mascara de red
IPAddress primaryDNS(8, 8, 8, 8);   // DNS primario de Google 
IPAddress secondaryDNS(8, 8, 4, 4); // DNS secundario de Google

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
const char *ssid = "****";              // Pon el nombre de tu WiFi
const char *password = "****";          // Pon la contraseña de tu WiFi

//Password para la actualización via OTA
char *passwordOTA = "****";

//Configuración del Servidor Web
String dominio = "tu_dominio.com";                              // Pon el dominio que vayas a utilizar
String url = "http://" + dominio + "/config/insertar_post.php"; // Dirección web del servidor con el dominio insertado