---
name: arduino-wifi-web
description: Implementa y depura la conexión Wi-Fi, las solicitudes HTTP/HTTPS y el análisis de JSON o HTML para un Arduino Mega con módulo de red. Úsala al obtener datos desde Internet o tratar fallos de conectividad.
---

# Arduino Wifi Web

## Define el contrato antes del código

Confirma el módulo Wi-Fi exacto, su firmware, el transporte con el Mega y las librerías compatibles. Obtén también la URL real, un ejemplo real de respuesta y la frecuencia de actualización permitida. Si falta un dato que cambia la implementación, pregunta antes de elegirlo.

Prefiere una API estructurada cuando la fuente elegida ofrezca una interfaz estable y autorizada. No cambies la fuente solicitada ni declares que existe una API sin comprobarlo. Si solo hay HTML, determina si el valor está en la respuesta inicial o lo genera JavaScript; no supongas que el Mega puede ejecutar una aplicación web.

## Implementación

- Separa conexión Wi-Fi, solicitud, recepción, análisis y publicación del dato en estados comprobables.
- Mantén el bucle principal no bloqueante. Usa límites de tiempo, reintentos acotados y espera progresiva sin impedir que el display siga respondiendo.
- Para HTTPS, verifica que el módulo y la librería soporten TLS y documenta la estrategia real de validación del certificado. No desactives la validación silenciosamente.
- Comprueba el código HTTP, tipo de contenido, longitud y límites de lectura antes de analizar.
- Reduce el uso de RAM: procesa en flujo o filtra campos cuando la librería lo permita, y evita conservar respuestas completas innecesariamente.
- En JSON, valida existencia y tipo del campo. En HTML, usa un marcador o selector respaldado por una muestra guardada y detecta cambios de formato.
- Conserva el último dato válido con su marca de tiempo, pero nunca lo muestres como actual después de superar el umbral de antigüedad definido.

## Configuración y seguridad

Mantén SSID, contraseña y otros secretos fuera del código versionado. Proporciona una plantilla sin valores reales y asegúrate de que el archivo local quede ignorado por Git. No imprimas secretos ni cuerpos sensibles en los registros.

## Verificación

Prueba por separado la comunicación con el módulo, la conexión Wi-Fi, la respuesta HTTP, el análisis con una muestra reproducible y el flujo integrado. Registra herramientas, versiones y salida observada. No afirmes que el firmware se compiló, se cargó o accedió al servidor si esas acciones no se ejecutaron.
