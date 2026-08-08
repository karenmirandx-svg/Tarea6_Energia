TAREA 6 - SISTEMAS EMBEBIDOS: EJERCICIO 1 (GESTION DE ENERGIA)Descripcion del Proyecto
Este repositorio contiene la solucion al Ejercicio 1 de la Tarea 6. El objetivo del proyecto es implementar modos de ahorro de energia en el microcontrolador ESP32, alternando entre periodos de actividad y bajo consumo.

Caracteristicas implementadas:
- Uso de temporizador (esp_sleep_enable_timer_wakeup) para despertar el sistema automaticamente despues de 10 segundos de inactividad.
- Uso de interrupcion externa (esp_sleep_enable_ext0_wakeup) para despertar el sistema manualmente mediante un boton conectado al pin RTC 33. 
- Indicadores visuales (LED) y mensajes de diagnostico por consola serial para identificar claramente el estado del sistema y la causa exacta que lo hizo despertar.  

Instrucciones de Compilacion y Ejecucion
1. Clonar o descargar este repositorio y abrir la carpeta en Visual Studio Code.
2. Asegurarse de tener instalada y configurada la extension PlatformIO}3. Hacer clic en el boton Build (icono de visto bueno) en la barra inferior para compilar el codigo.
4. Para la simulacion, abrir el archivo diagram.json, presionar F1 y ejecutar Wokwi: Start Simulator.
5. Observar el monitor serial para comprobar la respuesta a los eventos de temporizador e interrupcion fisica.