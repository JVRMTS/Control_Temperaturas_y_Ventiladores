/*
 * Configuración y función para la toma de datos de un sensor DHT, esta probado con DHT11 y DHT22 en Esp32 Dev Module y Wemos D1 R32
 * @JMTS - www.jmts.es
 * EL 27/12/2023
 */

#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN 22     // Se define el PIN al que conectamos el Sensor DHT: pin digital 22 - scl en wemos d1 r32

DHT dht(DHTPIN, DHTTYPE); // Creamos el objeto DHT

double hu;
double te;
double hic;
String t;
String h;
String s;

void temperatura(){
  te = dht.readTemperature();                // Leemos la temperatura del sensor
  t = String(te, 2);                         // La convertimos a un String  
  hu = dht.readHumidity();                   //Leemos la humedad del sensor
  h = String(hu, 1);                         // La convertimos a un String
  hic = dht.computeHeatIndex(te, hu, false); // Calculamos la sensación térmica
  s = String(hic, 2);                        // La convertimos a un String
} 
