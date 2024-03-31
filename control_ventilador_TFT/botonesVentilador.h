/*
 * Funciones para manejar el ventilador de techo
 * @JMTS - www.jmts.es
 * 22/03/2024
 */

ButtonWidget btn_1_1 = ButtonWidget(&tft);
ButtonWidget btn_1_2 = ButtonWidget(&tft);
ButtonWidget btn_1_3 = ButtonWidget(&tft);
ButtonWidget btn_1_4 = ButtonWidget(&tft);
ButtonWidget btn_1_5 = ButtonWidget(&tft);
ButtonWidget btn_1_6 = ButtonWidget(&tft);
ButtonWidget btn_1_7 = ButtonWidget(&tft);
ButtonWidget btn_1_8 = ButtonWidget(&tft);
ButtonWidget btn_1_9 = ButtonWidget(&tft);
ButtonWidget btn_1_10 = ButtonWidget(&tft);
ButtonWidget btn_1_11 = ButtonWidget(&tft);
ButtonWidget btn_1_12 = ButtonWidget(&tft);
ButtonWidget btn_1_13 = ButtonWidget(&tft);
ButtonWidget btn_1_14 = ButtonWidget(&tft);
ButtonWidget btn_1_15 = ButtonWidget(&tft);
ButtonWidget btn_1_16 = ButtonWidget(&tft);
ButtonWidget btn_1_17 = ButtonWidget(&tft);

// Tamaño de los botones
#define BUTTON_Wv2 100
#define BUTTON_Wv2_1 50
#define BUTTON_Hv2 50

// Crea una matriz de instancias de botones para usar en bucles for()
// Esto es más útil cuando se emplean una gran cantidad de botones
ButtonWidget* btn_1_[] = {&btn_1_1, &btn_1_2, &btn_1_3, &btn_1_4, &btn_1_5, &btn_1_6, &btn_1_7 , &btn_1_8, &btn_1_9, &btn_1_10, &btn_1_11, &btn_1_12, &btn_1_13, &btn_1_14, &btn_1_15, &btn_1_16, &btn_1_17};
uint8_t buttonCount1 = sizeof(btn_1_) / sizeof(btn_1_[0]);

void btn_1_1_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(on_off_luz, b);
    break;
    case 2:
      controlVentilador(on_off_luz2, b);
    break;
  }
}
// volver a pantalla principal
void btn_1_2_pressAction(void)
{
  ventilador = 0;
}

void btn_1_3_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(on_off_vent, b);
    break;
    case 2:
      controlVentilador(on_off_vent2, b);
    break;
  }
}

void btn_1_4_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(luz_amarilla, b);
    break;
    case 2:
      controlVentilador(luz_amarilla2, b);
    break;
  }
}

void btn_1_5_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(luz_blanca, b);
    break;
    case 2:
      controlVentilador(luz_blanca2, b);
    break;
  }
}

void btn_1_6_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(luz_azul, b);
    break;
    case 2:
      controlVentilador(luz_azul2, b);
    break;
  }
}

void btn_1_7_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(brillo_bajar, b);
    break;
    case 2:
      controlVentilador(brillo_bajar2, b);
    break;
  }
}

void btn_1_8_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(brillo_subir, b);
    break;
    case 2:
      controlVentilador(brillo_subir2, b);
    break;
  }
}

void btn_1_9_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(velo_1, b);
    break;
    case 2:
      controlVentilador(velo_1_2, b);
    break;
  }
}

void btn_1_10_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(velo_2, b);
    break;
    case 2:
      controlVentilador(velo_2_2, b);
    break;
  }
}

void btn_1_11_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(velo_3, b);
    break;
    case 2:
      controlVentilador(velo_3_2, b);
    break;
  }
}

void btn_1_12_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(velo_4, b);
    break;
    case 2:
      controlVentilador(velo_4_2, b);
    break;
  }
}

void btn_1_13_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(velo_5, b);
    break;
    case 2:
      controlVentilador(velo_5_2, b);
    break;
  }
}

void btn_1_14_pressAction(void)
{
  switch(ventilador){
    case 1:
      (invertir_vent, b);
    break;
    case 2:
      (invertir_vent2, b);
    break;
  }
}

void btn_1_15_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(h_2, b);
    break;
    case 2:
      controlVentilador(h_2_2, b);
    break;
  }
}

void btn_1_16_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(h_4, b);
    break;
    case 2:
      controlVentilador(h_4_2, b);
    break;
  }
}

void btn_1_17_pressAction(void)
{
  switch(ventilador){
    case 1:
      controlVentilador(h_8, b);
    break;
    case 2:
      controlVentilador(h_8_2, b);
    break;
  }
}

// Función para iniciar y mostrar los botones
void initButtonsV() {
  uint16_t x;
  uint16_t y = 20;
  uint16_t y1 = 90;
  uint16_t y2 = 160;
  uint16_t y3 = 230;
  
// On-Off Luz
  x = (tft.width() - BUTTON_Wv2) / 2 - 160;
  btn_1_1.initButtonUL(x, y, BUTTON_Wv2, BUTTON_Hv2, TFT_WHITE, TFT_BLUE, TFT_WHITE, "Luz", 1);
  btn_1_1.setPressAction(btn_1_1_pressAction);
  btn_1_1.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

// Volver pantalla principal
  x = (tft.width() - BUTTON_Wv2) / 2;
  btn_1_2.initButtonUL(x, y, BUTTON_Wv2, BUTTON_Hv2, TFT_WHITE, TFT_DARKGREEN, TFT_WHITE, "Atras", 1);
  btn_1_2.setPressAction(btn_1_2_pressAction);
  btn_1_2.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

// On-Off Ventilador
  x = ((tft.width() - BUTTON_Wv2) / 2) + 160 ;
  btn_1_3.initButtonUL(x, y, BUTTON_Wv2, BUTTON_Hv2, TFT_WHITE, TFT_BLUE, TFT_WHITE, "Vent", 1);
  btn_1_3.setPressAction(btn_1_3_pressAction);
  btn_1_3.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

// Luz Amarilla
  x = (tft.width() - BUTTON_Wv2_1) / 2 - 90;
  btn_1_4.initButtonUL(x, y1, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_YELLOW, TFT_BLACK, "", 1);
  btn_1_4.setPressAction(btn_1_4_pressAction);
  btn_1_4.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

// Luz Blanca
  x = (tft.width() - BUTTON_Wv2_1) / 2;
  btn_1_5.initButtonUL(x, y1, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_WHITE, TFT_BLACK, "", 1);
  btn_1_5.setPressAction(btn_1_5_pressAction);
  btn_1_5.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado

// Luz Azul
  x = (tft.width() - BUTTON_Wv2_1) / 2 + 90;
  btn_1_6.initButtonUL(x, y1, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_DARKCYAN, TFT_BLACK, "", 1);
  btn_1_6.setPressAction(btn_1_6_pressAction);
  btn_1_6.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado
// Botón Bajar Luz
  x = (tft.width() - BUTTON_Wv2_1) / 2 - 190;
  btn_1_8.initButtonUL(x, y1, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_PURPLE, TFT_WHITE, "-", 1);
  btn_1_8.setPressAction(btn_1_7_pressAction);
  btn_1_8.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado
// Botón Subir Luz
  x = (tft.width() - BUTTON_Wv2_1) / 2 + 190;
  btn_1_8.initButtonUL(x, y1, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_PURPLE, TFT_WHITE, "+", 1);
  btn_1_8.setPressAction(btn_1_8_pressAction);
  btn_1_8.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado
  // Botón v1
  x = (tft.width() - BUTTON_Wv2_1) / 2 - 180;
  btn_1_9.initButtonUL(x, y2, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_NAVY, TFT_WHITE, "1", 1);
  btn_1_9.setPressAction(btn_1_9_pressAction);
  btn_1_9.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado  
  // Botón v2
  x = (tft.width() - BUTTON_Wv2_1) / 2 - 90;
  btn_1_10.initButtonUL(x, y2, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_NAVY, TFT_WHITE, "2", 1);
  btn_1_10.setPressAction(btn_1_10_pressAction);
  btn_1_10.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado  
  // Botón v3
  x = (tft.width() - BUTTON_Wv2_1) / 2;
  btn_1_11.initButtonUL(x, y2, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_NAVY, TFT_WHITE, "3", 1);
  btn_1_11.setPressAction(btn_1_11_pressAction);
  btn_1_11.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado  
  // Botón v4
  x = (tft.width() - BUTTON_Wv2_1) / 2 + 90;
  btn_1_12.initButtonUL(x, y2, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_NAVY, TFT_WHITE, "4", 1);
  btn_1_12.setPressAction(btn_1_12_pressAction);
  btn_1_12.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado  
  // Botón v5
  x = (tft.width() - BUTTON_Wv2_1) / 2 + 180;
  btn_1_13.initButtonUL(x, y2, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_NAVY, TFT_WHITE, "5", 1);
  btn_1_13.setPressAction(btn_1_13_pressAction);
  btn_1_13.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado  
  // Botón F/R
  x = (tft.width() - BUTTON_Wv2) / 2- 132;
  btn_1_14.initButtonUL(x, y3, BUTTON_Wv2, BUTTON_Hv2, TFT_WHITE, TFT_NAVY, TFT_WHITE, "F/R", 1);
  btn_1_14.setPressAction(btn_1_14_pressAction);
  btn_1_14.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado  
  // Botón 2H
  x = (tft.width() - BUTTON_Wv2_1) / 2;
  btn_1_15.initButtonUL(x, y3, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_DARKGREY, TFT_WHITE, "2H", 1);
  btn_1_15.setPressAction(btn_1_15_pressAction);
  btn_1_15.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado 
  // Botón 4H
  x = (tft.width() - BUTTON_Wv2_1) / 2 + 90;
  btn_1_16.initButtonUL(x, y3, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_DARKGREY, TFT_WHITE, "4H", 1);
  btn_1_16.setPressAction(btn_1_16_pressAction);
  btn_1_16.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado 
  // Botón 8H
  x = (tft.width() - BUTTON_Wv2_1) / 2 +180;
  btn_1_17.initButtonUL(x, y3, BUTTON_Wv2_1, BUTTON_Hv2, TFT_WHITE, TFT_DARKGREY, TFT_WHITE, "8H", 1);
  btn_1_17.setPressAction(btn_1_17_pressAction);
  btn_1_17.drawSmoothButton(false, 2, TFT_BLACK); // 3 es el ancho del contorno, TFT_BLACK es el color de fondo circundante para el suavizado 
}
// Funión para que funcione el touch en la pantalla de control del ventilador 1
void touchBotonesV1(){
  static uint32_t scanTime = millis();
  uint16_t t_x = 9999, t_y = 9999;  // Para almacenar las coordenadas del touch 

  // Escanea claves cada 50 ms como máximo
  if (millis() - scanTime >= 50) {
    // Pulsado se establecerá como verdadero si hay un toque válido en la pantalla
    bool pressed = tft.getTouch(&t_x, &t_y);
    scanTime = millis();
    for (uint8_t b = 0; b < buttonCount1; b++) {
      if (pressed) {
        if (btn_1_[b]->contains(t_x, t_y)) {
          btn_1_[b]->press(true);
          btn_1_[b]->pressAction();
        }
      }
      else {
        btn_1_[b]->press(false);
        btn_1_[b]->releaseAction();
      }
    }
  }
}
void touchBotonesV2(){
  static uint32_t scanTime = millis();
  uint16_t t_x = 9999, t_y = 9999;  // Para almacenar las coordenadas del touch 

  // Escanea claves cada 50 ms como máximo
  if (millis() - scanTime >= 50) {
    // Pulsado se establecerá como verdadero si hay un toque válido en la pantalla
    bool pressed = tft.getTouch(&t_x, &t_y);
    scanTime = millis();
    for (uint8_t b = 0; b < buttonCount1; b++) {
      if (pressed) {
        if (btn_1_[b]->contains(t_x, t_y)) {
          btn_1_[b]->press(true);
          btn_1_[b]->pressAction();
        }
      }
      else {
        btn_1_[b]->press(false);
        btn_1_[b]->releaseAction();
      }
    }
  }
}
// Función para mostrar la pantalla de control del ventilador 1
void mostrarPantallaV1(){
  tft.fillScreen(TFT_BLACK);
  tft.drawLine(50, 79, 430, 79, TFT_RED);
  tft.drawLine(50, 80, 430, 80, TFT_RED);
  tft.drawLine(50, 81, 430, 81, TFT_RED);
  tft.drawLine(50, 149, 430, 149, TFT_RED);
  tft.drawLine(50, 150, 430, 150, TFT_RED);
  tft.drawLine(50, 151, 430, 151, TFT_RED);
  tft.drawLine((tft.width() - BUTTON_Wv2_1) / 2 + 20, 219, 430, 219, TFT_RED);
  tft.drawLine((tft.width() - BUTTON_Wv2_1) / 2 + 20, 220, 430, 220, TFT_RED);
  tft.drawLine((tft.width() - BUTTON_Wv2_1) / 2 + 20, 221, 430, 221, TFT_RED);
  initButtonsV();
  while(ventilador == 1){
    int xpos = tft.width() / 2;
    touchBotonesV1();
    if ((unsigned long) (currentMillis - previosMillis) >= intervalo){
      //enviarBD();
      previosMillis = millis();
    }
    //Recojemos los datos UDP
    datos();
    // Llamamos a la actualización via OTA
    ArduinoOTA.handle();
    // Llamamos a la actualización de los DDNS cada 10 segundos
    //EasyDDNS.update(10000);
  }
  zonaFijaPantalla();
  if (mostrar == 3){
    btn3.drawSmoothButton(true);
    btn4.drawSmoothButton(false);
  }
}
// Función para mostrar la pantalla de control del ventilador 2
void mostrarPantallaV2(){
  tft.fillScreen(TFT_BLACK);
  tft.drawLine(50, 79, 430, 79, TFT_RED);
  tft.drawLine(50, 80, 430, 80, TFT_RED);
  tft.drawLine(50, 81, 430, 81, TFT_RED);
  tft.drawLine(50, 149, 430, 149, TFT_RED);
  tft.drawLine(50, 150, 430, 150, TFT_RED);
  tft.drawLine(50, 151, 430, 151, TFT_RED);
  tft.drawLine((tft.width() - BUTTON_Wv2_1) / 2 + 20, 219, 430, 219, TFT_RED);
  tft.drawLine((tft.width() - BUTTON_Wv2_1) / 2 + 20, 220, 430, 220, TFT_RED);
  tft.drawLine((tft.width() - BUTTON_Wv2_1) / 2 + 20, 221, 430, 221, TFT_RED);
  initButtonsV();
  while(ventilador == 2){
    int xpos = tft.width() / 2;
    touchBotonesV2();
    if ((unsigned long) (currentMillis - previosMillis) >= intervalo){
      //enviarBD();
      previosMillis = millis();
    }
    //Recojemos los datos UDP
    datos();
    // Llamamos a la actualización via OTA
    ArduinoOTA.handle();
    // Llamamos a la actualización de los DDNS cada 10 segundos
    //EasyDDNS.update(10000);
  }
  zonaFijaPantalla();
  if (mostrar == 4){
    btn3.drawSmoothButton(false);
    btn4.drawSmoothButton(true);
  }
}
