Sistema de gestión de tickets de soporte técnico

============================================================================================================================================================
> DESCRIPCIÓN
============================================================================================================================================================
Este proyecto es una aplicación para administrar tickets de soporte técnico de una empresa, esta permite registrar nuevos tickets, asignar su prioridad, visualizar la lista de tickets pendientes, procesar el siguiente ticket según prioridad y buscar los tickets por ID. Utilizando el TDA lista para organizar los tickets según su prioridad (Alta, Media o Baja).

============================================================================================================================================================
> CÓMO COMPILAR Y EJECUTAR
============================================================================================================================================================

Este sistema ha sido desarrollado en lenguaje C y puede ejecutarse fácilmente utilizando **Visual Studio Code** junto con una extensión para C/C++, como **C/C++ Extension Pack** de Microsoft. Para comenzar a trabajar con el sistema en tu equipo local, sigue estos pasos:

> Requisitos previos:

- Tener instalado [Visual Studio Code](https://code.visualstudio.com/).
- Instalar la extensión **C/C++** (Microsoft).
- Tener instalado un compilador de C (como **gcc**). Si estás en Windows, se recomienda instalar [MinGW](https://www.mingw-w64.org/) o utilizar el entorno [WSL](https://learn.microsoft.com/en-us/windows/wsl/).

> Pasos para compilar y ejecutar:

1.  Descarga y descomprime el archivo `.zip` en una carpeta de tu elección.

2.  Abre el proyecto en Visual Studio Code
    - Inicia Visual Studio Code.
    - Selecciona `Archivo > Abrir carpeta...` y elige la carpeta donde descomprimiste el proyecto.

3.  Compila el código
    - Abre el archivo principal (por ejemplo, `main.c`).
    - Abre la terminal integrada (`Terminal > Nueva terminal`).
    - En la terminal, compila el programa con el siguiente comando:
        gcc main.c list.c -o gestion_tickets

4.  Ejecuta el programa
    - Una vez compilado, puedes ejecutar la aplicación con:
        ./gestion_tickets
        
============================================================================================================================================================
> FUNCIONALIDADES
============================================================================================================================================================

> Funcionando correctamente:

- Registro de tickets con datos básicos y hora de creación.
- Asignación de prioridad personalizada a cada ticket.
- Separación de tickets en listas según prioridad (Alta, Media, Baja).
- Visualización de listas de espera ordenadas.
- Procesamiento del ticket con mayor prioridad.
- Búsqueda de ticket por ID.

> Problemas conocidos:

- Actualmente es posible registrar varios tickets con el mismo ID sin verificación.
- Es posible registrar tickets con caracteres, lo que ocasiona problemas para ingresar los valores.

> A mejorar:

- Validación de IDs duplicados.
- Permitir edición de tickets ya ingresados.
- Optimización del uso de listas (evitar limpiar y redistribuir en cada ejecución).


============================================================================================================================================================
> EJEMPLO DE USO
============================================================================================================================================================

> Paso 1: Registrar un nuevo ticket

Se comienza registrando un nuevo ticket cuando se seleciona la opción 1.

```
SELECCIONE UNA OPCION (1, 2): 1

Ingrese el ID (NUMERICA) del Ticket: 101
Ingrese la descripcion del Ticket: Problema con acceso a la VPN
Ticket registrado con prioridad BAJA y hora 14:23:12
```

El sistema registra el ticket de ID '101' con una prioridad inicial "Bajo" y guarda la hora actual de registro.

> Paso 2: Se finaliza el registro de tickets

```
SELECCIONE UNA OPCION (1, 2): 2

FIN DEL REGISTRO
```

> Paso 3: Asignar prioridad

Se asigna la prioridad que tienen los tickets, ya sea por prioridad alta, media o baja.

```
Ingrese la prioridad (Bajo, Medio, Alto) para el ticket con ID 101: Alto
```
* El sistema actualiza la prioridad del ticket de ID '101' a "Alto".

> Paso 4: Mostrar lista de ticketcs pendientes

El usuario revisa la lista de los tickects pendientes para revisar todos los tickets y sus prioridades.

```
Tickets con prioridad ALTA: 
-ID: 101
Tickets con prioridad MEDIA: 
- NO HAY TICKETS CON PRIORIDAD MEDIA
Tickets con prioridad BAJA: 
- NO HAY TICKETS CON PRIORIDAD BAJA
```

La lista muestra al ticket de ID '101' en la parte superior, indicando su prioridad alta y que es el siguiente en procesarse.

> Paso 5: Procesar siguiente ticket

Se procesa el ticket de mayor prioridad en la cola de atención basándose en su prioridad.

```
DATOS TICKET A PROCESAR:
- ID: 101
- DESCRIPCION: Problema con acceso a la VPN
- PRIORIDAD: Alto
- HORA: 14:23:12
```

El sistema muestra que el ticket de ID '101' está siendo procesado y lo elimina de la lista.

> Paso 6: Se busca un ticket por ID

El usuario introduce una ID de ticket para buscar.

````
BUSQUEDA POR ID

INGRESE LA ID A BUSCAR: 101
ID NO ESCONTRADA
```

Se busca el ticket de ID 101, pero al haber sido procesado anteriormente no se encuentra.