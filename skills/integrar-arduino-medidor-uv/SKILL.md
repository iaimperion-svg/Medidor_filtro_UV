---
name: integrar-arduino-medidor-uv
description: Prepara y verifica la conexión del Arduino de Medidor_filtro_UV, incorporando los cambios de Kassian. Úsala al conectar la placa, revisar firmware o cableado, acordar el envío de datos UV y comprobar su recepción en el dispositivo.
---

# Integrar Arduino en Medidor_filtro_UV

## Contexto del proyecto

Repositorio: `https://github.com/iaimperion-svg/Medidor_filtro_UV`. Carpeta inicial: `C:\ANDRUINO`. Comprueba la ubicación y los cambios actuales antes de actuar. La fuente elegida para el índice UV es MeteoChile, estación Carriel Sur `360019`; la validación de esa fuente se documenta en la skill `obtener-datos-uv-meteochile`, disponible también en la carpeta hermana de este paquete.

Al preparar esta skill, el 7 de noviembre de 2026, no se habían identificado la placa, el sensor, la interfaz de comunicación ni los cambios concretos de Kassian. No conviertas estas incógnitas en valores predeterminados. La ausencia de cuenta GitHub de Kassian en esa fecha no impide recibir sus cambios por archivos o documentos.

Conectar el cable no demuestra que la placa esté preparada para recibir firmware. Distingue las tareas autorizadas: inspección, revisión de cambios, implementación y carga. Respeta la autorización ya dada y no repitas confirmaciones para los mismos pasos.

## Revisar los cambios de Kassian

Busca primero en el repositorio y en los materiales aportados: rama o revisión, archivos de firmware, esquema de conexiones, componentes y notas de modificación. Identifica qué versión se está usando y compara con la base antes de proponer una integración.

Si los cambios aún no están disponibles, avanza con la inspección que no dependa de ellos e identifica exactamente qué falta. No afirmes que se han integrado ni inventes una versión. Conserva modificaciones locales y revisa conflictos de comportamiento además de los conflictos de texto.

Comprueba especialmente si los cambios afectan a pines, alimentación, dirección de sensores, velocidad de comunicación, formato del mensaje, temporización o comportamiento de las salidas. Mantén coherentes cableado documentado y firmware.

## Identificar el equipo y la conexión

Obtén de evidencias disponibles el modelo exacto, revisión de placa, microcontrolador y perfil de compilación. Identifica el puerto o dirección del dispositivo; con varias placas, usa sus identificadores o una comprobación guiada para distinguirlas. No elijas el primer puerto disponible.

Distingue la conexión al ordenador de la conexión para obtener datos de Internet. USB, Wi-Fi, Ethernet o módem son opciones que deben verificarse en el montaje real. La familia Arduino no implica una capacidad de red concreta.

Antes de energizar un montaje modificado o activar salidas, contrasta la alimentación y los niveles lógicos con las especificaciones oficiales del modelo y de sus módulos. Un conector USB no confirma la compatibilidad de las señales externas. No deduzcas que todos los módulos toleran 5 V ni que son de 3,3 V por pertenecer a una familia.

Usa las herramientas instaladas y el sistema de construcción del proyecto. Identifica quién ocupa el puerto antes de abrirlo o cerrarlo; no finalices procesos ajenos para liberarlo. Ten en cuenta que abrir el puerto serie puede reiniciar algunas placas.

## Acordar el contrato de datos

Determina qué hará el dispositivo con la información: mostrar el índice, señalizar un estado, registrar lecturas o compararlas con un sensor local. Decide después dónde se consulta MeteoChile y cómo llega el mensaje a la placa.

Revisa con el firmware existente los campos mínimos: estación, índice UV, fecha y hora de medición, vigencia y estado de recepción. En comunicación serie, confirma también velocidad, codificación y delimitación de mensajes. No inventes esos parámetros a partir de valores habituales.

La pérdida de conexión, una lectura antigua y un índice cero deben producir estados distinguibles. Evita que una lectura retransmitida o anterior sustituya una más reciente. Define el comportamiento durante arranque, reconexión y ausencia de datos según el uso acordado.

Si se comparan lecturas de un sensor con el índice DMC, verifica que midan magnitudes compatibles y coincidan temporalmente. Una lectura analógica o irradiancia no equivale por sí sola al índice UV. Los datos de una estación remota no miden la transmisión de un filtro instalado sobre el dispositivo.

## Implementar y cargar cuando corresponda

Una petición limitada a análisis, skills o revisión termina con documentación y hallazgos. Cuando el encargo incluya implementación, adapta el firmware a la placa y a los cambios comprobados; compila con el perfil y dependencias identificados antes de cargarlo.

Para la carga, confirma que el dispositivo identificado es el objetivo y que cargar firmware forma parte de la autorización vigente. Revisa si la operación altera calibración o datos persistentes y preserva lo recuperable cuando sea relevante. Si no se dispone de copia del firmware anterior, indícalo sin prometer una reversión no verificada.

Ante una carga fallida, inspecciona el error y la conexión antes de reintentar. No cambies de placa, puerto, cargador de arranque ni parámetros de borrado para forzar un resultado sin evidencia que justifique ese cambio.

## Verificación del conjunto

Comprueba por separado compilación, carga, recepción del mensaje y resultado físico. Haber compilado o haber subido firmware no demuestra recepción de datos reales.

Con hardware disponible, verifica una lectura real de la estación y su marca temporal, el tratamiento de dato ausente o antiguo y la reconexión. Usa valores simulados únicamente identificados como tales. Evalúa los umbrales cuando existan en el comportamiento solicitado, sin añadir funciones ajenas al encargo.

Entrega la revisión incorporada de Kassian, equipo identificado, transporte utilizado y evidencia de cada comprobación. Si aún no hay placa conectada, limita la conclusión a lo verificado sin hardware y deja explícita la prueba física pendiente.
