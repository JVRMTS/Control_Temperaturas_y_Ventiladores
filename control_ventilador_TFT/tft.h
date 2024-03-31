/*
 * La función de este archivo es mostrar en la pantalla TFT los datos que queremos ver.
 * Probado con una pantallas TFT 3.5" ILI9486/9488 SPI EN UN ESP32 DEV MODULE
 * @JMTS - www.jmts.es
 * 17/02/24
 * Iconos creados por Those Icons - Flaticon https://www.flaticon.es
 */

#include <SPI.h>		                      // incluye libreria bus SPI.
#include <LittleFS.h>                     // incluye la libreria LittleFS
#include <FS.h>                           // incluye la libreria FS
#include <TFT_eSPI.h>                     // incluye la libreria para el manejo de la TFT.
#include <TFT_eWidget.h>                  // incluye la libreria para los botones
#include "Free_Fonts.h"                   // Incluye el archivo de encabezado adjunto a este sketch.
#include "imagenes.h"                     // Fichero con las imágenes e iconos.


#define TFT_CS 15                         //TFT CS al PIN 15

TFT_eSPI tft = TFT_eSPI();                // Crea el objeto tft

TFT_eSprite img = TFT_eSprite(&tft);      // Declarar objeto Sprite "spr" con puntero al objeto "tft"

#define CALIBRATION_FILE "/TouchCalData1" // Se declara el archivo de calibración
#define REPEAT_CAL false                  // Se declara la repetición de la calibración en falso
char* loca;


// BOTONES //
ButtonWidget btn1 = ButtonWidget(&tft);
ButtonWidget btn2 = ButtonWidget(&tft);
ButtonWidget btn3 = ButtonWidget(&tft);
ButtonWidget btn4 = ButtonWidget(&tft);
ButtonWidget btn5 = ButtonWidget(&tft);
ButtonWidget btn6 = ButtonWidget(&tft);


// Tamaño de los botones
#define BUTTON_W 100
#define BUTTON_H 50

// Crea una matriz de instancias de botones para usar en bucles for()
// Esto es más útil cuando se emplean una gran cantidad de botones
ButtonWidget* btn[] = {&btn1 , &btn2, &btn3, &btn4, &btn5, &btn6};
uint8_t buttonCount = sizeof(btn) / sizeof(btn[0]);

void mostrarPantalla();
void zonaFijaPantalla();
void initButtons();

#include "botonesVentilador.h"

void btn1_pressAction(void)
{
  mostrar = 1;
  loca = "DESPACHO";
  btn1.drawSmoothButton(true);
  btn2.drawSmoothButton(false);
  btn3.drawSmoothButton(false);
  btn4.drawSmoothButton(false);
  btn5.drawSmoothButton(false);
  btn6.drawSmoothButton(false);
}

void btn2_pressAction(void)
{
  mostrar = 2;
  loca = "SALON";
  btn1.drawSmoothButton(false);
  btn2.drawSmoothButton(true);
  btn3.drawSmoothButton(false);
  btn4.drawSmoothButton(false);
  btn5.drawSmoothButton(false);
  btn6.drawSmoothButton(false);
}
void btn3_pressAction(void)
{
  mostrar = 3;
  loca = "DORMITORIO";
  btn1.drawSmoothButton(false);
  btn2.drawSmoothButton(false);
  btn3.drawSmoothButton(true);
  btn4.drawSmoothButton(false);
  btn5.drawSmoothButton(false);
  btn6.drawSmoothButton(false);
}
void btn4_pressAction(void)
{
  mostrar = 4;
  btn1.drawSmoothButton(false);
  btn2.drawSmoothButton(false);
  btn3.drawSmoothButton(false);
  btn4.drawSmoothButton(true);
  btn5.drawSmoothButton(false);
  btn6.drawSmoothButton(false);
}

void btn5_pressAction(void)
{
  if (mostrar == 3){
   //control = 1;
    ventilador = 1;
    mostrarPantallaV1();
    btn5.drawSmoothButton(false);
    btn6.drawSmoothButton(false);
  }
  if (mostrar == 4){
    //control = 2;
    ventilador = 2;
    mostrarPantallaV2();
    btn5.drawSmoothButton(false);
    btn6.drawSmoothButton(false);
  }
}

void btn6_pressAction(void)
{
  btn5.drawSmoothButton(false);
  btn6.drawSmoothButton(true);
}

// Función para iniciar y mostrar los botones
void initButtons() {
  
  uint16_t x = (tft.width() - BUTTON_W) / 2 - 60;
  uint16_t y = 183;
  uint16_t y1 = 265;

  btn1.initButtonUL(x, y, BUTTON_W, BUTTON_H, TFT_WHITE, TFT_SKYBLUE, TFT_BLACK, "Despa", 1);
  btn1.setPressAction(btn1_pressAction);
  btn1.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

  x = (tft.width() - BUTTON_W) / 2 + 60;
  btn2.initButtonUL(x, y, BUTTON_W, BUTTON_H, TFT_WHITE, TFT_SKYBLUE, TFT_BLACK, "Salon", 1);
  btn2.setPressAction(btn2_pressAction);
  btn2.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

  x = ((tft.width() - BUTTON_W) / 2) + 180 ;
  btn3.initButtonUL(x, y, BUTTON_W, BUTTON_H, TFT_WHITE, TFT_SKYBLUE, TFT_BLACK, "Dormi", 1);
  btn3.setPressAction(btn3_pressAction);
  btn3.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

  x = (tft.width() - BUTTON_W) / 2 - 180;
  btn4.initButtonUL(x, y, BUTTON_W, BUTTON_H, TFT_WHITE, TFT_SKYBLUE, TFT_BLACK, "Local", 1);
  btn4.setPressAction(btn4_pressAction);
  btn4.drawSmoothButton(true, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

  x = (tft.width() - BUTTON_W) / 2 + 160;
  btn5.initButtonUL(x, y1, BUTTON_W, BUTTON_H, TFT_WHITE, TFT_SKYBLUE, TFT_BLACK, "Venti", 1);
  btn5.setPressAction(btn5_pressAction);
  btn5.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

  x = (tft.width() - BUTTON_W) / 2 - 160;
  btn6.initButtonUL(x, y1, BUTTON_W, BUTTON_H, TFT_WHITE, TFT_SKYBLUE, TFT_BLACK, "A/A", 1);
  btn6.setPressAction(btn6_pressAction);
  btn6.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado
}

// TFT CONFIGURACIÓN Y VISUALIZACIÓN //

// Con esta función dibujamos lo que no queremos que no se refresque en la pantalla y la orientación de esta, la ejecutamos desde la funcion configuracionPantalla().
void zonaFijaPantalla(){
  int xpos = tft.width() / 2;                                 // Centro del ancho de pantalla
  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);                                  // Establece el fondo de pantalla.
  tft.setTextDatum(TC_DATUM);                                 // Centramos el texto en pantalla
  // Se dibujan tres rectángulos para tener un grosor de línea de 3px
  tft.drawRoundRect(1, 1, 479, 251, 10, TFT_RED);
  tft.drawRoundRect(2, 2, 477, 249, 10, TFT_RED);
  tft.drawRoundRect(3, 3, 475, 247, 10, TFT_RED);
  // Se dibujan tres lineas para tener el grosor de 3px
  tft.drawLine(50, 121, 430, 121, TFT_RED);
  tft.drawLine(50, 122, 430, 122, TFT_RED);
  tft.drawLine(50, 123, 430, 123, TFT_RED);
  tft.pushImage(xpos - 77, 265, xw, xh, xxx);
  tft.setFreeFont(FSSB12);                                    // Definimos el tamaño de texto de los botones
  initButtons();                                              // Iniciamos los botones y sus funciones
}
//void mostrarPantalla();
// Esta funcion se ejecuta en el Setup para configurar la pantalla y mostrar los datos o dibujos que mo se refrescan mediante la función zonaFijaPantalla().
void configuracionPantalla(){
  tft.begin();			                                          // Inicializa pantalla.
  tft.setRotation(3);	                                        // establece posicion 0 - vertical alimentación arriba, 1-horizontal alimentación izquierda, 2-vertical alimentación abajo, 3-horizontal alimentación derecha.
  tft.fillScreen(TFT_BLACK);                                  // Establece el fondo de pantalla.
  zonaFijaPantalla();                                         // Llamamos a la función para mostrar los datos e imágenes que no se refrescan y permanecen fijos en pantalla.
}

// Función para mostrar los botones
void touchBotones(){
  static uint32_t scanTime = millis();
  uint16_t t_x = 9999, t_y = 9999;  // Para almacenar las coordenadas del touch 

  // Escanea claves cada 50 ms como máximo
  if (millis() - scanTime >= 50) {
    // Pulsado se establecerá como verdadero si hay un toque válido en la pantalla
    bool pressed = tft.getTouch(&t_x, &t_y);
    scanTime = millis();
    for (uint8_t b = 0; b < buttonCount; b++) {
      if (pressed) {
        if (btn[b]->contains(t_x, t_y)) {
          btn[b]->press(true);
          btn[b]->pressAction();
        }
      }
      else {
        btn[b]->press(false);
        btn[b]->releaseAction();
      }
    }
  }
}

// Declaramos las variables que se van a utilizar para mostrarlas en pantalla
String tem;
String hum;
String ste;
String ver;
// Función para escoger lo que queremos mostrar en pantalla
String dat(){
if(mostrar == 4){
    ver = horMin;
    tem = t;
    hum = h;
    ste = s;
  } else {
    ver = loca;
    tem = t1;
    hum = h1;
    ste = s1;
  }
  return ver;
  return tem;
  return hum;
  return ste;
}

// Declaramos las funciones para mostrar los Sprites
void drawReloj(int x, int y);
void drawTemperatura(int x, int y);
//void drawBotones(int x, int y);

// Función para mostrar los Sprites
void mostrarPantalla(){
  int xpos = tft.width() / 2;
  tft.setTextDatum(TC_DATUM);
  drawReloj(xpos - 215,6);
  drawTemperatura(xpos - 215,135);
  btn5.drawSmoothButton(false);
  touchBotones();
}

// Tamaño del Sprite fecha hora
#define RWIDTH  430
#define RHEIGHT 105

// Sprite para mostrar la fecha y hora
void drawReloj(int x, int y){
  dat();
  img.createSprite(RWIDTH, RHEIGHT);
  img.setTextDatum(TC_DATUM);
  int xpo = (RWIDTH / 2);
  img.setTextColor(TFT_WHITE, TFT_BLACK, true);
  img.setFreeFont(FSSB24);
  img.fillSprite(TFT_BLACK);
  img.drawString(ver,xpo,10);
  img.drawString(diaS + " " + dia + " " + mes + " " + ano,xpo,58);
  img.pushSprite(x, y, TFT_TRANSPARENT);
  img.deleteSprite();
}

// Tamaño del Sprite temperaturas
#define TWIDTH  430
#define THEIGHT 40

// Sprite para mostrar las temperaturas
void drawTemperatura(int x, int y){
  dat();
  img.createSprite(TWIDTH, THEIGHT);
  img.setSwapBytes(true);
  int xpo = (TWIDTH / 2);
  img.setTextDatum(TC_DATUM);
  img.setTextColor(TFT_YELLOW, TFT_BLACK, true);
  img.setFreeFont(FSSB18);                      
  img.drawString(tem, xpo - 119, 3);            
  img.pushImage(xpo - 200,0,TW,TH,th);
  img.drawString(hum, xpo + 19, 3);             
  img.pushImage(xpo - 53,0,HW,HH,ht);
  img.drawString(ste, xpo + 152, 3);            
  img.pushImage(xpo + 72,0,SW,SH,sh);
  img.pushSprite(x, y, TFT_TRANSPARENT);
  img.deleteSprite();
}

