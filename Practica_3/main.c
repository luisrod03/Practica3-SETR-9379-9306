#include "system_state.h"
#include "app_task.h"

/*

RESPUESTAS

1. ¿Qué diferencia existe entre BLOCKED y SUSPENDED?
Una tarea entra en BLOCKED automaticamente cando espera un evento y regresa sola a READY cuando este se cumple. Una tarea en SUSPENDED es pausada manualmente mediante 'vTaskSuspend()' y se queda congelada hasta que otra tarea la reactiva con 'vTaskResume()'.

2. ¿Por qué vTaskDelay() coloca una tarea en estado BLOCKED?
Porque le dice al planificador que la tarea no tiene trabajo que hacer durante un tiempo. Al pasarla a BLOCKED, FreeRTOS le quita temporalmente el uso del procesador para dárselo a otras tareas, evitando el desperdicio de ciclos de reloj.

3. ¿Qué diferencia existe entre vTaskDelay() y un Software Timer?
'vTaskDely()' detiene y bloquea por completo la ejecucion de la tarea en la que es llamado. En cambio, un Software Timer funciona de forma independiente mediante un callback, ejecutando acciones periódicas sin interrumpir el flujo interno de tus tareas de control principales.

4. ¿Qué función cumple el Idle Task?
Es una tarea de prioridad cero creada automáticamente por el sistema al iniciar el planificador. Su función es asegurar que el procesador siempre tenga algo que ejecutar cuando el resto de las tareas están bloquedas.

5. ¿Cómo decide FreeRTOS cuál tarea ejecutar cuando varias tienen la misma prioridad?
Utiliza Round Robin. El planificador divide el tiempo equitativamente y alterna la ejecución entre todas las tareas que comparten esa misma prioridad en cada tick de reloj.

6. ¿Qué ventajas aporta pvParameters?
Permite la reutilización y modularidad del código. Facilita que una sola función de tarea genérica pueda controlar diferentes elementos como distintos pines de LEDs o botones.

7. ¿Qué ventajas aporta TaskHandle_t?
Funciona como una referencia o de la tarea. Permite que otras tareas como el Task Manager puedan monitorear su estado actual con 'eTaskGetState()'.

8. ¿Qué ocurriría si el contador se implementara con variables globales únicamente?
Se generarían condiciones de carrera e inconsistencia de datos.

CONCLUSIÓN TÉCNICA 

Esta práctica nos permitió comprender de manera práctica la gestión de estados en un sistema operativo de tiempo real utilizando el ESP32. Mediante el diseño del Task Manager y el uso de 'TaskHandle_t', se logró coordinar la pausa y reanudación del contador BCD de forma controlada.
Asimismo, la parametrización con 'pvParameters' demostró ser una herramienta clave para optimizar el código, permitiendo reutilizar funciones de tareas para múltiples periféricos. En conclusión, el uso correcto de las herramientas de FreeRTOS es fundamental para construir aplicaciones embebidas estables y con un comportamiento temporal estrictamente predecible.

*/


void app_main(void)
{
    system_state_init();

    app_tasks_create();

}
