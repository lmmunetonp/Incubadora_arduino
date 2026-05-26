## Incubadora Automatizada con Arduino (Edición 2016 / Mejorado) 🌡️🥚

Este proyecto nació originalmente en **2016** como un proyecto final. Decidí rescatarlo de mis archivos para sumarlo a mi portafolio y darle una actualización completa, aplicando nuevas mejoras en el circuito y en el código.

## 🚀 Pruébalo en vivo (Simulador Web)
No necesitas tener las piezas en físico para ver cómo funciona. Puedes entrar a la simulación interactiva desde tu navegador:
👉 https://wokwi.com/projects/465095114889647105

## 🔄 ¿Qué mejoras se hicieron respecto al proyecto de 2016?
- **Antes (2016):** El sistema original solo usaba luces LED de colores para avisar si hacía frío o calor, y tenías que adivinar la temperatura exacta.
- **Ahora (Nueva Versión):** ¡Incorporé una **pantalla LCD 16x2**! Ahora el sistema muestra la temperatura y el porcentaje de humedad en tiempo real con datos exactos en la pantalla.
- **Sistema de emergencia:** Si el sensor se desconecta por accidente, el Arduino apaga el foco inmediatamente por seguridad para no sobrecalentar los huevos.

## 🎛️ Componentes del Circuito
- **Arduino Uno:** El cerebro que controla todo.
- **Sensor DHT22:** El termómetro digital que mide el ambiente.
- **Módulo Relé + LED:** El interruptor automático y la luz que simulan el foco de calor (En esta simulacion se agrego un LED, sin embargo la idea original lleva una conexion a un foco 120v).
- **Pantalla LCD (con adaptador I2C):** La nueva pantalla que muestra los datos usando solo 2 cables de señal.
