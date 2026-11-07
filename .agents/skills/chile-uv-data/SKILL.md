---
name: chile-uv-data
description: Investiga y valida una fuente de índice UV actual o pronosticado para una ubicación de Chile. Úsala al seleccionar el proveedor, interpretar sus datos o definir el contrato que consumirá el Arduino.
---

# Chile Uv Data

La expresión "índice UV de Chile" no identifica por sí sola un valor único. Determina la ciudad, estación o coordenadas y si el usuario necesita una observación actual, un pronóstico horario o el máximo diario. Si no está definido y afecta el resultado, pregunta antes de escoger una ubicación.

## Selección de la fuente

Busca información vigente y abre la fuente original. Prioriza organismos oficiales o proveedores con documentación técnica clara. Para cada alternativa registra:

- entidad responsable y URL exacta;
- cobertura geográfica y ubicación asociada al dato;
- si el dato es observado, estimado o pronosticado;
- frecuencia de actualización y marcas de tiempo disponibles;
- formato de acceso, autenticación, límites y condiciones de uso;
- estabilidad esperable del campo, endpoint o estructura HTML.

No describas una fuente como oficial, pública, en tiempo real o gratuita sin evidencia. No inventes endpoints ni valores UV. Cuando la fuente sea una página, comprueba si el dato está en el HTML descargable o si requiere JavaScript.

## Contrato de datos del proyecto

Normaliza el resultado, como mínimo, en estos campos:

- `uv_index`: valor numérico validado;
- `location`: ubicación inequívoca;
- `observed_at`: hora asociada por la fuente, cuando exista;
- `fetched_at`: hora de la descarga;
- `source`: proveedor y URL;
- `status`: `current`, `stale` o `invalid` según reglas documentadas.

No reemplaces `observed_at` por `fetched_at`. Usa la zona horaria indicada por la fuente y documenta las conversiones a la hora local de Chile, incluidos cambios estacionales cuando correspondan.

## Interpretación

Obtén los rangos de categorías y recomendaciones UV desde una fuente sanitaria o meteorológica autorizada y cítala en la documentación del proyecto. No codifiques umbrales desde memoria. Distingue claramente el valor numérico, su categoría y cualquier recomendación presentada al usuario.

Guarda una respuesta de ejemplo sin secretos para pruebas reproducibles, junto con la fecha de captura y el esquema o selector utilizado. Si el proveedor cambia el formato, informa el cambio y actualiza las pruebas antes de declarar la extracción reparada.
