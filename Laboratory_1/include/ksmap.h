#ifndef KSMAP_H
#define KSMAP_H

#endif // KSMAP_H

/**
   \file ksmap.h
   \brief Resumen del programa ksmap

          Laboratorio N°I: Monitor de sistema

  \author Valenzuela Gabriel Emanuel.
  \version 1.0.0
  \details \b Subject: Operating Systems I - 7422 \n
           \b Professor CE Pablo, Martinez \n
           <b>Universidad Nacional de Córdoba - Facultad de
          Ciencias Exactas, Físicas y Naturales</b> \n
  \date July 2019
  \copyright MIT License

  \brief Funcionalidad del programa:
    Este es un programa que monitorea algunos aspectos de un sistema funcionando con \b<Linux> como kernel.
    Podemos pensar el kernel de un sistema operativo como una colección de funciones y estructuras de datos.
    Estas estructuras de datos (o variables de kernel) contienen la visión del kernel respecto al estado del
    sistema donde cada interrupción, cada llamada al sistema, cada fallo de protección hacen que este estado cambie.
    Inspeccionando las variables del kernel podemos obtener información relevante a los procesos, interrupciones,
    dispositivos, sistemas de archivos, capacidades del hardware, etc.
    Los detalles del \proc se detallan en el informe.
*/

/*!
Tipo y modelo de CPU.
• Versión del kernel.• Tiempo en días, horas, minutos y segundos que han transcurrido desde que se inició el
sistema operativo.
• Cuánto tiempo de CPU ha sido empleado para procesos de usuario, de
sistema y cuando tiempo no se usó.
• Cuánta memoria tiene y cuánta está disponible.
• Cuántos sistemas de archivo soporta el kernel
• Cuántos pedidos de lectura/escritura a disco se han realizado.
• Cuántos cambios de contexto han sucedido.
• Cuántos procesos se crearon desde que inició el sistema.
*/

void part_a(void);

/*!
• Tipo y modelo de CPU.
• Versión de Kernel.
• Cantidad de tiempo transcurrido desde que se inició el sistema operativo,
con el formato ddD hh:mm:ss.
• Cantidad de sistemas de archivo soportados por el kernel
También se pide incluir una cabecera donde se indique el nombre de la máquina y la fecha
y hora actuales.
*/

void part_b(void);

/*!
• Cantidad de tiempo de CPU utilizado para usuarios, sistema y proceso idle.• Cantidad de cambios de contexto.
• Fecha y hora cuando el sistema fue iniciado.
• Número de procesos creados desde el inicio del sistema.
*/

void part_c(void);

/*!
• Número de peticiones a disco realizadas.
• Cantidad de memoria configurada en el hardware.
• Cantidad de memoria disponible.
• Lista de los promedios de carga de 1 minuto
*/

void part_d(int a, int b);

void part_e(int a, int b);

/**
  Conversion de segundos a HH:MM:SS
  */

void seg2hms(float seg, char* buffer);

void print_host_name(void);
void print_date(void);
void print_cpu_info(void);
void print_kernel_version(void);
void print_up_time(void);
void print_cpu_times(void);
void print_context_changes(void);
void boot_up_time(void);
void processes(void);
void hdd_requests(void);
void memory_info(void);
void load_avg(void);
unsigned int get_context(void);
void matcher(char* file_name,char* matched, char* match_str);
