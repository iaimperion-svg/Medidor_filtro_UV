---
name: arduino-uv-display
description: Diseña e implementa la interfaz del display que muestra el índice UV en Arduino. Úsala para elegir la distribución visual, integrar el controlador o comunicar estados de actualización y error.
---

# Arduino Uv Display

Antes de escribir código específico, identifica el modelo, controlador, resolución, interfaz y librería real del display. Si no están definidos y esto cambia pines o implementación, solicita esos datos y evita inventar un controlador.

## Información que debe comunicar

La pantalla debe distinguir, según el espacio disponible:

- valor UV y ubicación;
- categoría, solo cuando sus umbrales estén verificados;
- hora de observación o última actualización;
- estados de conexión, actualización, dato antiguo y error.

Nunca presentes el último valor almacenado como si fuera actual. Un dato antiguo debe conservar su hora y una indicación visible de antigüedad. Muestra texto además de color para que el estado no dependa únicamente de la percepción cromática.

## Implementación

- Separa el modelo de datos UV del código de renderizado.
- Define vistas o funciones explícitas para inicio, conexión, dato válido, dato antiguo y fallo.
- Actualiza únicamente cuando cambie la información o cuando el controlador lo requiera; evita parpadeos y limpiezas completas innecesarias.
- Mantén textos, números y unidades legibles a la distancia prevista. Adapta el contenido a la capacidad real de la pantalla.
- No bloquees la red ni los reintentos mediante animaciones o retardos del display.
- Si el display usa el mismo bus que otro periférico, verifica direcciones, selección de chip y velocidades compatibles.

## Verificación

Prueba la interfaz con datos controlados para valores válidos, límites de categoría, ausencia de hora, texto largo, desconexión y dato antiguo. Cuando haya hardware, verifica visualmente contraste, recorte, parpadeo y recuperación después de un error. Describe como simulados los resultados que no se hayan observado en el dispositivo real.
