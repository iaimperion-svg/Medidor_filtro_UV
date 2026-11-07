---
name: obtener-datos-uv-meteochile
description: Analiza y prepara la obtención de índice UV de MeteoChile para Medidor_filtro_UV. Úsala para evaluar la fuente DMC, seleccionar la estación, validar lecturas recientes o definir los datos que recibirá el Arduino.
---

# Obtener datos UV de MeteoChile

## Contexto y alcance

El proyecto es `iaimperion-svg/Medidor_filtro_UV`. La carpeta de trabajo inicial es `C:\ANDRUINO`; comprueba el repositorio activo antes de modificarlo. La estación inicialmente elegida es Carriel Sur, Concepción Ap., código `360019`. Cambiar de estación requiere una decisión basada en la ubicación del dispositivo, no sustituirla silenciosamente cuando falten datos.

Lee [la referencia de la fuente](references/fuente-dmc.md) al evaluar el acceso o la semántica de los datos. Las observaciones fechadas allí son antecedentes; verifica el estado actual antes de afirmar que el servicio sigue disponible.

La skill sirve tanto para análisis como para implementación. Ajusta los artefactos al encargo: una petición de análisis o documentación no autoriza crear un recolector, desplegar servicios ni programar la placa.

## Elegir el acceso

Prefiere el servicio oficial documentado `getRecienteUvb`. Comprueba los requisitos vigentes de acceso y los límites publicados; no deduzcas que uso público significa acceso anónimo a la API. Una documentación accesible no demuestra que se haya probado una consulta autenticada.

La tabla de la página diaria permite contrastar las lecturas. Extraerla puede ser una alternativa si el acceso oficial no está disponible, indicando que los cambios de presentación pueden romper esa integración. No recurras a reconocimiento de imágenes si los valores están publicados como texto o tabla.

El enlace diario contiene una fecha fija. Para seguimiento continuo hay que seleccionar el día que corresponde a las marcas temporales de la fuente y resolver los cambios de día; no conservar indefinidamente la fecha del enlace de ejemplo.

## Interpretar y validar

- Selecciona la estación por su código; comprueba el nombre como control adicional.
- Elige la lectura válida más reciente por fecha y hora, sin asumir que el último elemento de una respuesta es el más nuevo. Evita que un dato retrasado sustituya uno posterior.
- Distingue lectura reciente, máximo horario y máximo diario. Conserva los decimales disponibles; no uses un resumen redondeado como valor actual.
- Contrasta API y tabla para la misma estación y marca temporal. La prueba documentada mostró enteros en la API y decimales distintos en la tabla; no inventes la precisión que falte ni presupongas que ambas representaciones son equivalentes.
- Un punto, una celda vacía o un valor nulo significa falta de dato, no índice cero. Cero es válido cuando la fuente lo publica expresamente. No limites el índice a 11.
- Conserva las marcas originales en UTC. Convierte para mostrar la hora local con la zona `America/Santiago`, sin fijar manualmente un desfase permanente.
- Separa momento de medición, momento de consulta y, si existe, momento de generación del informe. La separación de cinco minutos entre registros no garantiza publicación inmediata ni disponibilidad continua.
- Define con el uso del dispositivo cuándo una lectura se considera antigua. Ante un fallo, conserva la última lectura con su antigüedad y estado; no inventes una nueva ni presentes el dato anterior como actualizado.

## Entrega al dispositivo

Propón un mensaje pequeño con estación, índice UV, fecha y hora de medición, momento de consulta y estado de vigencia. Mantén cualquier máximo diario en un campo distinto. Acuerda este contrato con el firmware de Kassian antes de implementar un formato o transporte.

Como opción de diseño, un ordenador o servicio intermedio puede consultar DMC, validar la información y enviar ese mensaje al Arduino. Determina si conviene acceso directo desde la placa después de conocer su conectividad, memoria y capacidad HTTPS. No hace falta IA para descargar y seleccionar registros.

Mantén las claves de acceso fuera del repositorio, del historial de cambios y de los registros visibles. Revisa los ejemplos oficiales antes de reutilizarlos: algunos omiten la validación TLS; esa omisión no es una condición necesaria de la integración.

## Comprobación y resultado

Cuando se autorice implementar, compara una lectura con la tabla oficial para la misma estación y hora. Comprueba también ausencia de datos, índice cero, lecturas antiguas, llegada desordenada y cambio de día. Informa qué se observó realmente y qué sigue siendo una hipótesis.

Los valores representan la estación meteorológica. Si se pretende evaluar un filtro o la radiación en el punto donde está el dispositivo, exige medición local y un método de comparación apropiado; no atribuyas esa capacidad a los datos remotos por sí solos.

Entrega la viabilidad, fuente consultada, estación elegida, requisitos de acceso, frescura observada y pendientes concretos. Identifica a la Dirección Meteorológica de Chile como fuente de los datos.
