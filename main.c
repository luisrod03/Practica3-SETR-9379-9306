#include "system_state.h"
#include "app_task.h"

/*

 * CONCLUSIÓN TÉCNICA:
 * Esta parctica demuestra el uso de FreeRTOS para construir un sistema
 * concurrente y modular sobre ESP32. El contador BCD 0-9 se implementa
 * como una tarea independiente controlada por el Task Manager mediante
 * vTaskSuspend() y vTaskResume(), lo que permite pausar y reanudar el
 * conteo conservando el valor sin necesidad de variables de control extra.
 *
 * pvParameters permite reutilizar una misma función de tarea (led_task,
 * button_task) para múltiples instancias con configuración diferente,
 * evitando código duplicado y respetando el principio de separación entre
 * lógica, drivers y aplicación.
 *
 * TaskHandle_t: sin él no sería posible suspender o
 * reanudar tareas específicas desde el manager. Centralizar el control
 * en un único Task Manager simplifica el razonamiento sobre el estado
 * global y evita condiciones de carrera entre tareas.
 *
 * La diferencia clave entre BLOCKED y SUSPENDED es que BLOCKED es
 * temporal (la tarea se desbloquea sola al vencer su temporizador o
 * recibir un semáforo), mientras que SUSPENDED es indefinida: la tarea
 * no regresa a READY a menos que otra tarea llame vTaskResume().
 * Esto hace que vTaskSuspend/Resume sea la herramienta correcta para
 * implementar la función Start/Pause de esta práctica.
 */
void app_main(void)
{
    system_state_init();

    app_tasks_create();

}
