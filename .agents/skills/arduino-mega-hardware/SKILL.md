---
name: arduino-mega-hardware
description: Diseña y revisa el hardware del Arduino Mega, su alimentación y el cableado con módulos Wi-Fi y displays. Úsala para seleccionar componentes, crear una lista de materiales o definir pines y conexiones.
---

# Arduino Mega Hardware

Preserva el Arduino Mega como requisito del proyecto. Solo compara otra placa cuando el usuario lo pida; no sustituyas el Mega por conveniencia.

## Antes de diseñar

Identifica con evidencia el modelo o revisión exactos de:

- placa Arduino Mega;
- módulo o shield Wi-Fi;
- display y controlador;
- fuente de alimentación y cualquier periférico adicional.

Usa las hojas de datos o documentación oficial de esos componentes. Si un modelo no está definido y la diferencia puede cambiar alimentación, niveles lógicos, pines o librerías, detente y pregunta antes de entregar un circuito como definitivo.

## Resultado esperado

Entrega, según corresponda:

- lista de materiales con modelos exactos y función de cada pieza;
- tabla de conexiones origen-destino;
- mapa de pines y buses UART, I2C o SPI;
- presupuesto de corriente, tensiones y fuente propuesta;
- componentes de adaptación, protección o desacoplamiento respaldados por la documentación;
- diagrama o esquema cuando ayude a eliminar ambigüedades.

## Comprobaciones obligatorias

- Verifica tensiones de alimentación, niveles lógicos y tolerancia de cada entrada. No conectes una salida de 5 V a una entrada de 3,3 V salvo que la documentación declare esa entrada tolerante.
- Comprueba la corriente máxima y la corriente de arranque del módulo Wi-Fi; no supongas que un pin de la placa puede alimentarlo.
- Detecta conflictos entre los puertos serie del Mega, I2C, SPI, interrupciones y pines reservados por shields.
- Distingue tierra común, alimentación y señales. Incluye el método de programación y depuración sin bloquear el enlace con el módulo Wi-Fi.
- No presentes el cableado como verificado hasta contrastarlo con documentación real y, cuando exista hardware disponible, con mediciones o una prueba física.
