/*
 * La función de este archivo es mostrar en la pantalla TFT los datos que queremos ver.
 * Probado con las pantallas 3.5" TFT SHIELD ARDUINO MEGA (ILI9486/9488) EN UN WEMOS D1 R32 Y TFT 3.5" ILI9486/9488 SPI EN UN ESP32 DEV MODULE
 * @JMTS - www.jmts.es
 * 10/02/24
 */

#include <TFT_eSPI.h>     // incluye la libreria para el manejo de la TFT
#include <SPI.h>		      // incluye libreria bus SPI
#include "Free_Fonts.h"   // Incluye el archivo de encabezado adjunto a este sketch.
#include "imagenes.h"
 
TFT_eSPI tft = TFT_eSPI();	// Crea el objeto tft

TFT_eSprite img = TFT_eSprite(&tft);         // Declarar objeto Sprite "spr" con puntero al objeto "tft"

// con esta función dibujamos lo que no queremos que no se refresque en la pantalla y la orientación de esta, la ejecutamos desde la funcion configuracionPantalla().
void zonaFijaPantalla(){
  int xpos = tft.width() / 2;                // Centro del ancho de pantalla
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);                 // Establece el fondo de pantalla.
  tft.drawLine(0, 0, 480, 0, TFT_WHITE);     // linea horizontal de color blanca
  tft.drawLine(0, 135, 480, 135, TFT_WHITE); // linea horizontal de color blanca
  tft.drawLine(0, 253, 480, 253, TFT_WHITE); // linea horizontal de color blanca
  tft.drawLine(0, 319, 480, 319, TFT_WHITE); // linea horizontal de color blanca
  tft.setTextDatum(TC_DATUM);
  tft.pushImage(xpos -77, 265, xw, xh, xxx);
}

// Esta funcion se ejecuta en el Setup para configurar la pantalla y mostrar los datos o dibujos que mo se refrescan mediante la función zonaFijaPantalla().
void configuracionPantalla(){
  tft.begin();				// Inicializa pantalla.
  tft.setRotation(3);	// establece posicion 0 - vertical pines pantalla abajo, 1-horizontal pines pantalla derecha, 2-vertical pines pantalla arriba, 3-horizontal pines pantalla izquierda.
  zonaFijaPantalla(); // Llamamos a la función para mostrar los datos e imágenes que no se refrescan y permanecen fijos en pantalla.
}
// Declaramos las funciones para mostrar los Sprites
void drawReloj(int x, int y);
void drawTemperatura(int x, int y);

void mostrarPantalla(){
  int xpos = tft.width() / 2;                                                        // Centro del ancho de pantalla
  tft.setTextDatum(TC_DATUM);
  drawReloj(xpos - 215,6);
  drawTemperatura(xpos - 240,145);
}

// Tamaño del Sprite fecha hora
#define RWIDTH  430
#define RHEIGHT 105

// Sprite para mostrar la fecha y hora
void drawReloj(int x, int y){
  img.createSprite(RWIDTH, RHEIGHT);
  img.setTextDatum(TC_DATUM);
  int xpo = (RWIDTH / 2);                                                            // Centro del ancho del Srite
  img.setTextColor(TFT_WHITE, TFT_BLACK, true);                                      // Establece el color de texto y del fondo para el texto  
  img.setFreeFont(FSSB24);                                                           // Seleccionamos la fuente
  img.fillSprite(TFT_BLACK);
  img.drawString(horMin,xpo,13);                                                     // Imprimimos por pantalla la hora y los minutos.
  img.drawString(diaS + " " + dia + " " + mes + " " + ano,xpo,61);                   // Imprimimos por pantalla la fecha
  img.pushSprite(x, y, TFT_TRANSPARENT);
  img.deleteSprite();
}

// Tamaño del Sprite temperaturas
#define TWIDTH  480
#define THEIGHT 100

void drawTemperatura(int x, int y){
  img.createSprite(TWIDTH, THEIGHT);
  int xpo = (TWIDTH / 2);                                                            // Centro del ancho del Srite
  img.setSwapBytes(true);
  img.setTextDatum(TC_DATUM);
  img.setFreeFont(FSSB18);                                                           // Seleccionamos la fuente FreeSansBold18pt7b
  img.setTextColor(TFT_YELLOW, TFT_BLACK,true);                                      // texto en color amarillo y fondo negro.
  img.pushImage(12,10,TW,TH,th);
  img.drawString("tem: " + t + " | " + "Hum: " + h,xpo,10);		                     // Imprimimos por pantalla la temperatura y la humedad
  img.pushImage(438,10,HW,HH,ht);
  img.drawString("Sen.Ter.: " + s,xpo,60);                                           // Imprimimos por pantalla la Sensación Térmica
  img.pushImage(80,55,SW,SH,sh);
  img.pushSprite(x, y, TFT_TRANSPARENT);
  img.deleteSprite();
}