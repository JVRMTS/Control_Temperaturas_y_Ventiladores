#include <esp_sleep.h>

void dormir(){
 esp_deep_sleep(1800 * 1000000);  // entrar en deep sleep por 1/2 hora
 WiFi.mode(WIFI_OFF);
}