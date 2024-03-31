/*
 * Funciones para manejar el ventilador de techo
 * @JMTS - www.jmts.es
 * 17/03/2024
 */

#include <ELECHOUSE_CC1101_SRC_DRV.h> // se ha modificdo la libreria para que no de problemas de compilación con la libreria TFT_eSPI
#include <RCSwitch.h>

int pin = 14;                           // Definir pin de transmisión GDO0

byte ventilador = 0;
byte a_a = 0;                           

RCSwitch mySwitch = RCSwitch();         // Declaramos el objeto mySwitch para transmitir por el CC1101

// Configuración del CC1101:
void configuracionCC1101(){
  ELECHOUSE_cc1101.Init();              // Debe configurarse para inicializar el cc1101
  ELECHOUSE_cc1101.setPA(10);           // configure TxPower. Son posibles los siguientes ajustes dependiendo de la banda de frecuencia. (-30 -20 -15 -10 -6 0 5 7 10 11 12) ¡El valor predeterminado es máximo!
  ELECHOUSE_cc1101.setMHZ(433.92);      // Aquí puede configurar su frecuencia básica. La lib calcula la frecuencia automáticamente (predeterminada = 433,92). El cc1101 puede: 300-348 MHZ, 387-464 MHZ y 779-928 MHZ. Lea más información de la hoja de datos.

  // Activamos la transmision en el pin correspondiente .
  mySwitch.enableTransmit(pin);

  // Configuramos el CC1101 en modo transmisión.
  ELECHOUSE_cc1101.SetTx();
    
  // Seleccionamos el protocolo de transmisión.
  mySwitch.setProtocol(6);

  // Seleccionamos tiempo del pulso en la transmisión.
  mySwitch.setPulseLength(390);
   
  // Numero de repeticiones de transmisión. En mi caso con 2 es suficiente.
  mySwitch.setRepeatTransmit(2);
}

// DECLARACIÓN DE VARIABLES PARA EL MANEJO DE LOS VENTILADORES
unsigned int b = 32;

unsigned long on_off_luz;       unsigned long on_off_luz2;
unsigned long on_off_vent;      unsigned long on_off_vent2;
unsigned long luz_amarilla;     unsigned long luz_amarilla2;
unsigned long luz_blanca;       unsigned long luz_blanca2;
unsigned long luz_azul;         unsigned long luz_azul2;
unsigned long brillo_bajar;     unsigned long brillo_bajar2;
unsigned long brillo_subir;     unsigned long brillo_subir2;
unsigned long invertir_vent;    unsigned long invertir_vent2;
unsigned long velo_1;           unsigned long velo_1_2;
unsigned long velo_2;           unsigned long velo_2_2;
unsigned long velo_3;           unsigned long velo_3_2;
unsigned long velo_4;           unsigned long velo_4_2;
unsigned long velo_5;           unsigned long velo_5_2;
unsigned long h_2;              unsigned long h_2_2;
unsigned long h_4;              unsigned long h_4_2;
unsigned long h_8;              unsigned long h_8_2;

void controlVentilador(unsigned long env, unsigned int b){
  /* AQUI SE HAN DE INTRODUCIR LOS CÓDIGOS QUE SE HAYAN EXTRAIDO DE LOS VENTILADORES*/
  // Ventilador 1
    on_off_luz      = ***;
    on_off_vent     = ***;
    luz_amarilla    = ***;
    luz_blanca      = ***;
    luz_azul        = ***;
    brillo_bajar    = ***;
    brillo_subir    = ***;
    invertir_vent   = ***;
    velo_1          = ***;
    velo_2          = ***;
    velo_3          = ***;
    velo_4          = ***;
    velo_5          = ***;
    h_2             = ***;
    h_4             = ***;
    h_8             = ***;

  // Ventilador 2
    on_off_luz2     = ***;
    on_off_vent2    = ***;
    luz_amarilla2   = ***;
    luz_blanca2     = ***;
    luz_azul2       = ***;
    brillo_bajar2   = ***;
    brillo_subir2   = ***;
    invertir_vent2  = ***;
    velo_1_2        = ***;
    velo_2_2        = ***;
    velo_3_2        = ***;
    velo_4_2        = ***;
    velo_5_2        = ***;
    h_2_2           = ***;
    h_4_2           = ***;
    h_8_2           = ***;
  
  mySwitch.send(env,b); // Función para enviar comandos al ventilador
}