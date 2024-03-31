/*
 * @JMTS
 * Probado con ESP32 DEVKIT y WEMOS D1 R32 (palaca con forma de arduino 1 para que funcione hay que realizar las modificaciones descritas en la libreria TFT_eSPI)
 * Reloj con fecha y hora más sensor de temperatura y humedad en pantalla TFT con la libreria TFT_eSPI
 * Sensor de Temperatura-Humedad DHT22 o DHT11 solo has de configurarlo en su script
 * Hora a traves de servidor NTP basado en el ejemplo SimpleTime de la libreria del ESP32
 * Conexión a base de datos Mysql mediante php con el método POST para realizar un registro
 * Actualización del frimware via OTA con contraseña basado en el ejemplo ArduinoOTA
 * 27/12/2024
 */
#include "configuracion.h"
#include "sensorDHT.h"
#include "conexionWiFi.h"
#include "enviar_UDP.h"
#include "baseDatos.h"
#include "ota.h"
//#include "dormir.h"

#define LED_PIN 2 // Led integrado en el PIN2

// Iniciamos los contadores para insertar en la base de datos y actualizar el reloj
unsigned long previosMillis;
unsigned long intervalo = 60000;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Ponemos el LED de la placa en OFF
  
  // Iniciamos el sensor DHT
  dht.begin(); 

  // Conexion a la wifi
  conectarWiFi();

  // Configuramos la actualización via OTA
  actualizacionOTA();
}

void loop()
{
  //Si se ha perdido la conexión wifi llamamos a la función para conectar de nuevo
  if (WiFi.isConnected() == false){
    conectarWiFi();
    }

  // Llamamos a la actualización via OTA
  ArduinoOTA.handle(); 

  // entrar en modo sueño
  unsigned long currentMillis = millis();
  if ((unsigned long) (currentMillis - previosMillis) >= intervalo){
    // actualizar base de datos
    enviarBD(); // Comentaló si no quieres utilizarlo
    //dormir();
    previosMillis = millis();
  }
  // enviamos los datos por UDP
  envioDatos();
}
