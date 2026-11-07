# Fuente DMC: evidencia y enlaces

Revisión realizada el 7 de noviembre de 2026. No se efectuó una llamada autenticada a la API ni una prueba con Arduino.

## Documentación oficial

- [Servicio de índice UV reciente](https://climatologia.meteochile.gob.cl/application/documentacion/getDocumento/3).
- [Catálogo de servicios JSON y GeoJSON](https://climatologia.meteochile.gob.cl/application/index/menuTematicoJson).
- [Descripción de productos de radiación](https://climatologia.meteochile.gob.cl/application/index/menuTematicoRadiacion).
- [Ficha de la estación 360019](https://climatologia.meteochile.gob.cl/application/informacion/fichaDeEstacion/360019).

El servicio documentado se denomina `getRecienteUvb`, bajo `https://climatologia.meteochile.gob.cl/application/servicios/getRecienteUvb`. La consulta documentada utiliza `usuario` y `token`; no se dispone de credenciales en esta skill.

La respuesta descrita es JSON con observaciones de la red nacional separadas por cinco minutos. Incluye `codigoNacional`, `nombreEstacion`, coordenadas y altitud, y registros con `fecha`, `hora` e `indiceUV`. La fecha y la hora se expresan en UTC. El índice es adimensional y puede superar 11. El ejemplo presenta valores numéricos como texto.

La documentación menciona cinco días recientes en su descripción y diez en el ejemplo. No fijes la duración del historial a partir de esa discrepancia: comprueba la respuesta vigente si esa ventana importa.

El portal declara acceso y uso público de la información y solicita atribuirla a la Dirección Meteorológica de Chile. Esta revisión no confirmó cuotas de consultas, retraso garantizado ni continuidad de servicio.

## Página que eligió Mauro

[Índice diario de Carriel Sur del 07-11-2026](https://climatologia.meteochile.gob.cl/application/diario/indiceUvbDiario/360019/2026/11/07).

La vista consultada mostraba una tabla legible, un gráfico y un botón Excel. La última lectura visible era 6,3 a las 19:05 UTC. El máximo de la tabla era 10,1 a las 16:30 UTC, mientras que el resumen diario mostraba 10. Los huecos se representaban con puntos. Son ejemplos de esa consulta, no valores actuales que deban reutilizarse.

La presencia de la tabla hace viable extraer datos de la página. La existencia de un servicio oficial ofrece una vía más adecuada para una integración mantenible; su funcionamiento autenticado sigue pendiente de verificación.
