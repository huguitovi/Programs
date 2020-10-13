## Requerimientos del Modelo de Ingeniería

1. Nomenclatura de Requerimientos
2. Requerimientos de Misión (MIS)
3. Requerimientos de Sistema (SIS) - Preliminar
4. Requerimientos de Carga Útil (PAY) - Preliminar
5. Requerimientos de Estructura (STR) - Preliminar
6. Requerimientos de Comunicaciones (COM) - Preliminar
7. Requerimientos de Comando y manejo de datos (C&DH) - Preliminar
8. Requerimientos de Potencia (POT) - Preliminar
9. Requerimientos de Propulsión (PRO) - Preliminar
10. Requerimientos de Guiado, Navegación y Control (GN&C) - Preliminar
11. Requerimientos de Estación Terrena (GST) - Preliminar

## 1. Nomenclatura de Requerimientos:

Los requerimientos de este documento siguen una nomenclatura según normativa del estándar ESA aeroespacial del tipo:
X-XXX-NNN
Donde el primer carácter es el prefijo que denota el tipo de requerimiento; los tres caracteres siguientes son el código de la categoría a la que pertenece el requerimiento (por ejemplo, el subsistema al que aplica y los últimos tres caracteres son el código numérico del requerimiento.
Los tipos de requerimientos son:
De diseño, denotados por una letra D.
Funcionales, denotados por una letra F.
De performance, denotados por una letra P.
Restrictivos, denotados por una letra R.

## 2. Requerimientos de Misión (MIS)
**F-MIS-010**	Se deberá concebir, diseñar, implementar y operar, el sistema completo, de un modelo de ingeniería, capaz de ensayar en tierra, capacidades específicas del dirigible propuesto en el proyecto Tolina.


## 3. Requerimientos de Sistema (SIS) - Preliminar
**P-SIS-010**	El dirigible Tolina deberá tener un radio de operación de al menos 30 m desde la GST.

**F-SIS-011**	El dirigible Tolina deberá brindar tres grados de libertad de traslación en el espacio de forma controlada.

**F-SIS-012**	El dirigible deberá brindar el grado de rotación de yaw de forma controlada.

**F-SIS-013**	El dirigible deberá presentar equilibrio mecánico estable en su rotación en torno a los ejes de roll y pitch a lo largo de toda la misión.

**F-SIS-020**	Los datos e imágenes obtenidos por la Tolina deberán ser transmitidos inalámbricamente hacia la estación terrena.

**F-SIS-030**	El dirigible deberá tener comunicación permanente con la estación terrena.

**P-SIS-040**	El dirigible deberá poder ser operado hasta por lo menos 3 m de altura.

**P-SIS-050**	El dirigible deberá tener una autonomía de por lo menos 30 minutos.

**R-SIS-060**	El volumen de helio contenido en módulo de flotación deberá ser inferior a 1.5 m3.

**R-SIS-061**	El dirigible deberá tener una masa total inferior a 1,5 kg.

**R-SIS-070**	El proyecto completo deberá consistir de un costo inferior a $30000.

**P-SIS-080**	El subsistema de potencia deberá proveer energía al Sistema al menos durante 30 minutos.


## 4. Requerimientos de Carga Útil (PAY) - Preliminar

**D-PAY-010**	El dirigible deberá contar con una cámara para capturar imágenes.

**D-PAY-011**	La cámara fotográfica deberá apuntar hacia nadir con una tolerancia de 10°.

**P-PAY-012**	La cámara fotográfica deberá proporcionar una pisada de por lo menos 2 m.

**P-PAY-013**	La cámara fotográfica deberá contar con una resolución de por lo menos 1 cm/px.

**R-PAY-020**	La carga útil de la Tolina deberá tener una masa inferior a TBD kg.

**R-PAY-030**	La carga útil de la Tolina deberá tener un consumo operativo menor a TBD mAh (crecimiento: 40%).


## 5. Requerimientos de Estructura (STR) - Preliminar

**D-STR-010**	El dirigible deberá consistir de dos módulos: un módulo de flotación y un módulo instrumental.

**F-STR-020**	El módulo de flotación deberá proveer al Tolina de flotación entre -TBD N y 0 N a lo largo de toda la misión.

**R-STR-021**	El gas helio en el módulo de flotación deberá estar a una presión absoluta de entre 1 atm y 1,1 atm a lo largo de toda la misión.

**D-STR-022**	La forma del módulo de flotación deberá optimizar la relación Volumen/Superficie.

**F-STR-030**	El módulo instrumental deberá alojar a la carga útil, y permitir que esta cumpla con todos los requerimientos definidos en la Sección 4.

**F-STR-031**	El módulo instrumental deberá alojar al subsistema de comunicaciones, y permitir que este cumpla con todos los requerimientos definidos en la Sección 6.

**F-STR-032**	El módulo instrumental deberá alojar al subsistema de C&DH, y permitir que este cumpla con todos los requerimientos definidos en la Sección 7.

**F-STR-033**	El módulo instrumental deberá alojar al subsistema de potencia, y permitir que este cumpla con todos los requerimientos definidos en la Sección 8.

**F-STR-034**	El módulo instrumental deberá alojar al subsistema de GN&C, y permitir que este cumpla con todos los requerimientos definidos en la Sección 10.

**D-STR-040**	El módulo instrumental deberá estar adherido a la parte inferior del módulo de flotación a lo largo de toda la misión.


## 6. Requerimientos de Comunicaciones (COM) - Preliminar

**F-COM-010**	El subsistema de comunicaciones deberá proveer comunicaciones en ambos sentidos para el subsistema GST.

**F-COM-011**	El subsistema de comunicaciones deberá contar con la capacidad de comunicarse con GST a un nivel de mínimo de TBD dB en cualquier configuración de actitud.

**F-COM-012**	El subsistema de comunicaciones deberá ser capaz de recibir comandos desde GST en cualquier momento de su misión.

**F-COM-013**	El subsistema de comunicaciones deberá ser capaz de transmitir todos los datos científicos a la GST.

**F-COM-014**	El subsistema de comunicaciones deberá ser capaz de transmitir todos los datos de ingeniería a la GST.

**F-COM-020**	El subsistema de comunicaciones deberá proveer comunicaciones en sentido de recepción para el subsistema PRO.

**F-COM-021**	El subsistema de comunicaciones de PRO deberá ser capaz de recibir comandos desde GST en cualquier momento de su misión.

**F-COM-030**	El subsistema de comunicaciones deberá proveer comunicaciones en sentido de emisión para el subsistema PAY.

**F-COM-031**	El subsistema de comunicaciones de PAY deberá ser capaz de enviar datos hacia GST en todo momento de su misión.

**P-COM-032**	La comunicación de PAY con GST deberá permitir el flujo de datos correspondiente al envío de imágenes de resolución mínima 320x240px.

**F-COM-040**	El subsistema de comunicaciones deberá proveer comunicaciones en sentido de emisión para el subsistema GN&C.

**F-COM-041**	El subsistema de comunicaciones de GN&C deberá ser capaz de enviar datos hacia GST en cualquier momento de su misión.

**P-COM-050**	El subsistema de comunicaciones deberá operar con una latencia menor a TBD ms.


## 7. Requerimientos de Comando y manejo de datos (C&DH) - Preliminar

**F-CDH-010**	El subsistema deberá soportar un sistema operativo en tiempo real.

**F-CDH-020**	El subsistema deberá proveer capacidad de procesamiento de datos.

**F-CDH-030**	El subsistema deberá asegurar transferencia de datos entre subsistemas.

**F-CDH-040**	El subsistema deberá asegurar transferencia de comandos entre subsistemas.

**F-CDH-050**	El subsistema deberá generar flujo de telemetría.


## 8. Requerimientos de Potencia (POT) - Preliminar

**R-POT-010**	El dirigible deberá tener un consumo operativo total menor a 10000 mAh.

**D-POT-011**	El dirigible deberá poseer una celda de potencia exclusiva para OBC y payload, llamada BATERÍA1.

**D-POT-012**	El dirigible deberá poseer una celda de potencia exclusiva para Propulsión, llamada BATERÍA2.

**P-POT-020**	La BATERÍA1 de potencia deberá alimentar a la OBC durante por lo menos 30 minutos de operación.

**P-POT-021**	La OBC deberá alimentar al payload durante por lo menos 30 minutos de operación.

**P-POT-030**	La BATERÍA2 de potencia deberá alimentar a los motores durante por lo menos 30 minutos de operación.

**R-POT-040** 	La BATERIA2 deberá tener un C-Rate mayor a 4C.

**D-POT-050** 	La BATERIA2 deberá ser de li-po o li-ion de 1 o 2 celdas. (TBC)

**R-POT-060** 	La celda de potencia deberá pesar menos de 400 g. (TBC)

**D-POT-070**	Las dimensiones de las baterías no deberán superar a las dimensiones internas de la góndola (TBC).

**F-POT-080**	Las baterías deberán ser recargables (reutilizables).

**R-POT-090**	Los motores de Tolina deberán poder operar en un rango nominal de voltajes entre 3.7 V y 7.4 V.

**R-POT-091**	Cada motor de Tolina deberá tener un consumo operativo menor a 1500 mAh.

 
## 9. Requerimientos de Propulsión (PRO) - Preliminar

**P-PRO-010**	Cada motor de Tolina deberá proporcionar un empuje de al menos 20 gf (TBC).

**F-PRO-011**	Cada motor deberá proporcionar empuje variable.

**D-PRO-020**	Cada motor deberá estar alojado en un soporte removible.

**R-PRO-030**	Los motores deberán pesar menos de 20 g cada uno (TBC).

**F-PRO-040**	Los motores deberán ser dispuestos de manera que aporten al vehículo los grados de libertad mencionados en F-SIS-011 y F-SIS-012.

**F-PRO-050**	Cada motor deberá poder girar en ambos sentidos.


## 10. Requerimientos de Guiado, Navegación y Control (GN&C) - Preliminar

**F-GNC-010**	El dirigible deberá sensar la magnitud y componentes de aceleración lineal con un error admisible de TBD m/s2 a lo largo de toda la misión.

**F-GNC-020**	El dirigible deberá medir su distancia al suelo a lo largo de toda la misión.


## 11. Requerimientos de Estación Terrena (GST) - Preliminar

**P-GST-010**	La Estación Terrena deberá recibir señal de video con una latencia de hasta TBD ms.

**F-GST-020**	La Estación Terrena deberá recibir telemetría del dirigible.

**P-GST-021**	La Estación Terrena deberá comunicarse con el dirigible durante al menos 30  min.

**F-GST-030**	La Estación Terrena deberá incluir soporte para visualización de las imágenes captadas por la cámara.

**P-GST-040**	La Estación Terrena deberá contar con capacidad de almacenamiento de los datos de por lo menos 8 GB.

**F-GST-050**	La Estación Terrena deberá permitir operar manualmente el dirigible.
