/*
 * @JMTS - www.jmts.es
 * Probado con ESP32 devmodule y WEMOS D1 R32 (palaca con forma de arduino 1 para que funcione hay que realizar las modificaciones descritas en la libreria TFT_eSPI)
 * Reloj con fecha y hora más sensor de temperatura y humedad en pantalla TFT con la libreria TFT_eSPI
 * Sensor de Temperatura-Humedad DHT22 o DHT11 solo has de configurarlo en su script
 * Hora a traves de servidor NTP basado en el ejemplo SimpleTime de la libreria del ESP32
 * Conexión a base de datos Mysql mediante php con el método POST para realizar un registro
 * Actualización del frimware via OTA con contraseña basado en el ejemplo ArduinoOTA
 * 27/12/2023
 */

#include "configuracion.h"
#include "sensorDHT.h"
#include "conexionWiFi.h"
#include "enviar_UDP.h"
#include "reloj.h"
#include "tft.h"
#include "baseDatos.h"
#include "ota.h"

#define LED_PIN 2 // Led integrado en el PIN2

// Iniciamos los contadores para insertar en la base de datos y actualizar el reloj
unsigned long previosMillis;
unsigned long intervalo = 60000;

void setup(){ // Iniciamos el puerto serial y la función SPI
  Serial.begin(115200);

  // Ponemos el led integrado en OFF
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Turn onboard LED OFF

  // Iniciamos el sensor DHT
  dht.begin();

  // Llamamos a la función para configurar la pantalla
  configuracionPantalla();

  // Conexion a la wifi y sincronización del reloj NTP
  conectarWiFi();

  // Configuranción del reloj
  configReloj();
  
  // Configuramos la actualización via OTA
  actualizacionOTA();
}

void loop(){
  fecha();
  temperatura();
  //Si se ha perdido la conexión wifi llamamos a la función para conectar de nuevo y configuramos fecha y hora
  if (WiFi.isConnected() == false){
    conectarWiFi();
    }
  unsigned long currentMillis = millis();   
  // Llamamos, cada minuto, a la función para insertar los datos en la base de datos
  if ((unsigned long) (currentMillis - previosMillis) >= intervalo){
      enviarBD();
      previosMillis = millis();
    }
  // Llamamos a la fundción para enviar los datos por UDP
  envioDatos();
  // Llamamos a la función para que se muestre la pantalla
  mostrarPantalla();
  // Llamamos a la actualización via OTA
  ArduinoOTA.handle();
}