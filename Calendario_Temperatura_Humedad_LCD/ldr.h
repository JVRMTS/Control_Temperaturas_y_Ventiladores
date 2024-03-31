/* Control de la retroiluminación de la pantalla, mediante la lectura de una LDR
 * y escribiendo con la libreria ESP32 AnalogWrite en el pin de la retroiluminación. Hay que modificar la libreria
 * Creado el 17/02/2024
 * @JMTS - www.jmts.es
 */

#include <analogWrite.h>

// Asignamos los pines de la iluminación del LCD y del LDR y declaramos sus variables
const int pinLCD = 18;
const int pinLDR = 32;
unsigned int valorLDR;
unsigned int valorLCD;

void iluminacion(){
  // Comprobamos la intensidad de la luz
  valorLDR = analogRead(pinLDR); // Leemos la variable del LDR
  if (valorLDR <= 5){
    valorLCD = 5; // esto es para que nunca se apaque del todo el LCD
  }else{
    valorLCD = valorLDR / 8; // Le damos el valor a la salida del LCD
  }
  analogWrite(pinLCD, valorLCD); // Escribimos en el pinLCD el valor
}
