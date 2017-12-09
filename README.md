# Respaldo asignatura computación paralela


Codigo grupo: PPg1
Semestre: 1
Año: 2017

Descripción:
Repositorio destinado al desarrollo y mantención de tareas para la asignatura de Computación paralela y distribuida.

### Tarea número 1

Esta tarea consiste en acceder a un archivo (access.log) el cual se encuentra comprimido dentro de la carpeta `Tarea_01`
y filtrar el contendido de este documento agrupando por `semana` o `horas` segun corresponda el parametro ingresado.

Como compilar la aplicación:

```
g++ main.cpp -o rfa -std=c++11
```

Usos:
```
./rfa -semana -C /home/user_path/access.log
./rfa -horas -C /home/user_path/access.log
./rfa --help
```

### Tarea número 2

Esta tarea consiste en ordenar las asignaturas de una lista de profesores en un horario. Este horario corresponde a una sala con 8 periodos de lunes a viernes y 6 periodos el día sábado.

Como compilar la aplicación:

```
g++ main.cpp Docente.cpp Sala.cpp -o ejecutable
```

Usos:
```
./ejecutable
```

Output:
```
archivo horario.csv`
```
