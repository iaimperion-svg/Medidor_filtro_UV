# Fuente DMC: evidencia y enlaces

Revisión realizada el 7 de noviembre de 2026. Se completaron el registro, la activación por correo y una consulta autenticada al servicio UV. No se ha realizado una prueba con Arduino.

## Documentación oficial

- [Servicio de índice UV reciente](https://climatologia.meteochile.gob.cl/application/documentacion/getDocumento/3).
- [Catálogo de servicios JSON y GeoJSON](https://climatologia.meteochile.gob.cl/application/index/menuTematicoJson).
- [Descripción de productos de radiación](https://climatologia.meteochile.gob.cl/application/index/menuTematicoRadiacion).
- [Ficha de la estación 360019](https://climatologia.meteochile.gob.cl/application/informacion/fichaDeEstacion/360019).

El servicio documentado se denomina `getRecienteUvb`, bajo `https://climatologia.meteochile.gob.cl/application/servicios/getRecienteUvb`. La consulta documentada utiliza `usuario` y `token`. Las credenciales no forman parte de esta skill ni del repositorio.

La respuesta descrita es JSON con observaciones de la red nacional separadas por cinco minutos. Incluye `codigoNacional`, `nombreEstacion`, coordenadas y altitud, y registros con `fecha`, `hora` e `indiceUV`. La fecha y la hora se expresan en UTC. El índice es adimensional y puede superar 11. El ejemplo presenta valores numéricos como texto.

La documentación menciona cinco días recientes en su descripción y diez en el ejemplo. No fijes la duración del historial a partir de esa discrepancia: comprueba la respuesta vigente si esa ventana importa.

El portal declara acceso y uso público de la información y solicita atribuirla a la Dirección Meteorológica de Chile. Esta revisión no confirmó cuotas de consultas, retraso garantizado ni continuidad de servicio.

## Página que eligió Mauro

[Índice diario de Carriel Sur del 07-11-2026](https://climatologia.meteochile.gob.cl/application/diario/indiceUvbDiario/360019/2026/11/07).

La vista consultada mostraba una tabla legible, un gráfico y un botón Excel. La última lectura visible era 6,3 a las 19:05 UTC. El máximo de la tabla era 10,1 a las 16:30 UTC, mientras que el resumen diario mostraba 10. Los huecos se representaban con puntos. Son ejemplos de esa consulta, no valores actuales que deban reutilizarse.

La presencia de la tabla hace viable extraer datos de la página. El servicio oficial también se ha comprobado con autenticación; deben tenerse en cuenta las diferencias observadas a continuación.

## Acceso verificado

El registro se realiza en el [portal de usuarios](https://climatologia.meteochile.gob.cl/application/usuario/registroUsuario). Después de crear la cuenta hay que abrir el enlace de activación recibido por correo e iniciar sesión.

La cuenta creada ya disponía de un campo `ApiKey` en el [perfil del usuario](https://climatologia.meteochile.gob.cl/application/usuario/editaDatosUsuario), accesible desde el nombre en la cabecera. Se utilizó esa clave existente; no fue necesario accionar el botón `Actualiza`.

La consulta autenticada a `getRecienteUvb` devolvió JSON con la estación `360019`. La respuesta indicaba generación a las 19:45 UTC del 07-11-2026; su última lectura válida de esa estación correspondía a las 19:20 UTC. Esa diferencia de 25 minutos es una observación puntual, no una garantía del retraso habitual.

Se contrastaron valores sin transformación de la respuesta con la tabla diaria de la misma estación y fecha:

| Hora UTC | Índice en la API | Índice en la tabla diaria |
| --- | --- | --- |
| 19:10 | 6 | 6,1 |
| 19:15 | 5 | 5,9 |
| 19:20 | 5 | 5,7 |

La API entregó estos índices como cadenas con números enteros. La tabla conservaba decimales. No se ha confirmado la causa de la diferencia: no asumir que la respuesta mantiene los decimales ni atribuirla a un método concreto de redondeo o agregación. Si esa precisión resulta necesaria para el dispositivo, resolver la discrepancia con DMC o evaluar la tabla como fuente alternativa antes de fijar el contrato de datos.

La cuenta y la ApiKey permiten preparar la integración antes de conectar la placa. Quedan pendientes la definición de precisión y antigüedad aceptables y la prueba física. No se generó código ni se almacenaron credenciales en archivos del proyecto durante esta comprobación.
