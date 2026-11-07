---
name: arduino-uv-validation
description: Planifica y ejecuta pruebas del sistema Arduino Mega que obtiene y muestra el índice UV. Úsala para revisar integración, tolerancia a fallos, consumo de memoria o criterios de aceptación antes de declarar el proyecto terminado.
---

# Arduino Uv Validation

Valida por capas y conserva evidencia de cada resultado. No conviertas una revisión de código o una simulación en evidencia de funcionamiento físico.

## Orden de integración

1. Compila una prueba mínima para la placa y versiones de librería seleccionadas.
2. Comprueba cada enlace físico: alimentación, puerto serie o bus y display.
3. Verifica conexión y reconexión Wi-Fi.
4. Analiza respuestas guardadas antes de depender del servidor real.
5. Consulta la fuente real y compara el dato extraído con la respuesta recibida.
6. Integra red, analizador, modelo de datos y display.
7. Ejecuta pruebas prolongadas cuando el objetivo incluya operación continua.

No avances como si una capa estuviera validada cuando su prueba falló o no pudo ejecutarse; registra el bloqueo exacto.

## Matriz mínima de fallos

Incluye los casos aplicables:

- arranque sin red y recuperación posterior;
- contraseña incorrecta o módulo ausente;
- DNS, TLS, tiempo de espera y respuestas HTTP no exitosas;
- respuesta vacía, truncada, con campo ausente o tipo inesperado;
- valor fuera del rango aceptado por el contrato;
- cambio de estructura HTML o JSON;
- reinicio del módulo Wi-Fi;
- pérdida del servidor mientras se conserva un dato anterior;
- desbordamiento temporal de `millis()` y ejecución prolongada;
- display desconectado o bus ocupado.

Comprueba que los reintentos estén limitados, que el bucle principal siga respondiendo y que el dato pase a `stale` según la regla definida.

## Evidencia y cierre

Registra placa, módulo, display, firmware, librerías, herramientas, comando de compilación, uso reportado de memoria y salidas relevantes. Sanitiza credenciales y datos sensibles.

Para declarar el proyecto validado se necesita evidencia proporcional al alcance: compilación exitosa, carga al hardware cuando sea parte del encargo, salida serial, comportamiento visible del display y prueba con la fuente real. Si alguna comprobación no está disponible, declara exactamente qué quedó sin verificar y no completes esa afirmación por inferencia.
