/*********************************************************************
 *  Get MAC address value of ESP32 board
 *  Obtém endereço MAC da placa ESP32
 *  Filipe Ihancis (filipeihancist@gmail.com)
 ********************************************************************/


#include <WiFi.h>
#include <esp_wifi.h>


/********************************************************************/

String readMAC()
{
    // Armazena endereço MAC hexadecimal
    uint8_t baseMac[6];

    // Obtém endereço MAC (ESP_OK) ou indica algum erro
    esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);
    
    String MAC = "";
    
    if (ret == ESP_OK) {
      // Converte o hexadecimal em string
      for(int i = 0; i < 6; i++) MAC += String(baseMac[i], HEX);
    } else {
      Serial.println("Failed to read MAC address");
    }
    // Converte para maiúsculo (padrão)
    MAC.toUpperCase();
    return MAC;
}

/********************************************************************/

void setup() 
{
    Serial.begin(9600);
    while(!Serial);
    delay(100);
    Serial.println("Init program");
    delay(500);
}

/********************************************************************/

void loop() 
{
    // Configura em Station Mode (Cliente)
    WiFi.mode(WIFI_STA);
    WiFi.STA.begin();

    // Exibe endereço MAC no Mon. Serial
    Serial.println("MAC address: " + readMAC());
    
    while(1);
}
