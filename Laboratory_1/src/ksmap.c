#include "ksmap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 256

void part_a(){
    printf("------ Kernel Sampler (ksamp) ------");
    printf("\n");
    print_host_name();
    print_date();
    return;
}

void part_b(void){
    print_up_time();
    printf("------- Información del Equipo -------");
    print_cpu_info();
    print_kernel_version();
    return;
}

void part_c(void){
     printf("\n");
     print_cpu_times();
     print_context_changes();
     boot_up_time();
     processes();
     return;
}

void part_d(int a, int b){
    int i;
    i=b/a;
    printf("-------------------------------------\n");
    while(i>0){
               hdd_requests();
               memory_info();
               load_avg();
               i--;
               sleep((unsigned int)a);
               printf("-------------------------------------\n");
       }
       return;
}

void part_e(int a, int b){
    int i;
    i=b/a;
    unsigned int initial_context = 0;
    unsigned int final_context = 0;
    unsigned int delta_context = 0;
    printf("-------------------------------------\n");
    initial_context = get_context();
    while(i>0){
               final_context = get_context();
               delta_context = final_context - initial_context;
               hdd_requests();
               memory_info();
               load_avg();
               printf("----- Cambios de contextos -------\n");
               printf("Cambios de contextos iniciales: %u\n",initial_context);
               printf("Cambios de contextos actuales: %u\n",final_context);
               printf("Diferencia de cambios de contexto: %u\n",delta_context);
               i--;
               sleep((unsigned int)a);
               printf("-------------------------------------\n");
       }
       return;
}

void seg2hms(float seg, char* buffer){
    unsigned int day, hour, minute;
    float seconds;

    day = (unsigned int) (seg/86400);
    seg = seg - (long)(day*86400);
    hour = (unsigned int) (seg/3600);
    seg = seg - (long)(hour*3600);
    minute = (unsigned int) (seg/60);
    seg = seg - (long)(minute*60);
    seconds = seg;

    if(day>0){
        sprintf(buffer, "%3ud %2u:%02u:%02.2f\n",day,hour,minute,seg);
    }
    else {
        sprintf(buffer,"%2u:%02u:%02.2f\n",hour,minute,seconds);
    }

    return;
}

void matcher(char* file_name,char* matched, char* match_str){
    FILE* fp;
    char* match = NULL;
    char buffer[512];
    fp = fopen(file_name,"r");

    while (feof(fp)==0) {
        fgets(buffer,512,fp);
        match = strstr(buffer,match_str);
        if (match!=NULL) {
            break;
        }
    }
    fclose(fp);
    strcpy(matched,match);
    return;
}

void print_host_name(){
    FILE* fp;
    char name[64];
    fp = fopen("/proc/sys/kernel/hostname","r");
    fscanf(fp,"%[^\n]s",name);
    printf("Nombre del equipo: %s\n",name);
    fclose(fp);
    return;
}

void print_cpu_info(){
    char matched[BUFFER_SIZE];
    char cpu_type[64];
    char cpu_model[128];

    matcher("/proc/cpuinfo",matched,"vendor_id");
    sscanf(matched,"vendor_id : %s",cpu_type);

    matcher("/proc/cpuinfo",matched,"model name");
    sscanf(matched,"model name : %[^\n]c",cpu_model);
    printf("\nTipo de procesador: %s \nModelo: %s\n",cpu_type,cpu_model);
    return;
}

void print_kernel_version(){
    FILE* fp;
    char kernel_version[64];
    fp = fopen("/proc/version","r");
    fscanf(fp,"%[^(]s",kernel_version);
    printf("Version del Kernel: %s \n",kernel_version);
    fclose(fp);
    return;
}

void print_up_time(){
    FILE* fp;
    float time;
    char hms[32];
    fp = fopen("/proc/uptime","r");
    fscanf(fp,"%f",&time);
    seg2hms(time,hms);
    printf("Tiempo transcurrido desde el inicio del SO: %s \n",hms);
    fclose(fp);
    return;
}

void print_cpu_times(){
    FILE* fp;
    float user=0, sys=0, idle = 0;
    char time_user[16], time_sys[16], time_idle[16];
    fp = fopen("/proc/stat","r");
    fscanf(fp,"cpu %f %*f %f %f",&user,&sys,&idle);
    seg2hms(user/100,time_user);
    printf("Tiempo del CPU para el usuario: %s",time_user);
    seg2hms(sys/100,time_sys);
    printf("Tiempo del CPU para el sistema: %s",time_sys);
    seg2hms(idle/100,time_idle);
    printf("Tiempo del CPU idle: %s",time_idle);
    return;
}

void print_context_changes(){
    char matched[BUFFER_SIZE];
    unsigned int changes;
    matcher("/proc/stat",matched,"ctxt");
    sscanf(matched,"ctxt %u",&changes);
    printf("Cambios de contexto: %u \n",changes);
    return;
}

void boot_up_time(){
    char matched[BUFFER_SIZE];
    time_t btime;
    unsigned int aux;
    char booted[64];
    matcher("/proc/stat",matched,"btime");
    sscanf(matched,"btime %u",&aux);
    btime = (time_t)aux;
    strftime(booted,sizeof (booted),"%c",localtime(&btime));
    printf("Boot Up Time: %s \n",booted);
    return;
}

void processes(){
    char matched[BUFFER_SIZE];
    int processes;
    matcher("/proc/stat",matched,"processes");
    sscanf(matched,"processes %u",&processes);
    printf("Cantidad de procesos creados: %u\n",processes);
    return;
}

void hdd_requests(){
    char matched[BUFFER_SIZE];
    unsigned int lectures = 0, writed = 0, request = 0;
    matcher("/proc/diskstats",matched,"sda");
    sscanf(matched,"sda %u",&lectures);
    sscanf(matched,"sda %*u %*u %*u %*u %u",&writed);
    request = lectures + writed;
    printf("Cantidad de pedidos al HDD: %u\n",request);
    return;
}

void memory_info(){
    char matched[BUFFER_SIZE];
    unsigned int total_memory = 0, free_memory = 0;
    matcher("/proc/meminfo",matched,"MemTotal");
    sscanf(matched,"MemTotal: %u",&total_memory);
    matcher("/proc/meminfo",matched,"MemFree");
    sscanf(matched,"MemFree: %u",&free_memory);
    printf("Memoria total: %uMB\n",total_memory/1024);
    printf("Memoria disponible: %uMB\n",free_memory/1024);
    return;
}

void load_avg(){
    FILE* fp;
    float load;
    fp = fopen("/proc/loadavg","r");
    fscanf(fp,"%f",&load);
    printf("Promedio de carga de un minuto: %f\n",load);
    fclose(fp);
    return;
}

void print_date(){
    char date[16];
    char time[16];
    char matched[BUFFER_SIZE+1];
    matcher("/proc/driver/rtc", matched, "rtc_date");
    sscanf(matched, "rtc_date : %s", date);
    matcher("/proc/driver/rtc", matched, "rtc_time");
    sscanf(matched, "rtc_time : %s", time);
    printf("Fecha: %s   -   Hora: %s UTC\n", date, time);
    return;

}

unsigned int get_context(){
    char matched[BUFFER_SIZE];
    unsigned int changes;
    matcher("/proc/stat",matched,"ctxt");
    sscanf(matched,"ctxt %u",&changes);
    return changes;
}


