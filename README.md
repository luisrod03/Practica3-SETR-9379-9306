Implementacion de un contador BCD de 0 a 9 desplegado mediante LEDs y controlado por tres botones fisicos. 
Este proyecto introduce la gestion jerarquica en FreeRTOS mediante un Task Manager central, demostrando el control explicito del ciclo de vida de las tareas utilizando manejadores de tarea.

El sistema aisla los componentes de hardware de la logica de aplicacion. 
El Task Manager es la unica entidad que decide el estado global del sistema. 
A traves de las funciones de la API de FreeRTOS, el manager enciende o apaga la ejecucion de las tareas de interaccion basandose en si el sistema esta en pausa o en operacion, garantizando que no se procesen entradas invalidas.

Preguntas Guia
1. Que diferencia existe entre BLOCKED y SUSPENDED?
Una tarea en estado BLOCKED espera un evento temporal o de sincronizacion y el planificador la despertara automaticamente.
Una tarea en SUSPENDED fue detenida explicitamente; el planificador la ignora y solo volvera a ejecutarse si otra tarea la despierta.

3. Por que vTaskDelay coloca una tarea en estado BLOCKED?
Porque le indica al planificador que la tarea no tiene trabajo que realizar durante un numero de ticks especifico, cediendo inmediatamente el control del procesador a otras tareas que esten listas.

4. Que diferencia existe entre vTaskDelay y un Software Timer?
vTaskDelay detiene la ejecucion lineal de una tarea de usuario.
Un Software Timer le indica al RTOS que ejecute una funcion callback cuando expire el tiempo, ejecutandose en el contexto independiente de la tarea de servicio de temporizadores.

6. Que funcion cumple el Idle Task?
Es una tarea de prioridad cero que el RTOS ejecuta cuando ninguna otra tarea esta lista para ejecutarse.
Sirve para liberar memoria de tareas borradas o mandar el procesador a modos de bajo consumo.

8. Como decide FreeRTOS cual tarea ejecutar cuando varias tienen la misma prioridad?
Utiliza un esquema de Round Robin.
El planificador interrumpe y alterna la ejecucion, otorgandole un tick de procesamiento a cada tarea de la misma prioridad de forma secuencial.

10. Que ventajas aporta pvParameters?
Permite utilizar una misma funcion generica para multiples instancias, inyectando dinamicamente configuraciones especificas en tiempo de ejecucion, reduciendo la huella de memoria.

11. Que ventajas aporta TaskHandle_t?
Otorga un identificador unico y un puntero de control directo para cada tarea.
Permite a una tarea supervisora consultar el estado, pausar, reanudar o eliminar tareas externas a voluntad.

13. Que ocurriria si el contador se implementara con variables globales unicamente?
Se perderia por completo la arquitectura de software.
El control de estados se volveria propenso a condiciones de carrera y el sistema seria fragil y complejo de escalar.
