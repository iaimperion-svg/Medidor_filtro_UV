# Medidor_filtro_UV

Proyecto con Arduino Mega 2560 para consultar por Wi-Fi el índice UV publicado
para una ubicación de Chile y mostrarlo en una pantalla. La implementación actual
es una prueba del display; todavía no obtiene datos UV desde Internet.

El planteamiento inicial del repositorio menciona medición con sensores e
inteligencia artificial. En esta primera implementación se trabaja con una fuente
web; no se han definido un sensor UV físico ni una función de inteligencia artificial.

## Estado de la implementación

| Componente | Estado |
| --- | --- |
| Arduino Mega 2560 | Identificado por el usuario; firma ATmega2560 `0x1e9801` leída durante la carga |
| TFT ILI9486, 480×320, bus paralelo de 16 bits | Programa compilado, cargado y leído de vuelta correctamente |
| Orientación del display | `Set_Rotation(3)`: horizontal, giro de 180° respecto a la primera prueba con rotación 1 |
| Comprobación visual | Pendiente de confirmación explícita del usuario sobre colores, texto y orientación |
| USR-WIFI232-D2 | Identificado por fotografías; enlace con el Mega y configuración Wi-Fi pendientes |
| Fuente externa para Wi-Fi | 3,3 V y 1 A según lo indicado por el usuario; sin medición eléctrica registrada |
| Fuente de datos UV | Pendientes la ubicación, el proveedor y la validación del acceso HTTP/HTTPS |

## Probar el display

El sketch está en [`firmware/prueba_display/prueba_display.ino`](firmware/prueba_display/prueba_display.ino).

1. Con el Mega desconectado, montar el shield alineando su conector doble de 36
   pines con el bloque del Mega. Verificar que los extremos `5V` y `GND` coincidan.
2. Conectar el Mega por USB. Esta prueba no necesita el módulo Wi-Fi ni utiliza
   la tarjeta SD. El display se alimenta mediante su conexión al Mega.
3. Instalar Arduino IDE y el paquete **Arduino AVR Boards** si no están disponibles.
4. Instalar **LCDWIKI_GUI** y **LCDWIKI_KBV** desde el paquete del módulo o los
   repositorios del proveedor, indicados más abajo.
5. En `LCDWIKI_KBV/lcd_mode.h`, establecer `CONFIG_USE_8BIT_BUS` en `0`.
   El sketch rechaza la compilación cuando la biblioteca está configurada a 8 bits.
6. Abrir el sketch, seleccionar **Arduino Mega or Mega 2560**, procesador
   **ATmega2560 (Mega 2560)**, y el puerto real del dispositivo.
   En el equipo de desarrollo se utilizó `COM3`; puede cambiar en otro equipo.
7. Compilar y cargar. Abrir el monitor serie a **115200 baudios**.

La pantalla recorre negro, blanco, rojo, verde y azul, aproximadamente un segundo
por color. Luego muestra `PRUEBA DISPLAY`, `Mega 2560 / ILI9486`, `UV: --`,
`Sin datos de Internet` y tres franjas de color. `UV: --` significa que todavía
no hay un dato; no es una lectura UV ni un valor simulado.

### Pines utilizados

La asignación corresponde al shield Mega de 16 bits, no al shield de 8 bits para Uno.

| Señal del TFT | Pin del Mega |
| --- | --- |
| DB0–DB7 | 37, 36, 35, 34, 33, 32, 31, 30 |
| DB8–DB15 | 22, 23, 24, 25, 26, 27, 28, 29 |
| RS / CD | 38 |
| WR | 39 |
| CS | 40 |
| RESET | 41 |
| RD de la biblioteca | 44, reservado como auxiliar; NC en este shield |
| CS de flash opcional | 45, deseleccionado por el sketch |
| CS de tarjeta SD | 53, deseleccionado por el sketch |

La versión local de LCDWIKI_KBV accede al registro de RD en su constructor incluso
si se pasa `-1`. Por eso esta prueba utiliza el pin válido 44 en lugar de `-1/255`.

### Resultado de las pruebas del 7 de noviembre de 2026

- Herramientas utilizadas: Arduino IDE de Microsoft Store, paquete
  `ArduinoLLC.ArduinoIDE` versión de distribución `1.8.57.0`;
  Arduino AVR Boards `1.8.3`; AVR GCC `7.3.0`; avrdude `6.3-20190619`.
- Las bibliotecas LCDWIKI_GUI y LCDWIKI_KBV proceden de la instalación existente
  del equipo; no se registró una versión o un commit de origen de cada una.
- Placa de compilación: `arduino:avr:mega:cpu=atmega2560`.
- Compilación correcta: **15.624 bytes de flash** y **382 bytes de RAM global**.
- La biblioteca existente emitió advertencias de conversiones numéricas y un
  desplazamiento en `Read_ID()`. No se modificó la biblioteca global.
- Carga en `COM3` y verificación por lectura de **15.624 bytes**, tanto en la
  primera prueba como en la actualización a rotación 3.
- En la primera carga se recibió por UART la resolución configurada `480x320`
  y el mensaje final de la prueba. Ese mensaje confirma ejecución del programa,
  no constituye una medición o lectura de retorno de los píxeles de la pantalla.
- La comprobación visual y la confirmación del giro de 180° siguen pendientes.

Los registros, binarios y el respaldo del firmware anterior permanecen en
`artifacts/prueba_display/` en el equipo de desarrollo y están excluidos de Git.

## Integración Wi-Fi pendiente

El módulo disponible es **USR-WIFI232-D2**, no un ESP8266. Su alimentación y
sus comandos deben seguir su propio manual. Se dispone de una fuente externa
de 3,3 V y 1 A según la información facilitada por el usuario.

Antes de conectar la UART hay que resolver la adaptación de niveles entre el Mega
y el módulo; no se ha validado un circuito con resistencias. También queda por
comprobar el firmware del módulo, el acceso a la fuente UV y el tratamiento de
datos antiguos o inválidos. No guardar contraseñas Wi-Fi en el código versionado.

## Skills del proyecto

Las instrucciones reutilizables están en [`.agents/skills/`](.agents/skills/):

- `arduino-mega-hardware`: componentes, alimentación y cableado.
- `arduino-uv-display`: interfaz del display y estados del dato.
- `arduino-uv-validation`: pruebas y evidencia de funcionamiento.
- `arduino-wifi-web`: conectividad y obtención de datos web.
- `chile-uv-data`: fuente, ubicación y significado del índice UV.

Los cinco paquetes pasaron el validador de estructura de skills. Eso no sustituye
las pruebas del firmware ni la validación física del montaje.

## Fuentes técnicas

- [Display paralelo ILI9486 para Mega: documentación y ejemplos](https://www.lcdwiki.com/3.5inch_Arduino_Display-Mega2560).
- [Biblioteca LCDWIKI_GUI del proveedor](https://github.com/lcdwiki/LCDWIKI_gui).
- [Biblioteca LCDWIKI_KBV del proveedor](https://github.com/lcdwiki/LCDWIKI_kbv).
- [Pinout oficial del Arduino Mega 2560](https://docs.arduino.cc/resources/pinouts/A000067-full-pinout.pdf).
- [Manual del USR-WIFI232-D2](https://www.pusr.com/download/WIFI/USR-WIFI232-D2-V1.0.1_en.pdf).

## Colaboración

- Registrar las tareas y los errores en las incidencias de GitHub.
- Trabajar cada cambio en una rama y proponer su integración mediante una pull request.
- Mantener este documento actualizado con las instrucciones necesarias para trabajar en el proyecto.
- No incluir contraseñas, claves ni archivos de configuración privados.
