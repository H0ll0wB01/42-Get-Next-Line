# 42-Get-Next-Line

Este proyecto implementa la función `get_next_line`, que reproduce el comportamiento de la función estándar de C para leer una línea completa de un archivo, manejando buffers de tamaño configurable. La biblioteca también incluye una versión adicional (bonus) que amplía la funcionalidad para soportar múltiples descriptores de archivo abiertos al mismo tiempo, lo que permite leer de varios archivos simultáneamente.

## Cómo usar

Los siguientes comandos deben ser ejecutados en la terminal, dentro del directorio denominado Extras:

- **`make all`**: Compila el proyecto y genera la biblioteca estática `get_next_line.a` sin incluir las funciones adicionales (bonus).

- **`make bonus`**: Compila las funciones adicionales (bonus) que permiten manejar múltiples descriptores de archivo y genera la biblioteca estática `get_next_line.a`.

- **`make test`**: Una vez compilado, genera un ejecutable de prueba usando `main.c` y lo ejecuta para verificar el correcto funcionamiento de la función `get_next_line`.

- **`make test_bonus`**: Similar al comando anterior, pero usa `main_bonus.c` para probar la funcionalidad de las funciones adicionales (bonus).

- **`make clean`**: Elimina los archivos objeto (`.o`) generados durante la compilación.

- **`make fclean`**: Ejecuta el comando `clean` y, además, elimina el archivo `get_next_line.a` y cualquier ejecutable generado (`test_program` o `test_program_bonus`).

- **`make re`**: Ejecuta los comandos `fclean` y `all`, recompilando todo el proyecto desde cero.

- **`make test_sanitize`**: Compila el proyecto usando las herramientas de sanitización para comprobar posibles errores de memoria durante la ejecución de las pruebas.

- **`make test_valgrind`**: Ejecuta el proyecto usando Valgrind para identificar fugas de memoria u otros problemas de manejo de memoria.

## Configuración

Puedes ajustar el tamaño del buffer usado por `get_next_line` estableciendo la variable `BUFFER_SIZE` al ejecutar el Makefile. El valor predeterminado es 42, pero puedes modificarlo:

## Autor

<div align="center">
  <img src="https://avatars.githubusercontent.com/u/102600920?v=4" alt="Logo" width="200"/>
  <br/> 
  <a href="https://github.com/H0ll0wB01">Javier Fernández Correa</a>
</div>
<div align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTVInHuUPtp3uiEuvF0aYAkFBUzpnr65b2CDA&s" alt="Logo"/>
</div>
