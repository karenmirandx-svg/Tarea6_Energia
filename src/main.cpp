#include <Arduino.h>

#define LED_PIN 2
#define BUTTON_PIN 33

void setup() {
    Serial.begin(115200);
    delay(1000); 
    
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Usamos la resistencia interna tranquilamente
}

void loop() {
    Serial.println("\n>>> Sistema ACTIVO. Ejecutando tareas por 5 segundos... <<<");
    digitalWrite(LED_PIN, HIGH);
    delay(5000);
    
    Serial.println("Apagando componentes... Entrando en modo LIGHT SLEEP.");
    digitalWrite(LED_PIN, LOW);
    delay(500); 

    // 1. Configuramos los despertadores
    esp_sleep_enable_timer_wakeup(10000000); // Temporizador de 10 segundos
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 0); // Botón hacia GND

    // 2. Entramos en Light Sleep (El simulador se PAUSA justo aquí)
    esp_light_sleep_start();

    // 3. ¡Despertó! El código CONTINÚA desde aquí
    esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
    
    if(wakeup_reason == ESP_SLEEP_WAKEUP_EXT0) {
        Serial.println(">>> Sistema despertado por INTERRUPCION EXTERNA (Boton) <<<");
    } else if(wakeup_reason == ESP_SLEEP_WAKEUP_TIMER) {
        Serial.println(">>> Sistema despertado por TEMPORIZADOR (Timer) <<<");
    }
    
    delay(2000); // Pequeña pausa de 2 segundos antes de repetir el ciclo
}
